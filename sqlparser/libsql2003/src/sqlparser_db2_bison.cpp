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
#define YYSTYPE         DB2_STYPE
#define YYLTYPE         DB2_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         db2_parse
#define yylex           db2_lex
#define yyerror         db2_error
#define yydebug         db2_debug
#define yynerrs         db2_nerrs


/* Copy the first part of user declarations.  */
#line 1 "sql_db2.y" /* yacc.c:339  */

/**
 * This Grammar is designed for db2.
 * https://github.com/Raphael2017/SQL/blob/master/sql-2003-2.bnf
 * sqlparser.y
 * defines sqlparser_db2_bison.h
 * outputs sqlparser_db2_bison.cpp
 *
 * Bison Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "sqlparser_db2_bison.h"
#include "sqlparser_db2_flex.h"
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


#line 110 "sqlparser_db2_bison.cpp" /* yacc.c:339  */

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
   by #include "sqlparser_db2_bison.h".  */
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
#line 42 "sql_db2.y" /* yacc.c:355  */

// %code requires block

#include "node.h"

#line 154 "sqlparser_db2_bison.cpp" /* yacc.c:355  */

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
#line 85 "sql_db2.y" /* yacc.c:355  */

    struct Node* node;
    int    ival;
    NodeType nodetype;

#line 364 "sqlparser_db2_bison.cpp" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 394 "sqlparser_db2_bison.cpp" /* yacc.c:358  */

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
         || (defined DB2_LTYPE_IS_TRIVIAL && DB2_LTYPE_IS_TRIVIAL \
             && defined DB2_STYPE_IS_TRIVIAL && DB2_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  129
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  207
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  561
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  939

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   446

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   203,     2,     2,     2,   206,     2,     2,
      12,    13,   199,   201,   198,   202,    14,   205,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   195,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   200,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   196,   204,   197,     2,     2,     2,     2,
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
     188,   189,   190,   191,   192,   193,   194
};

#if DB2_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   237,   237,   247,   248,   256,   257,   258,   259,   263,
     268,   273,   278,   286,   287,   295,   300,   308,   309,   313,
     317,   321,   322,   323,   327,   335,   340,   345,   350,   355,
     364,   373,   390,   407,   408,   416,   425,   435,   440,   447,
     448,   475,   505,   506,   536,   537,   550,   557,   559,   561,
     564,   593,   594,   603,   611,   612,   620,   621,   629,   630,
     631,   641,   642,   646,   654,   655,   663,   672,   675,   679,
     686,   687,   697,   702,   710,   711,   720,   728,   729,   733,
     741,   742,   750,   751,   755,   762,   763,   771,   785,   794,
     795,   803,   804,   808,   809,   821,   826,   831,   840,   841,
     846,   852,   858,   865,   871,   878,   884,   892,   898,   963,
     968,   973,   978,   983,   988,   993,   998,  1006,  1011,  1016,
    1024,  1029,  1034,  1043,  1044,  1049,  1054,  1061,  1066,  1075,
    1100,  1111,  1122,  1133,  1140,  1141,  1146,  1147,  1155,  1156,
    1164,  1165,  1173,  1174,  1179,  1187,  1188,  1206,  1207,  1208,
    1209,  1210,  1212,  1216,  1221,  1229,  1234,  1242,  1247,  1252,
    1257,  1265,  1270,  1278,  1283,  1291,  1300,  1301,  1306,  1314,
    1315,  1323,  1324,  1332,  1333,  1341,  1342,  1347,  1355,  1356,
    1357,  1358,  1363,  1364,  1368,  1369,  1377,  1378,  1385,  1385,
    1389,  1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,
    1402,  1403,  1408,  1415,  1416,  1420,  1421,  1422,  1423,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1438,  1446,  1447,  1451,
    1452,  1460,  1465,  1473,  1474,  1483,  1484,  1485,  1486,  1491,
    1497,  1503,  1509,  1515,  1527,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1557,  1566,  1567,
    1568,  1569,  1570,  1574,  1578,  1587,  1592,  1596,  1604,  1605,
    1609,  1610,  1615,  1616,  1625,  1626,  1630,  1631,  1635,  1636,
    1637,  1641,  1645,  1650,  1651,  1652,  1656,  1660,  1661,  1662,
    1663,  1664,  1668,  1674,  1686,  1692,  1699,  1706,  1713,  1722,
    1729,  1736,  1743,  1750,  1759,  1766,  1773,  1781,  1794,  1795,
    1796,  1797,  1801,  1809,  1817,  1823,  1828,  1836,  1841,  1846,
    1851,  1852,  1857,  1858,  1859,  1860,  1861,  1862,  1866,  1874,
    1879,  1883,  1889,  1893,  1894,  1899,  1906,  1911,  1912,  1917,
    1922,  1929,  1933,  1937,  1941,  1945,  1952,  1959,  1963,  1968,
    1973,  1978,  1982,  1986,  1991,  1996,  2001,  2005,  2012,  2013,
    2017,  2022,  2027,  2032,  2037,  2042,  2047,  2051,  2055,  2059,
    2063,  2067,  2071,  2078,  2083,  2087,  2091,  2098,  2103,  2108,
    2113,  2118,  2123,  2128,  2133,  2137,  2142,  2146,  2151,  2155,
    2159,  2166,  2171,  2175,  2180,  2187,  2192,  2196,  2201,  2205,
    2210,  2215,  2220,  2225,  2230,  2234,  2239,  2243,  2248,  2252,
    2259,  2264,  2269,  2274,  2282,  2286,  2290,  2297,  2301,  2305,
    2312,  2316,  2323,  2324,  2325,  2329,  2330,  2334,  2335,  2339,
    2340,  2341,  2342,  2349,  2357,  2358,  2359,  2360,  2361,  2362,
    2363,  2364,  2365,  2366,  2367,  2370,  2371,  2372,  2373,  2374,
    2378,  2379,  2383,  2384,  2385,  2386,  2387,  2388,  2392,  2393,
    2394,  2395,  2396,  2397,  2398,  2399,  2400,  2401,  2402,  2403,
    2404,  2405,  2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,
    2414,  2415,  2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,
    2424,  2425,  2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2437,  2438,  2439,  2440,  2441,  2442,  2446,
    2447,  2448,  2449,  2450,  2451,  2452,  2453,  2454,  2455,  2456,
    2460,  2461,  2464,  2465,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2482,  2486,  2495,  2496,  2502,  2503,  2506,  2509,
    2522,  2523,  2524,  2525,  2527,  2528,  2529,  2530,  2531,  2532,
    2533,  2537,  2539,  2540,  2541,  2542,  2544,  2545,  2546,  2547,
    2550,  2551,  2554,  2560,  2561,  2570,  2571,  2578,  2579,  2586,
    2593,  2594
};
#endif

#if DB2_DEBUG || YYERROR_VERBOSE || 1
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
  "INSERT", "INT", "INTEGER", "INTERSECT", "INTERVAL", "INTO", "IS",
  "JOIN", "K", "LARGE", "LEFT", "LIKE", "M", "MAX", "MIN", "MINUTE", "MOD",
  "MONTH", "MULTISET", "NATIONAL", "NATURAL", "NCHAR", "NCLOB", "NO",
  "NOT", "NULLIF", "NUMERIC", "OBJECT", "OCTETS", "OF", "ON", "ONLY", "OR",
  "ORDER", "OTHERS", "OUTER", "OVER", "PARTITION", "PERCENT_RANK",
  "PRECEDING", "PRECISION", "RANGE", "RANK", "READ", "REAL", "RECURSIVE",
  "REF", "RIGHT", "ROW", "ROWS", "ROW_NUMBER", "SCOPE", "SECOND", "SELECT",
  "SESSION_USER", "SET", "SETS", "SMALLINT", "SOME", "STDDEV_POP",
  "STDDEV_SAMP", "SUM", "SYSTEM_USER", "THEN", "TIES", "TIME", "TIMESTAMP",
  "TO", "UNBOUNDED", "UNION", "UPDATE", "USING", "VALUES", "VARCHAR",
  "VARYING", "VAR_POP", "VAR_SAMP", "WHEN", "WHERE", "WITH", "WITHOUT",
  "YEAR", "ZONE", "SKIP", "LOCKED", "DATA", "CS", "UR", "RS", "RR",
  "QUERYNO", "FETCH", "FIRST", "OPTIMIZE", "LIMIT", "TABLE", "DEGREE",
  "SCHEMA", "TIMEZONE", "COUNT_BIG", "STDDEV", "USE", "KEEP", "EXCLUSIVE",
  "LOCKS", "CARDINALITY", "BIT", "MINUTES", "SHARE", "OUTCOME", "WAIT",
  "OFFSET", "';'", "'{'", "'}'", "','", "'*'", "'^'", "'+'", "'-'", "'!'",
  "'|'", "'/'", "'%'", "$accept", "sql_stmt", "stmt_list", "stmt",
  "call_stmt", "sql_argument_list", "sql_argument", "value_expression",
  "sp_name", "dql_stmt", "dml_stmt", "insert_stmt",
  "insert_columns_and_source", "from_constructor", "delete_stmt",
  "update_stmt", "update_elem_list", "update_elem", "select_stmt",
  "query_expression", "query_expression_body", "query_term",
  "query_primary", "select_with_parens", "subquery", "table_subquery",
  "row_subquery", "simple_table", "opt_where", "opt_from_clause",
  "opt_groupby", "grouping_element_list", "grouping_element",
  "opt_order_by", "order_by", "sort_list", "sort_key", "opt_asc_desc",
  "opt_having", "with_clause", "with_list", "common_table_expr",
  "opt_derived_column_list", "simple_ident_list_with_parens",
  "simple_ident_list", "opt_distinct", "select_expr_list", "projection",
  "from_list", "table_reference", "table_primary",
  "table_primary_non_join", "opt_simple_ident_list_with_parens",
  "column_ref", "relation_factor", "relation_factor_datatype",
  "relation_factor_fuction", "joined_table", "qualified_join",
  "cross_join", "join_type", "join_outer", "search_condition",
  "boolean_term", "boolean_factor", "boolean_test", "boolean_primary",
  "predicate", "comparison_predicate", "between_predicate",
  "like_predicate", "in_predicate", "null_predicate", "exists_predicate",
  "row_expr", "factor0", "factor1", "factor2", "factor3", "factor4",
  "row_expr_list", "in_expr", "truth_value", "comp_op", "cnn_op",
  "comp_all_some_any_op", "plus_minus_op", "star_div_percent_mod_op",
  "expr_const", "case_expr", "case_arg", "when_clause_list", "when_clause",
  "case_default", "func_expr", "aggregate_windowed_function",
  "aggregate_function_name", "ranking_windowed_function",
  "ranking_function_name", "over_clause", "window_specification",
  "window_name", "window_specification_details",
  "opt_existing_window_name", "opt_window_partition_clause",
  "opt_window_frame_clause", "window_frame_units", "window_frame_extent",
  "window_frame_start", "window_frame_preceding", "window_frame_between",
  "window_frame_bound", "window_frame_following",
  "opt_window_frame_exclusion", "scalar_function", "function_call_keyword",
  "data_type", "user_defined_type_name", "reference_type",
  "collection_type", "predefined_type", "interval_type",
  "interval_qualifier", "start_field", "end_field",
  "single_datetime_field", "non_second_primary_datetime_field",
  "boolean_type", "datetime_type", "numeric_type", "exact_numeric_type",
  "approximate_numeric_type", "character_string_type",
  "binary_large_object_string_type", "national_character_string_type",
  "large_object_length", "char_length_units", "multiplier",
  "distinct_or_all", "all_some_any", "opt_as_label", "as_label", "label",
  "collate_clause", "name_fuc", "name_type", "name_r", "reserved",
  "reserved_other", "reserved_type", "opt_db2_special_clause_list",
  "db2_special_clause_list", "db2_special_clause", "db2_for_clause",
  "for_update", "opt_of_simple_ident_list", "read_only", "skip_locked",
  "with_isolation", "isolation", "opt_db2_locks", "queryno_clause",
  "fetch_clause", "optimize_clause", "param_num", "limit_num",
  "offset_num", "opt_col_def_list_with_parens", "col_def_list", "col_def",
  "opt_cardinality", YY_NULLPTR
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
     442,   443,   444,   445,   446,    59,   123,   125,    44,    42,
      94,    43,    45,    33,   124,    47,    37
};
# endif

#define YYPACT_NINF -792

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-792)))

