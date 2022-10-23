import https from 'https';
import { RequestHandler } from 'express';

import Logger from './Logger';
import { isUndefined } from '../util';
import { HTTPS_AGENT } from './constants';
import { proxyTargetURL } from './configInfo';

const proxyTarget = new URL(proxyTargetURL);

/** Proxy request to target URL and re-stream the parsed body before proxy. */
export const httpProxy: RequestHandler = (req, res, next) => {
  req.on('error', (err) => {
    res.writeHead(500, {
      'Content-Type': 'text/plain',
    });
    Logger.logError('Request error for proxying: ', err);
    res.end(JSON.stringify(err));
  });

  res.on('error', (err) => {
    Logger.logError('Response error for proxying: ', err);
  });

  const options: https.RequestOptions = {
    host: proxyTarget.hostname,
    port: proxyTarget.port,
    path: req.originalUrl,
    method: req.method,
    headers: req.headers,
    agent: HTTPS_AGENT,
  };

  const proxyReq = https.request(options, (proxyRes) => {
    res.writeHead(proxyRes.statusCode, proxyRes.headers);
    proxyRes.pipe(res);
  });

  proxyReq.on('error', (err) => {
    Logger.logError('Proxy error for proxying: ', err);
    res.writeHead(500, {
      'Content-Type': 'text/plain',
    });
    res.end(JSON.stringify(err));
  });

  proxyReq.setHeader('host', proxyTarget.host);

  if (isUndefined(req.body)) {
    req.pipe(proxyReq);
    return;
  }

  const body = Buffer.from(JSON.stringify(req.body));
  proxyReq.setHeader('content-length', body.length);
  proxyReq.write(body);
  proxyReq.end();
};
