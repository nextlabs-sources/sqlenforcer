/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         BIGQUERY_STYPE
#define YYLTYPE         BIGQUERY_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         bigquery_parse
#define yylex           bigquery_lex
#define yyerror         bigquery_error
#define yydebug         bigquery_debug
#define yynerrs         bigquery_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bigquery.y" /* yacc.c:339  */

/**
 * This Grammar is designed for bigquery.
 * https://github.com/Raphael2017/SQL/blob/master/sql-2003-2.bnf
 * sqlparser.y
 * defines sqlparser_bigquery_bison.h
 * outputs sqlparser_bigquery_bison.cpp
 *
 * Bison Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "sqlparser_bigquery_bison.h"
#include "sqlparser_bigquery_flex.h"
#include "serialize_format.h"

#include <stdio.h>
#include <string.h>
//#include <strings.h>

/*
 * We provide parse error includes error message, first line, first column of error lex for debug
 */
int yyerror(YYLTYPE* llocp, ParseResult* result, yyscan_t scanner, const char *msg) {
    result->accept = false;
    result->errFirstLine = llocp->first_line;
    result->errFirstColumn = llocp->first_column;
    result->errDetail = msg;
	return 0;
}

#define YYSTYPE         BIGQUERY_STYPE
#define YYLTYPE         BIGQUERY_LTYPE


#line 113 "sqlparser_bigquery_bison.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sqlparser_bigquery_bison.h".  */
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
#line 45 "bigquery.y" /* yacc.c:355  */

// %code requires block

#include "node.h"

#line 157 "sqlparser_bigquery_bison.cpp" /* yacc.c:355  */

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
#line 88 "bigquery.y" /* yacc.c:355  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 416 "sqlparser_bigquery_bison.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 446 "sqlparser_bigquery_bison.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined BIGQUERY_LTYPE_IS_TRIVIAL && BIGQUERY_LTYPE_IS_TRIVIAL \
             && defined BIGQUERY_STYPE_IS_TRIVIAL && BIGQUERY_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  186
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   12103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  259
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  213
/* YYNRULES -- Number of rules.  */
#define YYNRULES  692
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1350

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   255,     2,     2,     2,     2,   256,     2,
      22,    23,   248,   252,   247,   253,    24,   258,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   244,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   249,     2,   250,   251,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,   257,   246,   254,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243
};

#if BIGQUERY_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   271,   271,   281,   282,   290,   291,   292,   293,   297,
     302,   307,   312,   320,   321,   329,   334,   342,   347,   351,
     355,   356,   357,   365,   370,   378,   383,   388,   393,   398,
     407,   416,   429,   446,   463,   474,   475,   483,   492,   501,
     502,   507,   512,   520,   522,   527,   532,   540,   545,   552,
     553,   580,   611,   612,   643,   644,   657,   665,   672,   674,
     676,   679,   722,   723,   727,   734,   735,   744,   745,   753,
     754,   762,   763,   772,   773,   774,   784,   785,   789,   797,
     798,   806,   814,   818,   822,   829,   830,   834,   841,   842,
     852,   857,   865,   866,   875,   883,   884,   888,   896,   897,
     905,   906,   910,   917,   918,   919,   927,   934,   939,   949,
     959,   973,   978,   983,   988,   996,  1000,  1006,  1012,  1019,
    1026,  1033,  1034,  1040,  1048,  1049,  1057,  1058,  1062,  1063,
    1075,  1080,  1085,  1090,  1095,  1100,  1108,  1114,  1120,  1129,
    1138,  1143,  1148,  1162,  1168,  1174,  1181,  1190,  1197,  1198,
    1204,  1210,  1216,  1226,  1231,  1236,  1241,  1246,  1251,  1256,
    1261,  1269,  1274,  1279,  1288,  1289,  1290,  1291,  1295,  1300,
    1306,  1311,  1320,  1325,  1331,  1340,  1348,  1355,  1364,  1375,
    1386,  1397,  1404,  1405,  1410,  1411,  1419,  1420,  1428,  1429,
    1437,  1438,  1442,  1443,  1447,  1455,  1469,  1470,  1471,  1472,
    1473,  1474,  1478,  1496,  1501,  1509,  1514,  1519,  1524,  1532,
    1537,  1545,  1550,  1558,  1567,  1568,  1573,  1581,  1582,  1590,
    1591,  1599,  1600,  1608,  1609,  1617,  1618,  1623,  1628,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1646,  1647,  1648,  1649,
    1650,  1658,  1663,  1671,  1672,  1673,  1677,  1682,  1690,  1691,
    1692,  1695,  1703,  1704,  1708,  1709,  1714,  1715,  1722,  1723,
    1724,  1725,  1726,  1727,  1731,  1739,  1744,  1752,  1757,  1762,
    1767,  1775,  1780,  1788,  1793,  1801,  1816,  1829,  1839,  1852,
    1853,  1861,  1869,  1870,  1878,  1879,  1887,  1896,  1906,  1919,
    1928,  1929,  1937,  1938,  1945,  1945,  1945,  1949,  1950,  1951,
    1952,  1953,  1954,  1955,  1956,  1957,  1958,  1962,  1968,  1975,
    1976,  1977,  1978,  1982,  1983,  1987,  1988,  1992,  1993,  1994,
    1995,  1996,  1998,  1999,  2000,  2004,  2013,  2014,  2020,  2026,
    2032,  2042,  2050,  2051,  2055,  2056,  2064,  2073,  2074,  2083,
    2084,  2085,  2086,  2087,  2092,  2098,  2104,  2110,  2116,  2128,
    2143,  2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,  2152,
    2156,  2165,  2166,  2167,  2168,  2169,  2173,  2177,  2185,  2186,
    2190,  2195,  2199,  2207,  2208,  2212,  2213,  2218,  2219,  2228,
    2229,  2233,  2234,  2238,  2239,  2240,  2244,  2248,  2253,  2254,
    2255,  2259,  2263,  2264,  2265,  2266,  2267,  2271,  2277,  2286,
    2290,  2294,  2298,  2302,  2306,  2310,  2328,  2335,  2342,  2349,
    2358,  2365,  2372,  2379,  2386,  2401,  2402,  2406,  2407,  2408,
    2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,  2420,  2421,
    2425,  2432,  2441,  2445,  2452,  2453,  2454,  2455,  2459,  2460,
    2464,  2468,  2472,  2476,  2485,  2486,  2487,  2492,  2493,  2497,
    2498,  2499,  2500,  2501,  2504,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2513,  2514,  2515,  2516,  2517,  2518,  2519,  2520,
    2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2530,  2531,
    2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,
    2542,  2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,
    2555,  2556,  2557,  2558,  2561,  2562,  2563,  2569,  2570,  2571,
    2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,  2581,
    2582,  2583,  2584,  2585,  2586,  2587,  2588,  2589,  2590,  2591,
    2593,  2594,  2595,  2596,  2597,  2598,  2599,  2600,  2601,  2602,
    2603,  2604,  2605,  2606,  2607,  2608,  2609,  2611,  2612,  2613,
    2614,  2615,  2616,  2617,  2618,  2619,  2620,  2621,  2624,  2625,
    2626,  2627,  2628,  2629,  2630,  2631,  2632,  2637,  2638,  2639,
    2640,  2641,  2648,  2655,  2662,  2672,  2679,  2689,  2701,  2708,
    2718,  2730,  2740,  2750,  2757,  2770,  2780,  2790,  2800,  2812,
    2827,  2834,  2841,  2848,  2860,  2867,  2874,  2881,  2888,  2898,
    2907,  2917,  2918,  2922,  2930,  2931,  2939,  2946,  2955,  2956,
    2960,  2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2978,
    2979,  2983,  2984,  2985,  2986,  2990,  2991,  2992,  2993,  2994,
    2997,  2998,  3001,  3002,  3005,  3006,  3007,  3008,  3009,  3012,
    3013,  3016,  3019,  3020,  3021,  3022,  3023,  3024,  3025,  3029,
    3030,  3039,  3040,  3049,  3050,  3051,  3057,  3066,  3067,  3071,
    3072,  3076,  3087,  3098,  3109,  3122,  3129,  3136,  3144,  3151,
    3163,  3170,  3177,  3185,  3195,  3202,  3209,  3217,  3225,  3232,
    3239,  3247,  3254,  3263,  3273,  3280,  3287,  3297,  3307,  3314,
    3321,  3328,  3335
};
#endif

#if BIGQUERY_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "NAMES", "STR", "INTNUM",
  "BOOL_VAL", "APPROXNUM", "NULLX", "UNKNOWN", "QUESTIONMARK", "PARAM",
  "CROSS", "FULL", "INNER", "JOIN", "LEFT", "NATURAL", "RIGHT", "USING",
  "UMINUS", "'('", "')'", "'.'", "ALL", "AND", "ANY", "AS", "ASC", "AVG",
  "BETWEEN", "BY", "CALL", "CASE", "CAST", "CNNOP", "COALESCE",
  "CODE_UNITS", "COLLATE", "COMP_EQ", "COMP_GE", "COMP_GT", "COMP_LE",
  "COMP_LT", "COMP_NE", "CONVERT", "CORRESPONDING", "COUNT", "CUME_DIST",
  "CURRENT", "CURRENT_TIMESTAMP", "CURRENT_USER", "DAY", "DEC", "DEFAULT",
  "DELETE", "DENSE_RANK", "DESC", "DISTINCT", "ELSE", "END", "END_P",
  "ESCAPE", "ERROR", "EXCEPT", "EXCLUDE", "EXISTS", "FOLLOWING", "FOR",
  "FROM", "G", "GROUP", "GROUPING", "HAVING", "HOUR", "IN", "INSERT",
  "INTERSECT", "INTERVAL", "INTO", "IS", "K", "LARGE", "LIKE", "M", "MAX",
  "MIN", "MINUTE", "MOD", "MONTH", "MULTISET", "NATIONAL", "NO", "NOT",
  "NULLIF", "NUMERIC", "OBJECT", "OCTETS", "OF", "ON", "ONLY", "OR",
  "ORDER", "OTHERS", "OUTER", "OVER", "PARTITION", "PERCENT_RANK",
  "PRECEDING", "PRECISION", "RANGE", "RANK", "READ", "REAL", "RECURSIVE",
  "REF", "ROW", "ROWS", "ROW_NUMBER", "SCOPE", "SECOND", "SELECT",
  "SESSION_USER", "SET", "SETS", "SMALLINT", "SOME", "STDDEV_POP",
  "STDDEV_SAMP", "SUM", "SYSTEM_USER", "THEN", "TIES", "TO", "UNBOUNDED",
  "UNION", "UPDATE", "VALUES", "VARCHAR", "VARYING", "VAR_POP", "VAR_SAMP",
  "WHEN", "WHERE", "WITH", "WITHOUT", "YEAR", "ZONE", "LIMIT", "OFFSET",
  "ORDINAL", "SAFE_OFFSET", "SAFE_ORDINAL", "REPLACE", "NULLS", "FIRST",
  "LAST", "ARRAY", "STRUCT", "INT64", "FLOAT64", "STRING", "BYTES",
  "DATETIME", "DATE", "TIMESTAMP", "TIME", "BOOL", "VALUE", "UNNEST",
  "OP_LS", "OP_RS", "FIRST_VALUE", "RESPECT", "IGNORE", "WINDOW",
  "LAST_VALUE", "NTH_VALUE", "LEAD", "LAG", "PERCENTILE_CONT",
  "PERCENTILE_DISC", "NTILE", "ARRAY_AGG", "CORR", "COVAR_POP",
  "COVAR_SAMP", "STRING_AGG", "ANY_VALUE", "COUNTIF", "SAFE_CAST",
  "ARRAY_CONCAT_AGG", "BIT_XOR", "LOGICAL_AND", "LOGICAL_OR",
  "APPROX_COUNT_DISTINCT", "APPROX_QUANTILES", "APPROX_TOP_COUNT", "WEEK",
  "QUARTER", "DAYOFWEEK", "DAYOFYEAR", "ISOWEEK", "ISOYEAR", "MICROSECOND",
  "MILLISECOND", "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY",
  "FRIDAY", "SATURDAY", "AT", "EXTRACT", "DATE_ADD", "DATE_SUB",
  "DATE_DIFF", "DATE_TRUNC", "DATETIME_ADD", "DATETIME_SUB",
  "DATETIME_DIFF", "DATETIME_TRUNC", "TIME_ADD", "TIME_SUB", "TIME_DIFF",
  "TIME_TRUNC", "TIMESTAMP_ADD", "TIMESTAMP_SUB", "TIMESTAMP_DIFF",
  "TIMESTAMP_TRUNC", "TO_JSON_STRING", "STDDEV", "VARIANCE", "STARTS_WITH",
  "ENDS_WITH", "REGEXP_CONTAINS", "REGEXP_EXTRACT", "REGEXP_REPLACE",
  "GENERATE_TIMESTAMP_ARRAY", "GENERATE_DATE_ARRAY", "SYSTEM_TIME", "IF",
  "';'", "'{'", "'}'", "','", "'*'", "'['", "']'", "'^'", "'+'", "'-'",
  "'~'", "'!'", "'&'", "'|'", "'/'", "$accept", "sql_stmt", "stmt_list",
  "stmt", "call_stmt", "sql_argument_list", "sql_argument",
  "value_expression", "sp_name", "dql_stmt", "dml_stmt", "insert_stmt",
  "insert_columns_and_source", "from_constructor", "delete_stmt",
  "update_stmt", "table_and_alias", "update_elem_list", "update_elem",
  "select_stmt", "limit_num", "offset_num", "query_expression",
  "query_expression_body", "query_term", "query_primary",
  "select_with_parens", "select_stmt_with_parens", "subquery",
  "table_subquery", "row_subquery", "simple_table", "select_as_clause",
  "opt_where", "opt_from_clause", "opt_groupby", "grouping_element_list",
  "grouping_element", "opt_order_by", "order_by", "sort_list", "sort_key",
  "opt_asc_desc", "opt_nulls", "opt_having", "with_clause", "with_list",
  "common_table_expr", "opt_derived_column_list",
  "simple_ident_list_with_parens", "simple_ident_list", "opt_distinct",
  "select_expr_list", "projection_comma", "projection",
  "row_expr_op_as_label", "asterisk_expr", "asterisk_qualify",
  "except_expr", "repalce_expr", "row_expr_as_label_list",
  "row_expr_as_label", "from_list", "table_reference", "table_primary",
  "table_primary_non_join", "for_system_time_as_of", "with_as_num",
  "unnest_def", "column_ref", "column_ref_bigquery",
  "opt_array_index_type", "relation_factor", "custom_function_name",
  "joined_table", "qualified_join", "join_on", "cross_join",
  "qualified_join_2", "natural_join", "join_type", "join_outer",
  "search_condition", "boolean_term", "boolean_factor", "boolean_test",
  "boolean_primary", "parens_boolean_primary", "nonparens_boolean_primary",
  "predicate", "comparison_predicate", "between_predicate",
  "like_predicate", "in_predicate", "is_predicate", "exists_predicate",
  "row_expr", "factor", "factor0", "factor1", "factor2", "factor3",
  "factor4", "bool_row", "or_cond", "or_cond2", "and_cond", "and_cond2",
  "not_cond", "not_cond2", "bool_primary_row", "bool_primary_row_sub",
  "predicate_row", "comparison_predicate_row", "between_predicate_row",
  "like_predicate_row", "in_predicate_row", "is_predicate_row",
  "exists_predicate_row", "struct_def", "row_expr_op_as_label_list",
  "struct_mumber_def", "name_2_type_list", "name_2_type", "array_def",
  "array_mumber_def", "row_expr_list", "in_expr", "truth_value", "comp_op",
  "cnn_op", "comp_all_some_any_op", "bit_shift_op", "plus_minus_op",
  "star_div_percent_mod_op", "expr_const", "numeric_num", "const_string",
  "case_expr", "case_arg", "when_clause_list", "when_clause",
  "case_default", "func_expr", "aggregate_windowed_function",
  "aggregate_function_name", "ranking_windowed_function",
  "ranking_function_name", "over_clause", "opt_over_clause",
  "window_specification", "window_name", "window_specification_details",
  "opt_existing_window_name", "opt_window_partition_clause",
  "opt_window_frame_clause", "window_frame_units", "window_frame_extent",
  "window_frame_start", "window_frame_preceding", "window_frame_between",
  "window_frame_bound", "window_frame_following",
  "opt_window_frame_exclusion", "scalar_function",
  "non_second_primary_datetime_field", "function_call_keyword",
  "data_type", "predefined_type", "combination_type", "struct_type",
  "array_type", "distinct_or_all", "all_some_any", "opt_as_label",
  "as_label", "label", "collate_clause", "name_r", "name_f", "reserved",
  "function_name", "call_keyword", "bigquery_func_name",
  "datatype_reserved", "bigquery_function", "opt_window_clause",
  "window_clause", "window_list", "window_list_element",
  "opt_respect_nulls", "date_part", "datetime_part", "datetime_part2",
  "day_part", "ext_day_part1", "ext_day_part2", "hour_part",
  "hour_day_part", "week_func", "week_", "date_expression",
  "datetime_expression", "timestamp_expression", "all_date_expression",
  "opt_at_time_zone", "interval_date_part", "interval_datetime_part",
  "interval_time_part", "date_function", "datetime_function",
  "time_function", "string_function", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    40,    41,    46,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,    59,   123,   125,    44,    42,    91,
      93,    94,    43,    45,   126,    33,    38,   124,    47
};
# endif

#define YYPACT_NINF -941

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-941)))

