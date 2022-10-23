import { Request, Response } from 'express';

import BigQueryServer from '../../common/BigQueryServer';
import JobsInsertExtractEnforceStrategy from '../JobsInsertExtractEnforceStrategy';

import { PolicyResult } from '../../common/interfaces';
import { IJob } from '../../common/types';

jest.mock('../../common/BigQueryServer');

const MockedBigQueryServer = BigQueryServer as jest.MockedClass<typeof BigQueryServer>;

describe('executeAllowDecision()', () => {
  const newTable = {
    projectId: 'newProjectId',
    datasetId: 'newDatasetId',
    tableId: 'newTableId',
  };
  const res = {} as Response;
  const next = jest.fn();

  beforeEach(() => {
    next.mockClear();
  });

  test('reassign sourceTable directly when there is a cached newTable', async () => {
    const req = {
      body: {
        configuration: {
          extract: {
            sourceTable: {
              projectId: 'projectId',
              datasetId: 'datasetId',
              tableId: 'tableId',
            },
          },
        },
      },
    } as Request;
    const enforceStrategy = new JobsInsertExtractEnforceStrategy(req, res, next);
    const policyResult: PolicyResult = {
      enforcer_result: 'allow',
      safe_sql: 'SELECT * FROM TEST_TABLE',
      error: 'error message',
      redirectTableRef: newTable,
    };

    await enforceStrategy.executeAllowDecision(policyResult);

    expect(req.body.configuration.extract.sourceTable).toEqual(newTable);
    expect(next).toBeCalledTimes(1);
  });

  test('reassign sourceTable after insert a query job', async () => {
    const req = ({
      headers: {
        authorization: 'auth_token',
      },
      params: {
        projectId: 'projectId',
      },
      body: {
        configuration: {
          extract: {
            sourceTable: {
              projectId: 'projectId',
              datasetId: 'datasetId',
              tableId: 'tableId',
            },
          },
        },
      },
      get: jest.fn().mockReturnValue('uid'),
    } as unknown) as Request;

    const enforceStrategy = new JobsInsertExtractEnforceStrategy(req, res, next);

    const policyResult: PolicyResult = {
      enforcer_result: 'allow',
      safe_sql: 'SELECT * FROM TEST_TABLE',
      error: 'error message',
    };

    const jobInfo: IJob = {
      configuration: {
        query: {
          destinationTable: newTable,
        },
      },
    };

    MockedBigQueryServer.prototype.insertJob.mockResolvedValueOnce(jobInfo);

    await enforceStrategy.executeAllowDecision(policyResult);

    expect(req.body.configuration.extract.sourceTable).toEqual(newTable);
    expect(next).toBeCalledTimes(1);
  });
});
