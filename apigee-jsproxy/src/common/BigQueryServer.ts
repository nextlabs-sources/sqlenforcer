import Axios from 'axios';
import { v4 as uuidv4 } from 'uuid';

import Logger from './Logger';

import { IJob } from './types';
import { JOB_UUID_PREFIX } from './constants';

/** Class for interacting with BigQuery. */
export default class BigQueryServer {
  private projectId: string;

  private token: string;

  /**
   * Create a BigQuery server.
   * @param projectId The project ID from the Google Developer's Console.
   * @param token An OAUTH access token.
   */
  constructor(projectId: string, token: string) {
    this.projectId = projectId;
    this.token = token;
  }

  /**
   * Insert a job.
   * @param jobOptions The job config.
   * @returns The information about the created job.
   */
  public async insertJob(jobOptions: IJob): Promise<IJob> {
    const startTime: number = Date.now();

    const url = `https://bigquery.googleapis.com/bigquery/v2/projects/${this.projectId}/jobs`;
    const { data } = await Axios.post<IJob>(url, jobOptions, {
      headers: { authorization: this.token },
    });

    const error = data.status.errorResult;
    if (error) {
      throw new Error(JSON.stringify(error));
    }

    Logger.logDebug('Insert job', data.jobReference);
    Logger.logInfo(`Time for inserting job: ${Date.now() - startTime}ms`);
    return data;
  }

  /** Get UUID. */
  public static getUUID(): string {
    return JOB_UUID_PREFIX + uuidv4();
  }
}
