import BaseEnforceStrategy from './BaseEnforceStrategy';
import { PolicyResult } from '../common/interfaces';

/** Class representing the strategy to enforce security policy for jobs.query request.  */
export default class JobsQueryEnforceStrategy extends BaseEnforceStrategy {
  public async executeAllowDecision(policyResult: PolicyResult): Promise<void> {
    const { safe_sql: safeSQL } = policyResult;

    this.req.body.query = safeSQL;
    this.next();
  }
}
