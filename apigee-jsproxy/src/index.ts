import express from 'express';

import jobsQueryRouter from './routes/jobsQuery';
import jobsInsertRouter from './routes/jobsInsert';
import tabledataListRouter from './routes/tabledataList';
import tabledataInsertAllRouter from './routes/tabledataInsertAll';

import { httpProxy } from './common/middlewares';

const app = express();

app.param(['projectId', 'jobId', 'datasetId', 'tableId'], (req, res, next, value, name) => {
  const queryParam = req.query[name] as string;

  if (queryParam) {
    req.params[name] = queryParam;
  }

  next();
});

app.use('/bigquery/v2/projects/:projectId/queries', jobsQueryRouter);
app.use('/bigquery/v2/projects/:projectId/jobs', jobsInsertRouter);

app.use(
  '/bigquery/v2/projects/:projectId/datasets/:datasetId/tables/:tableId/data',
  tabledataListRouter
);
app.use(
  '/bigquery/v2/projects/:projectId/datasets/:datasetId/tables/:tableId/insertAll',
  tabledataInsertAllRouter
);

app.all('/*', httpProxy);

app.listen(process.env.PORT || 3000, () => {
  console.log('Node HTTP server is listening');
});