#define YYTABLE_NINF -449

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     301,   137, 10929,  8769,  9009,   358, 10929,  9249,    46,   152,
     104,   -15,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
     399,   198,  -941,  -941,    34,   224,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,   329,  -941,  -941,  -941,  -941,   373,  -941,  -941,  -941,
    -941,  -941, 10929,   245,  9489, 10929,   632,  -941,  -941,   390,
     305, 10929,  -941,   200,   466, 10929,  -941,  -941,   301,   437,
     473,   358,   362,  -941,   489,   399,  -941,  4626,  9729,   245,
    3618,  -941, 10929,  -941,  -941,  -941,  -941,   632,  7809,   393,
    5382,  -941,  -941,  -941,   365,   239,  2862,  5382,  -941, 10929,
   10929,   550,  -941,   547,  -941,    34,  5382,    34,   612,  -941,
      34,   362,   562,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
     566,   584,  3870,  -941,  5382,   598,   606,   608,   619,  -941,
     624,   631,    31,   391,   645,   648,   650,   663,   659,   673,
     687,   707,   724,   752,   754,   794,   803,   808,   812,   823,
     827,   843,   848,   851,   854,   860,   877,   878,   881,   886,
     888,   889,   890,   899,   900,   901,   903,   904,   905,   906,
     907,   908,   912,   913,   921,   922,   923,   925,   926,   928,
     929,   930,   931,   934,   935,   938,   939,   941,   943,  5382,
    5382,  5382,  5382,   668,   720,   942,  -941,  -941,  -941,   722,
    -941,   947,   554,    13,    94,   193,   726,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,   950,  -941,   953,
    -941,  -941,   954,  -941,   957,  -941,  -941,  -941,  -941,  -941,
    9969,   956,  -941,  2358,   978,  3618,   896,   980,  -941,  -941,
      90,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
     721,  -941,  -941,   984,   761,  -941,    79,  -941,  -941,  -941,
    -941,  -941,  2610,   978,  4122,  -941,   948,  2862,   762,  -941,
    -941,    56,  2118,  9489,  -941,   909,   987,   117,   296,   118,
    -941,  -941,  -941,  -941,  -941,  -941,   993,   948,   772,   691,
    -941,   978,  4878,   198,  -941,   774,   635,   198,   872,   872,
     872,  -941,  -941,  1000,  1002,  3870,  1003,  1005,   554,   887,
    5382,  5382,  5382,   430,  5382,  -941,   137,   640,  5382,  -941,
     780,  4374,  8049,  1012,  -941,  -941,  -941,  -941,  5382,  5382,
    5382,  5382,  5382,  5382,  5382,  5382,   358,  5382,  5382,  5382,
     358,  5382,  3618,  5382,  5382,   358,  3618,  3618,   358,   358,
     358,  1010, 11169, 11169, 11169, 11169, 11409, 11409, 11409, 11409,
    7328,  7328,  7328,  7328,  7328,  7328,  7328,  7328, 10929,   358,
     358, 10929, 10929, 10929, 10929, 10929,  5382,  5382,  3618,   785,
    -941,  -941,  -941,  -941,  5382,   640,   744,  -941,  5130,  -941,
   10929,  5382,  -941,  -941,  -941,  -941,  -941,  5382,  -941,  -941,
    5382,  -941,  -941,  5382,  5382,  3114,  1013, 11649, 10929,  1014,
   10209,  2358,    59,    81,   137,  -941,  -941,  -941,  3618,  3618,
    -941,  -941,  1001,  -941,   481,  -941,   505,  5382,  1006,    66,
    5382,  5382,  1018,   513,  -941, 10929,  5382,  2610,    88,  1019,
    -941,  2610,   807,  -941,  -941,  -941,  -941,  8529,   245,  -941,
    -941,   466,  1021,   891,  -941,  5382,  1018,   541,  -941,  -941,
    4122,  4122,  4122,  4122,   594,  5382,  5634,  6367,   245,  5382,
    5382,  -941,   801,  1027,  5382,  -941,  -941,   898,   781,  -941,
    -941,  -941,  -941,  -941,  1028,  -941,  -941,  3618,   994,   887,
     755,  1032,   601,  1033,  -941,   119,  -941,  1015,  1016,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  1020,  -941,
    -941,  -941,  -941,   811,  5382,   810,  1041,   -20,     8,    72,
      86,   103,   107,   108,   125,   127,  1023,   819,  -941,   640,
    5382,   386,   386,   820,    28,    39,   124,   126,  1045,  5382,
     141,   162,   168,  5382,  1046,    93,   835,   465,  5382,   113,
     171,  5382,  5382,  5382,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  1048,  -941,  -941,  -941,  -941,  -941,  -941,
    -941,  1004,  -941,  -941,  -941,  -941,  -941,  1067,  -941,   826,
     830,   831,   833,  1071,  -941,   839,   840,   842,   844,  1070,
    1088,  1089,  -941,  1072,   850,   855,   856,   857,   858,   859,
     861,   862,    41,  5382,  5382,   863,   864,   865,   866,   867,
     169,   177,   -24,  -941,  -941,  -941,  1079,  1085,  1093,  1094,
    -941,  1095,  -941,    13,    94,   193,   726,  -941,  -941,  -941,
    1097,   599,  5382,  1017,  1100,  -941,  -941, 10929, 10929,  1101,
    -941,  1098,   980,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
     897,  -941,   603,  -941,  -941,  -941,  -941,  -941,   554,   677,
    3870,  -941,  -941,  5382,  1018,  5382,  -941,  -941,    97,  1103,
    7569,  1105,  9489,  -941,    82,  -941,  -941,  9489,  9489,  -941,
    -941,  -941,  -941,  -941,  1056,  -941,  5382,  -941,   702,  -941,
    5382,  1018,  5382,  -941,  -941,   909,   987,   117,  -941,  -941,
     987,  1104,  -941,  -941,   897,  -941,   634,   554,  -941,  -941,
    1109,  -941,  -941,   554,  -941,   883,  -941,   672,  -941,  -941,
    -941,  -941,   604,   418,  5382,  1073,  -941,   640,  -941, 10929,
    -941,  5382,  -941,  -941,  -941,  -941,   892,  4374,  -941,  -941,
    8049,  -941,  1113,   983,   986,  1116,  1120,   773,  1017,  1139,
    1017,  1140,   773,   773,  1017,   286,  5382,  5382,  5382,    51,
    1017,  1017,   640,   362,   669,  -941,  -941,   711,   205,   215,
     776, 10449,  -941,  1068,  1068, 11169,  1010,  -941,  1069,  1069,
   11409,   614,  -941,  -941, 11649,  1074,  1074,  7328,   495,  1074,
    1074,  7328,   614,  -941,  3618,   750,   787,  1144,  1145,  1146,
    1149,  1150,  5382,  5382,  5382,  1152,  1154,  1156,  1157,  -941,
    1017,  1017,   788, 10689,  -941, 11649,  -941,  -941, 10929,  -941,
    -941,  5382,  5382,  1141,   736,  -941,   647,  -941,  7569,   977,
    1143,  6127,  -941,  1151,  1063,  -941,  8529,  1063,   871,  1063,
    8529,  1153,  1025,   248,  1148,  1107,  1155,   924,  8289,  5382,
     814,  -941,   660,  -941,  5382,  6607,  -941,  -941,  -941,  5382,
     554,  -941,  1159,  1161,   816,  -941,  -941,  -941,  -941,  -941,
    -941,  1017,  1017,   645,   648,   650,   663,   386,  -941,    60,
    -941,    61,   386,   386,  -941,  1082,   821,   828,   836,   773,
    1082,  -941,  -941,  -941,  1163,  1164,  -941,  -941,  1166,  1183,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  1167,  -941,  -941,
     981,  5382,  1168,  1174,   951,  1176,  5382,  1177,  1178,   958,
    1180,  -941,  -941,  -941,  -941,  1184,  5382,  1181,  1194,   960,
    1195,  1196,  1200,   979,    62,   356,  1017,  1017,  1201,  1202,
    1204,  1205,   982,   221,   222,   277,  1207,  1208,  1209,  1210,
    -941,  -941,  1017, 10929,  -941,  -941,  -941,  1211,  -941,  -941,
     554,   554,  -941,  5382,  5382,   224,  -941,  -941,   132,  1213,
    1214,  1215,  8529,  -941,  -941,   192,  -941,  8529,  1218,  -941,
    -941,  8529,  1090,  -941,   996,  -941,  -941,   358,  3618,  1065,
    -941,  5382,  -941,   554,  5382,  5382,   554,  -941,  1219,   554,
    -941,  -941,  -941,  -941,  -941,  1221,  1017,  5382,  1017,  5382,
    1222,  1223,   362,  1017,  1017,  1017,   386,   362,  -941,  -941,
     386,  1224,  -941,  1075,  1225,   543,  -941,  -941,  1010,  -941,
     559,  -941,  -941,   614,  -941, 11889,   527,  -941,  -941,   495,
    -941,  -941,  -941,   479,  -941,  1245,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  1246,  1069,  1068,  5382,  1008,  1009,  1011,
    1024,  -941,  -941,  1229,  1158, 10929,   554,   554,  -941,  -941,
   10929,  -941,   466,  3618,  -941,  -941,  8529,   212,  9489,  1227,
    5886,   896,  1250,  -941,  -941,  -941,   554,   554,  6847,  1017,
    -941,  1233,  -941,  1240,  1017,  1017,  1241,  -941,  -941,  -941,
    1082,  1243,  1244,  -941,  1121,  -941,  -941,  -941,  1247,  -941,
    -941,  -941,  1254,  -941,  -941,  -941,  -941,  -941,  1255,  1256,
    1257,  1259,  1260,  1261,   845,  -941,  -941,  -941,  -941,  -941,
    1236,  1082,  -941,  1249,  -941,   896,  -941,   466,  -941,  -941,
    1187,  3366,  1162,  -941,  1043,   554,  1263,  -941,  1047,  -941,
    -941,  1017,  1017,  -941,  -941,  1017,   362,  1017,  -941,  1283,
    -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  -941,  5382,
     331, 10929,  -941,  7087,  -941,  1270,  5886,   231,  1250,  -941,
    -941,  -941,  1272,  -941,  -941,  -941,  -941,  -941,  -941,   713,
    -941,  -941,  -941,  5886,  -941,  -941,  -941,  -941,  1017,   602,
    1179,  1188,  1189,  1234,  -941,  -941,  -941,  1276,  -941,    42,
     339,  -941,  1267,  -941,  -941,  -941,  -941,   312,  -941,  -941,
    -941,  -941,   602,  1192,  -941,  1206,  -941,  -941,  -941,  -941
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     3,     8,     6,     7,    22,    21,    20,    19,    38,
      76,    49,    52,    54,     0,     0,   444,   350,   451,   506,
     452,   504,   453,   358,   364,   401,   362,   454,   359,   402,
     455,   456,   457,   458,   351,   352,   403,   459,   400,   460,
     461,   505,   462,   463,   464,   465,   363,   466,   361,   467,
     468,   469,   470,   365,   471,   472,   473,   474,   475,   354,
     355,   353,   476,   477,   478,   479,   356,   357,   480,   399,
     481,   482,   483,   485,   484,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   404,   405,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,     0,    18,   500,   501,   449,   153,   445,   446,   503,
     502,   450,     0,    65,   438,     0,     0,   101,   102,    62,
       0,     0,    90,    92,    95,     0,     1,     2,     5,     0,
       0,   100,    39,    77,     0,    76,    55,     0,     0,    65,
       0,    32,     0,    34,   439,   441,   442,     0,     0,     0,
       0,    24,    28,    25,     0,     0,     0,     0,    91,     0,
       0,     0,    96,     0,     4,     0,     0,     0,     0,    47,
       0,    39,   444,   326,   318,   324,   319,   317,   320,   321,
       0,     0,     0,    10,   332,     0,   506,   504,     0,   413,
     505,     0,     0,     0,   562,   563,   564,   565,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,     0,     0,
       0,     0,     0,     0,    13,    15,    58,    60,   231,   148,
     229,     0,    17,   214,   217,   219,   221,   223,   225,   234,
     235,   230,   323,   322,   232,   233,   342,   500,   341,   501,
     340,   339,   143,   161,   445,   343,   567,   568,   569,   570,
       0,   154,    31,     0,     0,     0,    66,   184,   186,   188,
     191,   193,   192,   190,   196,   197,   199,   198,   200,   201,
     195,   440,    23,     0,    98,    29,   290,    30,    27,    26,
      63,    64,     0,     0,     0,   115,    67,   104,   103,   107,
     108,   111,   438,   438,   236,   237,   238,     0,   254,   239,
     258,   259,   261,   260,   262,   263,   143,    67,    35,     0,
      93,     0,     0,    51,    78,    79,    82,    50,    43,    43,
      43,    53,    48,     0,     0,     0,     0,     0,   333,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,   571,
       0,     0,     0,     0,   330,   329,   328,   327,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     100,     0,     0,     0,     0,   100,     0,     0,   100,   100,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,     9,     0,     0,     0,   147,     0,   307,
       0,     0,   215,   310,   309,   311,   312,     0,   313,   314,
       0,   315,   316,     0,     0,     0,     0,     0,     0,   156,
       0,     0,     0,   195,     0,    59,   213,   189,     0,     0,
     301,   299,   300,   297,   298,   302,     0,     0,     0,   434,
       0,     0,     0,     0,    97,     0,     0,     0,   256,     0,
     275,     0,   256,   253,   251,   252,   255,     0,    65,   105,
     106,     0,     0,   112,   113,     0,     0,     0,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    65,     0,
       0,    94,     0,     0,     0,    83,    84,    85,     0,    40,
      41,    42,   407,   406,     0,    56,   276,     0,   337,   334,
       0,     0,     0,     0,   411,     0,   418,   427,     0,   417,
     419,   421,   422,   424,   423,   426,   425,   420,     0,   415,
     416,   428,   429,     0,     0,   279,     0,   558,   559,   560,
     561,   562,   563,   564,   565,   566,     0,   282,   284,     0,
       0,   608,   608,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,   625,   638,   637,   627,   636,   629,
     617,   616,   618,   626,   628,   630,   631,   632,   633,   634,
     635,     0,   611,   613,   614,   612,   615,   563,   649,     0,
       0,     0,     0,   562,   651,     0,     0,     0,     0,     0,
     564,   565,   654,   653,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   286,    14,    16,     0,     0,     0,     0,
     397,     0,   443,   216,   218,   220,   222,   224,   432,   433,
       0,     0,     0,     0,   144,   162,   160,     0,     0,   155,
     194,     0,   185,   187,   303,   304,   305,   294,   296,   295,
       0,   211,   205,   306,   435,   437,   436,   308,   202,     0,
       0,   292,   209,     0,     0,     0,    99,   291,   240,     0,
       0,     0,   438,    68,   124,   126,   128,   438,   438,   127,
     164,   165,   167,   166,    69,   119,     0,   114,     0,   271,
       0,     0,     0,   244,   242,   245,     0,   243,   249,   247,
     250,   248,   246,   241,     0,   273,   267,   256,   264,   116,
     144,    33,    36,    37,    12,     0,    80,     0,    81,    44,
      45,    46,    56,     0,     0,     0,   335,     0,   410,     0,
     412,     0,   431,   430,   289,   287,     0,     0,   277,   281,
       0,   285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   608,     0,     0,     0,   608,
     368,   368,     0,    39,     0,   595,   596,     0,     0,     0,
       0,     0,   650,     0,     0,     0,     0,   652,     0,     0,
       0,     0,   655,   656,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   684,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   398,
     349,   345,     0,     0,   360,     0,   158,   159,     0,    57,
     212,     0,     0,     0,     0,   210,   207,   257,     0,     0,
     127,     0,   133,     0,   182,   181,     0,   182,     0,   182,
       0,     0,   134,   130,     0,    88,     0,   121,     0,     0,
       0,   272,   269,   274,     0,     0,    11,    86,    87,     0,
     338,   331,     0,     0,     0,   288,   280,   283,   278,   609,
     610,     0,     0,     0,     0,     0,     0,   608,   575,     0,
     578,     0,   608,   608,   583,    76,     0,     0,     0,     0,
      76,   369,   590,   591,     0,     0,   594,   597,     0,     0,
     642,   643,   644,   645,   646,   647,   648,     0,   658,   657,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   622,   623,   621,   624,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   368,   368,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     348,   344,   347,   373,   367,   366,   371,   145,   163,   157,
     206,   203,   293,     0,     0,     0,   129,   141,     0,     0,
       0,   143,     0,   183,   178,   174,   179,     0,     0,   180,
     125,     0,     0,   135,     0,   131,   132,   100,     0,   601,
     120,     0,   123,   265,     0,     0,   268,   117,   145,   336,
     408,   409,   414,   572,   573,     0,     0,     0,     0,     0,
       0,     0,    39,   368,   368,   368,   608,    39,   592,   593,
     608,     0,   641,     0,     0,     0,   665,   666,     0,   668,
       0,   670,   671,     0,   673,     0,     0,   674,   675,     0,
     677,   678,   679,     0,   681,     0,   685,   686,   687,   688,
     689,   690,   691,     0,     0,     0,     0,     0,     0,     0,
       0,   346,   374,     0,   375,     0,   204,   208,   142,   140,
       0,   173,     0,     0,   169,   177,     0,   175,   438,     0,
       0,    89,     0,    61,   602,   122,   266,   270,     0,     0,
     576,     0,   579,     0,     0,     0,     0,   585,   586,   587,
      76,     0,     0,   599,     0,   664,   626,   661,     0,   662,
     620,   619,     0,   447,   448,   640,   639,   663,     0,     0,
       0,     0,     0,     0,     0,   149,   150,   151,   152,   370,
       0,    76,   146,   144,   171,   172,   176,     0,   168,   139,
       0,     0,   359,    70,    71,    74,     0,   603,   604,   118,
     574,     0,     0,   581,   582,   368,    39,   368,   598,     0,
     667,   672,   676,   680,   682,   692,   683,   669,   600,     0,
     377,     0,   170,     0,    73,     0,     0,     0,     0,   577,
     580,   584,     0,   588,   660,   376,   380,   379,   372,     0,
     136,   138,   137,     0,    72,   606,   607,   605,   368,     0,
       0,     0,     0,   392,   381,   385,   382,     0,   589,     0,
       0,   388,     0,   390,   384,   383,   386,     0,   378,    75,
     389,   391,     0,     0,   394,     0,   395,   387,   393,   396
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -941,  -941,  1123,  -941,  -941,  -283,  -941,  -412,  1127,  -941,
    -941,  -941,  1106,  1102,  -941,  -941,  1308,   729,  -941,   154,
    -218,   472,    14,  1291,   -16,  1096,  -941,  -941,  -243,  -289,
    -941,  -941,  -941,  -158,   918,  -941,  -859,  -941,  -168,  -941,
     725,  -941,  -941,  -941,  -941,  -941,   -93,  -941,  -941,  -176,
     775,  -175,   940,  -941,  -941,  -431,  -941,  -941,  -941,   759,
     217,  -941,   374,  -677,  -864,  -941,  -941,   370,  -941,  -940,
    -941,  -941,    17,  -941,  -637,  -941,   138,  -941,  -941,  -941,
     378,  -410,  -188,   799,  -274,  -941,  -941,  -941,  -941,  -941,
    -941,  -941,  -941,  -941,  -941,  -941,   976,   832,   824,   818,
     817,  -164,  -941,  -293,    49,   763,   335,   760,  -181,  -941,
    -149,   758,   -64,  -941,  -941,  -941,  -941,  -941,  -941,  -941,
     488,   730,   487,  -941,   398,   733,  -207,  -534,  -527,  -941,
    -941,   955,  -941,  -941,  -941,  -812,  -941,   460,  -941,  -941,
     743,  -941,  -941,  -452,  -941,    64,  -941,   184,  -628,  -713,
      57,   283,  -941,  -941,  -941,  -941,  -941,  -941,    52,  -941,
    -941,    20,  -941,  -941,  -941,  -941,  -941,  -419,  -941,  -941,
    -941,  -941,  -941,  -941,  -386,   396,  1165,  -941,    -2,  -510,
     829,  -941,  -941,  -941,  -941,  -941,  -941,  -941,    67,  -941,
    -627,  -842,  -941,  -886,  -854,  -941,  -853,  -832,   203,  -849,
    -941,  -401,  -433,  -378,  -941,  -941,  -870,  -885,  -161,  -941,
    -941,  -941,  -941
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,   313,   314,   315,   161,    13,
      14,    15,   211,   212,    16,    17,   173,   407,   408,   761,
     229,   599,    19,    20,    21,    22,   316,   535,   317,   792,
     318,    23,   216,   201,   568,   965,  1263,  1264,   192,   193,
     414,   415,   597,   838,  1109,    24,   182,   183,   221,   214,
     373,   179,   386,   387,   388,   389,   390,   391,   573,   574,
     966,   967,   793,   794,   795,   796,  1105,  1103,   797,   319,
     320,   507,   798,   321,   799,   800,  1194,   801,   802,   803,
     961,  1094,   532,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   376,   323,   324,   325,
     326,   327,   328,   393,   394,   814,   395,   819,   396,   564,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   329,
     636,   443,   646,   647,   330,   440,   427,   782,   771,   549,
     511,   550,   517,   520,   523,   331,   332,   333,   334,   429,
     608,   609,   845,   335,   336,   337,   338,   339,  1011,  1012,
    1074,  1075,  1183,  1184,  1251,  1308,  1309,  1323,  1331,  1325,
    1326,  1332,  1333,  1338,   340,   165,   341,   648,   629,   630,
     631,   632,   752,   777,   203,   204,   205,   512,   342,   343,
     344,   168,   169,   170,   171,   345,  1203,  1204,  1267,  1268,
     865,   691,  1229,  1040,   692,   693,   694,   695,  1237,   696,
    1027,   699,   705,   714,  1030,  1144,  1032,  1037,  1047,   346,
     347,   348,   349
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     166,   166,   166,   377,   166,   184,   578,   579,   222,   439,
     635,  1089,   356,   422,  1038,    25,   227,   755,   628,   162,
     174,   176,  -417,   174,  1033,   866,  1054,   231,   712,   712,
     712,   712,   712,   712,   712,   712,   651,   652,   653,   654,
     655,   352,   809,   658,   706,   707,   708,  1041,  1042,   664,
    -419,   868,  1044,   436,  1035,   997,     1,   825,  1041,  1042,
    1002,  1003,   870,  1044,   913,   536,   163,   163,   163,  1043,
     163,   163,   700,   701,   702,   437,  1050,   755,   538,   185,
    1043,   537,   760,  1126,  1128,  1164,   735,   509,   218,   559,
     510,   774,  1095,   775,   560,   953,   954,   955,   956,   957,
     958,   959,   499,   715,   716,   717,   718,   719,   720,   721,
    1340,  -290,   551,   949,  -421,   509,   881,   509,   510,   575,
     510,   571,   591,  -257,   509,   934,   410,   510,  -422,   593,
     540,   541,   542,   543,   544,   545,   885,  -257,  -257,  -257,
    -257,  -257,  -257,   582,  -255,  -424,   500,   501,   502,  -423,
    -426,  1335,   186,   950,    18,   509,     5,   552,   510,     1,
     509,   538,   509,   510,   576,   510,   187,  -425,  1013,  -420,
     166,   546,   206,   166,   547,   553,   437,   509,  -257,   184,
     510,  -257,   577,   166,   513,   514,   164,   164,   164,   199,
     164,   164,   207,   776,   886,   538,   351,  1136,   509,  -257,
     206,   510,   162,   563,   509,   509,   374,   510,   510,   413,
     572,   417,  1192,   509,   406,   538,   510,   184,   374,   583,
    -255,   734,    25,   924,   611,   863,   864,  -417,  1191,   188,
     861,   633,  1257,  1195,  1315,   565,   163,  1197,   163,   163,
     998,   509,  1000,   940,   510,   163,  1004,   196,  1005,   163,
     945,   509,  1010,  1073,   510,  -419,   426,   509,   509,     5,
     510,   510,   163,   781,   559,   763,   163,  1232,   789,   515,
     516,   949,   163,   538,   665,   869,   194,   971,   669,   670,
     438,   659,     7,   163,   163,   663,   871,   781,   914,  1242,
     668,  1227,  1193,   671,   672,   673,  1230,   973,  1009,  1041,
    1042,   741,  1070,  1071,  1044,  1243,  1228,  1127,  1129,  1165,
     732,   950,  1193,   509,   723,   724,   510,  1104,  1231,  -421,
     566,  1043,   509,     1,  1236,   510,   556,  1238,   556,   960,
     213,  1236,  1256,  -422,     2,   556,   540,   541,   542,   543,
     544,   545,    18,  1167,  1168,   548,   518,   519,   529,   787,
    -424,   197,  -257,  1311,  -423,  -426,   164,     3,   164,   164,
     747,   213,  1343,  1123,  1124,   164,   851,   426,   379,   164,
    1125,   872,  -425,   873,  -420,  1130,  1131,   584,     4,  1166,
     585,   438,   164,   177,  1344,   406,   164,     1,   876,   200,
     206,   206,   164,  1102,   755,   805,   426,   198,   380,   816,
     820,   820,   816,   164,   164,  1345,   952,  1341,   381,   877,
     804,   962,   963,   441,   163,   878,   922,   178,   215,   843,
    1217,  1218,  1219,     5,   923,  1078,   635,   856,   982,   217,
     831,   817,   821,   821,   817,   442,   613,  1314,     6,   604,
     649,   521,  1306,   862,  1181,  1346,     7,   219,  1336,  1307,
     426,   522,  1018,   614,  1327,   712,   163,   163,   538,   712,
     863,   864,  1019,  1014,   189,  1078,   439,  1039,  1174,  1175,
     698,   698,   698,   698,   704,   704,   704,   704,   713,   713,
     713,   713,   713,   713,   713,   713,   722,     5,   220,   725,
     726,   727,   728,   729,  1034,   781,   225,  1322,  1210,   883,
    1212,   509,   190,   210,   510,   226,   163,  1330,   166,  1220,
       7,   228,   767,  1222,   768,   769,   566,   566,   566,   566,
     538,   765,   781,   766,  1176,   754,   756,   742,   759,  1049,
    1330,   375,  1235,  1053,   164,   191,   163,   163,   163,   163,
     163,   163,   163,   163,   783,   604,     8,  1096,   230,  1099,
     979,   548,   163,   374,   675,   163,   163,   163,   163,   163,
     863,   864,  1301,   509,  1303,   166,   510,   676,   190,   412,
     675,   604,   810,   943,   163,   426,   164,   164,   411,   509,
    1235,  1270,   510,   676,  -447,   830,  1273,  1274,   423,   784,
     509,   163,   163,   510,   163,   509,   674,   785,   510,   770,
     678,   767,   675,   768,   769,  1328,   424,   233,   234,   235,
     236,   237,   674,   238,   239,   676,   678,   811,   418,   163,
     430,   849,   931,   419,   420,   812,   164,   -55,   431,   813,
     432,   163,   813,   677,   675,   509,   435,   509,   510,   509,
     510,   433,   510,  1299,  1300,  1078,   434,   676,   678,   677,
     444,   163,  1320,   445,   208,   446,   164,   164,   164,   164,
     164,   164,   164,   164,   595,  1015,   941,   674,   447,   -55,
     509,   509,   164,   510,   510,   164,   164,   164,   164,   164,
     678,   448,   -55,   509,   689,   690,   510,   209,   824,   675,
     679,   503,  1016,   596,   164,   449,   509,   974,   251,   510,
     689,   690,   676,   942,   677,   509,   679,   -55,   510,   450,
    1084,   164,   164,   509,   164,  1211,   510,  1213,   233,   234,
     235,   236,   237,  1115,   238,   239,  1055,   509,   969,   451,
     510,   590,   689,   690,  1017,   678,   616,  1329,   509,   164,
     -55,   510,  1226,   684,  1319,  1048,   452,   509,  1051,  1052,
     510,   164,   551,   -55,     5,   936,   937,   509,  1226,   684,
     510,   679,  1083,  1320,   689,   690,   993,   994,   995,   996,
     210,   164,   509,  1056,   453,   510,   454,     7,   233,   234,
     235,   236,   237,   847,   238,   239,   509,   839,   166,   510,
     206,   509,   840,   841,   510,   206,   206,   552,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   251,
    1057,  1072,  1259,   683,   684,   553,   455,   687,   688,   689,
     690,   163,   163,   509,   509,   456,   510,   510,   977,   978,
     457,   167,   167,   167,   458,   167,   167,  1132,   575,  1122,
    1114,  1312,  1137,   509,  1133,   459,   510,   166,  1321,   460,
     509,  1134,   509,   510,   163,   510,   163,   509,   649,  1135,
     510,   163,   163,   882,   509,   461,   983,   510,  1288,   251,
     462,   509,   509,   463,   510,   510,   464,   993,   994,   995,
     996,   509,   465,   576,   510,   954,   955,  1097,   957,  1029,
     959,   600,   601,   698,   736,   737,   738,   739,   704,   466,
     467,   577,  1045,   468,   767,   713,   768,   769,   469,   713,
     470,   471,   472,   163,  1216,   815,   818,   818,   815,  1221,
    1201,   473,   474,   475,   163,   476,   477,   478,   479,   480,
     481,  1076,  1200,  1077,   482,   483,  1079,   993,   994,   995,
     996,   164,   164,   484,   485,   486,   166,   487,   488,  1091,
     489,   490,   491,   492,   166,   163,   493,   494,   166,   163,
     495,   496,  1085,   497,   163,   498,   206,   504,   163,   508,
     505,   506,   525,  1118,   164,   526,   164,   524,   527,  -448,
     530,   164,   164,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
     953,   954,   955,   956,   957,   958,   959,   163,   538,   163,
     534,   167,   163,   167,   167,  1255,   539,   554,   555,   570,
     167,   580,   163,   581,   167,   163,  1254,   587,   567,   589,
     163,   594,   598,   602,   163,   603,   605,   167,   606,   634,
     607,   167,   163,   164,   650,   733,   753,   167,   757,   163,
     780,   764,   788,   806,   164,   572,   773,   834,   167,   167,
     835,   842,  1276,   837,   844,   848,   850,   857,  1302,   437,
     442,   855,   854,   674,   858,   859,   860,   867,   874,   880,
     890,  1076,   892,   893,   891,   164,   897,   894,   895,   164,
     896,  1292,  1305,  1290,   164,   675,   898,   899,   164,   900,
     166,   901,   436,   902,   903,   166,   904,   905,   676,   166,
     677,   925,   906,   907,   908,   909,   910,   926,   911,   912,
     917,   918,   919,   920,   921,   927,   928,   164,   929,   164,
     930,   939,   164,   933,   935,   938,   947,   951,   964,   976,
     582,   678,   164,   975,   981,   164,   988,   163,   989,   991,
     164,   990,   985,   992,   164,   999,  1001,  1031,  1036,  1058,
    1059,  1060,   164,  1046,  1061,  1062,   163,   679,  1066,   164,
    1067,   163,  1068,  1069,  1082,   163,  1086,  1092,  1093,  1101,
    1102,  1111,  1140,   322,   680,   681,   370,   682,  1110,   167,
    1107,  1108,  1120,  1252,  1121,   190,  1138,  1139,  1253,  1141,
    1142,  1146,   392,   409,   166,  1143,   206,  1147,  1148,  1149,
    1151,  1152,   416,  1154,  1157,  1153,  1252,  1159,  1155,   683,
     684,   685,   686,   687,   688,   689,   690,  1158,  1160,  1161,
     428,   167,   167,  1162,  1169,  1170,  1163,  1171,  1172,  1173,
    1177,  1178,  1179,  1180,  1196,  1185,  1188,  1189,  1199,  1190,
    1198,  1202,  1224,  1208,  1209,  1214,  1215,  1223,  1225,   163,
    1240,  1241,  1249,  1266,   163,  1260,  1271,   164,  1245,  1246,
     163,  1247,   163,  1272,  1275,  1250,  1277,  1278,  1289,  1279,
    1280,   167,   163,  1291,  1248,   426,   164,  1281,  1282,  1283,
    1284,   164,  1285,  1286,  1287,   164,  1293,  1295,  1304,  1077,
    1296,  1297,  1313,  1342,  1298,  1318,  1334,  1335,  1336,  1339,
    1337,   167,   167,   167,   167,   167,   167,   167,   167,  1348,
    1349,   224,   223,   372,   180,   195,   378,   167,   832,   836,
     167,   167,   167,   167,   167,   588,   421,   569,  1205,   533,
     786,   370,   807,  1106,  1100,  1258,  1098,   762,   745,   167,
     746,   744,   822,   743,   828,   986,   823,   987,   853,  1090,
     852,  1028,   846,   586,  1316,   163,  1182,   167,   558,   167,
     562,  1324,  1347,   392,  1112,  1317,  1239,   371,     0,   164,
       0,     0,     0,     0,   164,     0,     0,     0,     0,     0,
     164,     0,   164,     0,   167,     0,     0,     0,   322,     0,
       0,     0,   164,     0,     0,     0,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,     0,   612,     0,
     615,     0,     0,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,   322,   322,   322,   322,   322,   656,
     657,   322,     0,   660,   661,   662,     0,   322,   370,   666,
     667,     0,   370,   370,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   730,   731,   370,   164,     0,     0,     0,     0,
     322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   751,     0,     0,     0,     0,     0,   533,     0,     0,
       0,     0,     0,     0,   370,   370,     0,     0,     0,     0,
       0,     0,     0,   772,     0,     0,   778,   779,     0,     0,
       0,     0,     0,   558,     0,     0,     0,   558,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   808,     0,     0,     0,     0,   562,   562,   562,   562,
       0,   826,   827,     0,     0,   409,   833,     0,     0,     0,
     416,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   370,     0,     0,   167,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,   167,     0,     0,     0,     0,   167,   167,     0,     0,
       0,     0,     0,     0,     0,   875,     0,     0,     0,   879,
       0,     0,     0,     0,   884,     0,     0,   887,   888,   889,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   915,
     916,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,     0,   167,     0,     0,     0,   932,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   944,
       0,   946,   167,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
     167,     0,   968,     0,     0,   167,   970,     0,   972,   167,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     980,     0,     0,     0,     0,     0,     0,   984,     0,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1006,  1007,  1008,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     370,     0,     0,     0,     0,     0,     0,     0,  1063,  1064,
    1065,     0,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1080,  1081,     0,
       0,   167,     0,     0,     0,     0,   167,     0,     0,     0,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1113,     0,     0,     0,     0,
    1116,     0,     0,     0,     0,  1119,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1234,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1145,     0,     0,
       0,     0,  1150,     0,   167,     0,     0,     0,     0,   167,
       0,     0,  1156,     0,     0,   167,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1186,
    1187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,     0,     0,   968,     0,     0,
    1206,  1207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   322,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -256,     0,   202,     0,    27,   575,
       0,    28,  1244,     0,   509,    29,    30,   510,  -256,  -256,
    -256,  -256,  -256,  -256,    31,    32,    33,    34,     0,   370,
       0,    35,     0,     0,     0,    36,  1265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,     0,    39,   576,    40,     0,     0,     0,  -256,
      41,    42,  -256,    43,    44,    45,    46,    47,    48,    49,
      50,     0,   577,    51,     0,    52,    53,     0,     0,    54,
    -256,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,    59,    60,     0,    61,    62,     0,    63,    64,    65,
       0,    66,     0,    67,    68,     0,    69,    70,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,     0,     0,     0,    78,    79,    80,     0,    81,    82,
      83,    84,  1265,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     0,     0,  1265,
       0,    94,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   232,     0,   233,   234,   235,   236,   237,     0,   238,
     239,     0,     0,  -256,     0,   240,     0,   241,     0,     0,
     531,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    28,   244,   245,     0,   246,    30,     0,     0,     0,
       0,     0,     0,     0,   247,    32,    33,    34,     0,   248,
     249,    35,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,     0,     0,     0,    37,
       0,    38,     0,    39,     0,    40,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,   355,   250,   251,    52,    53,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,    59,    60,     0,    61,    62,     0,    63,    64,    65,
       5,    66,     0,    67,    68,     0,    69,    70,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,     0,     0,     7,    78,    79,    80,     0,    81,    82,
      83,    84,     0,     0,     0,     0,   252,   253,    85,    86,
      87,    88,   254,   255,   256,   257,    93,     0,     0,     0,
       0,   258,     0,     0,     0,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     160,   308,     0,     0,     0,     0,     0,   309,     0,     0,
     310,   311,   312,   232,     0,   233,   234,   235,   236,   237,
       0,   238,   239,     0,     0,     0,     0,   240,     0,   241,
       0,     0,   557,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    28,   244,   245,     0,   246,    30,     0,
       0,     0,     0,     0,     0,     0,   247,    32,    33,    34,
       0,   248,   249,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   383,     0,     0,
       0,    37,     0,    38,     0,    39,     0,    40,     0,     0,
       0,     0,    41,    42,     0,    43,    44,    45,    46,    47,
      48,    49,    50,     0,   384,   250,   251,    52,    53,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,    59,    60,     0,    61,    62,     0,    63,
      64,    65,     5,    66,     0,    67,    68,     0,    69,    70,
      71,    72,     0,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,     0,     7,    78,    79,    80,     0,
      81,    82,    83,    84,     0,     0,     0,     0,   252,   253,
      85,    86,    87,    88,   254,   255,   256,   257,    93,     0,
       0,     0,     0,   258,     0,     0,     0,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   160,   308,     0,     0,     0,     0,     0,   309,
       0,     0,   310,   311,   312,   232,     0,   233,   234,   235,
     236,   237,     0,   238,   239,     0,     0,     0,     0,   240,
       0,   241,     0,     0,   382,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    28,   244,   245,     0,   246,
      30,     0,     0,     0,     0,     0,     0,     0,   247,    32,
      33,    34,     0,   248,   249,    35,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
       0,     0,     0,    37,     0,    38,     0,    39,     0,    40,
       0,     0,     0,     0,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,     0,   384,   250,   251,    52,
      53,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,    59,    60,     0,    61,    62,
       0,    63,    64,    65,     0,    66,     0,    67,    68,     0,
      69,    70,    71,    72,     0,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,     0,     0,    78,    79,
      80,     0,    81,    82,    83,    84,     0,     0,     0,     0,
     252,   253,    85,    86,    87,    88,   254,   255,   256,   257,
      93,     0,     0,     0,     0,   258,     0,     0,     0,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   160,   308,     0,     0,     0,     0,
     385,   309,     0,     0,   310,   311,   312,   232,     0,   233,
     234,   235,   236,   237,     0,   238,   239,     0,     0,     0,
       0,   240,     0,   241,     0,     0,   242,     0,     0,   748,
       0,     0,     0,     0,    27,     0,     0,    28,   244,   245,
       0,   246,    30,     0,     0,     0,     0,     0,     0,     0,
     247,    32,    33,    34,     0,   248,   249,    35,     0,     0,
       0,    36,     0,   749,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    38,     0,    39,
       0,    40,     0,     0,     0,     0,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,   250,
     251,    52,    53,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,    59,    60,     0,
      61,    62,     0,    63,    64,    65,     0,    66,     0,    67,
      68,     0,    69,    70,    71,    72,     0,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,     0,     0,
      78,    79,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,   252,   253,    85,    86,    87,    88,   254,   255,
     256,   257,    93,     0,     0,     0,     0,   258,     0,     0,
       0,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   160,   308,     0,     0,
       0,     0,   750,   309,     0,     0,   310,   311,   312,   232,
       0,   233,   234,   235,   236,   237,     0,   238,   239,     0,
       0,     0,     0,   240,     0,   241,     0,     0,   425,  1294,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
     244,   245,     0,   246,    30,     0,     0,     0,     0,     0,
       0,     0,   247,    32,    33,    34,     0,   248,   249,    35,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    38,
       0,    39,     0,    40,     0,     0,     0,     0,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,   250,   251,    52,    53,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,    59,
      60,     0,    61,    62,     0,    63,    64,    65,     5,    66,
       0,    67,    68,     0,    69,    70,    71,    72,     0,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,     0,
       0,     7,    78,    79,    80,     0,    81,    82,    83,    84,
       0,     0,     0,     0,   252,   253,    85,    86,    87,    88,
     254,   255,   256,   257,    93,     0,     0,     0,     0,   258,
       0,     0,     0,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   160,   308,
       0,     0,     0,     0,     0,   309,     0,     0,   310,   311,
     312,   232,     0,   233,   234,   235,   236,   237,     0,   238,
     239,     0,     0,     0,     0,   240,     0,   241,     0,     0,
     353,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    28,   244,   245,     0,   246,    30,     0,     0,     0,
       0,     0,     0,     0,   247,    32,    33,    34,     0,   248,
     249,    35,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   354,     0,     0,     0,    37,
       0,    38,     0,    39,     0,    40,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,   355,   250,   251,    52,    53,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,    59,    60,     0,    61,    62,     0,    63,    64,    65,
       0,    66,     0,    67,    68,     0,    69,    70,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,     0,     0,     0,    78,    79,    80,     0,    81,    82,
      83,    84,     0,     0,     0,     0,   252,   253,    85,    86,
      87,    88,   254,   255,   256,   257,    93,     0,     0,     0,
       0,   258,     0,     0,     0,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     160,   308,     0,     0,     0,     0,     0,   309,     0,     0,
     310,   311,   312,   232,     0,   233,   234,   235,   236,   237,
       0,   238,   239,     0,     0,     0,     0,   240,     0,   241,
       0,     0,   425,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    28,   244,   245,     0,   246,    30,     0,
       0,     0,     0,     0,     0,     0,   247,    32,    33,    34,
       0,   248,   249,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    38,     0,    39,     0,    40,     0,     0,
       0,     0,    41,    42,     0,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,   250,   251,    52,    53,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,    59,    60,     0,    61,    62,     0,    63,
      64,    65,     5,    66,     0,    67,    68,     0,    69,    70,
      71,    72,     0,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,     0,     7,    78,    79,    80,     0,
      81,    82,    83,    84,     0,     0,     0,     0,   252,   253,
      85,    86,    87,    88,   254,   255,   256,   257,    93,     0,
       0,     0,     0,   258,     0,     0,     0,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   160,   308,     0,     0,     0,     0,     0,   309,
       0,     0,   310,   311,   312,   232,     0,   233,   234,   235,
     236,   237,     0,   238,   239,     0,     0,     0,     0,   240,
       0,   241,     0,     0,   561,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    28,   244,   245,     0,   246,
      30,     0,     0,     0,     0,     0,     0,     0,   247,    32,
      33,    34,     0,   248,   249,    35,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
       0,     0,     0,    37,     0,    38,     0,    39,     0,    40,
       0,     0,     0,     0,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,     0,   384,   250,   251,    52,
      53,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,    59,    60,     0,    61,    62,
       0,    63,    64,    65,     0,    66,     0,    67,    68,     0,
      69,    70,    71,    72,     0,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,     0,     0,    78,    79,
      80,     0,    81,    82,    83,    84,     0,     0,     0,     0,
     252,   253,    85,    86,    87,    88,   254,   255,   256,   257,
      93,     0,     0,     0,     0,   258,     0,     0,     0,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   160,   308,     0,     0,     0,     0,
       0,   309,     0,     0,   310,   311,   312,   232,     0,   233,
     234,   235,   236,   237,     0,   238,   239,     0,     0,     0,
       0,   240,     0,   241,     0,     0,   382,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    28,   244,   245,
       0,   246,    30,     0,     0,     0,     0,     0,     0,     0,
     247,    32,    33,    34,     0,   248,   249,    35,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   383,     0,     0,     0,    37,     0,    38,     0,    39,
       0,    40,     0,     0,     0,     0,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,     0,   384,   250,
     251,    52,    53,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,    59,    60,     0,
      61,    62,     0,    63,    64,    65,     0,    66,     0,    67,
      68,     0,    69,    70,    71,    72,     0,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,     0,     0,
      78,    79,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,   252,   253,    85,    86,    87,    88,   254,   255,
     256,   257,    93,     0,     0,     0,     0,   258,     0,     0,
       0,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   160,   308,     0,     0,
       0,     0,     0,   309,     0,     0,   310,   311,   312,   232,
       0,   233,   234,   235,   236,   237,     0,   238,   239,     0,
       0,     0,     0,   240,     0,   241,     0,     0,   242,   243,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
     244,   245,     0,   246,    30,     0,     0,     0,     0,     0,
       0,     0,   247,    32,    33,    34,     0,   248,   249,    35,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    38,
       0,    39,     0,    40,     0,     0,     0,     0,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,   250,   251,    52,    53,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,    59,
      60,     0,    61,    62,     0,    63,    64,    65,     0,    66,
       0,    67,    68,     0,    69,    70,    71,    72,     0,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,     0,
       0,     0,    78,    79,    80,     0,    81,    82,    83,    84,
       0,     0,     0,     0,   252,   253,    85,    86,    87,    88,
     254,   255,   256,   257,    93,     0,     0,     0,     0,   258,
       0,     0,     0,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   160,   308,
       0,     0,     0,     0,     0,   309,     0,     0,   310,   311,
     312,   232,     0,   233,   234,   235,   236,   237,     0,   238,
     239,     0,     0,     0,     0,   240,     0,   241,     0,     0,
     242,   592,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    28,   244,   245,     0,   246,    30,     0,     0,     0,
       0,     0,     0,     0,   247,    32,    33,    34,     0,   248,
     249,    35,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,     0,    39,     0,    40,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,     0,   250,   251,    52,    53,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,    59,    60,     0,    61,    62,     0,    63,    64,    65,
       0,    66,     0,    67,    68,     0,    69,    70,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,     0,     0,     0,    78,    79,    80,     0,    81,    82,
      83,    84,     0,     0,     0,     0,   252,   253,    85,    86,
      87,    88,   254,   255,   256,   257,    93,     0,     0,     0,
       0,   258,     0,     0,     0,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     160,   308,     0,     0,     0,     0,     0,   309,     0,     0,
     310,   311,   312,   232,     0,   233,   234,   235,   236,   237,
       0,   238,   239,     0,     0,     0,     0,   240,     0,   241,
       0,     0,   242,   740,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    28,   244,   245,     0,   246,    30,     0,
       0,     0,     0,     0,     0,     0,   247,    32,    33,    34,
       0,   248,   249,    35,     0,     0,     0,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    38,     0,    39,     0,    40,     0,     0,
       0,     0,    41,    42,     0,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,   250,   251,    52,    53,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,    59,    60,     0,    61,    62,     0,    63,
      64,    65,     0,    66,     0,    67,    68,     0,    69,    70,
      71,    72,     0,    73,     0,     0,     0,     0,     0,    74,
      75,    76,    77,     0,     0,     0,    78,    79,    80,     0,
      81,    82,    83,    84,     0,     0,     0,     0,   252,   253,
      85,    86,    87,    88,   254,   255,   256,   257,    93,     0,
       0,     0,     0,   258,     0,     0,     0,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   160,   308,     0,     0,     0,     0,     0,   309,
       0,     0,   310,   311,   312,   232,     0,   233,   234,   235,
     236,   237,     0,   238,   239,     0,     0,     0,     0,   240,
       0,   241,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    28,   244,   245,     0,   246,
      30,     0,     0,     0,     0,     0,     0,     0,   247,    32,
      33,    34,     0,   248,   249,    35,     0,     0,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    38,     0,    39,     0,    40,
       0,     0,     0,     0,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,     0,     0,   250,   251,    52,
      53,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,    59,    60,     0,    61,    62,
       0,    63,    64,    65,     0,    66,     0,    67,    68,     0,
      69,    70,    71,    72,     0,    73,     0,     0,     0,     0,
       0,    74,    75,    76,    77,     0,     0,     0,    78,    79,
      80,     0,    81,    82,    83,    84,     0,     0,     0,     0,
     252,   253,    85,    86,    87,    88,   254,   255,   256,   257,
      93,     0,     0,     0,     0,   258,     0,     0,     0,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   160,   308,     0,     0,     0,     0,
       0,   309,     0,     0,   310,   311,   312,   232,     0,   233,
     234,   235,   236,   237,     0,   238,   239,     0,     0,     0,
       0,   240,     0,   241,     0,     0,   561,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,    28,   244,   245,
       0,   246,    30,     0,     0,     0,     0,     0,     0,     0,
     247,    32,    33,    34,     0,   248,   249,    35,     0,     0,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    38,     0,    39,
       0,    40,     0,     0,     0,     0,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,   250,
     251,    52,    53,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,    59,    60,     0,
      61,    62,     0,    63,    64,    65,     0,    66,     0,    67,
      68,     0,    69,    70,    71,    72,     0,    73,     0,     0,
       0,     0,     0,    74,    75,    76,    77,     0,     0,     0,
      78,    79,    80,     0,    81,    82,    83,    84,     0,     0,
       0,     0,   252,   253,    85,    86,    87,    88,   254,   255,
     256,   257,    93,     0,     0,     0,     0,   258,     0,     0,
       0,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   160,   308,     0,     0,
       0,     0,     0,   309,     0,     0,   310,   311,   312,   232,
       0,   233,   234,   235,   236,   237,     0,   238,   239,     0,
       0,     0,     0,   240,     0,   241,     0,     0,  1261,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
     244,   245,     0,   246,    30,     0,     0,     0,     0,     0,
       0,     0,   247,    32,    33,    34,     0,   248,   249,    35,
       0,     0,     0,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,  1262,
       0,    39,     0,    40,     0,     0,     0,     0,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,   250,   251,    52,    53,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,    59,
      60,     0,    61,    62,     0,    63,    64,    65,     0,    66,
       0,    67,    68,     0,    69,    70,    71,    72,     0,    73,
       0,     0,     0,     0,     0,    74,    75,    76,    77,     0,
       0,     0,    78,    79,    80,     0,    81,    82,    83,    84,
       0,     0,     0,     0,   252,   253,    85,    86,    87,    88,
     254,   255,   256,   257,    93,     0,     0,     0,     0,   258,
       0,     0,     0,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   160,   308,
      26,     0,     0,     0,     0,   309,     0,     0,   310,   311,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1087,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,     0,     0,     0,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      38,     0,    39,     0,    40,     0,     0,     0,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,     0,    52,    53,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
      59,    60,     0,    61,    62,     0,    63,    64,    65,     0,
      66,     0,    67,    68,     0,    69,    70,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,     0,     0,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,     0,  1088,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     232,     0,     0,     0,     0,     0,   309,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,     0,     0,     0,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      38,     0,    39,     0,    40,     0,     0,     0,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,     0,    52,    53,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
      59,    60,     0,    61,    62,     0,    63,    64,    65,     0,
      66,     0,    67,    68,     0,    69,    70,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,     0,     0,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     232,     0,     0,     0,     0,   829,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,     0,     0,     0,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      38,     0,    39,     0,    40,     0,     0,     0,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,     0,    52,    53,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
      59,    60,     0,    61,    62,     0,    63,    64,    65,     0,
      66,     0,    67,    68,     0,    69,    70,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,     0,     0,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      26,     0,     0,     0,     0,  1117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,     0,     0,     0,    29,    30,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      38,     0,    39,     0,    40,     0,     0,     0,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,    51,     0,    52,    53,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
      59,    60,     0,    61,    62,     0,    63,    64,    65,     0,
      66,     0,    67,    68,     0,    69,    70,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,     0,     0,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
      94,     0,     0,     0,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     232,     0,  1310,     0,     0,  1269,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     0,   241,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,     0,   245,     0,   246,    30,     0,     0,     0,     0,
       0,     0,     0,   247,    32,    33,    34,     0,   248,   249,
      35,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
      38,     0,    39,     0,    40,     0,     0,     0,     0,    41,
      42,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,   250,     0,    52,    53,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
      59,    60,     0,    61,    62,     0,    63,    64,    65,     0,
      66,     0,    67,    68,     0,    69,    70,    71,    72,     0,
      73,     0,     0,     0,     0,     0,    74,    75,    76,    77,
       0,     0,     0,    78,    79,    80,     0,    81,    82,    83,
      84,     0,     0,     0,     0,   709,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,     0,
     258,     0,     0,     0,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   160,
     308,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
       0,    28,     0,   245,     0,   246,    30,     0,     0,     0,
       0,     0,     0,     0,   247,    32,    33,    34,     0,   248,
     249,    35,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,     0,    39,     0,    40,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,     0,   250,     0,    52,    53,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,    59,    60,     0,    61,    62,     0,    63,    64,    65,
       0,    66,     0,    67,    68,     0,    69,    70,    71,    72,
       0,    73,     0,     0,     0,     0,     0,    74,    75,    76,
      77,     0,     0,     0,    78,    79,    80,     0,    81,    82,
      83,    84,     0,     0,     0,     0,   709,     0,    85,    86,
      87,    88,    89,    90,   710,   711,    93,     0,     0,     0,
       0,   258,     0,     0,     0,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     160,   308,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   948,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     5,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     7,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,   791,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     5,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     7,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,   616,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,   617,   618,   637,
     638,   639,   640,   641,   642,   643,   644,   645,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,    27,
       0,     0,    28,     0,     0,   509,    29,    30,   510,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   790,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,   791,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,   175,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,   181,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   350,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   758,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,   254,   255,   256,   257,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1073,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,   697,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,   703,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    28,     0,     0,     0,    29,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    38,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,    51,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,    59,    60,     0,    61,    62,     0,    63,    64,
      65,     0,    66,     0,    67,    68,     0,    69,    70,    71,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
      76,    77,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,    94,     0,     0,     0,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,  1233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    39,     0,    40,     0,     0,     0,
       0,    41,    42,     0,    43,     0,     0,    46,    47,    48,
      49,    50,     0,     0,     0,     0,    52,    53,     0,     0,
      54,     0,     0,    55,     0,     0,     0,     0,     0,    57,
       0,     0,    59,    60,     0,    61,    62,     0,     0,    64,
      65,     0,    66,     0,    67,    68,     0,     0,     0,     0,
      72,     0,    73,     0,     0,     0,     0,     0,    74,    75,
       0,     0,     0,     0,     0,    78,    79,    80,     0,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,    91,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
       2,     3,     4,   210,     6,     7,   392,   393,   184,   252,
     441,   951,   200,   231,   899,     1,   191,   527,   437,     2,
       3,     4,    42,     6,   894,   652,   912,   195,   480,   481,
     482,   483,   484,   485,   486,   487,   448,   449,   450,   451,
     452,   199,   576,   455,   477,   478,   479,   901,   901,   461,
      42,    23,   901,    22,   896,   867,    22,   584,   912,   912,
     872,   873,    23,   912,    23,   354,     2,     3,     4,   901,
       6,     7,   473,   474,   475,    44,   908,   587,   102,    33,
     912,   355,    23,    23,    23,    23,   505,    36,   181,   382,
      39,    25,   956,    27,   383,    13,    14,    15,    16,    17,
      18,    19,   309,   481,   482,   483,   484,   485,   486,   487,
      68,    23,    31,   790,    42,    36,    23,    36,    39,    31,
      39,    65,   411,    26,    36,   753,   219,    39,    42,   412,
      40,    41,    42,    43,    44,    45,    23,    40,    41,    42,
      43,    44,    45,    26,    26,    42,   310,   311,   312,    42,
      42,   109,     0,   790,     0,    36,   122,    76,    39,    22,
      36,   102,    36,    39,    76,    39,    62,    42,   881,    42,
     172,    81,   174,   175,    84,    94,    44,    36,    81,   181,
      39,    84,    94,   185,   171,   172,     2,     3,     4,   172,
       6,     7,   175,   127,    23,   102,   198,  1009,    36,   102,
     202,    39,   185,   384,    36,    36,   208,    39,    39,   225,
     154,   227,    20,    36,   216,   102,    39,   219,   220,   102,
     102,   504,   208,   247,   431,   174,   175,   247,  1092,   244,
     649,   438,    20,  1097,     3,   384,   172,  1101,   174,   175,
     868,    36,   870,   770,    39,   181,   874,    23,   875,   185,
     784,    36,   879,    22,    39,   247,   242,    36,    36,   122,
      39,    39,   198,   552,   557,   539,   202,  1153,   561,   256,
     257,   948,   208,   102,   462,   247,    78,   811,   466,   467,
     249,   456,   145,   219,   220,   460,   247,   576,   247,  1174,
     465,  1145,   100,   468,   469,   470,  1150,   824,   247,  1153,
    1153,   508,   930,   931,  1153,  1175,  1148,   247,   247,   247,
     498,   948,   100,    36,   489,   490,    39,    69,  1150,   247,
     384,  1153,    36,    22,  1156,    39,   247,  1159,   247,   247,
     176,  1163,  1196,   247,    33,   247,    40,    41,    42,    43,
      44,    45,   188,  1056,  1057,   255,   252,   253,   350,   556,
     247,    22,   255,  1293,   247,   247,   172,    56,   174,   175,
     524,   207,    50,   991,   992,   181,   247,   353,   214,   185,
     997,   247,   247,   247,   247,  1002,  1003,    81,    77,    23,
      84,   249,   198,    25,    72,   387,   202,    22,   247,   144,
     392,   393,   208,   145,   904,   571,   382,    24,   159,   580,
     581,   582,   583,   219,   220,    93,   792,    68,   169,   247,
     568,   797,   798,    22,   350,   247,   247,    59,    28,   607,
    1133,  1134,  1135,   122,   247,   935,   857,   634,   847,   124,
     588,   580,   581,   582,   583,    44,     6,  1296,   137,   425,
     442,   248,   111,   650,  1072,   133,   145,   247,   109,   118,
     436,   258,   247,    23,  1313,   907,   392,   393,   102,   911,
     174,   175,   247,   882,    65,   975,   709,   900,   247,   247,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   122,    22,   491,
     492,   493,   494,   495,   895,   784,    59,  1309,  1126,   667,
    1128,    36,   103,   138,    39,    32,   442,  1319,   510,  1136,
     145,   149,     7,  1140,     9,    10,   580,   581,   582,   583,
     102,    40,   811,    42,   247,   527,   528,   510,   530,   907,
    1342,   138,    53,   911,   350,   136,   472,   473,   474,   475,
     476,   477,   478,   479,    31,   531,   245,   957,    59,   959,
     132,   255,   488,   555,    75,   491,   492,   493,   494,   495,
     174,   175,  1275,    36,  1277,   567,    39,    88,   103,    22,
      75,   557,    31,   780,   510,   561,   392,   393,    28,    36,
      53,  1209,    39,    88,    22,   587,  1214,  1215,    22,    76,
      36,   527,   528,    39,   530,    36,    53,    84,    39,    94,
     121,     7,    75,     9,    10,  1318,    22,     5,     6,     7,
       8,     9,    53,    11,    12,    88,   121,    76,     6,   555,
      22,    20,    23,    11,    12,    84,   442,    23,    22,   580,
      22,   567,   583,    90,    75,    36,     5,    36,    39,    36,
      39,    22,    39,  1271,  1272,  1155,    22,    88,   121,    90,
       5,   587,    50,     5,    22,     5,   472,   473,   474,   475,
     476,   477,   478,   479,    29,   883,    63,    53,     5,    65,
      36,    36,   488,    39,    39,   491,   492,   493,   494,   495,
     121,    22,    78,    36,   205,   206,    39,    55,    94,    75,
     147,    23,    23,    58,   510,    22,    36,    63,    96,    39,
     205,   206,    88,    26,    90,    36,   147,   103,    39,    22,
      63,   527,   528,    36,   530,  1127,    39,  1129,     5,     6,
       7,     8,     9,    63,    11,    12,   914,    36,    26,    22,
      39,    40,   205,   206,    23,   121,    96,   135,    36,   555,
     136,    39,   199,   200,    31,   906,    22,    36,   909,   910,
      39,   567,    31,   149,   122,   757,   758,    36,   199,   200,
      39,   147,    26,    50,   205,   206,   164,   165,   166,   167,
     138,   587,    36,    23,    22,    39,    22,   145,     5,     6,
       7,     8,     9,    28,    11,    12,    36,     6,   790,    39,
     792,    36,    11,    12,    39,   797,   798,    76,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    96,
      23,    23,  1198,   199,   200,    94,    22,   203,   204,   205,
     206,   757,   758,    36,    36,    22,    39,    39,   156,   157,
      22,     2,     3,     4,    22,     6,     7,  1005,    31,    23,
      26,  1293,  1010,    36,    23,    22,    39,   849,   135,    22,
      36,    23,    36,    39,   790,    39,   792,    36,   860,    23,
      39,   797,   798,    28,    36,    22,   849,    39,    23,    96,
      22,    36,    36,    22,    39,    39,    22,   164,   165,   166,
     167,    36,    22,    76,    39,    14,    15,    16,    17,   891,
      19,   419,   420,   895,   150,   151,   152,   153,   900,    22,
      22,    94,   904,    22,     7,   907,     9,    10,    22,   911,
      22,    22,    22,   849,  1132,   580,   581,   582,   583,  1137,
    1108,    22,    22,    22,   860,    22,    22,    22,    22,    22,
      22,   933,  1107,   935,    22,    22,   938,   164,   165,   166,
     167,   757,   758,    22,    22,    22,   948,    22,    22,   951,
      22,    22,    22,    22,   956,   891,    22,    22,   960,   895,
      22,    22,   948,    22,   900,    22,   968,   247,   904,    22,
      28,   249,    22,   975,   790,    22,   792,   251,    24,    22,
      24,   797,   798,   207,   208,   209,   210,   211,   212,   213,
      13,    14,    15,    16,    17,    18,    19,   933,   102,   935,
      22,   172,   938,   174,   175,  1193,    26,    23,   247,   247,
     181,   102,   948,    26,   185,   951,  1192,    24,    70,   247,
     956,   247,   150,    23,   960,    23,    23,   198,    23,   249,
     143,   202,   968,   849,    22,   250,    23,   208,    24,   975,
      22,    40,    23,    22,   860,   154,    40,   246,   219,   220,
      23,    23,  1220,   155,    60,    23,    23,   247,  1276,    44,
      44,   250,    42,    53,    23,    42,   247,   247,    23,    23,
      22,  1073,     5,   247,    70,   891,     5,   247,   247,   895,
     247,  1257,  1289,  1251,   900,    75,   247,   247,   904,   247,
    1092,   247,    22,     5,     5,  1097,    24,   247,    88,  1101,
      90,    22,   247,   247,   247,   247,   247,    22,   247,   247,
     247,   247,   247,   247,   247,    22,    22,   933,    23,   935,
      23,    23,   938,   106,    24,    24,    23,    22,    72,   246,
      26,   121,   948,    24,    61,   951,    23,  1073,   155,    23,
     956,   155,   250,    23,   960,     6,     6,    79,    79,     5,
       5,     5,   968,    79,     5,     5,  1092,   147,     6,   975,
       6,  1097,     6,     6,    23,  1101,    23,    16,   105,    16,
     145,   247,     6,   197,   164,   165,   200,   167,    23,   350,
      32,    74,    23,  1185,    23,   103,    23,    23,  1190,     6,
      23,    23,   216,   217,  1196,   214,  1198,    23,   247,    23,
      23,    23,   226,    23,    23,   247,  1208,   247,    24,   199,
     200,   201,   202,   203,   204,   205,   206,    23,    23,    23,
     244,   392,   393,    23,    23,    23,   247,    23,    23,   247,
      23,    23,    23,    23,    16,    24,    23,    23,   242,    24,
     150,   176,   167,    24,    23,    23,    23,    23,    23,  1185,
       5,     5,    23,     3,  1190,    28,    23,  1073,   250,   250,
    1196,   250,  1198,    23,    23,   107,    23,    23,    32,   148,
      23,   442,  1208,    24,   250,  1261,  1092,    23,    23,    23,
      23,  1097,    23,    23,    23,  1101,    99,   125,     5,  1291,
     247,    28,    22,    26,   247,    23,   117,   109,   109,    23,
      66,   472,   473,   474,   475,   476,   477,   478,   479,   117,
     104,   188,   185,   207,     6,    24,   214,   488,   589,   594,
     491,   492,   493,   494,   495,   407,   230,   387,  1111,   353,
     555,   355,   573,   963,   960,  1197,   958,   538,   520,   510,
     523,   517,   582,   511,   586,   857,   583,   860,   618,   951,
     617,   891,   609,   398,  1297,  1291,  1073,   528,   382,   530,
     384,  1309,  1342,   387,   968,  1298,  1163,   202,    -1,  1185,
      -1,    -1,    -1,    -1,  1190,    -1,    -1,    -1,    -1,    -1,
    1196,    -1,  1198,    -1,   555,    -1,    -1,    -1,   412,    -1,
      -1,    -1,  1208,    -1,    -1,    -1,   567,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,   432,    -1,
     434,    -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,
      -1,    -1,    -1,    -1,   448,   449,   450,   451,   452,   453,
     454,   455,    -1,   457,   458,   459,    -1,   461,   462,   463,
     464,    -1,   466,   467,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   496,   497,   498,  1291,    -1,    -1,    -1,    -1,
     504,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   525,    -1,    -1,    -1,    -1,    -1,   531,    -1,    -1,
      -1,    -1,    -1,    -1,   538,   539,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   547,    -1,    -1,   550,   551,    -1,    -1,
      -1,    -1,    -1,   557,    -1,    -1,    -1,   561,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   575,    -1,    -1,    -1,    -1,   580,   581,   582,   583,
      -1,   585,   586,    -1,    -1,   589,   590,    -1,    -1,    -1,
     594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   607,    -1,    -1,   757,   758,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,
      -1,   792,    -1,    -1,    -1,    -1,   797,   798,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   659,    -1,    -1,    -1,   663,
      -1,    -1,    -1,    -1,   668,    -1,    -1,   671,   672,   673,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   849,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   860,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   723,
     724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     891,    -1,    -1,    -1,   895,    -1,    -1,    -1,   752,   900,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   783,
      -1,   785,   933,    -1,    -1,    -1,    -1,   938,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   948,    -1,    -1,
     951,    -1,   806,    -1,    -1,   956,   810,    -1,   812,   960,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     844,    -1,    -1,    -1,    -1,    -1,    -1,   851,    -1,    -1,
      -1,    -1,    -1,   857,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   876,   877,   878,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   922,   923,
     924,    -1,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   941,   942,    -1,
      -1,  1092,    -1,    -1,    -1,    -1,  1097,    -1,    -1,    -1,
    1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,
     974,    -1,    -1,    -1,    -1,   979,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1031,    -1,    -1,
      -1,    -1,  1036,    -1,  1185,    -1,    -1,    -1,    -1,  1190,
      -1,    -1,  1046,    -1,    -1,  1196,    -1,  1198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1083,
    1084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1108,    -1,    -1,  1111,    -1,    -1,
    1114,  1115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1127,    -1,  1129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1291,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,    31,
      -1,    33,  1176,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,  1193,
      -1,    53,    -1,    -1,    -1,    57,  1200,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    76,    77,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    -1,    97,    98,    -1,    -1,   101,
     102,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
      -1,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,   153,  1296,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,  1313,
      -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,   255,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,    -1,   145,   146,   147,   148,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
     252,   253,   254,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,   119,
     120,   121,   122,   123,    -1,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,    -1,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,   253,   254,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    73,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,   119,   120,   121,    -1,   123,    -1,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
     248,   249,    -1,    -1,   252,   253,   254,     3,    -1,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,    -1,   108,    -1,   110,    -1,   112,   113,   114,    -1,
     116,   117,    -1,   119,   120,   121,    -1,   123,    -1,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,   248,   249,    -1,    -1,   252,   253,   254,     3,
      -1,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    51,    52,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,
      -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,   119,   120,   121,   122,   123,
      -1,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,
      -1,   145,   146,   147,   148,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,   253,
     254,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
      -1,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
     252,   253,   254,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,   119,
     120,   121,   122,   123,    -1,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,    -1,    -1,   145,   146,   147,   148,    -1,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,   253,   254,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      -1,    -1,    -1,    71,    -1,    73,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,   119,   120,   121,    -1,   123,    -1,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,   252,   253,   254,     3,    -1,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,    -1,   108,    -1,   110,    -1,   112,   113,   114,    -1,
     116,   117,    -1,   119,   120,   121,    -1,   123,    -1,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,   253,   254,     3,
      -1,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    51,    52,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,
      -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,   119,   120,   121,    -1,   123,
      -1,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,   253,
     254,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    96,    97,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
      -1,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
     252,   253,   254,     3,    -1,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    96,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,
     110,    -1,   112,   113,   114,    -1,   116,   117,    -1,   119,
     120,   121,    -1,   123,    -1,   125,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,   253,   254,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    17,
      -1,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    -1,    51,    52,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,    73,    -1,    75,    -1,    77,
      -1,    -1,    -1,    -1,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    96,    97,
      98,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,
     108,    -1,   110,    -1,   112,   113,   114,    -1,   116,   117,
      -1,   119,   120,   121,    -1,   123,    -1,   125,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,    -1,    -1,    -1,    -1,   173,    -1,    -1,    -1,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,   252,   253,   254,     3,    -1,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    17,    -1,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    73,    -1,    75,
      -1,    77,    -1,    -1,    -1,    -1,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,    -1,   108,    -1,   110,    -1,   112,   113,   114,    -1,
     116,   117,    -1,   119,   120,   121,    -1,   123,    -1,   125,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,   253,   254,     3,
      -1,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    -1,    51,    52,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    73,
      -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,    83,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    96,    97,    98,    -1,    -1,   101,    -1,    -1,
     104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,   113,
     114,    -1,   116,   117,    -1,   119,   120,   121,    -1,   123,
      -1,   125,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,   173,
      -1,    -1,    -1,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       3,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,   253,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,    -1,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       3,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,    -1,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       3,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,    -1,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       3,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    -1,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,    -1,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       3,    -1,     5,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    -1,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    -1,    51,    52,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    82,
      83,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,   112,
     113,   114,    -1,   116,   117,    -1,   119,   120,   121,    -1,
     123,    -1,   125,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
     173,    -1,    -1,    -1,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,    51,
      52,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,   101,
      -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,    -1,
     112,   113,   114,    -1,   116,   117,    -1,   119,   120,   121,
      -1,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,   122,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,   145,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,   122,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,   145,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    96,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    33,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    80,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,   115,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    73,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,   108,    -1,   110,
      -1,   112,   113,   114,    -1,   116,   117,    -1,   119,   120,
     121,    -1,   123,    -1,   125,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,   173,    -1,    -1,    -1,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    -1,    -1,    88,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,   113,   114,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,   123,    -1,   125,   126,    -1,    -1,    -1,    -1,
     131,    -1,   133,    -1,    -1,    -1,    -1,    -1,   139,   140,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    22,    33,    56,    77,   122,   137,   145,   245,   260,
     261,   262,   263,   268,   269,   270,   273,   274,   278,   281,
     282,   283,   284,   290,   304,   281,     3,    30,    33,    37,
      38,    46,    47,    48,    49,    53,    57,    71,    73,    75,
      77,    82,    83,    85,    86,    87,    88,    89,    90,    91,
      92,    95,    97,    98,   101,   104,   108,   110,   112,   113,
     114,   116,   117,   119,   120,   121,   123,   125,   126,   128,
     129,   130,   131,   133,   139,   140,   141,   142,   146,   147,
     148,   150,   151,   152,   153,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   173,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   267,   331,   404,   406,   424,   437,   439,   440,   441,
     442,   443,    70,   275,   331,    80,   331,    25,    59,   310,
     275,   115,   305,   306,   437,    33,     0,    62,   244,    65,
     103,   136,   297,   298,    78,   282,    23,    22,    24,   331,
     144,   292,    28,   433,   434,   435,   437,   331,    22,    55,
     138,   271,   272,   278,   308,    28,   291,   124,   305,   247,
      22,   307,   308,   267,   261,    59,    32,   310,   149,   279,
      59,   297,     3,     5,     6,     7,     8,     9,    11,    12,
      17,    19,    22,    23,    34,    35,    37,    46,    51,    52,
      95,    96,   158,   159,   164,   165,   166,   167,   173,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   243,   249,
     252,   253,   254,   264,   265,   266,   285,   287,   289,   328,
     329,   332,   355,   356,   357,   358,   359,   360,   361,   378,
     383,   394,   395,   396,   397,   402,   403,   404,   405,   406,
     423,   425,   437,   438,   439,   444,   468,   469,   470,   471,
      24,   437,   292,    22,    67,    94,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   435,   271,   309,   437,   138,   355,   385,   272,   278,
     159,   169,    22,    67,    94,   248,   311,   312,   313,   314,
     315,   316,   355,   362,   363,   365,   367,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   437,   276,   277,   355,
     305,    28,    22,   283,   299,   300,   355,   283,     6,    11,
      12,   284,   279,    22,    22,    22,   281,   385,   355,   398,
      22,    22,    22,    22,    22,     5,    22,    44,   249,   287,
     384,    22,    44,   380,     5,     5,     5,     5,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,   385,
     360,   360,   360,    23,   247,    28,   249,   330,    22,    36,
      39,   389,   436,   171,   172,   256,   257,   391,   252,   253,
     392,   248,   258,   393,   251,    22,    22,    24,    24,   437,
      24,    22,   341,   355,    22,   286,   288,   343,   102,    26,
      40,    41,    42,    43,    44,    45,    81,    84,   255,   388,
     390,    31,    76,    94,    23,   247,   247,    22,   355,   362,
     288,    22,   355,   367,   368,   369,   371,    70,   293,   311,
     247,    65,   154,   317,   318,    31,    76,    94,   433,   433,
     102,    26,    26,   102,    81,    84,   390,    24,   293,   247,
      40,   288,    23,   264,   247,    29,    58,   301,   150,   280,
     280,   280,    23,    23,   281,    23,    23,   143,   399,   400,
     355,   385,   355,     6,    23,   355,    96,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   426,   427,
     428,   429,   430,   385,   249,   314,   379,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   381,   382,   426,   437,
      22,   266,   266,   266,   266,   266,   355,   355,   266,   310,
     355,   355,   355,   310,   266,   341,   355,   355,   310,   341,
     341,   310,   310,   310,    53,    75,    88,    90,   121,   147,
     164,   165,   167,   199,   200,   201,   202,   203,   204,   205,
     206,   450,   453,   454,   455,   456,   458,   165,   437,   460,
     460,   460,   460,   164,   437,   461,   461,   461,   461,   158,
     166,   167,   402,   437,   462,   462,   462,   462,   462,   462,
     462,   462,   437,   310,   310,   437,   437,   437,   437,   437,
     355,   355,   341,   250,   264,   426,   150,   151,   152,   153,
      23,   385,   331,   356,   357,   358,   359,   360,    25,    59,
     248,   355,   431,    23,   437,   438,   437,    24,    24,   437,
      23,   278,   342,   343,    40,    40,    42,     7,     9,    10,
      94,   387,   355,    40,    25,    27,   127,   432,   355,   355,
      22,   288,   386,    31,    76,    84,   309,   385,    23,   362,
      22,   170,   288,   321,   322,   323,   324,   327,   331,   333,
     334,   336,   337,   338,   292,   308,    22,   318,   355,   386,
      31,    76,    84,   363,   364,   365,   367,   369,   365,   366,
     367,   369,   366,   364,    94,   387,   355,   355,   370,   248,
     437,   292,   276,   355,   246,    23,   299,   155,   302,     6,
      11,    12,    23,   341,    60,   401,   399,    28,    23,    20,
      23,   247,   384,   380,    42,   250,   385,   247,    23,    42,
     247,   426,   385,   174,   175,   449,   449,   247,    23,   247,
      23,   247,   247,   247,    23,   355,   247,   247,   247,   355,
      23,    23,    28,   297,   355,    23,    23,   355,   355,   355,
      22,    70,     5,   247,   247,   247,   247,     5,   247,   247,
     247,   247,     5,     5,    24,   247,   247,   247,   247,   247,
     247,   247,   247,    23,   247,   355,   355,   247,   247,   247,
     247,   247,   247,   247,   247,    22,    22,    22,    22,    23,
      23,    23,   355,   106,   407,    24,   437,   437,    24,    23,
     387,    63,    26,   385,   355,   386,   355,    23,    22,   322,
     333,    22,   433,    13,    14,    15,    16,    17,    18,    19,
     247,   339,   433,   433,    72,   294,   319,   320,   355,    26,
     355,   386,   355,   387,    63,    24,   246,   156,   157,   132,
     355,    61,   426,   331,   355,   250,   379,   381,    23,   155,
     155,    23,    23,   164,   165,   166,   167,   394,   407,     6,
     407,     6,   394,   394,   407,   449,   355,   355,   355,   247,
     449,   407,   408,   408,   426,   279,    23,    23,   247,   247,
     207,   208,   209,   210,   211,   212,   213,   459,   396,   437,
     463,    79,   465,   465,   460,   450,    79,   466,   466,   461,
     452,   453,   455,   456,   458,   437,    79,   467,   467,   462,
     456,   467,   467,   462,   452,   341,    23,    23,     5,     5,
       5,     5,     5,   355,   355,   355,     6,     6,     6,     6,
     407,   407,    23,    22,   409,   410,   437,   437,   438,   437,
     355,   355,    23,    26,    63,   281,    23,    23,   158,   328,
     383,   437,    16,   105,   340,   323,   340,    16,   339,   340,
     321,    16,   145,   326,    69,   325,   326,    32,    74,   303,
      23,   247,   434,   355,    26,    63,   355,   248,   437,   355,
      23,    23,    23,   407,   407,   449,    23,   247,    23,   247,
     449,   449,   297,    23,    23,    23,   394,   297,    23,    23,
       6,     6,    23,   214,   464,   355,    23,    23,   247,    23,
     355,    23,    23,   247,    23,    24,   355,    23,    23,   247,
      23,    23,    23,   247,    23,   247,    23,   408,   408,    23,
      23,    23,    23,   247,   247,   247,   247,    23,    23,    23,
      23,   407,   410,   411,   412,    24,   355,   355,    23,    23,
      24,   323,    20,   100,   335,   323,    16,   323,   150,   242,
     310,   341,   176,   445,   446,   319,   355,   355,    24,    23,
     407,   266,   407,   266,    23,    23,   279,   408,   408,   408,
     449,   279,   449,    23,   167,    23,   199,   453,   450,   451,
     453,   456,   452,     3,   439,    53,   456,   457,   456,   457,
       5,     5,   466,   465,   355,   250,   250,   250,   250,    23,
     107,   413,   437,   437,   308,   341,   323,    20,   335,   433,
      28,    22,    73,   295,   296,   355,     3,   447,   448,   248,
     407,    23,    23,   407,   407,    23,   297,    23,    23,   148,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    32,
     297,    24,   308,    99,    23,   125,   247,    28,   247,   407,
     407,   408,   279,   408,     5,   385,   111,   118,   414,   415,
       5,   328,   402,    22,   295,     3,   409,   447,    23,    31,
      50,   135,   394,   416,   417,   418,   419,   295,   408,   135,
     394,   417,   420,   421,   117,   109,   109,    66,   422,    23,
      68,    68,    26,    50,    72,    93,   133,   420,   117,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   259,   260,   261,   261,   262,   262,   262,   262,   263,
     263,   263,   263,   264,   264,   265,   265,   266,   267,   268,
     269,   269,   269,   270,   270,   271,   271,   271,   271,   271,
     272,   273,   273,   274,   275,   276,   276,   277,   278,   279,
     279,   279,   279,   280,   280,   280,   280,   281,   281,   282,
     282,   282,   283,   283,   284,   284,   285,   286,   287,   288,
     289,   290,   291,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   296,   296,   296,   297,   297,   298,   299,
     299,   300,   301,   301,   301,   302,   302,   302,   303,   303,
     304,   304,   305,   305,   306,   307,   307,   308,   309,   309,
     310,   310,   310,   311,   311,   311,   312,   313,   313,   314,
     314,   315,   315,   315,   315,   316,   316,   316,   316,   317,
     318,   319,   319,   320,   321,   321,   322,   322,   323,   323,
     324,   324,   324,   324,   324,   324,   325,   325,   325,   326,
     327,   327,   327,   328,   328,   328,   328,   329,   330,   330,
     330,   330,   330,   331,   331,   331,   331,   331,   331,   331,
     331,   332,   332,   332,   333,   333,   333,   333,   334,   334,
     334,   334,   335,   336,   336,   337,   338,   338,   339,   339,
     339,   339,   340,   340,   341,   341,   342,   342,   343,   343,
     344,   344,   345,   345,   346,   347,   348,   348,   348,   348,
     348,   348,   349,   350,   350,   351,   351,   351,   351,   352,
     352,   353,   353,   354,   355,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   359,   360,   360,   360,   360,   361,
     361,   361,   361,   361,   361,   361,   362,   362,   362,   362,
     362,   363,   363,   364,   364,   364,   365,   365,   366,   366,
     366,   367,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   371,   371,   372,   373,   373,   374,   374,   374,
     374,   375,   375,   376,   376,   377,   378,   378,   378,   379,
     379,   380,   381,   381,   382,   382,   383,   383,   383,   384,
     385,   385,   386,   386,   387,   387,   387,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   389,   390,   391,
     391,   391,   391,   392,   392,   393,   393,   394,   394,   394,
     394,   394,   394,   394,   394,   395,   396,   396,   396,   396,
     396,   397,   398,   398,   399,   399,   400,   401,   401,   402,
     402,   402,   402,   402,   403,   403,   403,   403,   403,   403,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     405,   406,   406,   406,   406,   406,   407,   407,   408,   408,
     409,   410,   411,   412,   412,   413,   413,   414,   414,   415,
     415,   416,   416,   417,   417,   417,   418,   419,   420,   420,
     420,   421,   422,   422,   422,   422,   422,   423,   423,   424,
     424,   424,   424,   424,   424,   424,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   428,   428,
     429,   430,   431,   431,   432,   432,   432,   432,   433,   433,
     434,   434,   435,   436,   437,   437,   437,   438,   438,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     440,   440,   440,   440,   441,   441,   441,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   445,   445,   446,   447,   447,   448,   448,   449,   449,
     449,   450,   450,   450,   450,   450,   450,   450,   450,   451,
     451,   452,   452,   452,   452,   453,   453,   453,   453,   453,
     454,   454,   455,   455,   456,   456,   456,   456,   456,   457,
     457,   458,   459,   459,   459,   459,   459,   459,   459,   460,
     460,   461,   461,   462,   462,   462,   462,   463,   463,   464,
     464,   465,   466,   467,   468,   468,   468,   468,   468,   468,
     469,   469,   469,   469,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   471,   471,   471,   471,   471,   471,
     471,   471,   471
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     0,     1,     1,     1,     5,
       4,     7,     6,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     3,     1,     2,     2,     1,     2,
       2,     4,     3,     6,     2,     1,     3,     3,     1,     0,
       3,     3,     3,     0,     2,     2,     2,     3,     4,     1,
       4,     4,     1,     4,     1,     3,     3,     3,     1,     1,
       1,     9,     0,     2,     2,     0,     2,     0,     2,     0,
       4,     1,     3,     2,     1,     5,     0,     1,     3,     1,
       3,     3,     0,     1,     1,     0,     2,     2,     0,     2,
       2,     3,     1,     3,     4,     0,     1,     3,     1,     3,
       0,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     1,     2,     2,     3,     1,     3,     5,     7,     2,
       4,     1,     3,     2,     1,     3,     1,     1,     1,     3,
       2,     3,     3,     2,     2,     3,     5,     5,     5,     3,
       4,     3,     4,     1,     3,     5,     7,     2,     0,     6,
       6,     6,     6,     1,     3,     5,     4,     7,     6,     6,
       5,     1,     3,     5,     1,     1,     1,     1,     5,     4,
       6,     5,     2,     4,     3,     4,     5,     4,     2,     2,
       2,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     6,     3,     5,     4,     6,     3,
       4,     3,     4,     2,     1,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     5,     6,     3,     5,     4,
       6,     3,     4,     3,     4,     2,     3,     4,     5,     1,
       3,     3,     1,     3,     1,     2,     3,     4,     5,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     2,
       2,     5,     0,     1,     1,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     5,     4,     6,     5,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       3,     1,     4,     0,     1,     0,     3,     0,     3,     1,
       1,     1,     1,     2,     2,     1,     2,     4,     1,     2,
       1,     2,     0,     3,     2,     2,     3,     3,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     6,     6,
       4,     3,     4,     1,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     0,     1,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     6,     6,     8,     5,     7,     9,     5,     7,
       9,     8,     8,     5,     9,     7,     7,     7,     9,    11,
       5,     5,     6,     6,     5,     4,     4,     5,     8,     7,
       8,     0,     1,     2,     1,     3,     3,     3,     0,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     1,     2,     2,     1,     1,     0,
       4,     3,     3,     3,     7,     6,     6,     8,     6,     8,
       6,     6,     8,     6,     6,     6,     8,     6,     6,     6,
       8,     6,     8,     8,     4,     6,     6,     6,     6,     6,
       6,     6,     8
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if BIGQUERY_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined BIGQUERY_LTYPE_IS_TRIVIAL && BIGQUERY_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParseResult* result, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !BIGQUERY_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !BIGQUERY_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, ParseResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* NAME  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4552 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 4: /* NAMES  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4558 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 5: /* STR  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4564 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 6: /* INTNUM  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4570 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 7: /* BOOL_VAL  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4576 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 8: /* APPROXNUM  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4582 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 9: /* NULLX  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4588 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 10: /* UNKNOWN  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4594 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 11: /* QUESTIONMARK  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4600 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 12: /* PARAM  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4606 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 260: /* sql_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4612 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 261: /* stmt_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4618 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 262: /* stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4624 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 263: /* call_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4630 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 264: /* sql_argument_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4636 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 265: /* sql_argument  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4642 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 266: /* value_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4648 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 267: /* sp_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4654 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 268: /* dql_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4660 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 269: /* dml_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4666 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 270: /* insert_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4672 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 271: /* insert_columns_and_source  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4678 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 272: /* from_constructor  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4684 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 273: /* delete_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4690 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 274: /* update_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4696 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 275: /* table_and_alias  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4702 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 276: /* update_elem_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4708 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 277: /* update_elem  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4714 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 278: /* select_stmt  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4720 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 279: /* limit_num  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4726 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 280: /* offset_num  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4732 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 281: /* query_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4738 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 282: /* query_expression_body  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4744 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 283: /* query_term  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4750 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 284: /* query_primary  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4756 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 285: /* select_with_parens  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4762 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 286: /* select_stmt_with_parens  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4768 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 287: /* subquery  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4774 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 288: /* table_subquery  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4780 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 289: /* row_subquery  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4786 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 290: /* simple_table  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4792 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 291: /* select_as_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4798 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 292: /* opt_where  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4804 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 293: /* opt_from_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4810 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 294: /* opt_groupby  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4816 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 295: /* grouping_element_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4822 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 296: /* grouping_element  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4828 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 297: /* opt_order_by  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4834 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 298: /* order_by  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4840 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 299: /* sort_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4846 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 300: /* sort_key  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4852 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 301: /* opt_asc_desc  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4858 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 302: /* opt_nulls  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4864 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 303: /* opt_having  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4870 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 304: /* with_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4876 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 305: /* with_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4882 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 306: /* common_table_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4888 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 307: /* opt_derived_column_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4894 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 308: /* simple_ident_list_with_parens  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4900 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 309: /* simple_ident_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4906 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 310: /* opt_distinct  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4912 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 311: /* select_expr_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4918 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 312: /* projection_comma  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4924 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 313: /* projection  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4930 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 314: /* row_expr_op_as_label  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4936 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 315: /* asterisk_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4942 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 316: /* asterisk_qualify  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4948 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 317: /* except_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4954 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 318: /* repalce_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4960 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 319: /* row_expr_as_label_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4966 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 320: /* row_expr_as_label  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4972 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 321: /* from_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4978 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 322: /* table_reference  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4984 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 323: /* table_primary  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4990 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 324: /* table_primary_non_join  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4996 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 325: /* for_system_time_as_of  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5002 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 326: /* with_as_num  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5008 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 327: /* unnest_def  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5014 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 328: /* column_ref  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5020 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 329: /* column_ref_bigquery  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5026 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 330: /* opt_array_index_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5032 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 331: /* relation_factor  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5038 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 332: /* custom_function_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5044 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 333: /* joined_table  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5050 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 334: /* qualified_join  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5056 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 335: /* join_on  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5062 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 336: /* cross_join  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5068 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 337: /* qualified_join_2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5074 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 338: /* natural_join  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5080 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 339: /* join_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5086 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 341: /* search_condition  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5092 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 342: /* boolean_term  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5098 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 343: /* boolean_factor  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5104 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 344: /* boolean_test  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5110 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 345: /* boolean_primary  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5116 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 346: /* parens_boolean_primary  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5122 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 347: /* nonparens_boolean_primary  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5128 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 348: /* predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5134 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 349: /* comparison_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5140 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 350: /* between_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5146 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 351: /* like_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5152 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 352: /* in_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5158 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 353: /* is_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5164 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 354: /* exists_predicate  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5170 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 355: /* row_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5176 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 356: /* factor  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5182 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 357: /* factor0  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5188 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 358: /* factor1  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5194 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 359: /* factor2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5200 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 360: /* factor3  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5206 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 361: /* factor4  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5212 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 362: /* bool_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5218 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 363: /* or_cond  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5224 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 364: /* or_cond2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5230 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 365: /* and_cond  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5236 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 366: /* and_cond2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5242 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 367: /* not_cond  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5248 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 368: /* not_cond2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5254 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 369: /* bool_primary_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5260 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 370: /* bool_primary_row_sub  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5266 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 371: /* predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5272 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 372: /* comparison_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5278 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 373: /* between_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5284 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 374: /* like_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5290 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 375: /* in_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5296 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 376: /* is_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5302 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 377: /* exists_predicate_row  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5308 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 378: /* struct_def  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5314 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 379: /* row_expr_op_as_label_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5320 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 380: /* struct_mumber_def  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5326 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 381: /* name_2_type_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5332 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 382: /* name_2_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5338 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 383: /* array_def  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5344 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 384: /* array_mumber_def  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5350 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 385: /* row_expr_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5356 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 386: /* in_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5362 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 387: /* truth_value  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5368 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 394: /* expr_const  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5374 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 395: /* numeric_num  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5380 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 396: /* const_string  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5386 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 397: /* case_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5392 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 398: /* case_arg  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5398 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 399: /* when_clause_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5404 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 400: /* when_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5410 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 401: /* case_default  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5416 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 402: /* func_expr  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5422 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 403: /* aggregate_windowed_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5428 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 404: /* aggregate_function_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5434 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 405: /* ranking_windowed_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5440 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 406: /* ranking_function_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5446 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 407: /* over_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5452 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 408: /* opt_over_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5458 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 409: /* window_specification  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5464 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 410: /* window_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5470 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 411: /* window_specification_details  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5476 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 412: /* opt_existing_window_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5482 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 413: /* opt_window_partition_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5488 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 414: /* opt_window_frame_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5494 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 415: /* window_frame_units  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5500 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 416: /* window_frame_extent  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5506 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 417: /* window_frame_start  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5512 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 418: /* window_frame_preceding  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5518 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 419: /* window_frame_between  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5524 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 420: /* window_frame_bound  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5530 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 421: /* window_frame_following  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5536 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 422: /* opt_window_frame_exclusion  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5542 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 423: /* scalar_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5548 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 424: /* non_second_primary_datetime_field  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5554 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 425: /* function_call_keyword  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5560 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 426: /* data_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5566 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 427: /* predefined_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5572 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 428: /* combination_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5578 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 429: /* struct_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5584 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 430: /* array_type  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5590 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 431: /* distinct_or_all  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5596 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 433: /* opt_as_label  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5602 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 434: /* as_label  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5608 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 435: /* label  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5614 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 436: /* collate_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5620 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 437: /* name_r  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5626 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 438: /* name_f  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5632 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 439: /* reserved  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5638 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 440: /* function_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5644 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 441: /* call_keyword  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5650 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 442: /* bigquery_func_name  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5656 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 443: /* datatype_reserved  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5662 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 444: /* bigquery_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5668 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 445: /* opt_window_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5674 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 446: /* window_clause  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5680 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 447: /* window_list  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5686 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 448: /* window_list_element  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5692 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 449: /* opt_respect_nulls  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5698 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 450: /* date_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5704 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 451: /* datetime_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5710 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 452: /* datetime_part2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5716 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 453: /* day_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5722 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 454: /* ext_day_part1  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5728 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 455: /* ext_day_part2  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5734 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 456: /* hour_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5740 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 457: /* hour_day_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5746 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 458: /* week_func  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5752 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 459: /* week_  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5758 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 460: /* date_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5764 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 461: /* datetime_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5770 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 462: /* timestamp_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5776 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 463: /* all_date_expression  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5782 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 464: /* opt_at_time_zone  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5788 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 465: /* interval_date_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5794 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 466: /* interval_datetime_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5800 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 467: /* interval_time_part  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5806 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 468: /* date_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5812 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 469: /* datetime_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5818 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 470: /* time_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5824 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;

    case 471: /* string_function  */
