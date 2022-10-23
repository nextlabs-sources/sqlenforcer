import { AxiosError } from 'axios';
import bodyParser from 'body-parser';
import express, { RequestHandler } from 'express';

import Logger from '../common/Logger';
import { serializeObj } from '../util';
import Enforcer from '../common/Enforcer';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import BaseEnforceStrategy from '../enforce_strategies/BaseEnforceStrategy';

import { FACK_VALUE } from '../common/constants';
import { PolicyResult } from '../common/interfaces';

const enforce: RequestHandler = async (req, res, next): Promise<void> => {
  const startTime: number = Date.now();

  try {
    const uid: string = req.get('uid');
    const {
      body: { templateSuffix },
      params: { projectId, datasetId, tableId },
    } = req;
    const newTableId: string = templateSuffix ? tableId + templateSuffix : tableId;
    const sql = `INSERT INTO ${projectId}.${datasetId}.${newTableId} VALUES ("${FACK_VALUE}")`;

    const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(uid, sql, {
      projectId,
      datasetId,
      tableId: newTableId,
    });

    const strategy = new BaseEnforceStrategy(req, res, next);
    const enforcer = new Enforcer(policyResult, strategy);

    await enforcer.execute();
  } catch (err) {
    const error = err as AxiosError;

    if (error.response) {
      const { status, data } = error.response;
      res.status(status).send(data);

      Logger.logError('Response Error', error.response);
      Logger.logInfo(`Total time for enforcing tabledata.insertAll: ${Date.now() - startTime}ms`);
      return;
    }

    Logger.logError('Error', error);
    next(error);
  }

  Logger.logInfo(`Total time for enforcing tabledata.insertAll: ${Date.now() - startTime}ms`);
};

const router = express.Router({ mergeParams: true });

router.post(
  '/',
  bodyParser.json({
    type: (req) => true,
  }),
  enforce
);

export default router;
