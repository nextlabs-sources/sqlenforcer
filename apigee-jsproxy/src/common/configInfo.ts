import fs from 'fs';
import path from 'path';
import { ConfigInfo } from './interfaces';

export const {
  proxyTargetURL,
  enforcerURL,
  authConfig,
  useMultipleGoogleAccounts,
  logLevel,
} = JSON.parse(fs.readFileSync(path.resolve(__dirname, 'config.json'), 'utf-8')) as ConfigInfo;
