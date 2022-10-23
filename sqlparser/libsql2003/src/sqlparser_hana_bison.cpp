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
#define YYSTYPE         HANA_STYPE
#define YYLTYPE         HANA_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hana_parse
#define yylex           hana_lex
#define yyerror         hana_error
#define yydebug         hana_debug
#define yynerrs         hana_nerrs


/* Copy the first part of user declarations.  */
#line 1 "sqlparser_hana.yacc" /* yacc.c:339  */

/**
 * This Grammar is designed for hana.
 * https://github.com/Raphael2017/SQL/blob/master/sql-2003-2.bnf
 * sqlparser.y
 * defines sqlparser_hana_bison.h
 * outputs sqlparser_hana_bison.cpp
 *
 * Bison Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "sqlparser_hana_bison.h"
#include "sqlparser_hana_flex.h"
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

#define YYSTYPE         HANA_STYPE
#define YYLTYPE         HANA_LTYPE


#line 113 "sqlparser_hana_bison.cpp" /* yacc.c:339  */

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
   by #include "sqlparser_hana_bison.h".  */
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
#line 45 "sqlparser_hana.yacc" /* yacc.c:355  */

// %code requires block

#include "node.h"

#line 157 "sqlparser_hana_bison.cpp" /* yacc.c:355  */

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
#line 88 "sqlparser_hana.yacc" /* yacc.c:355  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 453 "sqlparser_hana_bison.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 483 "sqlparser_hana_bison.cpp" /* yacc.c:358  */

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
         || (defined HANA_LTYPE_IS_TRIVIAL && HANA_LTYPE_IS_TRIVIAL \
             && defined HANA_STYPE_IS_TRIVIAL && HANA_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  218
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   16219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  294
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  231
/* YYNRULES -- Number of rules.  */
#define YYNRULES  754
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1343

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   532

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   290,     2,     2,     2,   293,     2,     2,
      12,    13,   283,   288,   282,   289,    14,   292,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   286,   281,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   284,     2,   285,   287,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   291,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280
};

#if HANA_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   274,   274,   285,   286,   294,   295,   296,   297,   298,
     302,   309,   314,   319,   327,   328,   336,   341,   349,   350,
     354,   358,   362,   363,   364,   365,   366,   370,   371,   375,
     376,   380,   381,   385,   392,   399,   408,   417,   426,   435,
     447,   456,   469,   486,   503,   506,   537,   538,   546,   555,
     566,   580,   595,   596,   623,   650,   680,   681,   711,   712,
     730,   737,   740,   743,   745,   748,   777,   778,   787,   794,
     795,   798,   799,   807,   808,   816,   817,   818,   832,   833,
     840,   852,   853,   856,   857,   864,   865,   866,   869,   884,
     885,   888,   889,   890,   891,   894,   903,   906,   907,   910,
     911,   912,   915,   916,   917,   918,   955,   958,   962,   969,
     970,   980,   985,   993,   994,  1003,  1011,  1012,  1016,  1024,
    1025,  1032,  1039,  1040,  1047,  1048,  1052,  1059,  1060,  1068,
    1082,  1086,  1090,  1096,  1102,  1111,  1112,  1121,  1122,  1123,
    1127,  1128,  1139,  1144,  1149,  1154,  1159,  1164,  1169,  1177,
    1182,  1190,  1195,  1202,  1203,  1210,  1215,  1222,  1223,  1224,
    1225,  1226,  1227,  1228,  1231,  1232,  1236,  1237,  1241,  1242,
    1243,  1244,  1245,  1250,  1256,  1265,  1270,  1274,  1279,  1313,
    1319,  1325,  1331,  1337,  1343,  1349,  1355,  1361,  1371,  1376,
    1381,  1386,  1391,  1396,  1401,  1406,  1411,  1419,  1424,  1429,
    1434,  1445,  1446,  1451,  1456,  1462,  1482,  1489,  1490,  1497,
    1504,  1511,  1518,  1519,  1527,  1553,  1566,  1579,  1593,  1605,
    1606,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1623,  1631,  1632,  1640,  1649,  1650,  1658,  1659,  1667,
    1668,  1676,  1677,  1682,  1690,  1691,  1708,  1709,  1710,  1711,
    1712,  1714,  1715,  1716,  1717,  1720,  1725,  1732,  1737,  1744,
    1751,  1760,  1761,  1768,  1771,  1772,  1778,  1779,  1785,  1786,
    1794,  1795,  1801,  1807,  1814,  1820,  1828,  1829,  1837,  1842,
    1847,  1857,  1862,  1870,  1875,  1880,  1885,  1893,  1898,  1906,
    1911,  1919,  1928,  1929,  1934,  1942,  1943,  1951,  1952,  1960,
    1961,  1969,  1970,  1975,  1983,  1984,  1985,  1986,  1987,  1988,
    1991,  1998,  1999,  2007,  2008,  2013,  2014,  2017,  2017,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,  2034,
    2035,  2040,  2047,  2048,  2052,  2053,  2054,  2058,  2059,  2060,
    2061,  2062,  2066,  2067,  2068,  2069,  2074,  2082,  2083,  2087,
    2088,  2096,  2101,  2109,  2110,  2119,  2120,  2121,  2122,  2123,
    2127,  2128,  2129,  2134,  2142,  2150,  2157,  2163,  2173,  2174,
    2175,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,
    2185,  2189,  2196,  2203,  2211,  2218,  2225,  2232,  2239,  2240,
    2250,  2260,  2267,  2280,  2291,  2300,  2301,  2302,  2306,  2314,
    2315,  2319,  2326,  2327,  2334,  2343,  2349,  2359,  2360,  2361,
    2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2373,  2374,
    2377,  2381,  2390,  2395,  2399,  2407,  2408,  2410,  2419,  2420,
    2425,  2426,  2435,  2436,  2440,  2441,  2445,  2446,  2447,  2451,
    2455,  2460,  2461,  2462,  2466,  2470,  2471,  2472,  2473,  2474,
    2478,  2484,  2494,  2495,  2503,  2504,  2507,  2512,  2523,  2529,
    2536,  2543,  2553,  2560,  2569,  2576,  2583,  2590,  2597,  2606,
    2613,  2622,  2629,  2637,  2638,  2645,  2646,  2653,  2654,  2661,
    2670,  2671,  2678,  2685,  2686,  2687,  2688,  2689,  2690,  2691,
    2692,  2693,  2694,  2695,  2696,  2697,  2698,  2699,  2700,  2701,
    2702,  2703,  2704,  2705,  2706,  2707,  2708,  2709,  2710,  2711,
    2712,  2713,  2714,  2715,  2718,  2719,  2720,  2726,  2730,  2734,
    2738,  2742,  2746,  2756,  2757,  2758,  2762,  2763,  2767,  2768,
    2772,  2777,  2786,  2787,  2788,  2789,  2790,  2791,  2792,  2793,
    2794,  2795,  2796,  2797,  2798,  2799,  2800,  2801,  2802,  2803,
    2804,  2805,  2806,  2807,  2808,  2809,  2810,  2811,  2812,  2813,
    2817,  2818,  2822,  2823,  2824,  2825,  2826,  2827,  2828,  2829,
    2830,  2831,  2832,  2833,  2834,  2835,  2836,  2837,  2838,  2839,
    2840,  2841,  2842,  2843,  2844,  2845,  2846,  2847,  2848,  2849,
    2850,  2851,  2852,  2853,  2854,  2855,  2856,  2857,  2858,  2859,
    2860,  2861,  2862,  2863,  2864,  2865,  2866,  2867,  2868,  2869,
    2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,  2878,  2879,
    2880,  2881,  2882,  2883,  2884,  2885,  2886,  2887,  2890,  2891,
    2892,  2893,  2894,  2895,  2896,  2897,  2898,  2899,  2900,  2901,
    2902,  2903,  2904,  2905,  2906,  2908,  2909,  2910,  2911,  2912,
    2913,  2914,  2917,  2918,  2919,  2920,  2921,  2922,  2923,  2924,
    2925,  2926,  2927,  2928,  2929,  2930,  2931,  2932,  2933,  2934,
    2935,  2936,  2937,  2938,  2942,  2943,  2948,  2973,  2974,  2978,
    2981,  2986,  2987,  2988,  2992,  2993,  3001,  3002,  3005,  3006,
    3007,  3015,  3016,  3021,  3029,  3030,  3038,  3039,  3046,  3047,
    3050,  3051,  3059,  3060,  3071,  3082,  3098,  3099,  3108,  3115,
    3120,  3126,  3133,  3138,  3144,  3151,  3152,  3153,  3156,  3163,
    3171,  3179,  3186,  3194,  3195,  3202,  3208,  3214,  3223,  3224,
    3226,  3227,  3230,  3243,  3249,  3255,  3261,  3267,  3275,  3310,
    3311,  3312,  3315,  3316,  3322,  3323,  3329,  3330,  3336,  3337,
    3342,  3345,  3346,  3353,  3354
};
#endif

#if HANA_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "NULLX", "UNKNOWN", "QUESTIONMARK", "UMINUS", "'('", "')'",
  "'.'", "ALL", "AND", "ANY", "ARRAY", "AS", "ASC", "AVG", "BETWEEN",
  "BIGINT", "BINARY", "BLOB", "BOOLEAN", "BY", "CALL", "CASE", "CAST",
  "CHAR", "CHARACTER", "CHARACTERS", "CLOB", "CNNOP", "COALESCE",
  "CODE_UNITS", "COLLATE", "COMP_EQ", "COMP_GE", "COMP_GT", "COMP_LE",
  "COMP_LT", "COMP_NE", "CONVERT", "CORRESPONDING", "COUNT", "CROSS",
  "CUME_DIST", "CURRENT", "CURRENT_TIMESTAMP", "CURRENT_USER", "DATE",
  "DAY", "DEC", "DECIMAL", "DEFAULT", "DELETE", "DENSE_RANK", "DESC",
  "DISTINCT", "DOUBLE", "ELSE", "END", "END_P", "ESCAPE", "ERROR",
  "EXCEPT", "EXCLUDE", "EXISTS", "FLOAT", "FOLLOWING", "FOR", "FROM",
  "FULL", "G", "GROUP", "GROUPING", "HAVING", "HOUR", "IN", "INNER",
  "INSERT", "INT", "INTEGER", "INTERSECT", "INTERVAL", "MANY", "ONE",
  "EXACT", "INTO", "IS", "JOIN", "K", "LARGE", "LEFT", "LIKE", "M", "MAX",
  "MIN", "MINUTE", "MOD", "MONTH", "MULTISET", "NATIONAL", "NATURAL",
  "NCHAR", "NCLOB", "NO", "NOT", "NULLIF", "OBJECT", "OCTETS", "OF", "ON",
  "ONLY", "OR", "ORDER", "OTHERS", "OUTER", "OVER", "PARTITION",
  "PERCENT_RANK", "PRECEDING", "PRECISION", "RANGE", "RANK", "READ",
  "REAL", "RECURSIVE", "REF", "RIGHT", "ROW", "ROWS", "ROW_NUMBER",
  "SCOPE", "SECOND", "SELECT", "SESSION_USER", "SET", "SETS", "SMALLINT",
  "SOME", "STDDEV_POP", "STDDEV_SAMP", "SUM", "SYSTEM_USER", "THEN",
  "TIES", "TIME", "TIMESTAMP", "TO", "UNBOUNDED", "UNION", "UPDATE",
  "USING", "VALUES", "VARCHAR", "NVARCHAR", "VARYING", "VAR_POP",
  "VAR_SAMP", "WHEN", "WHERE", "WITH", "WITHOUT", "YEAR", "ZONE", "LIMIT",
  "OFFSET", "TOP", "WAIT", "NOWAIT", "HINT", "RANGE_RESTRICTION",
  "PARAMETERS", "UPSERT", "REPLACE", "PRIMARY", "KEY", "CONTAINS",
  "P_POINT", "SECONDDATE", "TINYINT", "SMALLDECIMAL", "TEXT", "BINTEXT",
  "ALPHANUM", "VARBINARY", "SHORTTEXT", "ORDINALITY", "UNNEST", "HISTORY",
  "OVERRIDING", "USER", "SYSTEM", "VALUE", "NULLS", "FIRST", "LAST",
  "CORR", "CORR_SPEARMAN", "MEDIAN", "STDDEV", "VAR", "STRING_AGG",
  "MEMBER", "SYSTEM_TIME", "APPLICATION_TIME", "TABLESAMPLE", "BERNOULLI",
  "RETURN", "LATERAL", "BINNING", "LAG", "LEAD", "RANDOM_PARTITION",
  "WEIGHTED_AVG", "EXTRACT", "FIRST_VALUE", "LAST_VALUE", "NTH_VALUE",
  "NTILE", "SERIES_FILTER", "LOCATE_REGEXPR", "OCCURRENCES_REGEXPR",
  "REPLACE_REGEXPR", "SUBSTRING_REGEXPR", "SUBSTR_REGEXPR",
  "PERCENTILE_CONT", "PERCENTILE_DISC", "TRIM", "WITHIN",
  "CUBIC_SPLINE_APPROX", "LINEAR_APPROX", "ROLLUP", "CUBE", "BEST",
  "SUBTOTAL", "BALANCE", "TOTAL", "MULTIPLE", "RESULTSETS", "PREFIX",
  "STRUCTURED", "RESULT", "OVERVIEW", "TEXT_FILTER", "FILL", "UP",
  "MATCHES", "SORT", "MINUS", "ROWCOUNT", "LOCKED", "IGNORE", "SHARE",
  "LOCK", "UTCTIMESTAMP", "COMMIT", "ID", "XML", "JSON", "RETURNS",
  "SERIES", "TABLE", "LIKE_REGEXPR", "FLAG", "LEADING", "TRAILING", "BOTH",
  "WEIGHT", "FULLTEXT", "LANGUAGE", "LINGUISTIC", "FUZZY", "PORTION",
  "START", "AFTER", "OCCURRENCE", "';'", "','", "'*'", "'['", "']'", "':'",
  "'^'", "'+'", "'-'", "'!'", "'|'", "'/'", "'%'", "$accept", "sql_stmt",
  "stmt_list", "stmt", "special_stmt", "call_stmt", "sql_argument_list",
  "sql_argument", "value_expression", "sp_name", "dql_stmt", "dml_stmt",
  "opt_partition_rest", "opt_column_ref_list_with_parens",
  "overriding_value", "insert_stmt", "from_constructor", "delete_stmt",
  "update_stmt", "delete_table", "update_table", "update_elem_list",
  "update_elem", "select_stmt", "query_expression",
  "query_expression_body", "query_term", "query_primary",
  "select_with_parens", "subquery", "sap_table_subquery", "table_subquery",
  "row_subquery", "simple_table", "opt_where", "from_clause",
  "opt_from_clause", "opt_groupby", "grouping_element_list",
  "grouping_element", "row_order_by_list", "row_order_by",
  "column_ref_perens", "group_set_name", "grouping_option",
  "grouping_best", "grouping_subtotal", "grouping_prefix_tb",
  "grouping_prefix", "grouping_structured_res", "grouping_text_filter",
  "opt_asc_desc", "opt_having", "with_clause", "with_list",
  "common_table_expr", "opt_derived_column_list",
  "simple_ident_list_with_parens", "simple_ident_list",
  "column_ref_list_with_parens", "column_ref_list", "opt_distinct",
  "select_expr_list", "projection", "asterisk_expr", "from_list",
  "table_reference", "table_primary", "table_primary_non_join",
  "lateral_table", "associated_table", "associated_ref_list",
  "associated_ref", "opt_many2one_part", "opt_search_condition",
  "opt_tablesample", "opt_table_qualify", "collection_derived_table",
  "collection_value_expr_list", "collection_value_expr", "column_ref",
  "relation_factor", "func_relation_factor", "joined_table",
  "qualified_join", "case_join", "case_join_when_list", "case_join_when",
  "ret_join_on", "select_expr_list_parens", "opt_case_join_else",
  "cross_join", "join_type", "join_outer", "join_cardinality",
  "hana_construct_table", "construct_column_list", "construct_column",
  "search_condition", "boolean_term", "boolean_factor", "boolean_test",
  "boolean_primary", "predicate", "like_regexpr_redicate",
  "member_of_predicate", "bool_function", "contains_param3", "search_type",
  "search_param_list", "search_param", "expr_const_list",
  "comparison_predicate", "between_predicate", "like_predicate",
  "in_predicate", "null_predicate", "exists_predicate", "row_expr",
  "factor0", "factor1", "factor2", "factor3", "factor4",
  "row_expr_list_parens", "row_expr_list", "row_expr_star", "in_expr",
  "truth_value", "comp_op", "cnn_op", "comp_all_some_any_op",
  "plus_minus_op", "star_div_percent_mod_op", "expr_const",
  "expr_const_string", "case_expr", "case_arg", "when_clause_list",
  "when_clause", "case_default", "func_expr", "opt_nulls",
  "aggregate_expression", "aggregate_name", "sap_specific_function",
  "trim_char", "within_group", "opt_order_by_clause", "order_by_clause",
  "order_by_expression_list", "order_by_expression",
  "ranking_windowed_function", "ranking_function_name", "opt_over_clause",
  "over_clause", "window_specification", "window_name",
  "window_specification_details", "opt_existing_window_name",
  "opt_window_partition_clause", "opt_window_frame_clause",
  "window_frame_units", "window_frame_extent", "window_frame_start",
  "window_frame_preceding", "window_frame_between", "window_frame_bound",
  "window_frame_following", "opt_window_frame_exclusion",
  "scalar_function", "table_function_param_list", "table_function_param",
  "expr_point_val", "function_call_keyword", "for_xml", "for_json",
  "opt_returns_clause", "opt_option_string_list_p", "option_string_list",
  "option_string", "data_type", "array_type", "predefined_type",
  "lob_data_type", "primary_datetime_field", "all_some_any",
  "opt_as_label", "as_label", "label", "collate_clause", "name_r",
  "name_f", "reserved", "top_clause", "opt_for_update", "for_share_lock",
  "for_update", "opt_of_ident_list", "opt_ignore_lock", "wait_nowait",
  "limit_num", "offset_num", "limit_total", "with_hint_param",
  "with_hint_param_list", "hint_clause", "opt_with_range_restrict",
  "with_primary_key", "upsert_stmt", "replace_stmt", "for_system_time",
  "sys_as_of_spec", "sys_from_to_spec", "sys_between_spec",
  "for_application_time", "partition_restriction", "intnum_list",
  "tablesample_num", "opt_partition_restriction",
  "opt_for_application_time_clause", "for_application_time_clause",
  "regexpr_str_function", "regex_parameter", "opt_st_or_af", "opt_flag",
  "opt_with_string", "opt_from_position", "opt_occurrence_num",
  "opt_group_num", "param_num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    40,    41,    46,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
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
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,    59,    44,    42,    91,    93,    58,    94,    43,    45,
      33,   124,    47,    37
};
# endif

#define YYPACT_NINF -1058

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1058)))