#line 98 "bigquery.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5830 "sqlparser_bigquery_bison.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (ParseResult* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined BIGQUERY_LTYPE_IS_TRIVIAL && BIGQUERY_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 67 "bigquery.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 5947 "sqlparser_bigquery_bison.cpp" /* yacc.c:1429  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 272 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    result->result_tree_ = (yyvsp[-1].node);
    result->accept = true;
    YYACCEPT;
}
#line 6141 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 283 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
#line 6150 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 290 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6156 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 298 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 6165 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 303 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-2].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 6174 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 308 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 6183 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 313 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 6192 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 322 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6201 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 330 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 6210 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 335 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 6219 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 366 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 6228 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 371 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT_V2;
}
#line 6237 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 379 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6246 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 384 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6255 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 389 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6264 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 394 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6273 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 399 "bigquery.y" /* yacc.c:1646  */
    {
    Node* src = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT VALUES");
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, src);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6283 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 408 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
#line 6292 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		(yyvsp[-1].node),		    /* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,    /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		(yyvsp[0].node),		    /* E_DELETE_OPT_WHERE 6 */
    		nullptr 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    (yyval.node)->serialize_format = &DELETE_SERIALIZE_FORMAT;
}
#line 6309 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 430 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		(yyvsp[-1].node),		    /* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,    /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		(yyvsp[0].node),		    /* E_DELETE_OPT_WHERE 6 */
    		nullptr 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    (yyval.node)->serialize_format = &DELETE_SERIALIZE_FORMAT_V2;
}
#line 6326 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 447 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE, E_UPDATE_PROPERTY_CNT,
        nullptr,	/* E_UPDATE_OPT_WITH 0 */
        nullptr,	/* E_UPDATE_OPT_TOP 1 */
        (yyvsp[-4].node),		    /* E_UPDATE_UPDATE_RELATION 2 */
        nullptr,	/* E_UPDATE_UPDATE_RELATION_OPT_TABLE_HINT 3 */
        (yyvsp[-2].node),		    /* E_UPDATE_UPDATE_ELEM_LIST 4 */
        nullptr,	/* E_UPDATE_OPT_OUTPUT 5 */
        (yyvsp[-1].node),	        /* E_UPDATE_FROM_LIST 6 */
        (yyvsp[0].node),		    /* E_UPDATE_OPT_WHERE 7 */
        nullptr		/* E_UPDATE_OPT_QUERY_HINT 8 */);
    (yyval.node)->serialize_format = &UPDATE_SERIALIZE_FORMAT;
}
#line 6344 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 464 "bigquery.y" /* yacc.c:1646  */
    {
    if((yyvsp[0].node)){
        (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
        (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
    } else {
        (yyval.node)=(yyvsp[-1].node);
    }
}
#line 6357 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 476 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6366 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 484 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
#line 6375 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 493 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
   // $$->setChild(E_DIRECT_SELECT_ORDER, $2);
   // $$->setChild(3, $3);
}
#line 6385 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 501 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6391 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 503 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT;
}
#line 6400 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 508 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT;
}
#line 6409 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 513 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT;
}
#line 6418 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 520 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6424 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 523 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_NUM_FORMAT;
}
#line 6433 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 528 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_NUM_FORMAT;
}
#line 6442 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 533 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_NUM_FORMAT;
}
#line 6451 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 541 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node),nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}
#line 6460 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 546 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}
#line 6469 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 554 "bigquery.y" /* yacc.c:1646  */
    {
    Node* set_op = Node::makeTerminalNode(E_SET_UNION, "UNION");
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        (yyvsp[-1].node),                  /* E_SELECT_ALL_SPECIFIED 7 */
                        (yyvsp[-3].node),                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        (yyvsp[0].node),                  /* E_SELECT_LATER_SELECT_STMT 9 */
                        nullptr,             /* E_SELECT_ORDER_BY 10 */
                        nullptr,             /* E_SELECT_LIMIT 11 */
                        nullptr,             /* E_SELECT_FOR_UPDATE 12 */
                        nullptr,             /* E_SELECT_HINTS 13 */
                        nullptr,             /* E_SELECT_WHEN 14 */
                        nullptr,             /* E_SELECT_OPT_TOP 15 */
                        nullptr,             /* E_SELECT_OPT_WITH 16 */
                        nullptr,             /* E_SELECT_OPT_OPTION 17 */
                        nullptr,             /* E_SELECT_OPT_INTO 18 */
                        nullptr              /* E_SELECT_AS_CLAUSE 19*/
                        );
    (yyval.node)->serialize_format = &SELECT_UNION_SERIALIZE_FORMAT;
}
#line 6500 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 581 "bigquery.y" /* yacc.c:1646  */
    {
    Node * dist = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
    Node* set_op = Node::makeTerminalNode(E_SET_EXCEPT, "EXCEPT");
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        dist,                  /* E_SELECT_ALL_SPECIFIED 7 */
                        (yyvsp[-3].node),                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        (yyvsp[0].node),                  /* E_SELECT_LATER_SELECT_STMT 9 */
                        nullptr,             /* E_SELECT_ORDER_BY 10 */
                        nullptr,             /* E_SELECT_LIMIT 11 */
                        nullptr,             /* E_SELECT_FOR_UPDATE 12 */
                        nullptr,             /* E_SELECT_HINTS 13 */
                        nullptr,             /* E_SELECT_WHEN 14 */
                        nullptr,             /* E_SELECT_OPT_TOP 15 */
                        nullptr,             /* E_SELECT_OPT_WITH 16 */
                        nullptr,             /* E_SELECT_OPT_OPTION 17 */
                        nullptr,             /* E_SELECT_OPT_INTO 18 */
                        nullptr              /* E_SELECT_AS_CLAUSE 19*/
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT;
}
#line 6532 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 613 "bigquery.y" /* yacc.c:1646  */
    {
    Node * dist = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
    Node* set_op = Node::makeTerminalNode(E_SET_INTERSECT, "INTERSECT");
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        dist,                  /* E_SELECT_ALL_SPECIFIED 7 */
                        (yyvsp[-3].node),                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        (yyvsp[0].node),                  /* E_SELECT_LATER_SELECT_STMT 9 */
                        nullptr,             /* E_SELECT_ORDER_BY 10 */
                        nullptr,             /* E_SELECT_LIMIT 11 */
                        nullptr,             /* E_SELECT_FOR_UPDATE 12 */
                        nullptr,             /* E_SELECT_HINTS 13 */
                        nullptr,             /* E_SELECT_WHEN 14 */
                        nullptr,             /* E_SELECT_OPT_TOP 15 */
                        nullptr,             /* E_SELECT_OPT_WITH 16 */
                        nullptr,             /* E_SELECT_OPT_OPTION 17 */
                        nullptr,             /* E_SELECT_OPT_INTO 18 */
                        nullptr              /* E_SELECT_AS_CLAUSE 19 */
                        );
    (yyval.node)->serialize_format = &SELECT_INTERSECT_SERIALIZE_FORMAT;
}
#line 6564 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 645 "bigquery.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].node)->getChild(E_DIRECT_SELECT_WITH)) {
        yyerror(&(yylsp[-2]), result, scanner, "error use common table expression");
        YYABORT;
    }
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6577 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 658 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6586 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 666 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6595 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 680 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                    (yyvsp[-7].node),             /* E_SELECT_DISTINCT 0 */
                    (yyvsp[-5].node),             /* E_SELECT_SELECT_EXPR_LIST 1 */
                    (yyvsp[-4].node),             /* E_SELECT_FROM_LIST 2 */
                    (yyvsp[-3].node),             /* E_SELECT_OPT_WHERE 3 */
                    (yyvsp[-2].node),             /* E_SELECT_GROUP_BY 4 */
                    (yyvsp[-1].node),             /* E_SELECT_HAVING 5 */
                    nullptr,        /* E_SELECT_SET_OPERATION 6 */
                    nullptr,        /* E_SELECT_ALL_SPECIFIED 7 */
                    nullptr,        /* E_SELECT_FORMER_SELECT_STMT 8 */
                    nullptr,        /* E_SELECT_LATER_SELECT_STMT 9 */
                    (yyvsp[0].node),             /* E_SELECT_ORDER_BY 10 */ /* WINDOW_CLAUSE */
                    nullptr,        /* E_SELECT_LIMIT 11 */
                    nullptr,        /* E_SELECT_FOR_UPDATE 12 */
                    nullptr,        /* E_SELECT_HINTS 13 */
                    nullptr,        /* E_SELECT_WHEN 14 */
                    nullptr,        /* E_SELECT_OPT_TOP 15 */
                    nullptr,        /* E_SELECT_OPT_WITH 16 */
                    nullptr,        /* E_SELECT_OPT_OPTION 17 */
	                nullptr,        /* E_SELECT_OPT_INTO 18 */
	                (yyvsp[-6].node)              /* E_SELECT_AS_CLAUSE 19*/
                    );
    if(NULL == (yyvsp[-5].node)){
        if(NULL != (yyvsp[-4].node)){
            yyerror(&(yylsp[-8]), result, scanner, "Statement without FROM clause cannot have an WHERE");
            YYABORT;
        }
        if(NULL != (yyvsp[-3].node)){
            yyerror(&(yylsp[-8]), result, scanner, "Statement without FROM clause cannot have an GROUP BY");
            YYABORT;
        }
        if(NULL != (yyvsp[-2].node)){
            yyerror(&(yylsp[-8]), result, scanner, "Statement without FROM clause cannot have an HAVING");
            YYABORT;
        }
    }
    (yyval.node)->serialize_format = &SELECT_SERIALIZE_FORMAT;
}
#line 6639 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 722 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; }
#line 6645 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 724 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_AS_STRUCT, "AS STRUCT");
}
#line 6653 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 728 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_AS_STRUCT_VALUE, "AS VALUE");
}
#line 6661 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 734 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6667 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 736 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
#line 6676 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 744 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node)=nullptr; }
#line 6682 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 746 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FROM_SERIALIZE_FORMAT;
}
#line 6691 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 753 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6697 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 755 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
#line 6706 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 764 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6715 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 772 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"()"); }
#line 6721 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 775 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6732 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 784 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6738 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 790 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_BY_SERIALIZE_FORMAT;
}
#line 6747 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 799 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6756 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 807 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_KEY, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 6765 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 815 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "");
}
#line 6773 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 819 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
#line 6781 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 823 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
#line 6789 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 829 "bigquery.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 6795 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 831 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, " NULLS FIRST");
}
#line 6803 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 835 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, " NULLS LAST");
}
#line 6811 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 841 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6817 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 843 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
#line 6826 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 853 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
#line 6835 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 858 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
#line 6844 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 867 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6853 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 876 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, E_COMMON_TABLE_EXPR_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT;
}
#line 6862 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 883 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6868 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 889 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6877 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 898 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6886 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 905 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6892 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 907 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 6900 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 911 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 6908 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 920 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 6917 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 928 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyval.node)->serialize_format = &EXPR_COMMA_SERIALIZE_FORMAT; /* Notice that the original value is SINGLE_SERIALIZE_FORMAT */
}
#line 6926 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 935 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6935 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 940 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6944 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 950 "bigquery.y" /* yacc.c:1646  */
    {
    if (!(yyvsp[0].node)) {
    	(yyval.node) = (yyvsp[-1].node);
    }
    else {
	    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
        (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
    }
}
#line 6958 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 960 "bigquery.y" /* yacc.c:1646  */
    {
    if (!(yyvsp[0].node)) {
    	(yyval.node) = (yyvsp[-1].node);
    }
    else {
	    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
        (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
    }
}
#line 6972 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 974 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, (yyvsp[0].node), NULL, NULL);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 6981 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 979 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, (yyvsp[-1].node), (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 6990 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 984 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, (yyvsp[-1].node), NULL, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 6999 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 989 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 7008 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 997 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STAR, "*");
}
#line 7016 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1001 "bigquery.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, NULL, NULL, (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 7026 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1007 "bigquery.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, NULL, (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 7036 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1013 "bigquery.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 7046 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1020 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXCEPT_EXPR, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &EXCEPT_EXPR_SERIALIZE_FORMAT;
}
#line 7055 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1027 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_REPLACE_EXPR, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &REPLACE_EXPR_SERIALIZE_FORMAT;
}
#line 7064 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1035 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ROW_EXPR_AS_LABEL_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7073 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1041 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ROW_EXPR_AS_LABEL, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &ROW_EXPR_AS_SERIALIZE_FORMAT;
}
#line 7082 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1050 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7091 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1064 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7100 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1076 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7109 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1081 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7118 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1086 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7127 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1091 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7136 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1096 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7145 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1101 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 7154 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1109 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR SYSTEM_TIME AS OF "+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 7164 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1115 "bigquery.y" /* yacc.c:1646  */
    {
    std::string ss = "";
    if((yyvsp[0].node)!=NULL){ss += "FOR SYSTEM_TIME AS OF "; ss+=(yyvsp[0].node)->text(); delete((yyvsp[0].node));}
    (yyval.node) = Node::makeTerminalNode(E_STRING, ss);
}
#line 7174 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1121 "bigquery.y" /* yacc.c:1646  */
    {
    std::string ss = "";
    if((yyvsp[0].node)!=NULL){ss += "FOR SYSTEM_TIME AS OF "; ss+=(yyvsp[0].node)->text(); delete((yyvsp[0].node));}
    (yyval.node) = Node::makeTerminalNode(E_STRING, ss);
}
#line 7184 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1130 "bigquery.y" /* yacc.c:1646  */
    {
    std::string ss = "WITH OFFSET ";
    if((yyvsp[0].node)!=NULL){ss += "AS "; ss+=(yyvsp[0].node)->text(); delete((yyvsp[0].node));}
    (yyval.node) = Node::makeTerminalNode(E_STRING, ss);
}
#line 7194 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1139 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
#line 7203 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1144 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, NULL);
    (yyval.node)->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
