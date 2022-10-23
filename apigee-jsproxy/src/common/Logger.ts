import pino from 'pino';

import { logLevel } from './configInfo';
import { LogLevel } from './enums';

const log = pino({ level: process.env.LOGLEVEL || logLevel || LogLevel.warn });

/** Class for logging messages. */
export default class Logger {
  /**
   * Write a "fatal" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logFatal(msg: string, obj: Record<string, any> = null): void {
    log.fatal(obj, msg);
  }

  /**
   * Write a "error" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logError(msg: string, obj: Record<string, any> = null): void {
    log.error(obj, msg);
  }

  /**
   * Write a "warn" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logWarn(msg: string, obj: Record<string, any> = null): void {
    log.warn(obj, msg);
  }

  /**
   * Write a "info" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logInfo(msg: string, obj: Record<string, any> = null): void {
    log.info(obj, msg);
  }

  /**
   * Write a "debug" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logDebug(msg: string, obj: Record<string, any> = null): void {
    log.debug(obj, msg);
  }

  /**
   * Write a "trace" level log.
   * @param msg The summary of the log.
   * @param obj The obj to be logged.
   */
  public static logTrace(msg: string, obj: Record<string, any> = null): void {
    log.trace(obj, msg);
  }
}