#define YYTABLE_NINF -562

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     445,   105,  8578,    60,    64,   -26,   177,   -26, 14620,  8578,
    8578,   230,   135,   -32, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058,    68,   174, -1058, -1058,   118, -1058, -1058,
     256, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, 14884,    83, -1058,
   -1058, -1058, -1058,   259, -1058,  8578,   203,  8578,   169,   120,
     281,  8578, 14884,    12, -1058,   340,   134,   134, -1058, -1058,
     445,   120,   271,   120,   120,   198, -1058,   120,    68, -1058,
   -1058,  3175,   377, -1058, 11045,   211, -1058,   273,  8578,   273,
   -1058, -1058, -1058, -1058,  5471, -1058,   278,    12, 14884, 14884,
     405, -1058, 10491, -1058,   282, -1058,   282, -1058,   118,  7193,
     118,   118,   275,   374,   118,   198,   438, -1058, -1058, -1058,
   -1058, -1058, -1058,  2888,   294,  7193,   453,   458,   462,   496,
     499,   501, -1058,   459,   507,   509,  4323,   515,   525, -1058,
   -1058,   527,   534,   536,   563,   565,   570,   572,   577,   584,
     592,   604,   609,   612,   623,   626,   629,   633,   636,  7193,
    7193,    23, -1058,   634, -1058, -1058, -1058, -1058,   642,   538,
     640, -1058, -1058,   566, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058,  1081,   200,    55,   375, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058,   651, -1058, -1058,   655,
   -1058, -1058,   657,   661, -1058,   659, -1058,   664,   665,   666,
   11322,   670,  4323,   294,   674, -1058, 11586,   211, 10214, -1058,
    4610, -1058,   -24, -1058, -1058,  2611,   673,  7193, -1058,    25,
   -1058,   507,  7193,   139,   331,   174,    71,   406, -1058,   174,
     174,   520,   520,   205, -1058, -1058,   294, -1058, -1058, -1058,
     374,  2888,   678,   107,  1081,    35, -1058,   173,   529,  7193,
     690,  7193,  7193,  4897,   694, -1058,   105, -1058, -1058,  7193,
   -1058,  1081,  7193,  5758, -1058,  6045,  7193,  7193,   114,  7193,
    7193,  7193,  7193,  7193,   238,   697,   697,   697,   697,   607,
     607,  7480, -1058, -1058,   294,  4323,  1210,  6332,  4323,  4323,
     147,  7193, -1058,  8578, -1058, -1058,   663, -1058,   199, -1058,
     695,    74,  7193,   209,   594,  7193,   667,   418,  5184,  7193,
     695, -1058, -1058, -1058,  7193, -1058, -1058, -1058,  7193,  7193,
     120,  6619,  7193, 11863,  9660,   706,   709, 14884,   700, 12140,
     538, -1058,   711, 14884,   644, -1058, -1058, -1058,   294, 10491,
     344,   282,   105, -1058,   105,   136,  4610,   173,  8037,  5471,
     211, -1058,  8855,   -18, -1058,    80, -1058, 14884, -1058,   440,
     544, -1058,   559,   546, -1058, -1058, -1058,   531,  7193,   721,
     487,   487,   617,   477,   724,   724, -1058,   294,   726, -1058,
   -1058, -1058,  7193,  4323,   102, -1058,    62,   728,    46,   119,
    7193,   729,    27,   730,    50,   158, -1058,    58, -1058,   173,
     464,   -28,   173,    67, -1058, -1058,   100,   675,   123,   123,
     -28,    90,    92, -1058, -1058,   697,   479,   731,   738,   739,
     740,   459,   527,   741,   742,   752,   753,   759,    22,   760,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058,   754, -1058,   755,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058,   756,   757, -1058,
   -1058, -1058, -1058, -1058,   758,   761,   762, -1058, -1058,   763,
   -1058, -1058,    94,   640, -1058, -1058, -1058,   318, -1058,    54,
   -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,   764,   163,
    7193,   695,  7193,   662,  7193,   164, -1058, -1058, -1058,   767,
   -1058,   173, -1058,   200, -1058, -1058,    55,   375, -1058,  7193,
     650,    97,    28, 12417,   766, -1058,   424, -1058,   768, -1058,
      98,   770,   746, -1058, 14884, 14884,   773, -1058,    99, -1058,
     511, -1058, -1058, -1058,   108, -1058,   775,   593,   595,   294,
   -1058, -1058,   282, -1058,   105,   772,  7760,   781,   782, 11586,
   -1058,   516,   652, -1058, -1058, 11586, 11586, 11586,    11, -1058,
   -1058, -1058, -1058, 11586,   785, -1058,   723, -1058,   790,  7193,
   -1058,   211,  7193, -1058,   632,   631, -1058,   637,   355, -1058,
   -1058, -1058,   560, -1058, -1058, 14884,   407, -1058,   809,   552,
     552, -1058,   404,   173,    15,   361,  7193, -1058,   769,  1210,
   -1058, -1058,  8578,   109,   650, -1058, -1058,  7193,  7193, -1058,
     172,   805,   650,  7193,  9937,  7193,   806,   810,   811,   650,
     650,   812,   818,   745, -1058, -1058, -1058, -1058,   597,   597,
   -1058,  7193,   771,   830,   831,   832,   835,   836,   838,   841,
   -1058, -1058, -1058,  7193, -1058,  7193,    63, -1058,   178,  7193,
     173,   846,    29, 12694, -1058,   650, -1058, 14884,   844, 12971,
   15148,   294,  9660,   294,   848, -1058, -1058, 14884, -1058,   854,
     748, -1058, 14884, 13248, -1058, -1058, -1058,   294, -1058, 14884,
    7760,   652,   850, 15412, 10768,   340,  8037,   774,   744,   471,
    8037,   744,   744,   133, -1058, -1058,   340,   267,  4323, 14884,
   11586, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058, 13525,
     839,   786,  9132, -1058,   294,   173, -1058,   856, -1058, -1058,
   -1058, -1058,   588,   864, -1058,   615,   833,   112, -1058,  1210,
   -1058, -1058,  7193,  7193,   173, -1058,   860,   861, -1058, -1058,
   -1058,    34,    38,   115, -1058, -1058, -1058, -1058, -1058,    39,
     650,   650,   650, -1058, -1058, -1058, -1058,  7193,   798,   650,
     650,    40,  7193,   116,   863,   865,   866,   868,   869,   870,
     173,   173,  7193,  7193,   173, -1058,   650, 15676, -1058, -1058,
   -1058, -1058,   871, 14884, 14884,   875, -1058,   876, -1058, -1058,
   -1058,   878, -1058, -1058,   683, -1058,   879, -1058,   872, -1058,
     884,   124, -1058, -1058,   886,   887, -1058,   652,  8314, -1058,
     471,   776,   777,   808, -1058,   430,   471,   471,   813,  8037,
   -1058, -1058,   145,   885,   -23,   891, -1058,   624,   699,   896,
     120,  4323, -1058, -1058,   897, -1058,   908, -1058,   658, -1058,
     910, -1058,   809, -1058,   173,   173, -1058, -1058, -1058, -1058,
   -1058,   226, -1058, -1058, -1058, -1058,   137,   906, -1058, -1058,
   -1058,    48, -1058,   914, -1058, -1058, -1058, -1058, -1058, -1058,
     173,   173, -1058,   654, -1058,   911,   801, 14884,   912,   916,
   15148, 15148,   294,   862, 13802, 14884,  7193,   778, 15412, -1058,
   -1058, -1058, -1058,   476,   482,   783,  4323, -1058, -1058,   779,
     550,   820,   933,   934,   825,   660, 14884,  4323,    56, -1058,
   -1058, 14079,  3462,   538,  9396,   927, -1058, -1058, -1058,   929,
     935,   937,   938,   939,   940,   941,   329,   671, -1058,   951,
     883,   842, -1058,   948,  8578, -1058,   936,   842, -1058, 14884,
   14884,   950, -1058,   952, -1058,   961,   954,   125, -1058,  1210,
     126,   780, -1058, -1058, -1058,   880, -1058, -1058,   881,   530,
     538,  4323,   103, -1058,  4323,   968,   957,   822,   971, 14884,
   -1058,   821,   538,   973,   964,   967,   966,  3749,   840, -1058,
   -1058,   701, -1058,   747,   173, -1058, -1058,   978,   607,   113,
     982,   983,  7193, -1058,   671,   329, -1058,   286,   712,   976,
   -1058, -1058,  7193,    26, -1058, -1058, 14884, 15940,   843, 14884,
   -1058, 14884, -1058, -1058, -1058, -1058, -1058, -1058, -1058,   904,
      75,   784, -1058,   930,   538, -1058,   993,   995, -1058,   891,
      81,   715,   988,   997,  1000, 15148, -1058, -1058,  3462,  1001,
     996,   198,   994,   127, -1058,   999,  1003,  1005,  1006,   129,
   -1058, -1058, -1058, -1058,   451,   932, -1058,   440, -1058, -1058,
   -1058,   528, -1058, -1058, -1058,  1016, -1058, -1058,   784,  1010,
   -1058, -1058, -1058, -1058,   874,   882,   455, -1058, -1058,  1011,
    1014, -1058, -1058, 14356,   858, -1058, -1058,   607, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058,   286, -1058,   587,   902,   913,
     915,   969, -1058, -1058, -1058, -1058, -1058,  5471,   970,   498,
     519,   949,   953, -1058, -1058,  6906,   130, -1058, -1058, -1058,
   -1058,   390,   793, -1058, -1058,   165,   187, -1058,  1029, -1058,
   -1058, -1058, -1058,   371, -1058,   131,  8037,   955,   956,   958,
     959, -1058, -1058,  4036, -1058,   842,    86, -1058, 14356, -1058,
   -1058, -1058,  1043,    91, -1058, -1058,   587,   917, -1058,   942,
   -1058, -1058,   551, -1058, -1058, -1058, -1058,  1040, -1058,   807,
     814,   817, -1058,   816, -1058, -1058, -1058,  4323, -1058,   815,
   -1058,   890,  1054, -1058,   538,   819,   826, -1058,   823, -1058,
     920,   895, -1058
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     0,     0,     0,   674,     0,   674,     0,     0,
       0,     0,     0,     3,     9,     8,     6,     7,    24,    23,
      22,    21,    49,   399,    52,    56,    58,     0,    25,    26,
       0,   532,   559,   566,   598,   374,   669,   567,   568,   542,
     569,   599,   570,   600,   571,   553,   410,   664,   519,   672,
     671,   602,   408,   593,   604,   597,   666,   572,   565,   520,
     665,   668,   573,   606,   607,   625,   563,   574,   564,   372,
     370,   521,   605,   518,   575,   627,   601,   576,   577,   589,
     578,   596,   409,   579,   580,   407,   590,   673,   581,   582,
     583,   411,   584,   522,   595,   667,   377,   379,   373,   594,
     592,   591,   603,   585,   586,   670,   378,   380,   587,   517,
     588,   619,   618,   608,   609,   543,   610,   611,   612,   613,
     614,   615,   616,   617,   654,   620,   621,   623,   622,   624,
     659,   660,   368,   369,   371,   375,   376,   541,   626,   544,
     412,   413,   414,   415,   545,   546,   547,   548,   549,   536,
     537,   538,   539,   540,   550,   551,   552,   416,   417,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   651,   650,   652,   653,   655,   656,   657,   658,   554,
     555,   556,   557,   558,   661,   662,   663,     0,   702,    20,
     534,   535,   562,   188,   533,     0,     0,     0,     0,   124,
       0,     0,   581,   111,   113,   116,   116,   116,     1,     2,
       5,   124,     0,   124,   124,   691,   400,   124,   399,    59,
     196,     0,     0,    13,     0,    66,    44,   728,     0,    27,
     675,   676,   125,   126,     0,    10,     0,   112,     0,     0,
       0,   117,     0,   711,     0,   714,     0,     4,     0,     0,
       0,     0,     0,   677,     0,   691,   532,   342,   339,   337,
     340,   338,   343,     0,   702,   347,   568,   542,   599,   600,
     553,   465,   467,   664,     0,     0,     0,   601,     0,   469,
     470,   591,   543,   541,   544,   545,   546,   547,   548,   549,
       0,   536,   537,   538,   539,   540,   550,   551,   552,     0,
       0,     0,    14,    16,    61,    64,   306,   304,     0,    18,
     235,   237,   239,   241,   244,   254,   253,   252,   246,   247,
     249,   248,   250,   251,    19,   292,   295,   297,   299,   301,
     307,   305,   341,   308,   309,   358,   534,   359,   357,   535,
     356,   355,   562,   179,   197,   533,   388,     0,     0,     0,
       0,   189,     0,   702,     0,   729,   526,    66,    29,    28,
       0,   131,     0,   127,   130,   526,   179,     0,   114,     0,
     119,     0,     0,    66,    66,    54,   106,   401,   402,    53,
      55,   694,   694,     0,   682,   683,   702,   681,   678,    57,
     677,     0,     0,     0,   311,     0,    12,   348,     0,     0,
       0,     0,     0,     0,     0,   344,     0,    63,   291,     0,
     240,     0,     0,     0,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   739,     0,     0,     0,     0,     0,
       0,     0,   302,   303,   702,     0,     0,     0,     0,     0,
       0,     0,   329,     0,   323,   321,   322,   319,   320,   324,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   332,   333,     0,   334,   335,   336,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   191,     0,
      67,    41,     0,     0,   730,   527,   529,   530,   702,     0,
     621,     0,     0,    34,    30,    29,     0,   311,     0,     0,
      66,   129,     0,    69,    46,     0,   118,     0,   115,    40,
       0,   709,   706,     0,   712,   107,   108,   360,     0,     0,
     696,   696,   684,     0,   475,   475,    50,   702,     0,    60,
     245,   310,     0,     0,   353,   349,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,     0,   314,   313,
       0,   399,   455,     0,   452,   454,   179,     0,   399,   399,
     399,     0,     0,   740,   741,     0,   742,     0,     0,     0,
       0,     0,     0,     0,     0,   656,   657,   658,     0,     0,
      11,    15,   491,   514,   512,   515,   483,   507,   494,   510,
     490,   489,   516,   493,   488,   484,   486,   497,   499,   485,
     487,   492,   495,   496,   501,   503,   505,    17,   481,   480,
     513,   450,     0,   236,   238,   317,   318,     0,   242,     0,
     531,   325,   326,   327,   315,   316,   287,   289,     0,   283,
       0,     0,     0,     0,     0,   256,   328,   330,   523,   559,
     524,   280,   331,   294,   278,   279,   296,   298,   300,     0,
       0,     0,     0,     0,   180,   198,   698,   699,     0,   700,
       0,     0,     0,   195,     0,     0,   190,   723,     0,   528,
       0,    45,   731,    42,     0,   122,   179,     0,     0,   702,
      37,    36,     0,    33,    30,     0,     0,     0,     0,   526,
      62,    68,   135,   137,   140,   526,   526,     0,   168,   138,
     201,   202,   139,   526,   188,   128,    71,   132,   180,     0,
      70,    66,     0,   120,     0,     0,   710,     0,     0,   404,
     403,   695,     0,   692,   693,     0,   688,   679,     0,   473,
     473,    51,    60,   312,     0,     0,     0,   350,     0,     0,
     367,   464,     0,     0,   418,   365,   466,     0,     0,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,   735,   736,   737,     0,     0,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,   451,   243,     0,   290,     0,     0,   288,   285,     0,
     258,     0,     0,     0,   405,     0,   458,     0,     0,     0,
       0,   702,     0,   702,     0,   193,   194,     0,   722,     0,
       0,   121,     0,     0,    32,    31,    39,   702,    35,     0,
       0,     0,   138,     0,     0,   116,     0,     0,   219,   221,
       0,   219,   219,     0,   148,   145,   147,     0,     0,     0,
     526,   172,   169,   715,   716,   717,   170,   171,   144,     0,
       0,   109,     0,    47,   702,    48,   708,     0,   713,   361,
     362,   697,   685,     0,   689,   686,     0,     0,   477,     0,
     471,   472,     0,     0,   354,   346,     0,     0,   364,   363,
     419,     0,     0,     0,   391,   381,   453,   457,   456,     0,
     418,   418,   418,   387,   382,   733,   743,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     281,   284,     0,     0,   257,   255,   418,   425,   421,   420,
     423,   406,     0,     0,     0,   181,   199,     0,   703,   701,
     704,     0,   192,   724,     0,   123,   180,    38,     0,   141,
     566,     0,   176,   178,     0,     0,   143,   136,     0,   220,
     221,     0,     0,     0,   218,     0,   221,   221,     0,     0,
     205,   146,     0,     0,     0,   152,   153,   156,   166,   189,
     124,     0,    65,   133,   181,    43,     0,   690,     0,   680,
       0,   476,     0,   474,   351,   352,   462,   463,   461,   468,
     260,     0,   383,   384,   385,   386,   744,     0,   389,   390,
     393,     0,   508,     0,   511,   498,   500,   502,   504,   506,
     282,   286,   366,   652,   426,     0,   428,     0,   183,     0,
       0,     0,   702,     0,     0,     0,     0,   174,     0,   150,
     149,   214,   215,     0,     0,     0,     0,   216,   217,     0,
       0,     0,     0,     0,     0,     0,     0,   164,     0,   142,
     167,     0,     0,   110,     0,     0,   687,   479,   478,   264,
       0,     0,     0,   268,   266,     0,   261,   263,   270,     0,
     746,     0,   392,     0,     0,   422,     0,   399,   187,     0,
       0,   182,   200,     0,   705,     0,   181,     0,   232,     0,
       0,     0,   175,   222,   223,     0,   225,   227,     0,     0,
     204,     0,   212,   207,     0,     0,     0,     0,     0,     0,
     154,   157,   165,     0,     0,     0,   190,     0,     0,    86,
      87,    72,    73,    89,    76,   134,   707,     0,     0,     0,
       0,     0,     0,   259,   262,     0,   745,     0,   748,     0,
     509,   427,     0,   430,   185,   186,     0,     0,     0,     0,
     231,     0,   234,   177,   173,   224,   229,   226,   228,     0,
       0,     0,   208,     0,   203,   718,     0,     0,   721,   151,
       0,     0,     0,     0,     0,     0,    75,    85,     0,     0,
       0,   691,     0,     0,   276,     0,     0,     0,     0,     0,
     271,   753,   754,   747,     0,   751,   398,   429,   433,   432,
     424,     0,   184,   560,   561,     0,   233,   230,     0,     0,
     213,   206,   720,   719,     0,     0,     0,   155,   727,     0,
       0,    74,    90,     0,    91,   265,   272,     0,   274,   273,
     275,   269,   267,   750,   749,     0,   738,     0,     0,     0,
       0,   445,   434,   438,   435,   732,   209,     0,     0,     0,
       0,     0,     0,   726,   725,     0,     0,    78,    81,    82,
      83,     0,   102,   277,   752,     0,     0,   441,     0,   443,
     437,   436,   439,     0,   431,     0,     0,     0,     0,     0,
       0,   159,   158,     0,    84,   399,   307,    77,     0,    92,
      93,    94,     0,    99,   442,   444,     0,     0,   447,     0,
     448,   211,     0,   161,   160,   163,   162,     0,    79,   103,
       0,     0,    88,    97,   440,   446,   449,     0,    80,     0,
      96,   100,     0,    95,   210,   104,     0,    98,     0,   101,
       0,     0,   105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1058, -1058,   855, -1058, -1058, -1058, -1058,   619, -1058, -1058,
   -1058, -1058, -1058,   574, -1058, -1058,  -246, -1058, -1058,   845,
     857, -1058,   358,  -190,    19,  1053,   183,   828, -1058,  -273,
   -1058,  -254, -1058, -1058,  -339,   568, -1058, -1058, -1058,  -104,
   -1058,  -212,  -176, -1058, -1058, -1058, -1058, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058,   889,   847,  -193,   247, -1058,   589,
     362,  -202,  -161,   590, -1058, -1058,  -490,   144, -1058, -1058,
   -1058,   -13,    51, -1058, -1058, -1058, -1058, -1058, -1058,    72,
    -496,     7, -1058,  -603, -1058, -1058, -1058,    -3,  -107, -1058,
   -1058, -1058, -1058,  -192,  -474, -1058, -1058,   -49,  -260,   680,
    -173, -1058, -1058, -1058, -1058, -1058, -1058, -1058, -1058,    37,
     -27, -1058, -1058, -1058, -1058, -1058, -1058, -1058,  1431,   668,
     656,   648,  -186, -1058,  -456,  -377, -1058,   488,   505, -1058,
   -1058, -1058, -1058, -1058,  -408,   373, -1058, -1058, -1058,   591,
   -1058,  -455, -1058, -1058,   710, -1058, -1058,   357,  -226,    53,
   -1058,   610, -1058,   893,  -592,  -483, -1058,   213, -1058, -1058,
   -1058, -1058, -1058, -1058,   -68, -1058, -1058,  -162, -1058, -1058,
    -475,  -213,   384, -1058, -1058, -1058, -1058,   408,   614, -1058,
     159,   403, -1058,  -836, -1058,   181, -1058,  -336,  -356,   672,
   -1058,    -2,  -425,  1422,  1146,   787, -1058,   447, -1058, -1058,
   -1058,  -264,   788,   625,   346, -1058,  -237, -1058, -1058, -1058,
   -1058, -1058, -1058, -1058, -1058, -1058,  -224, -1058, -1058, -1058,
   -1058, -1058, -1058,  -287, -1058, -1058, -1058, -1058, -1058, -1058,
   -1057
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,   311,   312,   313,   198,
      16,    17,   368,   501,   502,    18,   383,    19,    20,   235,
     236,   513,   514,    21,    22,    23,    24,    25,   314,   315,
     699,   700,   316,    26,   363,   510,   721,   861,  1131,  1132,
    1266,  1267,  1268,  1133,  1190,  1191,  1272,  1322,  1333,  1323,
    1303,   527,   982,    27,   213,   214,   250,   251,   379,   504,
     684,   244,   372,   373,   374,   701,   831,   703,   704,   705,
     706,   975,   976,  1181,  1121,  1059,   850,   707,   951,   952,
     317,   708,   318,   709,   710,   970,  1112,  1113,  1220,  1258,
    1173,   711,   843,   960,   964,   712,  1097,  1098,   319,   320,
     321,   322,   323,   324,   325,   326,   327,  1075,  1076,  1077,
    1078,  1193,   328,   329,   330,   331,   332,   333,   507,   335,
     336,   337,   338,   339,   340,   405,   560,   636,   628,   468,
     469,   470,   474,   478,   341,   342,   343,   408,   544,   545,
     748,   344,   729,   345,   346,   347,   589,   909,   225,   226,
     387,   388,   348,   349,   889,   890,   928,   929,  1025,  1026,
    1087,  1210,  1211,  1251,  1277,  1253,  1254,  1278,  1279,  1284,
     350,   563,   564,   565,   351,   394,   395,   880,   739,   877,
     878,   617,   618,   619,   620,   352,   652,   494,   495,   496,
     471,   353,   354,   355,   209,   396,   397,   398,   736,   989,
     875,   263,   530,   733,   669,   670,   233,   726,   522,    28,
      29,   852,   853,   854,   855,   856,   365,   678,  1060,   366,
     681,   682,   356,   577,   575,   773,  1080,  1148,  1205,  1246,
    1203
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     203,   400,   265,   685,   635,   519,   215,   203,   203,   199,
     384,   417,   505,   403,   655,   369,   216,   217,   702,   258,
      30,   260,   261,   254,   256,   264,   253,   255,   498,   667,
     418,   583,   584,   713,   548,   780,   444,   406,   516,   511,
     755,   806,   926,   993,   521,   524,   557,   998,   541,   561,
     508,   999,  1002,  1010,   570,   571,   508,   452,   665,   751,
     453,  1082,   452,   452,   452,   453,   453,   453,  1123,   452,
     793,   759,   453,   452,   452,   452,   453,   453,   453,   922,
     762,   749,   637,   452,   847,   452,   453,   665,   453,   452,
     222,   525,   453,   832,   448,   231,   781,   452,   452,   -83,
     453,   453,   490,   769,   661,   770,   452,   791,   417,   453,
     805,   811,   818,   420,   483,   452,  1195,     1,   453,   722,
     540,   821,   888,   442,   443,   991,   491,   518,  1000,  1012,
       1,   526,   448,   364,   205,   242,   221,  1037,  1160,  1163,
    1236,   403,  1242,  1297,  1311,   208,   252,  1244,   499,   578,
     579,   580,  1208,   625,   452,   207,   626,   453,   452,   536,
    1209,   453,   968,   882,  1051,   746,  1171,  1052,    48,  1224,
    1225,   716,   452,   753,   240,   453,   267,   804,   503,   241,
     210,   243,   272,   202,   638,   635,   222,   417,  1274,   202,
     202,   202,   448,   452,    59,   230,   453,   654,   452,   452,
     219,   453,   453,   203,   -83,   203,   634,   590,   452,   203,
     215,   453,   237,   452,   239,    71,   453,    73,   237,  1053,
     572,   713,   223,  1218,   448,   581,   969,   832,  1196,   795,
     218,   640,   361,  1226,   622,   417,   203,  1304,   632,   685,
     633,   222,   376,     5,   923,   237,   215,   380,   232,   220,
     380,    93,  1124,   206,   542,   689,     5,   627,   509,  1305,
     227,   683,  1055,  1162,   719,   543,  1111,  1125,   897,   229,
       8,    30,     5,   234,     5,   752,   624,   238,   659,   895,
     391,   109,   764,   744,   245,   392,   903,   904,   771,  1281,
     641,  1201,   402,   658,   248,   848,  1202,   849,   259,     8,
     741,     8,  1079,   362,   520,   445,   642,   517,  1003,  1004,
    1005,  1282,   690,   467,   691,   693,  1069,   542,   467,   467,
     467,   224,   931,   582,   625,   467,   945,   626,   542,   467,
     467,   467,   757,  1320,  1022,   761,  1321,   953,   475,   467,
     542,   467,   766,   767,   768,   467,   957,   476,   477,   763,
     965,   846,   249,   467,   467,   713,   898,   667,   488,   955,
     532,   713,   467,   835,   497,   713,   497,   262,   417,   844,
     845,   467,   542,   497,   763,   362,   763,   858,   202,   542,
     812,   819,   864,   451,   936,   665,   202,   634,   202,   402,
     822,   542,   202,   202,   992,   364,   452,  1001,  1013,   453,
     454,   455,   456,   457,   458,   459,  1038,  1161,   542,  1237,
     467,   542,  1298,   509,   467,   202,   643,   -59,   377,   202,
     538,  1307,   532,   417,   381,   566,  1008,  1009,   467,   202,
     202,   566,   801,   202,   665,   402,  -560,   936,  -532,   382,
     758,   385,   460,   389,   390,   566,   827,   393,  1308,   467,
    -560,   203,   826,   461,   467,   467,  1201,     1,   462,   232,
     630,  1202,   533,   415,   467,   409,  1243,   534,   535,   467,
     410,   463,   -59,     2,   411,   972,   973,   -59,   837,  1050,
    1309,   664,   668,   713,   857,   673,  1042,   676,   472,   473,
     -59,   497,  1047,  1048,   713,   362,   523,   686,  1070,  1071,
    1072,  1073,  1074,     3,   828,   838,   714,   376,   412,   883,
     718,   413,   839,   414,   978,   723,   573,   574,    30,   416,
    1310,   419,   -59,   840,   533,   538,   841,   422,     4,   534,
     535,   424,   267,   268,   269,   270,   271,   423,   272,   687,
     688,   202,   953,  1261,  1262,  1046,   425,   202,   426,   202,
    1247,   357,   358,   359,   869,   870,   202,   417,   -59,   961,
     962,   963,   842,   417,  1103,  1104,  1105,   417,   464,   -59,
    1106,  1107,  1108,   -59,   938,   427,   940,   428,  1248,   873,
     874,   581,   429,     5,   430,     6,  1287,  1288,   974,   431,
     947,   267,   268,   269,   270,   271,   432,   272,   837,   837,
       7,  1070,  1071,  1072,   433,  1092,   936,  1289,  1290,   567,
       8,   267,   268,   269,   270,   271,   434,   272,  1167,  1168,
    1169,   435,     9,    10,   436,   838,   838,   985,   465,  1299,
    1300,  1301,   839,   839,   202,   437,   936,  1248,   438,  1092,
     581,   439,   956,   840,   840,   440,   841,   841,   441,   966,
     967,   466,   467,   446,   447,   448,   449,   -59,   450,  1100,
     581,   808,   479,   480,   202,  1114,  1327,   481,   202,   482,
     202,  -561,   815,   816,   202,   483,   484,   485,   486,   582,
     202,  1249,   842,   842,   489,   417,   492,   512,   528,   202,
     529,   539,   543,   202,   714,   547,   417,   497,   202,   553,
     837,   576,   631,   497,   497,   497,   646,   370,   644,   647,
     671,   497,   200,   672,   674,   402,   677,   680,   200,   200,
     200,  1063,   542,   724,   725,   727,   731,   838,   732,   728,
    1194,   735,  1092,   686,   839,   737,   738,  1269,   582,   742,
    1275,   750,   754,   756,   774,   840,   760,   772,   841,   765,
     203,   775,   776,   777,   778,   779,  -395,  -396,   582,   887,
    1092,   566,   686,  -397,   782,  1199,   783,   784,   785,   786,
     787,   803,   794,   788,   789,  1207,   799,  1270,  1062,  -525,
     809,   790,   810,   813,   842,   814,  1110,   817,   820,   823,
     824,   829,   825,   833,   834,  1094,  1312,  1122,   836,   859,
     860,   930,  1269,  1250,   862,   932,   867,   935,   937,  1296,
     668,   713,   866,   876,   871,   942,   879,   868,   894,   900,
     686,   946,   906,   901,   902,   905,   907,   948,   714,  1273,
     908,   686,   668,   885,   714,   913,   914,   915,   714,  1276,
     916,   917,  1270,   918,   202,   912,   919,   977,   497,   538,
     925,  1170,   941,   954,  1174,   202,   202,   979,   933,   943,
     984,  1153,   944,   949,   959,   981,   980,   958,   986,   987,
     822,   988,   990,   996,   997,  1007,  1014,   202,  1015,  1016,
     202,  1017,  1018,  1019,  1035,  1027,   202,   202,   202,  1030,
    1031,  1032,  1033,  1034,   202,   201,  1036,  1045,  1276,  1039,
    1040,   201,   201,   201,  1054,  1056,  1049,   200,  1057,  1058,
    1061,  1064,  1065,  1066,  1067,   200,   202,   200,  1081,  1083,
    1084,   200,   200,  1086,  1085,   930,  1089,  1234,  1043,  1044,
    1090,  1028,  1029,   202,  1115,  1109,  1095,  1116,  1117,  1118,
    1136,  1137,  1111,  1101,   200,   202,  1119,  1138,   200,  1139,
    1140,  1141,  1142,  1145,  1143,  1146,   714,  1147,   200,   200,
     222,  1150,   200,  1152,  1156,  1158,  1157,   714,  1159,  1165,
    1166,  1164,  1175,  1176,  1177,  1178,  1183,  1180,  1182,  1184,
    1185,  1187,  1192,  1188,   202,  1189,  1197,  1198,   202,  1206,
     202,   202,  1204,  1217,  1221,  1215,  1219,  1222,   202,  1223,
    1227,  1228,  1229,   202,   202,  1230,  1232,  1235,  1233,  1245,
     202,   202,  1238,   417,   202,   202,  1239,   202,  1240,  1241,
    1255,   202,  1257,  1271,  1263,  1088,  1259,  1264,  1091,  1093,
     202,   202,  1096,  1099,  1260,  1280,   686,  1281,  1283,  1282,
     202,  1302,  1291,   202,  1286,  1306,  1292,  1319,  1313,  1314,
    1325,  1315,  1316,  1328,   977,  1336,  1329,  1330,  1337,  1126,
    1332,  1326,  1091,  1331,   591,  1335,  1342,  1334,   246,  1317,
     200,  1338,  1341,  1339,  1340,   257,   200,   863,   200,   692,
     228,   720,   203,   367,  1231,   200,  1318,  1154,  1155,  1295,
     201,  1151,   399,   971,   694,   378,  1285,   872,   201,   715,
     201,   247,  1041,   451,   201,   201,  1179,  1120,   202,  1172,
    1102,  1256,  1216,  1144,   202,   202,   452,   977,  1200,   453,
     454,   455,   456,   457,   458,   459,   657,   201,   623,   797,
     656,   201,   792,   893,  1149,   747,   910,   653,   730,   202,
    1024,   201,   201,  1252,  1324,   201,   402,   896,   881,   740,
     202,  1068,   886,   211,  1212,   851,   734,  1091,   939,  1099,
       0,     0,   460,   200,     0,   679,     0,     0,     0,     0,
       0,     0,     0,   461,     0,     0,     0,     0,   462,     0,
     531,     0,     0,   942,     0,     0,     0,   537,     0,     0,
       0,   463,     0,   200,     0,     0,     0,   200,     0,   200,
       0,     0,     0,   200,     0,     0,     0,     0,   202,   200,
       0,   202,   202,     0,     0,   202,   202,     0,   200,   202,
       0,     0,   200,     0,     0,     0,     0,   200,     0,     0,
       0,   686,     0,   592,     0,   593,   594,   202,     0,     0,
       0,     0,   202,     0,   595,   202,     0,     0,     0,     0,
       0,     0,     0,   201,     0,   376,     0,     0,     0,   201,
       0,   201,     0,   596,     0,   202,   597,     0,   201,     0,
     202,   202,   598,     0,     0,     0,     0,     0,     0,     0,
       0,   599,     0,     0,   714,     0,     0,     0,   464,     0,
       0,     0,     0,     0,   600,   601,   686,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   402,     0,     0,     0,     0,     0,   602,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,   202,   603,
     202,     0,   202,     0,     0,     0,   201,     0,   465,     0,
       0,     0,   604,     0,     0,     0,     0,     0,     0,     0,
     605,   606,     0,     0,     0,     0,   202,     0,   607,   608,
       0,   466,   467,   200,     0,     0,   201,     0,     0,     0,
     201,     0,   201,     0,   200,   200,   201,     0,     0,     0,
       0,     0,   201,   609,   610,   611,   612,   613,   614,   615,
     616,   201,     0,     0,     0,   201,   200,     0,     0,   200,
     201,     0,     0,     0,   202,   200,   200,   200,     0,     0,
       0,     0,     0,   200,   204,     0,     0,     0,     0,     0,
     204,   204,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     0,     0,   202,     0,     0,
       0,     0,     0,     0,   200,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   200,     0,     0,     0,   200,     0,   200,
     200,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,     0,   200,   200,     0,     0,     0,     0,     0,   200,
     200,     0,     0,   200,   200,     0,   200,     0,     0,     0,
     200,     0,     0,     0,     0,     0,   201,     0,     0,   200,
     200,     0,     0,     0,     0,     0,     0,   201,   201,   200,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,   201,     0,     0,     0,     0,     0,   201,   201,
     201,     0,     0,     0,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,     0,   204,   201,   204,
       0,     0,     0,   204,   204,     0,     0,   200,     0,     0,
       0,     0,     0,   200,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   201,     0,     0,
     204,     0,   334,     0,     0,     0,     0,     0,   200,     0,
     204,   204,     0,     0,   204,   375,     0,     0,     0,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,     0,   201,     0,     0,     0,
     201,     0,   201,   201,   404,     0,   407,     0,     0,     0,
     201,     0,     0,     0,     0,   201,   201,   421,     0,     0,
       0,     0,   201,   201,     0,     0,   201,   201,     0,   201,
       0,     0,     0,   201,     0,     0,     0,   200,     0,     0,
     200,   200,   201,   201,   200,   200,     0,     0,   200,     0,
       0,     0,   201,     0,     0,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,   200,     0,     0,   200,     0,     0,     0,     0,     0,
       0,     0,   204,     0,     0,     0,     0,     0,   204,     0,
     204,     0,     0,   421,   200,     0,     0,   204,     0,   200,
     200,     0,     0,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,   201,   201,     0,   200,
       0,     0,   404,     0,     0,     0,     0,     0,     0,     0,
     546,     0,     0,   549,   552,     0,     0,     0,     0,     0,
     554,   201,     0,   555,     0,     0,   559,     0,   562,     0,
     568,   569,   201,     0,   562,     0,   200,     0,     0,   200,
       0,   200,   588,     0,     0,   204,   334,     0,   562,   421,
     421,     0,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,     0,   200,   645,     0,     0,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,   204,     0,   662,     0,   204,     0,     0,     0,     0,
     201,   204,     0,   201,   201,     0,     0,   201,   201,     0,
       0,   201,     0,     0,     0,     0,     0,     0,     0,   204,
     375,     0,     0,   200,     0,     0,     0,     0,     0,   201,
       0,     0,     0,     0,   201,     0,     0,   201,     0,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   743,   745,     0,     0,   201,     0,     0,
       0,     0,   201,   201,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
       0,     0,   201,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   796,     0,   798,     0,   800,     0,     0,   201,     0,
       0,     0,     0,     0,     0,   204,     0,     0,     0,     0,
     802,     0,     0,     0,     0,     0,   204,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,     0,   201,   204,   204,   204,
       0,     0,     0,     0,     0,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     515,     0,     0,   865,     0,     0,     0,   204,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,     0,     0,   884,     0,   201,
       0,     0,     0,     0,     0,     0,   204,     0,   891,   892,
       0,   201,     0,     0,   562,     0,   899,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   911,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   920,   204,   921,     0,     0,   204,
     924,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,   204,   204,     0,     0,     0,     0,
       0,   204,     0,     0,     0,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   204,     0,     0,     0,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   994,   995,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1006,     0,
       0,     0,     0,  1011,     0,     0,     0,     0,     0,   204,
       0,     0,     0,  1020,  1021,   204,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   421,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,   204,   204,     0,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   421,   204,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   421,     0,
       0,     0,     0,  1134,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,     0,
       0,   204,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   421,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   204,  1214,
       0,   204,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,  1134,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
     493,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,    38,    39,     0,    40,     0,   452,    41,    42,   453,
       0,     0,     0,     0,     0,   204,    43,    44,    45,     0,
      46,     0,     0,     0,    47,    48,    49,    50,    51,     0,
      52,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,     0,    58,   375,     0,
       0,    59,     0,     0,     0,    60,    61,     0,    62,    63,
      64,    65,     0,     0,     0,    66,    67,     0,     0,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,     0,
     204,     0,    76,    77,    78,    79,     0,    80,     0,     0,
      81,     0,     0,     0,    82,    83,    84,     0,    85,    86,
      87,    88,    89,     0,    90,     0,    91,    92,    93,     0,
       0,     0,    94,    95,     0,    96,    97,    98,   421,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,   106,   107,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,   174,   175,     0,   176,   177,
     178,   179,   180,   181,   182,     0,   183,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   266,   267,   268,   269,   270,   271,     0,   272,     0,
     401,     0,   467,     0,     0,    32,    33,     0,    34,    35,
       0,    36,    37,     0,     0,     0,     0,   275,   276,   277,
       0,    40,     0,     0,   278,    42,     0,     0,     0,     0,
       0,     0,     0,   279,    44,   280,     0,    46,     0,   281,
     282,   283,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,   284,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,   285,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,   286,   287,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
     288,    90,     0,    91,    92,    93,     5,   289,     0,    94,
      95,     0,    96,    97,    98,   290,     0,    99,   100,   291,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     8,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   292,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   293,     0,     0,     0,     0,   138,
       0,     0,   294,   140,   141,   142,   143,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,     0,     0,     0,   309,   310,   266,   267,
     268,   269,   270,   271,     0,   272,     0,   273,   274,     0,
       0,     0,    32,    33,     0,    34,    35,     0,    36,    37,
       0,     0,     0,     0,   275,   276,   277,     0,    40,     0,
       0,   278,    42,     0,     0,     0,     0,     0,     0,     0,
     279,    44,   280,     0,    46,     0,   281,   282,   283,    48,
      49,    50,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    55,   284,    56,    57,     0,     0,
       0,    58,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    62,    63,    64,    65,     0,     0,     0,    66,
      67,   285,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,     0,     0,   286,   287,    77,    78,    79,
       0,    80,     0,     0,    81,     0,     0,     0,    82,    83,
      84,     0,    85,    86,    87,    88,    89,   288,    90,     0,
      91,    92,    93,     0,   289,     0,    94,    95,     0,    96,
      97,    98,   290,     0,    99,   100,   291,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   106,   107,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,   292,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   293,     0,     0,     0,     0,   138,     0,     0,   294,
     140,   141,   142,   143,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,   157,
     158,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,   309,   310,   266,   267,   268,   269,   270,
     271,     0,   272,     0,  1127,     0,     0,     0,     0,    32,
      33,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,   275,   276,   277,     0,    40,     0,     0,   278,    42,
       0,     0,     0,     0,     0,     0,     0,   279,    44,   280,
       0,    46,     0,   281,   282,   283,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
    1128,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,   285,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,   287,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,   288,    90,     0,    91,    92,    93,
       0,   289,     0,    94,    95,     0,    96,    97,    98,   290,
       0,    99,   100,   291,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   293,     0,
       0,     0,     0,   138,     0,     0,   294,   140,   141,   142,
     143,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,   157,   158,  1129,  1130,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   310,   266,   267,   268,   269,   270,   271,     0,   272,
       0,   506,  1186,     0,     0,     0,    32,    33,     0,    34,
      35,     0,    36,    37,     0,     0,     0,     0,   275,   276,
     277,     0,    40,     0,     0,   278,    42,     0,     0,     0,
       0,     0,     0,     0,   279,    44,   280,     0,    46,     0,
     281,   282,   283,    48,    49,    50,    51,     0,    52,    53,
       0,    54,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,     0,    58,     0,     0,     0,    59,
       0,     0,     0,    60,    61,     0,    62,    63,    64,    65,
       0,     0,     0,    66,    67,   285,     0,    68,    69,    70,
      71,    72,    73,    74,     0,     0,    75,     0,     0,     0,
     287,    77,    78,    79,     0,    80,     0,     0,    81,     0,
       0,     0,    82,    83,    84,     0,    85,    86,    87,    88,
      89,   288,    90,     0,    91,    92,    93,     5,   289,     0,
      94,    95,     0,    96,    97,    98,   290,     0,    99,   100,
     291,   102,   103,     0,     0,     0,     0,   104,   105,     0,
     106,   107,     0,     0,     8,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
     115,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   293,     0,     0,     0,     0,
     138,     0,     0,   294,   140,   141,   142,   143,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,   157,   158,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,     0,   183,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   310,   266,
     267,   268,   269,   270,   271,     0,   272,     0,   506,  1294,
       0,     0,     0,    32,    33,     0,    34,    35,     0,    36,
      37,     0,     0,     0,     0,   275,   276,   277,     0,    40,
       0,     0,   278,    42,     0,     0,     0,     0,     0,     0,
       0,   279,    44,   280,     0,    46,     0,   281,   282,   283,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,   285,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,   287,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,   288,    90,
       0,    91,    92,    93,     5,   289,     0,    94,    95,     0,
      96,    97,    98,   290,     0,    99,   100,   291,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     8,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   293,     0,     0,     0,     0,   138,     0,     0,
     294,   140,   141,   142,   143,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,   183,   184,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,     0,     0,     0,   309,   310,   266,   267,   268,   269,
     270,   271,     0,   272,     0,   273,     0,     0,     0,     0,
      32,    33,     0,    34,    35,     0,    36,    37,     0,     0,
       0,     0,   275,   276,   277,     0,    40,     0,     0,   278,
      42,     0,     0,     0,     0,     0,     0,     0,   279,    44,
     280,     0,    46,     0,   281,   282,   283,    48,    49,    50,
      51,     0,    52,    53,     0,    54,     0,     0,     0,     0,
       0,     0,    55,   284,    56,    57,     0,     0,     0,    58,
       0,     0,     0,    59,     0,     0,     0,    60,    61,     0,
      62,    63,    64,    65,     0,     0,     0,    66,    67,   285,
       0,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,     0,     0,   286,   287,    77,    78,    79,     0,    80,
       0,     0,    81,     0,     0,     0,    82,    83,    84,     0,
      85,    86,    87,    88,    89,   288,    90,     0,    91,    92,
      93,     0,   289,     0,    94,    95,     0,    96,    97,    98,
     290,     0,    99,   100,   291,   102,   103,     0,     0,     0,
       0,   104,   105,     0,   106,   107,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,   292,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,   127,   128,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   293,
       0,     0,     0,     0,   138,     0,     0,   294,   140,   141,
     142,   143,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,   157,   158,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   174,   175,     0,
     176,   177,   178,   179,   180,   181,   182,     0,   183,   184,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,     0,     0,     0,     0,     0,     0,
       0,   309,   310,   266,   267,   268,   269,   270,   271,     0,
     272,     0,   506,     0,     0,     0,     0,    32,    33,     0,
      34,    35,     0,    36,    37,     0,     0,     0,     0,   275,
     276,   277,     0,    40,     0,     0,   278,    42,     0,     0,
       0,     0,     0,     0,     0,   279,    44,   280,     0,    46,
       0,   281,   282,   283,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,   285,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,   287,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,   288,    90,     0,    91,    92,    93,     5,   289,
       0,    94,    95,     0,    96,    97,    98,   290,     0,    99,
     100,   291,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     8,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   293,     0,     0,     0,
       0,   138,     0,     0,   294,   140,   141,   142,   143,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,     0,     0,     0,     0,     0,     0,     0,   309,   310,
     266,   267,   268,   269,   270,   271,     0,   272,     0,   370,
       0,     0,     0,     0,    32,    33,     0,    34,    35,     0,
      36,    37,     0,     0,     0,     0,   275,   276,   277,     0,
      40,     0,     0,   278,    42,     0,     0,     0,     0,     0,
       0,     0,   279,    44,   280,     0,    46,     0,   281,   282,
     283,    48,    49,    50,    51,     0,    52,    53,   550,    54,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,    58,     0,     0,     0,    59,     0,     0,
       0,    60,    61,     0,    62,    63,    64,    65,     0,     0,
       0,    66,    67,   285,     0,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,     0,     0,     0,   287,    77,
      78,    79,     0,    80,     0,     0,    81,     0,     0,     0,
      82,    83,    84,     0,    85,    86,    87,    88,    89,   288,
      90,     0,    91,    92,    93,     0,   289,     0,    94,    95,
       0,    96,    97,    98,   290,     0,    99,   100,   291,   102,
     103,     0,     0,     0,     0,   104,   105,     0,   106,   107,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,   127,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   293,     0,     0,     0,     0,   138,     0,
       0,   294,   140,   141,   142,   143,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
       0,   157,   158,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,     0,   183,   184,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,     0,     0,
     551,     0,     0,     0,     0,   309,   310,   266,   267,   268,
     269,   270,   271,     0,   272,     0,   370,     0,     0,   648,
       0,   649,    33,     0,    34,    35,     0,    36,    37,     0,
       0,     0,     0,   275,   276,   277,     0,    40,     0,     0,
     278,    42,     0,     0,     0,     0,     0,     0,     0,   279,
      44,   280,     0,    46,     0,   281,   282,   283,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,     0,
      58,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    62,    63,    64,    65,     0,     0,     0,    66,    67,
     285,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,     0,     0,     0,   287,    77,    78,    79,     0,
      80,     0,     0,    81,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,   288,    90,     0,    91,
      92,    93,     0,   289,     0,    94,    95,   650,    96,    97,
      98,   290,     0,    99,   100,   291,   102,   103,     0,     0,
       0,     0,   104,   105,     0,   106,   107,     0,     0,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     293,     0,     0,     0,     0,   138,     0,     0,   294,   140,
     141,   142,   143,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,     0,   157,   158,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,     0,     0,     0,     0,     0,
       0,     0,   309,   310,   266,   267,   268,   269,   270,   271,
       0,   272,     0,   370,     0,     0,     0,     0,    32,    33,
       0,    34,    35,     0,    36,    37,     0,     0,     0,     0,
     275,   276,   277,     0,    40,     0,     0,   278,    42,     0,
       0,     0,     0,     0,     0,     0,   279,    44,   280,     0,
      46,     0,   281,   282,   283,    48,    49,    50,    51,     0,
      52,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,     0,    58,     0,     0,
       0,    59,     0,     0,     0,    60,    61,     0,    62,    63,
      64,    65,     0,     0,     0,    66,    67,   285,     0,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,     0,
       0,     0,   287,    77,    78,    79,     0,    80,     0,     0,
      81,     0,     0,     0,    82,    83,    84,     0,    85,    86,
      87,    88,    89,   288,    90,     0,    91,    92,    93,     0,
     289,     0,    94,    95,     0,    96,    97,    98,   290,     0,
      99,   100,   291,   102,   103,     0,     0,     0,     0,   104,
     105,     0,   106,   107,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   293,     0,     0,
       0,     0,   138,     0,     0,   294,   140,   141,   142,   143,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,     0,   157,   158,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,   174,   175,     0,   176,   177,
     178,   179,   180,   181,   182,     0,   183,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,     0,     0,   371,     0,     0,     0,     0,   309,
     310,   266,   267,   268,   269,   270,   271,     0,   272,     0,
     370,   556,     0,     0,     0,    32,    33,     0,    34,    35,
       0,    36,    37,     0,     0,     0,     0,   275,   276,   277,
       0,    40,     0,     0,   278,    42,     0,     0,     0,     0,
       0,     0,     0,   279,    44,   280,     0,    46,     0,   281,
     282,   283,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,   285,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,     0,   287,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
     288,    90,     0,    91,    92,    93,     0,   289,     0,    94,
      95,     0,    96,    97,    98,   290,     0,    99,   100,   291,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   293,     0,     0,     0,     0,   138,
       0,     0,   294,   140,   141,   142,   143,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,     0,
       0,     0,     0,     0,     0,     0,   309,   310,   266,   267,
     268,   269,   270,   271,     0,   272,     0,   370,     0,     0,
       0,     0,    32,    33,     0,    34,    35,     0,    36,    37,
       0,     0,     0,     0,   275,   276,   277,     0,    40,     0,
       0,   278,    42,     0,     0,     0,     0,     0,     0,     0,
     279,    44,   280,     0,    46,     0,   281,   282,   283,    48,
      49,    50,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
       0,    58,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    62,    63,    64,    65,     0,     0,     0,    66,
      67,   285,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,     0,     0,     0,   287,    77,    78,    79,
       0,    80,     0,     0,    81,     0,     0,     0,    82,    83,
      84,     0,    85,    86,    87,    88,    89,   288,    90,     0,
      91,    92,    93,     0,   289,     0,    94,    95,     0,    96,
      97,    98,   290,     0,    99,   100,   291,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   106,   107,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   293,     0,     0,     0,     0,   138,     0,     0,   294,
     140,   141,   142,   143,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,     0,   157,
     158,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,   558,     0,
       0,     0,     0,   309,   310,   266,   267,   268,   269,   270,
     271,     0,   272,     0,   370,   621,     0,     0,     0,    32,
      33,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,   275,   276,   277,     0,    40,     0,     0,   278,    42,
       0,     0,     0,     0,     0,     0,     0,   279,    44,   280,
       0,    46,     0,   281,   282,   283,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,   285,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,   287,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,   288,    90,     0,    91,    92,    93,
       0,   289,     0,    94,    95,     0,    96,    97,    98,   290,
       0,    99,   100,   291,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   293,     0,
       0,     0,     0,   138,     0,     0,   294,   140,   141,   142,
     143,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,     0,   157,   158,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   310,   266,   267,   268,   269,   270,   271,     0,   272,
       0,   370,   660,     0,     0,     0,    32,    33,     0,    34,
      35,     0,    36,    37,     0,     0,     0,     0,   275,   276,
     277,     0,    40,     0,     0,   278,    42,     0,     0,     0,
       0,     0,     0,     0,   279,    44,   280,     0,    46,     0,
     281,   282,   283,    48,    49,    50,    51,     0,    52,    53,
       0,    54,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,     0,    58,     0,     0,     0,    59,
       0,     0,     0,    60,    61,     0,    62,    63,    64,    65,
       0,     0,     0,    66,    67,   285,     0,    68,    69,    70,
      71,    72,    73,    74,     0,     0,    75,     0,     0,     0,
     287,    77,    78,    79,     0,    80,     0,     0,    81,     0,
       0,     0,    82,    83,    84,     0,    85,    86,    87,    88,
      89,   288,    90,     0,    91,    92,    93,     0,   289,     0,
      94,    95,     0,    96,    97,    98,   290,     0,    99,   100,
     291,   102,   103,     0,     0,     0,     0,   104,   105,     0,
     106,   107,     0,     0,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
     115,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   293,     0,     0,     0,     0,
     138,     0,     0,   294,   140,   141,   142,   143,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     0,   157,   158,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,     0,   183,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   310,   266,
     267,   268,   269,   270,   271,     0,   272,     0,  1293,  1294,
       0,     0,     0,    32,    33,     0,    34,    35,     0,    36,
      37,     0,     0,     0,     0,   275,   276,   277,     0,    40,
       0,     0,   278,    42,     0,     0,     0,     0,     0,     0,
       0,   279,    44,   280,     0,    46,     0,   281,   282,   283,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,   285,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,   287,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,   288,    90,
       0,    91,    92,    93,     0,   289,     0,    94,    95,     0,
      96,    97,    98,   290,     0,    99,   100,   291,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   293,     0,     0,     0,     0,   138,     0,     0,
     294,   140,   141,   142,   143,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,   183,   184,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,     0,     0,     0,
       0,     0,     0,     0,   309,   310,   266,   267,   268,   269,
     270,   271,     0,   272,     0,   370,     0,     0,     0,     0,
      32,    33,     0,    34,    35,     0,    36,    37,     0,     0,
       0,     0,   275,   276,   277,     0,    40,     0,     0,   278,
      42,     0,     0,     0,     0,     0,     0,     0,   279,    44,
     280,     0,    46,     0,   281,   282,   283,    48,    49,    50,
      51,     0,    52,    53,     0,    54,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,     0,    58,
       0,     0,     0,    59,     0,     0,     0,    60,    61,     0,
      62,    63,    64,    65,     0,     0,     0,    66,    67,   285,
       0,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,     0,     0,     0,   287,    77,    78,    79,     0,    80,
       0,     0,    81,     0,     0,     0,    82,    83,    84,     0,
      85,    86,    87,    88,    89,   288,    90,     0,    91,    92,
      93,     0,   289,     0,    94,    95,     0,    96,    97,    98,
     290,     0,    99,   100,   291,   102,   103,     0,     0,     0,
       0,   104,   105,     0,   106,   107,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,   127,   128,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   293,
       0,     0,     0,     0,   138,     0,     0,   294,   140,   141,
     142,   143,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,     0,   157,   158,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   174,   175,     0,
     176,   177,   178,   179,   180,   181,   182,     0,   183,   184,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,     0,     0,     0,     0,     0,     0,
       0,   309,   310,   266,   267,   268,   269,   270,   271,     0,
     272,     0,   370,     0,     0,     0,     0,    32,    33,     0,
      34,    35,     0,    36,    37,     0,     0,     0,     0,   275,
     276,   277,     0,    40,     0,     0,   278,    42,     0,     0,
       0,     0,     0,     0,     0,   279,    44,   280,     0,    46,
       0,   281,   282,   283,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,   285,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,   287,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,   288,    90,     0,    91,    92,    93,     0,   289,
       0,    94,    95,     0,    96,    97,    98,   290,     0,    99,
     100,   291,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   293,     0,     0,     0,
       0,   138,     0,     0,   294,   140,   141,   142,   143,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   585,
     586,   587,   189,   190,   191,   192,   193,   194,   195,   196,
       0,     0,     0,   266,     0,     0,     0,     0,   309,   310,
     695,     0,   830,     0,     0,     0,     0,    32,    33,     0,
      34,    35,     0,    36,    37,     0,     0,     0,     0,     0,
      38,    39,     0,    40,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,     0,    46,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,     0,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,    76,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,     0,    90,     0,    91,    92,    93,     5,     0,
       0,    94,    95,     0,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     8,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   697,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,   138,     0,   698,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     266,     0,     0,     0,     0,     0,   197,   695,     0,   696,
       0,     0,     0,     0,    32,    33,     0,    34,    35,     0,
      36,    37,     0,     0,     0,     0,     0,    38,    39,     0,
      40,     0,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,     0,    46,     0,     0,     0,
      47,    48,    49,    50,    51,     0,    52,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,    58,     0,     0,     0,    59,     0,     0,
       0,    60,    61,     0,    62,    63,    64,    65,     0,     0,
       0,    66,    67,     0,     0,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,     0,     0,     0,    76,    77,
      78,    79,     0,    80,     0,     0,    81,     0,     0,     0,
      82,    83,    84,     0,    85,    86,    87,    88,    89,     0,
      90,     0,    91,    92,    93,     0,     0,     0,    94,    95,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,   106,   107,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   697,
     125,   126,   127,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,   138,     0,
     698,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   157,   158,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,     0,   183,   184,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   266,     0,     0,
       0,     0,     0,   197,     0,     0,   696,     0,     0,     0,
       0,    32,    33,     0,    34,    35,     0,    36,    37,     0,
       0,     0,     0,     0,    38,    39,     0,    40,     0,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,     0,    46,     0,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,     0,
      58,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    62,    63,    64,    65,     0,     0,     0,    66,    67,
       0,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,     0,     0,     0,    76,    77,    78,    79,     0,
      80,     0,     0,    81,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,    93,     0,     0,     0,    94,    95,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,   106,   107,     0,     0,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   697,   125,   126,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,   138,     0,   698,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,    31,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,    32,    33,     0,    34,    35,
     197,    36,    37,     0,     0,     0,     0,     0,    38,    39,
       0,    40,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,     0,    46,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,     0,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,     0,    76,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,    93,     0,     0,     0,    94,
      95,     0,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   266,     0,
       0,     0,     0,     0,   197,     0,     0,     0,     0,   663,
       0,     0,    32,    33,     0,    34,    35,     0,    36,    37,
       0,     0,     0,     0,     0,    38,    39,     0,    40,     0,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,     0,    46,     0,     0,     0,    47,    48,
      49,    50,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
       0,    58,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    62,    63,    64,    65,     0,     0,     0,    66,
      67,     0,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,     0,     0,     0,    76,    77,    78,    79,
       0,    80,     0,     0,    81,     0,     0,     0,    82,    83,
      84,     0,    85,    86,    87,    88,    89,     0,    90,     0,
      91,    92,    93,     0,     0,     0,    94,    95,     0,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   106,   107,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   157,
     158,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   266,     0,     0,   717,     0,
       0,     0,     0,     0,     0,     0,   934,     0,     0,    32,
      33,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,    38,    39,     0,    40,     0,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,    46,     0,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,    76,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,     0,    90,     0,    91,    92,    93,
       0,     0,     0,    94,    95,     0,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,   266,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,    32,    33,   983,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     0,    38,    39,     0,    40,
       0,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,     0,    46,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,     0,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,    76,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,     0,    90,
       0,    91,    92,    93,     0,     0,     0,    94,    95,     0,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,   183,   184,   666,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,    32,    33,  1135,
      34,    35,     0,    36,    37,     0,     0,     0,     0,     0,
     276,   277,     0,    40,     0,     0,   278,    42,     0,     0,
       0,     0,     0,     0,     0,   279,    44,   280,     0,    46,
       0,   281,   282,    47,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,   285,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,   287,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,   288,    90,     0,    91,    92,    93,     0,   289,
       0,    94,    95,     0,    96,    97,    98,   290,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   293,     0,     0,     0,
       0,   138,     0,     0,   294,   140,   141,   142,   143,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      31,   267,   268,   269,   270,   271,     0,   272,     0,     0,
       0,     0,     0,     0,    32,    33,     0,    34,    35,     0,
      36,    37,     0,     0,     0,     0,     0,    38,    39,     0,
      40,     0,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,     0,    46,     0,     0,     0,
     283,    48,    49,    50,    51,     0,    52,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,    58,     0,     0,     0,    59,     0,     0,
       0,    60,    61,     0,    62,    63,    64,    65,     0,     0,
       0,    66,    67,     0,     0,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,     0,     0,     0,    76,    77,
      78,    79,     0,    80,     0,     0,    81,     0,     0,     0,
      82,    83,    84,     0,    85,    86,    87,    88,    89,     0,
      90,     0,    91,    92,    93,     0,     0,     0,    94,    95,
       0,    96,    97,    98,     0,     0,    99,   100,   291,   102,
     103,     0,     0,     0,     0,   104,   105,     0,   106,   107,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,   127,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   157,   158,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,     0,   183,   184,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    31,     0,     0,
       0,     0,     0,     0,     0,     0,   499,     0,     0,     0,
       0,    32,    33,   493,    34,    35,     0,    36,    37,     0,
       0,     0,     0,     0,    38,    39,     0,    40,     0,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,     0,    46,     0,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,     0,
      58,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    62,    63,    64,    65,     0,     0,     0,    66,    67,
       0,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,     0,     0,     0,    76,    77,    78,    79,     0,
      80,     0,     0,    81,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,    93,     5,     0,     0,    94,    95,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,   106,   107,     0,     0,     8,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   500,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,    32,    33,
       0,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,    38,    39,     0,    40,     0,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,     0,
      46,     0,     0,     0,    47,    48,    49,    50,    51,     0,
      52,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,     0,    58,     0,     0,
       0,    59,     0,     0,     0,    60,    61,     0,    62,    63,
      64,    65,     0,     0,     0,    66,    67,     0,     0,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,     0,
       0,     0,    76,    77,    78,    79,     0,    80,     0,     0,
      81,     0,     0,     0,    82,    83,    84,     0,    85,    86,
      87,    88,    89,     0,    90,     0,    91,    92,    93,     5,
       0,     0,    94,    95,     0,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,   106,   107,     0,     0,     8,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,   174,   175,     0,   176,   177,
     178,   179,   180,   181,   182,     0,   183,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,    32,    33,     0,    34,    35,
       0,    36,    37,     0,     0,     0,     0,     0,    38,    39,
       0,    40,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,     0,    46,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,     0,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,     0,    76,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,    93,     5,     0,     0,    94,
      95,     0,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     8,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,     0,    32,    33,     0,    34,    35,     0,    36,    37,
       0,     0,     0,     0,     0,    38,    39,     0,    40,     0,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,     0,    46,     0,     0,     0,    47,    48,
      49,    50,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
       0,    58,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    62,    63,    64,    65,     0,     0,     0,    66,
      67,     0,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,     0,     0,     0,    76,    77,    78,    79,
       0,    80,     0,     0,    81,     0,     0,     0,    82,    83,
      84,     0,    85,    86,    87,    88,    89,     0,    90,     0,
      91,    92,    93,     0,     0,     0,    94,    95,     0,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   106,   107,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   157,
     158,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,    32,
      33,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,    38,    39,     0,    40,     0,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,    46,     0,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,    76,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,     0,    90,     0,    91,    92,    93,
       0,     0,     0,    94,    95,     0,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,    31,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,    32,    33,   493,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     0,    38,    39,     0,    40,
       0,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,     0,    46,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,     0,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,    76,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,     0,    90,
       0,    91,    92,    93,     0,     0,     0,    94,    95,     0,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,   183,   184,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   663,     0,     0,
      32,    33,     0,    34,    35,     0,    36,    37,     0,     0,
       0,     0,     0,    38,    39,     0,    40,     0,     0,    41,
      42,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,     0,    46,     0,     0,     0,    47,    48,    49,    50,
      51,     0,    52,    53,     0,    54,     0,     0,     0,     0,
       0,     0,    55,     0,    56,    57,     0,     0,     0,    58,
       0,     0,     0,    59,     0,     0,     0,    60,    61,     0,
      62,    63,    64,    65,     0,     0,     0,    66,    67,     0,
       0,    68,    69,    70,    71,    72,    73,    74,     0,     0,
      75,     0,     0,     0,    76,    77,    78,    79,     0,    80,
       0,     0,    81,     0,     0,     0,    82,    83,    84,     0,
      85,    86,    87,    88,    89,     0,    90,     0,    91,    92,
      93,     0,     0,     0,    94,    95,     0,    96,    97,    98,
       0,     0,    99,   100,   101,   102,   103,     0,     0,     0,
       0,   104,   105,     0,   106,   107,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   111,
       0,   112,   113,   114,   115,     0,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,   126,   127,   128,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,   138,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   157,   158,     0,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   174,   175,     0,
     176,   177,   178,   179,   180,   181,   182,     0,   183,   184,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   675,     0,     0,    32,    33,     0,
      34,    35,     0,    36,    37,     0,     0,     0,     0,     0,
      38,    39,     0,    40,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,     0,    46,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,     0,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,    76,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
      88,    89,     0,    90,     0,    91,    92,    93,     0,     0,
       0,    94,    95,     0,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   807,     0,     0,    32,    33,     0,    34,    35,     0,
      36,    37,     0,     0,     0,     0,     0,    38,    39,     0,
      40,     0,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    43,    44,    45,     0,    46,     0,     0,     0,
      47,    48,    49,    50,    51,     0,    52,    53,     0,    54,
       0,     0,     0,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,    58,     0,     0,     0,    59,     0,     0,
       0,    60,    61,     0,    62,    63,    64,    65,     0,     0,
       0,    66,    67,     0,     0,    68,    69,    70,    71,    72,
      73,    74,     0,     0,    75,     0,     0,     0,    76,    77,
      78,    79,     0,    80,     0,     0,    81,     0,     0,     0,
      82,    83,    84,     0,    85,    86,    87,    88,    89,     0,
      90,     0,    91,    92,    93,     0,     0,     0,    94,    95,
       0,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   104,   105,     0,   106,   107,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,   111,     0,   112,   113,   114,   115,     0,
     116,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,   126,   127,   128,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   157,   158,     0,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
       0,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,     0,   183,   184,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    31,     0,     0,
       0,     0,     0,     0,     0,     0,   927,     0,     0,     0,
       0,    32,    33,     0,    34,    35,     0,    36,    37,     0,
       0,     0,     0,     0,    38,    39,     0,    40,     0,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,     0,    46,     0,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,     0,
      58,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    62,    63,    64,    65,     0,     0,     0,    66,    67,
       0,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,     0,     0,     0,    76,    77,    78,    79,     0,
      80,     0,     0,    81,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,    93,     0,     0,     0,    94,    95,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,   106,   107,     0,     0,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   934,     0,     0,    32,    33,
       0,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,    38,    39,     0,    40,     0,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,    43,    44,    45,     0,
      46,     0,     0,     0,    47,    48,    49,    50,    51,     0,
      52,    53,     0,    54,     0,     0,     0,     0,     0,     0,
      55,     0,    56,    57,     0,     0,     0,    58,     0,     0,
       0,    59,     0,     0,     0,    60,    61,     0,    62,    63,
      64,    65,     0,     0,     0,    66,    67,     0,     0,    68,
      69,    70,    71,    72,    73,    74,     0,     0,    75,     0,
       0,     0,    76,    77,    78,    79,     0,    80,     0,     0,
      81,     0,     0,     0,    82,    83,    84,     0,    85,    86,
      87,    88,    89,     0,    90,     0,    91,    92,    93,     0,
       0,     0,    94,    95,     0,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,   104,
     105,     0,   106,   107,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     113,   114,   115,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,   126,   127,   128,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   157,   158,     0,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,     0,   174,   175,     0,   176,   177,
     178,   179,   180,   181,   182,     0,   183,   184,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   663,     0,     0,    32,    33,     0,    34,    35,
       0,    36,    37,     0,     0,     0,     0,     0,    38,    39,
       0,    40,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,     0,    46,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,     0,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,     0,    76,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,    93,     0,     0,     0,    94,
      95,     0,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   266,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   360,
       0,     0,    32,    33,     0,    34,    35,     0,    36,    37,
       0,     0,     0,     0,     0,    38,    39,     0,    40,     0,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
      43,    44,    45,     0,    46,     0,     0,     0,    47,    48,
      49,    50,    51,     0,    52,    53,     0,    54,     0,     0,
       0,     0,     0,     0,    55,     0,    56,    57,     0,     0,
       0,    58,     0,     0,     0,    59,     0,     0,     0,    60,
      61,     0,    62,    63,    64,    65,     0,     0,     0,    66,
      67,     0,     0,    68,    69,    70,    71,    72,    73,    74,
       0,     0,    75,     0,     0,     0,    76,    77,    78,    79,
       0,    80,     0,     0,    81,     0,     0,     0,    82,    83,
      84,     0,    85,    86,    87,    88,    89,     0,    90,     0,
      91,    92,    93,     0,     0,     0,    94,    95,     0,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,     0,
       0,     0,     0,   104,   105,     0,   106,   107,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,   113,   114,   115,     0,   116,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,   126,
     127,   128,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   157,
     158,     0,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,     0,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
     183,   184,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   934,     0,     0,    32,
      33,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,    38,    39,     0,    40,     0,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,    46,     0,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,    76,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,     0,    90,     0,    91,    92,    93,
       0,     0,     0,    94,    95,     0,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   675,     0,     0,    32,    33,     0,    34,
      35,     0,    36,    37,     0,     0,     0,     0,     0,    38,
      39,     0,    40,     0,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,    43,    44,    45,     0,    46,     0,
       0,     0,    47,    48,    49,    50,    51,     0,    52,    53,
       0,    54,     0,     0,     0,     0,     0,     0,    55,     0,
      56,    57,     0,     0,     0,    58,     0,     0,     0,    59,
       0,     0,     0,    60,    61,     0,    62,    63,    64,    65,
       0,     0,     0,    66,    67,     0,     0,    68,    69,    70,
      71,    72,    73,    74,     0,     0,    75,     0,     0,     0,
      76,    77,    78,    79,     0,    80,     0,     0,    81,     0,
       0,     0,    82,    83,    84,     0,    85,    86,    87,    88,
      89,     0,    90,     0,    91,    92,    93,     0,     0,     0,
      94,    95,     0,    96,    97,    98,     0,     0,    99,   100,
     101,   102,   103,     0,     0,     0,     0,   104,   105,     0,
     106,   107,     0,     0,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,   111,     0,   112,   113,   114,
     115,     0,   116,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,   126,   127,   128,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
     138,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   157,   158,     0,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,     0,   183,   184,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    31,
       0,     0,     0,     0,     0,     0,     0,     0,  1265,     0,
       0,     0,     0,    32,    33,     0,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     0,    38,    39,     0,    40,
       0,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,     0,    46,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,     0,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,    76,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,     0,    90,
       0,    91,    92,    93,     0,     0,     0,    94,    95,     0,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,   183,   184,    31,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,    32,    33,     0,
      34,    35,     0,    36,    37,     0,     0,     0,     0,     0,
      38,    39,     0,    40,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    43,    44,    45,     0,    46,
       0,     0,     0,    47,    48,    49,    50,    51,     0,    52,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,     0,     0,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,    76,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,    82,    83,    84,     0,    85,    86,    87,
     212,    89,     0,    90,     0,    91,    92,    93,     0,     0,
       0,    94,    95,     0,    96,    97,    98,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,   106,   107,     0,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,   115,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,   138,     0,     0,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,   149,   150,   151,   152,   153,
     154,   155,   156,     0,   157,   158,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,    31,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,    32,    33,     0,    34,    35,     0,    36,    37,     0,
       0,     0,     0,     0,    38,    39,     0,    40,     0,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,     0,    46,     0,     0,     0,    47,    48,    49,
      50,    51,     0,    52,    53,     0,    54,     0,     0,     0,
       0,     0,     0,    55,     0,    56,    57,     0,     0,     0,
      58,     0,     0,     0,    59,     0,     0,     0,    60,    61,
       0,    62,    63,    64,    65,     0,     0,     0,    66,    67,
       0,     0,    68,    69,    70,    71,    72,    73,    74,     0,
       0,    75,     0,     0,     0,    76,    77,    78,    79,     0,
      80,     0,     0,    81,     0,     0,     0,    82,    83,    84,
       0,    85,    86,    87,    88,    89,     0,    90,     0,    91,
      92,    93,     0,     0,     0,    94,    95,     0,    96,    97,
      98,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,   104,   105,     0,   106,   107,     0,     0,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,     0,
     111,     0,   112,   113,   114,   115,     0,   116,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,   126,   127,
     128,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,   138,     0,     0,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   157,   158,
       0,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,     0,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,   183,
     184,   266,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,    32,    33,     0,    34,    35,
       0,    36,    37,     0,     0,     0,     0,     0,    38,    39,
       0,    40,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,    43,    44,    45,     0,    46,     0,     0,
       0,    47,    48,    49,    50,    51,     0,    52,    53,     0,
      54,     0,     0,     0,     0,     0,     0,    55,     0,    56,
      57,     0,     0,     0,    58,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,    63,    64,    65,     0,
       0,     0,    66,    67,     0,     0,    68,    69,    70,    71,
      72,    73,    74,     0,     0,    75,     0,     0,     0,    76,
      77,    78,    79,     0,    80,     0,     0,    81,     0,     0,
       0,    82,    83,    84,     0,    85,    86,    87,    88,    89,
       0,    90,     0,    91,    92,    93,     0,     0,     0,    94,
      95,     0,    96,    97,    98,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   104,   105,     0,   106,
     107,     0,     0,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,   113,   114,   115,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,   126,   127,   128,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,   138,
       0,     0,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,   149,   150,   151,   152,   153,   154,   155,
     156,     0,   157,   158,     0,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,     0,   174,   175,     0,   176,   177,   178,   179,   180,
     181,   182,     0,   183,   184,    31,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,    32,
     950,     0,    34,    35,     0,    36,    37,     0,     0,     0,
       0,     0,    38,    39,     0,    40,     0,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
       0,    46,     0,     0,     0,    47,    48,    49,    50,    51,
       0,    52,    53,     0,    54,     0,     0,     0,     0,     0,
       0,    55,     0,    56,    57,     0,     0,     0,    58,     0,
       0,     0,    59,     0,     0,     0,    60,    61,     0,    62,
      63,    64,    65,     0,     0,     0,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    75,
       0,     0,     0,    76,    77,    78,    79,     0,    80,     0,
       0,    81,     0,     0,     0,    82,    83,    84,     0,    85,
      86,    87,    88,    89,     0,    90,     0,    91,    92,    93,
       0,     0,     0,    94,    95,     0,    96,    97,    98,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     104,   105,     0,   106,   107,     0,     0,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,   111,     0,
     112,   113,   114,   115,     0,   116,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,   126,   127,   128,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,   138,     0,     0,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,   149,   150,   151,
     152,   153,   154,   155,   156,     0,   157,   158,     0,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     0,   174,   175,     0,   176,
     177,   178,   179,   180,   181,   182,     0,   183,   184,    31,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,    32,    33,     0,    34,    35,     0,    36,
      37,     0,     0,     0,     0,     0,    38,    39,     0,    40,
       0,     0,    41,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,     0,    46,     0,     0,     0,    47,
      48,    49,    50,    51,     0,    52,    53,     0,    54,     0,
       0,     0,     0,     0,     0,    55,     0,    56,    57,     0,
       0,     0,    58,     0,     0,     0,    59,     0,     0,     0,
      60,    61,     0,    62,    63,    64,    65,     0,     0,     0,
      66,    67,     0,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     0,    75,     0,     0,     0,    76,    77,    78,
      79,     0,    80,     0,     0,    81,     0,     0,     0,    82,
      83,    84,     0,    85,    86,    87,    88,    89,     0,    90,
       0,    91,    92,    93,     0,     0,     0,    94,    95,     0,
      96,    97,    98,     0,     0,    99,   100,   101,   102,   103,
       0,     0,     0,     0,   104,   105,     0,   106,   107,     0,
       0,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,   111,     0,   112,   113,   114,   115,     0,   116,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
     126,   127,   128,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,   138,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,   154,   155,   156,     0,
     157,   158,     0,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     0,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,  1023,   184,  1213,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,     0,    33,     0,
      34,     0,     0,    36,    37,     0,     0,     0,     0,     0,
      38,     0,     0,    40,     0,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,     0,     0,
      53,     0,    54,     0,     0,     0,     0,     0,     0,    55,
       0,    56,    57,     0,     0,     0,    58,     0,     0,     0,
      59,     0,     0,     0,    60,    61,     0,    62,    63,    64,
      65,     0,     0,     0,    66,    67,     0,     0,    68,     0,
       0,    71,    72,    73,    74,     0,     0,    75,     0,     0,
       0,    76,    77,    78,    79,     0,    80,     0,     0,    81,
       0,     0,     0,     0,    83,    84,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,    92,    93,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,   104,   105,
       0,     0,     0,     0,     0,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,   111,     0,   112,   113,
     114,     0,     0,   116,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,   126,   127,   128,   129,     0,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,     0,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,   183,   184,     0,   185,   186,
     187,   188,     0,     0,     0,     0,     0,   194,   195,   196
};

