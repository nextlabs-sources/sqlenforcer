/* eslint-disable no-new-wrappers */

import { isString, isPlainObject, isArray, isUndefined, serializeObj } from '..';

describe('isString()', () => {
  test('returns true when check a string primitive or object', () => {
    expect(isString('false')).toEqual(true);
    expect(isString(new String('false'))).toEqual(true);
  });

  test('returns false when check a boolean primitive or object', () => {
    expect(isString(false)).toEqual(false);
    expect(isString(new Boolean(false))).toEqual(false);
  });
});

describe('isPlainObject()', () => {
  test('returns true when check a plain object', () => {
    expect(isPlainObject({})).toEqual(true);
  });

  test('returns false when check a array ', () => {
    expect(isPlainObject([])).toEqual(false);
  });
});

describe('isArray()', () => {
  test('returns true when check a array', () => {
    expect(isArray([])).toEqual(true);
  });

  test('returns false when check a string ', () => {
    expect(isArray('Sun Jun 21 2020 23:27:35 GMT+0800 (China Standard Time)')).toEqual(false);
  });
});

describe('isUndefined()', () => {
  test('returns true when check undefined', () => {
    expect(isUndefined(undefined)).toEqual(true);
  });

  test('returns false when check other type value', () => {
    expect(isUndefined(null)).toEqual(false);
    expect(isUndefined(true)).toEqual(false);
    expect(isUndefined(false)).toEqual(false);
    expect(isUndefined(2123)).toEqual(false);
    expect(isUndefined('strrrring')).toEqual(false);
    expect(isUndefined({})).toEqual(false);
    expect(isUndefined([])).toEqual(false);
    expect(isUndefined(Symbol('sym'))).toEqual(false);
  });
});

test('serializeObj()', () => {
  JSON.stringify = jest.fn();
  const obj = { a: 2342 };

  serializeObj(obj);

  expect(JSON.stringify).toBeCalledTimes(1);
});