#line 7212 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1149 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
#line 7221 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1163 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    (yyvsp[0].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 7231 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1169 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 7241 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1175 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;

}
#line 7252 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1182 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                 (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;

}
#line 7263 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1191 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_INDEX, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 7272 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1197 "bigquery.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 7278 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1199 "bigquery.y" /* yacc.c:1646  */
    {
    std::string val = "[OFFSET("+(yyvsp[-2].node)->text()+")]";
    delete((yyvsp[-2].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 7288 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1205 "bigquery.y" /* yacc.c:1646  */
    {
   std::string val = "[ORDINAL("+(yyvsp[-2].node)->text()+")]";
   delete((yyvsp[-2].node));
   (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 7298 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1211 "bigquery.y" /* yacc.c:1646  */
    {
    std::string val = "[SAFE_OFFSET("+(yyvsp[-2].node)->text()+")]";
    delete((yyvsp[-2].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 7308 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1217 "bigquery.y" /* yacc.c:1646  */
    {
   std::string val = "[SAFE_ORDINAL("+(yyvsp[-2].node)->text()+")]";
   delete((yyvsp[-2].node));
   (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 7318 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1227 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7327 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1232 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 7336 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1237 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 7345 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1242 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 7354 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1247 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7363 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1252 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7372 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1257 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7381 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1262 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, (yyvsp[-4].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7390 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1270 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7399 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1275 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 7408 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1280 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 7417 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1296 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 7426 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1301 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 7436 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1307 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 7445 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1312 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 7455 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1321 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7461 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1326 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 7471 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1332 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-2].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 7481 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1341 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-3].node), (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 7490 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1349 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL " + (yyvsp[-2].node)->text());
    delete((yyvsp[-2].node));
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 7501 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1356 "bigquery.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 7511 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1365 "bigquery.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].ival))
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_FULL, "FULL OUTER");
    }
    else
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_FULL, "FULL");
    }
}
#line 7526 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1376 "bigquery.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].ival))
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_LEFT, "LEFT OUTER");
    }
    else
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_LEFT, "LEFT");
    }
}
#line 7541 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1387 "bigquery.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].ival))
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_RIGHT, "RIGHT OUTER");
    }
    else
    {
        (yyval.node) = Node::makeTerminalNode(E_JOIN_RIGHT, "RIGHT");
    }
}
#line 7556 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1398 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_JOIN_INNER, "INNER");
}
#line 7564 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1404 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 7570 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1405 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; /*this is a flag*/}
#line 7576 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1412 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 7585 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1421 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 7594 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1430 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 7603 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1448 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7612 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1479 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7621 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1497 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 7630 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1502 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 7639 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1510 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 7648 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1515 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 7657 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1520 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 7666 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1525 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 7675 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1533 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 7684 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1538 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 7693 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1546 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 7702 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1551 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 7711 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1559 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 7720 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1569 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 7729 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1574 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7738 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1583 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7747 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1592 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7756 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1601 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7765 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1610 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POW);
}
#line 7774 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1619 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POS);
}
#line 7783 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1624 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
#line 7792 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1629 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_BIT_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_BIT_OP_NOT);
}
#line 7801 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1651 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7810 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1659 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 7819 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1664 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 7828 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1678 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 7837 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1683 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 7846 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1696 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 7855 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1716 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7864 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1732 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 7873 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1740 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 7882 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1745 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 7891 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1753 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 7900 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1758 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 7909 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1763 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 7918 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1768 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 7927 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1776 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 7936 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1781 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 7945 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1789 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 7954 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1794 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 7963 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1802 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 7972 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1817 "bigquery.y" /* yacc.c:1646  */
    {

    Node * node_list  = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    if((yyvsp[-1].node)->nodeType_ == E_EXPR_LIST){
        (yyval.node) = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, NULL, NULL, node_list);
        (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
    } else {
        (yyval.node) =   node_list;
    }
}
#line 7989 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1830 "bigquery.y" /* yacc.c:1646  */
    {
    Node * node_struct = Node::makeTerminalNode(E_STRING,"STRUCT");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    (yyval.node) = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, node_struct, NULL, node_list);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8003 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1840 "bigquery.y" /* yacc.c:1646  */
    {
    Node * node_struct = Node::makeTerminalNode(E_STRING,"STRUCT");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    (yyval.node) = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, node_struct, (yyvsp[-3].node), node_list);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8017 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1854 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8026 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1862 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STRUCT_MEMBER_DEF, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &MEMBER_DEF_SERIALIZE_FORMAT;
}
#line 8035 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1871 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_NAME_TYPE_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8044 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1880 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_NAME_2_TYPE, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8053 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1888 "bigquery.y" /* yacc.c:1646  */
    {
    //square brackets
     Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, NULL, NULL, node_list);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8066 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1897 "bigquery.y" /* yacc.c:1646  */
    {
    Node * node_array = Node::makeTerminalNode(E_STRING,"ARRAY");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, node_array, NULL, node_list);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8080 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1907 "bigquery.y" /* yacc.c:1646  */
    {
    Node * node_array = Node::makeTerminalNode(E_STRING,"ARRAY");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  (yyvsp[-1].node));
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, node_array, (yyvsp[-3].node), node_list);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8094 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1920 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_MEMBER_DEF, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &MEMBER_DEF_SERIALIZE_FORMAT;
}
#line 8103 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1930 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8112 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1939 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8121 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1949 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 8127 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1950 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LT; }
#line 8133 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1951 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 8139 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1952 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GT; }
#line 8145 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 1953 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_EQ; }
#line 8151 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1954 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 8157 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1955 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 8163 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 1956 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 8169 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 1957 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 8175 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 1958 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 8181 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1962 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 8187 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 1969 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.nodetype) = Node::comp_all_some_any_op_form((yyvsp[-1].nodetype), (yyvsp[0].ival));
}
#line 8195 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1975 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_BIT_OP_RS; }
#line 8201 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1976 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_BIT_OP_LS; }
#line 8207 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 1977 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_BIT_OP_AND; }
#line 8213 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 1978 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_BIT_OP_OR; }
#line 8219 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 313:
#line 1982 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_ADD; }
#line 8225 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 1983 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MINUS; }
#line 8231 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 1987 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MUL; }
#line 8237 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 1988 "bigquery.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_DIV; }
#line 8243 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2005 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC"+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
}
#line 8253 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2015 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 8263 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2021 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 8273 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2027 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 8283 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2033 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATETIME"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 8293 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2043 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_CASE);
}
#line 8302 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2050 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8308 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2057 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 8317 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2065 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 8326 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 2073 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8332 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 2075 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
#line 8341 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2093 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8351 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2099 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8361 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2105 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 8371 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2111 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 8381 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2117 "bigquery.y" /* yacc.c:1646  */
    {
    if (!Node::CHECK_FUNCTION_CALL_WITH_STAR((yyvsp[-4].node)))
    {
        yyerror(&(yylsp[-4]), result, scanner, "error use *");
        YYABORT;
    }
    Node* star = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), star, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8397 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2129 "bigquery.y" /* yacc.c:1646  */
    {
    if (!Node::CHECK_FUNCTION_CALL_WITH_STAR((yyvsp[-3].node)))
    {
        yyerror(&(yylsp[-3]), result, scanner, "error use *");
        YYABORT;
    }
    Node* star = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), star, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8413 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2143 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