static const yytype_int16 yycheck[] =
{
       2,   265,   228,   499,   460,   382,     8,     9,    10,     2,
     256,   284,   368,   273,   470,   239,     9,    10,   508,   221,
       1,   223,   224,   216,   217,   227,   216,   217,   367,   484,
     284,   439,   440,   508,   411,    13,    13,   274,    13,   375,
      13,    13,    13,   879,   383,   384,   423,    13,    13,   426,
      74,    13,    13,    13,   431,   432,    74,    35,   483,    13,
      38,    13,    35,    35,    35,    38,    38,    38,    12,    35,
      16,    13,    38,    35,    35,    35,    38,    38,    38,    16,
      13,    19,     8,    35,    73,    35,    38,   512,    38,    35,
     118,    20,    38,   696,   117,    12,    74,    35,    35,    13,
      38,    38,   362,    13,   481,    13,    35,    13,   381,    38,
      13,    13,    13,   286,    14,    35,     3,    12,    38,    39,
      13,    13,    13,   309,   310,    13,   363,   381,    13,    13,
      12,    60,   117,   122,    74,    15,    68,    13,    13,    13,
      13,   401,    13,    13,    13,   171,    12,  1204,    12,   436,
     437,   438,   126,     6,    35,    91,     9,    38,    35,   396,
     134,    38,    29,   148,    19,    63,    63,    22,    54,    88,
      89,   510,    35,   550,     5,    38,     4,   660,   368,    10,
       3,    61,    10,     2,   110,   641,   118,   460,  1245,     8,
       9,    10,   117,    35,    80,   197,    38,   470,    35,    35,
      65,    38,    38,   205,   118,   207,   460,   444,    35,   211,
     212,    38,   205,    35,   207,   101,    38,   103,   211,    74,
     433,   696,   154,   148,   117,    53,    93,   830,   115,    66,
       0,    22,   234,   152,   447,   508,   238,    72,    39,   735,
      41,   118,   244,   138,    66,   238,   248,   249,   165,   281,
     252,   137,   196,   193,   282,   501,   138,   110,   282,    72,
      86,   498,   285,  1099,   282,   163,   163,   211,   764,    13,
     165,   252,   138,    14,   138,   156,   449,    74,   480,   762,
       5,   167,   182,   543,     3,    10,   769,   770,   575,   124,
      81,     5,   273,   479,   282,   284,    10,   286,    27,   165,
     537,   165,   165,   164,   165,   282,    97,   282,   900,   901,
     902,   124,   502,   291,   504,   505,    90,   282,   291,   291,
     291,   253,   805,   151,     6,   291,   822,     9,   282,   291,
     291,   291,   282,   242,   926,   561,   245,   833,   283,   291,
     282,   291,   568,   569,   570,   291,   836,   292,   293,   282,
     840,   707,    12,   291,   291,   830,   764,   812,   360,   834,
     155,   836,   291,   699,   366,   840,   368,   169,   641,   705,
     706,   291,   282,   375,   282,   164,   282,   713,   197,   282,
     282,   282,   721,    22,   809,   810,   205,   641,   207,   370,
     282,   282,   211,   212,   282,   122,    35,   282,   282,    38,
      39,    40,    41,    42,    43,    44,   282,   282,   282,   282,
     291,   282,   282,   282,   291,   234,   207,    13,   140,   238,
     401,    50,   155,   696,    19,   427,   909,   910,   291,   248,
     249,   433,   268,   252,   859,   416,    12,   862,    14,   157,
     282,   258,    81,   260,   261,   447,   692,    73,    77,   291,
      12,   453,   689,    92,   291,   291,     5,    12,    97,   165,
     453,    10,   257,     4,   291,    12,    15,   262,   263,   291,
      12,   110,    68,    28,    12,   208,   209,    73,    48,   969,
     109,   483,   484,   958,   708,   487,   960,   489,   288,   289,
      86,   493,   966,   967,   969,   164,   165,   499,   272,   273,
     274,   275,   276,    58,   694,    75,   508,   509,    12,   148,
     512,    12,    82,    12,   850,   517,   278,   279,   499,    12,
     149,    12,   118,    93,   257,   506,    96,    12,    83,   262,
     263,     4,     4,     5,     6,     7,     8,    12,    10,   195,
     196,   360,  1038,    88,    89,   115,    12,   366,    12,   368,
      22,   174,   175,   176,   199,   200,   375,   830,   154,    88,
      89,    90,   132,   836,    88,    89,    90,   840,   207,   165,
      88,    89,    90,   169,   811,    12,   813,    12,    50,   172,
     173,    53,    12,   138,    12,   140,    88,    89,   848,    12,
     827,     4,     5,     6,     7,     8,    12,    10,    48,    48,
     155,   272,   273,   274,    12,  1030,  1031,    88,    89,   428,
     165,     4,     5,     6,     7,     8,    12,    10,    88,    89,
      90,    12,   177,   178,    12,    75,    75,   864,   267,   239,
     240,   241,    82,    82,   453,    12,  1061,    50,    12,  1064,
      53,    12,   835,    93,    93,    12,    96,    96,    12,   841,
     842,   290,   291,    19,    12,   117,    16,   253,    92,  1036,
      53,   663,   287,    12,   483,   115,   115,    12,   487,    12,
     489,    12,   674,   675,   493,    14,    12,    12,    12,   151,
     499,   153,   132,   132,    14,   958,    12,    14,   282,   508,
     170,    13,   163,   512,   696,     5,   969,   699,   517,     5,
      48,     4,    39,   705,   706,   707,    39,    12,   114,   291,
       4,   713,     2,     4,    14,   696,     5,    73,     8,     9,
      10,   981,   282,   179,   165,   179,     5,    75,   241,   198,
    1138,   114,  1157,   735,    82,   258,    12,  1233,   151,    13,
     153,    13,    13,    13,    13,    93,   282,   268,    96,    74,
     752,    13,    13,    13,    13,    13,     4,     4,   151,   752,
    1185,   763,   764,     4,     4,  1142,    12,    12,    12,    12,
      12,   121,     8,    12,    12,  1152,   114,  1233,   980,    12,
      14,    18,    14,    13,   132,    39,  1046,    14,   277,    14,
     197,    19,   197,    12,    12,  1032,  1286,  1057,   282,    14,
      77,   803,  1298,  1211,    14,   807,   175,   809,   810,  1265,
     812,  1286,   180,     4,   254,   817,   264,   180,    13,    13,
     822,   823,     4,    13,    13,    13,    81,   829,   830,  1237,
     233,   833,   834,    64,   836,     5,     5,     5,   840,  1247,
       5,     5,  1298,     5,   663,    74,     5,   849,   850,   830,
       4,  1111,     4,   834,  1114,   674,   675,   859,    14,     5,
     862,  1087,   114,    13,   120,    79,    27,    93,    12,     5,
     282,   256,    39,    13,    13,    77,    13,   696,    13,    13,
     699,    13,    13,    13,    12,    14,   705,   706,   707,    14,
      14,    13,   209,    14,   713,     2,    12,    89,  1306,    13,
      13,     8,     9,    10,    19,    14,    93,   197,   284,   210,
      14,    14,     4,   255,     4,   205,   735,   207,    12,     5,
     266,   211,   212,   122,    13,   927,    14,  1191,   152,   152,
      14,   933,   934,   752,   114,   152,    74,     4,     4,   114,
      13,    12,   163,   165,   234,   764,   286,    12,   238,    12,
      12,    12,    12,   282,    13,     4,   958,    74,   248,   249,
     118,    13,   252,    27,    14,     4,    14,   969,    14,    89,
      89,   191,     4,    16,   152,     4,    12,   156,     5,    12,
      14,   141,     4,   282,   803,   238,     4,     4,   807,    13,
     809,   810,   280,    89,    64,   152,   212,     4,   817,     4,
     285,    13,     5,   822,   823,     5,     5,    13,    12,    77,
     829,   830,    13,  1286,   833,   834,    13,   836,    13,    13,
       4,   840,    12,   165,    13,  1027,   152,    13,  1030,  1031,
     849,   850,  1034,  1035,   152,   133,  1038,   124,    69,   124,
     859,   248,    93,   862,    74,    16,    93,     4,    93,    93,
     133,    93,    93,    13,  1056,   165,   249,   243,     4,  1061,
     244,   119,  1064,   246,   445,   250,   171,  1327,   211,  1295,
     360,   252,   152,   247,   251,   220,   366,   719,   368,   505,
      27,   513,  1084,   238,  1188,   375,  1298,  1089,  1090,  1265,
     197,  1084,   264,   846,   505,   248,  1257,   735,   205,   509,
     207,   212,   958,    22,   211,   212,  1119,  1056,   927,  1112,
    1038,  1218,  1161,  1076,   933,   934,    35,  1119,  1145,    38,
      39,    40,    41,    42,    43,    44,   478,   234,   448,   641,
     474,   238,   627,   760,  1081,   544,   779,   469,   528,   958,
     927,   248,   249,  1211,  1306,   252,  1127,   763,   740,   535,
     969,   992,   749,     7,  1156,   708,   531,  1159,   812,  1161,
      -1,    -1,    81,   453,    -1,   493,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,    -1,
     392,    -1,    -1,  1185,    -1,    -1,    -1,   400,    -1,    -1,
      -1,   110,    -1,   483,    -1,    -1,    -1,   487,    -1,   489,
      -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,  1027,   499,
      -1,  1030,  1031,    -1,    -1,  1034,  1035,    -1,   508,  1038,
      -1,    -1,   512,    -1,    -1,    -1,    -1,   517,    -1,    -1,
      -1,  1233,    -1,    23,    -1,    25,    26,  1056,    -1,    -1,
      -1,    -1,  1061,    -1,    34,  1064,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,    -1,  1257,    -1,    -1,    -1,   366,
      -1,   368,    -1,    53,    -1,  1084,    56,    -1,   375,    -1,
    1089,  1090,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    -1,    -1,  1286,    -1,    -1,    -1,   207,    -1,
      -1,    -1,    -1,    -1,    84,    85,  1298,    -1,    -1,    -1,
    1119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1293,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1156,  1157,   129,
    1159,    -1,  1161,    -1,    -1,    -1,   453,    -1,   267,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,   151,    -1,    -1,    -1,    -1,  1185,    -1,   158,   159,
      -1,   290,   291,   663,    -1,    -1,   483,    -1,    -1,    -1,
     487,    -1,   489,    -1,   674,   675,   493,    -1,    -1,    -1,
      -1,    -1,   499,   183,   184,   185,   186,   187,   188,   189,
     190,   508,    -1,    -1,    -1,   512,   696,    -1,    -1,   699,
     517,    -1,    -1,    -1,  1233,   705,   706,   707,    -1,    -1,
      -1,    -1,    -1,   713,     2,    -1,    -1,    -1,    -1,    -1,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   752,    -1,    -1,    -1,    -1,  1286,    -1,    -1,
      -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,    -1,  1298,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   803,    -1,    -1,    -1,   807,    -1,   809,
     810,    -1,    -1,    -1,    -1,    -1,    -1,   817,    -1,    -1,
      -1,    -1,   822,   823,    -1,    -1,    -1,    -1,    -1,   829,
     830,    -1,    -1,   833,   834,    -1,   836,    -1,    -1,    -1,
     840,    -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,   849,
     850,    -1,    -1,    -1,    -1,    -1,    -1,   674,   675,   859,
      -1,    -1,   862,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   696,
      -1,    -1,   699,    -1,    -1,    -1,    -1,    -1,   705,   706,
     707,    -1,    -1,    -1,    -1,    -1,   713,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   735,   207,
      -1,    -1,    -1,   211,   212,    -1,    -1,   927,    -1,    -1,
      -1,    -1,    -1,   933,   934,   752,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   234,   764,    -1,    -1,
     238,    -1,   231,    -1,    -1,    -1,    -1,    -1,   958,    -1,
     248,   249,    -1,    -1,   252,   244,    -1,    -1,    -1,   969,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,   803,    -1,    -1,    -1,
     807,    -1,   809,   810,   273,    -1,   275,    -1,    -1,    -1,
     817,    -1,    -1,    -1,    -1,   822,   823,   286,    -1,    -1,
      -1,    -1,   829,   830,    -1,    -1,   833,   834,    -1,   836,
      -1,    -1,    -1,   840,    -1,    -1,    -1,  1027,    -1,    -1,
    1030,  1031,   849,   850,  1034,  1035,    -1,    -1,  1038,    -1,
      -1,    -1,   859,    -1,    -1,   862,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,    -1,
      -1,  1061,    -1,    -1,  1064,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,   366,    -1,
     368,    -1,    -1,   362,  1084,    -1,    -1,   375,    -1,  1089,
    1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     927,    -1,    -1,    -1,    -1,    -1,   933,   934,    -1,  1119,
      -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     409,    -1,    -1,   412,   413,    -1,    -1,    -1,    -1,    -1,
     419,   958,    -1,   422,    -1,    -1,   425,    -1,   427,    -1,
     429,   430,   969,    -1,   433,    -1,  1156,    -1,    -1,  1159,
      -1,  1161,   441,    -1,    -1,   453,   445,    -1,   447,   448,
     449,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,  1185,   465,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
      -1,   489,    -1,   482,    -1,   493,    -1,    -1,    -1,    -1,
    1027,   499,    -1,  1030,  1031,    -1,    -1,  1034,  1035,    -1,
      -1,  1038,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,
     509,    -1,    -1,  1233,    -1,    -1,    -1,    -1,    -1,  1056,
      -1,    -1,    -1,    -1,  1061,    -1,    -1,  1064,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   542,   543,    -1,    -1,  1084,    -1,    -1,
      -1,    -1,  1089,  1090,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1298,    -1,
      -1,    -1,  1119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1156,
      -1,    -1,  1159,    -1,  1161,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   640,    -1,   642,    -1,   644,    -1,    -1,  1185,    -1,
      -1,    -1,    -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,
     659,    -1,    -1,    -1,    -1,    -1,   674,   675,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   699,    -1,    -1,    -1,    -1,  1233,   705,   706,   707,
      -1,    -1,    -1,    -1,    -1,   713,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     719,    -1,    -1,   722,    -1,    -1,    -1,   735,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   752,    -1,    -1,   746,    -1,  1286,
      -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,   757,   758,
      -1,  1298,    -1,    -1,   763,    -1,   765,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   781,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   793,   803,   795,    -1,    -1,   807,
     799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   817,
      -1,    -1,    -1,    -1,   822,   823,    -1,    -1,    -1,    -1,
      -1,   829,    -1,    -1,    -1,   833,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   849,   850,    -1,    -1,    -1,    -1,    -1,    -1,   848,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   882,   883,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   907,    -1,
      -1,    -1,    -1,   912,    -1,    -1,    -1,    -1,    -1,   927,
      -1,    -1,    -1,   922,   923,   933,   934,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   981,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1027,
      -1,    -1,    -1,    -1,    -1,    -1,  1034,  1035,    -1,    -1,
    1038,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1046,  1056,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1057,    -1,
      -1,    -1,    -1,  1062,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,  1089,  1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1119,  1111,    -1,    -1,  1114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1156,  1157,
      -1,  1159,    -1,  1161,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,  1188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,  1233,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    76,  1257,    -1,
      -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,   107,    -1,
    1298,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,    -1,   135,   136,   137,    -1,
      -1,    -1,   141,   142,    -1,   144,   145,   146,  1327,    -1,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,   291,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,   110,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,   137,   138,   139,    -1,   141,
     142,    -1,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   288,   289,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,   110,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,   137,    -1,   139,    -1,   141,   142,    -1,   144,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   289,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,   137,
      -1,   139,    -1,   141,   142,    -1,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,   137,   138,   139,    -1,
     141,   142,    -1,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    -1,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,   137,   138,   139,    -1,   141,   142,    -1,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   288,   289,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,    -1,    -1,   110,   111,   112,   113,   114,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
     137,    -1,   139,    -1,   141,   142,    -1,   144,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,   193,   194,   195,   196,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    -1,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,   136,   137,   138,   139,
      -1,   141,   142,    -1,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    12,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,   132,
     133,    -1,   135,   136,   137,    -1,   139,    -1,   141,   142,
      -1,   144,   145,   146,   147,    -1,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      -1,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,    -1,    -1,    -1,
     283,    -1,    -1,    -1,    -1,   288,   289,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    12,    -1,    -1,    15,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,   132,   133,    -1,   135,
     136,   137,    -1,   139,    -1,   141,   142,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   288,   289,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,   132,   133,    -1,   135,   136,   137,    -1,
     139,    -1,   141,   142,    -1,   144,   145,   146,   147,    -1,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,    -1,    -1,    -1,   283,    -1,    -1,    -1,    -1,   288,
     289,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
     132,   133,    -1,   135,   136,   137,    -1,   139,    -1,   141,
     142,    -1,   144,   145,   146,   147,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   288,   289,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    96,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,   132,   133,    -1,
     135,   136,   137,    -1,   139,    -1,   141,   142,    -1,   144,
     145,   146,   147,    -1,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    -1,    -1,    -1,   283,    -1,
      -1,    -1,    -1,   288,   289,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,   132,   133,    -1,   135,   136,   137,
      -1,   139,    -1,   141,   142,    -1,   144,   145,   146,   147,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,   132,   133,    -1,   135,   136,   137,    -1,   139,    -1,
     141,   142,    -1,   144,   145,   146,   147,    -1,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    -1,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   289,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,   132,   133,
      -1,   135,   136,   137,    -1,   139,    -1,   141,   142,    -1,
     144,   145,   146,   147,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   288,   289,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,   132,   133,    -1,   135,   136,
     137,    -1,   139,    -1,   141,   142,    -1,   144,   145,   146,
     147,    -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,   193,   194,   195,   196,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    -1,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288,   289,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,   136,   137,    -1,   139,
      -1,   141,   142,    -1,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,   288,   289,
      10,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,    -1,   135,   136,   137,   138,    -1,
      -1,   141,   142,    -1,   144,   145,   146,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,   165,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
       3,    -1,    -1,    -1,    -1,    -1,   286,    10,    -1,    12,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,
      -1,   144,   145,   146,    -1,    -1,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      -1,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,     3,    -1,    -1,
      -1,    -1,    -1,   286,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,    -1,   135,
     136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,   145,
     146,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,     3,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,    -1,    17,    18,    -1,    20,    21,
     286,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,
     142,    -1,   144,   145,   146,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,     3,    -1,
      -1,    -1,    -1,    -1,   286,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,    -1,
     135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,
     145,   146,    -1,    -1,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     3,    -1,    -1,   283,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,    -1,   135,   136,   137,
      -1,    -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,     3,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    17,    18,   283,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
      -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,
     144,   145,   146,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,     3,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    17,    18,   283,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,   132,   133,    -1,   135,   136,   137,    -1,   139,
      -1,   141,   142,    -1,   144,   145,   146,   147,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,
      -1,   144,   145,   146,    -1,    -1,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      -1,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,    -1,   135,
     136,   137,   138,    -1,    -1,   141,   142,    -1,   144,   145,
     146,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,    -1,   135,   136,   137,   138,
      -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,    -1,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,    -1,   135,   136,   137,   138,    -1,    -1,   141,
     142,    -1,   144,   145,   146,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,    -1,
     135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,
     145,   146,    -1,    -1,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,    -1,   135,   136,   137,
      -1,    -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,     3,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    17,    18,    19,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
      -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,
     144,   145,   146,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,
      87,    88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,
      -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,
     127,   128,   129,   130,   131,    -1,   133,    -1,   135,   136,
     137,    -1,    -1,    -1,   141,   142,    -1,   144,   145,   146,
      -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,   178,   179,   180,   181,    -1,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,   193,   194,   195,   196,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,    -1,   234,   235,    -1,
      -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,    -1,   254,   255,    -1,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,    -1,   135,   136,   137,    -1,    -1,
      -1,   141,   142,    -1,   144,   145,   146,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    -1,    59,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    84,    85,    -1,    87,    88,    89,    90,    -1,    -1,
      -1,    94,    95,    -1,    -1,    98,    99,   100,   101,   102,
     103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,
     123,   124,   125,    -1,   127,   128,   129,   130,   131,    -1,
     133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,
      -1,   144,   145,   146,    -1,    -1,   149,   150,   151,   152,
     153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
     193,   194,   195,   196,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,   225,   226,   227,   228,   229,   230,   231,   232,
      -1,   234,   235,    -1,    -1,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
      -1,   254,   255,    -1,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,    -1,   135,
     136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,   145,
     146,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,
      89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,    -1,    -1,   107,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,
     129,   130,   131,    -1,   133,    -1,   135,   136,   137,    -1,
      -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,    -1,
     149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,
     179,   180,   181,    -1,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,   193,   194,   195,   196,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,    -1,   225,   226,   227,   228,
     229,   230,   231,   232,    -1,   234,   235,    -1,    -1,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,    -1,   254,   255,    -1,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,
     142,    -1,   144,   145,   146,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,
      85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
      -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,
      -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,
     125,    -1,   127,   128,   129,   130,   131,    -1,   133,    -1,
     135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,
     145,   146,    -1,    -1,   149,   150,   151,   152,   153,    -1,
      -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,   178,   179,   180,   181,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,   196,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,    -1,   234,
     235,    -1,    -1,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,    -1,   254,
     255,    -1,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,    -1,   135,   136,   137,
      -1,    -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,    90,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,
     111,   112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,
      -1,    -1,   123,   124,   125,    -1,   127,   128,   129,   130,
     131,    -1,   133,    -1,   135,   136,   137,    -1,    -1,    -1,
     141,   142,    -1,   144,   145,   146,    -1,    -1,   149,   150,
     151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,
     181,    -1,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   193,   194,   195,   196,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,    -1,   225,   226,   227,   228,   229,   230,
     231,   232,    -1,   234,   235,    -1,    -1,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,    -1,   254,   255,    -1,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
      -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,
     144,   145,   146,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,     3,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    17,    18,    -1,
      20,    21,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,   123,   124,   125,    -1,   127,   128,   129,
     130,   131,    -1,   133,    -1,   135,   136,   137,    -1,    -1,
      -1,   141,   142,    -1,   144,   145,   146,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,   181,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,    -1,   234,   235,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,     3,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
      -1,    17,    18,    -1,    20,    21,    -1,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    80,    -1,    -1,    -1,    84,    85,
      -1,    87,    88,    89,    90,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
     116,    -1,    -1,   119,    -1,    -1,    -1,   123,   124,   125,
      -1,   127,   128,   129,   130,   131,    -1,   133,    -1,   135,
     136,   137,    -1,    -1,    -1,   141,   142,    -1,   144,   145,
     146,    -1,    -1,   149,   150,   151,   152,   153,    -1,    -1,
      -1,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,   178,   179,   180,   181,    -1,   183,   184,   185,
     186,   187,   188,   189,   190,   191,    -1,   193,   194,   195,
     196,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,    -1,   225,
     226,   227,   228,   229,   230,   231,   232,    -1,   234,   235,
      -1,    -1,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,    -1,   254,   255,
      -1,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,     3,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,    -1,    17,    18,    -1,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,
      72,    -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    84,    85,    -1,    87,    88,    89,    90,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    -1,    -1,    -1,   111,
     112,   113,   114,    -1,   116,    -1,    -1,   119,    -1,    -1,
      -1,   123,   124,   125,    -1,   127,   128,   129,   130,   131,
      -1,   133,    -1,   135,   136,   137,    -1,    -1,    -1,   141,
     142,    -1,   144,   145,   146,    -1,    -1,   149,   150,   151,
     152,   153,    -1,    -1,    -1,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   176,    -1,   178,   179,   180,   181,
      -1,   183,   184,   185,   186,   187,   188,   189,   190,   191,
      -1,   193,   194,   195,   196,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,    -1,   234,   235,    -1,    -1,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,    -1,   254,   255,    -1,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,     3,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,    -1,    17,
      18,    -1,    20,    21,    -1,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,    87,
      88,    89,    90,    -1,    -1,    -1,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,    -1,    -1,   107,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   116,    -1,
      -1,   119,    -1,    -1,    -1,   123,   124,   125,    -1,   127,
     128,   129,   130,   131,    -1,   133,    -1,   135,   136,   137,
      -1,    -1,    -1,   141,   142,    -1,   144,   145,   146,    -1,
      -1,   149,   150,   151,   152,   153,    -1,    -1,    -1,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
     178,   179,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,   196,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,    -1,   234,   235,    -1,    -1,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,    -1,   254,   255,    -1,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,     3,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,    -1,    17,    18,    -1,    20,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      84,    85,    -1,    87,    88,    89,    90,    -1,    -1,    -1,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,    -1,    -1,   107,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,   116,    -1,    -1,   119,    -1,    -1,    -1,   123,
     124,   125,    -1,   127,   128,   129,   130,   131,    -1,   133,
      -1,   135,   136,   137,    -1,    -1,    -1,   141,   142,    -1,
     144,   145,   146,    -1,    -1,   149,   150,   151,   152,   153,
      -1,    -1,    -1,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,   178,   179,   180,   181,    -1,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,   196,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,    -1,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
      -1,   225,   226,   227,   228,   229,   230,   231,   232,    -1,
     234,   235,    -1,    -1,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,    -1,
     254,   255,    -1,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,     3,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,    -1,    -1,    18,    -1,
      20,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    84,    85,    -1,    87,    88,    89,
      90,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,
      -1,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
      -1,   111,   112,   113,   114,    -1,   116,    -1,    -1,   119,
      -1,    -1,    -1,    -1,   124,   125,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,   136,   137,    -1,    -1,
      -1,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,    -1,    -1,    -1,    -1,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,   179,
     180,    -1,    -1,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,   196,   197,    -1,   199,
     200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,    -1,   254,   255,    -1,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,    -1,   268,   269,
     270,   271,    -1,    -1,    -1,    -1,    -1,   277,   278,   279
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    28,    58,    83,   138,   140,   155,   165,   177,
     178,   295,   296,   297,   298,   299,   304,   305,   309,   311,
     312,   317,   318,   319,   320,   321,   327,   347,   503,   504,
     318,     3,    17,    18,    20,    21,    23,    24,    30,    31,
      33,    36,    37,    45,    46,    47,    49,    53,    54,    55,
      56,    57,    59,    60,    62,    69,    71,    72,    76,    80,
      84,    85,    87,    88,    89,    90,    94,    95,    98,    99,
     100,   101,   102,   103,   104,   107,   111,   112,   113,   114,
     116,   119,   123,   124,   125,   127,   128,   129,   130,   131,
     133,   135,   136,   137,   141,   142,   144,   145,   146,   149,
     150,   151,   152,   153,   158,   159,   161,   162,   166,   167,
     168,   176,   178,   179,   180,   181,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   193,   194,   195,   196,   197,
     199,   200,   201,   202,   203,   204,   205,   206,   211,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   225,
     226,   227,   228,   229,   230,   231,   232,   234,   235,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   254,   255,   257,   258,   259,   260,
     261,   262,   263,   265,   266,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   286,   303,   375,
     438,   447,   479,   485,   487,    74,   193,    91,   171,   488,
       3,   488,   130,   348,   349,   485,   375,   375,     0,    65,
     281,    68,   118,   154,   253,   442,   443,    86,   319,    13,
     485,    12,   165,   500,    14,   313,   314,   375,    74,   375,
       5,    10,    15,    61,   355,     3,   314,   348,   282,    12,
     350,   351,    12,   317,   350,   317,   350,   296,   355,    27,
     355,   355,   169,   495,   355,   442,     3,     4,     5,     6,
       7,     8,    10,    12,    13,    29,    30,    31,    36,    45,
      47,    51,    52,    53,    70,    96,   110,   111,   132,   139,
     147,   151,   181,   206,   214,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   288,
     289,   300,   301,   302,   322,   323,   326,   374,   376,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   428,   429,   430,   435,   437,   438,   439,   446,   447,
     464,   468,   479,   485,   486,   487,   516,   174,   175,   176,
      14,   485,   164,   328,   122,   510,   513,   313,   306,   510,
      12,   283,   356,   357,   358,   412,   485,   140,   349,   352,
     485,    19,   157,   310,   310,   320,   412,   444,   445,   320,
     320,     5,    10,    73,   469,   470,   489,   490,   491,   321,
     495,    12,   318,   392,   412,   419,   500,   412,   431,    12,
      12,    12,    12,    12,    12,     4,    12,   323,   325,    12,
     394,   412,    12,    12,     4,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,   416,   416,    13,   282,    19,    12,   117,    16,
      92,    22,    35,    38,    39,    40,    41,    42,    43,    44,
      81,    92,    97,   110,   207,   267,   290,   291,   423,   424,
     425,   484,   288,   289,   426,   283,   292,   293,   427,   287,
      12,    12,    12,    14,    12,    12,    12,    14,   485,    14,
     392,   500,    12,    19,   481,   482,   483,   485,   328,    12,
     194,   307,   308,   317,   353,   482,    12,   412,    74,   282,
     329,   481,    14,   315,   316,   412,    13,   282,   325,   419,
     165,   328,   502,   165,   328,    20,    60,   345,   282,   170,
     496,   496,   155,   257,   262,   263,   500,   489,   318,    13,
      13,    13,   282,   163,   432,   433,   412,     5,   419,   412,
      61,   283,   412,     5,   412,   412,    13,   419,   283,   412,
     420,   419,   412,   465,   466,   467,   485,   479,   412,   412,
     419,   419,   465,   278,   279,   518,     4,   517,   517,   517,
     517,    53,   151,   428,   428,   269,   270,   271,   412,   440,
     500,   301,    23,    25,    26,    34,    53,    56,    62,    71,
      84,    85,   108,   129,   142,   150,   151,   158,   159,   183,
     184,   185,   186,   187,   188,   189,   190,   475,   476,   477,
     478,    13,   465,   393,   394,     6,     9,   110,   422,   412,
     375,    39,    39,    41,   325,   418,   421,     8,   110,   412,
      22,    81,    97,   207,   114,   412,    39,   291,    15,    17,
     143,   412,   480,   413,   323,   418,   414,   415,   416,   355,
      13,   419,   412,    14,   485,   486,     3,   435,   485,   498,
     499,     4,     4,   485,    14,    14,   485,     5,   511,   483,
      73,   514,   515,   500,   354,   374,   485,   195,   196,   310,
     317,   317,   307,   317,   353,    10,    12,   192,   213,   324,
     325,   359,   360,   361,   362,   363,   364,   371,   375,   377,
     378,   385,   389,   464,   485,   357,   328,   283,   485,   282,
     329,   330,    39,   485,   179,   165,   501,   179,   198,   436,
     445,     5,   241,   497,   497,   114,   492,   258,    12,   472,
     472,   500,    13,   412,   392,   412,    63,   433,   434,    19,
      13,    13,   156,   419,    13,    13,    13,   282,   282,    13,
     282,   442,    13,   282,   182,    74,   442,   442,   442,    13,
      13,   517,   268,   519,    13,    13,    13,    13,    13,    13,
      13,    74,     4,    12,    12,    12,    12,    12,    12,    12,
      18,    13,   422,    16,     8,    66,   412,   421,   412,   114,
     412,   268,   412,   121,   449,    13,    13,    14,   485,    14,
      14,    13,   282,    13,    39,   485,   485,    14,    13,   282,
     277,    13,   282,    14,   197,   197,   500,   310,   317,    19,
      12,   360,   377,    12,    12,   481,   282,    48,    75,    82,
      93,    96,   132,   386,   481,   481,   482,    73,   284,   286,
     370,   491,   505,   506,   507,   508,   509,   510,   481,    14,
      77,   331,    14,   316,   328,   412,   180,   175,   180,   199,
     200,   254,   354,   172,   173,   494,     4,   473,   474,   264,
     471,   471,   148,   148,   412,    64,   475,   375,    13,   448,
     449,   412,   412,   429,    13,   449,   466,   374,   428,   412,
      13,    13,    13,   449,   449,    13,     4,    81,   233,   441,
     441,   412,    74,     5,     5,     5,     5,     5,     5,     5,
     412,   412,    16,    66,   412,     4,    13,    12,   450,   451,
     485,   449,   485,    14,    14,   485,   486,   485,   500,   498,
     500,     4,   485,     5,   114,   374,   485,   500,   485,    13,
      18,   372,   373,   374,   318,   464,   350,   360,    93,   120,
     387,    88,    89,    90,   388,   360,   387,   387,    29,    93,
     379,   351,   208,   209,   392,   365,   366,   485,   481,   485,
      27,    79,   346,   283,   485,   500,    12,     5,   256,   493,
      39,    13,   282,   477,   412,   412,    13,    13,    13,    13,
      13,   282,    13,   448,   448,   448,   412,    77,   449,   449,
      13,   412,    13,   282,    13,    13,    13,    13,    13,    13,
     412,   412,   448,   265,   451,   452,   453,    14,   485,   485,
      14,    14,    13,   209,    14,    12,    12,    13,   282,    13,
      13,   361,   388,   152,   152,    89,   115,   388,   388,    93,
     360,    19,    22,    74,    19,   285,    14,   284,   210,   369,
     512,    14,   355,   392,    14,     4,   255,     4,   474,    90,
     272,   273,   274,   275,   276,   401,   402,   403,   404,   165,
     520,    12,    13,     5,   266,    13,   122,   454,   485,    14,
      14,   485,   486,   485,   500,    74,   485,   390,   391,   485,
     419,   165,   373,    88,    89,    90,    88,    89,    90,   152,
     392,   163,   380,   381,   115,   114,     4,     4,   114,   286,
     366,   368,   392,    12,   196,   211,   485,    12,    78,   236,
     237,   332,   333,   337,   412,   283,    13,    12,    12,    12,
      12,    12,    12,    13,   403,   282,     4,    74,   521,   443,
      13,   375,    27,   442,   485,   485,    14,    14,     4,    14,
      13,   282,   477,    13,   191,    89,    89,    88,    89,    90,
     392,    63,   381,   384,   392,     4,    16,   152,     4,   365,
     156,   367,     5,    12,    12,    14,    13,   141,   282,   238,
     338,   339,     4,   405,   428,     3,   115,     4,     4,   419,
     404,     5,    10,   524,   280,   522,    13,   419,   126,   134,
     455,   456,   485,     3,   487,   152,   391,    89,   148,   212,
     382,    64,     4,     4,    88,    89,   152,   285,    13,     5,
       5,   333,     5,    12,   495,    13,    13,   282,    13,    13,
      13,    13,    13,    15,   524,    77,   523,    22,    50,   153,
     428,   457,   458,   459,   460,     4,   382,    12,   383,   152,
     152,    88,    89,    13,    13,    12,   334,   335,   336,   374,
     418,   165,   340,   428,   524,   153,   428,   458,   461,   462,
     133,   124,   124,    69,   463,   356,    74,    88,    89,    88,
      89,    93,    93,    12,    13,   336,   418,    13,   282,   239,
     240,   241,   248,   344,    72,    72,    16,    50,    77,   109,
     149,    13,   360,    93,    93,    93,    93,   442,   335,     4,
     242,   245,   341,   343,   461,   133,   119,   115,    13,   249,
     243,   246,   244,   342,   392,   250,   165,     4,   252,   247,
     251,   152,   171
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   294,   295,   296,   296,   297,   297,   297,   297,   297,
     298,   299,   299,   299,   300,   300,   301,   301,   302,   302,
     303,   304,   305,   305,   305,   305,   305,   306,   306,   307,
     307,   308,   308,   309,   309,   309,   309,   309,   309,   309,
     310,   311,   311,   312,   313,   314,   315,   315,   316,   317,
     318,   318,   319,   319,   319,   319,   320,   320,   321,   321,
     322,   323,   324,   325,   326,   327,   328,   328,   329,   330,
     330,   331,   331,   332,   332,   333,   333,   333,   334,   334,
     335,   335,   335,   336,   336,   337,   337,   337,   338,   339,
     339,   340,   340,   340,   340,   341,   341,   342,   342,   343,
     343,   343,   344,   344,   344,   344,   345,   345,   345,   346,
     346,   347,   347,   348,   348,   349,   350,   350,   351,   352,
     352,   353,   354,   354,   355,   355,   355,   356,   356,   357,
     357,   358,   358,   358,   358,   359,   359,   360,   360,   360,
     361,   361,   362,   362,   362,   362,   362,   362,   362,   363,
     363,   364,   364,   365,   365,   366,   366,   367,   367,   367,
     367,   367,   367,   367,   368,   368,   369,   369,   370,   370,
     370,   370,   370,   371,   371,   372,   372,   373,   373,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   376,   376,   376,
     376,   377,   377,   378,   378,   378,   379,   380,   380,   381,
     382,   383,   384,   384,   385,   386,   386,   386,   386,   387,
     387,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   389,   390,   390,   391,   392,   392,   393,   393,   394,
     394,   395,   395,   395,   396,   396,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   398,   398,   399,   399,   400,
     400,   401,   401,   401,   402,   402,   402,   402,   402,   402,
     403,   403,   404,   404,   404,   404,   405,   405,   406,   406,
     406,   407,   407,   408,   408,   408,   408,   409,   409,   410,
     410,   411,   412,   412,   412,   413,   413,   414,   414,   415,
     415,   416,   416,   416,   417,   417,   417,   417,   417,   417,
     418,   419,   419,   420,   420,   421,   421,   422,   422,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   424,
     424,   425,   426,   426,   427,   427,   427,   428,   428,   428,
     428,   428,   429,   429,   429,   429,   430,   431,   431,   432,
     432,   433,   433,   434,   434,   435,   435,   435,   435,   435,
     436,   436,   436,   437,   437,   437,   437,   437,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   439,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   439,   439,   440,   440,   440,   441,   442,
     442,   443,   444,   444,   445,   446,   446,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   448,   448,
     449,   449,   450,   451,   452,   453,   453,   453,   454,   454,
     455,   455,   456,   456,   457,   457,   458,   458,   458,   459,
     460,   461,   461,   461,   462,   463,   463,   463,   463,   463,
     464,   464,   465,   465,   466,   466,   467,   467,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   469,   470,   471,   471,   472,   472,   473,   473,   474,
     475,   475,   476,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   478,   478,   478,   479,   479,   479,
     479,   479,   479,   480,   480,   480,   481,   481,   482,   482,
     483,   484,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     486,   486,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   488,   488,   488,   489,   489,   490,
     491,   491,   491,   491,   492,   492,   493,   493,   494,   494,
     494,   495,   495,   495,   496,   496,   497,   497,   498,   498,
     499,   499,   500,   500,   500,   500,   501,   501,   502,   503,
     503,   503,   504,   504,   504,   505,   505,   505,   506,   507,
     508,   509,   510,   511,   511,   512,   512,   512,   513,   513,
     514,   514,   515,   516,   516,   516,   516,   516,   517,   518,
     518,   518,   519,   519,   520,   520,   521,   521,   522,   522,
     522,   523,   523,   524,   524
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     0,     1,     1,     1,     1,
       3,     6,     5,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     3,     3,     6,     5,     7,     6,     6,     8,     7,
       2,     5,     6,     8,     1,     4,     1,     3,     3,     1,
       5,     6,     1,     4,     4,     4,     1,     4,     1,     3,
       3,     1,     1,     1,     1,     8,     0,     2,     2,     0,
       1,     0,     4,     1,     3,     2,     1,     5,     1,     3,
       4,     1,     1,     1,     2,     2,     1,     1,     5,     0,
       2,     0,     2,     2,     2,     2,     2,     0,     2,     0,
       2,     4,     0,     2,     4,     8,     0,     1,     1,     0,
       2,     2,     3,     1,     3,     4,     0,     1,     3,     1,
       3,     3,     1,     3,     0,     1,     1,     1,     3,     2,
       1,     1,     3,     5,     7,     1,     3,     1,     1,     1,
       1,     3,     4,     3,     2,     2,     3,     2,     2,     4,
       4,     6,     3,     1,     3,     5,     1,     0,     4,     4,
       5,     5,     5,     5,     0,     1,     0,     1,     0,     1,
       1,     1,     1,     6,     4,     3,     1,     4,     1,     1,
       3,     5,     7,     6,     9,     8,     8,     7,     1,     3,
       5,     4,     7,     6,     6,     5,     2,     1,     3,     5,
       7,     1,     1,     6,     5,     3,     5,     1,     2,     4,
       6,     3,     0,     2,     4,     3,     3,     3,     2,     0,
       1,     0,     3,     3,     4,     3,     4,     3,     4,     4,
       5,     6,     1,     3,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     5,     4,     8,
       6,     1,     2,     1,     1,     4,     1,     4,     1,     4,
       1,     3,     4,     4,     4,     4,     1,     3,     3,     3,
       3,     5,     6,     3,     5,     4,     6,     3,     4,     3,
       4,     2,     1,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     5,     0,     1,     1,
       2,     4,     4,     0,     2,     1,     1,     1,     1,     1,
       0,     2,     2,     5,     5,     4,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     6,     6,     6,     6,     5,     1,     6,
       6,     5,     7,     6,     4,     1,     1,     1,     5,     0,
       1,     3,     1,     3,     3,     4,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       2,     2,     3,     1,     4,     0,     1,     3,     0,     3,
       0,     3,     1,     1,     1,     1,     2,     2,     1,     2,
       4,     1,     2,     1,     2,     0,     3,     2,     2,     3,
       3,     4,     1,     3,     1,     1,     3,     3,     4,     3,
       4,     6,     6,     6,     4,     1,     4,     1,     6,     1,
       1,     4,     4,     0,     2,     0,     3,     1,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     4,     6,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     0,     1,     3,
       5,     1,     1,     1,     0,     2,     0,     2,     0,     1,
       2,     0,     4,     4,     0,     2,     0,     2,     1,     1,
       1,     3,     0,     6,     6,     8,     0,     5,     3,     5,
       6,     3,     5,     7,     3,     1,     1,     1,     5,     6,
       6,     5,     4,     1,     3,     5,     5,     4,     0,     1,
       0,     1,     8,     5,     4,     4,     4,     4,     8,     0,
       1,     1,     0,     2,     0,     2,     0,     2,     0,     2,
       2,     0,     2,     1,     1
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
#if HANA_DEBUG

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
# if defined HANA_LTYPE_IS_TRIVIAL && HANA_LTYPE_IS_TRIVIAL

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
#else /* !HANA_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HANA_DEBUG */


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
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5454 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5460 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 5: /* INTNUM  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5466 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 6: /* BOOL  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5472 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 7: /* APPROXNUM  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5478 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 8: /* NULLX  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5484 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 9: /* UNKNOWN  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5490 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 10: /* QUESTIONMARK  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5496 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 295: /* sql_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5502 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 296: /* stmt_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5508 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 297: /* stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5514 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 298: /* special_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5520 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 299: /* call_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5526 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 300: /* sql_argument_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5532 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 301: /* sql_argument  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5538 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 302: /* value_expression  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5544 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 303: /* sp_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5550 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 304: /* dql_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5556 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 305: /* dml_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5562 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 306: /* opt_partition_rest  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5568 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 307: /* opt_column_ref_list_with_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5574 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 308: /* overriding_value  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5580 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 309: /* insert_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5586 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 310: /* from_constructor  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5592 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 311: /* delete_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5598 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 312: /* update_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5604 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 313: /* delete_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5610 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 314: /* update_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5616 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 315: /* update_elem_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5622 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 316: /* update_elem  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5628 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 317: /* select_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5634 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 318: /* query_expression  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5640 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 319: /* query_expression_body  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5646 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 320: /* query_term  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5652 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 321: /* query_primary  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5658 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 322: /* select_with_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5664 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 323: /* subquery  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5670 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 324: /* sap_table_subquery  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5676 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 325: /* table_subquery  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5682 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 326: /* row_subquery  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5688 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 327: /* simple_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5694 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 328: /* opt_where  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5700 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 329: /* from_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5706 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 330: /* opt_from_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5712 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 331: /* opt_groupby  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5718 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 332: /* grouping_element_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5724 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 333: /* grouping_element  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5730 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 334: /* row_order_by_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5736 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 335: /* row_order_by  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5742 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 336: /* column_ref_perens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5748 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 337: /* group_set_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5754 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 338: /* grouping_option  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5760 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 339: /* grouping_best  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5766 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 340: /* grouping_subtotal  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5772 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 341: /* grouping_prefix_tb  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5778 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 342: /* grouping_prefix  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5784 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 343: /* grouping_structured_res  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5790 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 344: /* grouping_text_filter  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5796 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 345: /* opt_asc_desc  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5802 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 346: /* opt_having  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5808 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 347: /* with_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5814 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 348: /* with_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5820 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 349: /* common_table_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5826 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 350: /* opt_derived_column_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5832 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 351: /* simple_ident_list_with_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5838 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 352: /* simple_ident_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5844 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 353: /* column_ref_list_with_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5850 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 354: /* column_ref_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5856 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 355: /* opt_distinct  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5862 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 356: /* select_expr_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5868 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 357: /* projection  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5874 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 358: /* asterisk_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5880 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 359: /* from_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5886 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 360: /* table_reference  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5892 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 361: /* table_primary  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5898 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 362: /* table_primary_non_join  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5904 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 363: /* lateral_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5910 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 364: /* associated_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5916 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 365: /* associated_ref_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5922 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 366: /* associated_ref  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5928 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 367: /* opt_many2one_part  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5934 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 368: /* opt_search_condition  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5940 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 369: /* opt_tablesample  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5946 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 370: /* opt_table_qualify  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5952 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 371: /* collection_derived_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5958 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 372: /* collection_value_expr_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5964 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 373: /* collection_value_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5970 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 374: /* column_ref  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5976 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 375: /* relation_factor  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5982 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 376: /* func_relation_factor  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5988 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 377: /* joined_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 5994 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 378: /* qualified_join  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6000 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 379: /* case_join  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6006 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 380: /* case_join_when_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6012 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 381: /* case_join_when  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6018 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 382: /* ret_join_on  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6024 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 383: /* select_expr_list_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6030 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 384: /* opt_case_join_else  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6036 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 385: /* cross_join  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6042 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 386: /* join_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6048 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 388: /* join_cardinality  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6054 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 389: /* hana_construct_table  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6060 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 390: /* construct_column_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6066 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 391: /* construct_column  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6072 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 392: /* search_condition  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6078 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 393: /* boolean_term  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6084 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 394: /* boolean_factor  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6090 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 395: /* boolean_test  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6096 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 396: /* boolean_primary  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6102 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 397: /* predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6108 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 398: /* like_regexpr_redicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6114 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 399: /* member_of_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6120 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 400: /* bool_function  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6126 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 401: /* contains_param3  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6132 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 402: /* search_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6138 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 403: /* search_param_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6144 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 404: /* search_param  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6150 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 405: /* expr_const_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6156 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 406: /* comparison_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6162 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 407: /* between_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6168 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 408: /* like_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6174 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 409: /* in_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6180 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 410: /* null_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6186 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 411: /* exists_predicate  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6192 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 412: /* row_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6198 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 413: /* factor0  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6204 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 414: /* factor1  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6210 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 415: /* factor2  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6216 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 416: /* factor3  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6222 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 417: /* factor4  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6228 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 418: /* row_expr_list_parens  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6234 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 419: /* row_expr_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6240 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 420: /* row_expr_star  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6246 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 421: /* in_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6252 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 422: /* truth_value  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6258 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 428: /* expr_const  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6264 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 429: /* expr_const_string  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6270 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 430: /* case_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6276 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 431: /* case_arg  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6282 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 432: /* when_clause_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6288 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 433: /* when_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6294 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 434: /* case_default  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6300 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 435: /* func_expr  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6306 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 436: /* opt_nulls  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6312 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 437: /* aggregate_expression  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6318 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 438: /* aggregate_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6324 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 439: /* sap_specific_function  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6330 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 440: /* trim_char  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6336 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 441: /* within_group  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6342 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 442: /* opt_order_by_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6348 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 443: /* order_by_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6354 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 444: /* order_by_expression_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6360 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 445: /* order_by_expression  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6366 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 446: /* ranking_windowed_function  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6372 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 447: /* ranking_function_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6378 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 448: /* opt_over_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6384 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 449: /* over_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6390 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 450: /* window_specification  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6396 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 451: /* window_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6402 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 452: /* window_specification_details  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6408 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 453: /* opt_existing_window_name  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6414 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 454: /* opt_window_partition_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6420 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 455: /* opt_window_frame_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6426 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 456: /* window_frame_units  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6432 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 457: /* window_frame_extent  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6438 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 458: /* window_frame_start  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6444 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 459: /* window_frame_preceding  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6450 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 460: /* window_frame_between  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6456 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 461: /* window_frame_bound  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6462 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 462: /* window_frame_following  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6468 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 463: /* opt_window_frame_exclusion  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6474 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 464: /* scalar_function  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6480 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 465: /* table_function_param_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6486 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 466: /* table_function_param  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6492 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 467: /* expr_point_val  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6498 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 468: /* function_call_keyword  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6504 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 469: /* for_xml  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6510 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 470: /* for_json  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6516 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 471: /* opt_returns_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6522 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 472: /* opt_option_string_list_p  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6528 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 473: /* option_string_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6534 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 474: /* option_string  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6540 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 475: /* data_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6546 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 476: /* array_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6552 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 477: /* predefined_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6558 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 478: /* lob_data_type  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6564 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 479: /* primary_datetime_field  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6570 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 481: /* opt_as_label  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6576 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 482: /* as_label  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6582 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 483: /* label  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6588 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 484: /* collate_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6594 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 485: /* name_r  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6600 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 486: /* name_f  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6606 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 487: /* reserved  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6612 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 488: /* top_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6618 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 489: /* opt_for_update  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6624 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 490: /* for_share_lock  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6630 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 491: /* for_update  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6636 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 492: /* opt_of_ident_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6642 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 493: /* opt_ignore_lock  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6648 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 494: /* wait_nowait  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6654 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 495: /* limit_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6660 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 496: /* offset_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6666 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 497: /* limit_total  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6672 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 498: /* with_hint_param  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6678 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 499: /* with_hint_param_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6684 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 500: /* hint_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6690 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 501: /* opt_with_range_restrict  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6696 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 502: /* with_primary_key  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6702 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 503: /* upsert_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6708 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 504: /* replace_stmt  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6714 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 505: /* for_system_time  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6720 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 506: /* sys_as_of_spec  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6726 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 507: /* sys_from_to_spec  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6732 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 508: /* sys_between_spec  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6738 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 509: /* for_application_time  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6744 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 510: /* partition_restriction  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6750 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 511: /* intnum_list  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6756 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 512: /* tablesample_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6762 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 513: /* opt_partition_restriction  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6768 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 514: /* opt_for_application_time_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6774 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 515: /* for_application_time_clause  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6780 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 516: /* regexpr_str_function  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6786 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 517: /* regex_parameter  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6792 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 518: /* opt_st_or_af  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6798 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 519: /* opt_flag  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6804 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 520: /* opt_with_string  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6810 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 521: /* opt_from_position  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6816 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 522: /* opt_occurrence_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6822 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 523: /* opt_group_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6828 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
        break;

    case 524: /* param_num  */
#line 98 "sqlparser_hana.yacc" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 6834 "sqlparser_hana_bison.cpp" /* yacc.c:1257  */
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
# if defined HANA_LTYPE_IS_TRIVIAL && HANA_LTYPE_IS_TRIVIAL
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
#line 67 "sqlparser_hana.yacc" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 6951 "sqlparser_hana_bison.cpp" /* yacc.c:1429  */
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
#line 275 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    g_QuestMarkId = 0;
    (yyval.node) = (yyvsp[-1].node);
    result->result_tree_ = (yyvsp[-1].node);
    result->accept = true;
    YYACCEPT;
}
#line 7146 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 287 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
#line 7155 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 294 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7161 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 303 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SET_HANA, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SET_S_FORMAT_HANA;
}
#line 7170 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 310 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CALL_HANA_SERIALIZE_FORMAT;
}
#line 7179 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 315 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, 3, (yyvsp[-3].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &CALL_HANA_SERIALIZE_FORMAT;
}
#line 7188 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 320 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, 3, (yyvsp[-1].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &CALL_HANA_SERIALIZE_FORMAT2;
}
#line 7197 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 329 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7206 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 337 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 7215 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 342 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 7224 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 370 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7230 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 375 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) =nullptr;}
#line 7236 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 380 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node)= Node::makeTerminalNode(E_STRING,"OVERRIDING SYSTEM VALUE");}
#line 7242 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 381 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node)= Node::makeTerminalNode(E_STRING,"OVERRIDING USER VALUE");}
#line 7248 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 386 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, (yyvsp[-2].node));
    as->serialize_format = &AS_SERIALIZE_FORMAT;
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7259 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 393 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
     Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), nullptr, nullptr, nullptr, (yyvsp[-1].node));
     as->serialize_format = &AS_SERIALIZE_FORMAT;
     (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, (yyvsp[0].node));
     (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7270 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 400 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * source = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    source->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
    Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), nullptr, nullptr, (yyvsp[-3].node));
    as->serialize_format = &AS_SERIALIZE_FORMAT;
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, source);
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7283 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 409 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * source = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    source->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
    Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-3].node), nullptr, nullptr, nullptr, (yyvsp[-2].node));
    as->serialize_format = &AS_SERIALIZE_FORMAT;
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, source);
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7296 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
     Node * source = Node::makeNonTerminalNode(E_INSERT_SELECT, 2, (yyvsp[-1].node), (yyvsp[0].node));
     source->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
     Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-3].node), nullptr, nullptr, nullptr, (yyvsp[-2].node));
     as->serialize_format = &AS_SERIALIZE_FORMAT;
     (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, source);
     (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7309 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 427 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * source = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    source->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
    Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-4].node));
    as->serialize_format = &AS_SERIALIZE_FORMAT;
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, source);
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7322 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 436 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
     Node * source = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
     source->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
     Node * as = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-4].node), nullptr, nullptr, nullptr, (yyvsp[-3].node));
     as->serialize_format = &AS_SERIALIZE_FORMAT;
     (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, as, source);
     (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 7335 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 448 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
#line 7344 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 457 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		(yyvsp[-2].node),		/* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,        /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		(yyvsp[-1].node),		/* E_DELETE_OPT_WHERE 6 */
    		(yyvsp[0].node) 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    (yyval.node)->serialize_format = &DELETE_SERIALIZE_FORMAT;
}
#line 7361 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 470 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
        nullptr,	/* E_DELETE_OPT_WITH 0 */
        nullptr,	/* E_DELETE_OPT_TOP 1 */
        (yyvsp[-2].node),		/* E_DELETE_DELETE_RELATION 2 */
        nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
        nullptr,        /* E_DELETE_OPT_OUTPUT 4 */
        nullptr,	/* E_DELETE_FROM_LIST 5 */
        (yyvsp[-1].node),		/* E_DELETE_OPT_WHERE 6 */
        (yyvsp[0].node) 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    (yyval.node)->serialize_format = &DELETE_S_FORMAT;
}
#line 7378 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 487 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE, E_UPDATE_PROPERTY_CNT,
    		nullptr,	/* E_UPDATE_OPT_WITH 0 */
    		(yyvsp[-6].node),	/* E_UPDATE_OPT_TOP 1 */
    		(yyvsp[-5].node),		    /* E_UPDATE_UPDATE_RELATION 2 */
    		nullptr,	/* E_UPDATE_UPDATE_RELATION_OPT_TABLE_HINT 3 */
    		(yyvsp[-3].node),		    /* E_UPDATE_UPDATE_ELEM_LIST 4 */
    		nullptr,	/* E_UPDATE_OPT_OUTPUT 5 */
    		(yyvsp[-2].node),	        /* E_UPDATE_FROM_LIST 6 */
    		(yyvsp[-1].node),		    /* E_UPDATE_OPT_WHERE 7 */
    		(yyvsp[0].node)		    /* E_UPDATE_OPT_QUERY_HINT 8 */);
    (yyval.node)->serialize_format = &UPDATE_SERIALIZE_FORMAT;
}
#line 7396 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 507 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    if((yyvsp[-2].node) == nullptr && (yyvsp[-1].node) == nullptr && (yyvsp[0].node) == nullptr) {
        (yyval.node) = (yyvsp[-3].node);
    } else {
        (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, (yyvsp[-2].node));
        (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
    }

}
#line 7410 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 539 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7419 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 547 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
#line 7428 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 556 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
    // 0 , 1  2 already
    // $$->setChild(E_DIRECT_SELECT_FOR_UPDATE, $2);
    // $$->setChild(E_DIRECT_HINT_CLAUSE, $3);
}
#line 7439 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 567 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, (yyvsp[-4].node), nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT_HANA;

    if((yyvsp[-3].node) || (yyvsp[-2].node)){
        std::string val = "";
        if((yyvsp[-3].node)){val += (yyvsp[-3].node)->text(); delete((yyvsp[-3].node));}
        if((yyvsp[-2].node)){val += (yyvsp[-2].node)->text(); delete((yyvsp[-2].node));}
        Node * str  = Node::makeTerminalNode(E_STRING, val);
        (yyval.node)->setChild(2, str);
    }

}
#line 7457 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 581 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-4].node), nullptr,(yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT_HANA;

    if((yyvsp[-3].node) || (yyvsp[-2].node)){
        std::string val = "";
        if((yyvsp[-3].node)){val += (yyvsp[-3].node)->text(); delete((yyvsp[-3].node)); val += " ";}
        if((yyvsp[-2].node)){val += (yyvsp[-2].node)->text(); delete((yyvsp[-2].node)); }
        Node * str  = Node::makeTerminalNode(E_STRING, val);
        (yyval.node)->setChild(2, str);
    }
}
#line 7474 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 597 "sqlparser_hana.yacc" /* yacc.c:1646  */
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
                        nullptr,              /* E_SELECT_OPT_INTO 18 */
                        nullptr
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT_HANA;
}
#line 7505 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 624 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* set_op = Node::makeTerminalNode(E_SET_EXCEPT, "EXCEPT");
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
                        nullptr,              /* E_SELECT_OPT_INTO 18 */
                        nullptr
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT_HANA;
}
#line 7536 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 651 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* set_op = Node::makeTerminalNode(E_SET_EXCEPT, "MINUS");
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
                        nullptr,              /* E_SELECT_OPT_INTO 18 */
                        nullptr
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT_HANA;
}
#line 7567 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 682 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* set_op = Node::makeTerminalNode(E_SET_INTERSECT, "INTERSECT");
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
                        nullptr,              /* E_SELECT_OPT_INTO 18 */
                        nullptr
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT_HANA;
}
#line 7598 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 713 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
   // if ($2->getChild(E_DIRECT_SELECT_WITH)) {
    //    yyerror(&@1, result, scanner, "error use common table expression");
   //     YYABORT;
   // }
    //$$ = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2->getChild(E_DIRECT_SELECT_SELECT_CLAUSE));
    //$$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
    //$2->setChild(E_DIRECT_SELECT_SELECT_CLAUSE, nullptr);
    //delete($2);

    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7616 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 731 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7625 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 749 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                    (yyvsp[-5].node),             /* E_SELECT_DISTINCT 0 */
                    (yyvsp[-4].node),             /* E_SELECT_SELECT_EXPR_LIST 1 */
                    (yyvsp[-3].node),             /* E_SELECT_FROM_LIST 2 */
                    (yyvsp[-2].node),             /* E_SELECT_OPT_WHERE 3 */
                    (yyvsp[-1].node),             /* E_SELECT_GROUP_BY 4 */
                    (yyvsp[0].node),             /* E_SELECT_HAVING 5 */
                    nullptr,        /* E_SELECT_SET_OPERATION 6 */
                    nullptr,        /* E_SELECT_ALL_SPECIFIED 7 */
                    nullptr,        /* E_SELECT_FORMER_SELECT_STMT 8 */
                    nullptr,        /* E_SELECT_LATER_SELECT_STMT 9 */
                    nullptr,             /* E_SELECT_ORDER_BY 10 */
                    nullptr,            /* E_SELECT_LIMIT 11 */
                    nullptr,        /* E_SELECT_FOR_UPDATE 12 */
                    nullptr,        /* E_SELECT_HINTS 13 */
                    nullptr,        /* E_SELECT_WHEN 14 */
                    (yyvsp[-6].node),             /* E_SELECT_OPT_TOP 15 */
                    nullptr,        /* E_SELECT_OPT_WITH 16 */
                    nullptr,        /* E_SELECT_OPT_OPTION 17 */
	                nullptr,         /* E_SELECT_OPT_INTO 18 */
	                nullptr
                    );
    (yyval.node)->serialize_format = &SELECT_SERIALIZE_FORMAT;
}
#line 7655 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 777 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7661 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 779 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
#line 7670 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 788 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FROM_SERIALIZE_FORMAT;
}
#line 7679 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 794 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7685 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 798 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7691 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 800 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
#line 7700 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 809 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7709 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 816 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"()"); }
#line 7715 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 819 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string name = (yyvsp[-4].node)->text();
    delete((yyvsp[-4].node));
    if((yyvsp[-3].node)){
        name += (yyvsp[-3].node)->text();
        delete((yyvsp[-3].node));
    }
    Node * name_n = Node::makeTerminalNode(E_IDENTIFIER, name);
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name_n, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 7731 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 834 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7740 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 841 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string ss = (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    if((yyvsp[-1].node)){
        ss += (yyvsp[-1].node)->text();
        delete((yyvsp[-1].node));
    }
    Node * node_s  = Node::makeTerminalNode(E_STRING, ss );
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, node_s);
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7756 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 858 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) =  Node::makeTerminalNode(E_STRING, "()" );
}
#line 7764 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 864 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS ");}
#line 7770 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 865 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROLLUP "); }
#line 7776 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 866 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)  = Node::makeTerminalNode(E_IDENTIFIER, "CUBE "); }
#line 7782 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 870 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
      std::string val;
      if((yyvsp[-4].node)){ val += (yyvsp[-4].node)->text(); delete((yyvsp[-4].node)); }
      if((yyvsp[-3].node)){ val += (yyvsp[-3].node)->text(); delete((yyvsp[-3].node)); }
      if((yyvsp[-2].node)){ val += (yyvsp[-2].node)->text(); delete((yyvsp[-2].node)); }
      if((yyvsp[-1].node)){ val += (yyvsp[-1].node)->text(); delete((yyvsp[-1].node)); }
      if((yyvsp[0].node)){ val += (yyvsp[0].node)->text(); delete((yyvsp[0].node)); }
      if(!val.empty()){
        (yyval.node) = Node::makeTerminalNode(E_STRING, val);
      } else { (yyval.node) = nullptr; }
}
#line 7798 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 884 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7804 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 885 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, "BEST "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 7810 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 888 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7816 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 889 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {     (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH SUBTOTAL " ); }
#line 7822 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 890 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH BALANCE " ); }
#line 7828 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 891 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {     (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH TOTAL " ); }
#line 7834 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 895 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
     std::string pref_s ;
     if((yyvsp[-1].node)){ pref_s += (yyvsp[-1].node)->text(); delete((yyvsp[-1].node)); }
     if((yyvsp[0].node)){ pref_s += (yyvsp[0].node)->text(); delete((yyvsp[0].node)); }
     if(!pref_s.empty()){
         (yyval.node) = Node::makeTerminalNode( E_STRING, pref_s );
     } else { (yyval.node) = nullptr;  }
}
#line 7847 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 903 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, " MULTIPLE RESULTSETS " ); }
#line 7853 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 906 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7859 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 907 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {     (yyval.node) = Node::makeTerminalNode(E_STRING, "PREFIX "+ (yyvsp[0].node)->text() ); delete((yyvsp[0].node)); }
#line 7865 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 910 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7871 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 911 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, "STRUCTURED RESULT " ); }
#line 7877 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 912 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, "STRUCTURED RESULT WITH OVERVIEW " ); }
#line 7883 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 915 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7889 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 916 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node) = Node::makeTerminalNode(E_STRING, "TEXT_FILTER " + (yyvsp[0].node)->text() + " " ); delete((yyvsp[0].node)); }
#line 7895 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 917 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node) = Node::makeTerminalNode(E_STRING, "TEXT_FILTER " + (yyvsp[-2].node)->text() +  " FILL UP " );  delete((yyvsp[-2].node)); }
#line 7901 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 918 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node) = Node::makeTerminalNode(E_STRING, "TEXT_FILTER " + (yyvsp[-6].node)->text() +  " FILL UP SORT MATCHES TO TOP " ); delete((yyvsp[-6].node)); }
#line 7907 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 955 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "");
}
#line 7915 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 959 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
#line 7923 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 963 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
#line 7931 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 969 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7937 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 971 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
#line 7946 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 981 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
#line 7955 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 986 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
#line 7964 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 995 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 7973 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1004 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, E_COMMON_TABLE_EXPR_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT;
}
#line 7982 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1011 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7988 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1017 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 7997 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1026 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8006 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1033 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8015 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1041 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8024 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1047 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8030 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1049 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 8038 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1053 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 8046 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1061 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8055 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1069 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    if (!(yyvsp[0].node)) {
    	(yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, (yyvsp[-1].node));
    	(yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
    }
    else {
	Node* alias_node = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
        alias_node->serialize_format = &AS_SERIALIZE_FORMAT;

        (yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, alias_node);
        (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
    }
}
#line 8073 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1087 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STAR, "*");
}
#line 8081 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1091 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, nullptr, (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 8091 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1097 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 8101 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1103 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 8111 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1113 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8120 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1129 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8129 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1140 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, (yyvsp[-2].node));
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8138 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1145 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8147 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1150 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8156 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1155 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8165 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1160 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8174 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1165 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8183 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1170 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 8192 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1178 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LATERAL_QUERY, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &LATERAL_QUERY_SERIALIZE_FORMAT;
}
#line 8201 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1183 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LATERAL_QUERY, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &LATERAL_QUERY_SERIALIZE_FORMAT;
}
#line 8210 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1191 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASSOCIATED_TABLE, 3, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &ASSOCIATED_TAB_SERIALIZE_FORMAT;
}
#line 8219 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1196 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASSOCIATED_TABLE,3, (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ASSOCIATED_TAB_SERIALIZE_FORMAT;
}
#line 8228 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1204 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASSOCIATED_REF_LIST, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &ASSOCIATED_LIST_SERIALIZE_FORMAT;
}
#line 8237 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1211 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASSOCIATED_REF, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &ASSOCIATED_REF_SERIALIZE_FORMAT;
}
#line 8246 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1216 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ASSOCIATED_REF, 3, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8255 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1222 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr; }
#line 8261 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1223 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING TO ONE JOIN"); }
#line 8267 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1224 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING TO MANY JOIN"); }
#line 8273 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1225 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING MANY TO ONE JOIN"); }
#line 8279 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1226 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING MANY TO MANY JOIN"); }
#line 8285 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1227 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING ONE TO ONE JOIN"); }
#line 8291 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1228 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "USING ONE TO MANY JOIN"); }
#line 8297 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1231 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr; }
#line 8303 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1236 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 8309 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1241 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 8315 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1251 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * ordinality = Node::makeTerminalNode(E_STRING, "WITH ORDINALITY ");
    (yyval.node) = Node::makeNonTerminalNode(E_UNNEST_TABLE, 2, (yyvsp[-3].node), ordinality);
    (yyval.node)->serialize_format = &UNNEST_TABLE_FORMAT;
}
#line 8325 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1257 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UNNEST_TABLE, 2, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &UNNEST_TABLE_FORMAT;
}
#line 8334 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1266 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COLLECT_VAL_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8343 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1275 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COLLECT_VAL, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &COLLECT_VAL_FORMAT;
}
#line 8352 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1314 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8362 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1320 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8372 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1326 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8382 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1332 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8392 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1338 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, (yyvsp[-5].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8402 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1344 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-8].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8412 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1350 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, (yyvsp[-7].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8422 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1356 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, (yyvsp[-5].node), (yyvsp[-7].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8432 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1362 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, (yyvsp[-6].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 8442 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1372 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 8451 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1377 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 8460 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1382 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 8469 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1387 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 8478 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1392 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 8487 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1397 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 8496 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1402 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 8505 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1407 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, (yyvsp[-4].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 8514 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1412 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_VAR, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VAR_SERIALIZE_FORMAT;
}
#line 8523 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1420 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 8532 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1425 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 8541 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1430 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 8550 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1435 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 8559 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1452 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 8568 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1457 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 8578 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1463 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN_TABLE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8587 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1483 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN, 2, (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CASE_JOIN_SERIALIZE_FORMAT;
}
#line 8596 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1491 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN_WHEN_LIST, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 8605 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1498 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN_WHEN, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CASE_JOIN_WHEN_SERIALIZE_FORMAT;
}
#line 8614 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1505 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN_RET, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CASE_JOIN_RET_SERIALIZE_FORMAT;
}
#line 8623 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1512 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8632 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1518 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8638 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1520 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_JOIN_ELSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &CASE_JOIN_ELSE_SERIALIZE_FORMAT;
}
#line 8647 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1528 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 8657 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1554 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "FULL ";
    if ((yyvsp[-1].ival))
    {
        val += "OUTER ";
    }
    if((yyvsp[0].node)){
        val+=(yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_JOIN_FULL, val);
}
#line 8674 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1567 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "LEFT ";
    if ((yyvsp[-1].ival))
    {
        val += "OUTER ";
    }
    if((yyvsp[0].node)){
        val+=(yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_JOIN_LEFT, val);
}
#line 8691 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1580 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "RIGHT ";
    if ((yyvsp[-1].ival))
    {
        val+="OUTER ";
    }
    if((yyvsp[0].node)){
        val += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_JOIN_RIGHT, val);

}
#line 8709 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1594 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "INNER ";
    if((yyvsp[0].node)){
        val += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_JOIN_INNER, val);
}
#line 8722 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1605 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 8728 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1606 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.ival) = 1; /*this is a flag*/}
#line 8734 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1610 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8740 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1611 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "MANY TO MANY"); }
#line 8746 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1612 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "MANY TO ONE"); }
#line 8752 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1613 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "MANY TO EXACT ONE"); }
#line 8758 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1614 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ONE TO MANY"); }
#line 8764 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1615 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "EXACT ONE TO MANY"); }
#line 8770 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1616 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ONE TO ONE"); }
#line 8776 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1617 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "EXACT ONE TO ONE"); }
#line 8782 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1618 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ONE TO EXACT ONE"); }
#line 8788 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1619 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "EXACT ONE TO EXACT ONE"); }
#line 8794 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1624 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CONSTRUCT_FROM_TABLE, E_CONSTRUCT_FROM_TABLE_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CONSTRUCT_FROM_TABLE_SERIALIZE_FORMAT;
}
#line 8803 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1633 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CONSTRUCT_COL_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8812 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1641 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CONSTRUCT_COL, E_CONSTRUCT_COL_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CONSTRUCT_COL_SERIALIZE_FORMAT;
}
#line 8821 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1651 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 8830 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1660 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 8839 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1669 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 8848 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1678 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 8857 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1683 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 8866 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1692 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8875 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1721 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE_REGEXPR, 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE_REGEXPR);
}
#line 8884 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1726 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE_REGEXPR, 3, (yyvsp[-2].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE_REGEXPR);
}
#line 8893 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1733 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_MEMBER, 2, (yyvsp[-4].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_MEMBER);
}
#line 8902 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1738 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MEMBER, 2, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_MEMBER);
}
#line 8911 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1745 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * node_str = Node::makeTerminalNode(E_STRING, "CONTAINS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		node_str, (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 8922 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1752 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * node_str = Node::makeTerminalNode(E_STRING, "CONTAINS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        node_str, (yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 8933 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1762 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = (yyvsp[-1].node)->text() + " " + (yyvsp[0].node)->text();
    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
    delete((yyvsp[-1].node));
    delete((yyvsp[0].node));
}
#line 8944 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1771 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "EXACT"); }
#line 8950 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1773 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "EXACT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 8960 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 266:
#line 1778 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FUZZY"); }
#line 8966 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 267:
#line 1780 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "FUZZY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 8976 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1785 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "LINGUISTIC"); }
#line 8982 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1787 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "LINGUISTIC");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 8992 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1796 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 9001 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1802 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "WEIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 9011 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1808 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "FULLTEXT");
    Node * on_ = Node::makeTerminalNode(E_IDENTIFIER, "ON");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, on_, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 9022 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1815 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "FULLTEXT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 9032 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1821 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "LANGUAGE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
