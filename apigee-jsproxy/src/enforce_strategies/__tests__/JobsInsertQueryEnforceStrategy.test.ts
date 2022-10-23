import { Request, Response } from 'express';
import { PolicyResult } from '../../common/interfaces';
import JobsInsertQueryEnforceStrategy from '../JobsInsertQueryEnforceStrategy';

test('executeAllowDecision()', () => {
  const policyResult: PolicyResult = {
    enforcer_result: 'allow',
    safe_sql: 'SELECT * FROM TEST_TABLE WHERE 1 = 0',
    error: 'error message',
  };

  const req = {
    body: {
      configuration: {
        query: {
          query: 'SELECT * FROM TEST_TABLE',
        },
      },
    },
  } as Request;
  const res = {} as Response;
  const next = jest.fn();

  const enforceStrategy = new JobsInsertQueryEnforceStrategy(req, res, next);
  enforceStrategy.executeAllowDecision(policyResult);

  expect(req.body.configuration.query.query).toEqual(policyResult.safe_sql);
  expect(next).toBeCalledTimes(1);
});
