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
#define YYSTYPE         ORACLE_STYPE
#define YYLTYPE         ORACLE_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         oracle_parse
#define yylex           oracle_lex
#define yyerror         oracle_error
#define yydebug         oracle_debug
#define yynerrs         oracle_nerrs


/* Copy the first part of user declarations.  */
#line 1 "oracle.y" /* yacc.c:339  */

/**
 * This Grammar is designed for oracle.
 * https://github.com/Raphael2017/SQL/blob/master/sql-2003-2.bnf
 * sqlparser.y
 * defines sqlparser_oracle_bison.h
 * outputs sqlparser_oracle_bison.cpp
 *
 * Bison Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "sqlparser_oracle_bison.h"
#include "sqlparser_oracle_flex.h"
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


#line 110 "sqlparser_oracle_bison.cpp" /* yacc.c:339  */

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
   by #include "sqlparser_oracle_bison.h".  */
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
#line 42 "oracle.y" /* yacc.c:355  */

// %code requires block

#include "node.h"

#line 154 "sqlparser_oracle_bison.cpp" /* yacc.c:355  */

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
#line 85 "oracle.y" /* yacc.c:355  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 380 "sqlparser_oracle_bison.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 410 "sqlparser_oracle_bison.cpp" /* yacc.c:358  */

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
         || (defined ORACLE_LTYPE_IS_TRIVIAL && ORACLE_LTYPE_IS_TRIVIAL \
             && defined ORACLE_STYPE_IS_TRIVIAL && ORACLE_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  142
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  193
/* YYNRULES -- Number of rules.  */
#define YYNRULES  586
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1050

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   462

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   219,     2,     2,     2,   222,     2,     2,
      13,    14,   215,   217,   214,   218,    15,   221,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   211,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   216,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   212,   220,   213,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    16,    17,
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
     208,   209,   210
};

#if ORACLE_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   245,   245,   256,   257,   265,   266,   267,   268,   269,
     270,   274,   281,   286,   297,   311,   316,   321,   326,   334,
     335,   343,   348,   356,   357,   361,   365,   369,   370,   371,
     375,   383,   388,   393,   398,   403,   412,   421,   438,   454,
     455,   462,   463,   470,   471,   472,   477,   478,   486,   495,
     503,   513,   525,   526,   553,   580,   610,   611,   641,   642,
     655,   662,   664,   666,   668,   676,   702,   730,   731,   734,
     735,   744,   752,   753,   761,   762,   770,   771,   772,   782,
     783,   787,   792,   800,   801,   809,   818,   821,   825,   832,
     833,   834,   838,   839,   849,   854,   862,   863,   872,   880,
     881,   885,   893,   894,   902,   903,   907,   914,   915,   923,
     937,   941,   942,   950,   951,   955,   956,   968,   973,   978,
     983,   988,   993,  1043,  1048,  1055,  1063,  1072,  1079,  1086,
    1093,  1103,  1104,  1109,  1113,  1119,  1125,  1134,  1140,  1146,
    1152,  1158,  1229,  1230,  1238,  1243,  1248,  1285,  1286,  1287,
    1288,  1292,  1298,  1306,  1311,  1317,  1322,  1331,  1340,  1347,
    1356,  1367,  1378,  1389,  1396,  1397,  1402,  1403,  1411,  1412,
    1420,  1421,  1429,  1430,  1435,  1443,  1444,  1462,  1463,  1464,
    1465,  1466,  1467,  1468,  1469,  1473,  1482,  1490,  1498,  1503,
    1511,  1516,  1521,  1526,  1534,  1539,  1547,  1552,  1560,  1561,
    1562,  1565,  1574,  1575,  1580,  1588,  1589,  1597,  1598,  1606,
    1607,  1615,  1616,  1621,  1629,  1630,  1631,  1632,  1637,  1638,
    1642,  1643,  1651,  1652,  1659,  1659,  1664,  1665,  1666,  1667,
    1668,  1669,  1670,  1671,  1672,  1673,  1677,  1678,  1683,  1690,
    1691,  1695,  1696,  1697,  1698,  1702,  1703,  1704,  1705,  1706,
    1707,  1708,  1709,  1710,  1711,  1716,  1724,  1725,  1729,  1730,
    1738,  1743,  1751,  1752,  1761,  1762,  1763,  1764,  1769,  1775,
    1781,  1787,  1793,  1805,  1820,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829,  1830,  1834,  1843,  1844,  1845,  1846,
    1847,  1851,  1855,  1864,  1869,  1873,  1881,  1882,  1886,  1887,
    1892,  1893,  1902,  1903,  1907,  1908,  1912,  1913,  1914,  1918,
    1922,  1927,  1928,  1929,  1933,  1937,  1938,  1939,  1940,  1941,
    1945,  1951,  1963,  1969,  1976,  1983,  1990,  1999,  2006,  2013,
    2020,  2027,  2036,  2043,  2050,  2063,  2064,  2065,  2066,  2070,
    2078,  2083,  2088,  2093,  2102,  2110,  2116,  2121,  2129,  2134,
    2139,  2144,  2145,  2150,  2151,  2152,  2153,  2154,  2155,  2159,
    2167,  2172,  2176,  2182,  2186,  2187,  2192,  2199,  2204,  2205,
    2210,  2215,  2222,  2226,  2230,  2234,  2238,  2242,  2246,  2250,
    2254,  2261,  2268,  2272,  2277,  2282,  2287,  2291,  2295,  2300,
    2305,  2310,  2314,  2318,  2325,  2326,  2330,  2335,  2340,  2345,
    2350,  2355,  2360,  2364,  2368,  2372,  2376,  2380,  2384,  2391,
    2396,  2400,  2404,  2411,  2416,  2421,  2426,  2431,  2436,  2441,
    2445,  2450,  2454,  2459,  2463,  2467,  2474,  2479,  2483,  2488,
    2495,  2500,  2504,  2509,  2513,  2518,  2523,  2528,  2533,  2538,
    2542,  2547,  2551,  2556,  2560,  2567,  2572,  2577,  2582,  2590,
    2594,  2598,  2605,  2609,  2613,  2620,  2624,  2631,  2632,  2633,
    2637,  2638,  2642,  2643,  2647,  2652,  2662,  2663,  2667,  2668,
    2672,  2673,  2674,  2675,  2676,  2677,  2678,  2682,  2684,  2685,
    2686,  2687,  2688,  2689,  2690,  2691,  2692,  2693,  2694,  2699,
    2700,  2701,  2702,  2703,  2704,  2705,  2706,  2707,  2708,  2709,
    2710,  2711,  2712,  2713,  2714,  2715,  2716,  2717,  2718,  2719,
    2720,  2721,  2723,  2724,  2725,  2726,  2727,  2728,  2729,  2730,
    2731,  2732,  2733,  2734,  2735,  2736,  2737,  2738,  2742,  2743,
    2744,  2745,  2748,  2749,  2750,  2751,  2752,  2757,  2758,  2765,
    2772,  2773,  2781,  2782,  2789,  2790,  2793,  2794,  2795,  2802,
    2809,  2810,  2813,  2814,  2817,  2818,  2819,  2822,  2823,  2831,
    2832,  2835,  2836,  2839,  2840,  2859,  2880,  2881,  2884,  2891,
    2900,  2901,  2905,  2912,  2913,  2914,  2915,  2918,  2931,  2940,
    2945,  2950,  2958,  2964,  2973,  2974,  2982
};
#endif

#if ORACLE_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "BOOL",
  "APPROXNUM", "NULLX", "UNKNOWN", "QUESTIONMARK", "PARAM", "UMINUS",
  "'('", "')'", "'.'", "ALL", "AND", "ANY", "ARRAY", "AS", "ASC", "AVG",
  "BETWEEN", "BIGINT", "BINARY", "BLOB", "BOOLEAN", "BY", "CALL", "CASE",
  "CAST", "CHAR", "CHARACTER", "CHARACTERS", "CLOB", "CNNOP", "COALESCE",
  "CODE_UNITS", "COLLATE", "COMP_EQ", "COMP_GE", "COMP_GT", "COMP_LE",
  "COMP_LT", "COMP_NE", "CONVERT", "CORRESPONDING", "COUNT", "CROSS",
  "CUME_DIST", "CURRENT", "CURRENT_TIMESTAMP", "CURRENT_USER", "DATE",
  "DAY", "DEC", "DECIMAL", "DEFAULT", "DELETE", "DENSE_RANK", "DESC",
  "DISTINCT", "DOUBLE", "ELSE", "END", "END_P", "ESCAPE", "ERROR",
  "EXCEPT", "EXCLUDE", "EXISTS", "FLOAT", "FOLLOWING", "FOR", "FROM",
  "FULL", "G", "GROUP", "GROUPING", "HAVING", "HOUR", "IN", "INNER",
  "INSERT", "INT", "INTEGER", "INTERSECT", "INTERVAL", "INTO", "IS",
  "JOIN", "K", "LARGE", "LEFT", "LIKE", "M", "MAX", "MIN", "MINUTE", "MOD",
  "MONTH", "MULTISET", "NATIONAL", "NATURAL", "NCHAR", "NCLOB", "NO",
  "NOT", "NULLIF", "NUMERIC", "OBJECT", "OCTETS", "OF", "ON", "ONLY", "OR",
  "ORDER", "OTHERS", "OUTER", "OVER", "PARTITION", "PERCENT_RANK",
  "PRECEDING", "PRECISION", "RANGE", "RANK", "READ", "REAL", "RECURSIVE",
  "REF", "RIGHT", "ROW", "ROWS", "ROW_NUMBER", "SCOPE", "SECOND", "SELECT",
  "SESSION_USER", "SET", "SETS", "SMALLINT", "SOME", "STDDEV",
  "STDDEV_POP", "STDDEV_SAMP", "SUM", "SYSTEM_USER", "THEN", "TIES",
  "TIME", "TIMESTAMP", "TO", "UNBOUNDED", "UNION", "UPDATE", "USING",
  "VALUES", "VARCHAR", "VARYING", "VAR_POP", "VAR_SAMP", "WHEN", "WHERE",
  "WITH", "WITHOUT", "YEAR", "ZONE", "RETURNING", "SKIP", "LOCKED",
  "NOWAIT", "WAIT", "NULLS", "LAST", "SIBLINGS", "OFFSET", "FIRST", "NEXT",
  "FETCH", "PERCENT", "MINUS", "UNIQUE", "NAN", "INFINITE", "REGEXP_LIKE",
  "APPLY", "CYCLE", "SEARCH", "DEPTH", "BREADTH", "START", "CONNECT",
  "NOCYCLE", "CONTAINERS", "SHARDS", "SAMPLE", "BLOCK", "SEED", "PRIOR",
  "ALTER", "SESSION", "BEGIN", "DECLARE", "UNPIVOT", "PIVOT", "EXTRACT",
  "TIMEZONE_HOUR", "TIMEZONE_MINUTE", "TIMEZONE_REGION", "TIMEZONE_ABBR",
  "';'", "'{'", "'}'", "','", "'*'", "'^'", "'+'", "'-'", "'!'", "'|'",
  "'/'", "'%'", "$accept", "sql_stmt", "stmt_list", "stmt", "body_stmt",
  "special_stmt", "call_stmt", "sql_argument_list", "sql_argument",
  "value_expression", "sp_name", "dql_stmt", "dml_stmt", "insert_stmt",
  "insert_columns_and_source", "from_constructor", "delete_stmt",
  "update_stmt", "opt_returning_into", "variable_list", "variable",
  "update_elem_list", "update_elem", "select_stmt", "query_expression",
  "query_expression_body", "query_term", "query_primary",
  "select_with_parens", "subquery", "table_subquery", "row_subquery",
  "cte_subquery", "simple_table", "opt_hierarchical_query_clause",
  "opt_where", "opt_from_clause", "opt_groupby", "grouping_element_list",
  "grouping_element", "opt_order_by", "order_by", "sort_list", "sort_key",
  "opt_asc_desc", "opt_nulls_c", "opt_having", "with_clause", "with_list",
  "common_table_expr", "opt_derived_column_list",
  "simple_ident_list_with_parens", "simple_ident_list", "opt_distinct",
  "select_expr_list", "projection", "from_list", "table_reference",
  "table_primary", "table_primary_non_join", "unpivot_clause",
  "pivot_clause", "partition_by", "table_function",
  "opt_simple_ident_list_with_parens", "asterisk_expr", "column_ref",
  "relation_factor_2", "relation_factor", "joined_table", "cross_apply",
  "qualified_join", "cross_join", "natural_join", "join_type",
  "join_outer", "search_condition", "boolean_term", "boolean_factor",
  "boolean_test", "boolean_primary", "predicate", "bool_function",
  "comparison_predicate", "quantified_comparison_predicate",
  "between_predicate", "like_predicate", "in_predicate", "null_predicate",
  "null_value", "exists_predicate", "row_expr", "factor0", "factor1",
  "factor2", "factor3", "factor4", "row_expr_list", "in_expr",
  "truth_value", "comp_op", "cnn_op", "comp_all_some_any_op",
  "plus_minus_op", "star_div_percent_mod_op", "expr_const", "case_expr",
  "case_arg", "when_clause_list", "when_clause", "case_default",
  "func_expr", "aggregate_windowed_function", "aggregate_function_name",
  "ranking_windowed_function", "ranking_function_name", "over_clause",
  "window_specification", "window_name", "window_specification_details",
  "opt_existing_window_name", "opt_window_partition_clause",
  "opt_window_frame_clause", "window_frame_units", "window_frame_extent",
  "window_frame_start", "window_frame_preceding", "window_frame_between",
  "window_frame_bound", "window_frame_following",
  "opt_window_frame_exclusion", "scalar_function", "function_call_keyword",
  "data_type", "user_defined_type_name", "relation_factor_type",
  "reference_type", "collection_type", "predefined_type", "interval_type",
  "interval_qualifier", "start_field", "end_field",
  "single_datetime_field", "non_second_primary_datetime_field",
  "boolean_type", "datetime_type", "numeric_type", "exact_numeric_type",
  "approximate_numeric_type", "character_string_type",
  "binary_large_object_string_type", "national_character_string_type",
  "large_object_length", "char_length_units", "multiplier",
  "distinct_or_all", "all_some_any", "opt_as_label", "as_label", "label",
  "collate_clause", "name_r", "name_type", "reserved_type",
  "reserved_other", "reserved_non_type", "reserved", "opt_for_update",
  "for_update", "opt_of_column_ref_list", "column_ref_list",
  "opt_ignore_lock", "opt_wait_nowait", "row_limiting_clause", "row_rows",
  "opt_variable_v2", "variable_v2", "opt_offset_clause", "first_next",
  "only_or_ties", "opt_fetch_rows_clause", "opt_search_clause",
  "search_clause", "opt_cycle_clause", "cycle_clause", "connect_opt",
  "connect_by", "start_with", "hierarchical_query_clause", "sample_clause",
  "opt_seed_value", "simple_table_alias", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    40,    41,    46,   268,   269,   270,   271,
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
     462,    59,   123,   125,    44,    42,    94,    43,    45,    33,
     124,    47,    37
};
# endif

#define YYPACT_NINF -839

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-839)))