#line 8419 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2144 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
#line 8425 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2145 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
#line 8431 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2146 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
#line 8437 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2147 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
#line 8443 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2148 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
#line 8449 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 2149 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
#line 8455 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2150 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
#line 8461 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2151 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
#line 8467 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2152 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING"); }
#line 8473 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2157 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), nullptr, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8483 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2165 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
#line 8489 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2166 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
#line 8495 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2167 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
#line 8501 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2168 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
#line 8507 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2169 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
#line 8513 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2174 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node));
}
#line 8521 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2178 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
#line 8530 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2185 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8536 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2191 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 8542 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2200 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
#line 8551 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2207 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8557 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2212 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8563 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2214 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 8569 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2218 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8575 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2220 "bigquery.y" /* yacc.c:1646  */
    {
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+s3);
    delete((yyvsp[-2].node)); delete((yyvsp[-1].node)); delete((yyvsp[0].node));
}
#line 8585 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2228 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
#line 8591 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2229 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
#line 8597 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2238 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
#line 8603 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2239 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
#line 8609 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2244 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" PRECEDING"); delete((yyvsp[-1].node)); }
#line 8615 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2249 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text()); delete((yyvsp[-2].node)); delete((yyvsp[0].node)); }
#line 8621 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2254 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
#line 8627 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2259 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" FOLLOWING"); delete((yyvsp[-1].node)); }
#line 8633 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2263 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8639 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2264 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
#line 8645 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2265 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
#line 8651 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2266 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
#line 8657 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2267 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
#line 8663 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2272 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8673 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2278 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8683 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2287 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "YEAR");
}
#line 8691 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2291 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MONTH");
}
#line 8699 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2295 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DAY");
}
#line 8707 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2299 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "HOUR");
}
#line 8715 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2303 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MINUTE");
}
#line 8723 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2307 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "WEEK");
}
#line 8731 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2311 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "QUARTER");
}
#line 8739 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2329 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8750 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2336 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8761 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2343 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 8772 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2350 "bigquery.y" /* yacc.c:1646  */
    {
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-3].node), nullptr, nullptr, transcoding_name);
    (yyval.node)->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
