import BaseEnforceStrategy from './BaseEnforceStrategy';

import { IJob } from '../common/types';
import { PolicyResult } from '../common/interfaces';

/** Class representing the strategy to enforce security policy for jobs.insert:query request.  */
export default class JobsInsertQueryEnforceStrategy extends BaseEnforceStrategy {
  public async executeAllowDecision(policyResult: PolicyResult): Promise<void> {
    const { safe_sql: safeSQL } = policyResult;

    (this.req.body as IJob).configuration.query.query = safeSQL;

    this.next();
  }
}