#line 9042 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1830 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 9051 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1838 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9060 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1843 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9069 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1848 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9078 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1858 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 9087 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1863 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 9096 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1871 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 9105 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1876 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 9114 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1881 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 9123 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1886 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 9132 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1894 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 9141 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1899 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 9150 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1907 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 9159 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1912 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 9168 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1920 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 9177 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1930 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 9186 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1935 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9195 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1944 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9204 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1953 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 9213 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1962 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POW);
}
#line 9222 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1971 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POS);
}
#line 9231 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1976 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
#line 9240 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1992 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 9249 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 2000 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 9258 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 2008 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " * "); }
#line 9264 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 2021 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 9270 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 2022 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LT; }
#line 9276 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 2023 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 9282 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 2024 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GT; }
#line 9288 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 2025 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_EQ; }
#line 9294 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 2026 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 9300 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 2027 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 9306 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 2028 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 9312 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2029 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 9318 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2030 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 9324 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2034 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 9330 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2035 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 9336 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2041 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.nodetype) = Node::comp_all_some_any_op_form((yyvsp[-1].nodetype), (yyvsp[0].ival));
}
#line 9344 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2047 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_ADD; }
#line 9350 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2048 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MINUS; }
#line 9356 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2052 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MUL; }
#line 9362 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 2053 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_DIV; }
#line 9368 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 2054 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_REM; }
#line 9374 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2068 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE" + (yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 9380 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2069 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING,  "TIMESTAMP" + (yyvsp[0].node)->text()); delete((yyvsp[0].node));  }
#line 9386 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2075 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_CASE);
}
#line 9395 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2082 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9401 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2089 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 9410 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2097 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 9419 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2102 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 9428 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2109 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9434 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2111 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
#line 9443 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2127 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9449 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2128 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS FIRST"); }
#line 9455 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2129 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS LAST"); }
#line 9461 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2135 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "COUNT");
    Node* star = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		name, star, nullptr, nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9473 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2143 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "COUNT");
    Node * dist = Node::makeTerminalNode(E_IDENTIFIER, "DISTINCT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		name, dist, (yyvsp[-1].node), nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9485 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2151 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "COUNT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9496 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2158 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), nullptr,  (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9506 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2164 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* name = Node::makeTerminalNode(E_STRING, "CHAR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 9517 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2173 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORR"); }
