import { AxiosError } from 'axios';
import bodyParser from 'body-parser';
import express, { Router, RequestHandler } from 'express';

import { isArray } from '../util';
import Logger from '../common/Logger';
import Enforcer from '../common/Enforcer';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import JobsQueryEnforceStrategy from '../enforce_strategies/JobsQueryEnforceStrategy';

import { PolicyResult } from '../common/interfaces';
import { IQueryRequest } from '../common/types';

const enforce: RequestHandler = async (req, res, next): Promise<void> => {
  const startTime: number = Date.now();

  try {
    const uid = req.get('uid');
    const { query, defaultDataset = {} } = req.body as IQueryRequest;
    const { projectId } = req.params;

    const querySQL = isArray(query) ? query[0] : query;

    const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(uid, querySQL, {
      projectId,
      ...defaultDataset,
    });

    const strategy = new JobsQueryEnforceStrategy(req, res, next);
    const enforcer = new Enforcer(policyResult, strategy);

    await enforcer.execute();
  } catch (err) {
    const error = err as AxiosError;

    if (error.response) {
      const { status, data } = error.response;
      res.status(status).send(data);

      Logger.logError('Response Error', error.response);
      Logger.logInfo(`Total time for enforcing jobs.query: ${Date.now() - startTime}ms`);
      return;
    }

    Logger.logError('Error', error);
    next(error);
  }

  Logger.logInfo(`Total time for enforcing jobs.query: ${Date.now() - startTime}ms`);
};

const router: Router = express.Router({ mergeParams: true });

router.post(
  '/',
  bodyParser.json({
    type: (req) => true,
  }),
  enforce
);

export default router;
