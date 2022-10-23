/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_ORACLE_SQLPARSER_ORACLE_BISON_H_INCLUDED
# define YY_ORACLE_SQLPARSER_ORACLE_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef ORACLE_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define ORACLE_DEBUG 1
#  else
#   define ORACLE_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define ORACLE_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined ORACLE_DEBUG */
#if ORACLE_DEBUG
extern int oracle_debug;
#endif
/* "%code requires" blocks.  */
#line 42 "oracle.y"

// %code requires block

#include "node.h"

#line 62 "sqlparser_oracle_bison.h"

/* Token type.  */
#ifndef ORACLE_TOKENTYPE
# define ORACLE_TOKENTYPE
  enum oracle_tokentype
  {
    ORACLE_NAME = 258,
    ORACLE_STRING = 259,
    ORACLE_INTNUM = 260,
    ORACLE_BOOL = 261,
    ORACLE_APPROXNUM = 262,
    ORACLE_NULLX = 263,
    ORACLE_UNKNOWN = 264,
    ORACLE_QUESTIONMARK = 265,
    ORACLE_PARAM = 266,
    ORACLE_UMINUS = 267,
    ORACLE_ALL = 268,
    ORACLE_AND = 269,
    ORACLE_ANY = 270,
    ORACLE_ARRAY = 271,
    ORACLE_AS = 272,
    ORACLE_ASC = 273,
    ORACLE_AVG = 274,
    ORACLE_BETWEEN = 275,
    ORACLE_BIGINT = 276,
    ORACLE_BINARY = 277,
    ORACLE_BLOB = 278,
    ORACLE_BOOLEAN = 279,
    ORACLE_BY = 280,
    ORACLE_CALL = 281,
    ORACLE_CASE = 282,
    ORACLE_CAST = 283,
    ORACLE_CHAR = 284,
    ORACLE_CHARACTER = 285,
    ORACLE_CHARACTERS = 286,
    ORACLE_CLOB = 287,
    ORACLE_CNNOP = 288,
    ORACLE_COALESCE = 289,
    ORACLE_CODE_UNITS = 290,
    ORACLE_COLLATE = 291,
    ORACLE_COMP_EQ = 292,
    ORACLE_COMP_GE = 293,
    ORACLE_COMP_GT = 294,
    ORACLE_COMP_LE = 295,
    ORACLE_COMP_LT = 296,
    ORACLE_COMP_NE = 297,
    ORACLE_CONVERT = 298,
    ORACLE_CORRESPONDING = 299,
    ORACLE_COUNT = 300,
    ORACLE_CROSS = 301,
    ORACLE_CUME_DIST = 302,
    ORACLE_CURRENT = 303,
    ORACLE_CURRENT_TIMESTAMP = 304,
    ORACLE_CURRENT_USER = 305,
    ORACLE_DATE = 306,
    ORACLE_DAY = 307,
    ORACLE_DEC = 308,
    ORACLE_DECIMAL = 309,
    ORACLE_DEFAULT = 310,
    ORACLE_DELETE = 311,
    ORACLE_DENSE_RANK = 312,
    ORACLE_DESC = 313,
    ORACLE_DISTINCT = 314,
    ORACLE_DOUBLE = 315,
    ORACLE_ELSE = 316,
    ORACLE_END = 317,
    ORACLE_END_P = 318,
    ORACLE_ESCAPE = 319,
    ORACLE_ERROR = 320,
    ORACLE_EXCEPT = 321,
    ORACLE_EXCLUDE = 322,
    ORACLE_EXISTS = 323,
    ORACLE_FLOAT = 324,
    ORACLE_FOLLOWING = 325,
    ORACLE_FOR = 326,
    ORACLE_FROM = 327,
    ORACLE_FULL = 328,
    ORACLE_G = 329,
    ORACLE_GROUP = 330,
    ORACLE_GROUPING = 331,
    ORACLE_HAVING = 332,
    ORACLE_HOUR = 333,
    ORACLE_IN = 334,
    ORACLE_INNER = 335,
    ORACLE_INSERT = 336,
    ORACLE_INT = 337,
    ORACLE_INTEGER = 338,
    ORACLE_INTERSECT = 339,
    ORACLE_INTERVAL = 340,
    ORACLE_INTO = 341,
    ORACLE_IS = 342,
    ORACLE_JOIN = 343,
    ORACLE_K = 344,
    ORACLE_LARGE = 345,
    ORACLE_LEFT = 346,
    ORACLE_LIKE = 347,
    ORACLE_M = 348,
    ORACLE_MAX = 349,
    ORACLE_MIN = 350,
    ORACLE_MINUTE = 351,
    ORACLE_MOD = 352,
    ORACLE_MONTH = 353,
    ORACLE_MULTISET = 354,
    ORACLE_NATIONAL = 355,
    ORACLE_NATURAL = 356,
    ORACLE_NCHAR = 357,
    ORACLE_NCLOB = 358,
    ORACLE_NO = 359,
    ORACLE_NOT = 360,
    ORACLE_NULLIF = 361,
    ORACLE_NUMERIC = 362,
    ORACLE_OBJECT = 363,
    ORACLE_OCTETS = 364,
    ORACLE_OF = 365,
    ORACLE_ON = 366,
    ORACLE_ONLY = 367,
    ORACLE_OR = 368,
    ORACLE_ORDER = 369,
    ORACLE_OTHERS = 370,
    ORACLE_OUTER = 371,
    ORACLE_OVER = 372,
    ORACLE_PARTITION = 373,
    ORACLE_PERCENT_RANK = 374,
    ORACLE_PRECEDING = 375,
    ORACLE_PRECISION = 376,
    ORACLE_RANGE = 377,
    ORACLE_RANK = 378,
    ORACLE_READ = 379,
    ORACLE_REAL = 380,
    ORACLE_RECURSIVE = 381,
    ORACLE_REF = 382,
    ORACLE_RIGHT = 383,
    ORACLE_ROW = 384,
    ORACLE_ROWS = 385,
    ORACLE_ROW_NUMBER = 386,
    ORACLE_SCOPE = 387,
    ORACLE_SECOND = 388,
    ORACLE_SELECT = 389,
    ORACLE_SESSION_USER = 390,
    ORACLE_SET = 391,
    ORACLE_SETS = 392,
    ORACLE_SMALLINT = 393,
    ORACLE_SOME = 394,
    ORACLE_STDDEV = 395,
    ORACLE_STDDEV_POP = 396,
    ORACLE_STDDEV_SAMP = 397,
    ORACLE_SUM = 398,
    ORACLE_SYSTEM_USER = 399,
    ORACLE_THEN = 400,
    ORACLE_TIES = 401,
    ORACLE_TIME = 402,
    ORACLE_TIMESTAMP = 403,
    ORACLE_TO = 404,
    ORACLE_UNBOUNDED = 405,
    ORACLE_UNION = 406,
    ORACLE_UPDATE = 407,
    ORACLE_USING = 408,
    ORACLE_VALUES = 409,
    ORACLE_VARCHAR = 410,
    ORACLE_VARYING = 411,
    ORACLE_VAR_POP = 412,
    ORACLE_VAR_SAMP = 413,
    ORACLE_WHEN = 414,
    ORACLE_WHERE = 415,
    ORACLE_WITH = 416,
    ORACLE_WITHOUT = 417,
    ORACLE_YEAR = 418,
    ORACLE_ZONE = 419,
    ORACLE_RETURNING = 420,
    ORACLE_SKIP = 421,
    ORACLE_LOCKED = 422,
    ORACLE_NOWAIT = 423,
    ORACLE_WAIT = 424,
    ORACLE_NULLS = 425,
    ORACLE_LAST = 426,
    ORACLE_SIBLINGS = 427,
    ORACLE_OFFSET = 428,
    ORACLE_FIRST = 429,
    ORACLE_NEXT = 430,
    ORACLE_FETCH = 431,
    ORACLE_PERCENT = 432,
    ORACLE_MINUS = 433,
    ORACLE_UNIQUE = 434,
    ORACLE_NAN = 435,
    ORACLE_INFINITE = 436,
    ORACLE_REGEXP_LIKE = 437,
    ORACLE_APPLY = 438,
    ORACLE_CYCLE = 439,
    ORACLE_SEARCH = 440,
    ORACLE_DEPTH = 441,
    ORACLE_BREADTH = 442,
    ORACLE_START = 443,
    ORACLE_CONNECT = 444,
    ORACLE_NOCYCLE = 445,
    ORACLE_CONTAINERS = 446,
    ORACLE_SHARDS = 447,
    ORACLE_SAMPLE = 448,
    ORACLE_BLOCK = 449,
    ORACLE_SEED = 450,
    ORACLE_PRIOR = 451,
    ORACLE_ALTER = 452,
    ORACLE_SESSION = 453,
    ORACLE_BEGIN = 454,
    ORACLE_DECLARE = 455,
    ORACLE_UNPIVOT = 456,
    ORACLE_PIVOT = 457,
    ORACLE_EXTRACT = 458,
    ORACLE_TIMEZONE_HOUR = 459,
    ORACLE_TIMEZONE_MINUTE = 460,
    ORACLE_TIMEZONE_REGION = 461,
    ORACLE_TIMEZONE_ABBR = 462
  };
#endif

/* Value type.  */
#if ! defined ORACLE_STYPE && ! defined ORACLE_STYPE_IS_DECLARED
union ORACLE_STYPE
{
#line 85 "oracle.y"

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 287 "sqlparser_oracle_bison.h"

};
typedef union ORACLE_STYPE ORACLE_STYPE;
# define ORACLE_STYPE_IS_TRIVIAL 1
# define ORACLE_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined ORACLE_LTYPE && ! defined ORACLE_LTYPE_IS_DECLARED
typedef struct ORACLE_LTYPE ORACLE_LTYPE;
struct ORACLE_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define ORACLE_LTYPE_IS_DECLARED 1
# define ORACLE_LTYPE_IS_TRIVIAL 1
#endif



int oracle_parse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_ORACLE_SQLPARSER_ORACLE_BISON_H_INCLUDED  */