#line 9523 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2174 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORR_SPEARMAN"); }
#line 9529 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2175 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
#line 9535 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2176 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MEDIAN"); }
#line 9541 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2177 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
#line 9547 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2178 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
#line 9553 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2179 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
#line 9559 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2180 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV"); }
#line 9565 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2181 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR"); }
#line 9571 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2182 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
#line 9577 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2183 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
#line 9583 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2184 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
#line 9589 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2185 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
#line 9595 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2190 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "BINNING");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            name, (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 9606 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2197 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "SERIES_FILTER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            name, (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 9617 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2204 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT");
    Node * from = Node::makeTerminalNode(E_STRING, "FROM");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, from, nullptr, (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9629 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2212 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, (yyvsp[0].node), (yyvsp[-3].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9640 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2219 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, (yyvsp[0].node), (yyvsp[-3].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9651 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2226 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, (yyvsp[0].node), (yyvsp[-3].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9662 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2233 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "NTILE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            name, (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 9673 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2241 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT");
    Node * over = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text() + (yyvsp[0].node)->text());
    delete((yyvsp[-1].node));
    delete((yyvsp[0].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, over, (yyvsp[-3].node) ,nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9687 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2251 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC");
    Node * over = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text() + (yyvsp[0].node)->text());
    delete((yyvsp[-1].node));
    delete((yyvsp[0].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, over, (yyvsp[-3].node) ,nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9701 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2261 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, nullptr, (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9712 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2268 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "TRIM");
    std::string param1;
    if((yyvsp[-4].node)){ param1 += (yyvsp[-4].node)->text(); param1 += " "; delete((yyvsp[-4].node)); }
    param1 += (yyvsp[-3].node)->text();
    delete((yyvsp[-3].node));
    param1 += " FROM ";
     Node * param = Node::makeTerminalNode(E_IDENTIFIER, param1);
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, (yyvsp[-1].node), nullptr, param, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9729 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2281 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "TRIM");
    std::string param1 = (yyvsp[-3].node)->text();
    delete((yyvsp[-3].node));
    param1 += " FROM ";
    Node * param = Node::makeTerminalNode(E_IDENTIFIER, param1);
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
             name, (yyvsp[-1].node), nullptr, param, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9744 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2292 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "TRIM");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 9755 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2300 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node)  = Node::makeTerminalNode(E_STRING, "LEADING"); }
#line 9761 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2301 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node)  = Node::makeTerminalNode(E_STRING, "TRAILING"); }
#line 9767 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2302 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {  (yyval.node)  = Node::makeTerminalNode(E_STRING, "BOTH"); }
#line 9773 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2307 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WITHIN_GROUP, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &WITHIN_GROUP_SERIALIZE_FORMAT;
}
#line 9782 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2314 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node)=nullptr; }
#line 9788 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2320 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &AGG_ORDER_SERIALIZE_FORMAT;
}
#line 9797 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2328 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 9806 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2335 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY_EXPR, 4,
        		(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 9816 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2344 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), nullptr, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 9826 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2350 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 9836 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2359 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