#define YYTABLE_NINF -364

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,    77,  7263,    99,    97,    65,   252,  7263,  7455,    84,
      57,   302,   280,   314,   254,   117,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,   279,   245,  -839,  -839,
     133,   341,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,   350,  -839,  -839,  -839,
    -839,   372,  -839,  -839,  -839,  7263,  7263,  -839,  -839,    73,
    4302,   352,  6687,   265,  7263,  -839,   199,   423,   304,   380,
    5917,  7263,  -839,  -839,    57,    73,    40,    73,    73,   378,
    -839,    73,   279,  -839,  2790,  7263,   293,   155,  4302,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  4086,  4734,   445,   451,
     453,   456,  -839,   467,  -839,   460,   468,   472,  -839,  -839,
     485,   481,  -839,  4734,  4734,  -839,  -839,  -839,   426,   294,
    -839,  -839,   500,  2366,   -73,   120,   282,  -839,  -839,  -839,
    -839,  -839,  -839,   502,  -839,   506,  -839,  -839,   508,   330,
     746,  7263,  -839,  -839,  -839,  -839,  4734,  -839,  7263,  7263,
     504,  -839,   519,  -839,  -839,  -839,   440,   522,  -839,   152,
     156,   523,  -839,   524,   525,   416,   528,  -839,  -839,   354,
     122,   157,   532,   533,  -839,   534,  -839,   116,   125,   535,
    -839,  -839,   102,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,   146,  -839,   515,   543,  -839,
    -839,   552,  -839,   133,  4734,   539,   133,   133,   413,   393,
    -839,   133,   378,  2574,  -839,   558,  3222,   560,   562,   360,
     557,   462,   567,  -839,  -839,   495,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  -839,   183,   336,   571,  3222,  -839,
    6109,   430,  4734,  -839,   420,   420,   180,   426,  4086,   575,
      38,   576,    66,   431,  4734,  4734,  4734,   593,  -839,   587,
    4734,   588,  -839,   373,  -839,  -839,  6301,   293,  4302,  4518,
    -839,  7263,   384,  4734,  -839,  -839,  -839,  -839,  4734,  -839,
    -839,  -839,  -839,  4734,  4734,  3438,   592,  4734,  5151,   485,
    -839,  -839,   293,   394,    12,  -839,   595,   397,   594,   573,
     503,   611,   612,   507,   606,   615,   510,   609,   619,   620,
     621,  -839,   622,   616,  -839,   479,  -839,   127,   136,   195,
     630,   526,   625,   619,   635,  7263,   637,   493,   498,   646,
     505,   511,   649,   643,  -839,   527,  -839,  -839,  7622,  3006,
     245,  -839,   444,    48,  4734,   245,   245,   551,   348,  -839,
     486,  -839,   393,  2574,   188,    52,    77,  -839,  -839,  -839,
     183,  4734,  -839,  3222,  5917,  3222,  3222,   291,  4734,  -839,
    -839,   627,  -839,   368,  -839,   655,    70,  4734,    81,   629,
    3654,   558,  7263,  7263,   462,  -839,  -839,  4734,  -839,  -839,
     420,   420,   293,   656,  -839,  4734,  -839,  3222,   607,   431,
      24,   659,    43,   662,  -839,    62,  -839,   664,   603,  -839,
    5727,   666,   667,   668,  6687,  -839,   281,  -839,  -839,  6687,
    6879,  -839,  -839,  -839,  -839,  -839,  -839,   182,  -839,  -839,
     669,  -839,  -839,   -73,   120,   282,  -839,  -839,  -839,   671,
      10,  4734,   566,    14,  -839,   382,   420,  4734,  4734,  -839,
    7263,    77,   494,   684,   676,   677,   678,   680,   685,   681,
     686,   692,   367,   689,    17,    21,   690,   700,   373,   702,
     703,   697,   706,   601,   704,   699,   705,   711,   707,    23,
     708,   709,   559,   561,   713,   565,   568,   720,   731,  7263,
     710,   529,   723,  4734,  -839,  -839,   570,  -839,  7263,   209,
    -839,  -839,  -839,   315,   284,  -839,  -839,  -839,   724,  -839,
     102,   567,  -839,  -839,  -839,   320,  -839,    26,  -839,  -839,
    -839,  4086,  -839,  -839,  -839,    91,  -839,  -839,  -839,    44,
    4734,   655,  4734,  -839,  -839,  -839,  -839,    66,  -839,  -839,
     409,  -839,   650,  -839,  -839,   182,   253,  -839,     9,   375,
    4734,   675,  -839,  5917,  -839,  7263,  -839,  4734,   736,  4734,
    5727,   725,   730,   734,  7263,  7263,  7263,    58,    -6,   626,
    -839,  6301,   626,   355,   563,   626,  6301,   670,  -839,    59,
     173,  6687,   591,   732,   687,   572,   574,  -839,  -839,   566,
     566,    18,  7071,  -839,  -839,  5343,  -839,  -839,    66,  -839,
     744,   287,   582,  -839,  -839,   754,  -839,  -839,   619,   748,
    -839,   619,   756,  -839,  -839,  -839,  -839,  -839,  -839,  -839,
     124,  -839,  -839,   766,  -839,   767,  -839,    25,  -839,   765,
     768,   778,   775,   780,   789,  -839,   619,   781,  -839,  -839,
     797,   682,   328,  -839,  -839,   332,  -839,  -839,  -839,   792,
     515,  7622,  -839,   600,  -839,   191,  -839,   604,   800,  -839,
    -839,   816,   653,  -839,  -839,  -839,  -839,  -839,   348,  -839,
    -839,  4734,   810,  -839,  4734,    28,  -839,    64,  7263,  6495,
     687,  4734,  4734,    66,  -839,   101,   811,    20,   814,    22,
    -839,  -839,   817,   818,   821,   823,  -839,  -839,  -839,  6301,
    6301,  -839,  -839,   771,  -839,  6301,   751,  6301,  -839,  -839,
    6301,   832,   838,   827,   844,  -839,  -839,  -839,  -839,  3222,
      -4,   830,   779,  -839,  -839,  -839,  -839,   566,  7263,  -839,
    -839,  -839,  -839,   412,  -839,   683,   691,  7263,  -839,  -839,
     831,   847,  -839,   849,  -839,  -839,   852,   856,  -839,   859,
     717,  -839,   857,  -839,   619,   858,   860,  -839,   862,  7263,
     727,   728,   729,   733,  -839,  -839,   865,  -839,  -839,  -839,
    7263,  7263,  -839,   712,  -839,   250,  -839,    66,  -839,    66,
    4734,  4734,   424,  -839,  -839,  -839,   674,  -839,   779,    66,
      66,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  7263,
    -839,  -839,  3222,   423,  -839,  6301,  -839,   855,   867,   879,
     876,   755,   462,   693,  -839,  3222,    73,  3222,  -839,  -839,
    -839,   881,   782,  5535,   868,   877,   769,  -839,  -839,  -839,
    -839,  -839,   892,  -839,   893,  -839,  -839,  -839,  -839,   742,
     743,   745,   750,  7622,  -839,   896,  -839,   315,    69,    66,
      66,  7263,  6495,  -839,   839,   462,  -839,  -839,  3222,   423,
     726,   904,  7263,   848,   502,  -839,   462,  4950,   462,  -839,
     895,   804,  -839,   910,  7263,  7263,  7263,  -839,  -839,  -839,
    -839,  -839,  -839,  -839,  7263,    69,  -839,   777,  -839,  -839,
    7263,   462,  -839,   915,  -839,   726,   918,  7263,  3870,   793,
    -839,   715,    66,  4734,   213,  7263,    89,    89,   783,   919,
    -839,  -839,   854,   932,  -839,  -839,   863,  -839,   927,  4950,
    -839,  -839,  -839,  -839,   521,  -839,   570,   570,   937,   423,
     933,   423,  4950,  -839,   545,   819,   825,   833,   880,  -839,
    -839,  -839,   815,   822,   897,   939,  -839,   943,   946,     3,
      49,  -839,   945,  -839,  -839,  -839,  -839,   272,  -839,  7263,
    7263,   959,  6687,  6687,  -839,  -839,  -839,   545,   834,  -839,
     846,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     3,    10,     9,     8,     6,
       7,    29,    28,    27,    26,    49,    79,    52,    56,    58,
       0,     0,   466,   471,   519,   274,   483,   472,   479,   492,
     482,   475,   478,   520,   493,   521,   494,   282,   289,   374,
     484,   287,   514,   486,   518,   495,   491,   283,   375,   470,
     477,   489,   496,   490,   275,   276,   376,   373,   497,   485,
     476,   480,   522,   481,   498,   499,   512,   500,   517,   288,
     501,   502,   286,   513,   488,   503,   504,   505,   290,   506,
     507,   516,   284,   278,   279,   277,   515,   474,   473,   508,
     509,   487,   280,   281,   510,   372,   511,   523,   524,   525,
     526,   527,   377,   378,   379,   380,     0,    25,   532,   533,
     534,   144,   536,   535,   467,     0,     0,   105,   106,   104,
       0,     0,   460,     0,   503,    94,    96,    99,     0,     0,
       0,     0,     1,     2,     5,   104,     0,   104,   104,   537,
      80,   104,    79,    59,     0,     0,    69,     0,     0,   245,
     248,   246,   249,   247,   250,   251,     0,   256,   492,   520,
     521,   328,   330,     0,   252,     0,   522,     0,   332,   333,
     473,     0,   133,     0,     0,    61,    63,   216,     0,   107,
     110,   214,     0,   460,   202,   205,   207,   209,   211,   215,
     218,   219,   267,   532,   266,   533,   265,   264,   534,   137,
       0,     0,   586,   461,   463,   464,     0,    95,     0,     0,
       0,   100,     0,    11,   468,   406,     0,   429,   381,   424,
     425,   423,   382,   402,   408,     0,   411,   405,   404,     0,
       0,   444,   443,   407,   412,   504,   403,     0,   393,   509,
     528,   529,    14,   336,   339,   337,   338,   335,   358,   530,
     356,   357,   355,   394,   395,   351,   354,   353,   340,   531,
     469,     0,     4,     0,     0,     0,     0,     0,     0,   557,
     538,     0,   537,     0,    16,     0,     0,     0,     0,    19,
      21,    23,   166,   168,   170,   172,   175,   184,   177,   182,
     178,   180,   179,   181,   183,    24,   137,   145,     0,    37,
       0,     0,     0,    30,    39,    39,     0,     0,     0,     0,
     220,     0,   257,     0,     0,     0,     0,     0,   253,     0,
       0,     0,   254,     0,   212,   213,     0,    69,     0,     0,
     236,     0,     0,     0,   109,   203,   239,   240,     0,   244,
     241,   242,   243,     0,     0,     0,     0,     0,     0,     0,
      13,   462,    69,    46,     0,    97,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,     0,   371,   359,     0,   361,   368,   433,   431,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   346,   347,     0,   350,   352,     0,     0,
      54,    81,    83,    86,     0,    53,    55,   540,     0,    50,
     563,    57,   557,     0,     0,   220,     0,    62,   201,   171,
       0,     0,    15,     0,     0,     0,     0,     0,     0,   230,
     228,   229,   226,   227,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    35,    36,     0,    34,    31,
      39,    39,    69,     0,    60,     0,   217,     0,   262,   258,
       0,     0,     0,     0,   324,     0,   323,   366,     0,   364,
       0,   500,     0,     0,   460,    71,   111,   113,   115,   460,
     460,   142,   114,   150,   147,   148,   149,    67,   108,   320,
       0,   465,   237,   204,   206,   208,   210,   455,   456,     0,
       0,     0,     0,     0,   134,   138,    39,     0,     0,   101,
       0,     0,   566,     0,   427,     0,     0,   421,     0,     0,
     419,     0,   448,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   441,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     341,     0,     0,     0,    87,    88,    89,    82,     0,   546,
     556,   555,   554,     0,     0,   549,    51,   176,     0,    20,
      22,   167,   169,   224,   225,     0,   173,     0,   232,   233,
     234,     0,   222,   194,   198,     0,   199,   200,   196,   190,
       0,     0,     0,   235,   457,   459,   458,   186,   238,   187,
     138,   146,     0,    33,    32,    67,    60,   221,     0,     0,
       0,     0,   259,     0,   327,     0,   329,     0,     0,     0,
       0,     0,   142,   114,     0,     0,     0,   131,     0,   164,
     163,     0,   164,     0,     0,   164,     0,     0,   119,   524,
     117,   460,     0,     0,    72,   580,     0,    68,   321,   273,
     269,     0,     0,   285,   322,     0,    38,    47,    48,   103,
       0,     0,   570,   567,    12,     0,   428,   414,     0,     0,
     413,     0,     0,   449,   450,   454,   452,   453,   451,   447,
     446,   422,   401,     0,   399,     0,   409,     0,   360,     0,
       0,     0,     0,   439,     0,   434,     0,     0,   442,   397,
       0,     0,   385,   386,   387,   390,   391,   392,   417,     0,
     349,     0,    18,     0,    84,     0,    85,   542,   137,   541,
     547,     0,   544,   550,   551,   558,   559,   560,   552,   185,
     174,     0,     0,   197,     0,     0,   195,   192,     0,     0,
      72,     0,     0,   263,   255,     0,     0,     0,     0,     0,
     143,   116,     0,     0,     0,     0,   132,   123,   118,     0,
       0,   165,   160,     0,   161,     0,     0,     0,   162,   112,
       0,     0,     0,     0,     0,   122,   124,   121,   120,     0,
     573,     0,    92,   579,   581,   272,   268,   271,   296,   292,
     291,   294,   135,   139,    64,     0,     0,     0,    98,   571,
       0,     0,   416,     0,   415,   445,     0,     0,   370,     0,
     367,   432,     0,   430,     0,     0,     0,   437,     0,     0,
       0,     0,     0,     0,   345,   348,   342,    17,    91,    90,
       0,     0,   548,     0,   539,     0,   553,   188,   223,   191,
       0,     0,   139,    44,    43,    40,    41,    45,    92,   260,
     261,   325,   326,   331,   365,   334,   128,   129,   130,     0,
     157,   151,     0,     0,   159,     0,   152,     0,     0,     0,
       0,     0,   578,   574,   576,     0,   104,     0,    65,   270,
     297,     0,   298,     0,     0,     0,     0,   426,   420,   418,
     400,   398,     0,   436,     0,   435,   440,   396,   344,     0,
       0,     0,     0,     0,   543,   138,   545,     0,     0,   189,
     193,     0,     0,    66,     0,   154,   156,   158,     0,     0,
     584,     0,     0,     0,     0,   575,   577,     0,    93,   293,
       0,    79,   136,   140,     0,     0,     0,   369,   438,   383,
     384,   388,   389,   343,     0,     0,   561,     0,   564,    42,
       0,   153,   155,     0,   583,   584,     0,     0,     0,   283,
      73,    74,    77,     0,   300,     0,    86,    86,     0,   139,
     565,   562,     0,     0,   582,   127,     0,    76,     0,     0,
     299,   303,   302,   295,     0,   141,    89,    89,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,   315,   304,
     308,   305,     0,     0,     0,     0,   585,     0,     0,     0,
       0,   311,     0,   313,   307,   306,   309,     0,   301,     0,
       0,     0,   460,   460,    78,   312,   314,     0,     0,   317,
       0,   318,   568,   569,   572,   125,   126,   310,   316,   319
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -839,  -839,    63,  -839,  -839,  -839,  -839,  -290,  -839,  -839,
     829,  -839,  -839,  -839,  -839,   661,  -839,  -839,  -273,    50,
    -839,   454,  -839,  -155,     0,   949,   113,   694,  -839,  -270,
    -268,  -839,  -839,  -839,   366,  -164,   665,   233,  -838,  -839,
    -143,  -839,  -302,  -839,  -473,  -485,   126,  -839,   -17,  -839,
    -839,  -153,  -504,  -122,  -120,  -839,   339,  -459,  -408,  -839,
     337,  -839,  -839,  -839,  -839,  -839,  -538,  -839,    11,  -433,
    -839,  -839,  -839,  -839,   345,  -254,  -275,   554,  -231,  -839,
    -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,  -839,   396,
    -839,  1545,   651,   644,   640,   -77,  -839,  -298,   399,   410,
    -839,  -839,  -839,  -839,  -839,  -207,  -839,  -839,   537,  -839,
    -839,  -839,   121,   850,  -839,  1222,  -546,  -839,   200,  -839,
    -839,  -839,  -839,  -839,  -839,     7,  -839,  -839,   -40,  -839,
    -839,  -839,  -839,  -394,  -839,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,   469,  -839,   376,  -839,  -839,  -839,  -839,  -839,
    -839,  -839,  -839,  -382,   319,  -839,  -839,  -839,  -183,  -839,
     799,  -245,    -2,  -396,  -839,  -121,  -839,  -839,   737,  -839,
    -839,  -732,  -839,  -839,   590,  -727,  -839,   275,  -839,  -839,
      60,  -839,  -839,  -839,  -839,  -839,  -839,   358,   363,  -839,
    -839,    55,   898
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,   288,   289,   290,
     116,    19,    20,    21,   313,   314,    22,    23,   458,   855,
     856,   362,   363,    24,    25,    26,    27,    28,   185,   186,
     484,   187,   522,    29,   654,   309,   337,   792,   970,   971,
     149,   150,   411,   412,   566,   726,   888,    30,   135,   136,
     220,   221,   366,   130,   188,   189,   485,   486,   487,   488,
     767,   786,   787,   489,   768,   190,   191,   490,   192,   492,
     493,   494,   495,   496,   647,   772,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   598,
     304,   320,   194,   195,   196,   197,   198,   321,   593,   586,
     450,   343,   451,   348,   353,   199,   200,   323,   468,   469,
     621,   201,   202,   118,   204,   119,   663,   799,   800,   891,
     892,   941,   993,   994,  1008,  1021,  1010,  1011,  1022,  1023,
    1028,   206,   207,   252,   253,   254,   255,   256,   257,   258,
     384,   385,   478,   386,   120,   260,   261,   262,   263,   264,
     265,   266,   267,   533,   689,   690,   511,   608,   212,   213,
     214,   345,   306,   268,   122,   123,   270,   124,   279,   280,
     569,   729,   844,   732,   419,   735,   845,   573,   420,   738,
     958,   575,   672,   673,   808,   809,   885,   655,   656,   657,
     651,   964,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,    31,   315,   360,   316,   121,   137,   158,   424,   282,
     344,   548,   560,   117,   456,   427,   669,   428,   132,   269,
     406,   631,   407,   273,   660,   276,   277,   471,   664,   281,
     727,   692,   797,   454,   863,   694,   865,   709,   317,   818,
     580,   500,   459,   741,   623,   850,   340,   633,   340,   341,
     340,   341,   518,   341,   340,   429,   340,   341,   340,   341,
     340,   341,   340,   341,   340,   341,   427,   341,   274,   564,
       1,   219,   781,   139,   340,   438,  1035,   341,   594,   340,
     340,   127,   341,   341,   340,   769,     2,   341,   340,   127,
       1,   341,   439,   440,   441,   442,   443,   444,   340,   594,
     340,   341,   340,   341,   600,   341,   334,   335,   914,   565,
     564,   744,   567,   795,   796,   861,     3,   217,   918,   562,
     403,   403,  1036,   121,   121,   435,  1025,   128,   209,   396,
     215,   851,   137,   578,   445,   128,   132,   157,   399,   121,
     539,     4,   446,   579,   346,   347,     1,   447,   424,   540,
     565,  1003,   117,   307,   388,   389,   209,   751,   683,   612,
     448,   461,   684,   601,  1018,   372,   319,   617,   310,   375,
     390,   631,  1026,   497,   125,   427,   602,   592,   595,   405,
     770,   427,   773,   609,   956,   341,   126,   613,   614,   883,
     955,   215,   618,     1,     5,   884,     6,   633,   516,   625,
     966,   365,   577,   404,   404,   582,   438,   272,   542,   215,
     427,   857,     7,   311,     5,   275,   137,   367,   498,   340,
     349,     8,   341,   439,   440,   441,   442,   443,   444,   755,
     342,   693,   342,   957,   342,   695,   688,   710,   342,   819,
     342,     8,   342,   666,   342,   373,   342,   129,   342,   376,
     391,   889,   465,   596,   597,   131,   782,     9,   342,    10,
      11,   724,   765,   342,   342,   445,   465,   -59,   342,    12,
       5,   449,   342,   446,   596,   597,   627,   506,   447,  -363,
     397,   398,   342,   319,   342,   138,   342,   269,   543,   400,
     401,   448,     5,   742,   783,   541,   811,   583,   615,   813,
     584,   637,   727,   896,   435,   140,   648,   650,   367,   141,
      31,   374,   312,   269,   142,   377,   392,     5,   463,     8,
     143,   877,   -59,  1038,   826,   836,   583,   -59,   144,   584,
     638,   427,   151,   592,   121,   350,   209,   312,   991,   121,
     -59,   351,   352,  -144,     8,   358,   992,   491,   145,  -144,
    1039,   452,   501,   570,   544,   153,   515,   639,   571,   572,
     427,   870,   871,   154,   640,   838,   670,   874,   839,   876,
     -59,   427,   641,   652,   653,   642,   427,   765,   784,  1040,
     730,   731,   733,   734,   857,   643,   410,   155,   774,   415,
     416,   778,   210,   121,   727,  -145,   146,   665,   438,   585,
     644,   683,   449,   342,   216,   684,   550,   -59,   589,    49,
     590,   340,   645,   218,   341,   439,   440,   441,   442,   443,
     444,  1041,  -145,   463,   748,  -146,   319,   893,    49,   -59,
     917,   639,   -59,   147,   -59,    58,   219,  -146,   640,   921,
     976,   977,   904,   222,   685,   223,   775,   733,   734,   642,
     610,   611,   278,    66,    58,    67,   308,   445,   324,   686,
     148,   736,   737,   687,   325,   446,   326,   927,   788,   327,
     447,   328,    66,   329,    67,   835,   805,   806,   121,   688,
     319,   330,   215,   448,   766,   331,   645,   215,   215,   332,
     383,   632,   830,   831,   333,   646,   832,   833,   354,   427,
     427,   336,   269,   996,   997,   427,   208,   427,   338,   477,
     427,  1012,  1013,   339,   882,   355,   259,   953,   367,   356,
     105,   357,   369,   752,   368,   159,   160,   161,   162,   163,
     208,   164,   165,   370,   208,   371,   378,   379,   380,   105,
     381,   382,   208,   208,  1004,   393,   394,   395,   402,   159,
     160,   161,   162,   163,   341,   164,   165,   121,   408,   208,
     208,   112,   113,   114,   115,   409,   728,   414,   417,   418,
     720,   426,  1005,   431,   433,   173,   432,   434,   435,   174,
     112,   113,   114,   115,   436,   437,   453,   455,   457,   464,
     466,   319,   208,   467,   449,   342,  1005,   925,   473,   173,
     269,   474,   476,   174,   502,   427,   512,   521,   517,   519,
     936,   520,   938,   523,   524,   387,   525,   526,   527,   528,
     529,   530,   531,   121,   532,   534,   535,   536,   121,   537,
     463,   538,   121,   121,   121,   545,   756,   546,   547,   121,
     549,   632,   551,   552,   121,   762,   763,   764,   553,   215,
     208,   554,   491,   961,   557,   555,   558,   491,   563,   208,
     801,   556,   208,   803,   568,   574,   559,   588,   591,   603,
     616,   620,   359,   624,  1006,   990,   626,   628,   629,   634,
     635,   636,   671,   658,   208,   659,   662,   674,   208,   675,
     679,   676,   677,   678,   208,   680,   359,   682,  1019,   681,
     208,   208,   208,   691,   696,   697,   208,   699,   700,   479,
     701,   702,   703,   705,   208,   208,   707,   704,   706,   208,
     926,   708,   711,   712,   208,   721,   713,   715,   714,   208,
     208,   208,   716,   208,   718,   717,   719,   723,   739,   749,
     754,   758,   722,   725,   760,   771,   852,   728,   761,   777,
     159,   160,   161,   162,   163,   789,   164,   165,   804,   810,
     790,   780,   812,   652,   937,   791,   653,   121,   121,   807,
     814,   816,   817,   121,   638,   121,   962,    35,   121,   820,
     491,   491,   821,   822,   259,   208,   491,  1007,   491,   823,
     208,   491,   269,   824,   825,   827,   801,  1020,   974,   208,
     173,   639,   828,    47,   174,   367,   834,   208,   640,   208,
     259,   208,   208,   837,   208,   841,   641,   829,   840,   642,
     638,   842,   843,   208,   848,   862,   208,   121,   864,   643,
    1020,   866,   867,   208,    57,   868,   869,   878,   728,   915,
     908,   208,   875,   208,   644,   897,  1015,   639,  1017,  1045,
    1046,   879,    64,    65,   640,   880,   645,   881,   886,   887,
     894,   898,   641,   899,   902,   642,   900,   924,   895,  -362,
     901,   903,   905,   121,   906,   643,   907,   909,   910,   911,
     913,   930,   916,   912,   931,   872,   491,   208,   922,   932,
     644,   943,   935,   208,   208,   939,   944,   359,    92,    93,
      94,    95,   645,   940,   638,   945,   947,   948,   946,   949,
     950,   954,   951,   960,   479,   102,   103,   952,   965,   943,
     728,   146,   967,   973,   963,   975,   981,   873,   983,   989,
     728,   639,   985,   988,   921,   998,   999,  1000,   640,   208,
    1002,  1014,   367,   367,   978,  1001,   641,  1016,  1025,   642,
    1027,  1024,   979,  1032,  1029,  1031,  1026,  1033,   982,   643,
    1034,  1030,  1037,  1044,  1049,   986,  1048,   208,   319,   928,
     271,   667,   959,   995,   644,   421,   208,   460,   208,   152,
     203,   750,   462,   858,   923,   779,   645,   785,   776,   581,
     250,   743,   504,   505,   503,   740,   208,  1047,   890,   259,
     746,  1009,   933,   208,   203,   208,   622,   698,   203,   815,
     361,   929,   576,   846,   794,   980,   203,   203,   793,   422,
     984,     0,     0,   156,     0,     0,     0,  1042,  1043,     0,
     215,   215,     0,   203,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
     208,     0,     0,     0,   203,     0,     0,   208,   208,     0,
       0,     0,     0,   203,     0,     0,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,     0,
       0,     0,   203,     0,     0,   208,     0,     0,   203,     0,
       0,     0,     0,     0,   203,   203,   203,     0,     0,     0,
     203,     0,     0,     0,     0,     0,     0,     0,   203,   203,
       0,     0,     0,   203,     0,     0,     0,     0,   203,     0,
       0,     0,     0,   203,   203,   203,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   203,
       0,   208,     0,   208,   203,     0,     0,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
       0,   203,     0,   203,   250,   203,   203,     0,   203,   259,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
     203,     0,     0,     0,   208,     0,     0,   203,     0,     0,
       0,     0,     0,   208,     0,   203,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,     0,     0,   208,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,   203,   251,     0,     0,   208,     0,   203,   203,     0,
       0,     0,     0,     0,     0,     0,   205,     0,   208,     0,
     205,     0,     0,     0,     0,     0,     0,     0,   205,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   205,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
     203,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,     0,     0,   250,     0,     0,     0,   203,     0,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,     0,   205,     0,     0,     0,     0,     0,
     205,     0,     0,     0,     0,     0,   205,   205,   205,     0,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
     205,   205,     0,     0,     0,   205,     0,     0,     0,     0,
     205,   250,     0,     0,     0,   205,   205,   205,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   203,     0,     0,     0,     0,     0,
       0,   203,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,   205,     0,     0,     0,     0,   205,     0,     0,   203,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,   205,     0,   205,   251,   205,   205,     0,
     205,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,   205,     0,     0,   193,     0,     0,     0,   205,
       0,     0,     0,     0,     0,     0,     0,   205,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
     203,   203,     0,   193,     0,     0,     0,     0,     0,     0,
       0,     0,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
       0,   934,     0,   205,     0,   203,     0,   203,     0,   205,
     205,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   364,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   205,     0,   203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,   203,   413,
       0,     0,   205,   203,   205,     0,     0,     0,   425,     0,
       0,   430,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,   205,     0,     0,   251,     0,     0,     0,   205,
       0,   205,   203,   430,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
       0,   472,     0,     0,     0,   475,     0,     0,     0,     0,
       0,     0,     0,   193,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     510,     0,   513,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   305,     0,     0,     0,     0,   413,
       0,     0,     0,   205,     0,     0,   205,     0,   425,     0,
       0,     0,     0,   205,   205,     0,     0,     0,   305,     0,
     430,   430,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,   607,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   661,     0,     0,     0,
       0,     0,   364,   668,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   413,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   251,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   745,     0,   747,     0,     0,
     205,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,     0,     0,     0,     0,   753,     0,     0,     0,     0,
       0,     0,   757,     0,   759,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,     0,     0,     0,     0,   205,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   847,     0,     0,   849,
       0,     0,     0,     0,     0,     0,   859,   860,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,   211,    34,    35,     0,
      36,    37,    38,     0,     0,   919,   920,    39,     0,    40,
      41,    42,   340,    43,    44,   341,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,    48,   430,     0,     0,
       0,    49,    50,     0,     0,     0,    51,    52,     0,    53,
     430,     0,   430,     0,     0,     0,    54,     0,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,   430,     0,    72,    73,    74,    75,    76,
       0,    77,   972,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,     0,    87,     0,
      88,    89,    90,     0,     0,     0,    91,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,   972,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,   972,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,   109,   110,   111,
       0,     0,     0,   112,   113,   114,   115,    32,   159,   160,
     161,   162,   163,     0,   164,   165,   342,   423,     0,     0,
       0,     0,     0,    33,     0,    34,    35,     0,    36,    37,
      38,     0,     0,     0,   167,   168,     0,    40,    41,    42,
       0,   169,    44,     0,     0,     0,     0,     0,     0,     0,
     170,    46,    47,     0,    48,     0,   171,   172,   173,    49,
      50,     0,   174,     0,    51,    52,     0,    53,     0,     0,
       0,     0,     0,     0,    54,   285,     0,    55,     0,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,    59,
       0,     0,    60,     0,     0,     0,    61,    62,   175,     0,
      63,    64,    65,    66,     0,    67,    68,    69,     0,    70,
      71,     0,   286,   176,    73,    74,    75,    76,     0,    77,
       0,     0,    78,     0,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    86,   177,    87,     0,    88,    89,
      90,     5,   178,     0,    91,     0,     0,    92,    93,    94,
      95,   179,     0,    96,    97,   180,     0,    99,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     8,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,   287,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,   109,   110,   111,     0,     0,
     181,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   183,   184,    32,   159,   160,   161,   162,   163,     0,
     164,   165,     0,   283,   284,     0,     0,     0,     0,    33,
       0,    34,    35,     0,    36,    37,    38,     0,     0,     0,
     167,   168,     0,    40,    41,    42,     0,   169,    44,     0,
       0,     0,     0,     0,     0,     0,   170,    46,    47,     0,
      48,     0,   171,   172,   173,    49,    50,     0,   174,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,   285,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,   175,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,   286,   176,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,   177,    87,     0,    88,    89,    90,     0,   178,     0,
      91,     0,     0,    92,    93,    94,    95,   179,     0,    96,
      97,   180,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,   109,   110,   111,     0,     0,   181,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,   183,   184,    32,
     159,   160,   161,   162,   163,     0,   164,   165,     0,   283,
     561,     0,     0,     0,     0,    33,     0,    34,    35,     0,
      36,    37,    38,     0,     0,     0,   167,   168,     0,    40,
      41,    42,     0,   169,    44,     0,     0,     0,     0,     0,
       0,     0,   170,    46,    47,     0,    48,     0,   171,   172,
     173,    49,    50,     0,   174,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,    54,   285,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
     175,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,     0,   286,   176,    73,    74,    75,    76,
       0,    77,     0,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,   177,    87,     0,
      88,    89,    90,     0,   178,     0,    91,     0,     0,    92,
      93,    94,    95,   179,     0,    96,    97,   180,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,   109,   110,   111,
       0,     0,   181,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,   183,   184,    32,   159,   160,   161,   162,
     163,     0,   164,   165,     0,   283,     0,     0,     0,     0,
       0,    33,     0,    34,    35,     0,    36,    37,    38,     0,
       0,     0,   167,   168,     0,    40,    41,    42,     0,   169,
      44,     0,     0,     0,     0,     0,     0,     0,   170,    46,
      47,     0,    48,     0,   171,   172,   173,    49,    50,     0,
     174,     0,    51,    52,     0,    53,     0,     0,     0,     0,
       0,     0,    54,   285,     0,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,    59,     0,     0,
      60,     0,     0,     0,    61,    62,   175,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,     0,
     286,   176,    73,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
      84,    85,    86,   177,    87,     0,    88,    89,    90,     0,
     178,     0,    91,     0,     0,    92,    93,    94,    95,   179,
       0,    96,    97,   180,     0,    99,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,   287,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     0,   181,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,   183,
     184,    32,   159,   160,   161,   162,   163,     0,   164,   165,
       0,   166,     0,     0,   507,     0,     0,    33,     0,    34,
      35,     0,    36,    37,    38,     0,     0,     0,   167,   168,
       0,    40,    41,    42,     0,   169,    44,     0,     0,     0,
       0,     0,     0,     0,   170,    46,    47,     0,    48,     0,
     171,   172,   173,    49,    50,     0,   174,     0,    51,    52,
     508,    53,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
       0,     0,     0,    59,     0,     0,    60,     0,     0,     0,
      61,    62,   175,     0,    63,    64,    65,    66,     0,    67,
      68,    69,     0,    70,    71,     0,     0,   176,    73,    74,
      75,    76,     0,    77,     0,     0,    78,     0,     0,     0,
      79,    80,    81,     0,    82,    83,    84,    85,    86,   177,
      87,     0,    88,    89,    90,     0,   178,     0,    91,     0,
       0,    92,    93,    94,    95,   179,     0,    96,    97,   180,
       0,    99,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,   109,
     110,   111,     0,     0,   181,   112,   113,   114,   115,     0,
       0,     0,     0,   509,     0,   183,   184,    32,   159,   160,
     161,   162,   163,     0,   164,   165,     0,   166,     0,     0,
     604,     0,   605,    33,     0,    34,    35,     0,    36,    37,
      38,     0,     0,     0,   167,   168,     0,    40,    41,    42,
       0,   169,    44,     0,     0,     0,     0,     0,     0,     0,
     170,    46,    47,     0,    48,     0,   171,   172,   173,    49,
      50,     0,   174,     0,    51,    52,     0,    53,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,    59,
       0,     0,    60,     0,     0,     0,    61,    62,   175,     0,
      63,    64,    65,    66,     0,    67,    68,    69,     0,    70,
      71,     0,     0,   176,    73,    74,    75,    76,     0,    77,
       0,     0,    78,     0,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    86,   177,    87,     0,    88,    89,
      90,     0,   178,     0,    91,     0,   606,    92,    93,    94,
      95,   179,     0,    96,    97,   180,     0,    99,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,   109,   110,   111,     0,     0,
     181,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   183,   184,    32,   159,   160,   161,   162,   163,     0,
     164,   165,     0,   318,   987,     0,     0,     0,     0,    33,
       0,    34,    35,     0,    36,    37,    38,     0,     0,     0,
     167,   168,     0,    40,    41,    42,     0,   169,    44,     0,
       0,     0,     0,     0,     0,     0,   170,    46,    47,     0,
      48,     0,   171,   172,   173,    49,    50,     0,   174,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,   175,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,     0,   176,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,   177,    87,     0,    88,    89,    90,     5,   178,     0,
      91,     0,     0,    92,    93,    94,    95,   179,     0,    96,
      97,   180,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     8,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,   109,   110,   111,     0,     0,   181,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,   183,   184,    32,
     159,   160,   161,   162,   163,     0,   164,   165,     0,   318,
       0,     0,     0,     0,     0,    33,     0,    34,    35,     0,
      36,    37,    38,     0,     0,     0,   167,   168,     0,    40,
      41,    42,     0,   169,    44,     0,     0,     0,     0,     0,
       0,     0,   170,    46,    47,     0,    48,     0,   171,   172,
     173,    49,    50,     0,   174,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
     175,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,     0,     0,   176,    73,    74,    75,    76,
       0,    77,     0,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,   177,    87,     0,
      88,    89,    90,     5,   178,     0,    91,     0,     0,    92,
      93,    94,    95,   179,     0,    96,    97,   180,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       8,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,     0,     0,   109,   110,   111,
       0,     0,   181,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,   183,   184,    32,   159,   160,   161,   162,
     163,     0,   164,   165,     0,   166,     0,     0,     0,     0,
       0,    33,     0,    34,    35,     0,    36,    37,    38,     0,
       0,     0,   167,   168,     0,    40,    41,    42,     0,   169,
      44,     0,     0,     0,     0,     0,     0,     0,   170,    46,
      47,     0,    48,     0,   171,   172,   173,    49,    50,     0,
     174,     0,    51,    52,     0,    53,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,    59,     0,     0,
      60,     0,     0,     0,    61,    62,   175,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,     0,
       0,   176,    73,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
      84,    85,    86,   177,    87,     0,    88,    89,    90,     0,
     178,     0,    91,     0,     0,    92,    93,    94,    95,   179,
       0,    96,    97,   180,     0,    99,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     0,   181,   112,
     113,   114,   115,     0,     0,     0,     0,   182,     0,   183,
     184,    32,   159,   160,   161,   162,   163,     0,   164,   165,
       0,   166,   499,     0,     0,     0,     0,    33,     0,    34,
      35,     0,    36,    37,    38,     0,     0,     0,   167,   168,
       0,    40,    41,    42,     0,   169,    44,     0,     0,     0,
       0,     0,     0,     0,   170,    46,    47,     0,    48,     0,
     171,   172,   173,    49,    50,     0,   174,     0,    51,    52,
       0,    53,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
       0,     0,     0,    59,     0,     0,    60,     0,     0,     0,
      61,    62,   175,     0,    63,    64,    65,    66,     0,    67,
      68,    69,     0,    70,    71,     0,     0,   176,    73,    74,
      75,    76,     0,    77,     0,     0,    78,     0,     0,     0,
      79,    80,    81,     0,    82,    83,    84,    85,    86,   177,
      87,     0,    88,    89,    90,     0,   178,     0,    91,     0,
       0,    92,    93,    94,    95,   179,     0,    96,    97,   180,
       0,    99,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,   109,
     110,   111,     0,     0,   181,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,   183,   184,    32,   159,   160,
     161,   162,   163,     0,   164,   165,     0,   166,     0,     0,
       0,     0,     0,    33,     0,    34,    35,     0,    36,    37,
      38,     0,     0,     0,   167,   168,     0,    40,    41,    42,
       0,   169,    44,     0,     0,     0,     0,     0,     0,     0,
     170,    46,    47,     0,    48,     0,   171,   172,   173,    49,
      50,     0,   174,     0,    51,    52,     0,    53,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,    59,
       0,     0,    60,     0,     0,     0,    61,    62,   175,     0,
      63,    64,    65,    66,     0,    67,    68,    69,     0,    70,
      71,     0,     0,   176,    73,    74,    75,    76,     0,    77,
       0,     0,    78,     0,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    86,   177,    87,     0,    88,    89,
      90,     0,   178,     0,    91,     0,     0,    92,    93,    94,
      95,   179,     0,    96,    97,   180,     0,    99,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,   109,   110,   111,     0,     0,
     181,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,   183,   184,    32,   159,   160,   161,   162,   163,     0,
     164,   165,     0,   968,     0,     0,     0,     0,     0,    33,
       0,    34,    35,     0,    36,    37,    38,     0,     0,     0,
     167,   168,     0,    40,    41,    42,     0,   169,    44,     0,
       0,     0,     0,     0,     0,     0,   170,    46,    47,     0,
      48,     0,   171,   172,   173,    49,    50,     0,   174,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,   969,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,   175,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,     0,   176,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,   177,    87,     0,    88,    89,    90,     0,   178,     0,
      91,     0,     0,    92,    93,    94,    95,   179,     0,    96,
      97,   180,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,   109,   110,   111,    32,     0,   181,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,   183,   184,     0,
      33,     0,    34,    35,     0,    36,    37,    38,     0,     0,
       0,     0,    39,     0,    40,    41,    42,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,     0,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,     0,
      72,    73,    74,    75,    76,     0,    77,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,     0,    87,     0,    88,    89,    90,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    95,     0,     0,
      96,    97,    98,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   108,     0,     0,
       0,     0,   109,   110,   111,     0,     0,     0,   112,   113,
     114,   115,    33,     0,    34,    35,   514,    36,    37,    38,
       0,     0,     0,     0,    39,     0,    40,    41,    42,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,    51,    52,     0,    53,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,    59,     0,
       0,    60,     0,     0,     0,    61,    62,     0,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
       0,     0,    72,    73,    74,    75,    76,     0,    77,     0,
       0,    78,     0,     0,     0,    79,    80,    81,     0,    82,
      83,    84,    85,    86,     0,    87,     0,    88,    89,    90,
       0,     0,     0,    91,     0,     0,    92,    93,    94,    95,
       0,     0,    96,    97,    98,     0,    99,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,   108,
       0,     0,     0,     0,   109,   110,   111,     0,     0,     0,
     112,   113,   114,   115,    33,     0,    34,    35,   802,    36,
      37,    38,     0,     0,     0,     0,    39,     0,    40,    41,
      42,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,     0,    72,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,    85,    86,     0,    87,     0,    88,
      89,    90,     0,     0,     0,    91,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,    98,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,   108,     0,     0,     0,     0,   109,   110,   111,     0,
     630,     0,   112,   113,   114,   115,    33,     0,    34,    35,
     942,    36,    37,    38,     0,     0,     0,     0,    39,     0,
      40,    41,    42,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,    59,     0,     0,    60,     0,     0,     0,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,     0,     0,    72,    73,    74,    75,
      76,     0,   481,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,    84,    85,    86,     0,    87,
       0,    88,    89,    90,     5,     0,     0,    91,     0,     0,
      92,    93,    94,    95,     0,     0,    96,    97,    98,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     8,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   482,   483,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     0,     0,   112,   113,   114,   115,    34,    35,
       0,   225,   226,   227,   228,     0,     0,     0,    39,   229,
     230,     0,   231,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,    48,     0,     0,
       0,   232,    49,   233,   234,     0,     0,    51,    52,     0,
     235,     0,     0,     0,     0,     0,     0,    54,     0,   236,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,   237,   238,     0,   239,     0,     0,     0,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
     240,     0,   241,   242,     0,     0,    72,   243,    74,    75,
      76,     0,    77,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,   244,    85,   245,     0,    87,
       0,    88,    89,    90,     0,     0,     0,    91,   246,     0,
      92,    93,    94,    95,     0,     0,    96,   247,   248,     0,
      99,     0,     0,     0,     0,   249,     0,   102,   103,     0,
       0,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     1,     0,   112,   113,   114,   115,    33,     0,
      34,    35,     0,    36,    37,    38,     0,     0,     0,     0,
      39,     0,    40,    41,    42,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,    45,    46,    47,     0,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,    51,
      52,     0,    53,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,    59,     0,     0,    60,     0,     0,
       0,    61,    62,     0,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,     0,     0,    72,    73,
      74,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,    79,    80,    81,     0,    82,    83,    84,    85,    86,
       0,    87,     0,    88,    89,    90,     5,     0,     0,    91,
       0,     0,    92,    93,    94,    95,     0,     0,    96,    97,
      98,     0,    99,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     8,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,   108,     0,     0,     0,     0,
     109,   110,   111,     0,   480,     0,   112,   113,   114,   115,
      33,     0,    34,    35,     0,    36,    37,    38,     0,     0,
       0,     0,    39,     0,    40,    41,    42,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,     0,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,     0,
      72,    73,    74,    75,    76,     0,   481,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,     0,    87,     0,    88,    89,    90,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    95,     0,     0,
      96,    97,    98,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   482,   483,   108,    32,     0,
       0,     0,   109,   110,   111,   853,   854,     0,   112,   113,
     114,   115,     0,     0,    33,     0,    34,    35,     0,    36,
      37,    38,     0,     0,     0,     0,    39,     0,    40,    41,
      42,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,     0,    72,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,    85,    86,     0,    87,     0,    88,
      89,    90,     0,     0,     0,    91,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,    98,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,   108,     0,     0,     0,     0,   109,   110,   111,     0,
       0,     0,   112,   113,   114,   115,    33,   211,    34,    35,
       0,    36,    37,    38,     0,     0,     0,     0,    39,     0,
      40,    41,    42,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,    48,     0,     0,
       0,     0,    49,    50,     0,     0,     0,    51,    52,     0,
      53,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,    59,     0,     0,    60,     0,     0,     0,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,     0,     0,    72,    73,    74,    75,
      76,     0,    77,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,    84,    85,    86,     0,    87,
       0,    88,    89,    90,     0,     0,     0,    91,     0,     0,
      92,    93,    94,    95,     0,     0,    96,    97,    98,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     0,     0,   112,   113,   114,   115,    33,   211,
      34,    35,     0,    36,    37,    38,     0,     0,     0,     0,
      39,     0,    40,    41,    42,     0,    43,    44,     0,     0,
       0,     0,     0,     0,     0,    45,    46,    47,     0,    48,
       0,     0,     0,     0,    49,    50,     0,     0,     0,    51,
      52,     0,    53,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,    59,     0,     0,    60,     0,     0,
       0,    61,    62,     0,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,     0,     0,    72,    73,
      74,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,    79,    80,    81,     0,    82,    83,    84,    85,    86,
       0,    87,     0,    88,    89,    90,     0,     0,     0,    91,
       0,     0,    92,    93,    94,    95,     0,     0,    96,    97,
      98,     0,    99,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,   649,     0,     0,     0,     0,
     109,   110,   111,     0,   798,     0,   112,   113,   114,   115,
      33,     0,    34,    35,     0,    36,    37,    38,     0,     0,
       0,     0,    39,     0,    40,    41,    42,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,     0,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,     0,
      72,    73,    74,    75,    76,     0,    77,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,     0,    87,     0,    88,    89,    90,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    95,     0,     0,
      96,    97,    98,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,   108,     0,     0,
       0,     0,   109,   110,   111,     0,     0,     0,   112,   113,
     114,   115,    33,     0,    34,    35,     0,    36,    37,    38,
       0,     0,     0,     0,    39,     0,    40,    41,    42,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,    48,     0,     0,     0,     0,    49,    50,
       0,     0,     0,    51,    52,     0,    53,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,    59,     0,
       0,    60,     0,     0,     0,    61,    62,     0,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
       0,     0,    72,    73,    74,    75,    76,     0,    77,     0,
       0,    78,     0,     0,     0,    79,    80,    81,     0,    82,
      83,    84,    85,    86,     0,    87,     0,    88,    89,    90,
       0,     0,     0,    91,     0,     0,    92,    93,    94,    95,
       0,     0,    96,    97,    98,     0,    99,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,   108,
       0,     0,     0,     0,   109,   110,   111,     0,     0,     0,
     112,   113,   114,   115,    33,     0,    34,    35,     0,    36,
      37,    38,     0,     0,     0,     0,    39,     0,    40,    41,
      42,     0,    43,    44,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,    48,     0,     0,     0,     0,
      49,    50,     0,     0,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,     0,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,     0,    72,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,   134,    86,     0,    87,     0,    88,
      89,    90,     0,     0,     0,    91,     0,     0,    92,    93,
      94,    95,     0,     0,    96,    97,    98,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,     0,     0,   224,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,   108,     0,    39,     0,     0,   109,   110,   111,    43,
      44,     0,   112,   113,   114,   115,     0,     0,    45,    46,
      47,     0,    48,     0,     0,     0,     0,    49,     0,     0,
       0,     0,    51,    52,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,     0,     0,     0,     0,     0,
       0,    72,     0,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
       0,    85,    86,     0,    87,     0,    88,    89,    90,     0,
       0,     0,    91,     0,     0,    92,    93,    94,    95,     0,
       0,    96,     0,     0,     0,    99,     0,     0,     0,     0,
     100,     0,   102,   103,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     0,     0,   112,
     113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       2,     1,   157,   210,   157,     7,     8,   129,   283,   152,
     193,   393,   408,     2,   312,   285,   520,   285,     7,   140,
     265,   480,   267,   145,    14,   147,   148,   325,    14,   151,
     568,    14,    14,   308,    14,    14,    14,    14,   158,    14,
     434,   339,   315,    17,    20,    17,    36,   480,    36,    39,
      36,    39,    40,    39,    36,   286,    36,    39,    36,    39,
      36,    39,    36,    39,    36,    39,   336,    39,    28,    21,
      13,    13,    13,    10,    36,    23,    73,    39,     8,    36,
      36,    16,    39,    39,    36,    91,    29,    39,    36,    16,
      13,    39,    40,    41,    42,    43,    44,    45,    36,     8,
      36,    39,    36,    39,    23,    39,   183,   184,   840,    61,
      21,    67,   414,   659,   660,    14,    59,   134,   845,   409,
      19,    19,    73,   125,   126,   116,   123,    62,   130,    13,
     132,    67,   134,   431,    82,    62,   125,   126,    13,   141,
      13,    84,    90,   433,   217,   218,    13,    95,   423,    13,
      61,   989,   141,   155,    32,    33,   158,   148,    34,   457,
     108,   316,    38,    82,  1002,    13,   166,   465,    13,    13,
      13,   630,   123,   337,    75,   445,    95,   445,   108,    33,
     186,   451,   641,   451,   115,    39,    89,   460,   461,   193,
     917,   193,   467,    13,   137,   199,   139,   630,   362,   156,
     932,   218,    14,   102,   102,   436,    23,   144,    13,   211,
     480,   749,   155,    58,   137,   175,   218,   219,   338,    36,
     100,   164,    39,    40,    41,    42,    43,    44,    45,   623,
     220,   214,   220,   164,   220,   214,   112,   214,   220,   214,
     220,   164,   220,   516,   220,    93,   220,   182,   220,    93,
      93,   797,   214,   183,   184,     3,   197,   200,   220,   202,
     203,   563,   204,   220,   220,    82,   214,    14,   220,   212,
     137,   219,   220,    90,   183,   184,   214,   354,    95,   152,
     164,   165,   220,   283,   220,   201,   220,   408,    93,   164,
     165,   108,   137,   591,   121,   159,   678,     6,   462,   681,
       9,   484,   840,   807,   116,     3,   489,   490,   310,    29,
     310,   159,   157,   434,     0,   159,   159,   137,   318,   164,
      66,   780,    69,    51,   706,   721,     6,    74,   211,     9,
      49,   601,    87,   601,   336,   215,   338,   157,   125,   341,
      87,   221,   222,    13,   164,    15,   133,   336,    69,    13,
      78,    15,   341,     5,   159,    14,   358,    76,    10,    11,
     630,   769,   770,    13,    83,   174,   521,   775,   177,   777,
     117,   641,    91,   191,   192,    94,   646,   204,   205,   107,
     171,   172,   132,   133,   922,   104,   273,    15,   642,   276,
     277,   645,    40,   395,   932,    13,   117,    15,    23,   108,
     119,    34,   219,   220,   139,    38,   395,   154,    40,    55,
      42,    36,   131,   214,    39,    40,    41,    42,    43,    44,
      45,   149,    13,   423,    15,    13,   426,    15,    55,   176,
     180,    76,   179,   154,   181,    81,    13,    13,    83,    15,
     944,   945,   824,   139,    77,    65,    91,   132,   133,    94,
     452,   453,    74,    99,    81,   101,   163,    82,    13,    92,
     181,   177,   178,    96,    13,    90,    13,   875,   651,    13,
      95,     4,    99,    13,   101,   720,   189,   190,   480,   112,
     480,    13,   484,   108,   637,    13,   131,   489,   490,     4,
     136,   480,   164,   165,    13,   214,   164,   165,   216,   769,
     770,    75,   623,   976,   977,   775,   130,   777,   214,   136,
     780,   996,   997,    13,   789,    13,   140,   913,   520,    13,
     166,    13,     3,   148,    20,     4,     5,     6,     7,     8,
     154,    10,    11,    93,   158,    13,    13,    13,    13,   166,
     124,    13,   166,   167,    23,    13,    13,    13,    13,     4,
       5,     6,     7,     8,    39,    10,    11,   559,    15,   183,
     184,   207,   208,   209,   210,    13,   568,    28,   155,   176,
     559,    13,    51,    13,   214,    54,    14,    20,   116,    58,
     207,   208,   209,   210,    17,    90,    15,   157,   168,    14,
      14,   591,   216,   162,   219,   220,    51,   872,     5,    54,
     721,    14,    14,    58,   220,   875,    14,    13,   214,    14,
     885,   214,   887,    40,   111,   239,     5,     5,   111,    13,
       5,   111,    13,   625,     5,     5,     5,     5,   630,    13,
     630,   152,   634,   635,   636,     5,   625,   111,    13,   641,
       5,   630,     5,   150,   646,   634,   635,   636,   150,   651,
     274,     5,   641,   928,     5,   150,    13,   646,   214,   283,
     662,   150,   286,   665,   113,   179,   139,    40,    13,    40,
      14,    64,   151,    14,   153,   973,    14,    13,    75,    13,
      13,    13,   188,    14,   308,    14,   120,     3,   312,    13,
       5,    14,    14,    13,   318,    14,   151,     5,   153,    13,
     324,   325,   326,    14,    14,     5,   330,     5,     5,   333,
      13,     5,   111,    14,   338,   339,     5,    13,    13,   343,
     873,    14,    14,    14,   348,    15,   167,    14,   167,   353,
     354,   355,   167,   357,    14,   167,     5,    14,    14,    89,
      65,     5,   213,   173,    14,   119,   748,   749,    14,   186,
       4,     5,     6,     7,     8,   164,    10,    11,    14,     5,
      28,    91,    14,   191,   886,    78,   192,   769,   770,   187,
      14,     5,     5,   775,    49,   777,   929,    22,   780,    14,
     769,   770,    14,     5,   408,   409,   775,   994,   777,    14,
     414,   780,   913,    13,     5,    14,   798,  1004,   941,   423,
      54,    76,     5,    48,    58,   807,    14,   431,    83,   433,
     434,   435,   436,   213,   438,    15,    91,   135,   214,    94,
      49,     5,   169,   447,    14,    14,   450,   829,    14,   104,
    1037,    14,    14,   457,    79,    14,    13,     5,   840,   841,
     829,   465,    91,   467,   119,    14,   999,    76,  1001,  1032,
    1033,    13,    97,    98,    83,    28,   131,    13,    28,    80,
     177,    14,    91,    14,     5,    94,    14,   869,   177,   152,
      14,    14,    14,   875,    14,   104,    14,   150,   150,   150,
      15,    14,   170,   150,     5,   114,   875,   511,   214,    13,
     119,   893,   199,   517,   518,    14,    28,   151,   143,   144,
     145,   146,   131,   121,    49,    28,    14,    14,   139,   167,
     167,    15,   167,    74,   538,   160,   161,   167,    14,   921,
     922,   117,    74,    28,   198,    15,   149,   156,    13,   214,
     932,    76,    14,   140,    15,   152,    82,     5,    83,   563,
      13,     4,   944,   945,   946,    82,    91,    14,   123,    94,
      70,   132,   954,    14,   139,    58,   123,    14,   960,   104,
      14,   139,    17,     4,   118,   967,   132,   591,   968,   114,
     141,   517,   922,   975,   119,   281,   600,   316,   602,    30,
     130,   615,   317,   750,   858,   646,   131,   650,   643,   435,
     140,   595,   348,   353,   343,   585,   620,  1037,   798,   623,
     601,   994,   881,   627,   154,   629,   469,   538,   158,   690,
     211,   156,   422,   738,   656,   955,   166,   167,   655,   282,
     965,    -1,    -1,   125,    -1,    -1,    -1,  1029,  1030,    -1,
    1032,  1033,    -1,   183,   184,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   741,    -1,    -1,
     744,    -1,    -1,    -1,   274,    -1,    -1,   751,   752,    -1,
      -1,    -1,    -1,   283,    -1,    -1,   286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,   312,    -1,    -1,   789,    -1,    -1,   318,    -1,
      -1,    -1,    -1,    -1,   324,   325,   326,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,   339,
      -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,   348,    -1,
      -1,    -1,    -1,   353,   354,   355,    -1,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   850,   851,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   872,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,   409,
      -1,   885,    -1,   887,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   431,    -1,   433,   434,   435,   436,    -1,   438,   913,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,    -1,    -1,
     450,    -1,    -1,    -1,   928,    -1,    -1,   457,    -1,    -1,
      -1,    -1,    -1,   937,    -1,   465,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,   973,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   511,   140,    -1,    -1,   989,    -1,   517,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   154,    -1,  1002,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,    -1,    -1,    -1,
      -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,
      -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,    -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,   623,    -1,    -1,    -1,   627,    -1,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   283,    -1,    -1,   286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    -1,    -1,    -1,   312,    -1,    -1,    -1,    -1,    -1,
     318,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,    -1,
      -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     338,   339,    -1,    -1,    -1,   343,    -1,    -1,    -1,    -1,
     348,   721,    -1,    -1,    -1,   353,   354,   355,    -1,   357,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   741,    -1,    -1,   744,    -1,    -1,    -1,    -1,    -1,
      -1,   751,   752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,   409,    -1,    -1,    -1,    -1,   414,    -1,    -1,   789,
      -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   431,    -1,   433,   434,   435,   436,    -1,
     438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,   450,    -1,    -1,   130,    -1,    -1,    -1,   457,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,    -1,   467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     850,   851,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   881,    -1,   511,    -1,   885,    -1,   887,    -1,   517,
     518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   216,    -1,   913,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   928,    -1,
      -1,    -1,    -1,    -1,    -1,   563,    -1,   937,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   591,    -1,    -1,    -1,    -1,   968,   274,
      -1,    -1,   600,   973,   602,    -1,    -1,    -1,   283,    -1,
      -1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   989,
      -1,    -1,   620,    -1,    -1,   623,    -1,    -1,    -1,   627,
      -1,   629,  1002,   308,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,
      -1,   326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   338,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     355,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,   414,
      -1,    -1,    -1,   741,    -1,    -1,   744,    -1,   423,    -1,
      -1,    -1,    -1,   751,   752,    -1,    -1,    -1,   433,    -1,
     435,   436,    -1,   438,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   447,    -1,    -1,   450,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   789,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,   517,   518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   850,   851,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   872,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   885,   563,   887,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   600,    -1,   602,    -1,    -1,
     928,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   937,
      -1,    -1,    -1,    -1,    -1,   620,    -1,    -1,    -1,    -1,
      -1,    -1,   627,    -1,   629,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     968,    -1,    -1,    -1,    -1,   973,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1002,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   741,    -1,    -1,   744,
      -1,    -1,    -1,    -1,    -1,    -1,   751,   752,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      24,    25,    26,    -1,    -1,   850,   851,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,   872,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,
     885,    -1,   887,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,   928,    -1,   109,   110,   111,   112,   113,
      -1,   115,   937,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,    -1,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     144,   145,   146,    -1,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   989,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,  1002,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
      -1,    -1,    -1,   207,   208,   209,   210,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,   220,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,    -1,   108,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,   137,   138,    -1,   140,    -1,    -1,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,   108,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,    -1,   138,    -1,
     140,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    -1,    52,    53,
      54,    55,    56,    -1,    58,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,    -1,   108,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    52,    53,    54,    55,    56,    -1,
      58,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,   106,    -1,
     108,   109,   110,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,
     218,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    -1,    -1,    16,    -1,    -1,    19,    -1,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,   105,   106,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,    -1,   138,    -1,   140,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,    -1,    -1,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,    -1,   217,   218,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    -1,
      16,    -1,    18,    19,    -1,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,    -1,   138,    -1,   140,    -1,   142,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,   137,   138,    -1,
     140,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    -1,    52,    53,
      54,    55,    56,    -1,    58,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,   138,    -1,   140,    -1,    -1,   143,
     144,   145,   146,   147,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
     164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   218,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    52,    53,    54,    55,    56,    -1,
      58,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    -1,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
     128,   129,   130,   131,   132,    -1,   134,   135,   136,    -1,
     138,    -1,   140,    -1,    -1,   143,   144,   145,   146,   147,
      -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,   206,   207,
     208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,   217,
     218,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,   105,   106,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,   131,
     132,    -1,   134,   135,   136,    -1,   138,    -1,   140,    -1,
      -1,   143,   144,   145,   146,   147,    -1,   149,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,    -1,    -1,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,   217,   218,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    -1,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,   131,   132,    -1,   134,   135,
     136,    -1,   138,    -1,   140,    -1,    -1,   143,   144,   145,
     146,   147,    -1,   149,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   217,   218,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,   131,   132,    -1,   134,   135,   136,    -1,   138,    -1,
     140,    -1,    -1,   143,   144,   145,   146,   147,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,     3,    -1,   206,   207,   208,   209,
     210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,   208,
     209,   210,    19,    -1,    21,    22,   215,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,
     127,   128,   129,   130,    -1,   132,    -1,   134,   135,   136,
      -1,    -1,    -1,   140,    -1,    -1,   143,   144,   145,   146,
      -1,    -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,
     207,   208,   209,   210,    19,    -1,    21,    22,   215,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   144,
     145,   146,    -1,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
      13,    -1,   207,   208,   209,   210,    19,    -1,    21,    22,
     215,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,    -1,   132,
      -1,   134,   135,   136,   137,    -1,    -1,   140,    -1,    -1,
     143,   144,   145,   146,    -1,    -1,   149,   150,   151,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,   164,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    -1,    -1,   207,   208,   209,   210,    21,    22,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    54,    55,    56,    57,    -1,    -1,    60,    61,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,    -1,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,   140,   141,    -1,
     143,   144,   145,   146,    -1,    -1,   149,   150,   151,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    13,    -1,   207,   208,   209,   210,    19,    -1,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
      -1,   132,    -1,   134,   135,   136,   137,    -1,    -1,   140,
      -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    13,    -1,   207,   208,   209,   210,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,   196,     3,    -1,
      -1,    -1,   201,   202,   203,    10,    11,    -1,   207,   208,
     209,   210,    -1,    -1,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   144,
     145,   146,    -1,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
      -1,    -1,   207,   208,   209,   210,    19,    20,    21,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,    -1,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,   144,   145,   146,    -1,    -1,   149,   150,   151,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    -1,    -1,   207,   208,   209,   210,    19,    20,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    93,    -1,    -1,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
      -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,   140,
      -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    13,    -1,   207,   208,   209,   210,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,   208,
     209,   210,    19,    -1,    21,    22,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,
     127,   128,   129,   130,    -1,   132,    -1,   134,   135,   136,
      -1,    -1,    -1,   140,    -1,    -1,   143,   144,   145,   146,
      -1,    -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,
     207,   208,   209,   210,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,    -1,   132,    -1,   134,
     135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,   144,
     145,   146,    -1,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    31,    -1,    -1,   201,   202,   203,    37,
      38,    -1,   207,   208,   209,   210,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,
      98,    99,    -1,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
      -1,   129,   130,    -1,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,
      -1,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,
     208,   209,   210
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    13,    29,    59,    84,   137,   139,   155,   164,   200,
     202,   203,   212,   224,   225,   226,   227,   228,   229,   234,
     235,   236,   239,   240,   246,   247,   248,   249,   250,   256,
     270,   247,     3,    19,    21,    22,    24,    25,    26,    31,
      33,    34,    35,    37,    38,    46,    47,    48,    50,    55,
      56,    60,    61,    63,    70,    73,    77,    79,    81,    85,
      88,    92,    93,    96,    97,    98,    99,   101,   102,   103,
     105,   106,   109,   110,   111,   112,   113,   115,   118,   122,
     123,   124,   126,   127,   128,   129,   130,   132,   134,   135,
     136,   140,   143,   144,   145,   146,   149,   150,   151,   153,
     158,   159,   160,   161,   165,   166,   167,   177,   196,   201,
     202,   203,   207,   208,   209,   210,   233,   291,   336,   338,
     367,   385,   387,   388,   390,    75,    89,    16,    62,   182,
     276,     3,   291,   415,   129,   271,   272,   385,   201,   225,
       3,    29,     0,    66,   211,    69,   117,   154,   181,   263,
     264,    87,   248,    14,    13,    15,   415,   291,   276,     4,
       5,     6,     7,     8,    10,    11,    13,    30,    31,    37,
      46,    52,    53,    54,    58,    94,   109,   131,   138,   147,
     151,   206,   215,   217,   218,   251,   252,   254,   277,   278,
     288,   289,   291,   314,   315,   316,   317,   318,   319,   328,
     329,   334,   335,   336,   337,   338,   354,   355,   367,   385,
      40,    20,   381,   382,   383,   385,   139,   271,   214,    13,
     273,   274,   139,    65,     3,    24,    25,    26,    27,    32,
      33,    35,    54,    56,    57,    63,    72,    85,    86,    88,
     103,   105,   106,   110,   128,   130,   141,   150,   151,   158,
     336,   338,   356,   357,   358,   359,   360,   361,   362,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   386,   388,
     389,   233,   225,   276,    28,   175,   276,   276,    74,   391,
     392,   276,   263,    13,    14,    71,   108,   185,   230,   231,
     232,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   313,   314,   385,   385,   163,   258,
      13,    58,   157,   237,   238,   246,   274,   277,    13,   247,
     314,   320,   314,   330,    13,    13,    13,    13,     4,    13,
      13,    13,     4,    13,   318,   318,    75,   259,   214,    13,
      36,    39,   220,   324,   381,   384,   217,   218,   326,   100,
     215,   221,   222,   327,   216,    13,    13,    13,    15,   151,
     328,   383,   244,   245,   314,   271,   275,   385,    20,     3,
      93,    13,    13,    93,   159,    13,    93,   159,    13,    13,
      13,   124,    13,   136,   363,   364,   366,   367,    32,    33,
      13,    93,   159,    13,    13,    13,    13,   164,   165,    13,
     164,   165,    13,    19,   102,    33,   384,   384,    15,    13,
     249,   265,   266,   314,    28,   249,   249,   155,   176,   397,
     401,   250,   391,    13,   299,   314,    13,   252,   253,   301,
     314,    13,    14,   214,    20,   116,    17,    90,    23,    40,
      41,    42,    43,    44,    45,    82,    90,    95,   108,   219,
     323,   325,    15,    15,   299,   157,   320,   168,   241,   241,
     238,   246,   259,   247,    14,   214,    14,   162,   331,   332,
     314,   320,   314,     5,    14,   314,    14,   136,   365,   367,
      13,   115,   194,   195,   253,   279,   280,   281,   282,   286,
     290,   291,   292,   293,   294,   295,   296,   258,   277,    14,
     320,   291,   220,   315,   316,   317,   318,    16,    62,   215,
     314,   379,    14,   314,   215,   385,   258,   214,    40,    14,
     214,    13,   255,    40,   111,     5,     5,   111,    13,     5,
     111,    13,     5,   376,     5,     5,     5,    13,   152,    13,
      13,   159,    13,    93,   159,     5,   111,    13,   376,     5,
     291,     5,   150,   150,     5,   150,   150,     5,    13,   139,
     386,    14,   230,   214,    21,    61,   267,   265,   113,   393,
       5,    10,    11,   400,   179,   404,   397,    14,   320,   230,
     356,   300,   301,     6,     9,   108,   322,   314,    40,    40,
      42,    13,   253,   321,     8,   108,   183,   184,   312,   314,
      23,    82,    95,    40,    16,    18,   142,   314,   380,   253,
     385,   385,   320,   241,   241,   258,    14,   320,   299,   314,
      64,   333,   331,    20,    14,   156,    14,   214,    13,    75,
      13,   280,   291,   292,    13,    13,    13,   381,    49,    76,
      83,    91,    94,   104,   119,   131,   214,   297,   381,   196,
     381,   413,   191,   192,   257,   410,   411,   412,    14,    14,
      14,   314,   120,   339,    14,    15,   241,   244,   314,   275,
     246,   188,   405,   406,     3,    13,    14,    14,    13,     5,
      14,    13,     5,    34,    38,    77,    92,    96,   112,   377,
     378,    14,    14,   214,    14,   214,    14,     5,   365,     5,
       5,    13,     5,   111,    13,    14,    13,     5,    14,    14,
     214,    14,    14,   167,   167,    14,   167,   167,    14,     5,
     291,    15,   213,    14,   265,   173,   268,   289,   385,   394,
     171,   172,   396,   132,   133,   398,   177,   178,   402,    14,
     322,    17,   320,   312,    67,   314,   321,   314,    15,    89,
     257,   148,   148,   314,    65,   356,   291,   314,     5,   314,
      14,    14,   291,   291,   291,   204,   274,   283,   287,    91,
     186,   119,   298,   280,   298,    91,   297,   186,   298,   279,
      91,    13,   197,   121,   205,   283,   284,   285,   381,   164,
      28,    78,   260,   411,   410,   339,   339,    14,    13,   340,
     341,   385,   215,   385,    14,   189,   190,   187,   407,   408,
       5,   376,    14,   376,    14,   377,     5,     5,    14,   214,
      14,    14,     5,    14,    13,     5,   376,    14,     5,   135,
     164,   165,   164,   165,    14,   384,   386,   213,   174,   177,
     214,    15,     5,   169,   395,   399,   400,   314,    14,   314,
      17,    67,   385,    10,    11,   242,   243,   289,   260,   314,
     314,    14,    14,    14,    14,    14,    14,    14,    14,    13,
     281,   281,   114,   156,   281,    91,   281,   280,     5,    13,
      28,    13,   299,   193,   199,   409,    28,    80,   269,   339,
     341,   342,   343,    15,   177,   177,   275,    14,    14,    14,
      14,    14,     5,    14,   376,    14,    14,    14,   291,   150,
     150,   150,   150,    15,   394,   385,   170,   180,   398,   314,
     314,    15,   214,   269,   385,   299,   274,   281,   114,   156,
      14,     5,    13,   335,   336,   199,   299,   276,   299,    14,
     121,   344,   215,   385,    28,    28,   139,    14,    14,   167,
     167,   167,   167,   386,    15,   398,   115,   164,   403,   242,
      74,   299,   274,   198,   414,    14,   394,    74,    13,    79,
     261,   262,   314,    28,   263,    15,   275,   275,   385,   385,
     403,   149,   385,    13,   414,    14,   385,    14,   140,   214,
     320,   125,   133,   345,   346,   385,   267,   267,   152,    82,
       5,    82,    13,   261,    23,    51,   153,   328,   347,   348,
     349,   350,   268,   268,     4,   274,    14,   274,   261,   153,
     328,   348,   351,   352,   132,   123,   123,    70,   353,   139,
     139,    58,    14,    14,    14,    73,    73,    17,    51,    78,
     107,   149,   385,   385,     4,   381,   381,   351,   132,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   223,   224,   225,   225,   226,   226,   226,   226,   226,
     226,   227,   228,   228,   228,   229,   229,   229,   229,   230,
     230,   231,   231,   232,   232,   233,   234,   235,   235,   235,
     236,   237,   237,   237,   237,   237,   238,   239,   240,   241,
     241,   242,   242,   243,   243,   243,   244,   244,   245,   246,
     247,   247,   248,   248,   248,   248,   249,   249,   250,   250,
     251,   252,   253,   254,   255,   256,   256,   257,   257,   258,
     258,   259,   260,   260,   261,   261,   262,   262,   262,   263,
     263,   264,   264,   265,   265,   266,   267,   267,   267,   268,
     268,   268,   269,   269,   270,   270,   271,   271,   272,   273,
     273,   274,   275,   275,   276,   276,   276,   277,   277,   278,
     278,   279,   279,   280,   280,   281,   281,   282,   282,   282,
     282,   282,   282,   282,   282,   283,   284,   285,   286,   286,
     286,   287,   287,   288,   288,   288,   288,   289,   289,   289,
     289,   289,   290,   290,   291,   291,   291,   292,   292,   292,
     292,   293,   293,   294,   294,   294,   294,   295,   296,   296,
     297,   297,   297,   297,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   302,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   305,   306,   307,   308,   308,
     309,   309,   309,   309,   310,   310,   311,   311,   312,   312,
     312,   313,   314,   314,   314,   315,   315,   316,   316,   317,
     317,   318,   318,   318,   319,   319,   319,   319,   319,   319,
     320,   320,   321,   321,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   324,   324,   325,   326,
     326,   327,   327,   327,   327,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   329,   330,   330,   331,   331,
     332,   332,   333,   333,   334,   334,   334,   334,   335,   335,
     335,   335,   335,   335,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   337,   338,   338,   338,   338,
     338,   339,   339,   340,   341,   342,   343,   343,   344,   344,
     345,   345,   346,   346,   347,   347,   348,   348,   348,   349,
     350,   351,   351,   351,   352,   353,   353,   353,   353,   353,
     354,   354,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   356,   356,   356,   356,   357,
     358,   358,   358,   358,   359,   360,   360,   360,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   361,   362,
     363,   363,   364,   364,   365,   365,   365,   366,   366,   366,
     366,   366,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   368,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   370,   370,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   372,
     372,   372,   372,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   374,   374,   374,   374,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   376,   376,   376,   376,   377,
     377,   377,   378,   378,   378,   379,   379,   380,   380,   380,
     381,   381,   382,   382,   383,   384,   385,   385,   386,   386,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   387,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   389,   389,
     389,   389,   390,   390,   390,   390,   390,   391,   391,   392,
     393,   393,   394,   394,   395,   395,   396,   396,   396,   397,
     398,   398,   399,   399,   400,   400,   400,   401,   401,   402,
     402,   403,   403,   404,   404,   404,   405,   405,   406,   406,
     407,   407,   408,   409,   409,   409,   409,   410,   411,   412,
     412,   412,   413,   413,   414,   414,   415
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     0,     1,     1,     1,     1,
       1,     3,     6,     4,     3,     5,     4,     7,     6,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     3,     3,     2,     2,     2,     4,     6,     0,
       4,     1,     3,     1,     1,     1,     1,     3,     3,     1,
       4,     5,     1,     4,     4,     4,     1,     4,     1,     3,
       3,     1,     1,     1,     3,     8,     9,     0,     1,     0,
       2,     2,     0,     4,     1,     3,     2,     1,     5,     0,
       1,     3,     4,     1,     3,     3,     0,     1,     1,     0,
       2,     2,     0,     2,     2,     3,     1,     3,     6,     0,
       1,     3,     1,     3,     0,     1,     1,     1,     3,     2,
       1,     1,     3,     1,     1,     1,     3,     2,     3,     2,
       3,     3,     3,     3,     3,     9,     9,     5,     4,     4,
       4,     0,     1,     1,     3,     5,     7,     1,     3,     5,
       7,     9,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     4,     4,     6,     5,     6,     5,     4,     5,     4,
       2,     2,     2,     1,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     5,     6,
       3,     5,     4,     6,     3,     4,     3,     4,     1,     1,
       1,     2,     1,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     5,     0,     1,     1,     2,
       4,     4,     0,     2,     1,     1,     1,     1,     5,     4,
       6,     5,     5,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     2,     2,     3,     1,     4,     0,     1,     0,     3,
       0,     3,     1,     1,     1,     1,     2,     2,     1,     2,
       4,     1,     2,     1,     2,     0,     3,     2,     2,     3,
       3,     4,     4,     3,     3,     6,     6,     4,     1,     4,
       1,     6,     1,     1,     6,     1,     1,     1,     1,     1,
       1,     3,     5,     7,     6,     5,     2,     2,     5,     4,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     4,     1,     1,     4,     1,     4,     1,     6,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     7,     4,     4,     4,     7,     7,
       4,     4,     4,     1,     1,     1,     6,     4,     6,     4,
       6,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     1,     1,     4,     4,     5,     5,     4,     6,     3,
       6,     3,     4,     1,     1,     1,     6,     3,     4,     1,
       5,     2,     5,     2,     4,     6,     6,     5,     7,     4,
       6,     3,     4,     1,     1,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     5,
       0,     2,     1,     3,     0,     2,     0,     1,     2,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     3,     1,
       1,     1,     2,     0,     5,     6,     0,     1,     9,     9,
       0,     1,     8,     0,     1,     2,     1,     4,     3,     2,
       1,     2,     6,     5,     0,     4,     2
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
#if ORACLE_DEBUG

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
# if defined ORACLE_LTYPE_IS_TRIVIAL && ORACLE_LTYPE_IS_TRIVIAL

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
#else /* !ORACLE_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !ORACLE_DEBUG */


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
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3514 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3520 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 5: /* INTNUM  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3526 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 6: /* BOOL  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3532 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 7: /* APPROXNUM  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3538 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 8: /* NULLX  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3544 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 9: /* UNKNOWN  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3550 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 10: /* QUESTIONMARK  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3556 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 11: /* PARAM  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3562 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 224: /* sql_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3568 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 225: /* stmt_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3574 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 226: /* stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3580 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 227: /* body_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3586 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 228: /* special_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3592 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 229: /* call_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3598 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 230: /* sql_argument_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3604 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 231: /* sql_argument  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3610 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 232: /* value_expression  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3616 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 233: /* sp_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3622 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 234: /* dql_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3628 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 235: /* dml_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3634 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 236: /* insert_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3640 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 237: /* insert_columns_and_source  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3646 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 238: /* from_constructor  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3652 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 239: /* delete_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3658 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 240: /* update_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3664 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 241: /* opt_returning_into  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3670 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 242: /* variable_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3676 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 243: /* variable  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3682 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 244: /* update_elem_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3688 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 245: /* update_elem  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3694 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 246: /* select_stmt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3700 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 247: /* query_expression  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3706 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 248: /* query_expression_body  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3712 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 249: /* query_term  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3718 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 250: /* query_primary  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3724 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 251: /* select_with_parens  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3730 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 252: /* subquery  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3736 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 253: /* table_subquery  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3742 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 254: /* row_subquery  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3748 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 255: /* cte_subquery  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3754 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 256: /* simple_table  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3760 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 257: /* opt_hierarchical_query_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3766 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 258: /* opt_where  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3772 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 259: /* opt_from_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3778 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 260: /* opt_groupby  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3784 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 261: /* grouping_element_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3790 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 262: /* grouping_element  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3796 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 263: /* opt_order_by  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3802 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 264: /* order_by  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3808 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 265: /* sort_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3814 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 266: /* sort_key  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3820 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 267: /* opt_asc_desc  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3826 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 268: /* opt_nulls_c  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3832 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 269: /* opt_having  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3838 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 270: /* with_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3844 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 271: /* with_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3850 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 272: /* common_table_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3856 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 273: /* opt_derived_column_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3862 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 274: /* simple_ident_list_with_parens  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3868 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 275: /* simple_ident_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3874 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 276: /* opt_distinct  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3880 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 277: /* select_expr_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3886 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 278: /* projection  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3892 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 279: /* from_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3898 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 280: /* table_reference  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3904 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 281: /* table_primary  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3910 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 282: /* table_primary_non_join  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3916 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 283: /* unpivot_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3922 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 284: /* pivot_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3928 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 285: /* partition_by  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3934 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 286: /* table_function  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3940 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 287: /* opt_simple_ident_list_with_parens  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3946 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 288: /* asterisk_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3952 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 289: /* column_ref  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3958 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 290: /* relation_factor_2  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3964 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 291: /* relation_factor  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3970 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 292: /* joined_table  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3976 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 293: /* cross_apply  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3982 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 294: /* qualified_join  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3988 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 295: /* cross_join  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3994 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 296: /* natural_join  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4000 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 297: /* join_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4006 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 299: /* search_condition  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4012 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 300: /* boolean_term  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4018 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 301: /* boolean_factor  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4024 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 302: /* boolean_test  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4030 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 303: /* boolean_primary  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4036 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 304: /* predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4042 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 305: /* bool_function  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4048 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 306: /* comparison_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4054 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 307: /* quantified_comparison_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4060 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 308: /* between_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4066 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 309: /* like_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4072 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 310: /* in_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4078 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 311: /* null_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4084 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 312: /* null_value  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4090 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 313: /* exists_predicate  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4096 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 314: /* row_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4102 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 315: /* factor0  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4108 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 316: /* factor1  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4114 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 317: /* factor2  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4120 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 318: /* factor3  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4126 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 319: /* factor4  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4132 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 320: /* row_expr_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4138 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 321: /* in_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4144 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 322: /* truth_value  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4150 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 328: /* expr_const  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4156 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 329: /* case_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4162 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 330: /* case_arg  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4168 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 331: /* when_clause_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4174 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 332: /* when_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4180 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 333: /* case_default  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4186 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 334: /* func_expr  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4192 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 335: /* aggregate_windowed_function  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4198 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 336: /* aggregate_function_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4204 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 337: /* ranking_windowed_function  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4210 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 338: /* ranking_function_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4216 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 339: /* over_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4222 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 340: /* window_specification  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4228 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 341: /* window_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4234 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 342: /* window_specification_details  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4240 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 343: /* opt_existing_window_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4246 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 344: /* opt_window_partition_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4252 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 345: /* opt_window_frame_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4258 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 346: /* window_frame_units  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4264 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 347: /* window_frame_extent  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4270 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 348: /* window_frame_start  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4276 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 349: /* window_frame_preceding  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4282 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 350: /* window_frame_between  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4288 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 351: /* window_frame_bound  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4294 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 352: /* window_frame_following  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4300 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 353: /* opt_window_frame_exclusion  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4306 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 354: /* scalar_function  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4312 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 355: /* function_call_keyword  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4318 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 356: /* data_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4324 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 357: /* user_defined_type_name  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4330 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 358: /* relation_factor_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4336 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 359: /* reference_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4342 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 360: /* collection_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4348 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 361: /* predefined_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4354 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 362: /* interval_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4360 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 363: /* interval_qualifier  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4366 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 364: /* start_field  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4372 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 365: /* end_field  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4378 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 366: /* single_datetime_field  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4384 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 367: /* non_second_primary_datetime_field  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4390 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 368: /* boolean_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4396 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 369: /* datetime_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4402 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 370: /* numeric_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4408 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 371: /* exact_numeric_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4414 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 372: /* approximate_numeric_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4420 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 373: /* character_string_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4426 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 374: /* binary_large_object_string_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4432 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 375: /* national_character_string_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4438 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 376: /* large_object_length  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4444 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 377: /* char_length_units  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4450 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 378: /* multiplier  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4456 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 379: /* distinct_or_all  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4462 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 381: /* opt_as_label  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4468 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 382: /* as_label  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4474 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 383: /* label  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4480 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 384: /* collate_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4486 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 385: /* name_r  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4492 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 386: /* name_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4498 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 387: /* reserved_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4504 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 388: /* reserved_other  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4510 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 389: /* reserved_non_type  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4516 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 390: /* reserved  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4522 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 391: /* opt_for_update  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4528 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 392: /* for_update  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4534 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 393: /* opt_of_column_ref_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4540 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 394: /* column_ref_list  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4546 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 395: /* opt_ignore_lock  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4552 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 396: /* opt_wait_nowait  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4558 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 397: /* row_limiting_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4564 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 398: /* row_rows  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4570 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 399: /* opt_variable_v2  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4576 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 400: /* variable_v2  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4582 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 401: /* opt_offset_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4588 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 402: /* first_next  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4594 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 403: /* only_or_ties  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4600 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 404: /* opt_fetch_rows_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4606 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 405: /* opt_search_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4612 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 406: /* search_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4618 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 407: /* opt_cycle_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4624 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 408: /* cycle_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4630 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 409: /* connect_opt  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4636 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 410: /* connect_by  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4642 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 411: /* start_with  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4648 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 412: /* hierarchical_query_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4654 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 413: /* sample_clause  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4660 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 414: /* opt_seed_value  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4666 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
        break;

    case 415: /* simple_table_alias  */
