import Token from '../Token';

const freshTokenValue = 'fresh_token_value';
const freshTokenExpires = new Date(Date.now() + 10000);
const freshToken = new Token(freshTokenValue, freshTokenExpires);

const expiredTokenValue = 'expired_token_value';
const expiredTokenExpires = new Date(Date.now());
const expiredToken = new Token(expiredTokenValue, expiredTokenExpires);

test('constructor()', () => {
  expect(freshToken).toEqual({
    value: freshTokenValue,
    expires: freshTokenExpires,
  });
});

describe('isExpired()', () => {
  test('return true when the token is expired', () => {
    expect(expiredToken.isExpired()).toEqual(true);
  });

  test('return false when the token is not expired', () => {
    expect(freshToken.isExpired()).toEqual(false);
  });
});

test('getValue()', () => {
  expect(freshToken.getValue()).toEqual(freshTokenValue);
});