#line 8785 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2359 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8796 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2366 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8807 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2373 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8818 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2380 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 8829 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2387 "bigquery.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 8842 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2406 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "INT64");}
#line 8848 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2407 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "NUMERIC");}
#line 8854 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2408 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "FLOAT64");}
#line 8860 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2409 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "BOOL");}
#line 8866 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2410 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "STRING");}
#line 8872 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2411 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "BYTES");}
#line 8878 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2412 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "DATE");}
#line 8884 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2413 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "DATETIME");}
#line 8890 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2414 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "TIME");}
#line 8896 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2415 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "TIMESTAMP");}
#line 8902 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2416 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_PRE_DEF_TYPE, "ARRAY");}
#line 8908 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2426 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STRUCT_TYPE, 1, (yyvsp[0].node) );
    (yyval.node)->serialize_format = &STRUCT_TYPE_SERIALIZE_FORMAT;
}
#line 8917 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2433 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ARRAY_TYPE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ARRAY_TYPE_SERIALIZE_FORMAT;
}
#line 8926 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2442 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 8934 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2446 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 8942 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2452 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = -1; }
#line 8948 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2453 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 8954 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2454 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; }
#line 8960 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2455 "bigquery.y" /* yacc.c:1646  */
    { (yyval.ival) = 2; }
