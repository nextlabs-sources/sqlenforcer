import BaseEnforceStrategy from './BaseEnforceStrategy';
import { PolicyResult } from '../common/interfaces';
import BigQueryServer from '../common/BigQueryServer';
import { IJob, ITableReference } from '../common/types';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import { useMultipleGoogleAccounts } from '../common/configInfo';

/** Class representing the strategy to enforce security policy for tabledata.list request.  */
export default class TabledataListEnforceStrategy extends BaseEnforceStrategy {
  public async executeAllowDecision(policyResult: PolicyResult): Promise<void> {
    const uid: string = this.req.get('uid');
    const accessToken: string = useMultipleGoogleAccounts
      ? this.req.get('authorization')
      : undefined;

    const { safe_sql: safeSQL, redirectTableRef: newTable } = policyResult;
    const {
      headers: { authorization },
      params: { projectId, datasetId, tableId },
    } = this.req;

    if (newTable) {
      const { projectId: newProjectId, datasetId: newDatasetId, tableId: newTableId } = newTable;
      this.req.originalUrl = this.req.originalUrl
        .replace(projectId, newProjectId)
        .replace(datasetId, newDatasetId)
        .replace(tableId, newTableId);
      this.next();
      return;
    }

    const bigquery = new BigQueryServer(projectId, authorization);
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

    const job = await bigquery.insertJob(jobOptions);

    const { destinationTable: redirectTableRef } = job.configuration.query;
    const {
      projectId: newProjectId,
      datasetId: newDatasetId,
      tableId: newTableId,
    } = redirectTableRef;

    this.req.originalUrl = this.req.originalUrl
      .replace(projectId, newProjectId)
      .replace(datasetId, newDatasetId)
      .replace(tableId, newTableId);

    const tableReference: ITableReference = {
      projectId,
      datasetId,
      tableId,
    };

    EnforcerModuleServer.cacheRedirectResult(
      uid,
      tableReference,
      {
        ...policyResult,
        redirectTableRef,
      },
      accessToken
    );

    this.next();
  }
}