#define YYTABLE_NINF -510

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     106,    44,  6643,    47,    69,   284,  6643,  6834,    80,   168,
     178,    78,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   163,
     -11,   197,  -792,  -792,    77,   304,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,   213,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   308,
    -792,  -792,  -792,  -792,   294,  -792,  -792,  -792,  6643,  6643,
    -792,  -792,  3178,   185,  6643,  -792,   138,   321,  6643,  -792,
    -792,   106,   317,   295,  -792,   284,   284,   284,   -11,  -792,
    -792,  -792,  -792,  -792,  1778,  5879,   196,   125,   354,  -792,
    -792,  -792,  -792,  -792,  -792,  2578,   357,   359,  3578,   361,
     375,   384,   387,   391,   405,  -792,   410,  -792,   413,   419,
     421,  -792,  -792,   424,   438,   441,   458,   464,  -792,  3578,
    3578,  -792,  -792,  -792,   345,   187,  -792,   468,  1374,   200,
      89,   245,  -792,  -792,  -792,  -792,  -792,  -792,   472,  -792,
     474,  -792,  -792,   482,  -792,   484,   487,  3578,  -792,  6643,
    6643,   485,  -792,   494,  -792,  3578,    -3,   356,   340,   329,
     334,   437,   329,  -792,  -792,   295,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,    77,    77,    77,  1578,  -792,
     500,  2778,   502,   315,   498,   403,   505,  -792,  -792,   434,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,   679,  6070,   508,
    2778,   295,  5115,   374,  3578,  -792,   295,  -792,   103,  2578,
     517,     6,   518,    58,   376,  3578,  3578,  3578,  3578,   533,
     536,   528,  3578,   529,  -792,  -792,  5497,   196,  3178,  3378,
    -792,  -792,  5688,  -792,  -792,  6643,   341,  3578,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  3578,  -792,  -792,  -792,  -792,
    3578,  3578,  1978,   531,  3578,  3969,   196,   349,    37,  -792,
     538,   355,   500,  2178,  -792,   365,    32,   440,   443,   450,
    -792,  -792,  -792,  -792,   -15,   389,  -792,  -792,  -792,   329,
     329,   358,  -792,   197,   197,  -792,  1578,    66,   157,    44,
    -792,  -792,  -792,   679,  -792,  2778,  4733,  2778,  2778,   145,
    3578,  -792,  -792,   526,  -792,   301,  -792,   555,    41,  3578,
     303,   530,  2978,   500,  6643,   554,  6261,   403,  -792,  -792,
    -792,  -792,   295,  -792,   558,  -792,  3578,  -792,  2778,   513,
     376,    36,    45,   565,    49,   566,   567,  -792,    50,  -792,
    4924,   570,  5306,  -792,   229,  -792,  -792,  5306,  -792,  -792,
    -792,   506,  -792,  -792,   572,  -792,  -792,  -792,   200,    89,
     245,  -792,  -792,  -792,   574,    24,  3578,   469,    25,  -792,
     579,  -792,   578,   295,  3578,  3578,  -792,  6643,  -792,   397,
     583,  3578,  -792,  -792,  -792,  -792,  6643,  -792,  -792,   582,
     412,   527,  -792,  -792,   195,   281,   329,  -792,  -792,  -792,
     587,  -792,   510,   591,  -792,   135,    54,   592,   595,   593,
     594,   488,   598,   600,  -792,   251,   417,   124,   606,   610,
    -792,   611,  -792,    22,   107,   615,  -792,   616,   619,    93,
    -792,  -792,  -792,  -792,  -792,   621,  -792,  -792,  -792,  -792,
    -792,   278,  -792,   599,  -792,   622,   624,   505,  -792,  -792,
    -792,   149,  -792,    15,  -792,  -792,  -792,  2578,  -792,  -792,
    -792,   604,    43,  3578,   555,  3578,  -792,  -792,   620,  -792,
      58,  -792,  -792,  -792,  6643,  6643,   626,  -792,   290,  -792,
     -33,   667,  3578,   577,  -792,  4733,   629,  -792,  6643,  -792,
    -792,  3578,  4924,   407,   630,  3578,   321,   556,   532,  -792,
    5497,   532,   532,  5497,   557,  -792,   627,   569,  -792,   469,
     469,    26,  6452,  -792,  -792,  4160,  -792,  -792,    58,  -792,
    -792,   448,  -792,  -792,   466,  -792,   457,   539,   543,   544,
     547,  -792,   552,   658,   659,   559,   654,   665,   561,   660,
     668,   669,   670,  -792,   673,   672,  -792,   535,  -792,    65,
      57,   171,   674,   571,   675,   668,   677,  6643,   681,   540,
     542,   686,   545,   546,   687,   684,  -792,   562,  -792,  -792,
    7025,  -792,  3578,   691,  -792,  3578,    16,  -792,    63,  -792,
    -792,  6643,  3578,  3578,    58,  -792,    73,  -792,   699,    30,
    -792,    62,  -792,  -792,  5497,  -792,  -792,   372,   549,  -792,
    -792,  -792,  5497,   284,  2778,  -792,  -792,  -792,   469,  6643,
    -792,  -792,  -792,  -792,  -792,   666,  -792,   162,  -792,  -792,
    -792,  -792,  -792,   685,   700,   702,   712,   720,   713,   715,
     723,   313,   716,    20,    33,   718,   728,   311,   729,   730,
     726,   734,   631,   732,   727,   733,   744,   737,    34,   739,
     742,   597,   601,   745,   605,   607,   752,   764,  6643,  -792,
     743,    58,  -792,    58,  3578,  3578,  -792,    58,    58,  -792,
    -792,  -792,   329,   763,  -792,  2778,   321,   426,   623,  3778,
     403,  -792,  -792,   765,   663,  4351,   602,   603,   609,   775,
    -792,  -792,   668,   772,  -792,   668,   774,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,   241,  -792,  -792,   783,  -792,   787,
    -792,    35,   781,  -792,  -792,   784,   785,   795,   788,   790,
     798,  -792,   668,   791,  -792,  -792,   800,   676,   296,  -792,
    -792,   316,  -792,  -792,   735,   793,   599,  7199,    58,    58,
    -792,  5306,   403,  -792,  2778,   321,  2378,   678,  -792,   625,
      58,  -792,   780,   163,  -792,   802,   628,  -792,  -792,   796,
     801,  -792,   805,  -792,  -792,   806,   807,  -792,   817,   819,
     680,  -792,   812,  -792,   668,   813,   816,  -792,   818,  6643,
     692,   693,   694,   695,   643,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,   821,   403,  -792,  -792,   823,  3778,  3578,
     -22,  4542,   766,  -792,  -792,  -792,  -792,  -792,   825,   831,
    -792,   833,  -792,  -792,  -792,  -792,   682,   689,   696,   697,
     688,  2778,  -792,  3778,  -792,  -792,  -792,  -792,  -792,   373,
    -792,  -792,   698,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  4733,   837,   657,   839,   433,   736,   746,   747,   789,
    -792,  -792,  -792,  -792,    93,  -792,  2778,  -792,    40,   199,
    -792,   841,  -792,  -792,  -792,  -792,   235,  -792,  -792,  -792,
    -792,   433,   741,  -792,   749,  -792,  -792,  -792,  -792
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     0,     0,     0,    82,     0,     0,     0,     0,
       0,     3,     8,     6,     7,    23,    22,    21,    20,    61,
      37,    39,    42,    44,     0,     0,   440,   447,   500,   478,
     235,   501,   451,   499,   502,   479,   452,   480,   453,   243,
     251,     0,   508,   333,   249,   473,   477,   454,   450,   244,
     334,   509,   455,   448,   456,   449,   236,   237,   335,   332,
     457,   481,   458,   459,   471,   460,   476,   250,   461,   462,
     248,   472,   463,   464,   465,   252,   466,   467,   475,   239,
     240,   238,   474,   505,   504,   468,   503,   241,   242,   469,
     331,   470,   488,   489,   486,   487,   506,   245,   246,   490,
     491,   492,   493,   494,   507,   495,   496,   498,   497,     0,
      19,   443,   444,   445,   109,   441,   446,   442,     0,     0,
      83,    84,     0,     0,   463,    72,    74,    77,     0,     1,
       2,     5,     0,   510,    62,    82,    82,    82,    38,    45,
     482,   483,   484,   485,     0,     0,    51,     0,   440,   209,
     212,   210,   213,   211,   214,     0,   500,   501,   217,   451,
     499,   502,   479,   480,   290,   292,   508,   215,     0,   481,
       0,   294,   295,   505,   504,   503,   506,   507,    88,     0,
       0,    47,    49,   180,     0,    85,   178,     0,   415,   166,
     169,   171,   173,   175,   179,   182,   183,   228,   443,   227,
     444,   226,   225,   445,   120,   100,   446,     0,    73,     0,
       0,     0,    78,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,    36,   511,   512,   514,   522,   520,   515,
     516,   517,   518,   519,   521,     0,     0,     0,     0,    10,
       0,     0,     0,    13,    15,    17,   136,   138,   140,   142,
     145,   147,   148,   150,   149,   151,   152,    18,     0,   110,
       0,   510,     0,     0,     0,    24,   510,    25,     0,     0,
       0,   184,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,     0,    51,     0,     0,
     419,   421,     0,   422,   200,     0,     0,     0,    87,   416,
     418,   167,   420,   203,   204,     0,   208,   205,   206,   207,
       0,     0,     0,     0,     0,     0,    51,    33,     0,    75,
       0,    80,     0,     0,    63,    64,    67,     0,   524,     0,
     530,   531,   532,   533,   534,     0,   550,   551,   541,     0,
       0,   553,   513,    41,    40,    43,     0,     0,   184,     0,
      48,   165,   141,     0,     9,     0,     0,     0,     0,     0,
       0,   194,   192,   193,   190,   191,   195,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,    52,    31,    29,
      30,    28,   510,    26,     0,    46,     0,   181,     0,   223,
     219,     0,     0,     0,     0,     0,     0,   286,     0,   285,
       0,     0,   415,    53,    89,    91,    93,   415,    92,   123,
     124,    54,    86,   282,     0,   417,   423,   201,   168,   170,
     172,   174,   410,   411,     0,     0,     0,     0,     0,   102,
     445,   121,   101,   510,     0,     0,    79,     0,    76,     0,
       0,     0,    68,    69,    66,   526,     0,   523,   527,     0,
       0,     0,   529,   528,     0,     0,     0,   552,   146,    14,
     435,   360,   501,   384,   336,   379,   380,   378,   337,   356,
     362,     0,   365,   359,   358,   455,     0,   399,   398,   361,
     366,   464,   357,   505,   504,   503,   302,   436,   437,    16,
     299,   300,   301,   298,   317,   438,   315,   316,   314,   348,
     349,   310,   313,   312,   117,     0,   439,   137,   139,   188,
     189,     0,   143,     0,   196,   197,   198,     0,   186,   161,
     163,     0,   157,     0,     0,     0,   199,   412,   447,   413,
     153,   202,   154,   116,     0,     0,   111,    27,    46,   185,
       0,     0,     0,     0,   220,     0,     0,   289,     0,   291,
     297,     0,     0,     0,    92,     0,    98,     0,   134,   133,
       0,   134,   134,     0,     0,    95,     0,    70,   283,   234,
     230,     0,     0,   247,   284,     0,    32,    34,    35,    81,
      12,     0,    65,   525,     0,   538,     0,   545,   544,   549,
     548,   554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   364,     0,   330,   318,     0,   320,   327,
     388,   386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   305,   306,     0,   309,   311,
       0,   144,     0,     0,   164,     0,     0,   162,   159,   114,
     115,     0,     0,     0,   224,   216,     0,   296,     0,     0,
      94,   560,    99,    96,     0,   135,   130,     0,    91,   131,
     132,    90,     0,    82,     0,    50,   233,   229,   232,   258,
     254,   253,   256,   104,   122,   103,    11,     0,   539,   543,
     542,   547,   546,   382,     0,     0,   376,     0,     0,   374,
       0,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   396,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
       0,   155,   187,   158,     0,     0,   113,   221,   222,   287,
     288,   293,     0,     0,   129,     0,     0,     0,    91,     0,
      71,   231,   259,     0,   260,     0,     0,     0,     0,     0,
     383,   368,     0,     0,   367,     0,     0,   404,   405,   409,
     407,   408,   406,   402,   401,   377,   355,     0,   353,     0,
     363,     0,   325,   319,   323,     0,     0,     0,     0,   394,
       0,   389,     0,     0,   397,   351,     0,     0,   340,   341,
     342,   345,   346,   347,   371,     0,   308,     0,   156,   160,
     561,   415,   126,   128,     0,     0,     0,   244,    55,    56,
      59,   255,     0,    61,   106,   105,   536,   535,   537,     0,
       0,   370,     0,   369,   400,     0,     0,   329,     0,     0,
     326,   387,     0,   385,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,   304,   307,   435,   436,   437,
     438,   119,   439,   555,   125,   127,    58,     0,     0,     0,
     262,     0,     0,   381,   375,   373,   354,   352,     0,     0,
     391,     0,   390,   395,   350,   303,     0,     0,     0,     0,
       0,     0,    97,     0,    57,   261,   265,   264,   257,     0,
     108,   107,     0,   328,   324,   393,   338,   339,   343,   344,
     372,     0,     0,   557,     0,     0,     0,     0,     0,   277,
     266,   270,   267,   540,   559,   556,     0,    60,     0,     0,
     273,     0,   275,   269,   268,   271,     0,   263,   558,   274,
     276,     0,     0,   279,     0,   280,   272,   278,   281
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -792,  -792,   748,  -792,  -792,  -220,  -792,  -791,   750,  -792,
    -792,  -792,  -792,   596,  -792,  -792,   451,  -792,    29,  -792,
     850,   252,   640,  -792,  -228,  -223,  -792,  -792,   -30,  -792,
    -792,  -706,  -792,    71,  -792,   445,  -792,  -792,  -792,  -792,
      -4,  -792,  -792,  -146,  -342,  -128,   612,  -792,   324,  -387,
    -487,  -792,  -792,  -792,    12,  -792,  -792,  -365,  -792,  -792,
    -792,   -69,  -232,   537,  -205,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,   690,   613,   588,   585,   -74,  -792,
    -262,   368,   390,  -792,  -792,  -792,  -792,  -792,  -575,  -792,
    -792,   512,  -792,  -792,  -792,  -792,    14,  -792,   219,  -379,
    -792,   234,  -792,  -792,  -792,  -792,  -792,  -792,     9,  -792,
    -792,   -25,  -792,  -792,  -792,  -792,  -534,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,    -2,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -589,   143,  -792,  -792,  -792,
    -383,  -792,   617,  -478,  -293,  -588,   618,  -185,   489,  -792,
    -221,   683,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -212,  -792,  -792,  -792,    -5,  -792,
    -792
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,   242,   243,   244,   109,    13,
      14,    15,   265,   266,    16,    17,   316,   317,   270,    19,
      20,    21,    22,   181,   182,   402,   183,    23,   261,   287,
     567,   808,   809,   133,   134,   324,   325,   444,   665,    24,
     125,   126,   211,   212,   320,   122,   184,   185,   403,   404,
     405,   406,   653,   186,   407,   486,   187,   408,   409,   410,
     564,   656,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   271,   189,   190,   191,   192,   193,
     272,   519,   512,   372,   297,   373,   305,   310,   194,   195,
     274,   389,   390,   543,   196,   197,   198,   199,   200,   573,
     670,   671,   743,   744,   813,   888,   889,   909,   920,   911,
     912,   921,   922,   927,   201,   202,   489,   490,   491,   492,
     493,   494,   606,   607,   773,   608,   203,   496,   497,   498,
     499,   500,   501,   502,   503,   692,   763,   764,   426,   531,
     298,   299,   300,   301,   204,   504,   205,   115,   206,   117,
     223,   224,   225,   226,   227,   447,   228,   229,   230,   334,
     452,   231,   232,   233,   338,   234,   457,   882,   902,   903,
     733
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     113,   268,   380,   302,   113,   113,   347,   235,   236,   237,
     341,   646,   350,   553,   110,   393,   111,   351,   123,   556,
     111,   111,   431,   628,   565,   629,   707,   414,   377,    18,
      25,   632,   724,   766,   618,   554,   352,   570,   574,   668,
     378,   294,   719,   731,   295,   381,   768,   785,   827,   520,
     294,   294,   442,   295,   295,   545,     1,   135,   350,   294,
     294,   294,   295,   295,   295,   294,   597,   294,   295,   699,
     295,   294,   294,   658,   295,   295,   435,   698,   294,   458,
     294,   295,   357,   295,   294,   294,   729,   295,   295,     1,
     901,   625,   443,   294,   350,   579,   295,   294,   294,   438,
     295,   295,   886,   440,   583,   284,   285,   302,   128,   635,
     887,   625,   929,   642,   347,     1,   113,   113,     1,   621,
     208,   118,   113,   327,   539,   901,   113,   454,   455,   725,
     146,   147,   111,   111,     2,   459,   612,   262,   111,   350,
     110,   136,   111,   113,   518,   532,   598,   594,   521,  -499,
     328,   509,   884,   508,   510,   509,   540,   119,   510,   111,
      18,   537,   924,   820,     3,   553,   822,   734,   129,   449,
     450,   329,   350,   657,   626,   738,   267,   904,   451,   360,
       5,   357,   263,   701,   619,   620,   113,   554,   306,     4,
     666,   667,   294,   836,   626,   295,   361,   362,   363,   364,
     365,   366,   111,   548,   386,   319,     7,   113,   113,   851,
     296,   599,   576,     5,   700,  -322,   613,   302,   767,   296,
     296,   112,   302,   111,   111,   112,   112,   595,   296,   296,
     296,   769,   786,   828,   296,   546,   296,   421,   367,     5,
     296,   296,     5,   130,   591,   871,   368,   296,   551,   296,
     732,   369,   511,   296,   296,   633,   113,   411,   264,     6,
     113,     5,   296,   702,   370,     7,   296,   296,     7,   622,
     623,   930,   111,   131,   757,   737,   111,   557,   758,   132,
     264,   614,   674,   137,   113,   932,   433,     7,   307,   741,
     113,    25,   596,   113,   308,   309,   350,   383,   384,   120,
     111,   518,     8,   -45,   558,    43,   111,   416,   145,   111,
     627,   559,   933,   430,   908,   746,   295,   139,   846,   560,
     144,   925,   561,   207,   350,   523,   587,   588,   703,   111,
     919,    50,   350,   210,   336,   350,   209,   112,   112,   337,
     515,   934,   516,   112,   215,   121,   757,   112,   747,    58,
     758,    59,   762,   748,   495,   386,   919,   260,   -45,   562,
     371,   296,   140,   -45,   112,    43,  -424,   914,   216,  -427,
     487,  -428,   113,   275,   113,   384,   -45,   149,   150,   151,
     152,   153,   935,   154,   524,   288,   605,   276,   111,   759,
     111,    50,   141,   142,   143,   905,  -429,   525,   113,   277,
     113,   303,   304,   278,   760,   113,   -45,   112,   761,    58,
     652,    59,   589,   590,   111,    90,   111,   279,   853,   286,
     557,   111,   280,   906,   762,   281,   350,   563,   112,   112,
     167,   282,   740,   283,   350,   113,  -432,   149,   150,   151,
     152,   153,   -45,   154,   113,   311,   772,   558,   610,   611,
    -431,   111,   -45,  -430,   559,   557,   -45,   217,   840,   841,
     111,   218,   560,   -45,   -45,   561,   -45,   -45,   219,   220,
    -433,   221,   222,   609,   557,    90,  -434,   112,   842,   843,
     289,   112,   558,   906,   312,   735,   313,   343,   344,   559,
     167,   116,   659,   660,   314,   116,   116,   560,   315,  -425,
     561,   558,   562,   802,   322,   112,   323,   335,   559,   339,
     340,   112,   349,   355,   112,   354,   560,   356,   357,   561,
     800,   358,   376,   359,   907,   330,   331,   332,   333,   379,
     385,   387,   113,   113,   112,   739,   388,   562,   395,   804,
     396,   397,   399,   495,   427,   417,   113,   434,   111,   111,
     113,   436,   456,   437,   445,   446,   562,   453,   113,   487,
     648,   113,   111,   441,   448,   514,   111,   517,   534,   526,
     113,   538,   854,   430,   111,   488,   542,   111,   547,   549,
     550,   384,   555,   566,   918,   568,   111,   569,   572,   111,
     803,  -426,   575,   112,   580,   112,   581,   885,   584,   585,
     586,  -440,   592,   593,   600,   601,   602,   116,   116,  -508,
     604,   603,   634,   116,  -509,   113,   302,   116,   615,   112,
     114,   112,   616,   617,   114,   127,   112,   624,   495,   709,
    -443,   111,  -414,  -444,   116,  -445,   630,   295,  -446,   113,
     641,   645,   647,   650,   487,   676,   654,   662,   664,   678,
     655,   677,   113,   679,   663,   111,   112,   680,   681,   855,
     113,   682,   683,   684,   685,   112,   687,   113,   111,   686,
     688,   689,   690,   691,   693,   694,   111,   116,   695,   704,
     745,   705,   708,   111,   696,   697,   710,   706,   711,   360,
     712,   713,   716,   714,   715,   774,   717,   749,   116,   116,
     718,   360,   294,   736,   722,   295,   361,   362,   363,   364,
     365,   366,   730,   750,   294,   751,   113,   295,   361,   362,
     363,   364,   365,   366,   752,   753,   754,   755,   756,   765,
     796,   770,   111,   771,   775,   776,   114,   114,   777,   778,
     781,   779,   127,   113,   780,   782,   114,   116,   367,   783,
     784,   116,   787,   112,   112,   788,   368,   797,   791,   111,
     367,   369,   789,   259,   488,   794,   790,   112,   368,   795,
     792,   112,   793,   369,   370,   116,   801,   805,   811,   112,
     819,   116,   112,   812,   116,   821,   370,   823,   825,   816,
     817,   112,   826,   829,   112,   850,   818,   830,   831,   113,
     832,   833,   834,   835,   837,   838,   845,   859,   844,   863,
     839,   848,   188,   643,   864,   111,   861,   857,   865,   866,
     867,   862,   868,   858,   869,   870,   872,   127,   321,   873,
    -321,   874,   880,   881,   257,   883,   112,   113,   893,   892,
     876,   877,   878,   879,   894,   506,   895,   896,   273,   488,
     915,   875,   917,   111,   897,   916,   900,   931,   926,   113,
     112,   898,   899,   116,   382,   116,   938,   923,   924,   925,
     371,   296,   937,   112,   138,   111,   375,   345,   213,   214,
     321,   112,   371,   296,   860,   577,   582,   661,   112,   116,
     913,   116,   637,   419,   507,   420,   116,   318,   910,   495,
     412,   631,   544,   742,   114,   326,   936,   824,   342,   415,
     418,   928,     0,   114,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,   348,     0,
       0,   353,     0,   432,     0,   116,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   391,   392,     0,   394,     0,
       0,     0,   398,     0,   505,     0,     0,     0,   188,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533,     0,   536,     0,     0,     0,     0,     0,
       0,     0,   425,     0,   428,     0,     0,     0,     0,     0,
       0,     0,     0,   257,     0,     0,   849,     0,   114,     0,
     112,     0,     0,   116,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,   348,   116,     0,     0,
       0,   116,     0,     0,     0,   257,     0,   353,   353,   116,
     513,     0,   116,     0,     0,   321,     0,     0,   112,   522,
       0,   116,   530,     0,   321,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   541,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   571,     0,     0,   506,
     488,     0,     0,     0,   318,   578,     0,     0,     0,     0,
     116,   326,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,   116,   639,   640,     0,     0,     0,     0,   116,     0,
       0,     0,     0,   505,     0,     0,   114,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   114,     0,
       0,   114,     0,     0,     0,     0,     0,     0,     0,     0,
     672,     0,     0,   675,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,     0,     0,   636,     0,   638,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   644,     0,   116,   114,     0,     0,     0,     0,
       0,   649,     0,     0,     0,   651,     0,     0,   720,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   726,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   114,     0,     0,     0,     0,     0,     0,     0,
     114,     0,     0,     0,     0,     0,   852,   672,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   721,     0,     0,   723,     0,     0,   116,     0,
       0,     0,   727,   728,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   353,     0,     0,     0,     0,     0,
       0,     0,     0,   815,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   290,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,    27,    28,   292,    29,    30,     0,     0,    31,     0,
       0,     0,     0,   293,    32,    33,     0,    34,     0,   294,
      35,    36,   295,     0,   798,   799,     0,     0,     0,    37,
      38,    39,     0,    40,    41,   353,     0,    42,    43,   810,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,    49,     0,    50,     0,     0,   114,    51,     0,
       0,    52,     0,     0,     0,    53,    54,     0,     0,    55,
      56,    57,    58,     0,    59,    60,     0,     0,     0,   891,
       0,     0,    61,     0,    62,    63,    64,     0,    65,     0,
       0,    66,     0,     0,   353,    67,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,     0,    75,    76,    77,
       0,     0,     0,    78,     0,     0,    79,    80,    81,   505,
       0,    82,    83,    84,     0,    85,     0,     0,     0,     0,
      86,     0,    87,    88,     0,     0,     0,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,   810,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   257,     0,   810,     0,     0,     0,     0,   296,     0,
       0,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     346,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,   257,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   240,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,   241,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     5,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       7,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     238,   239,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   240,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,   241,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,   422,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,   423,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,   424,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     238,   439,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   240,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,   241,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     269,   856,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     5,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       7,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     269,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     5,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       7,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     238,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   240,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,   241,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,   527,     0,   528,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,   529,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,   178,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,   413,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     155,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,   179,
     180,   148,   149,   150,   151,   152,   153,     0,   154,     0,
     806,     0,     0,     0,     0,    27,   156,     0,    29,    30,
       0,     0,   157,     0,     0,     0,     0,   158,   159,   160,
       0,   161,     0,     0,   162,    36,     0,     0,     0,     0,
       0,     0,     0,   163,    38,    39,     0,    40,    41,   164,
     165,   166,    43,     0,     0,   167,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,   807,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,   168,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,   169,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,   170,    74,
       0,    75,    76,    77,     0,   171,     0,    78,     0,     0,
      79,    80,    81,   172,     0,    82,   173,   174,     0,    85,
       0,     0,     0,     0,   175,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,   176,
      97,    98,    99,   100,   101,   102,   103,   177,   105,   106,
     107,   108,   148,     0,     0,     0,     0,     0,     0,   179,
     180,     0,     0,     0,     0,     0,    27,   156,     0,    29,
      30,     0,     0,   157,     0,     0,     0,     0,     0,    32,
      33,     0,   161,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,    40,    41,
       0,     0,    42,    43,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,    49,     0,    50,
       0,     0,     0,    51,     0,     0,    52,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,     0,    59,
      60,     0,     0,     0,     0,     0,     0,    61,     0,    62,
      63,    64,     0,    65,     0,     0,    66,     0,     0,     0,
      67,    68,    69,     0,    70,    71,     0,    72,    73,     0,
      74,     0,    75,    76,    77,     0,     0,     0,    78,     0,
       0,    79,    80,    81,     0,     0,    82,   173,   174,     0,
      85,     0,     0,     0,     0,   175,     0,    87,    88,     0,
       0,     0,    89,    90,    91,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
     176,    97,    98,    99,   100,   101,   102,   103,   177,   105,
     106,   107,   108,   148,     0,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     0,     0,     0,    27,   156,     0,
      29,    30,     0,     0,   157,     0,     0,     0,     0,     0,
      32,    33,     0,   161,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,     0,    40,
      41,     0,     0,    42,    43,     0,     0,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,    47,     0,     0,     0,    48,     0,    49,     0,
      50,     0,     0,     0,    51,     0,     0,    52,     0,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,     0,
      59,    60,     0,     0,     0,     0,     0,     0,    61,     0,
      62,    63,    64,     0,    65,     0,     0,    66,     0,     0,
       0,    67,    68,    69,     0,    70,    71,     0,    72,    73,
       0,    74,     0,    75,    76,    77,     0,     0,     0,    78,
       0,     0,    79,    80,    81,     0,     0,    82,   173,   174,
       0,    85,     0,     0,     0,     0,   175,     0,    87,    88,
       0,     0,     0,    89,    90,    91,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,   176,    97,    98,    99,   100,   101,   102,   103,   177,
     105,   106,   107,   108,    26,     0,     0,     0,     0,   673,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    28,
       0,    29,    30,     0,     0,    31,     0,     0,     0,     0,
       0,    32,    33,     0,    34,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,     0,
      40,    41,     0,     0,    42,    43,     0,     0,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,    47,     0,     0,     0,    48,     0,    49,
       0,    50,     0,     0,     0,    51,     0,     0,    52,     0,
       0,     0,    53,    54,     0,     0,    55,    56,    57,    58,
       0,    59,    60,     0,     0,     0,     0,     0,     0,    61,
       0,    62,    63,    64,     0,    65,     0,     0,    66,     0,
       0,     0,    67,    68,    69,     0,    70,    71,     0,    72,
      73,     0,    74,     0,    75,    76,    77,     0,     0,     0,
      78,     0,     0,    79,    80,    81,     0,     0,    82,    83,
      84,     0,    85,     0,     0,     0,     0,    86,     0,    87,
      88,     0,     0,     0,    89,    90,    91,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    26,     0,     0,     0,     0,
     814,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
       0,     0,    32,    33,     0,    34,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
       0,    40,    41,     0,     0,    42,    43,     0,     0,     0,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,    47,     0,     0,     0,    48,     0,
      49,     0,    50,     0,     0,     0,    51,     0,     0,    52,
       0,     0,     0,    53,    54,     0,     0,    55,    56,    57,
      58,     0,    59,    60,     0,     0,     0,     0,     0,     0,
      61,     0,    62,    63,    64,     0,    65,     0,     0,    66,
       0,     0,     0,    67,    68,    69,     0,    70,    71,     0,
      72,    73,     0,    74,     0,    75,    76,    77,     0,     0,
       0,    78,     0,     0,    79,    80,    81,     0,     0,    82,
      83,    84,     0,    85,     0,     0,     0,     0,    86,     0,
      87,    88,     0,     0,     0,    89,    90,    91,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   460,     0,     0,     0,
       0,   890,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    29,    30,     0,   461,   462,   463,   464,
       0,     0,     0,    32,   465,   466,    34,   467,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      39,     0,    40,    41,     0,     0,   468,    43,   469,   470,
       0,     0,    44,    45,     0,   471,     0,     0,     0,     0,
       0,     0,    46,     0,   472,    47,     0,     0,     0,    48,
       0,    49,     0,    50,     0,     0,     0,   473,   474,     0,
     475,     0,     0,     0,    53,    54,     0,     0,    55,    56,
      57,    58,     0,    59,    60,   476,     0,   477,   478,     0,
       0,    61,   479,    62,    63,    64,     0,    65,     0,     0,
      66,     0,     0,     0,    67,    68,    69,     0,    70,    71,
     480,    72,   481,     0,    74,     0,    75,    76,    77,     0,
       0,     0,    78,   482,     0,    79,    80,    81,     0,     0,
      82,   483,   484,     0,    85,     0,     0,     0,     0,   485,
       0,    87,    88,     0,     0,     0,    89,    90,    91,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    26,     0,     0,
       0,     0,     0,     0,     0,     0,   552,     0,     0,     0,
       0,    27,    28,     0,    29,    30,     0,     0,    31,     0,
       0,     0,     0,     0,    32,    33,     0,    34,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,     0,    40,    41,     0,     0,    42,    43,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,    49,     0,    50,     0,     0,     0,    51,     0,
       0,    52,     0,     0,     0,    53,    54,     0,     0,    55,
      56,    57,    58,     0,    59,    60,     0,     0,     0,     0,
       0,     0,    61,     0,    62,    63,    64,     0,    65,     0,
       0,    66,     0,     0,     0,    67,    68,    69,     0,    70,
      71,     0,    72,    73,     0,    74,     0,    75,    76,    77,
       5,     0,     0,    78,     0,     0,    79,    80,    81,     0,
       0,    82,    83,    84,     0,    85,     0,     0,     0,     0,
      86,     0,    87,    88,     0,     0,     7,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   401,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,    27,    28,     0,    29,    30,     0,     0,    31,
       0,     0,     0,     0,     0,    32,    33,     0,    34,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,     0,    40,    41,     0,     0,    42,    43,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,    47,     0,     0,
       0,    48,     0,    49,     0,    50,     0,     0,     0,    51,
       0,     0,    52,     0,     0,     0,    53,    54,     0,     0,
      55,    56,    57,    58,     0,    59,    60,     0,     0,     0,
       0,     0,     0,    61,     0,    62,    63,    64,     0,    65,
       0,     0,    66,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,    74,     0,    75,    76,
      77,     5,     0,     0,    78,     0,     0,    79,    80,    81,
       0,     0,    82,    83,    84,     0,    85,     0,     0,     0,
       0,    86,     0,    87,    88,     0,     0,     7,    89,    90,
      91,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   290,
     291,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,   292,    29,    30,     0,     0,
      31,     0,     0,     0,     0,   293,    32,    33,     0,    34,
       0,     0,    35,    36,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,     0,    40,    41,     0,     0,    42,
      43,     0,     0,     0,     0,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,    47,     0,
       0,     0,    48,     0,    49,     0,    50,     0,     0,     0,
      51,     0,     0,    52,     0,     0,     0,    53,    54,     0,
       0,    55,    56,    57,    58,     0,    59,    60,     0,     0,
       0,     0,     0,     0,    61,     0,    62,    63,    64,     0,
      65,     0,     0,    66,     0,     0,     0,    67,    68,    69,
       0,    70,    71,     0,    72,    73,     0,    74,     0,    75,
      76,    77,     0,     0,     0,    78,     0,     0,    79,    80,
      81,     0,     0,    82,    83,    84,     0,    85,     0,     0,
       0,     0,    86,     0,    87,    88,     0,     0,     0,    89,
      90,    91,     0,    92,    93,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      26,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,     0,    27,    28,     0,    29,    30,     0,
       0,    31,     0,     0,     0,     0,     0,    32,    33,     0,
      34,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,    37,    38,    39,     0,    40,    41,     0,     0,
      42,    43,     0,     0,     0,     0,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     0,    47,
       0,     0,     0,    48,     0,    49,     0,    50,     0,     0,
       0,    51,     0,     0,    52,     0,     0,     0,    53,    54,
       0,     0,    55,    56,    57,    58,     0,    59,    60,     0,
       0,     0,     0,     0,     0,    61,     0,    62,    63,    64,
       0,    65,     0,     0,    66,     0,     0,     0,    67,    68,
      69,     0,    70,    71,     0,    72,    73,     0,    74,     0,
      75,    76,    77,     0,     0,     0,    78,     0,     0,    79,
      80,    81,     0,     0,    82,    83,    84,     0,    85,     0,
       0,     0,     0,    86,     0,    87,    88,     0,     0,     0,
      89,    90,    91,     0,    92,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   401,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   290,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    28,     0,    29,    30,
       0,     0,    31,     0,     0,     0,     0,   293,    32,    33,
       0,    34,     0,     0,    35,    36,     0,     0,     0,     0,
       0,     0,     0,    37,    38,    39,     0,    40,    41,     0,
       0,    42,    43,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
      47,     0,     0,     0,    48,     0,    49,     0,    50,     0,
       0,     0,    51,     0,     0,    52,     0,     0,     0,    53,
      54,     0,     0,    55,    56,    57,    58,     0,    59,    60,
       0,     0,     0,     0,     0,     0,    61,     0,    62,    63,
      64,     0,    65,     0,     0,    66,     0,     0,     0,    67,
      68,    69,     0,    70,    71,     0,    72,    73,     0,    74,
       0,    75,    76,    77,     0,     0,     0,    78,     0,     0,
      79,    80,    81,     0,     0,    82,    83,    84,     0,    85,
       0,     0,     0,     0,    86,     0,    87,    88,     0,     0,
       0,    89,    90,    91,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,     0,     0,    27,    28,     0,    29,
      30,     0,     0,    31,     0,     0,     0,     0,     0,    32,
      33,     0,    34,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,    40,    41,
       0,     0,    42,    43,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,    49,     0,    50,
       0,     0,     0,    51,     0,     0,    52,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,     0,    59,
      60,     0,     0,     0,     0,     0,     0,    61,     0,    62,
      63,    64,     0,    65,     0,     0,    66,     0,     0,     0,
      67,    68,    69,     0,    70,    71,     0,    72,    73,     0,
      74,     0,    75,    76,    77,     0,     0,     0,    78,     0,
       0,    79,    80,    81,     0,     0,    82,    83,    84,     0,
      85,     0,     0,     0,     0,    86,     0,    87,    88,     0,
       0,     0,    89,    90,    91,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,    27,    28,     0,
      29,    30,     0,     0,    31,     0,     0,     0,     0,     0,
      32,    33,     0,    34,     0,     0,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,     0,    40,
      41,     0,     0,    42,    43,     0,     0,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,    47,     0,     0,     0,    48,     0,    49,     0,
      50,     0,     0,     0,    51,     0,     0,    52,     0,     0,
       0,    53,    54,     0,     0,    55,    56,    57,    58,     0,
      59,    60,     0,     0,     0,     0,     0,     0,    61,     0,
      62,    63,    64,     0,    65,     0,     0,    66,     0,     0,
       0,    67,    68,    69,     0,    70,    71,     0,    72,    73,
       0,    74,     0,    75,    76,    77,     0,     0,     0,    78,
       0,     0,    79,    80,    81,     0,     0,    82,    83,    84,
       0,    85,     0,     0,     0,     0,    86,     0,    87,    88,
       0,     0,     0,    89,    90,    91,     0,    92,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   535,     0,     0,    27,    28,
       0,    29,    30,     0,     0,    31,     0,     0,     0,     0,
       0,    32,    33,     0,    34,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     0,     0,    37,    38,    39,     0,
      40,    41,     0,     0,    42,    43,     0,     0,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
      46,     0,     0,    47,     0,     0,     0,    48,     0,    49,
       0,    50,     0,     0,     0,    51,     0,     0,    52,     0,
       0,     0,    53,    54,     0,     0,    55,    56,    57,    58,
       0,    59,    60,     0,     0,     0,     0,     0,     0,    61,
       0,    62,    63,    64,     0,    65,     0,     0,    66,     0,
       0,     0,    67,    68,    69,     0,    70,    71,     0,    72,
      73,     0,    74,     0,    75,    76,    77,     0,     0,     0,
      78,     0,     0,    79,    80,    81,     0,     0,    82,    83,
      84,     0,    85,     0,     0,     0,     0,    86,     0,    87,
      88,     0,     0,     0,    89,    90,    91,     0,    92,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    26,     0,     0,     0,     0,
       0,     0,     0,     0,   669,     0,     0,     0,     0,    27,
      28,     0,    29,    30,     0,     0,    31,     0,     0,     0,
       0,     0,    32,    33,     0,    34,     0,     0,    35,    36,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
       0,    40,    41,     0,     0,    42,    43,     0,     0,     0,
       0,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,    46,     0,     0,    47,     0,     0,     0,    48,     0,
      49,     0,    50,     0,     0,     0,    51,     0,     0,    52,
       0,     0,     0,    53,    54,     0,     0,    55,    56,    57,
      58,     0,    59,    60,     0,     0,     0,     0,     0,     0,
      61,     0,    62,    63,    64,     0,    65,     0,     0,    66,
       0,     0,     0,    67,    68,    69,     0,    70,    71,     0,
      72,    73,     0,    74,     0,    75,    76,    77,     0,     0,
       0,    78,     0,     0,    79,    80,    81,     0,     0,    82,
      83,    84,     0,    85,     0,     0,     0,     0,    86,     0,
      87,    88,     0,     0,     0,    89,    90,    91,     0,    92,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,    29,    30,     0,     0,    31,     0,     0,
       0,     0,     0,    32,    33,     0,    34,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,     0,    37,    38,
      39,     0,    40,    41,     0,     0,    42,    43,     0,     0,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,    47,     0,     0,     0,    48,
       0,    49,     0,    50,     0,     0,     0,    51,     0,     0,
      52,     0,     0,     0,    53,    54,     0,     0,    55,    56,
      57,    58,     0,    59,    60,     0,     0,     0,     0,     0,
       0,    61,     0,    62,    63,    64,     0,    65,     0,     0,
      66,     0,     0,     0,    67,    68,    69,     0,    70,    71,
       0,    72,    73,     0,    74,     0,    75,    76,    77,     0,
       0,     0,    78,     0,     0,    79,    80,    81,     0,     0,
      82,    83,    84,     0,    85,     0,     0,     0,     0,    86,
       0,    87,    88,     0,     0,     0,    89,    90,    91,     0,
      92,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,    29,    30,     0,     0,    31,     0,
       0,     0,     0,     0,    32,    33,     0,    34,     0,     0,
      35,    36,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,     0,    40,    41,     0,     0,    42,    43,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    47,     0,     0,     0,
      48,     0,    49,     0,    50,     0,     0,     0,    51,     0,
       0,    52,     0,     0,     0,    53,    54,     0,     0,    55,
      56,    57,    58,     0,    59,    60,     0,     0,     0,     0,
       0,     0,    61,     0,    62,    63,    64,     0,    65,     0,
       0,    66,     0,     0,     0,    67,    68,    69,     0,    70,
      71,     0,   124,    73,     0,    74,     0,    75,    76,    77,
       0,     0,     0,    78,     0,     0,    79,    80,    81,     0,
       0,    82,    83,    84,     0,    85,     0,     0,     0,     0,
      86,     0,    87,    88,     0,     0,     0,    89,    90,    91,
       0,    92,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   460,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    28,     0,    29,    30,     0,     0,    31,
       0,     0,     0,     0,     0,    32,    33,     0,    34,     0,
       0,    35,    36,     0,     0,     0,     0,     0,     0,     0,
      37,    38,    39,     0,    40,    41,     0,     0,    42,    43,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,    47,     0,     0,
       0,    48,     0,    49,     0,    50,     0,     0,     0,    51,
       0,     0,    52,     0,     0,     0,    53,    54,     0,     0,
      55,    56,    57,    58,     0,    59,    60,     0,     0,     0,
       0,     0,     0,    61,     0,    62,    63,    64,     0,    65,
       0,     0,    66,     0,     0,     0,    67,    68,    69,     0,
      70,    71,     0,    72,    73,     0,    74,     0,    75,    76,
      77,     0,     0,     0,    78,     0,     0,    79,    80,    81,
       0,     0,    82,    83,    84,     0,    85,     0,     0,     0,
       0,    86,     0,    87,    88,     0,     0,     0,    89,    90,
      91,     0,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,   847,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,    40,    41,
       0,     0,     0,    43,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,    47,     0,     0,     0,    48,     0,    49,     0,    50,
       0,     0,     0,     0,     0,     0,    52,     0,     0,     0,
      53,    54,     0,     0,    55,    56,    57,    58,     0,    59,
      60,     0,     0,     0,     0,     0,     0,    61,     0,    62,
      63,    64,     0,    65,     0,     0,    66,     0,     0,     0,
      67,    68,    69,     0,    70,    71,     0,    72,    73,     0,
      74,     0,    75,    76,    77,     0,     0,     0,    78,     0,
       0,    79,    80,    81,     0,     0,    82,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,    87,    88,     0,
       0,     0,    89,    90,    91,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
       0,    97,    98,    99,   100,   101,   102,   103,     0,   105,
     106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       2,   147,   264,   188,     6,     7,   238,   135,   136,   137,
     222,   545,   240,   400,     2,   277,     2,   240,     6,   402,
       6,     7,   315,   501,   407,   503,   615,   289,   260,     0,
       1,    16,    16,    13,    12,   400,   241,    13,    13,    13,
     261,    35,   630,    13,    38,   266,    13,    13,    13,     8,
      35,    35,    20,    38,    38,    19,    12,    68,   286,    35,
      35,    35,    38,    38,    38,    35,    12,    35,    38,    12,
      38,    35,    35,   560,    38,    38,    39,    12,    35,    13,
      35,    38,   115,    38,    35,    35,    13,    38,    38,    12,
     881,    18,    60,    35,   322,   437,    38,    35,    35,   322,
      38,    38,   124,   323,   446,   179,   180,   292,    28,    66,
     132,    18,    72,   146,   346,    12,   118,   119,    12,    12,
     124,    74,   124,   126,   386,   916,   128,   339,   340,    66,
     118,   119,   118,   119,    28,   355,    12,    12,   124,   367,
     128,   152,   128,   145,   367,   373,    92,    12,   107,    14,
     153,     6,   858,   358,     9,     6,   388,    88,     9,   145,
     131,   382,   122,   752,    58,   552,   755,   654,     0,   184,
     185,   174,   400,   560,   101,   662,   147,   883,   193,    22,
     136,   115,    57,    12,   162,   163,   188,   552,    99,    83,
     569,   570,    35,   782,   101,    38,    39,    40,    41,    42,
      43,    44,   188,   154,   198,   209,   162,   209,   210,   797,
     204,   157,   433,   136,   157,   150,    92,   402,   198,   204,
     204,     2,   407,   209,   210,     6,     7,    92,   204,   204,
     204,   198,   198,   198,   204,   190,   204,   311,    81,   136,
     204,   204,   136,    65,   456,   834,    89,   204,   198,   204,
     188,    94,   107,   204,   204,   517,   258,   287,   155,   153,
     262,   136,   204,    92,   107,   162,   204,   204,   162,   162,
     163,    72,   258,   195,    33,   662,   262,    48,    37,   116,
     155,   157,   575,    86,   286,    50,   316,   162,   199,   668,
     292,   262,   157,   295,   205,   206,   524,   268,   269,    15,
     286,   524,   196,    13,    75,    54,   292,   295,    14,   295,
      32,    82,    77,   315,   889,   153,    38,    13,   796,    90,
      12,   122,    93,   138,   552,    22,   131,   132,   157,   315,
     905,    80,   560,    12,     5,   563,   198,   118,   119,    10,
      39,   106,    41,   124,    27,    61,    33,   128,   186,    98,
      37,   100,   111,   191,   356,   198,   931,   161,    68,   130,
     203,   204,   149,    73,   145,    54,    12,   901,    73,    12,
     356,    12,   374,    12,   376,   346,    86,     4,     5,     6,
       7,     8,   147,    10,    81,   198,   135,    12,   374,    76,
     376,    80,   179,   180,   181,    22,    12,    94,   400,    12,
     402,   201,   202,    12,    91,   407,   116,   188,    95,    98,
     556,   100,   131,   132,   400,   164,   402,    12,   801,    74,
      48,   407,    12,    50,   111,    12,   654,   198,   209,   210,
      57,    12,   664,    12,   662,   437,    12,     4,     5,     6,
       7,     8,   152,    10,   446,   200,   135,    75,    31,    32,
      12,   437,   162,    12,    82,    48,   166,   162,   162,   163,
     446,   166,    90,   173,   174,    93,   176,   177,   173,   174,
      12,   176,   177,   475,    48,   164,    12,   258,   162,   163,
      12,   262,    75,    50,    12,   113,    12,   235,   236,    82,
      57,     2,   561,   562,    12,     6,     7,    90,    14,    12,
      93,    75,   130,   735,    19,   286,    12,   167,    82,   175,
      73,   292,    12,   198,   295,    13,    90,    19,   115,    93,
     732,    16,    14,    89,   151,   169,   170,   171,   172,   155,
      13,    13,   534,   535,   315,   663,   160,   130,     5,   113,
       4,    13,    13,   545,    13,   204,   548,   198,   534,   535,
     552,    13,   194,   198,   114,   112,   130,   168,   560,   545,
     548,   563,   548,   198,   114,    39,   552,    12,    14,    39,
     572,    13,   804,   575,   560,   356,    63,   563,    13,    13,
      13,   552,    12,    77,   151,    13,   572,    13,   119,   575,
     736,    12,    14,   374,   197,   376,    13,   859,    16,   187,
      73,    14,    92,    12,    12,    12,    12,   118,   119,    14,
      12,   123,     8,   124,    14,   617,   801,   128,    12,   400,
       2,   402,    12,    12,     6,     7,   407,    12,   630,   617,
      14,   617,    12,    14,   145,    14,    14,    38,    14,   641,
      14,    64,    13,    13,   630,   197,    90,    90,    79,   192,
     118,   185,   654,   114,    27,   641,   437,   114,   114,   805,
     662,   114,   110,     5,     5,   446,    12,   669,   654,   110,
       5,   110,    12,     5,     5,     5,   662,   188,     5,     5,
      14,   110,     5,   669,    12,   150,     5,    12,   148,    22,
     148,     5,     5,   148,   148,   697,    12,    12,   209,   210,
     138,    22,    35,   154,    13,    38,    39,    40,    41,    42,
      43,    44,    13,    13,    35,    13,   718,    38,    39,    40,
      41,    42,    43,    44,    12,     5,    13,    12,     5,    13,
     718,    13,   718,     5,     5,     5,   118,   119,    12,     5,
      13,   110,   124,   745,    12,    12,   128,   258,    81,     5,
      13,   262,    13,   534,   535,    13,    89,    14,    13,   745,
      81,    94,   165,   145,   545,    13,   165,   548,    89,     5,
     165,   552,   165,    94,   107,   286,    13,   154,    13,   560,
       5,   292,   563,   120,   295,    13,   107,    13,     5,   187,
     187,   572,     5,    12,   575,   797,   187,    13,    13,   801,
       5,    13,    12,     5,    13,     5,    13,    27,    73,    13,
     134,   797,   122,   146,    13,   801,    14,   139,    13,    13,
      13,   193,     5,   198,     5,    13,    13,   209,   210,    13,
     150,    13,   189,    12,   144,    12,   617,   839,    13,    73,
     148,   148,   148,   148,    13,   356,    13,   165,   158,   630,
      13,   839,    13,   839,   165,   198,   168,    16,    69,   861,
     641,   165,   165,   374,   268,   376,   117,   131,   122,   122,
     203,   204,   131,   654,    24,   861,   258,   237,   128,   131,
     262,   662,   203,   204,   813,   434,   441,   563,   669,   400,
     192,   402,   524,   305,   357,   310,   407,   207,   889,   901,
     288,   511,   390,   669,   286,   215,   931,   764,   225,   292,
     297,   916,    -1,   295,    -1,   901,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   437,    -1,   238,    -1,
      -1,   241,    -1,   315,    -1,   446,    -1,   718,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   745,   275,   276,    -1,   278,    -1,
      -1,    -1,   282,    -1,   356,    -1,    -1,    -1,   288,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   374,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   312,    -1,   314,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   323,    -1,    -1,   797,    -1,   400,    -1,
     801,    -1,    -1,   534,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,   346,   548,    -1,    -1,
      -1,   552,    -1,    -1,    -1,   355,    -1,   357,   358,   560,
     360,    -1,   563,    -1,    -1,   437,    -1,    -1,   839,   369,
      -1,   572,   372,    -1,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,
     861,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   617,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   426,    -1,    -1,   630,
     901,    -1,    -1,    -1,   434,   435,    -1,    -1,    -1,    -1,
     641,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   662,   534,   535,    -1,    -1,    -1,    -1,   669,    -1,
      -1,    -1,    -1,   545,    -1,    -1,   548,    -1,    -1,    -1,
     552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   560,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     572,    -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,    -1,    -1,
      -1,    -1,    -1,   523,    -1,   525,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   542,    -1,   745,   617,    -1,    -1,    -1,    -1,
      -1,   551,    -1,    -1,    -1,   555,    -1,    -1,   630,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   654,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     662,    -1,    -1,    -1,    -1,    -1,   797,   669,    -1,    -1,
     801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   632,    -1,    -1,   635,    -1,    -1,   839,    -1,
      -1,    -1,   642,   643,    -1,    -1,   718,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     861,    -1,    -1,    -1,   664,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   745,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     901,    17,    18,    19,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    35,
      36,    37,    38,    -1,   724,   725,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    50,   735,    -1,    53,    54,   739,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    80,    -1,    -1,   839,    84,    -1,
      -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,   861,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,    -1,
      -1,   117,    -1,    -1,   804,   121,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,    -1,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,    -1,   142,   143,   144,   901,
      -1,   147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   159,    -1,    -1,    -1,   163,   164,   165,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,   858,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
      -1,   881,    -1,   883,    -1,    -1,    -1,    -1,   204,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,   916,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,   136,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
     162,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,   107,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    15,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,   141,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    93,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,   130,   131,
      -1,   133,   134,   135,    -1,   137,    -1,   139,    -1,    -1,
     142,   143,   144,   145,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     3,    -1,    -1,    -1,    -1,    -1,    -1,   201,
     202,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      91,    92,    -1,    -1,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,   144,    -1,    -1,   147,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,
      -1,    -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     3,    -1,    -1,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    91,    92,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     110,   111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,   125,   126,    -1,   128,   129,
      -1,   131,    -1,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,   144,    -1,    -1,   147,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,
      -1,    -1,    -1,   163,   164,   165,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     3,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    96,    97,    98,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    -1,   114,    -1,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,    -1,   133,   134,   135,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,   144,    -1,    -1,   147,   148,
     149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     159,    -1,    -1,    -1,   163,   164,   165,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     3,    -1,    -1,    -1,    -1,
     199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    96,    97,
      98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,    -1,   114,    -1,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,    -1,
     128,   129,    -1,   131,    -1,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   142,   143,   144,    -1,    -1,   147,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   159,    -1,    -1,    -1,   163,   164,   165,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     3,    -1,    -1,    -1,
      -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    53,    54,    55,    56,
      -1,    -1,    59,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    -1,    -1,    -1,    84,    85,    -1,
      87,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,   104,   105,    -1,
      -1,   108,   109,   110,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,
     127,   128,   129,    -1,   131,    -1,   133,   134,   135,    -1,
      -1,    -1,   139,   140,    -1,   142,   143,   144,    -1,    -1,
     147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   159,    -1,    -1,    -1,   163,   164,   165,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,    -1,
      -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,    -1,   133,   134,   135,
     136,    -1,    -1,   139,    -1,    -1,   142,   143,   144,    -1,
      -1,   147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   159,    -1,    -1,   162,   163,   164,   165,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
      -1,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
     125,   126,    -1,   128,   129,    -1,   131,    -1,   133,   134,
     135,   136,    -1,    -1,   139,    -1,    -1,   142,   143,   144,
      -1,    -1,   147,   148,   149,    -1,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   159,    -1,    -1,   162,   163,   164,
     165,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     3,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    19,    20,    21,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    49,    50,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,
      -1,    -1,    76,    -1,    78,    -1,    80,    -1,    -1,    -1,
      84,    -1,    -1,    87,    -1,    -1,    -1,    91,    92,    -1,
      -1,    95,    96,    97,    98,    -1,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,
     114,    -1,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
      -1,   125,   126,    -1,   128,   129,    -1,   131,    -1,   133,
     134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,
     144,    -1,    -1,   147,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,    -1,   158,   159,    -1,    -1,    -1,   163,
     164,   165,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,
      -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,    -1,
      -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,    92,
      -1,    -1,    95,    96,    97,    98,    -1,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,   112,
      -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,   125,   126,    -1,   128,   129,    -1,   131,    -1,
     133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,   142,
     143,   144,    -1,    -1,   147,   148,   149,    -1,   151,    -1,
      -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,    -1,
     163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,     3,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    21,
      -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,    91,
      92,    -1,    -1,    95,    96,    97,    98,    -1,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,   111,
     112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,   121,
     122,   123,    -1,   125,   126,    -1,   128,   129,    -1,   131,
      -1,   133,   134,   135,    -1,    -1,    -1,   139,    -1,    -1,
     142,   143,   144,    -1,    -1,   147,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,    -1,
      -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,    20,
      21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,    -1,
      91,    92,    -1,    -1,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,   144,    -1,    -1,   147,   148,   149,    -1,
     151,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,    -1,
      -1,    -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,
      80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,    -1,
      -1,    91,    92,    -1,    -1,    95,    96,    97,    98,    -1,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
     110,   111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,   125,   126,    -1,   128,   129,
      -1,   131,    -1,   133,   134,   135,    -1,    -1,    -1,   139,
      -1,    -1,   142,   143,   144,    -1,    -1,   147,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,   159,
      -1,    -1,    -1,   163,   164,   165,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,
      -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,    78,
      -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    96,    97,    98,
      -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   110,   111,   112,    -1,   114,    -1,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,   125,   126,    -1,   128,
     129,    -1,   131,    -1,   133,   134,   135,    -1,    -1,    -1,
     139,    -1,    -1,   142,   143,   144,    -1,    -1,   147,   148,
     149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,   158,
     159,    -1,    -1,    -1,   163,   164,   165,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    76,    -1,
      78,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,    87,
      -1,    -1,    -1,    91,    92,    -1,    -1,    95,    96,    97,
      98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,   112,    -1,   114,    -1,    -1,   117,
      -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,    -1,
     128,   129,    -1,   131,    -1,   133,   134,   135,    -1,    -1,
      -1,   139,    -1,    -1,   142,   143,   144,    -1,    -1,   147,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,    -1,
     158,   159,    -1,    -1,    -1,   163,   164,   165,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,    76,
      -1,    78,    -1,    80,    -1,    -1,    -1,    84,    -1,    -1,
      87,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,    96,
      97,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,   110,   111,   112,    -1,   114,    -1,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,   125,   126,
      -1,   128,   129,    -1,   131,    -1,   133,   134,   135,    -1,
      -1,    -1,   139,    -1,    -1,   142,   143,   144,    -1,    -1,
     147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,
      -1,   158,   159,    -1,    -1,    -1,   163,   164,   165,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    21,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,    -1,
      76,    -1,    78,    -1,    80,    -1,    -1,    -1,    84,    -1,
      -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,    95,
      96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,    -1,
      -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,   125,
     126,    -1,   128,   129,    -1,   131,    -1,   133,   134,   135,
      -1,    -1,    -1,   139,    -1,    -1,   142,   143,   144,    -1,
      -1,   147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,    -1,   158,   159,    -1,    -1,    -1,   163,   164,   165,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    53,    54,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    78,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,
      95,    96,    97,    98,    -1,   100,   101,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    -1,   110,   111,   112,    -1,   114,
      -1,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
     125,   126,    -1,   128,   129,    -1,   131,    -1,   133,   134,
     135,    -1,    -1,    -1,   139,    -1,    -1,   142,   143,   144,
      -1,    -1,   147,   148,   149,    -1,   151,    -1,    -1,    -1,
      -1,   156,    -1,   158,   159,    -1,    -1,    -1,   163,   164,
     165,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      91,    92,    -1,    -1,    95,    96,    97,    98,    -1,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,   110,
     111,   112,    -1,   114,    -1,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,   126,    -1,   128,   129,    -1,
     131,    -1,   133,   134,   135,    -1,    -1,    -1,   139,    -1,
      -1,   142,   143,   144,    -1,    -1,   147,    -1,    -1,    -1,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   158,   159,    -1,
      -1,    -1,   163,   164,   165,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
      -1,   182,   183,   184,   185,   186,   187,   188,    -1,   190,
     191,   192,   193
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    28,    58,    83,   136,   153,   162,   196,   208,
     209,   210,   211,   216,   217,   218,   221,   222,   225,   226,
     227,   228,   229,   234,   246,   225,     3,    17,    18,    20,
      21,    24,    30,    31,    33,    36,    37,    45,    46,    47,
      49,    50,    53,    54,    59,    60,    69,    72,    76,    78,
      80,    84,    87,    91,    92,    95,    96,    97,    98,   100,
     101,   108,   110,   111,   112,   114,   117,   121,   122,   123,
     125,   126,   128,   129,   131,   133,   134,   135,   139,   142,
     143,   144,   147,   148,   149,   151,   156,   158,   159,   163,
     164,   165,   167,   168,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   215,
     261,   303,   305,   333,   353,   354,   355,   356,    74,    88,
      15,    61,   252,   261,   128,   247,   248,   353,    28,     0,
      65,   195,   116,   240,   241,    68,   152,    86,   227,    13,
     149,   179,   180,   181,    12,    14,   261,   261,     3,     4,
       5,     6,     7,     8,    10,    12,    18,    24,    29,    30,
      31,    33,    36,    45,    51,    52,    53,    57,    93,   108,
     130,   137,   145,   148,   149,   156,   181,   189,   199,   201,
     202,   230,   231,   233,   253,   254,   260,   263,   281,   282,
     283,   284,   285,   286,   295,   296,   301,   302,   303,   304,
     305,   321,   322,   333,   351,   353,   355,   138,   247,   198,
      12,   249,   250,   215,   209,    27,    73,   162,   166,   173,
     174,   176,   177,   357,   358,   359,   360,   361,   363,   364,
     365,   368,   369,   370,   372,   252,   252,   252,    12,    13,
      70,   107,   212,   213,   214,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,    14,   353,
     161,   235,    12,    57,   155,   219,   220,   225,   250,    12,
     225,   281,   287,   281,   297,    12,    12,    12,    12,    12,
      12,    12,    12,    12,   285,   285,    74,   236,   198,    12,
       3,     4,    19,    29,    35,    38,   204,   291,   347,   348,
     349,   350,   354,   201,   202,   293,    99,   199,   205,   206,
     294,   200,    12,    12,    12,    14,   223,   224,   281,   247,
     251,   353,    19,    12,   242,   243,   281,   126,   153,   174,
     169,   170,   171,   172,   366,   167,     5,    10,   371,   175,
      73,   371,   358,   228,   228,   229,    12,   269,   281,    12,
     231,   232,   271,   281,    13,   198,    19,   115,    16,    89,
      22,    39,    40,    41,    42,    43,    44,    81,    89,    94,
     107,   203,   290,   292,    14,   353,    14,   269,   357,   155,
     287,   357,   220,   225,   225,    13,   198,    13,   160,   298,
     299,   281,   281,   287,   281,     5,     4,    13,   281,    13,
      12,   178,   232,   255,   256,   257,   258,   261,   264,   265,
     266,   235,   253,    13,   287,   349,   261,   204,   282,   283,
     284,   285,    15,    61,   199,   281,   345,    13,   281,   199,
     333,   351,   353,   235,   198,    39,    13,   198,   232,    13,
     212,   198,    20,    60,   244,   114,   112,   362,   114,   184,
     185,   193,   367,   168,   371,   371,   194,   373,    13,   212,
       3,    23,    24,    25,    26,    31,    32,    34,    53,    55,
      56,    62,    71,    84,    85,    87,   102,   104,   105,   109,
     127,   129,   140,   148,   149,   156,   262,   303,   305,   323,
     324,   325,   326,   327,   328,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   352,   353,   355,   270,   271,     6,
       9,   107,   289,   281,    39,    39,    41,    12,   232,   288,
       8,   107,   281,    22,    81,    94,    39,    15,    17,   141,
     281,   346,   231,   353,    14,    14,   353,   357,    13,   287,
     269,   281,    63,   300,   298,    19,   190,    13,   154,    13,
      13,   198,    12,   256,   264,    12,   347,    48,    75,    82,
      90,    93,   130,   198,   267,   347,    77,   237,    13,    13,
      13,   281,   119,   306,    13,    14,   357,   223,   281,   251,
     197,    13,   242,   251,    16,   187,    73,   131,   132,   131,
     132,   371,    92,    12,    12,    92,   157,    12,    92,   157,
      12,    12,    12,   123,    12,   135,   329,   330,   332,   333,
      31,    32,    12,    92,   157,    12,    12,    12,    12,   162,
     163,    12,   162,   163,    12,    18,   101,    32,   350,   350,
      14,   289,    16,   287,     8,    66,   281,   288,   281,   353,
     353,    14,   146,   146,   281,    64,   323,    13,   261,   281,
      13,   281,   250,   259,    90,   118,   268,   256,   257,   268,
     268,   255,    90,    27,    79,   245,   306,   306,    13,    12,
     307,   308,   353,   199,   351,   353,   197,   185,   192,   114,
     114,   114,   114,   110,     5,     5,   110,    12,     5,   110,
      12,     5,   342,     5,     5,     5,    12,   150,    12,    12,
     157,    12,    92,   157,     5,   110,    12,   342,     5,   261,
       5,   148,   148,     5,   148,   148,     5,    12,   138,   352,
     353,   281,    13,   281,    16,    66,   353,   281,   281,    13,
      13,    13,   188,   377,   257,   113,   154,   256,   257,   252,
     269,   306,   308,   309,   310,    14,   153,   186,   191,    12,
      13,    13,    12,     5,    13,    12,     5,    33,    37,    76,
      91,    95,   111,   343,   344,    13,    13,   198,    13,   198,
      13,     5,   135,   331,   333,     5,     5,    12,     5,   110,
      12,    13,    12,     5,    13,    13,   198,    13,    13,   165,
     165,    13,   165,   165,    13,     5,   261,    14,   281,   281,
     371,    13,   269,   250,   113,   154,    12,    78,   238,   239,
     281,    13,   120,   311,   199,   353,   187,   187,   187,     5,
     342,    13,   342,    13,   343,     5,     5,    13,   198,    12,
      13,    13,     5,    13,    12,     5,   342,    13,     5,   134,
     162,   163,   162,   163,    73,    13,   350,     3,   303,   305,
     333,   352,   355,   347,   269,   250,    13,   139,   198,    27,
     240,    14,   193,    13,    13,    13,    13,    13,     5,     5,
      13,   342,    13,    13,    13,   261,   148,   148,   148,   148,
     189,    12,   374,    12,   238,   287,   124,   132,   312,   313,
     199,   353,    73,    13,    13,    13,   165,   165,   165,   165,
     168,   214,   375,   376,   238,    22,    50,   151,   295,   314,
     315,   316,   317,   192,   323,    13,   198,    13,   151,   295,
     315,   318,   319,   131,   122,   122,    69,   320,   375,    72,
      72,    16,    50,    77,   106,   147,   318,   131,   117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   207,   208,   209,   209,   210,   210,   210,   210,   211,
     211,   211,   211,   212,   212,   213,   213,   214,   214,   215,
     216,   217,   217,   217,   218,   219,   219,   219,   219,   219,
     220,   221,   222,   223,   223,   224,   225,   226,   226,   227,
     227,   227,   228,   228,   229,   229,   230,   231,   232,   233,
     234,   235,   235,   236,   237,   237,   238,   238,   239,   239,
     239,   240,   240,   241,   242,   242,   243,   244,   244,   244,
     245,   245,   246,   246,   247,   247,   248,   249,   249,   250,
     251,   251,   252,   252,   252,   253,   253,   254,   254,   255,
     255,   256,   256,   257,   257,   258,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   262,   262,
     263,   263,   263,   264,   264,   265,   265,   265,   265,   266,
     267,   267,   267,   267,   268,   268,   269,   269,   270,   270,
     271,   271,   272,   272,   272,   273,   273,   274,   274,   274,
     274,   274,   274,   275,   275,   276,   276,   277,   277,   277,
     277,   278,   278,   279,   279,   280,   281,   281,   281,   282,
     282,   283,   283,   284,   284,   285,   285,   285,   286,   286,
     286,   286,   286,   286,   287,   287,   288,   288,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     291,   291,   292,   293,   293,   294,   294,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   296,   297,   297,   298,
     298,   299,   299,   300,   300,   301,   301,   301,   301,   302,
     302,   302,   302,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   304,   305,   305,
     305,   305,   305,   306,   306,   307,   308,   309,   310,   310,
     311,   311,   312,   312,   313,   313,   314,   314,   315,   315,
     315,   316,   317,   318,   318,   318,   319,   320,   320,   320,
     320,   320,   321,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   323,   323,
     323,   323,   324,   325,   326,   326,   326,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   328,   329,
     329,   330,   330,   331,   331,   331,   332,   332,   332,   332,
     332,   333,   333,   333,   333,   333,   334,   335,   335,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   336,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   338,   338,   338,   338,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   340,   340,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     342,   342,   342,   342,   343,   343,   343,   344,   344,   344,
     345,   345,   346,   346,   346,   347,   347,   348,   348,   349,
     349,   349,   349,   350,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   352,   352,   352,   352,
     353,   353,   354,   354,   354,   354,   354,   354,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   356,
     356,   356,   356,   356,   356,   356,   356,   356,   356,   356,
     357,   357,   358,   358,   359,   359,   359,   359,   359,   359,
     359,   359,   360,   361,   362,   362,   363,   363,   364,   365,
     366,   366,   366,   366,   367,   367,   367,   367,   367,   367,
     367,   368,   369,   369,   369,   369,   370,   370,   370,   370,
     371,   371,   372,   373,   373,   374,   374,   375,   375,   376,
     377,   377
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     0,     1,     1,     1,     5,
       4,     7,     6,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     2,     3,     2,     2,
       2,     5,     6,     1,     3,     3,     3,     1,     2,     1,
       4,     4,     1,     4,     1,     3,     3,     1,     1,     1,
       7,     0,     2,     2,     0,     4,     1,     3,     2,     1,
       5,     0,     1,     3,     1,     3,     2,     0,     1,     1,
       0,     2,     2,     3,     1,     3,     4,     0,     1,     3,
       1,     3,     0,     1,     1,     1,     3,     2,     1,     1,
       3,     1,     1,     1,     3,     2,     3,     7,     0,     1,
       1,     3,     3,     5,     5,     7,     7,     9,     9,     1,
       3,     5,     4,     7,     6,     6,     5,     1,     3,     5,
       1,     3,     5,     1,     1,     6,     5,     6,     5,     4,
       2,     2,     2,     1,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     5,     6,     3,     5,     4,
       6,     3,     4,     3,     4,     2,     1,     2,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     2,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     0,     1,     1,
       2,     4,     4,     0,     2,     1,     1,     1,     1,     5,
       4,     6,     5,     5,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     0,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     2,     2,
       1,     2,     4,     1,     2,     1,     2,     0,     3,     2,
       2,     3,     3,     4,     4,     3,     3,     6,     6,     4,
       1,     4,     1,     6,     1,     1,     5,     4,     1,     1,
       1,     1,     1,     6,     5,     2,     2,     5,     4,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     4,     1,     1,     4,     1,     4,     1,     6,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     7,
       4,     4,     4,     7,     7,     4,     4,     4,     1,     1,
       6,     4,     6,     4,     6,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     1,     1,     4,     4,     5,
       5,     4,     7,     6,     3,     6,     3,     4,     1,     1,
       1,     6,     3,     4,     1,     5,     2,     5,     2,     4,
       6,     6,     5,     7,     4,     6,     3,     4,     1,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     0,     5,     5,     5,     2,     3,
       8,     2,     5,     5,     4,     4,     5,     5,     4,     4,
       1,     1,     3,     0,     2,     0,     3,     1,     3,     2,
       0,     2
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
#if DB2_DEBUG

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
# if defined DB2_LTYPE_IS_TRIVIAL && DB2_LTYPE_IS_TRIVIAL

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
#else /* !DB2_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !DB2_DEBUG */


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
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3356 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3362 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 5: /* INTNUM  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3368 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 6: /* BOOL  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3374 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 7: /* APPROXNUM  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3380 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 8: /* NULLX  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3386 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 9: /* UNKNOWN  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3392 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 10: /* QUESTIONMARK  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3398 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 208: /* sql_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3404 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 209: /* stmt_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3410 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 210: /* stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3416 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 211: /* call_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3422 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 212: /* sql_argument_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3428 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 213: /* sql_argument  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3434 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 214: /* value_expression  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3440 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 215: /* sp_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3446 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 216: /* dql_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3452 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 217: /* dml_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3458 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 218: /* insert_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3464 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 219: /* insert_columns_and_source  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3470 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 220: /* from_constructor  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3476 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 221: /* delete_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3482 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 222: /* update_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3488 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 223: /* update_elem_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3494 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 224: /* update_elem  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3500 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 225: /* select_stmt  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3506 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 226: /* query_expression  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3512 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 227: /* query_expression_body  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3518 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 228: /* query_term  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3524 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 229: /* query_primary  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3530 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 230: /* select_with_parens  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3536 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 231: /* subquery  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3542 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 232: /* table_subquery  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3548 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 233: /* row_subquery  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3554 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 234: /* simple_table  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3560 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 235: /* opt_where  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3566 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 236: /* opt_from_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3572 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 237: /* opt_groupby  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3578 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 238: /* grouping_element_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3584 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 239: /* grouping_element  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3590 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 240: /* opt_order_by  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3596 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 241: /* order_by  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3602 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 242: /* sort_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3608 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 243: /* sort_key  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3614 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 244: /* opt_asc_desc  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3620 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 245: /* opt_having  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3626 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 246: /* with_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3632 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 247: /* with_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3638 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 248: /* common_table_expr  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3644 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 249: /* opt_derived_column_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3650 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 250: /* simple_ident_list_with_parens  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3656 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 251: /* simple_ident_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3662 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 252: /* opt_distinct  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3668 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 253: /* select_expr_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3674 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 254: /* projection  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3680 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 255: /* from_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3686 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 256: /* table_reference  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3692 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 257: /* table_primary  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3698 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 258: /* table_primary_non_join  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3704 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 259: /* opt_simple_ident_list_with_parens  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3710 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 260: /* column_ref  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3716 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 261: /* relation_factor  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3722 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 262: /* relation_factor_datatype  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3728 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 263: /* relation_factor_fuction  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3734 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 264: /* joined_table  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3740 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 265: /* qualified_join  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3746 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 266: /* cross_join  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3752 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 267: /* join_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3758 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 269: /* search_condition  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3764 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 270: /* boolean_term  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3770 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 271: /* boolean_factor  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3776 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 272: /* boolean_test  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3782 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 273: /* boolean_primary  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3788 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 274: /* predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3794 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 275: /* comparison_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3800 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 276: /* between_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3806 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 277: /* like_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3812 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 278: /* in_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3818 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 279: /* null_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3824 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 280: /* exists_predicate  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3830 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 281: /* row_expr  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3836 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 282: /* factor0  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3842 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 283: /* factor1  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3848 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 284: /* factor2  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3854 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 285: /* factor3  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3860 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 286: /* factor4  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3866 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 287: /* row_expr_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3872 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 288: /* in_expr  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3878 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 289: /* truth_value  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3884 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 295: /* expr_const  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3890 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 296: /* case_expr  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3896 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 297: /* case_arg  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3902 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 298: /* when_clause_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3908 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 299: /* when_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3914 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 300: /* case_default  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3920 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 301: /* func_expr  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3926 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 302: /* aggregate_windowed_function  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3932 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 303: /* aggregate_function_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3938 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 304: /* ranking_windowed_function  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3944 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 305: /* ranking_function_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3950 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 306: /* over_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3956 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 307: /* window_specification  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3962 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 308: /* window_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3968 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 309: /* window_specification_details  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3974 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 310: /* opt_existing_window_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3980 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 311: /* opt_window_partition_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3986 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 312: /* opt_window_frame_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3992 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 313: /* window_frame_units  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 3998 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 314: /* window_frame_extent  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4004 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 315: /* window_frame_start  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4010 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 316: /* window_frame_preceding  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4016 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 317: /* window_frame_between  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4022 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 318: /* window_frame_bound  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4028 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 319: /* window_frame_following  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4034 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 320: /* opt_window_frame_exclusion  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4040 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 321: /* scalar_function  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4046 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 322: /* function_call_keyword  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4052 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 323: /* data_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4058 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 324: /* user_defined_type_name  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4064 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 325: /* reference_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4070 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 326: /* collection_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4076 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 327: /* predefined_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4082 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 328: /* interval_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4088 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 329: /* interval_qualifier  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4094 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 330: /* start_field  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4100 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 331: /* end_field  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4106 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 332: /* single_datetime_field  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4112 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 333: /* non_second_primary_datetime_field  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4118 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 334: /* boolean_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4124 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 335: /* datetime_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4130 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 336: /* numeric_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4136 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 337: /* exact_numeric_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4142 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 338: /* approximate_numeric_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4148 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 339: /* character_string_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4154 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 340: /* binary_large_object_string_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4160 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 341: /* national_character_string_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4166 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 342: /* large_object_length  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4172 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 343: /* char_length_units  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4178 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 344: /* multiplier  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4184 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 345: /* distinct_or_all  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4190 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 347: /* opt_as_label  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4196 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 348: /* as_label  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4202 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 349: /* label  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4208 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 350: /* collate_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4214 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 351: /* name_fuc  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4220 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 352: /* name_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4226 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 353: /* name_r  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4232 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 354: /* reserved  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4238 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 355: /* reserved_other  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4244 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 356: /* reserved_type  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4250 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 357: /* opt_db2_special_clause_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4256 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 358: /* db2_special_clause_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4262 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 359: /* db2_special_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4268 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 360: /* db2_for_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4274 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 361: /* for_update  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4280 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 362: /* opt_of_simple_ident_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4286 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 363: /* read_only  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4292 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 364: /* skip_locked  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4298 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 365: /* with_isolation  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4304 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 366: /* isolation  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4310 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 367: /* opt_db2_locks  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4316 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 368: /* queryno_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4322 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 369: /* fetch_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4328 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 370: /* optimize_clause  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4334 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 371: /* param_num  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4340 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 372: /* limit_num  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4346 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 373: /* offset_num  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4352 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 374: /* opt_col_def_list_with_parens  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4358 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 375: /* col_def_list  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4364 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 376: /* col_def  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4370 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
        break;

    case 377: /* opt_cardinality  */
