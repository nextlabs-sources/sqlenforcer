import { Agent } from 'https';

export const JOB_UUID_PREFIX = 'nxl_job_';
export const FACK_VALUE = 'FACK_VALUE';
export const HTTPS_AGENT = new Agent({
  rejectUnauthorized: false,
  keepAlive: true,
});
