/** Class representing a token. */
export default class Token {
  private value: string;

  private expires: Date;

  /**
   * Create a token.
   * @param value The value of the token.
   * @param expires The date after which the token is considered stale.
   */
  constructor(value: string, expires: Date) {
    this.value = value;
    this.expires = expires;
  }

  /** Check if the token is expired. */
  public isExpired(): boolean {
    return Date.now() > this.expires.getTime();
  }

  /** Get the value of the token. */
  public getValue(): string {
    return this.value;
  }
}
