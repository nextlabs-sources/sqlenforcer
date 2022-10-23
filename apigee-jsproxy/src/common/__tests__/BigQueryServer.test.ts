import Axios from 'axios';
import { v4 as uuidv4 } from 'uuid';
import BigQueryServer from '../BigQueryServer';
import { JOB_UUID_PREFIX } from '../constants';
import { IJob } from '../types';

jest.mock('axios');
jest.mock('uuid');

const mockedAxios = Axios as jest.Mocked<typeof Axios>;
const mockedUUIDV4 = uuidv4 as jest.Mock;

test('constructor()', () => {
  const projectId = 'projectId';
  const token = 'token';

  const bigquery = new BigQueryServer(projectId, token);

  expect(bigquery).toEqual({
    projectId,
    token,
  });
});

describe('insertJob()', () => {
  test('return job info after successful insertion', async () => {
    const jobOptions: IJob = {
      configuration: {
        query: {
          query: 'select * from EMDB_1_2.customer',
          useLegacySql: false,
        },
      },
      status: {
        state: 'Running',
      },
    };
    const resp = { data: jobOptions };

    mockedAxios.post.mockResolvedValueOnce(resp);

    const projectId = 'jdbc-enforcer';
    const token = 'token';
    const bigquery = new BigQueryServer(projectId, token);
    const job = await bigquery.insertJob(jobOptions);

    expect(job).toEqual(jobOptions);
  });

  test('throw error', async () => {
    const jobOptions: IJob = {
      configuration: {
        query: {
          query: 'select * from EMDB_1_2.customer into',
        },
      },
    };

    const jobInfo: IJob = {
      kind: 'bigquery#job',
      etag: '86jQyqL0g04qyqRC134aSA==',
      id: 'jdbc-enforcer:US.job_IENTj3_Vb_pLTQmEYOQk3lligQ97',
      selfLink:
        'https://bigquery.googleapis.com/bigquery/v2/projects/jdbc-enforcer/jobs/job_IENTj3_Vb_pLTQmEYOQk3lligQ97?location=US',
      user_email: 'joy.wu@gcp.cloudaz.net',
      configuration: {
        query: {
          query: 'select * from EMDB_1_2.customer into',
          priority: 'INTERACTIVE',
        },
        jobType: 'QUERY',
      },
      jobReference: {
        projectId: 'jdbc-enforcer',
        jobId: 'job_IENTj3_Vb_pLTQmEYOQk3lligQ97',
        location: 'US',
      },
      statistics: {
        creationTime: '1600069157962',
        startTime: '1600069157972',
        endTime: '1600069157972',
      },
      status: {
        errorResult: {
          reason: 'invalidQuery',
          location: 'query',
          message:
            'Encountered " "INTO" "into "" at line 1, column 33.\nWas expecting:\n    <EOF> \n    ',
        },
        errors: [
          {
            reason: 'invalidQuery',
            location: 'query',
            message:
              'Encountered " "INTO" "into "" at line 1, column 33.\nWas expecting:\n    <EOF> \n    ',
          },
        ],
        state: 'DONE',
      },
    };

    const resp = { data: jobInfo };

    mockedAxios.post.mockResolvedValueOnce(resp);

    const projectId = 'jdbc-enforcer';
    const token = 'token';
    const bigquery = new BigQueryServer(projectId, token);

    await expect(bigquery.insertJob(jobOptions)).rejects.toEqual(
      new Error(JSON.stringify(jobInfo.status.errorResult))
    );
  });
});

test('getUUID()', () => {
  const uuid = 'test_uuid';
  mockedUUIDV4.mockImplementation(() => uuid);

  const uuidWithPrefix = BigQueryServer.getUUID();

  expect(mockedUUIDV4).toHaveBeenCalledTimes(1);
  expect(uuidWithPrefix).toBe(`${JOB_UUID_PREFIX}${uuid}`);
});
