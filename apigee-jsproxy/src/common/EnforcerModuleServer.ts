import Axios, { AxiosError } from 'axios';
import querystring from 'querystring';

import Logger from './Logger';
import { ITableReference } from './types';
import { PolicyResult, RawToken } from './interfaces';
import { enforcerURL, authConfig } from './configInfo';
import { isUndefined } from '../util';
import Token from './Token';
import { HTTPS_AGENT } from './constants';

/** Class for interacting with enforcer module server. */
export default class EnforcerModuleServer {
  private static accessToken: Token;

  /**
   * Get the policy result from enforcer module server.
   * @param uid The application user ID.
   * @param sql The SQL to be enforced.
   * @param tableReference The reference of the table to be enforced.
   * @param useCachedRedirectResult: A boolean flag for indicating whether use cached redirect
   * result which contains enforcer result and redirect table reference. If true, maybe it will
   * use cache for it.
   * @param bigQueryAccessToken: Access token for BigQuery. Used as one part of the cache key when it exists.
   */
  public static async getPolicyResult(
    uid: string,
    sql: string,
    tableReference: ITableReference,
    useCachedRedirectResult = false,
    bigQueryAccessToken?: string
  ): Promise<PolicyResult> {
    const startTime: number = Date.now();

    const url = `${enforcerURL}/emdb/bigquery/enforce`;
    const { projectId = '', datasetId = '', tableId = '' } = tableReference;
    const body = {
      uid,
      accessToken: bigQueryAccessToken,
      sql,
      database: projectId,
      schema: datasetId,
      table: tableId,
    };

    await EnforcerModuleServer.ensureExistFreshToken();

    const { data } = await Axios.post<PolicyResult>(url, body, {
      headers: {
        Authorization: EnforcerModuleServer.accessToken.getValue(),
        'content-type': 'application/json;charset=utf-8',
      },
      params: {
        useCachedRedirectResult,
      },
      httpsAgent: HTTPS_AGENT,
    });

    Logger.logDebug('Policy Result', data);
    Logger.logInfo(`Time for getting policy result: ${Date.now() - startTime}ms`);
    return data;
  }

  /**
   * Cache the redirect result which contains enforcer result and redirect table reference.
   * @param uid The application user ID.
   * @param tableRef The reference for the enforced table.
   * @param policyResult The policy result to be cached.
   * @param bigQueryAccessToken: Access token for BigQuery. Used as one part of the cache key when it exists.
   * @param expiresIn The seconds after which the cache will be clear.
   */
  public static async cacheRedirectResult(
    uid: string,
    tableRef: ITableReference,
    policyResult: PolicyResult,
    bigQueryAccessToken?: string,
    expiresIn = 24 * 60 * 60
  ): Promise<void> {
    try {
      const url = `${enforcerURL}/emdb/bigquery/caches/redirectResult`;

      const body = {
        uid,
        accessToken: bigQueryAccessToken,
        tableRef,
        redirectResult: policyResult,
      };

      await EnforcerModuleServer.ensureExistFreshToken();

      await Axios.post(url, body, {
        headers: {
          Authorization: EnforcerModuleServer.accessToken.getValue(),
        },
        params: { expiresIn },
        httpsAgent: HTTPS_AGENT,
      });

      Logger.logDebug('Cache policy result', policyResult);
    } catch (err) {
      const error = err as AxiosError;

      if (error.response) {
        Logger.logError('Response error for caching redirect result', error.response);
      } else if (error.request) {
        Logger.logError('Request error for caching redirect result', error.request);
      } else {
        Logger.logError('Error for caching redirect result', error);
      }
    }
  }

  /**
   * Get token from enforcer module server.
   * @returns An instance of class Token.
   */
  public static async getTokenFromServer(): Promise<Token> {
    const startTime: number = Date.now();

    const url = `${enforcerURL}/emdb/bigquery/auth`;
    const { data } = await Axios.post<RawToken>(url, querystring.stringify(authConfig), {
      headers: { 'content-type': 'application/x-www-form-urlencoded' },
      httpsAgent: HTTPS_AGENT,
    });

    const { error, token_type: tokenType, access_token: accessToken, expires_in: maxAge } = data;

    if (error) {
      throw new Error(error);
    }

    const value = `${tokenType} ${accessToken}`;
    const expires = new Date(Date.now() + maxAge * 1000);
    const token = new Token(value, expires);

    Logger.logDebug('Get token from server.');
    Logger.logInfo(`Time for getting token from server: ${Date.now() - startTime}ms`);
    return token;
  }

  /** Ensure the token is exist and fresh. */
  private static async ensureExistFreshToken(): Promise<void> {
    if (
      isUndefined(EnforcerModuleServer.accessToken) ||
      EnforcerModuleServer.accessToken.isExpired()
    ) {
      const token = await EnforcerModuleServer.getTokenFromServer();
      EnforcerModuleServer.accessToken = token;
    }
  }
}
