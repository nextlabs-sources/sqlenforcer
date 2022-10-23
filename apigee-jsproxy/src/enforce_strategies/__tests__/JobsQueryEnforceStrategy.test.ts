import { Request, Response } from 'express';
import { PolicyResult } from '../../common/interfaces';
import JobsQueryEnforceStrategy from '../JobsQueryEnforceStrategy';

test('executeAllowDecision()', () => {
  const policyResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT * FROM TEST_TABLE WHERE 1 = 0',
    error: 'error message',
  };

  const req = {
    body: {
      query: 'SELECT * FROM TEST_TABLE',
    },
  } as Request;
  const res = {} as Response;
  const next = jest.fn();

  const enforceStrategy = new JobsQueryEnforceStrategy(req, res, next);
  enforceStrategy.executeAllowDecision(policyResult);

  expect(req.body.query).toEqual(policyResult.safe_sql);
  expect(next).toBeCalledTimes(1);
});