#line 95 "oracle.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4672 "sqlparser_oracle_bison.cpp" /* yacc.c:1257  */
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
# if defined ORACLE_LTYPE_IS_TRIVIAL && ORACLE_LTYPE_IS_TRIVIAL
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
#line 64 "oracle.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 4789 "sqlparser_oracle_bison.cpp" /* yacc.c:1429  */
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
#line 246 "oracle.y" /* yacc.c:1646  */
    {
    g_QuestMarkId = 0;
    (yyval.node) = (yyvsp[-1].node);
    result->result_tree_ = (yyvsp[-1].node);
    result->accept = true;
    YYACCEPT;
}
#line 4984 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 258 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
#line 4993 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 265 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 4999 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 275 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_BODYS, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &STMT_BODYS_SERIALIZE_FORMAT_ORA;
}
#line 5008 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 282 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_ALTER_SESSION, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &ALTER_SESSION_SERIALIZE_FORMAT_ORA;
}
#line 5017 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 287 "oracle.y" /* yacc.c:1646  */
    {
    std::string val = "SET ";
    val += (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    val += " = ";
    val += (yyvsp[0].node)->text();
    delete((yyvsp[0].node));

    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 5032 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 298 "oracle.y" /* yacc.c:1646  */
    {
    std::string val = "DECLARE ";
    val += (yyvsp[-1].node)->text();
    delete((yyvsp[-1].node));
    val += " ";
    val += (yyvsp[0].node)->text();
    delete((yyvsp[0].node));

    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 5047 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 312 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 5056 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 317 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-2].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 5065 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 322 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 5074 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 327 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 5083 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 336 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5092 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 344 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 5101 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 349 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 5110 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 376 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 5119 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 384 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5128 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 389 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5137 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 394 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5146 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 399 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5155 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 404 "oracle.y" /* yacc.c:1646  */
    {
    Node* src = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT VALUES");
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, src);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 5165 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 413 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
#line 5174 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		(yyvsp[-1].node),		/* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,        /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		(yyvsp[0].node),		/* E_DELETE_OPT_WHERE 6 */
    		nullptr 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    (yyval.node)->serialize_format = &DELETE_SERIALIZE_FORMAT;
}
#line 5191 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 439 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE, E_UPDATE_PROPERTY_CNT,
    		nullptr,	/* E_UPDATE_OPT_WITH 0 */
    		nullptr,	/* E_UPDATE_OPT_TOP 1 */
    		(yyvsp[-4].node),		/* E_UPDATE_UPDATE_RELATION 2 */
    		nullptr,	/* E_UPDATE_UPDATE_RELATION_OPT_TABLE_HINT 3 */
    		(yyvsp[-2].node),		/* E_UPDATE_UPDATE_ELEM_LIST 4 */
    		nullptr,	/* E_UPDATE_OPT_OUTPUT 5 */
    		nullptr,	/* E_UPDATE_FROM_LIST 6 */
    		(yyvsp[-1].node),		/* E_UPDATE_OPT_WHERE 7 */
    		(yyvsp[0].node)		/* E_UPDATE_OPT_QUERY_HINT 8 */);
    (yyval.node)->serialize_format = &UPDATE_SERIALIZE_FORMAT;
}
#line 5209 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 454 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 5215 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 456 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_RETURNING_INTO, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &RETURNING_INTO_SERIALIZE_FORMAT;
}
#line 5224 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 464 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_VAR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5233 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 479 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5242 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 487 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
#line 5251 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 496 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);

}
#line 5260 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 504 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, (yyvsp[-3].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;

        (yyval.node)->setChild(E_DIRECT_SELECT_ORDER, (yyvsp[-2].node));
        (yyval.node)->setChild(E_DIRECT_SELECT_FOR_UPDATE, (yyvsp[-1].node));
        (yyval.node)->setChild(E_DIRECT_HINT_CLAUSE, (yyvsp[0].node));

}
#line 5274 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 514 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-3].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;


        (yyval.node)->setChild(E_DIRECT_SELECT_ORDER, (yyvsp[-2].node));
        (yyval.node)->setChild(E_DIRECT_SELECT_FOR_UPDATE, (yyvsp[-1].node));
        (yyval.node)->setChild(E_DIRECT_HINT_CLAUSE, (yyvsp[0].node));
}
#line 5288 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 527 "oracle.y" /* yacc.c:1646  */
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
                        nullptr             /*user for bigquery*/
                        );
    (yyval.node)->serialize_format = &SELECT_UNION_SERIALIZE_FORMAT;
}
#line 5319 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 554 "oracle.y" /* yacc.c:1646  */
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
                        nullptr,             /* E_SELECT_OPT_INTO 18 */
                        nullptr             /*user for bigquery*/
                        );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT;
}
#line 5350 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 581 "oracle.y" /* yacc.c:1646  */
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
                     nullptr,             /* E_SELECT_OPT_INTO 18 */
                     nullptr             /*user for bigquery*/
                     );
    (yyval.node)->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT;
}
#line 5381 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 612 "oracle.y" /* yacc.c:1646  */
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
                        nullptr             /*user for bigquery*/
                        );
    (yyval.node)->serialize_format = &SELECT_INTERSECT_SERIALIZE_FORMAT;
}
#line 5412 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 643 "oracle.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].node)->getChild(E_DIRECT_SELECT_WITH)) {
        yyerror(&(yylsp[-2]), result, scanner, "error use common table expression");
        YYABORT;
    }
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5425 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 656 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5434 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 669 "oracle.y" /* yacc.c:1646  */
    {
        (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
        (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
    }
#line 5443 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 677 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                    (yyvsp[-6].node),             /* E_SELECT_DISTINCT 0 */
                    (yyvsp[-5].node),             /* E_SELECT_SELECT_EXPR_LIST 1 */
                    (yyvsp[-4].node),             /* E_SELECT_FROM_LIST 2 */
                    (yyvsp[-3].node),             /* E_SELECT_OPT_WHERE 3 */
                    (yyvsp[-1].node),             /* E_SELECT_GROUP_BY 4 */
                    (yyvsp[0].node),             /* E_SELECT_HAVING 5 */
                    nullptr,        /* E_SELECT_SET_OPERATION 6 */
                    nullptr,        /* E_SELECT_ALL_SPECIFIED 7 */
                    nullptr,        /* E_SELECT_FORMER_SELECT_STMT 8 */
                    nullptr,        /* E_SELECT_LATER_SELECT_STMT 9 */
                    nullptr,        /* E_SELECT_ORDER_BY 10 */
                    nullptr,             /* E_SELECT_LIMIT 11 */
                    nullptr,        /* E_SELECT_FOR_UPDATE 12 */
                    nullptr,        /* E_SELECT_HINTS 13 */
                    nullptr,        /* E_SELECT_WHEN 14 */
                    nullptr,        /* E_SELECT_OPT_TOP 15 */
                    nullptr,        /* E_SELECT_OPT_WITH 16 */
                    nullptr,        /* E_SELECT_OPT_OPTION 17 */
	                nullptr,         /* E_SELECT_OPT_INTO 18 */
	                (yyvsp[-2].node)             /*user for oracle */
                    );
    (yyval.node)->serialize_format = &SELECT_SERIALIZE_FORMAT_ORA;
}
#line 5473 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 703 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
          (yyvsp[-6].node),             /* E_SELECT_DISTINCT 0 */
          (yyvsp[-5].node),             /* E_SELECT_SELECT_EXPR_LIST 1 */
          (yyvsp[-4].node),             /* E_SELECT_FROM_LIST 2 */
          (yyvsp[-3].node),             /* E_SELECT_OPT_WHERE 3 */
          (yyvsp[-1].node),             /* E_SELECT_GROUP_BY 4 */
          (yyvsp[0].node),             /* E_SELECT_HAVING 5 */
          nullptr,        /* E_SELECT_SET_OPERATION 6 */
          nullptr,        /* E_SELECT_ALL_SPECIFIED 7 */
          nullptr,        /* E_SELECT_FORMER_SELECT_STMT 8 */
          nullptr,        /* E_SELECT_LATER_SELECT_STMT 9 */
          nullptr,        /* E_SELECT_ORDER_BY 10 */
          nullptr,        /* E_SELECT_LIMIT 11 */
          nullptr,        /* E_SELECT_FOR_UPDATE 12 */
          nullptr,        /* E_SELECT_HINTS 13 */
          nullptr,        /* E_SELECT_WHEN 14 */
          nullptr,        /* E_SELECT_OPT_TOP 15 */
          nullptr,        /* E_SELECT_OPT_WITH 16 */
          nullptr,        /* E_SELECT_OPT_OPTION 17 */
          nullptr,        /* E_SELECT_OPT_INTO 18 */
          (yyvsp[-2].node)         /* user for oracle*/
          );
    (yyval.node)->serialize_format = &SELECT_SERIALIZE_FORMAT2_ORA;
}
#line 5503 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 730 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5509 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 734 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5515 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 736 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
#line 5524 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 745 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FROM_SERIALIZE_FORMAT;
}
#line 5533 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 752 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5539 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 754 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
#line 5548 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 763 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5557 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 770 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"()"); }
#line 5563 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 773 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5574 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 782 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5580 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 788 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_BY_SERIALIZE_FORMAT;
}
#line 5589 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 793 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_SIBLINGS_BY_SERIALIZE_FORMAT;
}
#line 5598 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 802 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5607 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 810 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_KEY, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5616 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 818 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "");
}
#line 5624 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 822 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
#line 5632 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 826 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
#line 5640 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 832 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5646 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 833 "oracle.y" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS FIRST"); }
#line 5652 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 834 "oracle.y" /* yacc.c:1646  */
    {    (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS LAST"); }
#line 5658 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 838 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5664 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 840 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
#line 5673 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 850 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
#line 5682 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 855 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
#line 5691 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 864 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5700 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 873 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT_ORA;
}
#line 5709 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 880 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5715 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 886 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5724 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 895 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5733 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 902 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5739 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 904 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 5747 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 908 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 5755 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 916 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5764 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 924 "oracle.y" /* yacc.c:1646  */
    {
    if (!(yyvsp[0].node)) {
    	(yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, (yyvsp[-1].node));
    	(yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
    }
    else {
	    Node* alias_node = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
        alias_node->serialize_format = &ORA_AS_SERIALIZE_FORMAT;

        (yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, alias_node);
        (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
    }
}
#line 5782 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 943 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5791 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 957 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5800 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 969 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5809 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 974 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5818 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 979 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5827 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 984 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5836 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 989 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5845 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 994 "oracle.y" /* yacc.c:1646  */
    {
    // Translate "relation_factor" into "table_subquery" node for mask and filter
    Node* alias_node = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    alias_node->serialize_format = &ORA_AS_SERIALIZE_FORMAT;

    Node* from_clause_node = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, alias_node);
    from_clause_node->serialize_format = &FROM_SERIALIZE_FORMAT;

    Node* star_node = Node::makeTerminalNode(E_STAR, "*");

    Node* select_node = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        star_node,           /* E_SELECT_SELECT_EXPR_LIST 1 */
                        from_clause_node,    /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        nullptr,             /* E_SELECT_SET_OPERATION 6 */
                        nullptr,             /* E_SELECT_ALL_SPECIFIED 7 */
                        nullptr,             /* E_SELECT_FORMER_SELECT_STMT 8 */
                        nullptr,             /* E_SELECT_LATER_SELECT_STMT 9 */
                        nullptr,             /* E_SELECT_ORDER_BY 10 */
                        nullptr,             /* E_SELECT_LIMIT 11 */
                        nullptr,             /* E_SELECT_FOR_UPDATE 12 */
                        nullptr,             /* E_SELECT_HINTS 13 */
                        nullptr,             /* E_SELECT_WHEN 14 */
                        nullptr,             /* E_SELECT_OPT_TOP 15 */
                        nullptr,             /* E_SELECT_OPT_WITH 16 */
                        nullptr,             /* E_SELECT_OPT_OPTION 17 */
                        nullptr,             /* E_SELECT_OPT_INTO 18 */
                        nullptr              /*user for bigquery*/
                        );
    select_node->serialize_format = &SELECT_SERIALIZE_FORMAT;

    Node* direct_select_node = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, select_node, nullptr, nullptr,nullptr);
    direct_select_node->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;

    Node* select_with_parens_node = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, direct_select_node);
    select_with_parens_node->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    Node * alias_name_node = nullptr;
    if ((yyvsp[-1].node)){
        alias_name_node =  (yyvsp[-1].node);
    } else {
        alias_name_node =  Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->getChild(E_TABLE_IDENT_OBJECT)->text());
    }
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, select_with_parens_node, alias_name_node, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5899 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1044 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5908 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1049 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5917 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1056 "oracle.y" /* yacc.c:1646  */
    {
    Node* npvt = Node::makeTerminalNode(E_IDENTIFIER, "UNPIVOT");
    (yyval.node) = Node::makeNonTerminalNode(E_UNPIVOT_PIVOT, 5, npvt, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &PIVOT_CLAUSE_SERIALIZE_FORMAT;
}
#line 5927 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1064 "oracle.y" /* yacc.c:1646  */
    {
    Node* npvt = Node::makeTerminalNode(E_IDENTIFIER, "PIVOT");
    (yyval.node) = Node::makeNonTerminalNode(E_UNPIVOT_PIVOT, 5, npvt, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &PIVOT_CLAUSE_SERIALIZE_FORMAT;
}
#line 5937 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1073 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_PARTITION_BY, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &PARTITION_BY_SERIALIZE_FORMAT;
}
#line 5946 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1080 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "ONLY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5957 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1087 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONTAINERS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5968 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1094 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SHARDS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5979 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1103 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5985 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1110 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STAR, "*");
}
#line 5993 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1114 "oracle.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, nullptr, (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6003 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1120 "oracle.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6013 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1126 "oracle.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6023 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1135 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6033 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1141 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6043 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1147 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6053 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1153 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6063 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1159 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-8].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6073 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1231 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6082 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1239 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6091 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1244 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 6100 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1249 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 6109 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1293 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_3_SERIALIZE_FORMAT;
}
#line 6119 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1299 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "OUTER");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_3_SERIALIZE_FORMAT;
}
#line 6129 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1307 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 6138 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1312 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 6148 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1318 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 6157 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1323 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 6167 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1332 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6177 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1341 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL " + (yyvsp[-2].node)->text());
    delete((yyvsp[-2].node));
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6188 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1348 "oracle.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6198 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1357 "oracle.y" /* yacc.c:1646  */
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
#line 6213 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1368 "oracle.y" /* yacc.c:1646  */
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
#line 6228 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1379 "oracle.y" /* yacc.c:1646  */
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
#line 6243 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1390 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_JOIN_INNER, "INNER");
}
#line 6251 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1396 "oracle.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 6257 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1397 "oracle.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; /*this is a flag*/}
#line 6263 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1404 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 6272 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1413 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 6281 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1422 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 6290 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1431 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 6299 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1436 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 6308 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1445 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6317 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1474 "oracle.y" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_LIKE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6328 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1483 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6337 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1491 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6346 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1499 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 6355 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1504 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 6364 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1512 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 6373 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1517 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 6382 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1522 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 6391 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1527 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 6400 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1535 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 6409 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1540 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 6418 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1548 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 6427 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1553 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 6436 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1561 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NAN"); }
#line 6442 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1562 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INFINITE"); }
#line 6448 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1566 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 6457 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1576 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6466 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1581 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6475 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1590 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6484 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1599 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6493 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1608 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POW);
}
#line 6502 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1617 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POS);
}
#line 6511 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1622 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
#line 6520 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1633 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6529 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1644 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6538 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1653 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6547 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1664 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 6553 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1665 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LT; }
#line 6559 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1666 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 6565 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1667 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GT; }
#line 6571 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1668 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_EQ; }
#line 6577 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1669 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 6583 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1670 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 6589 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1671 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 6595 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1672 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 6601 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1673 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 6607 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1677 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 6613 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1678 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 6619 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1684 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.nodetype) = Node::comp_all_some_any_op_form((yyvsp[-1].nodetype), (yyvsp[0].ival));
}
#line 6627 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1690 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_ADD; }
#line 6633 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1691 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MINUS; }
#line 6639 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1695 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MUL; }
#line 6645 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1696 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_DIV; }
#line 6651 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1697 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_REM; }
#line 6657 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1698 "oracle.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MOD; }
#line 6663 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1709 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "DEFAULT"); }
#line 6669 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1710 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE " + (yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 6675 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1711 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING,  "TIMESTAMP " + (yyvsp[0].node)->text()); delete((yyvsp[0].node));  }
#line 6681 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1717 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_CASE);
}
#line 6690 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 256:
#line 1724 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6696 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 259:
#line 1731 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 6705 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1739 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6714 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1744 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6723 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1751 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6729 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1753 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
#line 6738 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1770 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6748 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1776 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6758 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 270:
#line 1782 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6768 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1788 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node),(yyvsp[-2].node), (yyvsp[-1].node), nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6778 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1794 "oracle.y" /* yacc.c:1646  */
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
#line 6794 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 273:
#line 1806 "oracle.y" /* yacc.c:1646  */
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
#line 6810 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1820 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
#line 6816 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 275:
#line 1821 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
#line 6822 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1822 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
#line 6828 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1823 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
#line 6834 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1824 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
#line 6840 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1825 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
#line 6846 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1826 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
#line 6852 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1827 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
#line 6858 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1828 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
#line 6864 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1829 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING"); }
#line 6870 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1830 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV"); }
#line 6876 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1835 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), nullptr, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6886 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1843 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
#line 6892 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1844 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
#line 6898 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1845 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
#line 6904 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1846 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
#line 6910 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1847 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
#line 6916 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1852 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node));
}
#line 6924 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1856 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
#line 6933 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1865 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 6939 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1874 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
#line 6948 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1881 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6954 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 298:
#line 1886 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6960 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 299:
#line 1888 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 6966 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 300:
#line 1892 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6972 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 301:
#line 1894 "oracle.y" /* yacc.c:1646  */
    {
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+s3);
    delete((yyvsp[-2].node)); delete((yyvsp[-1].node)); delete((yyvsp[0].node));
}
#line 6982 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1902 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
#line 6988 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1903 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
#line 6994 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 1912 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
#line 7000 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1913 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
#line 7006 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1918 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" PRECEDING"); delete((yyvsp[-1].node)); }
#line 7012 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 310:
#line 1923 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text()); delete((yyvsp[-2].node)); delete((yyvsp[0].node)); }
#line 7018 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 312:
#line 1928 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
#line 7024 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 314:
#line 1933 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" FOLLOWING"); delete((yyvsp[-1].node)); }
#line 7030 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 315:
#line 1937 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7036 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 316:
#line 1938 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
#line 7042 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 317:
#line 1939 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
#line 7048 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 1940 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
#line 7054 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 1941 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
#line 7060 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 320:
#line 1946 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7070 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 1952 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7080 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 322:
#line 1964 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7090 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 323:
#line 1970 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7101 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 1977 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7112 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 1984 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 7123 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 1991 "oracle.y" /* yacc.c:1646  */
    {
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-3].node), nullptr, nullptr, transcoding_name);
    (yyval.node)->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