#line 9842 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2360 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
#line 9848 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2361 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
#line 9854 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2362 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
#line 9860 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2363 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
#line 9866 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2364 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LAG"); }
#line 9872 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2365 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LEAD"); }
#line 9878 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2366 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANDOM_PARTITION"); }
#line 9884 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2367 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WEIGHTED_AVG"); }
#line 9890 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2368 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUBIC_SPLINE_APPROX"); }
#line 9896 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2369 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LINEAR_APPROX"); }
#line 9902 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2373 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr;}
#line 9908 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2378 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node));
}
#line 9916 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2382 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
#line 9925 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2391 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 9931 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2400 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
#line 9940 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2407 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9946 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2411 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SERIES TABLE "+s3);
    delete((yyvsp[0].node));
}
#line 9956 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2419 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9962 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2421 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 9968 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2425 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 9974 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2427 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+s3);
    delete((yyvsp[-2].node)); delete((yyvsp[-1].node)); delete((yyvsp[0].node));
}
#line 9984 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2435 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
#line 9990 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2436 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
#line 9996 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2445 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
#line 10002 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2446 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
#line 10008 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2451 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" PRECEDING"); delete((yyvsp[-1].node)); }
#line 10014 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2456 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text()); delete((yyvsp[-2].node)); delete((yyvsp[0].node)); }
#line 10020 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2461 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
#line 10026 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 2466 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" FOLLOWING"); delete((yyvsp[-1].node)); }
#line 10032 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 2470 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 10038 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 2471 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
#line 10044 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 2472 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
#line 10050 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2473 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
#line 10056 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 2474 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
#line 10062 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2479 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10072 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2485 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10082 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2496 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 10091 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2508 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
        (yyval.node) = Node::makeNonTerminalNode(E_POINT_VALUE, 2, (yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node)->serialize_format = &POINT_VALUE_FORMAT;
}
#line 10100 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2513 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
        (yyval.node) = Node::makeNonTerminalNode(E_POINT_VALUE, 2, (yyvsp[-2].node), (yyvsp[0].node));
        (yyval.node)->serialize_format = &POINT_VALUE_FORMAT;
}
#line 10109 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2524 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10119 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2530 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10130 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2537 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10141 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2544 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10155 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2554 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 10166 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2561 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-3].node), nullptr, nullptr, transcoding_name);
    (yyval.node)->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
