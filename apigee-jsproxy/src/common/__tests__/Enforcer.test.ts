import { Request, Response } from 'express';

import Enforcer from '../Enforcer';
import BaseEnforceStrategy from '../../enforce_strategies/BaseEnforceStrategy';

import { PolicyResult } from '../interfaces';

jest.mock('../../enforce_strategies/BaseEnforceStrategy');

const MockedBaseEnforceStrategy = BaseEnforceStrategy as jest.MockedClass<
  typeof BaseEnforceStrategy
>;

test('constructor()', () => {
  const policyResult = {} as PolicyResult;
  const enforceStrategy = {} as BaseEnforceStrategy;

  const enforcer = new Enforcer(policyResult, enforceStrategy);
  expect(enforcer).toEqual({
    policyResult,
    enforceStrategy,
  });
});

describe('execute()', () => {
  const req = {} as Request;
  const res = {} as Response;
  const next = jest.fn();
  const enforceStrategy = new MockedBaseEnforceStrategy(req, res, next);

  beforeEach(() => {
    MockedBaseEnforceStrategy.prototype.executeFailedDecision.mockClear();
    MockedBaseEnforceStrategy.prototype.executeDenyDecision.mockClear();
    MockedBaseEnforceStrategy.prototype.executeAllowDecision.mockClear();
    MockedBaseEnforceStrategy.prototype.executeIgnoreDecision.mockClear();
    MockedBaseEnforceStrategy.prototype.executeDefaultDecision.mockClear();
  });

  test('enforce failed decision', async () => {
    const policyResult: PolicyResult = {
      enforcer_result: 'failed',
      safe_sql: 'safe_sql',
      error: 'error',
    };

    const enforcer = new Enforcer(policyResult, enforceStrategy);

    await enforcer.execute();

    expect(MockedBaseEnforceStrategy.prototype.executeDenyDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeAllowDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeIgnoreDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDefaultDecision).not.toBeCalled();

    expect(MockedBaseEnforceStrategy.prototype.executeFailedDecision).toBeCalledWith(policyResult);
  });

  test('enforce deny decision', async () => {
    const policyResult: PolicyResult = {
      enforcer_result: 'deny',
      safe_sql: 'safe_sql',
      error: 'error',
    };
    const enforcer = new Enforcer(policyResult, enforceStrategy);

    await enforcer.execute();

    expect(MockedBaseEnforceStrategy.prototype.executeFailedDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeAllowDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeIgnoreDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDefaultDecision).not.toBeCalled();

    expect(MockedBaseEnforceStrategy.prototype.executeDenyDecision).toBeCalledWith(policyResult);
  });

  test('enforce allow decision', async () => {
    const policyResult: PolicyResult = {
      enforcer_result: 'allow',
      safe_sql: 'safe_sql',
      error: 'error',
    };
    const enforcer = new Enforcer(policyResult, enforceStrategy);

    await enforcer.execute();

    expect(MockedBaseEnforceStrategy.prototype.executeFailedDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDenyDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeIgnoreDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDefaultDecision).not.toBeCalled();

    expect(MockedBaseEnforceStrategy.prototype.executeAllowDecision).toBeCalledWith(policyResult);
  });

  test('enforce ignore decision', async () => {
    const policyResult: PolicyResult = {
      enforcer_result: 'ignore',
      safe_sql: 'safe_sql',
      error: 'error',
    };
    const enforcer = new Enforcer(policyResult, enforceStrategy);

    await enforcer.execute();

    expect(MockedBaseEnforceStrategy.prototype.executeFailedDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDenyDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeAllowDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDefaultDecision).not.toBeCalled();

    expect(MockedBaseEnforceStrategy.prototype.executeIgnoreDecision).toBeCalledWith(policyResult);
  });

  test('enforce default decision', async () => {
    const policyResult: unknown = {
      enforcer_result: 'other',
      safe_sql: 'safe_sql',
      error: 'error',
    };
    const enforcer = new Enforcer(policyResult as PolicyResult, enforceStrategy);

    await enforcer.execute();

    expect(MockedBaseEnforceStrategy.prototype.executeFailedDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeDenyDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeAllowDecision).not.toBeCalled();
    expect(MockedBaseEnforceStrategy.prototype.executeIgnoreDecision).not.toBeCalled();

    expect(MockedBaseEnforceStrategy.prototype.executeDefaultDecision).toBeCalledWith(policyResult);
  });
});
