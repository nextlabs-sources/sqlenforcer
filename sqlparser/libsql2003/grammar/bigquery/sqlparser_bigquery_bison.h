/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_BIGQUERY_SQLPARSER_BIGQUERY_BISON_H_INCLUDED
# define YY_BIGQUERY_SQLPARSER_BIGQUERY_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef BIGQUERY_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define BIGQUERY_DEBUG 1
#  else
#   define BIGQUERY_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define BIGQUERY_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined BIGQUERY_DEBUG */
#if BIGQUERY_DEBUG
extern int bigquery_debug;
#endif
/* "%code requires" blocks.  */
#line 45 "bigquery.y" /* yacc.c:1909  */

// %code requires block

#include "node.h"

#line 58 "sqlparser_bigquery_bison.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef BIGQUERY_TOKENTYPE
# define BIGQUERY_TOKENTYPE
  enum bigquery_tokentype
  {
    BIGQUERY_NAME = 258,
    BIGQUERY_NAMES = 259,
    BIGQUERY_STR = 260,
    BIGQUERY_INTNUM = 261,
    BIGQUERY_BOOL_VAL = 262,
    BIGQUERY_APPROXNUM = 263,
    BIGQUERY_NULLX = 264,
    BIGQUERY_UNKNOWN = 265,
    BIGQUERY_QUESTIONMARK = 266,
    BIGQUERY_PARAM = 267,
    BIGQUERY_CROSS = 268,
    BIGQUERY_FULL = 269,
    BIGQUERY_INNER = 270,
    BIGQUERY_JOIN = 271,
    BIGQUERY_LEFT = 272,
    BIGQUERY_NATURAL = 273,
    BIGQUERY_RIGHT = 274,
    BIGQUERY_USING = 275,
    BIGQUERY_UMINUS = 276,
    BIGQUERY_ALL = 277,
    BIGQUERY_AND = 278,
    BIGQUERY_ANY = 279,
    BIGQUERY_AS = 280,
    BIGQUERY_ASC = 281,
    BIGQUERY_AVG = 282,
    BIGQUERY_BETWEEN = 283,
    BIGQUERY_BY = 284,
    BIGQUERY_CALL = 285,
    BIGQUERY_CASE = 286,
    BIGQUERY_CAST = 287,
    BIGQUERY_CNNOP = 288,
    BIGQUERY_COALESCE = 289,
    BIGQUERY_CODE_UNITS = 290,
    BIGQUERY_COLLATE = 291,
    BIGQUERY_COMP_EQ = 292,
    BIGQUERY_COMP_GE = 293,
    BIGQUERY_COMP_GT = 294,
    BIGQUERY_COMP_LE = 295,
    BIGQUERY_COMP_LT = 296,
    BIGQUERY_COMP_NE = 297,
    BIGQUERY_CONVERT = 298,
    BIGQUERY_CORRESPONDING = 299,
    BIGQUERY_COUNT = 300,
    BIGQUERY_CUME_DIST = 301,
    BIGQUERY_CURRENT = 302,
    BIGQUERY_CURRENT_TIMESTAMP = 303,
    BIGQUERY_CURRENT_USER = 304,
    BIGQUERY_DAY = 305,
    BIGQUERY_DEC = 306,
    BIGQUERY_DEFAULT = 307,
    BIGQUERY_DELETE = 308,
    BIGQUERY_DENSE_RANK = 309,
    BIGQUERY_DESC = 310,
    BIGQUERY_DISTINCT = 311,
    BIGQUERY_ELSE = 312,
    BIGQUERY_END = 313,
    BIGQUERY_END_P = 314,
    BIGQUERY_ESCAPE = 315,
    BIGQUERY_ERROR = 316,
    BIGQUERY_EXCEPT = 317,
    BIGQUERY_EXCLUDE = 318,
    BIGQUERY_EXISTS = 319,
    BIGQUERY_FOLLOWING = 320,
    BIGQUERY_FOR = 321,
    BIGQUERY_FROM = 322,
    BIGQUERY_G = 323,
    BIGQUERY_GROUP = 324,
    BIGQUERY_GROUPING = 325,
    BIGQUERY_HAVING = 326,
    BIGQUERY_HOUR = 327,
    BIGQUERY_IN = 328,
    BIGQUERY_INSERT = 329,
    BIGQUERY_INTERSECT = 330,
    BIGQUERY_INTERVAL = 331,
    BIGQUERY_INTO = 332,
    BIGQUERY_IS = 333,
    BIGQUERY_K = 334,
    BIGQUERY_LARGE = 335,
    BIGQUERY_LIKE = 336,
    BIGQUERY_M = 337,
    BIGQUERY_MAX = 338,
    BIGQUERY_MIN = 339,
    BIGQUERY_MINUTE = 340,
    BIGQUERY_MOD = 341,
    BIGQUERY_MONTH = 342,
    BIGQUERY_MULTISET = 343,
    BIGQUERY_NATIONAL = 344,
    BIGQUERY_NO = 345,
    BIGQUERY_NOT = 346,
    BIGQUERY_NULLIF = 347,
    BIGQUERY_NUMERIC = 348,
    BIGQUERY_OBJECT = 349,
    BIGQUERY_OCTETS = 350,
    BIGQUERY_OF = 351,
    BIGQUERY_ON = 352,
    BIGQUERY_ONLY = 353,
    BIGQUERY_OR = 354,
    BIGQUERY_ORDER = 355,
    BIGQUERY_OTHERS = 356,
    BIGQUERY_OUTER = 357,
    BIGQUERY_OVER = 358,
    BIGQUERY_PARTITION = 359,
    BIGQUERY_PERCENT_RANK = 360,
    BIGQUERY_PRECEDING = 361,
    BIGQUERY_PRECISION = 362,
    BIGQUERY_RANGE = 363,
    BIGQUERY_RANK = 364,
    BIGQUERY_READ = 365,
    BIGQUERY_REAL = 366,
    BIGQUERY_RECURSIVE = 367,
    BIGQUERY_REF = 368,
    BIGQUERY_ROW = 369,
    BIGQUERY_ROWS = 370,
    BIGQUERY_ROW_NUMBER = 371,
    BIGQUERY_SCOPE = 372,
    BIGQUERY_SECOND = 373,
    BIGQUERY_SELECT = 374,
    BIGQUERY_SESSION_USER = 375,
    BIGQUERY_SET = 376,
    BIGQUERY_SETS = 377,
    BIGQUERY_SMALLINT = 378,
    BIGQUERY_SOME = 379,
    BIGQUERY_STDDEV_POP = 380,
    BIGQUERY_STDDEV_SAMP = 381,
    BIGQUERY_SUM = 382,
    BIGQUERY_SYSTEM_USER = 383,
    BIGQUERY_THEN = 384,
    BIGQUERY_TIES = 385,
    BIGQUERY_TO = 386,
    BIGQUERY_UNBOUNDED = 387,
    BIGQUERY_UNION = 388,
    BIGQUERY_UPDATE = 389,
    BIGQUERY_VALUES = 390,
    BIGQUERY_VARCHAR = 391,
    BIGQUERY_VARYING = 392,
    BIGQUERY_VAR_POP = 393,
    BIGQUERY_VAR_SAMP = 394,
    BIGQUERY_WHEN = 395,
    BIGQUERY_WHERE = 396,
    BIGQUERY_WITH = 397,
    BIGQUERY_WITHOUT = 398,
    BIGQUERY_YEAR = 399,
    BIGQUERY_ZONE = 400,
    BIGQUERY_LIMIT = 401,
    BIGQUERY_OFFSET = 402,
    BIGQUERY_ORDINAL = 403,
    BIGQUERY_SAFE_OFFSET = 404,
    BIGQUERY_SAFE_ORDINAL = 405,
    BIGQUERY_REPLACE = 406,
    BIGQUERY_NULLS = 407,
    BIGQUERY_FIRST = 408,
    BIGQUERY_LAST = 409,
    BIGQUERY_ARRAY = 410,
    BIGQUERY_STRUCT = 411,
    BIGQUERY_INT64 = 412,
    BIGQUERY_FLOAT64 = 413,
    BIGQUERY_STRING = 414,
    BIGQUERY_BYTES = 415,
    BIGQUERY_DATETIME = 416,
    BIGQUERY_DATE = 417,
    BIGQUERY_TIMESTAMP = 418,
    BIGQUERY_TIME = 419,
    BIGQUERY_BOOL = 420,
    BIGQUERY_VALUE = 421,
    BIGQUERY_UNNEST = 422,
    BIGQUERY_OP_LS = 423,
    BIGQUERY_OP_RS = 424,
    BIGQUERY_FIRST_VALUE = 425,
    BIGQUERY_RESPECT = 426,
    BIGQUERY_IGNORE = 427,
    BIGQUERY_WINDOW = 428,
    BIGQUERY_LAST_VALUE = 429,
    BIGQUERY_NTH_VALUE = 430,
    BIGQUERY_LEAD = 431,
    BIGQUERY_LAG = 432,
    BIGQUERY_PERCENTILE_CONT = 433,
    BIGQUERY_PERCENTILE_DISC = 434,
    BIGQUERY_NTILE = 435,
    BIGQUERY_ARRAY_AGG = 436,
    BIGQUERY_CORR = 437,
    BIGQUERY_COVAR_POP = 438,
    BIGQUERY_COVAR_SAMP = 439,
    BIGQUERY_STRING_AGG = 440,
    BIGQUERY_ANY_VALUE = 441,
    BIGQUERY_COUNTIF = 442,
    BIGQUERY_SAFE_CAST = 443,
    BIGQUERY_ARRAY_CONCAT_AGG = 444,
    BIGQUERY_BIT_XOR = 445,
    BIGQUERY_LOGICAL_AND = 446,
    BIGQUERY_LOGICAL_OR = 447,
    BIGQUERY_APPROX_COUNT_DISTINCT = 448,
    BIGQUERY_APPROX_QUANTILES = 449,
    BIGQUERY_APPROX_TOP_COUNT = 450,
    BIGQUERY_WEEK = 451,
    BIGQUERY_QUARTER = 452,
    BIGQUERY_DAYOFWEEK = 453,
    BIGQUERY_DAYOFYEAR = 454,
    BIGQUERY_ISOWEEK = 455,
    BIGQUERY_ISOYEAR = 456,
    BIGQUERY_MICROSECOND = 457,
    BIGQUERY_MILLISECOND = 458,
    BIGQUERY_SUNDAY = 459,
    BIGQUERY_MONDAY = 460,
    BIGQUERY_TUESDAY = 461,
    BIGQUERY_WEDNESDAY = 462,
    BIGQUERY_THURSDAY = 463,
    BIGQUERY_FRIDAY = 464,
    BIGQUERY_SATURDAY = 465,
    BIGQUERY_AT = 466,
    BIGQUERY_EXTRACT = 467,
    BIGQUERY_DATE_ADD = 468,
    BIGQUERY_DATE_SUB = 469,
    BIGQUERY_DATE_DIFF = 470,
    BIGQUERY_DATE_TRUNC = 471,
    BIGQUERY_DATETIME_ADD = 472,
    BIGQUERY_DATETIME_SUB = 473,
    BIGQUERY_DATETIME_DIFF = 474,
    BIGQUERY_DATETIME_TRUNC = 475,
    BIGQUERY_TIME_ADD = 476,
    BIGQUERY_TIME_SUB = 477,
    BIGQUERY_TIME_DIFF = 478,
    BIGQUERY_TIME_TRUNC = 479,
    BIGQUERY_TIMESTAMP_ADD = 480,
    BIGQUERY_TIMESTAMP_SUB = 481,
    BIGQUERY_TIMESTAMP_DIFF = 482,
    BIGQUERY_TIMESTAMP_TRUNC = 483,
    BIGQUERY_TO_JSON_STRING = 484,
    BIGQUERY_STDDEV = 485,
    BIGQUERY_VARIANCE = 486,
    BIGQUERY_STARTS_WITH = 487,
    BIGQUERY_ENDS_WITH = 488,
    BIGQUERY_REGEXP_CONTAINS = 489,
    BIGQUERY_REGEXP_EXTRACT = 490,
    BIGQUERY_REGEXP_REPLACE = 491,
    BIGQUERY_GENERATE_TIMESTAMP_ARRAY = 492,
    BIGQUERY_GENERATE_DATE_ARRAY = 493,
    BIGQUERY_SYSTEM_TIME = 494,
    BIGQUERY_IF = 495
  };
#endif

/* Value type.  */
#if ! defined BIGQUERY_STYPE && ! defined BIGQUERY_STYPE_IS_DECLARED

union BIGQUERY_STYPE
{
#line 88 "bigquery.y" /* yacc.c:1909  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 317 "sqlparser_bigquery_bison.h" /* yacc.c:1909  */
};

typedef union BIGQUERY_STYPE BIGQUERY_STYPE;
# define BIGQUERY_STYPE_IS_TRIVIAL 1
# define BIGQUERY_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined BIGQUERY_LTYPE && ! defined BIGQUERY_LTYPE_IS_DECLARED
typedef struct BIGQUERY_LTYPE BIGQUERY_LTYPE;
struct BIGQUERY_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define BIGQUERY_LTYPE_IS_DECLARED 1
# define BIGQUERY_LTYPE_IS_TRIVIAL 1
#endif



int bigquery_parse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_BIGQUERY_SQLPARSER_BIGQUERY_BISON_H_INCLUDED  */
