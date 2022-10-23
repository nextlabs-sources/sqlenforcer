import BaseEnforceStrategy from './BaseEnforceStrategy';
import BigQueryServer from '../common/BigQueryServer';

import { IJob } from '../common/types';
import { PolicyResult } from '../common/interfaces';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import { useMultipleGoogleAccounts } from '../common/configInfo';

/** Class representing the strategy to enforce security policy for jobs.insert:extract request.  */
export default class JobsInsertExtractEnforceStrategy extends BaseEnforceStrategy {
  public async executeAllowDecision(policyResult: PolicyResult): Promise<void> {
    const { safe_sql: safeSQL, redirectTableRef: newTable } = policyResult;
    const reqBody = this.req.body as IJob;

    const { sourceTable } = reqBody.configuration.extract;

    if (newTable) {
      reqBody.configuration.extract.sourceTable = newTable;

      this.next();
      return;
    }

    const uid: string = this.req.get('uid');
    const accessToken: string = useMultipleGoogleAccounts
      ? this.req.get('authorization')
      : undefined;

    const {
      params: { projectId },
      headers: { authorization },
    } = this.req;
    const jobId: string = BigQueryServer.getUUID();
    const jobOptions: IJob = {
      configuration: {
        query: {
          query: safeSQL,
          useLegacySql: false,
        },
      },
      jobReference: {
        projectId,
        jobId,
      },
    };

    const bigquery = new BigQueryServer(projectId, authorization);
    const job = await bigquery.insertJob(jobOptions);

    const redirectTableRef = job.configuration.query.destinationTable;

    EnforcerModuleServer.cacheRedirectResult(
      uid,
      sourceTable,
      {
        ...policyResult,
        redirectTableRef,
      },
      accessToken
    );

    reqBody.configuration.extract.sourceTable = redirectTableRef;

    this.next();
  }
}