#line 95 "sql_db2.y" /* yacc.c:1257  */
      { delete(((*yyvaluep).node)); }
#line 4376 "sqlparser_db2_bison.cpp" /* yacc.c:1257  */
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
# if defined DB2_LTYPE_IS_TRIVIAL && DB2_LTYPE_IS_TRIVIAL
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
#line 64 "sql_db2.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 4493 "sqlparser_db2_bison.cpp" /* yacc.c:1429  */
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
#line 238 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-1].node);
    result->result_tree_ = (yyvsp[-1].node);
    result->accept = true;
    YYACCEPT;
}
#line 4687 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 249 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
#line 4696 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 256 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 4702 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 264 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 4711 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 269 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-2].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 4720 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 274 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 4729 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 279 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 4738 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 288 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 4747 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 296 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 4756 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 301 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 4765 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 328 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 4774 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 336 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE_DB2, 3, nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 4783 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 341 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE_DB2, 3, (yyvsp[-1].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 4792 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 346 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE_DB2, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 4801 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 351 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE_DB2, 3, nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 4810 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 356 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* src = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT VALUES");
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE_DB2, 3, nullptr, src, nullptr);
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 4820 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 365 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
#line 4829 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 374 "sql_db2.y" /* yacc.c:1646  */
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
#line 4846 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 391 "sql_db2.y" /* yacc.c:1646  */
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
#line 4864 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 409 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 4873 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
#line 4882 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 426 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[-2].node);
    (yyval.node)->setChild(2, (yyvsp[-1].node));
    (yyval.node)->setChild(3, (yyvsp[0].node));
    //$$->setChild(4, $4);
}
#line 4893 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 436 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, (yyvsp[0].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}
#line 4902 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 441 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}
#line 4911 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 449 "sql_db2.y" /* yacc.c:1646  */
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
#line 4942 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 476 "sql_db2.y" /* yacc.c:1646  */
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
#line 4973 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 507 "sql_db2.y" /* yacc.c:1646  */
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
#line 5004 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 538 "sql_db2.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].node)->getChild(E_DIRECT_SELECT_WITH)) {
        yyerror(&(yylsp[-2]), result, scanner, "error use common table expression");
        YYABORT;
    }
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5017 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 551 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5026 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 565 "sql_db2.y" /* yacc.c:1646  */
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
                    nullptr,        /* E_SELECT_ORDER_BY 10 */
                    nullptr,        /* E_SELECT_LIMIT 11 */
                    nullptr,        /* E_SELECT_FOR_UPDATE 12 */
                    nullptr,        /* E_SELECT_HINTS 13 */
                    nullptr,        /* E_SELECT_WHEN 14 */
                    nullptr,        /* E_SELECT_OPT_TOP 15 */
                    nullptr,        /* E_SELECT_OPT_WITH 16 */
                    nullptr,        /* E_SELECT_OPT_OPTION 17 */
	                nullptr,         /* E_SELECT_OPT_INTO 18 */
	                nullptr             /*user for bigquery*/
                    );
    (yyval.node)->serialize_format = &SELECT_SERIALIZE_FORMAT;
}
#line 5056 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 593 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5062 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 595 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
#line 5071 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 604 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FROM_SERIALIZE_FORMAT;
}
#line 5080 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 611 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5086 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 613 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
#line 5095 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 622 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5104 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 629 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"()"); }
#line 5110 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 632 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5121 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 641 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5127 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 647 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_BY_SERIALIZE_FORMAT;
}
#line 5136 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 656 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5145 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_KEY, E_SORT_KEY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 5154 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 672 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "");
}
#line 5162 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 676 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
#line 5170 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 680 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
#line 5178 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 686 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5184 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 688 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
#line 5193 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 698 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
#line 5202 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 703 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
#line 5211 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 712 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5220 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 721 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, E_COMMON_TABLE_EXPR_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT;
}
#line 5229 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 728 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5235 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 734 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5244 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 743 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5253 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 750 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5259 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 752 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 5267 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 756 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 5275 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 764 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5284 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 772 "sql_db2.y" /* yacc.c:1646  */
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
#line 5302 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 786 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, star_node);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 5312 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 796 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5321 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 810 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5330 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 822 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 5339 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 827 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &AS_SERIALIZE_FORMAT;
}
#line 5348 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 832 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_DB2_CONSTRUCT_TABLE, 4,
        (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DB2_TABLE_SERIALIZE_FORMAT;
}
#line 5358 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 840 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 5364 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 847 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5374 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 853 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5384 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 859 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			nd, (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5395 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 866 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5405 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 872 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			nd, (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5416 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 879 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5426 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 885 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			nd, (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5437 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 893 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-8].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5447 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 899 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			nd, (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-8].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 5458 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 964 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 5467 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 969 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 5476 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 974 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 5485 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 979 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 5494 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 984 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 5503 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 989 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 5512 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 994 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, (yyvsp[-3].node), (yyvsp[-5].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 5521 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 999 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, (yyvsp[-4].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 5530 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1007 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 5539 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1012 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 5548 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1017 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 5557 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1025 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 5566 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1030 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 5575 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1035 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 5584 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1050 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 5593 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1055 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 5603 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1062 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 5612 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1067 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 5622 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1076 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 5632 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1101 "sql_db2.y" /* yacc.c:1646  */
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
#line 5647 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1112 "sql_db2.y" /* yacc.c:1646  */
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
#line 5662 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1123 "sql_db2.y" /* yacc.c:1646  */
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
#line 5677 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1134 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_JOIN_INNER, "INNER");
}
#line 5685 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1140 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 5691 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1141 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; /*this is a flag*/}
#line 5697 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1148 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 5706 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1157 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 5715 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1166 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 5724 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1175 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 5733 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1180 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 5742 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1189 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5751 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1217 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 5760 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1222 "sql_db2.y" /* yacc.c:1646  */
    {
      (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
      (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
  }
#line 5769 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1230 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 5778 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1235 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 5787 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1243 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 5796 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1248 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 5805 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1253 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 5814 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1258 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 5823 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1266 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 5832 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1271 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 5841 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1279 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 5850 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1284 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 5859 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1292 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 5868 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1302 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 5877 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1307 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 5886 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1316 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 5895 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1325 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 5904 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1334 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POW);
}
#line 5913 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1343 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POS);
}
#line 5922 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1348 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
#line 5931 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1359 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5940 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1370 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5949 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1379 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5958 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1389 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 5964 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1390 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LT; }
#line 5970 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1391 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 5976 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1392 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GT; }
#line 5982 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1393 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_EQ; }
#line 5988 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1394 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 5994 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1395 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_GE; }
#line 6000 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1396 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_LE; }
#line 6006 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1397 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 6012 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1398 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_NE; }
#line 6018 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1402 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 6024 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1403 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_CNN; }
#line 6030 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1409 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.nodetype) = Node::comp_all_some_any_op_form((yyvsp[-1].nodetype), (yyvsp[0].ival));
}
#line 6038 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1415 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_ADD; }
#line 6044 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1416 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MINUS; }
#line 6050 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1420 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MUL; }
#line 6056 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1421 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_DIV; }
#line 6062 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1422 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_REM; }
#line 6068 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1423 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.nodetype) = E_OP_MOD; }
#line 6074 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1433 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "DEFAULT"); }
#line 6080 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1439 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_CASE);
}
#line 6089 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1446 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6095 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1453 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 6104 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1461 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6113 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1466 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6122 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1473 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6128 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1475 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
#line 6137 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1492 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6147 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1498 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6157 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1504 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6167 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1510 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node),  (yyvsp[-2].node),(yyvsp[-1].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6177 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1516 "sql_db2.y" /* yacc.c:1646  */
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
#line 6193 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1528 "sql_db2.y" /* yacc.c:1646  */
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
#line 6209 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 235:
#line 1542 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
#line 6215 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 236:
#line 1543 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
#line 6221 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 237:
#line 1544 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
#line 6227 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 238:
#line 1545 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
#line 6233 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 239:
#line 1546 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
#line 6239 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 240:
#line 1547 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
#line 6245 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 241:
#line 1548 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
#line 6251 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 242:
#line 1549 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
#line 6257 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 243:
#line 1550 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
#line 6263 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 244:
#line 1551 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING"); }
#line 6269 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 245:
#line 1552 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT_BIG");}
#line 6275 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 246:
#line 1553 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV");}
#line 6281 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 247:
#line 1558 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), nullptr, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6291 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 248:
#line 1566 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
#line 6297 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 249:
#line 1567 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
#line 6303 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 250:
#line 1568 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
#line 6309 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 251:
#line 1569 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
#line 6315 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 252:
#line 1570 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
#line 6321 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 253:
#line 1575 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node));
}
#line 6329 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 254:
#line 1579 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
#line 6338 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 255:
#line 1588 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 6344 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 257:
#line 1597 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
#line 6353 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 258:
#line 1604 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6359 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 260:
#line 1609 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6365 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 261:
#line 1611 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 6371 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 262:
#line 1615 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6377 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 263:
#line 1617 "sql_db2.y" /* yacc.c:1646  */
    {
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+s3);
    delete((yyvsp[-2].node)); delete((yyvsp[-1].node)); delete((yyvsp[0].node));
}
#line 6387 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 264:
#line 1625 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
#line 6393 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 265:
#line 1626 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
#line 6399 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 268:
#line 1635 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
#line 6405 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 269:
#line 1636 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
#line 6411 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 271:
#line 1641 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" PRECEDING"); delete((yyvsp[-1].node)); }
#line 6417 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 272:
#line 1646 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text()); delete((yyvsp[-2].node)); delete((yyvsp[0].node)); }
#line 6423 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 274:
#line 1651 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
#line 6429 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 276:
#line 1656 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" FOLLOWING"); delete((yyvsp[-1].node)); }
#line 6435 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 277:
#line 1660 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 6441 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 278:
#line 1661 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
#line 6447 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 279:
#line 1662 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
#line 6453 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 280:
#line 1663 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
#line 6459 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 281:
#line 1664 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
#line 6465 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 282:
#line 1669 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6475 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 283:
#line 1675 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6485 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 284:
#line 1687 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6495 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 285:
#line 1693 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6506 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 286:
#line 1700 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6517 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 287:
#line 1707 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 6528 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 288:
#line 1714 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-3].node), nullptr, nullptr, transcoding_name);
    (yyval.node)->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