#line 7136 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 327:
#line 2000 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7147 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 2007 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7158 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 2014 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7169 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 2021 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7180 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 2028 "oracle.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7193 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 2037 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7204 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 2044 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7215 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 2051 "oracle.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            fun_name, (yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_EXTRACT_SERIALIZE_FORMAT_ORA;
}
#line 7226 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 2071 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7235 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 2079 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7244 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 2084 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 7253 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 2089 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 7262 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 2094 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7271 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 2103 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REF("+(yyvsp[-3].node)->text()+")SCOPE "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 7280 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 2111 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" ARRAY("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-4].node));
    delete((yyvsp[-1].node));
}
#line 7290 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2117 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" ARRAY");
    delete((yyvsp[-1].node));
}
#line 7299 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2122 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" MULTISET");
    delete((yyvsp[-1].node));
}
#line 7308 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 348:
#line 2130 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" CHARACTER SET "+(yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-4].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7317 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 349:
#line 2135 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+" CHARACTER SET "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 7326 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2140 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7335 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2146 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7344 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2160 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTERVAL "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7353 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2168 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" TO "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[0].node));
}
#line 7362 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2177 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));
    delete((yyvsp[-1].node));
}
#line 7372 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2188 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7381 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2193 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 7389 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2200 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7398 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2206 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7407 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2211 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7416 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2216 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 7424 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2223 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "YEAR");
}
#line 7432 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2227 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MONTH");
}
#line 7440 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2231 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DAY");
}
#line 7448 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2235 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "HOUR");
}
#line 7456 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2239 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MINUTE");
}
#line 7464 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2243 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_HOUR");
}
#line 7472 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2247 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_MINUTE");
}
#line 7480 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2251 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_REGION");
}
#line 7488 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2255 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_ABBR");
}
#line 7496 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2262 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BOOLEAN");
}
#line 7504 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2269 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE");
}
#line 7512 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2273 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7521 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2278 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7530 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2283 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7539 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2288 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITH TIME ZONE");
}
#line 7547 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2292 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITHOUT TIME ZONE");
}
#line 7555 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2296 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7564 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2301 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7573 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2306 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7582 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2311 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITH TIME ZONE");
}
#line 7590 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2315 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITHOUT TIME ZONE");
}
#line 7598 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2319 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP");
}
#line 7606 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2331 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7615 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2336 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7624 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2341 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7633 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2346 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7642 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2351 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7651 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2356 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7660 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2361 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC");
}
#line 7668 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2365 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SMALLINT");
}
#line 7676 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2369 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTEGER");
}
#line 7684 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2373 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INT");
}
#line 7692 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2377 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BIGINT");
}
#line 7700 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2381 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC");
}
#line 7708 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2385 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL");
}
#line 7716 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2392 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7725 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2397 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DOUBLE PRECISION");
}
#line 7733 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2401 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT");
}
#line 7741 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2405 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REAL");
}
#line 7749 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2412 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7758 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2417 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7767 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2422 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7776 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 416:
#line 2427 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7785 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2432 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7794 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 418:
#line 2437 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7803 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 419:
#line 2442 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT");
}
#line 7811 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 420:
#line 2446 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7820 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 421:
#line 2451 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT");
}
#line 7828 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2455 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7837 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2460 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB");
}
#line 7845 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 424:
#line 2464 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR");
}
#line 7853 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 425:
#line 2468 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER");
}
#line 7861 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 426:
#line 2475 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7870 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2480 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT");
}
#line 7878 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2484 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7887 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2489 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB");
}
#line 7895 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2496 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7904 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2501 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER");
}
#line 7912 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2505 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7921 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2510 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR");
}
#line 7929 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2514 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7938 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 435:
#line 2519 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7947 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 436:
#line 2524 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7956 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 437:
#line 2529 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7965 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 438:
#line 2534 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7974 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 439:
#line 2539 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT");
}
#line 7982 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 440:
#line 2543 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7991 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 441:
#line 2548 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT");
}
#line 7999 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 442:
#line 2552 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8008 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 443:
#line 2557 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB");
}
#line 8016 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 444:
#line 2561 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR");
}
#line 8024 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 445:
#line 2568 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8033 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 446:
#line 2573 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8042 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 2578 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8051 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2583 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 8060 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 2591 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTERS");
}
#line 8068 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2595 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CODE_UNITS");
}
#line 8076 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2599 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "OCTETS");
}
#line 8084 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 2606 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "K");
}
#line 8092 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2610 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "M");
}
#line 8100 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 2614 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "G");
}
#line 8108 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2621 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 8116 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2625 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 8124 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2631 "oracle.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 8130 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2632 "oracle.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; }
#line 8136 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2633 "oracle.y" /* yacc.c:1646  */
    { (yyval.ival) = 2; }
