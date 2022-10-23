import { Request } from 'express';
import { PolicyResult } from '../../common/interfaces';
import PROMPTS from '../../common/prompts';
import BaseEnforceStrategy from '../BaseEnforceStrategy';

const req = {} as Request;
const res: any = {
  status: jest.fn().mockReturnThis(),
  send: jest.fn().mockReturnThis(),
};
const next = jest.fn();

const enforceStrategy = new BaseEnforceStrategy(req, res, next);

beforeEach(() => {
  res.status.mockClear();
  res.send.mockClear();
  next.mockClear();
});

test('constructor()', () => {
  expect(enforceStrategy).toEqual({ req, res, next });
});

test('executeFailedDecision()', () => {
  const policyResult: PolicyResult = {
    enforcer_result: 'failed',
    safe_sql: 'SELECT * FROM TEST_TABLE',
    error: 'error massage',
  };

  enforceStrategy.executeFailedDecision(policyResult);

  expect(res.status).toBeCalledWith(500);
  expect(res.send).toBeCalledWith(policyResult.error);
});

test('executeDenyDecision()', () => {
  const policyResult: PolicyResult = {
    enforcer_result: 'deny',
    safe_sql: 'SELECT * FROM TEST_TABLE',
    error: 'error massage',
  };

  enforceStrategy.executeDenyDecision(policyResult);

  expect(res.status).toBeCalledWith(403);
  expect(res.send).toBeCalledWith(policyResult.error);
});

test('executeAllowDecision()', () => {
  const policyResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT * FROM TEST_TABLE',
    error: 'error massage',
  };

  enforceStrategy.executeAllowDecision(policyResult);

  expect(next).toBeCalledTimes(1);
});

test('executeIgnoreDecision()', () => {
  enforceStrategy.executeIgnoreDecision({} as PolicyResult);
  expect(next).toBeCalledTimes(1);
});

test('executeDefaultDecision()', () => {
  const policyResult: unknown = {
    enforcer_result: 'other',
    safe_sql: 'SELECT * FROM TEST_TABLE',
    error: 'error massage',
  };

  enforceStrategy.executeDefaultDecision(policyResult as PolicyResult);

  expect(next).toBeCalledWith(PROMPTS.noDefaultPolicyDecision);
});
