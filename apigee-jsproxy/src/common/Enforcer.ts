import Logger from './Logger';
import BaseEnforceStrategy from '../enforce_strategies/BaseEnforceStrategy';

import { PolicyResult } from './interfaces';

/** Class representing an enforcer to enforce the policy result based on an enforce strategy. */
export default class Enforcer {
  private policyResult: PolicyResult;

  private enforceStrategy: BaseEnforceStrategy;

  /**
   * Create an enforcer.
   * @param policyResult The policy result to be enforced.
   * @param enforceStrategy The enforce strategy used for enforcing.
   */
  constructor(policyResult: PolicyResult, enforceStrategy: BaseEnforceStrategy) {
    this.policyResult = policyResult;
    this.enforceStrategy = enforceStrategy;
  }

  /** Enforce the policy result based on the enforce strategy. */
  public async execute(): Promise<void> {
    const { enforcer_result: decision } = this.policyResult;

    switch (decision) {
      case 'failed':
        await this.enforceStrategy.executeFailedDecision(this.policyResult);
        Logger.logInfo('Enforced policy result: failed.');
        break;
      case 'deny':
        await this.enforceStrategy.executeDenyDecision(this.policyResult);
        Logger.logInfo('Enforced policy result: deny.');
        break;
      case 'allow':
        await this.enforceStrategy.executeAllowDecision(this.policyResult);
        Logger.logInfo('Enforced policy result: allow.');
        break;
      case 'ignore':
        await this.enforceStrategy.executeIgnoreDecision(this.policyResult);
        Logger.logInfo('Enforced policy result: ignore.');
        break;
      default:
        await this.enforceStrategy.executeDefaultDecision(this.policyResult);
        Logger.logInfo('Enforced policy result: default.');
    }
  }
}