#line 8142 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2637 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 8148 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2642 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 8154 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2653 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "COLLATE "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 8163 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2672 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INT"); }
#line 8169 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2673 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY"); }
#line 8175 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2674 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINARY"); }
#line 8181 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2675 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 8187 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2676 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME");  }
#line 8193 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2677 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTERS"); }
#line 8199 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2678 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NCHAR"); }
#line 8205 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2682 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INTERVAL"); }
#line 8211 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2684 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CLOB"); }
#line 8217 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2685 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BLOB"); }
#line 8223 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2686 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NCLOB"); }
#line 8229 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2687 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NUMERIC"); }
#line 8235 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2688 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTER"); }
#line 8241 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2689 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIGINT"); }
#line 8247 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2690 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DEC"); }
#line 8253 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2691 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NATIONAL"); }
#line 8259 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2692 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DOUBLE"); }
#line 8265 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2693 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARYING"); }
#line 8271 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2694 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REAL"); }
#line 8277 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2699 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
#line 8283 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2700 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
#line 8289 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2701 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
#line 8295 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2702 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CAST"); }
#line 8301 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2703 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
#line 8307 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2704 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
#line 8313 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2705 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FOLLOWING"); }
#line 8319 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2706 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
#line 8325 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2707 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
#line 8331 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2708 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
#line 8337 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2709 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
#line 8343 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2710 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
#line 8349 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2711 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECEDING"); }
#line 8355 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2712 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
#line 8361 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 2713 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RECURSIVE"); }
#line 8367 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2714 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
#line 8373 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2715 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
#line 8379 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2716 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
#line 8385 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2717 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SECOND"); }
#line 8391 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2718 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UNBOUNDED"); }
#line 8397 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2719 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 8403 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 2720 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
#line 8409 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 511:
#line 2721 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
#line 8415 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 512:
#line 2723 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OF"); }
#line 8421 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 2724 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
#line 8427 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 514:
#line 2725 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DESC"); }
#line 8433 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 515:
#line 2726 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
#line 8439 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 516:
#line 2727 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
#line 8445 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 517:
#line 2728 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
#line 8451 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 518:
#line 2729 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXCLUDE"); }
#line 8457 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 519:
#line 2730 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ASC"); }
#line 8463 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 520:
#line 2731 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }
#line 8469 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 521:
#line 2732 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }
#line 8475 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 522:
#line 2733 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
#line 8481 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 2734 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FIRST"); }
#line 8487 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 2735 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SAMPLE"); }
#line 8493 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 2736 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SESSION"); }
#line 8499 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 2737 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BEGIN"); }
#line 8505 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 2738 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DECLARE"); }
#line 8511 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 2757 "oracle.y" /* yacc.c:1646  */
    { (yyval.node)=NULL; }
