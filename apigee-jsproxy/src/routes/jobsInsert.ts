import { AxiosError } from 'axios';
import bodyParser from 'body-parser';
import express, { RequestHandler } from 'express';

import { isArray } from '../util';
import Logger from '../common/Logger';
import Enforcer from '../common/Enforcer';
import EnforcerModuleServer from '../common/EnforcerModuleServer';
import BaseEnforceStrategy from '../enforce_strategies/BaseEnforceStrategy';
import JobsInsertQueryEnforceStrategy from '../enforce_strategies/JobsInsertQueryEnforceStrategy';
import JobsInsertExtractEnforceStrategy from '../enforce_strategies/JobsInsertExtractEnforceStrategy';

import { IJob } from '../common/types';
import { FACK_VALUE } from '../common/constants';
import { PolicyResult } from '../common/interfaces';
import { useMultipleGoogleAccounts } from '../common/configInfo';

const enforceQuery: RequestHandler = async (req, res, next): Promise<void> => {
  const uid = req.get('uid');
  const { query, defaultDataset = {} } = (req.body as IJob).configuration.query;
  const { projectId } = req.params;

  const querySQL = isArray(query) ? query[0] : query;

  const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(uid, querySQL, {
    projectId,
    ...defaultDataset,
  });

  const strategy = new JobsInsertQueryEnforceStrategy(req, res, next);
  const enforcer = new Enforcer(policyResult, strategy);

  await enforcer.execute();
};

const enforceLoad: RequestHandler = async (req, res, next) => {
  const uid = req.get('uid');
  const { destinationTable } = (req.body as IJob).configuration.load;
  const {
    projectId: destProjectId,
    datasetId: destDatasetId,
    tableId: destTableId,
  } = destinationTable;

  const insertSQL = `INSERT INTO ${destProjectId}.${destDatasetId}.${destTableId} VALUES ("${FACK_VALUE}")`;

  const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(
    uid,
    insertSQL,
    destinationTable
  );

  const enforceStrategy = new BaseEnforceStrategy(req, res, next);
  const enforcer = new Enforcer(policyResult, enforceStrategy);

  await enforcer.execute();
};

const enforceExtract: RequestHandler = async (req, res, next) => {
  const accessToken: string = useMultipleGoogleAccounts ? req.get('authorization') : undefined;

  const { sourceTable } = (req.body as IJob).configuration.extract;

  if (sourceTable) {
    const uid = req.get('uid');
    const { projectId: srcProjectId, datasetId: srcDatasetId, tableId: srcTableId } = sourceTable;
    const selectSQL = `SELECT * FROM ${srcProjectId}.${srcDatasetId}.${srcTableId}`;
    const policyResult: PolicyResult = await EnforcerModuleServer.getPolicyResult(
      uid,
      selectSQL,
      sourceTable,
      true,
      accessToken
    );
    const enforceStrategy = new JobsInsertExtractEnforceStrategy(req, res, next);
    const enforcer = new Enforcer(policyResult, enforceStrategy);

    await enforcer.execute();
    return;
  }

  next();
};

const enforce: RequestHandler = async (req, res, next): Promise<void> => {
  const startTime: number = Date.now();

  const reqBody = req.body as IJob;
  const { query, load, copy, extract } = reqBody.configuration;

  try {
    if (query) {
      await enforceQuery(req, res, next);
    } else if (load) {
      await enforceLoad(req, res, next);
    } else if (extract) {
      await enforceExtract(req, res, next);
    } else {
      next();
    }
  } catch (err) {
    const error = err as AxiosError;

    if (error.response) {
      const { status, data } = error.response;
      res.status(status).send(data);

      Logger.logError('Response Error for inserting the job', error.response);
      Logger.logInfo(`Total time for enforcing: ${Date.now() - startTime}ms`);
      return;
    }

    Logger.logError('Error', error);
    next(error);
  }

  Logger.logInfo(`Total time for enforcing jobs.insert: ${Date.now() - startTime}ms`);
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