#line 8966 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2459 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8972 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2465 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 8980 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2477 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "COLLATE "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 8989 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2499 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CALL"); }
#line 8995 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 2500 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
#line 9001 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2501 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
#line 9007 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 2504 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
#line 9013 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2505 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INSERT"); }
#line 9019 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2506 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
#line 9025 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2507 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
#line 9031 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2508 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
#line 9037 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2509 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MOD"); }
#line 9043 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2510 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
#line 9049 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2511 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NATIONAL"); }
#line 9055 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2513 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
#line 9061 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2514 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
#line 9067 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2515 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
#line 9073 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2516 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
#line 9079 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2517 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
#line 9085 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2518 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
#line 9091 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2519 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REAL"); }
#line 9097 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2520 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
#line 9103 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2521 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
#line 9109 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2522 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
#line 9115 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2523 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SECOND"); }
#line 9121 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2524 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER"); }
#line 9127 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2525 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
#line 9133 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2526 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SMALLINT"); }
#line 9139 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2527 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER"); }
#line 9145 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2528 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
#line 9151 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2530 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 9157 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2531 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARYING"); }
#line 9163 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2532 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
#line 9169 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2533 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
#line 9175 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2534 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OFFSET"); }
#line 9181 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2535 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ORDINAL"); }
#line 9187 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2536 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_ORDINAL"); }
#line 9193 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2537 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_OFFSET"); }
#line 9199 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2538 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DAYOFWEEK"); }
#line 9205 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2539 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DAYOFYEAR"); }
#line 9211 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2540 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ISOWEEK"); }
#line 9217 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2541 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ISOYEAR"); }
#line 9223 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2542 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MICROSECOND"); }
#line 9229 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2543 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MILLISECOND"); }
#line 9235 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2544 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUNDAY"); }
#line 9241 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2545 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MONDAY"); }
#line 9247 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2546 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TUESDAY"); }
#line 9253 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2547 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WEDNESDAY"); }
#line 9259 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2548 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "THURSDAY"); }
#line 9265 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2549 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FRIDAY"); }
#line 9271 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2550 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SATURDAY"); }
#line 9277 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2551 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AT"); }
#line 9283 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2561 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }
#line 9289 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2562 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
#line 9295 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2563 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }
#line 9301 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2569 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE"); }
#line 9307 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2570 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE"); }
#line 9313 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2571 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE"); }
#line 9319 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 2572 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LEAD"); }
#line 9325 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 2573 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LAG"); }
#line 9331 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 2574 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT"); }
#line 9337 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 2575 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC"); }
#line 9343 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 2576 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NTILE"); }
#line 9349 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 2577 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_AGG"); }
#line 9355 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 2578 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORR"); }
#line 9361 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 2579 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COVAR_POP"); }
#line 9367 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 2580 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COVAR_SAMP"); }
#line 9373 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 2581 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG"); }
#line 9379 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 2582 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ANY_VALUE"); }
#line 9385 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 2583 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNTIF"); }
#line 9391 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 2584 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_CAST"); }
#line 9397 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 2585 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_CONCAT_AGG"); }
#line 9403 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 2586 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIT_XOR"); }
#line 9409 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 2587 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_AND"); }
#line 9415 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 2588 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_OR"); }
#line 9421 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 2589 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_COUNT_DISTINCT"); }
#line 9427 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 2590 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_QUANTILES"); }
#line 9433 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 2591 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_TOP_COUNT"); }
#line 9439 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 2593 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT"); }
#line 9445 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 2594 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE_ADD"); }
#line 9451 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 2595 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE_SUB"); }
#line 9457 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 2596 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE_DIFF"); }
#line 9463 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 2597 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE_TRUNC"); }
#line 9469 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 2598 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_ADD"); }
#line 9475 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 2599 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_SUB"); }
#line 9481 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 2600 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_DIFF"); }
#line 9487 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 2601 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_TRUNC"); }
#line 9493 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 2602 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME_ADD"); }
#line 9499 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 2603 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME_SUB"); }
#line 9505 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 2604 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME_DIFF"); }
#line 9511 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 2605 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME_TRUNC"); }
#line 9517 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 2606 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_ADD"); }
#line 9523 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 2607 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_SUB"); }
#line 9529 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 2608 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_DIFF"); }
#line 9535 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 2609 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC"); }
#line 9541 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 2611 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING"); }
#line 9547 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 2612 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV"); }
#line 9553 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 2613 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARIANCE"); }
#line 9559 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 2614 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STARTS_WITH"); }
#line 9565 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 2615 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ENDS_WITH"); }
#line 9571 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 2616 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_CONTAINS"); }
#line 9577 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 2617 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_EXTRACT"); }
#line 9583 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 2618 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_REPLACE"); }
#line 9589 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 2619 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_TIMESTAMP_ARRAY"); }
#line 9595 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 2620 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_DATE_ARRAY"); }
#line 9601 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 2621 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_TIME"); }
#line 9607 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 2624 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INT64"); }
#line 9613 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 2625 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FLOAT64"); }
#line 9619 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 2626 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STRING"); }
#line 9625 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 2627 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BYTES"); }
#line 9631 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 2628 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME"); }
#line 9637 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 2629 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE"); }
#line 9643 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 2630 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 9649 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 2631 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME"); }
#line 9655 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 2632 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BOOL"); }
#line 9661 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 571:
#line 2642 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 9672 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 2649 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9683 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 2656 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9694 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 2663 "bigquery.y" /* yacc.c:1646  */
    {   //NTH_VALUE (value_expression, constant_integer_expression [{RESPECT | IGNORE} NULLS]) over_clause
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-3].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list, (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9708 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 2673 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9719 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 2680 "bigquery.y" /* yacc.c:1646  */
    {   //LEAD (value_expression[, offset [, default_expression]])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9733 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 2690 "bigquery.y" /* yacc.c:1646  */
    {   //LEAD (value_expression[, offset [, default_expression]])
    Node* expr_list1 = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-6].node), (yyvsp[-4].node));
    expr_list1->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, expr_list1, (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9749 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 2702 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9760 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 2709 "bigquery.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9774 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 580:
#line 2719 "bigquery.y" /* yacc.c:1646  */
    {   //LAG (value_expression[, offset [, default_expression]])
    Node* expr_list1 = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-6].node), (yyvsp[-4].node));
    expr_list1->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, expr_list1, (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9790 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 581:
#line 2731 "bigquery.y" /* yacc.c:1646  */
    {   //PERCENTILE_CONT (value_expression, percentile [{RESPECT | IGNORE} NULLS])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-3].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list,(yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9804 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 2741 "bigquery.y" /* yacc.c:1646  */
    {   //PERCENTILE_DISC (value_expression, percentile [{RESPECT | IGNORE} NULLS])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-3].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list,(yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9818 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 2751 "bigquery.y" /* yacc.c:1646  */
    {   //NTILE(constant_integer_expression)
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "NTILE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9829 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 2758 "bigquery.y" /* yacc.c:1646  */
    {   //ARRAY_AGG([DISTINCT] expression [{IGNORE|RESPECT} NULLS] [ORDER BY key [{ASC|DESC}] [, ... ]] [LIMIT n]) [OVER (...)]
    std::string ss = "";
    if((yyvsp[-4].node)){ss+= (yyvsp[-4].node)->text(); delete((yyvsp[-4].node)); }
    if((yyvsp[-3].node)){ss+= ss.empty() ? (yyvsp[-3].node)->text() : " " + (yyvsp[-3].node)->text(); delete((yyvsp[-3].node)); }
    if((yyvsp[-2].node)){ss+= ss.empty() ? (yyvsp[-2].node)->text() : " " + (yyvsp[-2].node)->text(); delete((yyvsp[-2].node)); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_AGG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-6].node), (yyvsp[-5].node),  transcoding_nod, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9846 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 585:
#line 2771 "bigquery.y" /* yacc.c:1646  */
    {   //CORR(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "CORR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9860 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 2781 "bigquery.y" /* yacc.c:1646  */
    {   //COVAR_POP(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COVAR_POP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9874 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 2791 "bigquery.y" /* yacc.c:1646  */
    {   //COVAR_SAMP(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COVAR_SAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9888 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 588:
#line 2801 "bigquery.y" /* yacc.c:1646  */
    {   //STRING_AGG([DISTINCT] expression [, delimiter]  [ORDER BY key [{ASC|DESC}] [, ... ]]  [LIMIT n]) [OVER (...)]
    std::string ss = "";
    if((yyvsp[-4].node)){ss+= (yyvsp[-4].node)->text(); delete((yyvsp[-4].node)); }
    if((yyvsp[-3].node)){ss+= ss.empty() ? (yyvsp[-3].node)->text() : " " + (yyvsp[-3].node)->text(); delete((yyvsp[-3].node)); }
    if((yyvsp[-2].node)){ss+= ss.empty() ? (yyvsp[-2].node)->text() : " " + (yyvsp[-2].node)->text(); delete((yyvsp[-2].node)); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-6].node), (yyvsp[-5].node),  transcoding_nod, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9904 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 589:
#line 2813 "bigquery.y" /* yacc.c:1646  */
    {   //STRING_AGG([DISTINCT] expression [, delimiter]  [ORDER BY key [{ASC|DESC}] [, ... ]]  [LIMIT n]) [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-7].node), (yyvsp[-5].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    std::string ss = "";
    if((yyvsp[-4].node)){ss+= (yyvsp[-4].node)->text(); delete((yyvsp[-4].node)); }
    if((yyvsp[-3].node)){ss+= ss.empty() ? (yyvsp[-3].node)->text() : " " + (yyvsp[-3].node)->text(); delete((yyvsp[-3].node)); }
    if((yyvsp[-2].node)){ss+= ss.empty() ? (yyvsp[-2].node)->text() : " " + (yyvsp[-2].node)->text(); delete((yyvsp[-2].node)); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-8].node), expr_list,  transcoding_nod, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9923 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 590:
#line 2828 "bigquery.y" /* yacc.c:1646  */
    {   //ANY_VALUE(expression)  [OVER (...)]
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ANY_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9934 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 591:
#line 2835 "bigquery.y" /* yacc.c:1646  */
    {   //COUNTIF(expression)  [OVER (...)]
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COUNTIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9945 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 592:
#line 2842 "bigquery.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 9956 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 593:
#line 2849 "bigquery.y" /* yacc.c:1646  */
    {   //ARRAY_CONCAT_AGG(expression  [ORDER BY key [{ASC|DESC}] [, ... ]] [LIMIT n])
    std::string ss = "";
    if((yyvsp[-2].node)){ss+= (yyvsp[-2].node)->text(); delete((yyvsp[-2].node));}
    if((yyvsp[-1].node)){ss+= ss.empty() ? (yyvsp[-1].node)->text() : " " + (yyvsp[-1].node)->text(); delete((yyvsp[-1].node));}
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_CONCAT_AGG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node),  transcoding_nod, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9972 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 594:
#line 2861 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "BIT_XOR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), (yyvsp[-1].node), nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9983 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 595:
#line 2868 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_AND");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9994 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 596:
#line 2875 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_OR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 10005 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 597:
#line 2882 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_COUNT_DISTINCT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-2].node), (yyvsp[-1].node), nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 10016 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 598:
#line 2889 "bigquery.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_QUANTILES");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-5].node), expr_list, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 10030 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 599:
#line 2899 "bigquery.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_TOP_COUNT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-4].node), expr_list, nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 10043 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 600:
#line 2908 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "IF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10054 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 601:
#line 2917 "bigquery.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 10060 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 603:
#line 2923 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, " WINDOW "+ (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 10069 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 605:
#line 2932 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 10078 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 606:
#line 2940 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING,  (yyvsp[-2].node)->text() + " AS " + (yyvsp[0].node)->text() );
    delete((yyvsp[-2].node));
    delete((yyvsp[0].node));

}
#line 10089 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 607:
#line 2947 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING,  (yyvsp[-2].node)->text() + " AS " + (yyvsp[0].node)->text() );
    delete((yyvsp[-2].node));
    delete((yyvsp[0].node));
}
#line 10099 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 608:
#line 2955 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = NULL;}
#line 10105 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 609:
#line 2957 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) =  Node::makeTerminalNode(E_STRING, " RESPECT NULLS ");
}
#line 10113 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 610:
#line 2961 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) =  Node::makeTerminalNode(E_STRING, " IGNORE NULLS ");
}
#line 10121 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 616:
#line 2972 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, " DATE");}
#line 10127 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 617:
#line 2973 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "DATETIME");}
#line 10133 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 618:
#line 2974 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "TIME");}
#line 10139 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 625:
#line 2990 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "DAY"); }
#line 10145 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 626:
#line 2991 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "WEEK"); }
#line 10151 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 627:
#line 2992 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "MONTH"); }
#line 10157 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 628:
#line 2993 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "QUARTER"); }
#line 10163 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 629:
#line 2994 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "YEAR"); }
#line 10169 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 630:
#line 2997 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "DAYOFWEEK"); }
#line 10175 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 631:
#line 2998 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "DAYOFYEAR"); }
#line 10181 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 632:
#line 3001 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "ISOWEEK"); }
#line 10187 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 633:
#line 3002 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "ISOYEAR"); }
#line 10193 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 634:
#line 3005 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "MICROSECOND"); }
#line 10199 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 635:
#line 3006 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "MILLISECOND"); }
#line 10205 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 636:
#line 3007 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "SECOND"); }
#line 10211 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 637:
#line 3008 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "MINUTE"); }
#line 10217 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 638:
#line 3009 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "HOUR"); }
#line 10223 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 640:
#line 3013 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "DAY"); }
#line 10229 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 641:
#line 3016 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "WEEK("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10235 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 642:
#line 3019 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "SUNDAY"); }
#line 10241 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 643:
#line 3020 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "MONDAY"); }
#line 10247 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 644:
#line 3021 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "TUESDAY"); }
#line 10253 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 645:
#line 3022 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "WEDNESDAY"); }
#line 10259 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 646:
#line 3023 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "THURSDAY"); }
#line 10265 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 647:
#line 3024 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "FRIDAY"); }
#line 10271 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 648:
#line 3025 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =  Node::makeTerminalNode(E_STRING, "SATURDAY"); }
#line 10277 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 650:
#line 3031 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 10287 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 652:
#line 3041 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATETIME"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 10297 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 655:
#line 3052 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 10307 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 656:
#line 3058 "bigquery.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME"+(yyvsp[0].node)->text());
    (yyval.node)->terminalToken_.str = (yyvsp[0].node)->terminalToken_.str;
    delete((yyvsp[0].node));
}
#line 10317 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 659:
#line 3071 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) =NULL;}
#line 10323 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 660:
#line 3072 "bigquery.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " AT TIME ZONE "+(yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 10329 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 661:
#line 3077 "bigquery.y" /* yacc.c:1646  */
    {
    std::string node = " INTERVAL ";
    node += (yyvsp[-1].node)->text();    delete((yyvsp[-1].node));
    node += " ";
    node += (yyvsp[0].node)->text();    delete((yyvsp[0].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, node);
}
#line 10341 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 662:
#line 3088 "bigquery.y" /* yacc.c:1646  */
    {
    std::string node = " INTERVAL ";
    node += (yyvsp[-1].node)->text();    delete((yyvsp[-1].node));
    node += " ";
    node += (yyvsp[0].node)->text();    delete((yyvsp[0].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, node);
}
#line 10353 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 663:
#line 3099 "bigquery.y" /* yacc.c:1646  */
    {
    std::string node = " INTERVAL ";
    node += (yyvsp[-1].node)->text();    delete((yyvsp[-1].node));
    node += " ";
    node += (yyvsp[0].node)->text();    delete((yyvsp[0].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, node);
}
#line 10365 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 664:
#line 3110 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT");
    std::string s_param;
    s_param += (yyvsp[-4].node)->text(); delete((yyvsp[-4].node));
    s_param += " FROM ";
    s_param += (yyvsp[-2].node)->text(); delete((yyvsp[-2].node));
    if((yyvsp[-1].node)){ s_param += (yyvsp[-1].node)->text(); delete((yyvsp[-1].node)); }
    Node * param = Node::makeTerminalNode(E_STRING, s_param);
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, param, NULL, NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10382 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 665:
#line 3123 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_ADD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10393 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 666:
#line 3130 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_SUB");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10404 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 667:
#line 3137 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_DIFF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10415 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 668:
#line 3145 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_TRUNC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10426 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 669:
#line 3152 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_DATE_ARRAY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10437 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 670:
#line 3164 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_ADD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10448 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 671:
#line 3171 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_SUB");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10459 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 672:
#line 3178 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_DIFF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10470 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 673:
#line 3186 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_TRUNC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10481 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 674:
#line 3196 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_ADD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10492 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 675:
#line 3203 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_SUB");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10503 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 676:
#line 3210 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_DIFF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10514 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 677:
#line 3218 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_TRUNC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10525 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 678:
#line 3226 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_ADD");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10536 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 679:
#line 3233 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_SUB");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10547 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 680:
#line 3240 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_DIFF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10558 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 681:
#line 3248 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10569 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 682:
#line 3255 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10580 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 683:
#line 3264 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_TIMESTAMP_ARRAY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10591 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 684:
#line 3274 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-1].node), NULL, NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10602 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 685:
#line 3281 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10613 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 686:
#line 3288 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STDDEV");
    std::string s_param;
    if((yyvsp[-3].node)) {s_param += "DISTINCT "; delete((yyvsp[-3].node));}
    Node * param = Node::makeTerminalNode(E_STRING, s_param + (yyvsp[-2].node)->text());  delete((yyvsp[-2].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, param, NULL, NULL, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10627 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 687:
#line 3298 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "VARIANCE");
    std::string s_param;
    if((yyvsp[-3].node)) { s_param += "DISTINCT "; delete((yyvsp[-3].node)); }
    Node * param = Node::makeTerminalNode(E_STRING, s_param + (yyvsp[-2].node)->text());  delete((yyvsp[-2].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, param, NULL, NULL,  (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10641 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 688:
#line 3308 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STARTS_WITH");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10652 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 689:
#line 3315 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ENDS_WITH");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10663 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 690:
#line 3322 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_CONTAINS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10674 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 691:
#line 3329 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_EXTRACT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-3].node), (yyvsp[-1].node), NULL, NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10685 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;

  case 692:
#line 3336 "bigquery.y" /* yacc.c:1646  */
    {
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_REPLACE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), NULL);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 10696 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
    break;


#line 10700 "sqlparser_bigquery_bison.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 3346 "bigquery.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/


