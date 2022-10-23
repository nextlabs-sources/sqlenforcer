import { Request, Response } from 'express';

import BigQueryServer from '../../common/BigQueryServer';
import EnforcerModuleServer from '../../common/EnforcerModuleServer';
import TabledataListEnforceStrategy from '../TabledataListEnforceStrategy';

import { PolicyResult } from '../../common/interfaces';
import { IJob } from '../../common/types';

jest.mock('../../common/BigQueryServer');
jest.mock('../../common/EnforcerModuleServer');

const MockedBigQueryServer = BigQueryServer as jest.MockedClass<typeof BigQueryServer>;
const MockedEnforcerModuleServer = EnforcerModuleServer as jest.Mocked<typeof EnforcerModuleServer>;

describe('executeAllowDecision()', () => {
  const res = {} as Response;
  const next = jest.fn();
  const originalTable = {
    projectId: 'originalProjectId',
    datasetId: 'originalDatasetId',
    tableId: 'originalTableId',
  };
  const newTable = {
    projectId: 'newProjectId',
    datasetId: 'newDatasetId',
    tableId: 'newTableId',
  };
  const originalUrl = `https://bigquery.googleapis.com/bigquery/v2/projects/${originalTable.projectId}/datasets/${originalTable.datasetId}/tables/${originalTable.tableId}/data`;
  const newUrl = `https://bigquery.googleapis.com/bigquery/v2/projects/${newTable.projectId}/datasets/${newTable.datasetId}/tables/${newTable.tableId}/data`;

  const req = ({
    headers: {},
    params: originalTable,
    originalUrl,
    get: jest.fn().mockReturnValue('uid'),
  } as unknown) as Request;

  const enforceStrategy = new TabledataListEnforceStrategy(req, res, next);

  beforeEach(() => {
    next.mockClear();
    req.originalUrl = originalUrl;
    MockedBigQueryServer.prototype.insertJob.mockClear();
    MockedEnforcerModuleServer.cacheRedirectResult.mockClear();
  });

  test('cache', async () => {
    const policyResult: PolicyResult = {
      enforcer_result: 'allow',
      safe_sql: 'SELECT * FROM TEST_TABLE',
      error: 'error message',
      redirectTableRef: newTable,
    };

    await enforceStrategy.executeAllowDecision(policyResult);

    expect(req.originalUrl).toEqual(newUrl);
    expect(next).toBeCalledTimes(1);
    expect(MockedBigQueryServer.prototype.insertJob).not.toBeCalled();
    expect(MockedEnforcerModuleServer.cacheRedirectResult).not.toBeCalled();
  });

  test('insert job', async () => {
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

    expect(req.originalUrl).toEqual(newUrl);
    expect(next).toBeCalledTimes(1);
    expect(MockedBigQueryServer.prototype.insertJob).toBeCalledTimes(1);
    expect(MockedEnforcerModuleServer.cacheRedirectResult).toBeCalledTimes(1);
  });
});
