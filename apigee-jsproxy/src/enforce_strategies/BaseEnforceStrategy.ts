import { Request, Response, NextFunction } from 'express';

import PROMPTS from '../common/prompts';
import { PolicyResult } from '../common/interfaces';

/** Class representing the base strategy to enforce security policy. */
export default class BaseEnforceStrategy {
  protected req: Request;

  protected res: Response;

  protected next: NextFunction;

  /**
   * Create a base strategy to enforce security policy.
   * @param req The request object.
   * @param res The response object.
   * @param next Indicating the next middleware function.
   */
  constructor(req: Request, res: Response, next: NextFunction) {
    this.req = req;
    this.res = res;
    this.next = next;
  }

  /**
   * Enforce failed decision of the security policy result.
   * @param policyResult The security policy result which will be enforced.
   */
  public async executeFailedDecision(policyResult: PolicyResult): Promise<void> {
    const { error } = policyResult;
    this.res.status(500).send(error);
  }

  /**
   * Enforce deny decision of the security policy result.
   * @param policyResult The security policy result which will be enforced.
   */
  public async executeDenyDecision(policyResult: PolicyResult): Promise<void> {
    const { error } = policyResult;
    this.res.status(403).send(error);
  }

  /**
   * Enforce allow decision of the security policy result.
   * @param policyResult The security policy result which will be enforced.
   */
  public async executeAllowDecision(policyResult: PolicyResult): Promise<void> {
    this.next();
  }

  /**
   * Enforce ignore decision of the security policy result.
   * @param policyResult The security policy result which will be enforced.
   */
  public async executeIgnoreDecision(policyResult: PolicyResult): Promise<void> {
    this.next();
  }

  /**
   * Enforce default decision of the security policy result.
   * @param policyResult The security policy result which will be enforced.
   */
  public async executeDefaultDecision(policyResult: PolicyResult): Promise<void> {
    this.next(PROMPTS.noDefaultPolicyDecision);
  }
}