#line 10179 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2570 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10190 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2577 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 10201 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2584 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10212 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2591 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 10223 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2598 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 10236 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2607 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 10247 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2614 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 10258 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2623 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* xml = Node::makeTerminalNode(E_STRING, "XML");
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_CLAUSE_HANA, 4, xml, (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &FOR_CLAUSE_FORMAT;
}
#line 10268 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2630 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node* json = Node::makeTerminalNode(E_STRING, "JSON");
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_CLAUSE_HANA, 4, json, (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &FOR_CLAUSE_FORMAT;
}
#line 10278 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2637 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 10284 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2639 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_RETURNS_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &RETURNS_CLAUSE_FORMAT;
}
#line 10293 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2645 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 10299 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2647 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 10308 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2655 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 10317 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2662 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPTION_STRING, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OPTION_STRING_FORMAT;
}
#line 10326 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2679 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    (yyvsp[-1].node)->set_text( (yyvsp[-1].node)->text() + " ARRAY ");
}
#line 10335 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2685 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "DATE");}
#line 10341 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2686 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "TIME");}
#line 10347 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2687 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "SECONDDATE");}
#line 10353 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2688 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP");}
#line 10359 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2689 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "TINYINT");}
#line 10365 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2690 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "SMALLINT");}
#line 10371 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2691 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "INTEGER");}
#line 10377 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2692 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "INT");  }
#line 10383 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2693 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "BIGINT");}
#line 10389 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2694 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "SMALLDECIMAL");}
#line 10395 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2695 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "REAL");}
#line 10401 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2696 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "DOUBLE");}
#line 10407 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2697 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "TEXT");}
#line 10413 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2698 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "BINTEXT");}
#line 10419 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2699 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR");}
#line 10425 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2700 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10431 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2701 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "NVARCHAR");}
#line 10437 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2702 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "NVARCHAR("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10443 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2703 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "ALPHANUM");}
#line 10449 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2704 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "ALPHANUM("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10455 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 2705 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "VARBINARY");}
#line 10461 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2706 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "VARBINARY("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10467 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2707 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "SHORTTEXT");}
#line 10473 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2708 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "SHORTTEXT("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10479 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2709 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL");}
#line 10485 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2710 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10491 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2711 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-3].node));delete((yyvsp[-1].node)); }
#line 10497 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 2712 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT");}
#line 10503 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 2713 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT("+(yyvsp[-1].node)->text()+")"); delete((yyvsp[-1].node)); }
#line 10509 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 2714 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "BOOLEAN");}
#line 10515 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 2718 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB");}
#line 10521 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 2719 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB");}
#line 10527 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 2720 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB");}
#line 10533 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 2727 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "YEAR");
}
#line 10541 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 2731 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MONTH");
}
#line 10549 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 2735 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DAY");
}
#line 10557 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 2739 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "HOUR");
}
#line 10565 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 2743 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MINUTE");
}
#line 10573 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 2747 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 10581 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 2756 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 10587 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 2757 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.ival) = 1; }
#line 10593 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 2758 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.ival) = 2; }
#line 10599 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 2762 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 10605 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 2767 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 10611 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 2778 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "COLLATE "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 10620 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 2790 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOCATE_REGEXPR"); }
#line 10626 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 2791 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCCURRENCES_REGEXPR"); }
#line 10632 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 2792 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REPLACE_REGEXPR"); }
#line 10638 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 2793 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUBSTRING_REGEXPR"); }
#line 10644 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 2794 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUBSTR_REGEXPR"); }
#line 10650 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 2795 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG"); }
#line 10656 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 2796 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHAR"); }
#line 10662 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 2797 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONTAINS"); }
#line 10668 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 2798 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINNING"); }
#line 10674 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 2799 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT"); }
#line 10680 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 2800 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE"); }
#line 10686 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 2801 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE"); }
#line 10692 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 2802 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE"); }
#line 10698 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 2803 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NTILE"); }
#line 10704 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 2804 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT"); }
#line 10710 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 2805 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC"); }
#line 10716 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 2806 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TRIM"); }
#line 10722 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 2807 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
#line 10728 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 2808 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WEIGHT");  }
#line 10734 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 2809 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FULLTEXT");  }
#line 10740 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 2810 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LANGUAGE");  }
#line 10746 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 2811 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LINGUISTIC");  }
#line 10752 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 2812 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FUZZY");  }
#line 10758 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 2813 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ANY");  }
#line 10764 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 2823 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
#line 10770 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 2824 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
#line 10776 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 2825 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
#line 10782 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 2826 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY"); }
#line 10788 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 567:
#line 2827 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINARY"); }
#line 10794 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 568:
#line 2828 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CAST"); }
#line 10800 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 2829 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTERS"); }
#line 10806 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 570:
#line 2830 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
#line 10812 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 571:
#line 2831 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
#line 10818 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 2832 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FOLLOWING"); }
#line 10824 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 2833 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INTERVAL"); }
#line 10830 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 2834 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
#line 10836 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 2835 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
#line 10842 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 2836 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
#line 10848 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 2837 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
#line 10854 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 2838 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
#line 10860 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 2839 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECEDING"); }
#line 10866 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 580:
#line 2840 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
#line 10872 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 581:
#line 2841 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RECURSIVE"); }
#line 10878 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 2842 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
#line 10884 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 2843 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
#line 10890 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 2844 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
#line 10896 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 585:
#line 2845 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UNBOUNDED"); }
#line 10902 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 2846 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 10908 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 587:
#line 2847 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
#line 10914 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 588:
#line 2848 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
#line 10920 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 589:
#line 2849 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OF"); }
#line 10926 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 590:
#line 2850 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
#line 10932 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 591:
#line 2851 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 10938 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 592:
#line 2852 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME");  }
#line 10944 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 593:
#line 2853 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DESC"); }
#line 10950 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 594:
#line 2854 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
#line 10956 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 595:
#line 2855 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
#line 10962 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 596:
#line 2856 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
#line 10968 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 597:
#line 2857 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXCLUDE"); }
#line 10974 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 598:
#line 2858 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ASC"); }
#line 10980 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 599:
#line 2859 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }
#line 10986 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 600:
#line 2860 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }
#line 10992 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 601:
#line 2861 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
#line 10998 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 602:
#line 2862 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT"); }
#line 11004 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 603:
#line 2863 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TO"); }
#line 11010 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 604:
#line 2864 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DOUBLE"); }
#line 11016 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 605:
#line 2865 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MOD"); }
#line 11022 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 606:
#line 2866 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MANY"); }
#line 11028 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 607:
#line 2867 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONE"); }
#line 11034 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 608:
#line 2868 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRIMARY"); }
#line 11040 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 609:
#line 2869 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "KEY"); }
#line 11046 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 610:
#line 2870 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SECONDDATE"); }
#line 11052 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 611:
#line 2871 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TINYINT"); }
#line 11058 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 612:
#line 2872 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SMALLDECIMAL"); }
#line 11064 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 613:
#line 2873 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TEXT"); }
#line 11070 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 614:
#line 2874 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINTEXT"); }
#line 11076 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 615:
#line 2875 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ALPHANUM"); }
#line 11082 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 616:
#line 2876 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARBINARY"); }
#line 11088 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 617:
#line 2877 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SHORTTEXT"); }
#line 11094 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 618:
#line 2878 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REPLACE"); }
#line 11100 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 619:
#line 2879 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PARAMETERS"); }
#line 11106 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 620:
#line 2880 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "HISTORY"); }
#line 11112 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 621:
#line 2881 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVERRIDING"); }
#line 11118 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 622:
#line 2882 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM"); }
#line 11124 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 623:
#line 2883 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "USER"); }
#line 11130 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 624:
#line 2884 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VALUE"); }
#line 11136 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 625:
#line 2885 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXACT"); }
#line 11142 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 626:
#line 2886 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BERNOULLI"); }
#line 11148 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 627:
#line 2887 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NCHAR"); }
#line 11154 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 628:
#line 2890 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BEST"); }
#line 11160 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 629:
#line 2891 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUBTOTAL"); }
#line 11166 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 630:
#line 2892 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BALANCE"); }
#line 11172 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 631:
#line 2893 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TOTAL"); }
#line 11178 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 632:
#line 2894 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTIPLE"); }
#line 11184 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 633:
#line 2895 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RESULTSETS"); }
#line 11190 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 634:
#line 2896 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PREFIX"); }
#line 11196 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 635:
#line 2897 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STRUCTURED"); }
#line 11202 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 636:
#line 2898 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RESULT"); }
#line 11208 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 637:
#line 2899 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVERVIEW"); }
#line 11214 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 638:
#line 2900 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TEXT_FILTER"); }
#line 11220 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 639:
#line 2901 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FILL"); }
#line 11226 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 640:
#line 2902 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UP"); }
#line 11232 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 641:
#line 2903 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MATCHES"); }
#line 11238 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 642:
#line 2904 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SORT"); }
#line 11244 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 643:
#line 2905 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROWCOUNT"); }
#line 11250 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 644:
#line 2906 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOCKED"); }
#line 11256 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 645:
#line 2908 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SHARE"); }
#line 11262 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 646:
#line 2909 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOCK"); }
#line 11268 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 647:
#line 2910 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UTCTIMESTAMP"); }
#line 11274 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 648:
#line 2911 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COMMIT"); }
#line 11280 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 649:
#line 2912 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ID"); }
#line 11286 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 650:
#line 2913 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "JSON"); }
#line 11292 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 651:
#line 2914 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "XML"); }
#line 11298 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 652:
#line 2917 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SERIES"); }
#line 11304 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 653:
#line 2918 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TABLE");  }
#line 11310 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 654:
#line 2919 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ORDINALITY");  }
#line 11316 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 655:
#line 2920 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FLAG");  }
#line 11322 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 656:
#line 2921 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LEADING");  }
#line 11328 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 657:
#line 2922 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TRAILING");  }
#line 11334 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 658:
#line 2923 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BOTH");  }
#line 11340 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 659:
#line 2924 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FIRST");  }
#line 11346 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 660:
#line 2925 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LAST");  }
#line 11352 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 661:
#line 2926 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PORTION");  }
#line 11358 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 662:
#line 2927 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "START");  }
#line 11364 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 663:
#line 2928 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AFTER");  }
#line 11370 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 664:
#line 2929 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE");}
#line 11376 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 665:
#line 2930 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INT");}
#line 11382 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 666:
#line 2931 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FLOAT");}
#line 11388 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 667:
#line 2932 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SMALLINT");}
#line 11394 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 668:
#line 2933 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INTEGER");}
#line 11400 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 669:
#line 2934 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIGINT");}
#line 11406 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 670:
#line 2935 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NVARCHAR");}
#line 11412 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 671:
#line 2936 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DECIMAL");}
#line 11418 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 672:
#line 2937 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DEC");}
#line 11424 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 673:
#line 2938 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REAL");}
#line 11430 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 674:
#line 2942 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11436 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 675:
#line 2944 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TOP_CLAUSE, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TOP_CLAUSE_FORMAT;
}
#line 11445 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 676:
#line 2949 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TOP_CLAUSE, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TOP_CLAUSE_FORMAT;
}
#line 11454 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 677:
#line 2973 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr;}
#line 11460 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 679:
#line 2978 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " FOR SHARE LOCK "); }
#line 11466 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 680:
#line 2982 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_UPDATE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &FOR_UPDATE_FORMAT_HANA;
}
#line 11475 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 684:
#line 2992 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 11481 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 685:
#line 2994 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * p_of = Node::makeTerminalNode(E_STRING, "OF");
    (yyval.node) = Node::makeNonTerminalNode(E_OF_COLUMS, 2, p_of, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 11491 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 686:
#line 3001 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 11497 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 687:
#line 3002 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "IGNORE LOCKED");}
#line 11503 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 688:
#line 3005 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 11509 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 689:
#line 3006 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_NOWAIT, "NOWAIT");}
#line 11515 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 690:
#line 3008 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WAIT_INT, 1,  (yyvsp[0].node));
    (yyval.node)->serialize_format = &WAIT_TIME_FORMAT;
}
#line 11524 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 691:
#line 3015 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11530 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 692:
#line 3017 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT_HANA;
}
#line 11539 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 693:
#line 3022 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT_HANA;
}
#line 11548 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 694:
#line 3029 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11554 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 695:
#line 3031 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_NUM_FORMAT;
}
#line 11563 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 696:
#line 3038 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11569 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 697:
#line 3040 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TOTAL ROWCOUNT");
}
#line 11577 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 701:
#line 3052 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 11586 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 702:
#line 3059 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11592 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 703:
#line 3061 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
     std::string ss = (yyvsp[-2].node)->text();
     delete((yyvsp[-2].node));
    std::string sval = "WITH HINT(" + ss + ")";
    if((yyvsp[0].node)){
        sval += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_STRING, sval);
}
#line 11607 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 704:
#line 3072 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string ss = (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    std::string sval = "WITH RANGE_RESTRICTION(" + ss + ")";
    if((yyvsp[0].node)){
        sval += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_STRING, sval);
}
#line 11622 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 705:
#line 3083 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string ss1 = (yyvsp[-4].node)->text();
    delete((yyvsp[-4].node));
    std::string ss2 = (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    std::string sval = "WITH PARAMETERS(" + ss1 +"=" + ss2 + ")";
    if((yyvsp[0].node)){
        sval += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node) = Node::makeTerminalNode(E_STRING, sval);
}
#line 11639 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 706:
#line 3098 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11645 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 707:
#line 3100 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string sval = "WITH RANGE_RESTRICTION(" + (yyvsp[-1].node)->text() + ")";
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING, sval);
}
#line 11655 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 708:
#line 3109 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH PRIMARY KEY");
}
#line 11663 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 709:
#line 3116 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPSERT, 6, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), NULL,NULL);
    (yyval.node)->serialize_format = &UPSERT_SERIALIZE_FORMAT;
}
#line 11672 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 710:
#line 3121 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {

    (yyval.node) = Node::makeNonTerminalNode(E_UPSERT, 6, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), NULL, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &UPSERT_SERIALIZE_FORMAT;
}
#line 11682 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 711:
#line 3127 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPSERT, 6, (yyvsp[-1].node), NULL, (yyvsp[0].node), NULL, NULL,NULL);
    (yyval.node)->serialize_format = &UPSERT_SERIALIZE_FORMAT;
}
#line 11691 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 712:
#line 3134 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_REPLACE, 5, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = &REPLACE_SERIALIZE_FORMAT;
}
#line 11700 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 713:
#line 3139 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * pwith = Node::makeTerminalNode(E_STRING, " WITH PRIMARY KEY");
    (yyval.node) = Node::makeNonTerminalNode(E_REPLACE, 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), NULL, pwith);
    (yyval.node)->serialize_format = &REPLACE_SERIALIZE_FORMAT;
}
#line 11710 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 714:
#line 3145 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_REPLACE, 5, (yyvsp[-1].node), NULL, (yyvsp[0].node), NULL, NULL);
    (yyval.node)->serialize_format = &REPLACE_SERIALIZE_FORMAT;
}
#line 11719 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 718:
#line 3157 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR SYSTEM_TIME AS OF "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 11728 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 719:
#line 3164 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR SYSTEM_TIME FROM "+(yyvsp[-2].node)->text()+" TO "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));
    delete((yyvsp[0].node));
}
#line 11738 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 720:
#line 3172 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR SYSTEM_TIME BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));
    delete((yyvsp[0].node));
}
#line 11748 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 721:
#line 3180 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR APPLICATION_TIME AS OF "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 11757 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 722:
#line 3187 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "PARTITION("+(yyvsp[-1].node)->text()+")";
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING,val );
}
#line 11767 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 724:
#line 3196 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 11776 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 725:
#line 3203 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "TABLESAMPLE BERNOULLI("+(yyvsp[-1].node)->text()+")";
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING,val );
}
#line 11786 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 726:
#line 3209 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "TABLESAMPLE SYSTEM("+(yyvsp[-1].node)->text()+")";
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING,val );
}
#line 11796 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 727:
#line 3215 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = "TABLESAMPLE("+(yyvsp[-1].node)->text()+")";
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeTerminalNode(E_STRING,val );
}
#line 11806 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 728:
#line 3223 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11812 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 730:
#line 3226 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 11818 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 732:
#line 3231 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string ss = "FOR PORTION OF APPLICATION_TIME FROM ";
    ss += (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    ss += " TO ";
    ss += (yyvsp[0].node)->text();
    delete((yyvsp[0].node));
    (yyval.node)= Node::makeTerminalNode(E_STRING, ss);
}
#line 11832 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 733:
#line 3244 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "LOCATE_REGEXPR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, nullptr, nullptr, (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 11842 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 734:
#line 3250 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "OCCURRENCES_REGEXPR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 11852 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 735:
#line 3256 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "REPLACE_REGEXPR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 11862 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 736:
#line 3262 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "SUBSTRING_REGEXPR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 11872 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 737:
#line 3268 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "SUBSTR_REGEXPR");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT, name, nullptr, nullptr, (yyvsp[-1].node), nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_314_SERIALIZE_FORMAT;
}
#line 11882 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 738:
#line 3276 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    std::string val = (yyvsp[-7].node)->text();
    delete((yyvsp[-7].node));
    if((yyvsp[-6].node)){
        val += " ";
        val += (yyvsp[-6].node)->text();
        delete((yyvsp[-6].node));
    }
    val +=" IN ";
    val += (yyvsp[-4].node)->text();
    delete((yyvsp[-4].node));
    if((yyvsp[-3].node)){
        val+= " ";
        val+=(yyvsp[-3].node)->text();
        delete((yyvsp[-3].node));
    }
    if((yyvsp[-2].node)){
        val+= " ";
        val+=(yyvsp[-2].node)->text();
        delete((yyvsp[-2].node));
    }
    if((yyvsp[-1].node)){
        val+= " ";
        val+=(yyvsp[-1].node)->text();
        delete((yyvsp[-1].node));
    }
    if((yyvsp[0].node)){
        val+= " ";
        val+=(yyvsp[0].node)->text();
        delete((yyvsp[0].node));
    }
    (yyval.node)= Node::makeTerminalNode(E_STRING, val );
}
#line 11920 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 739:
#line 3310 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr;}
#line 11926 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 740:
#line 3311 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)= Node::makeTerminalNode(E_STRING, "START" ); }
#line 11932 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 741:
#line 3312 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)= Node::makeTerminalNode(E_STRING, "AFTER" ); }
#line 11938 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 742:
#line 3315 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node) = nullptr;}
#line 11944 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 743:
#line 3317 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STRING, "FLAG "+(yyvsp[0].node)->text() );
    delete((yyvsp[0].node));
}
#line 11953 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 744:
#line 3322 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr;}
#line 11959 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 745:
#line 3324 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STRING, "WITH "+(yyvsp[0].node)->text() );
    delete((yyvsp[0].node));
}
#line 11968 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 746:
#line 3329 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr;}
#line 11974 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 747:
#line 3331 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STRING, "FROM "+(yyvsp[0].node)->text() );
    delete((yyvsp[0].node));
}
#line 11983 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 748:
#line 3336 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr;}
#line 11989 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 749:
#line 3338 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STRING, "OCCURRENCE "+(yyvsp[0].node)->text() );
    delete((yyvsp[0].node));
}
#line 11998 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 750:
#line 3342 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)= Node::makeTerminalNode(E_STRING, "OCCURRENCE ALL"); }
#line 12004 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 751:
#line 3345 "sqlparser_hana.yacc" /* yacc.c:1646  */
    { (yyval.node)=nullptr;}
#line 12010 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;

  case 752:
#line 3347 "sqlparser_hana.yacc" /* yacc.c:1646  */
    {
    (yyval.node)= Node::makeTerminalNode(E_STRING, "GROUP "+(yyvsp[0].node)->text() );
    delete((yyvsp[0].node));
}
#line 12019 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
    break;


#line 12023 "sqlparser_hana_bison.cpp" /* yacc.c:1646  */
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
#line 3356 "sqlparser_hana.yacc" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */
