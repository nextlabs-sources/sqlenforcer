import Axios from 'axios';

import Logger from '../Logger';
import Token from '../Token';
import EnforcerModuleServer from '../EnforcerModuleServer';

import { ITableReference } from '../types';
import { PolicyResult } from '../interfaces';

jest.mock('axios');
jest.mock('../Logger');

const MockedAxios = Axios as jest.Mocked<typeof Axios>;
const MockedLogger = Logger as jest.Mocked<typeof Logger>;

beforeEach(() => {
  MockedAxios.post.mockReset();
});

describe('EnforcerModuleServer.getEnforcerResult()', () => {
  const uid = 'Louis';
  const sql = 'select * from EMDB_1_2.customer';
  const tableRef: ITableReference = {
    projectId: 'projectId',
    datasetId: 'datasetId',
    tableId: 'tableId',
  };
  const enforcerResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT *  FROM EMDB_1_2.customer_mask WHERE  1 = 0   ',
    error: "Denied by policy, value of 'effectType' is 'deny'",
  };
  const cachedEnforcerResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT *  FROM EMDB_1_2.customer_mask WHERE  1 = 0   ',
    error: "Denied by policy, value of 'effectType' is 'deny'",
    redirectTableRef: {
      projectId: 'newProjectId',
      datasetId: 'newDatasetId',
      tableId: 'newTableId',
    },
  };

  beforeAll(() => {
    (EnforcerModuleServer as any).ensureExistFreshToken = jest.fn();
    (EnforcerModuleServer as any).accessToken = {
      getValue: jest.fn().mockReturnValueOnce('token'),
    };
  });

  test('base', async () => {
    MockedAxios.post.mockResolvedValueOnce({ data: enforcerResult });

    const data = await EnforcerModuleServer.getPolicyResult(uid, sql, tableRef);

    expect(data).toEqual(enforcerResult);
  });

  test('use cache', async () => {
    MockedAxios.post.mockResolvedValueOnce({ data: cachedEnforcerResult });

    const data = await EnforcerModuleServer.getPolicyResult(uid, sql, tableRef, true);

    expect(data).toEqual(cachedEnforcerResult);
  });

  afterAll(() => {
    (EnforcerModuleServer as any).ensureExistFreshToken.mockReset();
    (EnforcerModuleServer as any).accessToken.mockReset();
  });
});

describe('EnforcerModuleServer.cachePolicyResultForTabledataList()', () => {
  const uid = 'Louis';
  const tableRef: ITableReference = {
    projectId: 'projectId',
    datasetId: 'datasetId',
    tableId: 'tableId',
  };
  const enforcerResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT *  FROM EMDB_1_2.customer_mask WHERE  1 = 0   ',
    error: "Denied by policy, value of 'effectType' is 'deny'",
    redirectTableRef: {
      projectId: 'newProjectId',
      datasetId: 'newDatasetId',
      tableId: 'newTableId',
    },
  };

  test('success', async () => {
    (EnforcerModuleServer as any).ensureExistFreshToken = jest.fn();
    MockedAxios.post.mockResolvedValueOnce({ status: 200 });

    await EnforcerModuleServer.cacheRedirectResult(uid, tableRef, enforcerResult);

    expect((EnforcerModuleServer as any).ensureExistFreshToken).toBeCalledTimes(1);
  });

  test('error', async () => {
    (EnforcerModuleServer as any).ensureExistFreshToken = jest.fn();
    MockedAxios.post.mockRejectedValueOnce({ status: 300 });

    await EnforcerModuleServer.cacheRedirectResult(uid, tableRef, enforcerResult);

    expect((EnforcerModuleServer as any).ensureExistFreshToken).toBeCalledTimes(1);
    expect(MockedLogger.logError).toBeCalled();
  });
});

test('EnforcerModuleServer.getTokenFromServer()', async () => {
  const rawToken = {
    access_token:
      'eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJhcGljbGllbnQiLCJpc3MiOiJuZXh0bGFicyIsImV4cCI6MTU5ODk1MjQzOX0.z2YkXYS8LHvlHlCEO7I94D4yhUID184FX_t25kvNCTQ',
    token_type: 'Bearer',
    expires_in: 3600,
  };

  MockedAxios.post.mockResolvedValueOnce({ data: rawToken });

  const token: Token = await EnforcerModuleServer.getTokenFromServer();
  expect(token.getValue()).toBe(`${rawToken.token_type} ${rawToken.access_token}`);
  expect(token.isExpired()).toBe(false);
});
