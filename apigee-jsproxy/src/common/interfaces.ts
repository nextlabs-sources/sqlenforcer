import { LogLevel } from './enums';
import { ITableReference } from './types';

export interface CacheObj {
  accessEMDBToken?: {
    token: string;
    expires: number;
  };
}

export interface RawToken {
  error: string;
  access_token: string;
  token_type: string;
  expires_in: number;
}

export interface PolicyResult {
  enforcer_result: 'allow' | 'deny' | 'ignore' | 'failed';
  safe_sql: string;
  error: string;
  redirectTableRef?: ITableReference;
}

export interface ConfigInfo {
  proxyTargetURL: string;
  enforcerURL: string;
  authConfig: {
    grant_type: string;
    client_id: string;
    client_secret: string;
    expires_in: number;
  };
  useMultipleGoogleAccounts: boolean;
  logLevel: LogLevel;
}