#line 6541 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 289:
#line 1723 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6552 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 290:
#line 1730 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6563 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 291:
#line 1737 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6574 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 292:
#line 1744 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6585 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 293:
#line 1751 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6598 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 294:
#line 1760 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6609 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 295:
#line 1767 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6620 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 296:
#line 1774 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CHAR");
    Node* mut = Node::makeTerminalNode(E_STRING, "MINUTES");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        fun_name,   (yyvsp[-2].node),mut,nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6632 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 297:
#line 1782 "sql_db2.y" /* yacc.c:1646  */
    {
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "DATE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        fun_name,   (yyvsp[-1].node),nullptr,nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6643 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 302:
#line 1802 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 6652 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 303:
#line 1810 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REF("+(yyvsp[-3].node)->text()+")SCOPE "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 6661 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 304:
#line 1818 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" ARRAY("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-4].node));
    delete((yyvsp[-1].node));
}
#line 6671 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 305:
#line 1824 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" ARRAY");
    delete((yyvsp[-1].node));
}
#line 6680 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 306:
#line 1829 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" MULTISET");
    delete((yyvsp[-1].node));
}
#line 6689 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 307:
#line 1837 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" CHARACTER SET "+(yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-4].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 6698 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 308:
#line 1842 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+" CHARACTER SET "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 6707 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 309:
#line 1847 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 6716 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 311:
#line 1853 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 6725 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 318:
#line 1867 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTERVAL "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 6734 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 319:
#line 1875 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" TO "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[0].node));
}
#line 6743 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 321:
#line 1884 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));
    delete((yyvsp[-1].node));
}
#line 6753 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 324:
#line 1895 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6762 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 325:
#line 1900 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 6770 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 326:
#line 1907 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 6779 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 328:
#line 1913 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 6788 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 329:
#line 1918 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6797 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 330:
#line 1923 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 6805 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 331:
#line 1930 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "YEAR");
}
#line 6813 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 332:
#line 1934 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MONTH");
}
#line 6821 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 333:
#line 1938 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DAY");
}
#line 6829 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 334:
#line 1942 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "HOUR");
}
#line 6837 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 335:
#line 1946 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MINUTE");
}
#line 6845 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 336:
#line 1953 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BOOLEAN");
}
#line 6853 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 337:
#line 1960 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE");
}
#line 6861 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 338:
#line 1964 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 6870 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 339:
#line 1969 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 6879 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 340:
#line 1974 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6888 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 341:
#line 1979 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITH TIME ZONE");
}
#line 6896 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 342:
#line 1983 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITHOUT TIME ZONE");
}
#line 6904 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 343:
#line 1987 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 6913 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 344:
#line 1992 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 6922 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 345:
#line 1997 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6931 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 346:
#line 2002 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITH TIME ZONE");
}
#line 6939 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 347:
#line 2006 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITHOUT TIME ZONE");
}
#line 6947 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 350:
#line 2018 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 6956 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 351:
#line 2023 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6965 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 352:
#line 2028 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 6974 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 353:
#line 2033 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 6983 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 354:
#line 2038 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 6992 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 355:
#line 2043 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7001 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 356:
#line 2048 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC");
}
#line 7009 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 357:
#line 2052 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SMALLINT");
}
#line 7017 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 358:
#line 2056 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTEGER");
}
#line 7025 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 359:
#line 2060 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INT");
}
#line 7033 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 360:
#line 2064 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BIGINT");
}
#line 7041 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 361:
#line 2068 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC");
}
#line 7049 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 362:
#line 2072 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL");
}
#line 7057 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 363:
#line 2079 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7066 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 364:
#line 2084 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DOUBLE PRECISION");
}
#line 7074 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 365:
#line 2088 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT");
}
#line 7082 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 366:
#line 2092 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REAL");
}
#line 7090 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 367:
#line 2099 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7099 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 368:
#line 2104 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7108 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 369:
#line 2109 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7117 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 370:
#line 2114 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7126 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 371:
#line 2119 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7135 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 372:
#line 2124 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR("+(yyvsp[-4].node)->text()+") FOR BIT DATA");
    delete((yyvsp[-4].node));
}
#line 7144 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 373:
#line 2129 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7153 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 374:
#line 2134 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT");
}
#line 7161 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 375:
#line 2138 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7170 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 376:
#line 2143 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT");
}
#line 7178 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 377:
#line 2147 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7187 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 378:
#line 2152 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB");
}
#line 7195 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 379:
#line 2156 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR");
}
#line 7203 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 380:
#line 2160 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER");
}
#line 7211 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 381:
#line 2167 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7220 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 382:
#line 2172 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT");
}
#line 7228 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 383:
#line 2176 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7237 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 384:
#line 2181 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB");
}
#line 7245 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 385:
#line 2188 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7254 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 386:
#line 2193 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER");
}
#line 7262 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 387:
#line 2197 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7271 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 388:
#line 2202 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR");
}
#line 7279 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 389:
#line 2206 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7288 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 390:
#line 2211 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7297 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 391:
#line 2216 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7306 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 392:
#line 2221 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7315 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 393:
#line 2226 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7324 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 394:
#line 2231 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT");
}
#line 7332 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 395:
#line 2235 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7341 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 396:
#line 2240 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT");
}
#line 7349 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 397:
#line 2244 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7358 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 398:
#line 2249 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB");
}
#line 7366 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 399:
#line 2253 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR");
}
#line 7374 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 400:
#line 2260 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7383 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 401:
#line 2265 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7392 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 402:
#line 2270 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7401 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 403:
#line 2275 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7410 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 404:
#line 2283 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTERS");
}
#line 7418 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 405:
#line 2287 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CODE_UNITS");
}
#line 7426 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 406:
#line 2291 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "OCTETS");
}
#line 7434 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 407:
#line 2298 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "K");
}
#line 7442 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 408:
#line 2302 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "M");
}
#line 7450 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 409:
#line 2306 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "G");
}
#line 7458 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 410:
#line 2313 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 7466 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 411:
#line 2317 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 7474 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 412:
#line 2323 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 7480 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 413:
#line 2324 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.ival) = 1; }
#line 7486 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 414:
#line 2325 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.ival) = 2; }
#line 7492 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 415:
#line 2329 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 7498 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 417:
#line 2334 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 7504 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 422:
#line 2342 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CASE"); }
#line 7510 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 423:
#line 2350 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeTerminalNode(E_STRING, "COLLATE "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7519 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 427:
#line 2360 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY"); }
#line 7525 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 428:
#line 2361 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINARY"); }
#line 7531 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 429:
#line 2362 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTERS"); }
#line 7537 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 430:
#line 2363 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 7543 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 431:
#line 2364 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 7549 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 432:
#line 2365 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME");  }
#line 7555 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 433:
#line 2366 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMEZONE"); }
#line 7561 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 434:
#line 2367 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIT"); }
#line 7567 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 447:
#line 2388 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ANY"); }
#line 7573 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 448:
#line 2392 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
#line 7579 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 449:
#line 2393 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
#line 7585 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 450:
#line 2394 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
#line 7591 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 451:
#line 2395 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CAST"); }
#line 7597 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 452:
#line 2396 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
#line 7603 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 453:
#line 2397 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
#line 7609 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 454:
#line 2398 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FOLLOWING"); }
#line 7615 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 455:
#line 2399 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INTERVAL"); }
#line 7621 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 456:
#line 2400 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
#line 7627 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 457:
#line 2401 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
#line 7633 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 458:
#line 2402 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
#line 7639 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 459:
#line 2403 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
#line 7645 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 460:
#line 2404 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
#line 7651 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 461:
#line 2405 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECEDING"); }
#line 7657 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 462:
#line 2406 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
#line 7663 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 463:
#line 2407 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RECURSIVE"); }
#line 7669 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 464:
#line 2408 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
#line 7675 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 465:
#line 2409 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
#line 7681 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 466:
#line 2410 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
#line 7687 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 467:
#line 2411 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SECOND"); }
#line 7693 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 468:
#line 2412 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UNBOUNDED"); }
#line 7699 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 469:
#line 2413 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
#line 7705 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 470:
#line 2414 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
#line 7711 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 471:
#line 2415 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OF"); }
#line 7717 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 472:
#line 2416 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
#line 7723 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 473:
#line 2417 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DESC"); }
#line 7729 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 474:
#line 2418 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
#line 7735 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 475:
#line 2419 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
#line 7741 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 476:
#line 2420 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
#line 7747 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 477:
#line 2421 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXCLUDE"); }
#line 7753 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 478:
#line 2422 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ASC"); }
#line 7759 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 479:
#line 2423 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }
#line 7765 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 480:
#line 2424 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }
#line 7771 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 481:
#line 2425 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
#line 7777 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 482:
#line 2426 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT TIMESTAMP"); }
#line 7783 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 483:
#line 2427 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT DEGREE"); }
#line 7789 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 484:
#line 2428 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT SCHEMA"); }
#line 7795 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 485:
#line 2429 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT TIMEZONE"); }
#line 7801 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 486:
#line 2430 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DEGREE"); }
#line 7807 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 487:
#line 2431 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCHEMA"); }
#line 7813 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 488:
#line 2432 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOCKED"); }
#line 7819 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 489:
#line 2433 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATA"); }
#line 7825 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 490:
#line 2434 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "USE"); }
#line 7831 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 491:
#line 2435 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "KEEP"); }
#line 7837 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 492:
#line 2436 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXCLUSIVE"); }
#line 7843 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 493:
#line 2437 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LOCKS"); }
#line 7849 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 494:
#line 2438 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CARDINALITY"); }
#line 7855 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 495:
#line 2439 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MINUTES"); }
#line 7861 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 496:
#line 2440 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SHARE"); }
#line 7867 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 497:
#line 2441 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WAIT"); }
#line 7873 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 498:
#line 2442 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OUTCOME"); }
#line 7879 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 499:
#line 2446 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHAR"); }
#line 7885 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 500:
#line 2447 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY"); }
#line 7891 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 501:
#line 2448 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINARY"); }
#line 7897 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 502:
#line 2449 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTERS"); }
#line 7903 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 503:
#line 2450 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 7909 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 504:
#line 2451 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 7915 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 505:
#line 2452 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME");  }
#line 7921 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 506:
#line 2453 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMEZONE"); }
#line 7927 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 507:
#line 2454 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIT"); }
#line 7933 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 508:
#line 2455 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DATE"); }
#line 7939 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 509:
#line 2456 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INT"); }
#line 7945 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 510:
#line 2460 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 7951 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 513:
#line 2466 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SPECIAL_CLAUSE_LIST, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 7960 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 523:
#line 2487 "sql_db2.y" /* yacc.c:1646  */
    {
    Node * for_ = Node::makeTerminalNode(E_STRING, "FOR");
    Node * update_ = Node::makeTerminalNode(E_STRING, "UPDATE");
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_UPDATE, 3, for_, update_, (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = &FOR_UPDATE_FORMAT;
}
#line 7971 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 524:
#line 2495 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 7977 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 525:
#line 2497 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
}
#line 7985 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 526:
#line 2502 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR READ ONLY"); }
#line 7991 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 527:
#line 2503 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FOR FETCH ONLY"); }
#line 7997 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 528:
#line 2506 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "SKIP LOCKED DATA"); }
#line 8003 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 529:
#line 2510 "sql_db2.y" /* yacc.c:1646  */
    {
     std::string ss = "WITH ";
     ss += (yyvsp[-1].node)->text() ;
     delete((yyvsp[-1].node));
     if((yyvsp[0].node)){
        ss += (yyvsp[0].node)->text();
        delete((yyvsp[0].node));
     }
    (yyval.node) = Node::makeTerminalNode(E_STRING, ss);
}
#line 8018 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 530:
#line 2522 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CS"); }
#line 8024 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 531:
#line 2523 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UR"); }
#line 8030 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 532:
#line 2524 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RS"); }
#line 8036 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 533:
#line 2525 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RR"); }
#line 8042 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 534:
#line 2527 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8048 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 535:
#line 2528 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " USE AND KEEP EXCLUSIVE LOCKS"); }
#line 8054 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 536:
#line 2529 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " USE AND KEEP UPDATE LOCKS"); }
#line 8060 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 537:
#line 2530 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " USE AND KEEP SHARE LOCKS"); }
#line 8066 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 538:
#line 2531 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " KEEP LOCKS"); }
#line 8072 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 539:
#line 2532 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " WAIT FOR OUTCOME"); }
#line 8078 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 540:
#line 2533 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, " USE AND KEEP UPDATE LOCKS WAIT FOR OUTCOME"); }
#line 8084 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 541:
#line 2537 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "QUERYNO "+(yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 8090 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 542:
#line 2539 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FETCH FIRST "+(yyvsp[-2].node)->text()+" ROWS ONLY"); delete((yyvsp[-2].node));  }
#line 8096 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 543:
#line 2540 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FETCH FIRST "+(yyvsp[-2].node)->text()+" ROW ONLY"); delete((yyvsp[-2].node));  }
#line 8102 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 544:
#line 2541 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FETCH FIRST "+(yyvsp[-1].node)->text()+" ROWS"); delete((yyvsp[-1].node));  }
#line 8108 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 545:
#line 2542 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "FETCH FIRST "+(yyvsp[-1].node)->text()+" ROW"); delete((yyvsp[-1].node));  }
#line 8114 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 546:
#line 2544 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "OPTIMIZE FOR "+(yyvsp[-2].node)->text()+" ROWS ONLY"); delete((yyvsp[-2].node));  }
#line 8120 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 547:
#line 2545 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "OPTIMIZE FOR "+(yyvsp[-2].node)->text()+" ROW ONLY"); delete((yyvsp[-2].node));  }
#line 8126 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 548:
#line 2546 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "OPTIMIZE FOR "+(yyvsp[-1].node)->text()+" ROWS"); delete((yyvsp[-1].node));  }
#line 8132 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 549:
#line 2547 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "OPTIMIZE FOR "+(yyvsp[-1].node)->text()+" ROW"); delete((yyvsp[-1].node));  }
#line 8138 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 552:
#line 2555 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &LIMIT_NUM_FORMAT;
}
#line 8147 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 553:
#line 2560 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8153 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 554:
#line 2562 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_NUM_FORMAT;
}
#line 8162 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 555:
#line 2570 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8168 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 556:
#line 2572 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 8177 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 558:
#line 2580 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8186 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 559:
#line 2587 "sql_db2.y" /* yacc.c:1646  */
    {
    (yyval.node) = Node::makeNonTerminalNode(E_COLUMN_DEFINED, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8195 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 560:
#line 2593 "sql_db2.y" /* yacc.c:1646  */
    {(yyval.node) = nullptr;}
#line 8201 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;

  case 561:
#line 2594 "sql_db2.y" /* yacc.c:1646  */
    { (yyval.node) = Node::makeTerminalNode(E_STRING, "CARDINALITY "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 8207 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
    break;


#line 8211 "sqlparser_db2_bison.cpp" /* yacc.c:1646  */
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
#line 2597 "sql_db2.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */
