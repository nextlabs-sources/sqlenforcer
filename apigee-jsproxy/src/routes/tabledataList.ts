import { AxiosError } from 'axios';
import bodyParser from 'body-parser';
import express, { RequestHandler } from 'express';

import Logger from '../common/Logger';
import { serializeObj } from '../util';
import Enforcer from '../common/Enforcer';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import TabledataListEnforceStrategy from '../enforce_strategies/TabledataListEnforceStrategy';

import { PolicyResult } from '../common/interfaces';
import { useMultipleGoogleAccounts } from '../common/configInfo';

const enforce: RequestHandler = async (req, res, next): Promise<void> => {
  const startTime: number = Date.now();

  try {
    const uid: string = req.get('uid');
    const accessToken: string = useMultipleGoogleAccounts ? req.get('authorization') : undefined;

    const { projectId, datasetId, tableId } = req.params;
    const sql = `SELECT * FROM ${datasetId}.${tableId}`;

    const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(
      uid,
      sql,
      {
        projectId,
        datasetId,
        tableId,
      },
      true,
      accessToken
    );

    const strategy = new TabledataListEnforceStrategy(req, res, next);
    const enforcer = new Enforcer(policyResult, strategy);

    await enforcer.execute();
  } catch (err) {
    const error = err as AxiosError;

    if (error.response) {
      const { status, data } = error.response;
      res.status(status).send(data);

      Logger.logError('Response Error', error.response);
      Logger.logInfo(`Total time for enforcing tabledata.list: ${Date.now() - startTime}ms`);
      return;
    }

    next(error);
    Logger.logError('Error', error);
  }

  Logger.logInfo(`Total time for enforcing tabledata.list: ${Date.now() - startTime}ms`);
};

const router = express.Router({ mergeParams: true });

router.get('/', enforce);

export default router;
