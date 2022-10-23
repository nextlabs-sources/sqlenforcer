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

#ifndef YY_DB2_SQLPARSER_DB2_BISON_H_INCLUDED
# define YY_DB2_SQLPARSER_DB2_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef DB2_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define DB2_DEBUG 1
#  else
#   define DB2_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define DB2_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined DB2_DEBUG */
#if DB2_DEBUG
extern int db2_debug;
#endif
/* "%code requires" blocks.  */
#line 42 "sql_db2.y" /* yacc.c:1909  */

// %code requires block

#include "node.h"

#line 58 "sqlparser_db2_bison.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef DB2_TOKENTYPE
# define DB2_TOKENTYPE
  enum db2_tokentype
  {
    DB2_NAME = 258,
    DB2_STRING = 259,
    DB2_INTNUM = 260,
    DB2_BOOL = 261,
    DB2_APPROXNUM = 262,
    DB2_NULLX = 263,
    DB2_UNKNOWN = 264,
    DB2_QUESTIONMARK = 265,
    DB2_UMINUS = 266,
    DB2_ALL = 267,
    DB2_AND = 268,
    DB2_ANY = 269,
    DB2_ARRAY = 270,
    DB2_AS = 271,
    DB2_ASC = 272,
    DB2_AVG = 273,
    DB2_BETWEEN = 274,
    DB2_BIGINT = 275,
    DB2_BINARY = 276,
    DB2_BLOB = 277,
    DB2_BOOLEAN = 278,
    DB2_BY = 279,
    DB2_CALL = 280,
    DB2_CASE = 281,
    DB2_CAST = 282,
    DB2_CHAR = 283,
    DB2_CHARACTER = 284,
    DB2_CHARACTERS = 285,
    DB2_CLOB = 286,
    DB2_CNNOP = 287,
    DB2_COALESCE = 288,
    DB2_CODE_UNITS = 289,
    DB2_COLLATE = 290,
    DB2_COMP_EQ = 291,
    DB2_COMP_GE = 292,
    DB2_COMP_GT = 293,
    DB2_COMP_LE = 294,
    DB2_COMP_LT = 295,
    DB2_COMP_NE = 296,
    DB2_CONVERT = 297,
    DB2_CORRESPONDING = 298,
    DB2_COUNT = 299,
    DB2_CROSS = 300,
    DB2_CUME_DIST = 301,
    DB2_CURRENT = 302,
    DB2_CURRENT_TIMESTAMP = 303,
    DB2_CURRENT_USER = 304,
    DB2_DATE = 305,
    DB2_DAY = 306,
    DB2_DEC = 307,
    DB2_DECIMAL = 308,
    DB2_DEFAULT = 309,
    DB2_DELETE = 310,
    DB2_DENSE_RANK = 311,
    DB2_DESC = 312,
    DB2_DISTINCT = 313,
    DB2_DOUBLE = 314,
    DB2_ELSE = 315,
    DB2_END = 316,
    DB2_END_P = 317,
    DB2_ESCAPE = 318,
    DB2_ERROR = 319,
    DB2_EXCEPT = 320,
    DB2_EXCLUDE = 321,
    DB2_EXISTS = 322,
    DB2_FLOAT = 323,
    DB2_FOLLOWING = 324,
    DB2_FOR = 325,
    DB2_FROM = 326,
    DB2_FULL = 327,
    DB2_G = 328,
    DB2_GROUP = 329,
    DB2_GROUPING = 330,
    DB2_HAVING = 331,
    DB2_HOUR = 332,
    DB2_IN = 333,
    DB2_INNER = 334,
    DB2_INSERT = 335,
    DB2_INT = 336,
    DB2_INTEGER = 337,
    DB2_INTERSECT = 338,
    DB2_INTERVAL = 339,
    DB2_INTO = 340,
    DB2_IS = 341,
    DB2_JOIN = 342,
    DB2_K = 343,
    DB2_LARGE = 344,
    DB2_LEFT = 345,
    DB2_LIKE = 346,
    DB2_M = 347,
    DB2_MAX = 348,
    DB2_MIN = 349,
    DB2_MINUTE = 350,
    DB2_MOD = 351,
    DB2_MONTH = 352,
    DB2_MULTISET = 353,
    DB2_NATIONAL = 354,
    DB2_NATURAL = 355,
    DB2_NCHAR = 356,
    DB2_NCLOB = 357,
    DB2_NO = 358,
    DB2_NOT = 359,
    DB2_NULLIF = 360,
    DB2_NUMERIC = 361,
    DB2_OBJECT = 362,
    DB2_OCTETS = 363,
    DB2_OF = 364,
    DB2_ON = 365,
    DB2_ONLY = 366,
    DB2_OR = 367,
    DB2_ORDER = 368,
    DB2_OTHERS = 369,
    DB2_OUTER = 370,
    DB2_OVER = 371,
    DB2_PARTITION = 372,
    DB2_PERCENT_RANK = 373,
    DB2_PRECEDING = 374,
    DB2_PRECISION = 375,
    DB2_RANGE = 376,
    DB2_RANK = 377,
    DB2_READ = 378,
    DB2_REAL = 379,
    DB2_RECURSIVE = 380,
    DB2_REF = 381,
    DB2_RIGHT = 382,
    DB2_ROW = 383,
    DB2_ROWS = 384,
    DB2_ROW_NUMBER = 385,
    DB2_SCOPE = 386,
    DB2_SECOND = 387,
    DB2_SELECT = 388,
    DB2_SESSION_USER = 389,
    DB2_SET = 390,
    DB2_SETS = 391,
    DB2_SMALLINT = 392,
    DB2_SOME = 393,
    DB2_STDDEV_POP = 394,
    DB2_STDDEV_SAMP = 395,
    DB2_SUM = 396,
    DB2_SYSTEM_USER = 397,
    DB2_THEN = 398,
    DB2_TIES = 399,
    DB2_TIME = 400,
    DB2_TIMESTAMP = 401,
    DB2_TO = 402,
    DB2_UNBOUNDED = 403,
    DB2_UNION = 404,
    DB2_UPDATE = 405,
    DB2_USING = 406,
    DB2_VALUES = 407,
    DB2_VARCHAR = 408,
    DB2_VARYING = 409,
    DB2_VAR_POP = 410,
    DB2_VAR_SAMP = 411,
    DB2_WHEN = 412,
    DB2_WHERE = 413,
    DB2_WITH = 414,
    DB2_WITHOUT = 415,
    DB2_YEAR = 416,
    DB2_ZONE = 417,
    DB2_SKIP = 418,
    DB2_LOCKED = 419,
    DB2_DATA = 420,
    DB2_CS = 421,
    DB2_UR = 422,
    DB2_RS = 423,
    DB2_RR = 424,
    DB2_QUERYNO = 425,
    DB2_FETCH = 426,
    DB2_FIRST = 427,
    DB2_OPTIMIZE = 428,
    DB2_LIMIT = 429,
    DB2_TABLE = 430,
    DB2_DEGREE = 431,
    DB2_SCHEMA = 432,
    DB2_TIMEZONE = 433,
    DB2_COUNT_BIG = 434,
    DB2_STDDEV = 435,
    DB2_USE = 436,
    DB2_KEEP = 437,
    DB2_EXCLUSIVE = 438,
    DB2_LOCKS = 439,
    DB2_CARDINALITY = 440,
    DB2_BIT = 441,
    DB2_MINUTES = 442,
    DB2_SHARE = 443,
    DB2_OUTCOME = 444,
    DB2_WAIT = 445,
    DB2_OFFSET = 446
  };
#endif

/* Value type.  */
#if ! defined DB2_STYPE && ! defined DB2_STYPE_IS_DECLARED

union DB2_STYPE
{
#line 85 "sql_db2.y" /* yacc.c:1909  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 268 "sqlparser_db2_bison.h" /* yacc.c:1909  */
};

typedef union DB2_STYPE DB2_STYPE;
# define DB2_STYPE_IS_TRIVIAL 1
# define DB2_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined DB2_LTYPE && ! defined DB2_LTYPE_IS_DECLARED
typedef struct DB2_LTYPE DB2_LTYPE;
struct DB2_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define DB2_LTYPE_IS_DECLARED 1
# define DB2_LTYPE_IS_TRIVIAL 1
#endif



int db2_parse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_DB2_SQLPARSER_DB2_BISON_H_INCLUDED  */
