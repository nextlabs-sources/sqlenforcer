/**
 * Checks if value is classified as a `String` primitive or object.
 * @param value The value to check.
 * @returns Returns `true` if value is a string, else `false`.
 */
export function isString(value: any): value is string {
  return Object.prototype.toString.call(value) === '[object String]';
}

/**
 * Checks if value is a plain object, that is,
 * an object created by the Object constructor or one with a [[Prototype]] of null.
 * @param value The value to check.
 * @returns Returns `true` if value is a plain object, else `false`.
 */
export function isPlainObject(value: any): value is Record<string, any> {
  return Object.prototype.toString.call(value) === '[object Object]';
}

/**
 * Checks if value is classified as a `Array` object.
 * @param value The value to check.
 * @returns Returns `true` if value is a array, else `false`.
 */
export function isArray(value: any): value is Array<any> {
  return Object.prototype.toString.call(value) === '[object Array]';
}

/**
 * Checks if value is undefined.
 * @param value The value to check.
 * @returns Returns `true` if value is undefined, else `false`.
 */
export function isUndefined(value: any): value is undefined {
  return value === undefined;
}

/**
 * Serialize and format the object.
 * @param obj The object to be serialized adn formatted.
 */
export function serializeObj(obj: Record<string, any>): string {
  const space = 2;
  return JSON.stringify(obj, null, space);
}