#line 8517 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 2759 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
}
#line 8525 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 2766 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_UPDATE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &FOR_UPDATE_FORMAT_HANA;
}
#line 8534 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 2772 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8540 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 2774 "oracle.y" /* yacc.c:1646  */
    {
    Node * p_of = Node::makeTerminalNode(E_STRING, "OF");
    (yyval.node) = Node::makeNonTerminalNode(E_OF_COLUMS, 2, p_of, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8550 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 2783 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8559 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 2789 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8565 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 2790 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "SKIP LOCKED");}
#line 8571 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 2793 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8577 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 2794 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_NOWAIT, "NOWAIT");}
#line 8583 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 2796 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WAIT_INT, 1,  (yyvsp[0].node));
    (yyval.node)->serialize_format = &WAIT_TIME_FORMAT;
}
#line 8592 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 2803 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_FETCH, 2,  (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8601 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 550:
#line 2809 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ROW");}
#line 8607 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 551:
#line 2810 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ROWS");}
#line 8613 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 2813 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8619 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 557:
#line 2822 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8625 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 2824 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_ROW, 2,  (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_SERIALIZE_FORMAT;
}
#line 8634 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 2831 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FIRST");}
#line 8640 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 2832 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "NEXT");}
#line 8646 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 2835 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "ONLY");}
#line 8652 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 562:
#line 2836 "oracle.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH TIES");}
#line 8658 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 563:
#line 2839 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8664 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 564:
#line 2841 "oracle.y" /* yacc.c:1646  */
    {
    Node * name1 = nullptr;
    {
        std::string name = "FETCH "+(yyvsp[-3].node)->text();
        delete((yyvsp[-3].node));
        name1 = Node::makeTerminalNode(E_STRING, name);
    }
    Node * name2 = nullptr;
    {
        std::string name = (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text();
        delete((yyvsp[-1].node));
        delete((yyvsp[0].node));
        name2 = Node::makeTerminalNode(E_STRING, name);
    }
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_ROW, 3, name1, (yyvsp[-2].node), name2);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;

}
#line 8687 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 565:
#line 2860 "oracle.y" /* yacc.c:1646  */
    {
    Node * name1 = nullptr;
    {
        std::string name = "FETCH "+(yyvsp[-4].node)->text();
        delete((yyvsp[-4].node));
        name1 = Node::makeTerminalNode(E_STRING, name);
    }
    Node * name2 = nullptr;
    {
        std::string name =" PERCENT "+ (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text();
        delete((yyvsp[-1].node));
        delete((yyvsp[0].node));
        name2 = Node::makeTerminalNode(E_STRING, name);
    }
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_ROW, 3, name1, (yyvsp[-3].node), name2);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 8709 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 566:
#line 2880 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8715 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 568:
#line 2885 "oracle.y" /* yacc.c:1646  */
    {
    std::string name = "SEARCH DEPTH FIRST BY ";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EROA_SEARCH_CLAUSE, 5, prename, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEARCH_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8726 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 569:
#line 2892 "oracle.y" /* yacc.c:1646  */
    {
    std::string name = "SEARCH BREADTH FIRST BY ";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EROA_SEARCH_CLAUSE, 5, prename, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEARCH_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8737 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 570:
#line 2900 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8743 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 572:
#line 2906 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_CYCLE_CLAUSE, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CYCLE_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8752 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 573:
#line 2912 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8758 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 574:
#line 2913 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "NOCYCLE"); }
#line 8764 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 575:
#line 2914 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "NOCYCLE PRIOR"); }
#line 8770 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 576:
#line 2915 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = Node::makeTerminalNode(E_STRING, "PRIOR"); }
#line 8776 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 577:
#line 2919 "oracle.y" /* yacc.c:1646  */
    {
    std::string name = "CONNECT BY ";
    if((yyvsp[-1].node)){
        name += (yyvsp[-1].node)->text();
        delete((yyvsp[-1].node));
    }
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EORA_CONNECT_BY, 2, prename, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8791 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 578:
#line 2932 "oracle.y" /* yacc.c:1646  */
    {
    std::string name = "START WITH";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EORA_START_WITH, 2, prename, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8802 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 579:
#line 2941 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8811 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 580:
#line 2946 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8820 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 581:
#line 2951 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8829 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 582:
#line 2959 "oracle.y" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_STRING, "SAMPLE BLOCK");
    (yyval.node) = Node::makeNonTerminalNode(EORA_SAMPLE_CLAUSE, 3, name, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SAMPLE_CLAUSE_SERIALIZE_FORMAT;
}
#line 8839 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 583:
#line 2965 "oracle.y" /* yacc.c:1646  */
    {
    Node * name = Node::makeTerminalNode(E_STRING, "SAMPLE");
    (yyval.node) = Node::makeNonTerminalNode(EORA_SAMPLE_CLAUSE, 3, name, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SAMPLE_CLAUSE_SERIALIZE_FORMAT;
}
#line 8849 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 584:
#line 2973 "oracle.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8855 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 585:
#line 2975 "oracle.y" /* yacc.c:1646  */
    {
   (yyval.node) = Node::makeNonTerminalNode(EORA_SEED_VALUE, 1, (yyvsp[-1].node));
   (yyval.node)->serialize_format = &EORA_SEED_VALUE_SERIALIZE_FORMAT;
}
#line 8864 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;

  case 586:
#line 2983 "oracle.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 8873 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
    break;


#line 8877 "sqlparser_oracle_bison.cpp" /* yacc.c:1646  */
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
#line 2990 "oracle.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

