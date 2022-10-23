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

#ifndef YY_HANA_SQLPARSER_HANA_BISON_H_INCLUDED
# define YY_HANA_SQLPARSER_HANA_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef HANA_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HANA_DEBUG 1
#  else
#   define HANA_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HANA_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HANA_DEBUG */
#if HANA_DEBUG
extern int hana_debug;
#endif
/* "%code requires" blocks.  */
#line 45 "sqlparser_hana.yacc" /* yacc.c:1909  */

// %code requires block

#include "node.h"

#line 58 "sqlparser_hana_bison.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef HANA_TOKENTYPE
# define HANA_TOKENTYPE
  enum hana_tokentype
  {
    HANA_NAME = 258,
    HANA_STRING = 259,
    HANA_INTNUM = 260,
    HANA_BOOL = 261,
    HANA_APPROXNUM = 262,
    HANA_NULLX = 263,
    HANA_UNKNOWN = 264,
    HANA_QUESTIONMARK = 265,
    HANA_UMINUS = 266,
    HANA_ALL = 267,
    HANA_AND = 268,
    HANA_ANY = 269,
    HANA_ARRAY = 270,
    HANA_AS = 271,
    HANA_ASC = 272,
    HANA_AVG = 273,
    HANA_BETWEEN = 274,
    HANA_BIGINT = 275,
    HANA_BINARY = 276,
    HANA_BLOB = 277,
    HANA_BOOLEAN = 278,
    HANA_BY = 279,
    HANA_CALL = 280,
    HANA_CASE = 281,
    HANA_CAST = 282,
    HANA_CHAR = 283,
    HANA_CHARACTER = 284,
    HANA_CHARACTERS = 285,
    HANA_CLOB = 286,
    HANA_CNNOP = 287,
    HANA_COALESCE = 288,
    HANA_CODE_UNITS = 289,
    HANA_COLLATE = 290,
    HANA_COMP_EQ = 291,
    HANA_COMP_GE = 292,
    HANA_COMP_GT = 293,
    HANA_COMP_LE = 294,
    HANA_COMP_LT = 295,
    HANA_COMP_NE = 296,
    HANA_CONVERT = 297,
    HANA_CORRESPONDING = 298,
    HANA_COUNT = 299,
    HANA_CROSS = 300,
    HANA_CUME_DIST = 301,
    HANA_CURRENT = 302,
    HANA_CURRENT_TIMESTAMP = 303,
    HANA_CURRENT_USER = 304,
    HANA_DATE = 305,
    HANA_DAY = 306,
    HANA_DEC = 307,
    HANA_DECIMAL = 308,
    HANA_DEFAULT = 309,
    HANA_DELETE = 310,
    HANA_DENSE_RANK = 311,
    HANA_DESC = 312,
    HANA_DISTINCT = 313,
    HANA_DOUBLE = 314,
    HANA_ELSE = 315,
    HANA_END = 316,
    HANA_END_P = 317,
    HANA_ESCAPE = 318,
    HANA_ERROR = 319,
    HANA_EXCEPT = 320,
    HANA_EXCLUDE = 321,
    HANA_EXISTS = 322,
    HANA_FLOAT = 323,
    HANA_FOLLOWING = 324,
    HANA_FOR = 325,
    HANA_FROM = 326,
    HANA_FULL = 327,
    HANA_G = 328,
    HANA_GROUP = 329,
    HANA_GROUPING = 330,
    HANA_HAVING = 331,
    HANA_HOUR = 332,
    HANA_IN = 333,
    HANA_INNER = 334,
    HANA_INSERT = 335,
    HANA_INT = 336,
    HANA_INTEGER = 337,
    HANA_INTERSECT = 338,
    HANA_INTERVAL = 339,
    HANA_MANY = 340,
    HANA_ONE = 341,
    HANA_EXACT = 342,
    HANA_INTO = 343,
    HANA_IS = 344,
    HANA_JOIN = 345,
    HANA_K = 346,
    HANA_LARGE = 347,
    HANA_LEFT = 348,
    HANA_LIKE = 349,
    HANA_M = 350,
    HANA_MAX = 351,
    HANA_MIN = 352,
    HANA_MINUTE = 353,
    HANA_MOD = 354,
    HANA_MONTH = 355,
    HANA_MULTISET = 356,
    HANA_NATIONAL = 357,
    HANA_NATURAL = 358,
    HANA_NCHAR = 359,
    HANA_NCLOB = 360,
    HANA_NO = 361,
    HANA_NOT = 362,
    HANA_NULLIF = 363,
    HANA_OBJECT = 364,
    HANA_OCTETS = 365,
    HANA_OF = 366,
    HANA_ON = 367,
    HANA_ONLY = 368,
    HANA_OR = 369,
    HANA_ORDER = 370,
    HANA_OTHERS = 371,
    HANA_OUTER = 372,
    HANA_OVER = 373,
    HANA_PARTITION = 374,
    HANA_PERCENT_RANK = 375,
    HANA_PRECEDING = 376,
    HANA_PRECISION = 377,
    HANA_RANGE = 378,
    HANA_RANK = 379,
    HANA_READ = 380,
    HANA_REAL = 381,
    HANA_RECURSIVE = 382,
    HANA_REF = 383,
    HANA_RIGHT = 384,
    HANA_ROW = 385,
    HANA_ROWS = 386,
    HANA_ROW_NUMBER = 387,
    HANA_SCOPE = 388,
    HANA_SECOND = 389,
    HANA_SELECT = 390,
    HANA_SESSION_USER = 391,
    HANA_SET = 392,
    HANA_SETS = 393,
    HANA_SMALLINT = 394,
    HANA_SOME = 395,
    HANA_STDDEV_POP = 396,
    HANA_STDDEV_SAMP = 397,
    HANA_SUM = 398,
    HANA_SYSTEM_USER = 399,
    HANA_THEN = 400,
    HANA_TIES = 401,
    HANA_TIME = 402,
    HANA_TIMESTAMP = 403,
    HANA_TO = 404,
    HANA_UNBOUNDED = 405,
    HANA_UNION = 406,
    HANA_UPDATE = 407,
    HANA_USING = 408,
    HANA_VALUES = 409,
    HANA_VARCHAR = 410,
    HANA_NVARCHAR = 411,
    HANA_VARYING = 412,
    HANA_VAR_POP = 413,
    HANA_VAR_SAMP = 414,
    HANA_WHEN = 415,
    HANA_WHERE = 416,
    HANA_WITH = 417,
    HANA_WITHOUT = 418,
    HANA_YEAR = 419,
    HANA_ZONE = 420,
    HANA_LIMIT = 421,
    HANA_OFFSET = 422,
    HANA_TOP = 423,
    HANA_WAIT = 424,
    HANA_NOWAIT = 425,
    HANA_HINT = 426,
    HANA_RANGE_RESTRICTION = 427,
    HANA_PARAMETERS = 428,
    HANA_UPSERT = 429,
    HANA_REPLACE = 430,
    HANA_PRIMARY = 431,
    HANA_KEY = 432,
    HANA_CONTAINS = 433,
    HANA_P_POINT = 434,
    HANA_SECONDDATE = 435,
    HANA_TINYINT = 436,
    HANA_SMALLDECIMAL = 437,
    HANA_TEXT = 438,
    HANA_BINTEXT = 439,
    HANA_ALPHANUM = 440,
    HANA_VARBINARY = 441,
    HANA_SHORTTEXT = 442,
    HANA_ORDINALITY = 443,
    HANA_UNNEST = 444,
    HANA_HISTORY = 445,
    HANA_OVERRIDING = 446,
    HANA_USER = 447,
    HANA_SYSTEM = 448,
    HANA_VALUE = 449,
    HANA_NULLS = 450,
    HANA_FIRST = 451,
    HANA_LAST = 452,
    HANA_CORR = 453,
    HANA_CORR_SPEARMAN = 454,
    HANA_MEDIAN = 455,
    HANA_STDDEV = 456,
    HANA_VAR = 457,
    HANA_STRING_AGG = 458,
    HANA_MEMBER = 459,
    HANA_SYSTEM_TIME = 460,
    HANA_APPLICATION_TIME = 461,
    HANA_TABLESAMPLE = 462,
    HANA_BERNOULLI = 463,
    HANA_RETURN = 464,
    HANA_LATERAL = 465,
    HANA_BINNING = 466,
    HANA_LAG = 467,
    HANA_LEAD = 468,
    HANA_RANDOM_PARTITION = 469,
    HANA_WEIGHTED_AVG = 470,
    HANA_EXTRACT = 471,
    HANA_FIRST_VALUE = 472,
    HANA_LAST_VALUE = 473,
    HANA_NTH_VALUE = 474,
    HANA_NTILE = 475,
    HANA_SERIES_FILTER = 476,
    HANA_LOCATE_REGEXPR = 477,
    HANA_OCCURRENCES_REGEXPR = 478,
    HANA_REPLACE_REGEXPR = 479,
    HANA_SUBSTRING_REGEXPR = 480,
    HANA_SUBSTR_REGEXPR = 481,
    HANA_PERCENTILE_CONT = 482,
    HANA_PERCENTILE_DISC = 483,
    HANA_TRIM = 484,
    HANA_WITHIN = 485,
    HANA_CUBIC_SPLINE_APPROX = 486,
    HANA_LINEAR_APPROX = 487,
    HANA_ROLLUP = 488,
    HANA_CUBE = 489,
    HANA_BEST = 490,
    HANA_SUBTOTAL = 491,
    HANA_BALANCE = 492,
    HANA_TOTAL = 493,
    HANA_MULTIPLE = 494,
    HANA_RESULTSETS = 495,
    HANA_PREFIX = 496,
    HANA_STRUCTURED = 497,
    HANA_RESULT = 498,
    HANA_OVERVIEW = 499,
    HANA_TEXT_FILTER = 500,
    HANA_FILL = 501,
    HANA_UP = 502,
    HANA_MATCHES = 503,
    HANA_SORT = 504,
    HANA_MINUS = 505,
    HANA_ROWCOUNT = 506,
    HANA_LOCKED = 507,
    HANA_IGNORE = 508,
    HANA_SHARE = 509,
    HANA_LOCK = 510,
    HANA_UTCTIMESTAMP = 511,
    HANA_COMMIT = 512,
    HANA_ID = 513,
    HANA_XML = 514,
    HANA_JSON = 515,
    HANA_RETURNS = 516,
    HANA_SERIES = 517,
    HANA_TABLE = 518,
    HANA_LIKE_REGEXPR = 519,
    HANA_FLAG = 520,
    HANA_LEADING = 521,
    HANA_TRAILING = 522,
    HANA_BOTH = 523,
    HANA_WEIGHT = 524,
    HANA_FULLTEXT = 525,
    HANA_LANGUAGE = 526,
    HANA_LINGUISTIC = 527,
    HANA_FUZZY = 528,
    HANA_PORTION = 529,
    HANA_START = 530,
    HANA_AFTER = 531,
    HANA_OCCURRENCE = 532
  };
#endif

/* Value type.  */
#if ! defined HANA_STYPE && ! defined HANA_STYPE_IS_DECLARED

union HANA_STYPE
{
#line 88 "sqlparser_hana.yacc" /* yacc.c:1909  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 354 "sqlparser_hana_bison.h" /* yacc.c:1909  */
};

typedef union HANA_STYPE HANA_STYPE;
# define HANA_STYPE_IS_TRIVIAL 1
# define HANA_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HANA_LTYPE && ! defined HANA_LTYPE_IS_DECLARED
typedef struct HANA_LTYPE HANA_LTYPE;
struct HANA_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HANA_LTYPE_IS_DECLARED 1
# define HANA_LTYPE_IS_TRIVIAL 1
#endif



int hana_parse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_HANA_SQLPARSER_HANA_BISON_H_INCLUDED  */
