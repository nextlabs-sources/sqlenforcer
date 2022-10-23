/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

/* First part of user prologue.  */
#line 1 "oracle.y"

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


#line 113 "sqlparser_oracle_bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 170 "sqlparser_oracle_bison.cpp"

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

#line 395 "sqlparser_oracle_bison.cpp"

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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   7297

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  194
/* YYNRULES -- Number of rules.  */
#define YYNRULES  588
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1054

#define YYUNDEFTOK  2
#define YYMAXUTOK   462


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
static const yytype_int16 yyrline[] =
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
     983,   988,   993,  1043,  1048,  1098,  1105,  1113,  1122,  1130,
    1137,  1144,  1151,  1161,  1162,  1167,  1171,  1177,  1183,  1192,
    1198,  1204,  1210,  1216,  1287,  1288,  1296,  1301,  1306,  1343,
    1344,  1345,  1346,  1350,  1356,  1364,  1369,  1375,  1380,  1389,
    1398,  1405,  1414,  1425,  1436,  1447,  1454,  1455,  1460,  1461,
    1469,  1470,  1478,  1479,  1487,  1488,  1493,  1501,  1502,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1527,  1531,  1540,  1548,
    1556,  1561,  1569,  1574,  1579,  1584,  1592,  1597,  1605,  1610,
    1618,  1619,  1620,  1623,  1632,  1633,  1638,  1646,  1647,  1655,
    1656,  1664,  1665,  1673,  1674,  1679,  1687,  1688,  1689,  1690,
    1695,  1696,  1700,  1701,  1709,  1710,  1717,  1717,  1722,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1735,  1736,
    1741,  1748,  1749,  1753,  1754,  1755,  1756,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1774,  1782,  1783,
    1787,  1788,  1796,  1801,  1809,  1810,  1819,  1820,  1821,  1822,
    1827,  1833,  1839,  1845,  1851,  1863,  1878,  1879,  1880,  1881,
    1882,  1883,  1884,  1885,  1886,  1887,  1888,  1892,  1901,  1902,
    1903,  1904,  1905,  1909,  1913,  1922,  1927,  1931,  1939,  1940,
    1944,  1945,  1950,  1951,  1960,  1961,  1965,  1966,  1970,  1971,
    1972,  1976,  1980,  1985,  1986,  1987,  1991,  1995,  1996,  1997,
    1998,  1999,  2003,  2009,  2021,  2027,  2034,  2041,  2048,  2057,
    2064,  2071,  2078,  2085,  2094,  2101,  2108,  2121,  2122,  2123,
    2124,  2128,  2136,  2141,  2146,  2151,  2160,  2168,  2174,  2179,
    2187,  2192,  2197,  2202,  2203,  2208,  2209,  2210,  2211,  2212,
    2213,  2217,  2225,  2230,  2234,  2240,  2244,  2245,  2250,  2257,
    2262,  2263,  2268,  2273,  2280,  2284,  2288,  2292,  2296,  2300,
    2304,  2308,  2312,  2319,  2326,  2330,  2335,  2340,  2345,  2349,
    2353,  2358,  2363,  2368,  2372,  2376,  2383,  2384,  2388,  2393,
    2398,  2403,  2408,  2413,  2418,  2422,  2426,  2430,  2434,  2438,
    2442,  2449,  2454,  2458,  2462,  2469,  2474,  2479,  2484,  2489,
    2494,  2499,  2503,  2508,  2512,  2517,  2521,  2525,  2532,  2537,
    2541,  2546,  2553,  2558,  2562,  2567,  2571,  2576,  2581,  2586,
    2591,  2596,  2600,  2605,  2609,  2614,  2618,  2625,  2630,  2635,
    2640,  2648,  2652,  2656,  2663,  2667,  2671,  2678,  2682,  2689,
    2690,  2691,  2695,  2696,  2700,  2701,  2705,  2710,  2720,  2721,
    2725,  2726,  2730,  2731,  2732,  2733,  2734,  2735,  2736,  2740,
    2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,  2750,  2751,
    2752,  2757,  2758,  2759,  2760,  2761,  2762,  2763,  2764,  2765,
    2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,  2774,  2775,
    2776,  2777,  2778,  2779,  2781,  2782,  2783,  2784,  2785,  2786,
    2787,  2788,  2789,  2790,  2791,  2792,  2793,  2794,  2795,  2796,
    2800,  2801,  2802,  2803,  2806,  2807,  2808,  2809,  2810,  2815,
    2816,  2823,  2830,  2831,  2839,  2840,  2847,  2848,  2851,  2852,
    2853,  2860,  2867,  2868,  2871,  2872,  2875,  2876,  2877,  2880,
    2881,  2889,  2890,  2893,  2894,  2897,  2898,  2917,  2938,  2939,
    2942,  2949,  2958,  2959,  2963,  2970,  2971,  2972,  2973,  2976,
    2989,  2998,  3003,  3008,  3016,  3022,  3031,  3032,  3040
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
  "pivot_clause", "select_expr_list_with_parens", "partition_by",
  "table_function", "opt_simple_ident_list_with_parens", "asterisk_expr",
  "column_ref", "relation_factor_2", "relation_factor", "joined_table",
  "cross_apply", "qualified_join", "cross_join", "natural_join",
  "join_type", "join_outer", "search_condition", "boolean_term",
  "boolean_factor", "boolean_test", "boolean_primary", "predicate",
  "bool_function", "comparison_predicate",
  "quantified_comparison_predicate", "between_predicate", "like_predicate",
  "in_predicate", "null_predicate", "null_value", "exists_predicate",
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
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-840)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-366)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     331,   136,  6728,    43,   113,    37,   203,  6728,  6920,    50,
     331,   220,   246,   294,   219,   104,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,   266,   244,  -840,  -840,
      57,   292,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,   335,  -840,  -840,  -840,
    -840,   338,  -840,  -840,  -840,  6728,  6728,  -840,  -840,   151,
    3767,   337,  6152,   265,  6728,  -840,   194,   408,   296,   368,
    5382,  6728,  -840,  -840,   331,   151,    32,   151,   151,   363,
    -840,   151,   266,  -840,  2255,  6728,   280,   145,  3767,  -840,
    -840,  -840,  -840,  -840,  -840,  -840,  3551,  4199,   435,   453,
     456,   466,  -840,   479,  -840,   472,   480,   489,  -840,  -840,
     499,   491,  -840,  4199,  4199,  -840,  -840,  -840,   431,   293,
    -840,  -840,   496,  1831,   109,   108,   295,  -840,  -840,  -840,
    -840,  -840,  -840,   497,  -840,   501,  -840,  -840,   504,   161,
     663,  6728,  -840,  -840,  -840,  -840,  4199,  -840,  6728,  6728,
     502,  -840,   529,  -840,  -840,  -840,   444,   526,  -840,    85,
     121,   539,  -840,   541,   542,   436,   543,  -840,  -840,   264,
     380,   152,   546,   551,  -840,   555,  -840,    62,   123,   557,
    -840,  -840,    98,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,   318,  -840,   532,   558,  -840,
    -840,   559,  -840,    57,  4199,   547,    57,    57,   421,   398,
    -840,    57,   363,  2039,  -840,   565,  2687,   566,   567,   374,
     562,   473,   576,  -840,  -840,   506,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  1122,   328,   579,  2687,  -840,
    5574,   440,  4199,  -840,   430,   430,   176,   431,  3551,   585,
      35,   587,    54,   441,  4199,  4199,  4199,   597,  -840,   590,
    4199,   592,  -840,   376,  -840,  -840,  5766,   280,  3767,  3983,
    -840,  6728,   387,  4199,  -840,  -840,  -840,  -840,  4199,  -840,
    -840,  -840,  -840,  4199,  4199,  2903,   595,  4199,  4616,   499,
    -840,  -840,   280,   396,    33,  -840,   598,   397,   601,   575,
     507,   611,   614,   510,   613,   619,   516,   616,   626,   630,
     631,  -840,   632,   625,  -840,   488,  -840,    82,   100,   277,
     636,   531,   634,   626,   638,  6728,   640,   498,   500,   646,
     508,   511,   647,   641,  -840,   517,  -840,  -840,  7087,  2471,
     244,  -840,   443,    41,  4199,   244,   244,   549,   357,  -840,
     476,  -840,   398,  2039,    95,   102,   136,  -840,  -840,  -840,
    1122,  4199,  -840,  2687,  5382,  2687,  2687,   110,  4199,  -840,
    -840,   624,  -840,   369,  -840,   653,    74,  4199,   315,   635,
    3119,   565,  6728,  6728,   473,  -840,  -840,  4199,  -840,  -840,
     430,   430,   280,   662,  -840,  4199,  -840,  2687,   617,   441,
      27,   666,    40,   669,  -840,    52,  -840,   664,   609,  -840,
    5192,   672,   673,   674,  6152,  -840,   432,  -840,  -840,  6152,
    6344,  -840,  -840,  -840,  -840,  -840,  -840,   250,  -840,  -840,
     677,  -840,  -840,   109,   108,   295,  -840,  -840,  -840,   678,
       5,  4199,   573,    12,  -840,   403,   430,  4199,  4199,  -840,
    6728,   136,   515,   696,   691,   693,   694,   692,   704,   697,
     699,   705,   348,   702,     6,     8,   706,   713,   376,   714,
     718,   717,   721,   622,   722,   720,   723,   732,   724,    21,
     725,   726,   560,   578,   728,   582,   583,   729,   754,  6728,
     745,   552,   748,  4199,  -840,  -840,   588,  -840,  6728,   281,
    -840,  -840,  -840,   313,   285,  -840,  -840,  -840,   752,  -840,
      98,   576,  -840,  -840,  -840,   290,  -840,    22,  -840,  -840,
    -840,  3551,  -840,  -840,  -840,    86,  -840,  -840,  -840,    47,
    4199,   653,  4199,  -840,  -840,  -840,  -840,    54,  -840,  -840,
     409,  -840,   679,  -840,  -840,   250,   238,  -840,     4,   505,
    4199,   707,  -840,  5382,  -840,  6728,  -840,  4199,   768,  4199,
    5192,   486,   762,   767,  6728,  6728,  6728,    25,    -6,   659,
    -840,  5766,   659,   422,   596,   659,  5766,   695,  -840,    36,
     -32,  6152,   627,   755,   710,   604,   608,  -840,  -840,   573,
     573,    16,  6536,  -840,  -840,  4808,  -840,  -840,    54,  -840,
     782,   269,   615,  -840,  -840,   799,  -840,  -840,   626,   793,
    -840,   626,   794,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
     316,  -840,  -840,   804,  -840,   805,  -840,    29,  -840,   801,
     802,   812,   806,   808,   813,  -840,   626,   809,  -840,  -840,
     814,   698,   325,  -840,  -840,   327,  -840,  -840,  -840,   811,
     532,  7087,  -840,   629,  -840,   210,  -840,   618,   815,  -840,
    -840,   822,   660,  -840,  -840,  -840,  -840,  -840,   357,  -840,
    -840,  4199,   821,  -840,  4199,    28,  -840,    64,  6728,  5960,
     710,  4199,  4199,    54,  -840,    96,   823,    18,   831,    20,
    -840,  -840,   832,   833,   834,   838,   840,  -840,  -840,  -840,
    -840,  5766,  5766,  -840,  -840,   680,  -840,  5766,   763,  5766,
    -840,  -840,  5766,   850,   844,   830,  -840,  -840,  -840,  -840,
    2687,   182,   836,   779,  -840,  -840,  -840,  -840,   573,  6728,
    -840,  -840,  -840,  -840,   414,  -840,   688,   700,  6728,  -840,
    -840,   853,   856,  -840,   857,  -840,  -840,   865,   866,  -840,
     876,   730,  -840,   869,  -840,   626,   870,   871,  -840,   874,
    6728,   739,   740,   743,   749,  -840,  -840,   880,  -840,  -840,
    -840,  6728,  6728,  -840,   727,  -840,   274,  -840,    54,  -840,
      54,  4199,  4199,   419,  -840,  -840,  -840,   701,  -840,   779,
      54,    54,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
    6728,   765,  -840,  -840,  2687,   408,  -840,  5766,  -840,   917,
     892,   908,   901,   473,   733,  -840,  2687,   151,  2687,  -840,
    -840,  -840,   902,   796,  5000,   891,   895,   785,  -840,  -840,
    -840,  -840,  -840,   913,  -840,   915,  -840,  -840,  -840,  -840,
     769,   770,   771,   772,  7087,  -840,   919,  -840,   313,   -14,
      54,    54,  6728,  5960,  -840,   861,   868,   497,   473,  -840,
    -840,  2687,   408,   742,   935,  6728,  -840,   473,  4415,   473,
    -840,   922,   835,  -840,   940,  6728,  6728,  6728,  -840,  -840,
    -840,  -840,  -840,  -840,  -840,  6728,   -14,  -840,   816,  -840,
    -840,  6728,  6728,   473,  -840,   945,  -840,   742,   947,  3335,
     824,  -840,   753,    54,  4199,   199,  6728,   127,   127,   818,
     948,  -840,  -840,   886,   890,   968,  -840,  -840,  -840,   962,
    4415,  -840,  -840,  -840,  -840,   690,  -840,   588,   588,   972,
     964,   964,   971,  4415,  -840,   747,   846,   864,   867,   918,
    -840,  -840,  -840,   852,   855,   931,  3767,   978,   982,  -840,
     983,    38,    67,  -840,   984,  -840,  -840,  -840,  -840,    55,
    -840,  6728,  6728,   995,   988,  6152,  6152,  -840,  -840,  -840,
     747,   872,  -840,   885,  -840,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     3,    10,     9,     8,     6,
       7,    29,    28,    27,    26,    49,    79,    52,    56,    58,
       0,     0,   468,   473,   521,   276,   485,   474,   481,   494,
     484,   477,   480,   522,   495,   523,   496,   284,   291,   376,
     486,   289,   516,   488,   520,   497,   493,   285,   377,   472,
     479,   491,   498,   492,   277,   278,   378,   375,   499,   487,
     478,   482,   524,   483,   500,   501,   514,   502,   519,   290,
     503,   504,   288,   515,   490,   505,   506,   507,   292,   508,
     509,   518,   286,   280,   281,   279,   517,   476,   475,   510,
     511,   489,   282,   283,   512,   374,   513,   525,   526,   527,
     528,   529,   379,   380,   381,   382,     0,    25,   534,   535,
     536,   146,   538,   537,   469,     0,     0,   105,   106,   104,
       0,     0,   462,     0,   505,    94,    96,    99,     0,     0,
       0,     0,     1,     2,     5,   104,     0,   104,   104,   539,
      80,   104,    79,    59,     0,     0,    69,     0,     0,   247,
     250,   248,   251,   249,   252,   253,     0,   258,   494,   522,
     523,   330,   332,     0,   254,     0,   524,     0,   334,   335,
     475,     0,   135,     0,     0,    61,    63,   218,     0,   107,
     110,   216,     0,   462,   204,   207,   209,   211,   213,   217,
     220,   221,   269,   534,   268,   535,   267,   266,   536,   139,
       0,     0,   588,   463,   465,   466,     0,    95,     0,     0,
       0,   100,     0,    11,   470,   408,     0,   431,   383,   426,
     427,   425,   384,   404,   410,     0,   413,   407,   406,     0,
       0,   446,   445,   409,   414,   506,   405,     0,   395,   511,
     530,   531,    14,   338,   341,   339,   340,   337,   360,   532,
     358,   359,   357,   396,   397,   353,   356,   355,   342,   533,
     471,     0,     4,     0,     0,     0,     0,     0,     0,   559,
     540,     0,   539,     0,    16,     0,     0,     0,     0,    19,
      21,    23,   168,   170,   172,   174,   177,   186,   179,   184,
     180,   182,   181,   183,   185,    24,   139,   147,     0,    37,
       0,     0,     0,    30,    39,    39,     0,     0,     0,     0,
     222,     0,   259,     0,     0,     0,     0,     0,   255,     0,
       0,     0,   256,     0,   214,   215,     0,    69,     0,     0,
     238,     0,     0,     0,   109,   205,   241,   242,     0,   246,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
      13,   464,    69,    46,     0,    97,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   412,     0,   373,   361,     0,   363,   370,   435,   433,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,   349,     0,   352,   354,     0,     0,
      54,    81,    83,    86,     0,    53,    55,   542,     0,    50,
     565,    57,   559,     0,     0,   222,     0,    62,   203,   173,
       0,     0,    15,     0,     0,     0,     0,     0,     0,   232,
     230,   231,   228,   229,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    35,    36,     0,    34,    31,
      39,    39,    69,     0,    60,     0,   219,     0,   264,   260,
       0,     0,     0,     0,   326,     0,   325,   368,     0,   366,
       0,   502,     0,     0,   462,    71,   111,   113,   115,   462,
     462,   144,   114,   152,   149,   150,   151,    67,   108,   322,
       0,   467,   239,   206,   208,   210,   212,   457,   458,     0,
       0,     0,     0,     0,   136,   140,    39,     0,     0,   101,
       0,     0,   568,     0,   429,     0,     0,   423,     0,     0,
     421,     0,   450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   443,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,    87,    88,    89,    82,     0,   548,
     558,   557,   556,     0,     0,   551,    51,   178,     0,    20,
      22,   169,   171,   226,   227,     0,   175,     0,   234,   235,
     236,     0,   224,   196,   200,     0,   201,   202,   198,   192,
       0,     0,     0,   237,   459,   461,   460,   188,   240,   189,
     140,   148,     0,    33,    32,    67,    60,   223,     0,     0,
       0,     0,   261,     0,   329,     0,   331,     0,     0,     0,
       0,     0,   144,   114,     0,     0,     0,   133,     0,   166,
     165,     0,   166,     0,     0,   166,     0,     0,   119,   526,
     117,   462,     0,     0,    72,   582,     0,    68,   323,   275,
     271,     0,     0,   287,   324,     0,    38,    47,    48,   103,
       0,     0,   572,   569,    12,     0,   430,   416,     0,     0,
     415,     0,     0,   451,   452,   456,   454,   455,   453,   449,
     448,   424,   403,     0,   401,     0,   411,     0,   362,     0,
       0,     0,     0,   441,     0,   436,     0,     0,   444,   399,
       0,     0,   387,   388,   389,   392,   393,   394,   419,     0,
     351,     0,    18,     0,    84,     0,    85,   544,   139,   543,
     549,     0,   546,   552,   553,   560,   561,   562,   554,   187,
     176,     0,     0,   199,     0,     0,   197,   194,     0,     0,
      72,     0,     0,   265,   257,     0,     0,     0,     0,     0,
     145,   116,     0,     0,     0,     0,     0,   134,   123,   125,
     118,     0,     0,   167,   162,     0,   163,     0,     0,     0,
     164,   112,     0,     0,     0,     0,   122,   124,   121,   120,
       0,   575,     0,    92,   581,   583,   274,   270,   273,   298,
     294,   293,   296,   137,   141,    64,     0,     0,     0,    98,
     573,     0,     0,   418,     0,   417,   447,     0,     0,   372,
       0,   369,   434,     0,   432,     0,     0,     0,   439,     0,
       0,     0,     0,     0,     0,   347,   350,   344,    17,    91,
      90,     0,     0,   550,     0,   541,     0,   555,   190,   225,
     193,     0,     0,   141,    44,    43,    40,    41,    45,    92,
     262,   263,   327,   328,   333,   367,   336,   130,   131,   132,
       0,     0,   159,   153,     0,     0,   161,     0,   154,     0,
       0,     0,     0,   580,   576,   578,     0,   104,     0,    65,
     272,   299,     0,   300,     0,     0,     0,     0,   428,   422,
     420,   402,   400,     0,   438,     0,   437,   442,   398,   346,
       0,     0,     0,     0,     0,   545,   140,   547,     0,     0,
     191,   195,     0,     0,    66,     0,     0,     0,   156,   158,
     160,     0,     0,   586,     0,     0,   577,   579,     0,    93,
     295,     0,    79,   138,   142,     0,     0,     0,   371,   440,
     385,   386,   390,   391,   345,     0,     0,   563,     0,   566,
      42,     0,     0,   155,   157,     0,   585,   586,     0,     0,
     285,    73,    74,    77,     0,   302,     0,    86,    86,     0,
     141,   567,   564,     0,     0,     0,   584,   129,    76,     0,
       0,   301,   305,   304,   297,     0,   143,    89,    89,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,   317,
     306,   310,   307,     0,     0,     0,     0,     0,     0,   587,
       0,     0,     0,   313,     0,   315,   309,   308,   311,     0,
     303,     0,     0,     0,     0,   462,   462,    78,   314,   316,
       0,     0,   319,     0,   320,   570,   571,   574,   128,   126,
     127,   312,   318,   321
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -840,  -840,    26,  -840,  -840,  -840,  -840,  -274,  -840,  -840,
     875,  -840,  -840,  -840,  -840,   703,  -840,  -840,  -275,    83,
    -840,   490,  -840,  -141,     0,   979,   125,   731,  -840,  -252,
    -264,  -840,  -840,  -840,   395,  -225,   708,   267,  -839,  -840,
    -150,  -840,  -368,  -840,  -481,  -498,   159,  -840,   -47,  -840,
    -840,  -153,  -507,  -120,  -155,  -840,   377,  -462,  -413,  -840,
     370,   372,    23,  -840,  -840,  -840,  -840,  -544,  -840,   944,
    -415,  -840,  -840,  -840,  -840,   383,  -246,  -266,   593,  -205,
    -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,  -840,
     437,  -840,   910,   684,   687,   686,   -76,  -840,  -302,   442,
     452,  -840,  -840,  -840,  -840,  -840,  -202,  -840,  -840,   572,
    -840,  -840,  -840,   171,   548,  -840,   764,  -533,  -840,   245,
    -840,  -840,  -840,  -840,  -840,  -840,    51,  -840,  -840,     9,
    -840,  -840,  -840,  -840,  -384,  -840,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,   513,  -840,   -62,  -840,  -840,  -840,  -840,
    -840,  -840,  -840,  -840,  -364,   355,  -840,  -840,  -840,  -186,
    -840,   841,  -253,    -2,  -393,  -840,  -129,  -840,  -840,   773,
    -840,  -840,  -681,  -840,  -840,   639,  -749,  -840,   319,  -840,
    -840,    97,  -840,  -840,  -840,  -840,  -840,  -840,   400,   399,
    -840,  -840,    91,   937
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,   288,   289,   290,
     116,    19,    20,    21,   313,   314,    22,    23,   458,   856,
     857,   362,   363,    24,    25,    26,    27,    28,   185,   186,
     484,   187,   522,    29,   654,   309,   337,   793,   971,   972,
     149,   150,   411,   412,   566,   726,   889,    30,   135,   136,
     220,   221,   366,   130,   188,   189,   485,   486,   487,   488,
     768,   769,  1017,   788,   489,   770,   190,   191,   490,   192,
     492,   493,   494,   495,   496,   647,   774,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     598,   304,   320,   194,   195,   196,   197,   198,   321,   593,
     586,   450,   343,   451,   348,   353,   199,   200,   323,   468,
     469,   621,   201,   202,   118,   204,   119,   663,   800,   801,
     892,   893,   942,   994,   995,  1009,  1023,  1011,  1012,  1024,
    1025,  1030,   206,   207,   252,   253,   254,   255,   256,   257,
     258,   384,   385,   478,   386,   120,   260,   261,   262,   263,
     264,   265,   266,   267,   533,   689,   690,   511,   608,   212,
     213,   214,   345,   306,   268,   122,   123,   270,   124,   279,
     280,   569,   729,   845,   732,   419,   735,   846,   573,   420,
     738,   959,   575,   672,   673,   809,   810,   886,   655,   656,
     657,   651,   966,   133
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,    31,   282,   317,   316,   121,   137,   344,   360,   158,
     456,   269,   406,   669,   407,   560,   315,   424,   631,   660,
     692,   428,   694,   471,   727,   273,   664,   276,   277,   548,
     798,   281,   864,   427,   866,   709,   139,   500,   219,   741,
     459,   340,   454,   819,   341,   851,   567,   623,   340,   783,
     580,   341,   340,   127,   340,   341,   340,   341,   340,   341,
     274,   341,   564,   340,   340,   633,   341,   341,   208,   340,
       1,   340,   341,   518,   341,   396,   340,   340,   259,   341,
     341,   429,   594,   340,   427,   771,   341,   217,   340,   785,
     340,   341,   208,   341,   594,   539,   208,   919,   372,   128,
     340,   957,   565,   341,   208,   208,  1041,   334,   335,   577,
     862,  1038,   497,   540,   744,   403,   583,   403,   125,   584,
     435,   208,   208,   121,   121,   438,   796,   797,   209,   578,
     215,   852,   137,  1042,   375,   562,   399,   516,   340,   121,
    1039,   341,   439,   440,   441,   442,   443,   444,   564,     1,
     958,  1004,   751,   307,   208,   612,   209,   424,   310,   579,
     915,  1027,  1043,   617,  1020,   390,   319,   127,   631,   956,
     272,   365,   765,   766,  -146,   461,   358,   387,   373,   775,
     772,   592,   595,   498,   445,   613,   614,   609,   565,     1,
    1028,   215,   446,   427,     5,   724,   625,   447,   404,   427,
     404,   618,   126,   311,  1044,   858,   131,   275,   349,   215,
     448,   435,   208,   128,   376,   633,   137,   367,   585,   129,
     693,   208,   695,   140,   208,   342,   397,   398,   427,   765,
     766,   582,   342,   784,  -365,   710,   342,   615,   342,   755,
     342,   666,   342,   820,   374,   391,   208,   342,   342,   465,
     208,   138,   -59,   342,   968,   342,   208,   596,   597,   541,
     342,   342,   208,   208,   208,   890,   627,   342,   208,   596,
     597,   479,   342,     5,   342,   141,   208,   208,   506,   269,
     377,   208,     5,   319,   342,   143,   208,   400,   401,   742,
     542,   208,   208,   208,   142,   208,   583,   727,   637,   584,
       8,   897,   312,   648,   650,   269,   153,   -59,   367,     8,
      31,   392,   -59,     5,   812,   144,   465,   814,   463,    49,
     879,   449,   342,   350,   992,   -59,   346,   347,   837,   351,
     352,   151,   993,   312,   121,   145,   209,   592,   600,   121,
       8,  -146,   827,   452,     1,    58,   259,   208,   154,   427,
     683,   405,   208,   155,   684,   -59,   515,   341,   872,   873,
       2,   208,   570,    66,   876,    67,   878,   571,   572,   208,
     543,   208,   259,   208,   208,   884,   208,   210,   427,   858,
     670,   885,   683,   146,   839,   208,   684,   840,   208,   427,
       3,   727,   -59,   121,   427,   208,   776,   601,   410,   780,
     383,   415,   416,   208,   216,   208,   733,   734,   218,   589,
     602,   590,   388,   389,   -59,     4,  -147,   -59,   665,   -59,
     147,   219,  -147,   463,   748,   685,   319,  -148,   688,   894,
     105,    49,  -148,   223,   922,   222,   544,   278,   977,   978,
     686,   652,   653,   308,   687,   733,   734,   148,   324,   208,
     610,   611,   730,   731,   918,   208,   208,    58,   806,   807,
     688,   905,   736,   737,   930,   789,   325,   836,     5,   326,
       6,   112,   113,   114,   115,    66,   479,    67,   121,   327,
     319,   638,   215,   328,   767,   329,     7,   215,   215,   831,
     832,   833,   834,   330,   269,     8,   997,   998,   639,  1013,
    1014,   208,   331,   332,   333,   640,   336,   338,   639,   339,
     355,   354,   477,   777,   356,   640,   642,   357,   367,   427,
     427,   954,   368,   641,   883,   427,   642,   427,   438,   208,
     427,     9,   369,    10,    11,   638,   643,   370,   208,   371,
     208,   340,   105,    12,   341,   439,   440,   441,   442,   443,
     444,   644,   378,   645,   379,   380,   382,   121,   208,   393,
     381,   259,   639,   645,   394,   208,   728,   208,   395,   640,
     402,   341,   409,   408,   418,   414,   417,   641,   426,   431,
     642,   432,   434,   112,   113,   114,   115,   445,   433,   435,
     643,   319,   269,   436,   453,   446,   437,   455,   457,   464,
     447,   466,   473,   467,   474,   644,   476,   502,   928,   512,
     517,   520,   519,   448,   521,   523,   525,   645,   524,   526,
     937,   527,   939,   121,   529,   427,   528,   530,   121,   531,
     463,   532,   121,   121,   121,   534,   535,   536,   537,   121,
     538,   545,   546,   549,   121,   551,   646,   547,   552,   215,
     553,   554,   557,   752,   558,   574,   559,   563,   555,   259,
     802,   556,   568,   804,   588,   963,   591,   159,   160,   161,
     162,   163,   991,   164,   165,   603,   616,   628,   203,   208,
     624,   620,   208,   626,   629,   634,   635,   636,   250,   208,
     208,   658,   659,   662,   159,   160,   161,   162,   163,   674,
     164,   165,   203,   671,   675,   678,   203,   676,   677,   679,
     682,   680,   681,  1005,   203,   203,   691,   173,   697,   699,
     696,   174,   929,   700,   449,   342,   702,   713,   208,   638,
     701,   203,   203,   703,   705,   704,   706,   707,   708,   711,
     712,  1006,   715,   718,   173,   714,   853,   728,   174,   716,
     717,   159,   160,   161,   162,   163,   639,   164,   165,   719,
     721,   725,   723,   640,   203,   722,   739,   938,   749,   121,
     121,   641,   754,   758,   642,   121,   760,   121,   773,   964,
     121,   761,   779,   791,   643,   269,   782,    35,   792,   208,
     208,   790,   975,  1008,   874,   652,   805,   802,  1006,   644,
     653,   173,   808,  1022,   811,   174,   367,   813,   815,   817,
     818,   645,   208,    47,   359,   821,   822,   823,   826,   829,
     824,   825,   203,   828,   208,   835,   208,   843,   121,   844,
     842,   203,   841,   830,   203,   849,   875,   863,  1022,   728,
     916,   359,   838,  1007,    57,   865,   867,   868,   869,  1049,
    1050,   870,   259,   871,   877,   880,   203,   881,   882,   888,
     203,  1034,    64,    65,   887,   895,   203,   898,   925,   208,
     899,   900,   203,   203,   203,   121,   208,   896,   203,   901,
     902,   903,  -364,   904,   906,   907,   203,   203,   908,   910,
     911,   203,   944,   912,   205,   914,   203,   917,   359,   913,
    1021,   203,   203,   203,   251,   203,   933,   208,    92,    93,
      94,    95,   208,   934,   935,   923,   940,   941,   205,   945,
     944,   728,   205,   946,   947,   102,   103,   948,   208,   949,
     205,   205,   936,   728,   955,   961,   950,   951,   952,   953,
     965,   208,   962,   367,   367,   979,   117,   205,   205,   967,
     974,   132,   146,   980,   208,   976,   250,   203,   985,   983,
     984,   987,   203,   922,   989,   982,   638,   990,  1000,   319,
     999,   203,  1001,  1002,   996,  1003,  1015,  1016,  1026,   203,
     205,   203,   250,   203,   203,  1019,   203,  1027,  1029,  1033,
    1028,  1031,  1035,   639,  1032,   203,  1036,  1037,   203,  1047,
     640,  1040,  1048,  1053,  1052,   203,   960,   667,   641,   152,
     750,   642,   421,   203,   209,   203,   271,   859,   924,   460,
     786,   643,   787,   781,  1018,   462,   778,   503,   581,  1045,
    1046,   931,   743,   215,   215,   504,   644,   740,   205,   505,
     193,   622,   926,   746,   891,   816,  1010,   205,   645,  1051,
     205,   698,   361,   981,   794,   422,   795,   847,   986,   203,
       0,   576,   156,     0,   305,   203,   203,     0,   193,   132,
     157,     0,   205,   932,     0,     0,   205,   322,     0,     0,
       0,     0,   205,     0,     0,   117,     0,     0,   205,   205,
     205,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,   205,   205,     0,     0,     0,   205,     0,     0,
       0,   203,   205,     0,     0,     0,     0,   205,   205,   205,
       0,   205,     0,     0,     0,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
       0,     0,     0,     0,     0,   438,     0,     0,   203,     0,
     203,     0,     0,     0,     0,     0,     0,     0,   340,     0,
       0,   341,   439,   440,   441,   442,   443,   444,   203,     0,
       0,   250,   251,   205,     0,   203,     0,   203,   205,     0,
       0,     0,     0,     0,   413,     0,     0,   205,     0,     0,
       0,     0,     0,   425,     0,   205,   430,   205,   251,   205,
     205,     0,   205,     0,   445,     0,     0,     0,     0,     0,
       0,   205,   446,     0,   205,     0,     0,   447,   430,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,   205,
     448,   205,     0,     0,   470,     0,   472,     0,     0,     0,
     475,     0,     0,     0,     0,     0,     0,     0,   193,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,     0,   513,     0,   250,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
     491,   205,   205,     0,     0,   501,     0,     0,     0,   203,
       0,     0,   203,     0,     0,     0,     0,     0,     0,   203,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   305,
       0,     0,     0,     0,   413,     0,     0,   205,     0,     0,
       0,     0,     0,   425,     0,     0,     0,     0,   203,   550,
       0,   449,   342,   305,     0,   430,   430,     0,   587,     0,
       0,     0,     0,     0,     0,   205,     0,   599,     0,     0,
     607,     0,     0,     0,   205,     0,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   619,     0,     0,
       0,     0,     0,     0,   205,     0,     0,   251,     0,     0,
       0,   205,     0,   205,     0,     0,     0,     0,     0,   203,
     203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   927,
       0,   661,   203,     0,   632,     0,     0,   364,   668,     0,
       0,     0,     0,     0,   203,     0,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,     0,     0,     0,     0,     0,   203,
       0,     0,     0,     0,     0,   251,   203,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   720,     0,   205,     0,     0,   205,     0,
     745,     0,   747,     0,     0,   205,   205,   203,     0,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,     0,
     753,     0,     0,     0,     0,     0,     0,   757,   203,   759,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,     0,     0,     0,     0,   756,
       0,     0,     0,     0,   632,     0,     0,     0,   762,   763,
     764,     0,     0,     0,     0,   491,     0,     0,     0,     0,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   848,   205,     0,   850,     0,     0,     0,     0,     0,
       0,   860,   861,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,     0,     0,
     430,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   491,     0,     0,     0,
       0,   491,     0,   491,     0,     0,   491,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,   205,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   205,     0,     0,     0,     0,     0,
       0,   920,   921,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,   909,     0,     0,     0,     0,     0,
     205,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   430,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   491,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,   430,     0,     0,     0,     0,     0,     0,   973,     0,
      33,   211,    34,    35,     0,    36,    37,    38,     0,     0,
       0,     0,    39,     0,    40,    41,    42,   340,    43,    44,
     341,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
     973,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,   973,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,     0,   193,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,     0,
      72,    73,    74,    75,    76,     0,    77,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,     0,    87,     0,    88,    89,    90,     0,     0,
       0,    91,     0,     0,    92,    93,    94,    95,     0,     0,
      96,    97,    98,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,   109,   110,   111,     0,     0,     0,   112,   113,
     114,   115,    32,   159,   160,   161,   162,   163,     0,   164,
     165,   342,   423,     0,     0,     0,     0,     0,    33,     0,
      34,    35,     0,    36,    37,    38,     0,     0,     0,   167,
     168,     0,    40,    41,    42,     0,   169,    44,     0,     0,
       0,     0,     0,     0,     0,   170,    46,    47,     0,    48,
       0,   171,   172,   173,    49,    50,     0,   174,     0,    51,
      52,     0,    53,     0,     0,     0,     0,     0,     0,    54,
     285,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,    59,     0,     0,    60,     0,     0,
       0,    61,    62,   175,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,     0,   286,   176,    73,
      74,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,    79,    80,    81,     0,    82,    83,    84,    85,    86,
     177,    87,     0,    88,    89,    90,     5,   178,     0,    91,
       0,     0,    92,    93,    94,    95,   179,     0,    96,    97,
     180,     0,    99,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     8,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,     0,     0,   181,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,   183,   184,    32,   159,
     160,   161,   162,   163,     0,   164,   165,     0,   283,   284,
       0,     0,     0,     0,    33,     0,    34,    35,     0,    36,
      37,    38,     0,     0,     0,   167,   168,     0,    40,    41,
      42,     0,   169,    44,     0,     0,     0,     0,     0,     0,
       0,   170,    46,    47,     0,    48,     0,   171,   172,   173,
      49,    50,     0,   174,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,   285,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,   175,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,   286,   176,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,    85,    86,   177,    87,     0,    88,
      89,    90,     0,   178,     0,    91,     0,     0,    92,    93,
      94,    95,   179,     0,    96,    97,   180,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,   109,   110,   111,     0,
       0,   181,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,   183,   184,    32,   159,   160,   161,   162,   163,
       0,   164,   165,     0,   283,   561,     0,     0,     0,     0,
      33,     0,    34,    35,     0,    36,    37,    38,     0,     0,
       0,   167,   168,     0,    40,    41,    42,     0,   169,    44,
       0,     0,     0,     0,     0,     0,     0,   170,    46,    47,
       0,    48,     0,   171,   172,   173,    49,    50,     0,   174,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
       0,    54,   285,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,   175,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,   286,
     176,    73,    74,    75,    76,     0,    77,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,   177,    87,     0,    88,    89,    90,     0,   178,
       0,    91,     0,     0,    92,    93,    94,    95,   179,     0,
      96,    97,   180,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     0,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,   109,   110,   111,     0,     0,   181,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,   183,   184,
      32,   159,   160,   161,   162,   163,     0,   164,   165,     0,
     283,     0,     0,     0,     0,     0,    33,     0,    34,    35,
       0,    36,    37,    38,     0,     0,     0,   167,   168,     0,
      40,    41,    42,     0,   169,    44,     0,     0,     0,     0,
       0,     0,     0,   170,    46,    47,     0,    48,     0,   171,
     172,   173,    49,    50,     0,   174,     0,    51,    52,     0,
      53,     0,     0,     0,     0,     0,     0,    54,   285,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,    59,     0,     0,    60,     0,     0,     0,    61,
      62,   175,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,     0,   286,   176,    73,    74,    75,
      76,     0,    77,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,    84,    85,    86,   177,    87,
       0,    88,    89,    90,     0,   178,     0,    91,     0,     0,
      92,    93,    94,    95,   179,     0,    96,    97,   180,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     0,   181,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,   183,   184,    32,   159,   160,   161,
     162,   163,     0,   164,   165,     0,   166,     0,     0,   507,
       0,     0,    33,     0,    34,    35,     0,    36,    37,    38,
       0,     0,     0,   167,   168,     0,    40,    41,    42,     0,
     169,    44,     0,     0,     0,     0,     0,     0,     0,   170,
      46,    47,     0,    48,     0,   171,   172,   173,    49,    50,
       0,   174,     0,    51,    52,   508,    53,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,    59,     0,
       0,    60,     0,     0,     0,    61,    62,   175,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
       0,     0,   176,    73,    74,    75,    76,     0,    77,     0,
       0,    78,     0,     0,     0,    79,    80,    81,     0,    82,
      83,    84,    85,    86,   177,    87,     0,    88,    89,    90,
       0,   178,     0,    91,     0,     0,    92,    93,    94,    95,
     179,     0,    96,    97,   180,     0,    99,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,   109,   110,   111,     0,     0,   181,
     112,   113,   114,   115,     0,     0,     0,     0,   509,     0,
     183,   184,    32,   159,   160,   161,   162,   163,     0,   164,
     165,     0,   166,     0,     0,   604,     0,   605,    33,     0,
      34,    35,     0,    36,    37,    38,     0,     0,     0,   167,
     168,     0,    40,    41,    42,     0,   169,    44,     0,     0,
       0,     0,     0,     0,     0,   170,    46,    47,     0,    48,
       0,   171,   172,   173,    49,    50,     0,   174,     0,    51,
      52,     0,    53,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,    59,     0,     0,    60,     0,     0,
       0,    61,    62,   175,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,     0,     0,   176,    73,
      74,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,    79,    80,    81,     0,    82,    83,    84,    85,    86,
     177,    87,     0,    88,    89,    90,     0,   178,     0,    91,
       0,   606,    92,    93,    94,    95,   179,     0,    96,    97,
     180,     0,    99,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,     0,     0,   181,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,   183,   184,    32,   159,
     160,   161,   162,   163,     0,   164,   165,     0,   318,   988,
       0,     0,     0,     0,    33,     0,    34,    35,     0,    36,
      37,    38,     0,     0,     0,   167,   168,     0,    40,    41,
      42,     0,   169,    44,     0,     0,     0,     0,     0,     0,
       0,   170,    46,    47,     0,    48,     0,   171,   172,   173,
      49,    50,     0,   174,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,    57,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,   175,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,     0,   176,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,    85,    86,   177,    87,     0,    88,
      89,    90,     5,   178,     0,    91,     0,     0,    92,    93,
      94,    95,   179,     0,    96,    97,   180,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     8,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,   109,   110,   111,     0,
       0,   181,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,   183,   184,    32,   159,   160,   161,   162,   163,
       0,   164,   165,     0,   318,     0,     0,     0,     0,     0,
      33,     0,    34,    35,     0,    36,    37,    38,     0,     0,
       0,   167,   168,     0,    40,    41,    42,     0,   169,    44,
       0,     0,     0,     0,     0,     0,     0,   170,    46,    47,
       0,    48,     0,   171,   172,   173,    49,    50,     0,   174,
       0,    51,    52,     0,    53,     0,     0,     0,     0,     0,
       0,    54,     0,     0,    55,     0,     0,     0,    56,     0,
      57,     0,    58,     0,     0,     0,    59,     0,     0,    60,
       0,     0,     0,    61,    62,   175,     0,    63,    64,    65,
      66,     0,    67,    68,    69,     0,    70,    71,     0,     0,
     176,    73,    74,    75,    76,     0,    77,     0,     0,    78,
       0,     0,     0,    79,    80,    81,     0,    82,    83,    84,
      85,    86,   177,    87,     0,    88,    89,    90,     5,   178,
       0,    91,     0,     0,    92,    93,    94,    95,   179,     0,
      96,    97,   180,     0,    99,     0,     0,     0,     0,   100,
     101,   102,   103,     0,     0,     8,   104,   105,   106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
       0,     0,   109,   110,   111,     0,     0,   181,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,   183,   184,
      32,   159,   160,   161,   162,   163,     0,   164,   165,     0,
     166,     0,     0,     0,     0,     0,    33,     0,    34,    35,
       0,    36,    37,    38,     0,     0,     0,   167,   168,     0,
      40,    41,    42,     0,   169,    44,     0,     0,     0,     0,
       0,     0,     0,   170,    46,    47,     0,    48,     0,   171,
     172,   173,    49,    50,     0,   174,     0,    51,    52,     0,
      53,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,    59,     0,     0,    60,     0,     0,     0,    61,
      62,   175,     0,    63,    64,    65,    66,     0,    67,    68,
      69,     0,    70,    71,     0,     0,   176,    73,    74,    75,
      76,     0,    77,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,    84,    85,    86,   177,    87,
       0,    88,    89,    90,     0,   178,     0,    91,     0,     0,
      92,    93,    94,    95,   179,     0,    96,    97,   180,     0,
      99,     0,     0,     0,     0,   100,   101,   102,   103,     0,
       0,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     0,   181,   112,   113,   114,   115,     0,     0,
       0,     0,   182,     0,   183,   184,    32,   159,   160,   161,
     162,   163,     0,   164,   165,     0,   166,   499,     0,     0,
       0,     0,    33,     0,    34,    35,     0,    36,    37,    38,
       0,     0,     0,   167,   168,     0,    40,    41,    42,     0,
     169,    44,     0,     0,     0,     0,     0,     0,     0,   170,
      46,    47,     0,    48,     0,   171,   172,   173,    49,    50,
       0,   174,     0,    51,    52,     0,    53,     0,     0,     0,
       0,     0,     0,    54,     0,     0,    55,     0,     0,     0,
      56,     0,    57,     0,    58,     0,     0,     0,    59,     0,
       0,    60,     0,     0,     0,    61,    62,   175,     0,    63,
      64,    65,    66,     0,    67,    68,    69,     0,    70,    71,
       0,     0,   176,    73,    74,    75,    76,     0,    77,     0,
       0,    78,     0,     0,     0,    79,    80,    81,     0,    82,
      83,    84,    85,    86,   177,    87,     0,    88,    89,    90,
       0,   178,     0,    91,     0,     0,    92,    93,    94,    95,
     179,     0,    96,    97,   180,     0,    99,     0,     0,     0,
       0,   100,   101,   102,   103,     0,     0,     0,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,   109,   110,   111,     0,     0,   181,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
     183,   184,    32,   159,   160,   161,   162,   163,     0,   164,
     165,     0,   166,     0,     0,     0,     0,     0,    33,     0,
      34,    35,     0,    36,    37,    38,     0,     0,     0,   167,
     168,     0,    40,    41,    42,     0,   169,    44,     0,     0,
       0,     0,     0,     0,     0,   170,    46,    47,     0,    48,
       0,   171,   172,   173,    49,    50,     0,   174,     0,    51,
      52,     0,    53,     0,     0,     0,     0,     0,     0,    54,
       0,     0,    55,     0,     0,     0,    56,     0,    57,     0,
      58,     0,     0,     0,    59,     0,     0,    60,     0,     0,
       0,    61,    62,   175,     0,    63,    64,    65,    66,     0,
      67,    68,    69,     0,    70,    71,     0,     0,   176,    73,
      74,    75,    76,     0,    77,     0,     0,    78,     0,     0,
       0,    79,    80,    81,     0,    82,    83,    84,    85,    86,
     177,    87,     0,    88,    89,    90,     0,   178,     0,    91,
       0,     0,    92,    93,    94,    95,   179,     0,    96,    97,
     180,     0,    99,     0,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
     109,   110,   111,     0,     0,   181,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,   183,   184,    32,   159,
     160,   161,   162,   163,     0,   164,   165,     0,   969,     0,
       0,     0,     0,     0,    33,     0,    34,    35,     0,    36,
      37,    38,     0,     0,     0,   167,   168,     0,    40,    41,
      42,     0,   169,    44,     0,     0,     0,     0,     0,     0,
       0,   170,    46,    47,     0,    48,     0,   171,   172,   173,
      49,    50,     0,   174,     0,    51,    52,     0,    53,     0,
       0,     0,     0,     0,     0,    54,     0,     0,    55,     0,
       0,     0,    56,     0,   970,     0,    58,     0,     0,     0,
      59,     0,     0,    60,     0,     0,     0,    61,    62,   175,
       0,    63,    64,    65,    66,     0,    67,    68,    69,     0,
      70,    71,     0,     0,   176,    73,    74,    75,    76,     0,
      77,     0,     0,    78,     0,     0,     0,    79,    80,    81,
       0,    82,    83,    84,    85,    86,   177,    87,     0,    88,
      89,    90,     0,   178,     0,    91,     0,     0,    92,    93,
      94,    95,   179,     0,    96,    97,   180,     0,    99,     0,
       0,     0,     0,   100,   101,   102,   103,     0,     0,     0,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,     0,     0,     0,     0,   109,   110,   111,    32,
       0,   181,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,   183,   184,     0,    33,     0,    34,    35,     0,
      36,    37,    38,     0,     0,     0,     0,    39,     0,    40,
      41,    42,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,     0,     0,    72,    73,    74,    75,    76,
       0,    77,     0,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,     0,    87,     0,
      88,    89,    90,     0,     0,     0,    91,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,   108,     0,     0,     0,     0,   109,   110,   111,
       0,     0,     0,   112,   113,   114,   115,    33,     0,    34,
      35,   514,    36,    37,    38,     0,     0,     0,     0,    39,
       0,    40,    41,    42,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,    45,    46,    47,     0,    48,     0,
       0,     0,     0,    49,    50,     0,     0,     0,    51,    52,
       0,    53,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
       0,     0,     0,    59,     0,     0,    60,     0,     0,     0,
      61,    62,     0,     0,    63,    64,    65,    66,     0,    67,
      68,    69,     0,    70,    71,     0,     0,    72,    73,    74,
      75,    76,     0,    77,     0,     0,    78,     0,     0,     0,
      79,    80,    81,     0,    82,    83,    84,    85,    86,     0,
      87,     0,    88,    89,    90,     0,     0,     0,    91,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
       0,    99,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,   108,     0,     0,     0,     0,   109,
     110,   111,     0,     0,     0,   112,   113,   114,   115,    33,
       0,    34,    35,   803,    36,    37,    38,     0,     0,     0,
       0,    39,     0,    40,    41,    42,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,     0,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,     0,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,     0,    72,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,     0,    87,     0,    88,    89,    90,     0,     0,     0,
      91,     0,     0,    92,    93,    94,    95,     0,     0,    96,
      97,    98,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,   108,     0,     0,     0,
       0,   109,   110,   111,     0,   630,     0,   112,   113,   114,
     115,    33,     0,    34,    35,   943,    36,    37,    38,     0,
       0,     0,     0,    39,     0,    40,    41,    42,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      47,     0,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,    59,     0,     0,
      60,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,     0,
       0,    72,    73,    74,    75,    76,     0,   481,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
      84,    85,    86,     0,    87,     0,    88,    89,    90,     5,
       0,     0,    91,     0,     0,    92,    93,    94,    95,     0,
       0,    96,    97,    98,     0,    99,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     8,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,   482,   483,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     0,     0,   112,
     113,   114,   115,    34,    35,     0,   225,   226,   227,   228,
       0,     0,     0,    39,   229,   230,     0,   231,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      47,     0,    48,     0,     0,     0,   232,    49,   233,   234,
       0,     0,    51,    52,     0,   235,     0,     0,     0,     0,
       0,     0,    54,     0,   236,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,   237,   238,     0,
     239,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,   240,     0,   241,   242,     0,
       0,    72,   243,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
     244,    85,   245,     0,    87,     0,    88,    89,    90,     0,
       0,     0,    91,   246,     0,    92,    93,    94,    95,     0,
       0,    96,   247,   248,     0,    99,     0,     0,     0,     0,
     249,     0,   102,   103,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     1,     0,   112,
     113,   114,   115,    33,     0,    34,    35,     0,    36,    37,
      38,     0,     0,     0,     0,    39,     0,    40,    41,    42,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
      45,    46,    47,     0,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,    51,    52,     0,    53,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,    59,
       0,     0,    60,     0,     0,     0,    61,    62,     0,     0,
      63,    64,    65,    66,     0,    67,    68,    69,     0,    70,
      71,     0,     0,    72,    73,    74,    75,    76,     0,    77,
       0,     0,    78,     0,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    86,     0,    87,     0,    88,    89,
      90,     5,     0,     0,    91,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,     0,    99,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     8,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
     108,     0,     0,     0,     0,   109,   110,   111,     0,   480,
       0,   112,   113,   114,   115,    33,     0,    34,    35,     0,
      36,    37,    38,     0,     0,     0,     0,    39,     0,    40,
      41,    42,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,     0,     0,    72,    73,    74,    75,    76,
       0,   481,     0,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,     0,    87,     0,
      88,    89,    90,     0,     0,     0,    91,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,   483,   108,    32,     0,     0,     0,   109,   110,   111,
     854,   855,     0,   112,   113,   114,   115,     0,     0,    33,
       0,    34,    35,     0,    36,    37,    38,     0,     0,     0,
       0,    39,     0,    40,    41,    42,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,     0,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,     0,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,     0,    72,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,     0,    87,     0,    88,    89,    90,     0,     0,     0,
      91,     0,     0,    92,    93,    94,    95,     0,     0,    96,
      97,    98,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,   108,     0,     0,     0,
       0,   109,   110,   111,     0,     0,     0,   112,   113,   114,
     115,    33,   211,    34,    35,     0,    36,    37,    38,     0,
       0,     0,     0,    39,     0,    40,    41,    42,     0,    43,
      44,     0,     0,     0,     0,     0,     0,     0,    45,    46,
      47,     0,    48,     0,     0,     0,     0,    49,    50,     0,
       0,     0,    51,    52,     0,    53,     0,     0,     0,     0,
       0,     0,    54,     0,     0,    55,     0,     0,     0,    56,
       0,    57,     0,    58,     0,     0,     0,    59,     0,     0,
      60,     0,     0,     0,    61,    62,     0,     0,    63,    64,
      65,    66,     0,    67,    68,    69,     0,    70,    71,     0,
       0,    72,    73,    74,    75,    76,     0,    77,     0,     0,
      78,     0,     0,     0,    79,    80,    81,     0,    82,    83,
      84,    85,    86,     0,    87,     0,    88,    89,    90,     0,
       0,     0,    91,     0,     0,    92,    93,    94,    95,     0,
       0,    96,    97,    98,     0,    99,     0,     0,     0,     0,
     100,   101,   102,   103,     0,     0,     0,   104,   105,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,   108,     0,
       0,     0,     0,   109,   110,   111,     0,     0,     0,   112,
     113,   114,   115,    33,   211,    34,    35,     0,    36,    37,
      38,     0,     0,     0,     0,    39,     0,    40,    41,    42,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
      45,    46,    47,     0,    48,     0,     0,     0,     0,    49,
      50,     0,     0,     0,    51,    52,     0,    53,     0,     0,
       0,     0,     0,     0,    54,     0,     0,    55,     0,     0,
       0,    56,     0,    57,     0,    58,     0,     0,     0,    59,
       0,     0,    60,     0,     0,     0,    61,    62,     0,     0,
      63,    64,    65,    66,     0,    67,    68,    69,     0,    70,
      71,     0,     0,    72,    73,    74,    75,    76,     0,    77,
       0,     0,    78,     0,     0,     0,    79,    80,    81,     0,
      82,    83,    84,    85,    86,     0,    87,     0,    88,    89,
      90,     0,     0,     0,    91,     0,     0,    92,    93,    94,
      95,     0,     0,    96,    97,    98,     0,    99,     0,     0,
       0,     0,   100,   101,   102,   103,     0,     0,     0,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
     649,     0,     0,     0,     0,   109,   110,   111,     0,   799,
       0,   112,   113,   114,   115,    33,     0,    34,    35,     0,
      36,    37,    38,     0,     0,     0,     0,    39,     0,    40,
      41,    42,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,    46,    47,     0,    48,     0,     0,     0,
       0,    49,    50,     0,     0,     0,    51,    52,     0,    53,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
       0,     0,     0,    56,     0,    57,     0,    58,     0,     0,
       0,    59,     0,     0,    60,     0,     0,     0,    61,    62,
       0,     0,    63,    64,    65,    66,     0,    67,    68,    69,
       0,    70,    71,     0,     0,    72,    73,    74,    75,    76,
       0,    77,     0,     0,    78,     0,     0,     0,    79,    80,
      81,     0,    82,    83,    84,    85,    86,     0,    87,     0,
      88,    89,    90,     0,     0,     0,    91,     0,     0,    92,
      93,    94,    95,     0,     0,    96,    97,    98,     0,    99,
       0,     0,     0,     0,   100,   101,   102,   103,     0,     0,
       0,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,   108,     0,     0,     0,     0,   109,   110,   111,
       0,     0,     0,   112,   113,   114,   115,    33,     0,    34,
      35,     0,    36,    37,    38,     0,     0,     0,     0,    39,
       0,    40,    41,    42,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,    45,    46,    47,     0,    48,     0,
       0,     0,     0,    49,    50,     0,     0,     0,    51,    52,
       0,    53,     0,     0,     0,     0,     0,     0,    54,     0,
       0,    55,     0,     0,     0,    56,     0,    57,     0,    58,
       0,     0,     0,    59,     0,     0,    60,     0,     0,     0,
      61,    62,     0,     0,    63,    64,    65,    66,     0,    67,
      68,    69,     0,    70,    71,     0,     0,    72,    73,    74,
      75,    76,     0,    77,     0,     0,    78,     0,     0,     0,
      79,    80,    81,     0,    82,    83,    84,    85,    86,     0,
      87,     0,    88,    89,    90,     0,     0,     0,    91,     0,
       0,    92,    93,    94,    95,     0,     0,    96,    97,    98,
       0,    99,     0,     0,     0,     0,   100,   101,   102,   103,
       0,     0,     0,   104,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,   108,     0,     0,     0,     0,   109,
     110,   111,     0,     0,     0,   112,   113,   114,   115,    33,
       0,    34,    35,     0,    36,    37,    38,     0,     0,     0,
       0,    39,     0,    40,    41,    42,     0,    43,    44,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,     0,
      48,     0,     0,     0,     0,    49,    50,     0,     0,     0,
      51,    52,     0,    53,     0,     0,     0,     0,     0,     0,
      54,     0,     0,    55,     0,     0,     0,    56,     0,    57,
       0,    58,     0,     0,     0,    59,     0,     0,    60,     0,
       0,     0,    61,    62,     0,     0,    63,    64,    65,    66,
       0,    67,    68,    69,     0,    70,    71,     0,     0,    72,
      73,    74,    75,    76,     0,    77,     0,     0,    78,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,   134,
      86,     0,    87,     0,    88,    89,    90,     0,     0,     0,
      91,     0,     0,    92,    93,    94,    95,     0,     0,    96,
      97,    98,     0,    99,     0,     0,     0,     0,   100,   101,
     102,   103,     0,     0,     0,   104,   105,   106,     0,     0,
     224,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
       0,     0,     0,     0,     0,     0,   108,     0,    39,     0,
       0,   109,   110,   111,    43,    44,     0,   112,   113,   114,
     115,     0,     0,    45,    46,    47,     0,    48,     0,     0,
       0,     0,    49,     0,     0,     0,     0,    51,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
      55,     0,     0,     0,    56,     0,    57,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     0,     0,    63,    64,    65,    66,     0,    67,    68,
       0,     0,     0,     0,     0,     0,    72,     0,    74,    75,
      76,     0,    77,     0,     0,    78,     0,     0,     0,    79,
      80,    81,     0,    82,    83,     0,    85,    86,     0,    87,
       0,    88,    89,    90,     0,     0,     0,    91,     0,     0,
      92,    93,    94,    95,     0,     0,    96,     0,     0,     0,
      99,     0,     0,     0,     0,   100,     0,   102,   103,     0,
       0,     0,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,   109,   110,
     111,     0,     0,     0,   112,   113,   114,   115
};

static const yytype_int16 yycheck[] =
{
       2,     1,   152,   158,   157,     7,     8,   193,   210,   129,
     312,   140,   265,   520,   267,   408,   157,   283,   480,    14,
      14,   285,    14,   325,   568,   145,    14,   147,   148,   393,
      14,   151,    14,   285,    14,    14,    10,   339,    13,    17,
     315,    36,   308,    14,    39,    17,   414,    20,    36,    13,
     434,    39,    36,    16,    36,    39,    36,    39,    36,    39,
      28,    39,    21,    36,    36,   480,    39,    39,   130,    36,
      13,    36,    39,    40,    39,    13,    36,    36,   140,    39,
      39,   286,     8,    36,   336,    91,    39,   134,    36,   121,
      36,    39,   154,    39,     8,    13,   158,   846,    13,    62,
      36,   115,    61,    39,   166,   167,    51,   183,   184,    14,
      14,    73,   337,    13,    67,    19,     6,    19,    75,     9,
     116,   183,   184,   125,   126,    23,   659,   660,   130,   431,
     132,    67,   134,    78,    13,   409,    13,   362,    36,   141,
      73,    39,    40,    41,    42,    43,    44,    45,    21,    13,
     164,   990,   148,   155,   216,   457,   158,   423,    13,   433,
     841,   123,   107,   465,  1003,    13,   166,    16,   630,   918,
     144,   218,   204,   205,    13,   316,    15,   239,    93,   641,
     186,   445,   108,   338,    82,   460,   461,   451,    61,    13,
     123,   193,    90,   445,   137,   563,   156,    95,   102,   451,
     102,   467,    89,    58,   149,   749,     3,   175,   100,   211,
     108,   116,   274,    62,    93,   630,   218,   219,   108,   182,
     214,   283,   214,     3,   286,   220,   164,   165,   480,   204,
     205,   436,   220,   197,   152,   214,   220,   462,   220,   623,
     220,   516,   220,   214,   159,    93,   308,   220,   220,   214,
     312,   201,    14,   220,   935,   220,   318,   183,   184,   159,
     220,   220,   324,   325,   326,   798,   214,   220,   330,   183,
     184,   333,   220,   137,   220,    29,   338,   339,   354,   408,
     159,   343,   137,   283,   220,    66,   348,   164,   165,   591,
      13,   353,   354,   355,     0,   357,     6,   841,   484,     9,
     164,   808,   157,   489,   490,   434,    14,    69,   310,   164,
     310,   159,    74,   137,   678,   211,   214,   681,   318,    55,
     782,   219,   220,   215,   125,    87,   217,   218,   721,   221,
     222,    87,   133,   157,   336,    69,   338,   601,    23,   341,
     164,    13,   706,    15,    13,    81,   408,   409,    13,   601,
      34,    33,   414,    15,    38,   117,   358,    39,   771,   772,
      29,   423,     5,    99,   777,   101,   779,    10,    11,   431,
      93,   433,   434,   435,   436,   193,   438,    40,   630,   923,
     521,   199,    34,   117,   174,   447,    38,   177,   450,   641,
      59,   935,   154,   395,   646,   457,   642,    82,   273,   645,
     136,   276,   277,   465,   139,   467,   132,   133,   214,    40,
      95,    42,    32,    33,   176,    84,    13,   179,    15,   181,
     154,    13,    13,   423,    15,    77,   426,    13,   112,    15,
     166,    55,    13,    65,    15,   139,   159,    74,   945,   946,
      92,   191,   192,   163,    96,   132,   133,   181,    13,   511,
     452,   453,   171,   172,   180,   517,   518,    81,   189,   190,
     112,   825,   177,   178,   877,   651,    13,   720,   137,    13,
     139,   207,   208,   209,   210,    99,   538,   101,   480,    13,
     480,    49,   484,     4,   637,    13,   155,   489,   490,   164,
     165,   164,   165,    13,   623,   164,   977,   978,    76,   997,
     998,   563,    13,     4,    13,    83,    75,   214,    76,    13,
      13,   216,   136,    91,    13,    83,    94,    13,   520,   771,
     772,   914,    20,    91,   790,   777,    94,   779,    23,   591,
     782,   200,     3,   202,   203,    49,   104,    93,   600,    13,
     602,    36,   166,   212,    39,    40,    41,    42,    43,    44,
      45,   119,    13,   131,    13,    13,    13,   559,   620,    13,
     124,   623,    76,   131,    13,   627,   568,   629,    13,    83,
      13,    39,    13,    15,   176,    28,   155,    91,    13,    13,
      94,    14,    20,   207,   208,   209,   210,    82,   214,   116,
     104,   591,   721,    17,    15,    90,    90,   157,   168,    14,
      95,    14,     5,   162,    14,   119,    14,   220,   874,    14,
     214,   214,    14,   108,    13,    40,     5,   131,   111,     5,
     886,   111,   888,   625,     5,   877,    13,   111,   630,    13,
     630,     5,   634,   635,   636,     5,     5,     5,    13,   641,
     152,     5,   111,     5,   646,     5,   214,    13,   150,   651,
     150,     5,     5,   148,    13,   179,   139,   214,   150,   721,
     662,   150,   113,   665,    40,   931,    13,     4,     5,     6,
       7,     8,   974,    10,    11,    40,    14,    13,   130,   741,
      14,    64,   744,    14,    75,    13,    13,    13,   140,   751,
     752,    14,    14,   120,     4,     5,     6,     7,     8,     3,
      10,    11,   154,   188,    13,    13,   158,    14,    14,     5,
       5,    14,    13,    23,   166,   167,    14,    54,     5,     5,
      14,    58,   875,     5,   219,   220,     5,   167,   790,    49,
      13,   183,   184,   111,    14,    13,    13,     5,    14,    14,
      14,    51,    14,    14,    54,   167,   748,   749,    58,   167,
     167,     4,     5,     6,     7,     8,    76,    10,    11,     5,
      15,   173,    14,    83,   216,   213,    14,   887,    89,   771,
     772,    91,    65,     5,    94,   777,    14,   779,   119,   932,
     782,    14,   186,    28,   104,   914,    91,    22,    78,   851,
     852,   164,   942,   995,   114,   191,    14,   799,    51,   119,
     192,    54,   187,  1005,     5,    58,   808,    14,    14,     5,
       5,   131,   874,    48,   151,    14,    14,     5,     5,     5,
      14,    13,   274,    14,   886,    14,   888,     5,   830,   169,
      15,   283,   214,   135,   286,    14,   156,    14,  1040,   841,
     842,   151,   213,   153,    79,    14,    14,    14,    14,  1035,
    1036,    13,   914,    13,    91,     5,   308,    13,    28,    80,
     312,  1016,    97,    98,    28,   177,   318,    14,   870,   931,
      14,    14,   324,   325,   326,   877,   938,   177,   330,    14,
      14,     5,   152,    14,    14,    14,   338,   339,    14,   150,
     150,   343,   894,   150,   130,    15,   348,   170,   151,   150,
     153,   353,   354,   355,   140,   357,    14,   969,   143,   144,
     145,   146,   974,     5,    13,   214,    14,   121,   154,    28,
     922,   923,   158,    28,   139,   160,   161,    14,   990,    14,
     166,   167,   199,   935,    15,    74,   167,   167,   167,   167,
     198,  1003,    74,   945,   946,   947,     2,   183,   184,    14,
      28,     7,   117,   955,  1016,    15,   408,   409,    13,   961,
     962,    14,   414,    15,   140,   149,    49,   214,    82,   969,
     152,   423,    82,     5,   976,    13,     4,    13,   132,   431,
     216,   433,   434,   435,   436,    14,   438,   123,    70,    58,
     123,   139,    14,    76,   139,   447,    14,    14,   450,     4,
      83,    17,    14,   118,   132,   457,   923,   517,    91,    30,
     615,    94,   281,   465,  1016,   467,   141,   750,   859,   316,
     650,   104,   650,   646,  1001,   317,   643,   343,   435,  1031,
    1032,   114,   595,  1035,  1036,   348,   119,   585,   274,   353,
     130,   469,   871,   601,   799,   690,   995,   283,   131,  1040,
     286,   538,   211,   956,   655,   282,   656,   738,   967,   511,
      -1,   422,   125,    -1,   154,   517,   518,    -1,   158,   125,
     126,    -1,   308,   156,    -1,    -1,   312,   167,    -1,    -1,
      -1,    -1,   318,    -1,    -1,   141,    -1,    -1,   324,   325,
     326,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   338,   339,    -1,    -1,    -1,   343,    -1,    -1,
      -1,   563,   348,    -1,    -1,    -1,    -1,   353,   354,   355,
      -1,   357,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   591,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,   600,    -1,
     602,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,   620,    -1,
      -1,   623,   408,   409,    -1,   627,    -1,   629,   414,    -1,
      -1,    -1,    -1,    -1,   274,    -1,    -1,   423,    -1,    -1,
      -1,    -1,    -1,   283,    -1,   431,   286,   433,   434,   435,
     436,    -1,   438,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,   447,    90,    -1,   450,    -1,    -1,    95,   308,    -1,
      -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   465,
     108,   467,    -1,    -1,   324,    -1,   326,    -1,    -1,    -1,
     330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   355,    -1,   357,    -1,   721,
      -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
     336,   517,   518,    -1,    -1,   341,    -1,    -1,    -1,   741,
      -1,    -1,   744,    -1,    -1,    -1,    -1,    -1,    -1,   751,
     752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
      -1,    -1,    -1,    -1,   414,    -1,    -1,   563,    -1,    -1,
      -1,    -1,    -1,   423,    -1,    -1,    -1,    -1,   790,   395,
      -1,   219,   220,   433,    -1,   435,   436,    -1,   438,    -1,
      -1,    -1,    -1,    -1,    -1,   591,    -1,   447,    -1,    -1,
     450,    -1,    -1,    -1,   600,    -1,   602,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,   620,    -1,    -1,   623,    -1,    -1,
      -1,   627,    -1,   629,    -1,    -1,    -1,    -1,    -1,   851,
     852,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   871,
      -1,   511,   874,    -1,   480,    -1,    -1,   517,   518,    -1,
      -1,    -1,    -1,    -1,   886,    -1,   888,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   914,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,   931,
      -1,    -1,    -1,    -1,    -1,   721,   938,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,   741,    -1,    -1,   744,    -1,
     600,    -1,   602,    -1,    -1,   751,   752,   969,    -1,    -1,
      -1,    -1,   974,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,    -1,    -1,    -1,    -1,   627,   990,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1003,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1016,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,    -1,   630,    -1,    -1,    -1,   634,   635,
     636,    -1,    -1,    -1,    -1,   641,    -1,    -1,    -1,    -1,
     646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   851,   852,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   874,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     886,   741,   888,    -1,   744,    -1,    -1,    -1,    -1,    -1,
      -1,   751,   752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   914,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   931,    -1,    -1,    -1,    -1,
     790,    -1,   938,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   771,   772,    -1,    -1,    -1,
      -1,   777,    -1,   779,    -1,    -1,   782,    -1,    -1,    -1,
      -1,    -1,    -1,   969,    -1,    -1,    -1,    -1,   974,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   990,    -1,    -1,    -1,    -1,    -1,
      -1,   851,   852,    -1,    -1,    -1,    -1,  1003,    -1,    -1,
      -1,    -1,    -1,    -1,   830,    -1,    -1,    -1,    -1,    -1,
    1016,    -1,    -1,    -1,   874,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   886,    -1,   888,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,   931,    -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
     990,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,  1003,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    -1,  1016,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,
      -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,   208,
     209,   210,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,   220,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,   106,    -1,   108,   109,   110,
     111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,   137,   138,    -1,   140,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,   164,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    -1,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    52,    53,    54,
      55,    56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,   108,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    52,    53,    54,    55,    56,    -1,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,   108,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,   135,   136,    -1,   138,
      -1,   140,    -1,    -1,   143,   144,   145,   146,   147,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,    -1,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    52,
      53,    54,    55,    56,    -1,    58,    -1,    60,    61,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,   106,    -1,   108,   109,   110,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   217,   218,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    -1,    16,
      -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,    -1,    52,    53,    54,    55,    56,
      -1,    58,    -1,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,   215,    -1,
     217,   218,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    -1,    16,    -1,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,    -1,   138,    -1,   140,
      -1,   142,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    -1,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    52,    53,    54,
      55,    56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,   137,   138,    -1,   140,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    -1,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    50,    -1,    52,    53,    54,    55,    56,    -1,    58,
      -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,
     109,   110,   111,   112,   113,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,   128,
     129,   130,   131,   132,    -1,   134,   135,   136,   137,   138,
      -1,   140,    -1,    -1,   143,   144,   145,   146,   147,    -1,
     149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      -1,    -1,   201,   202,   203,    -1,    -1,   206,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,    -1,    -1,   217,   218,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    52,
      53,    54,    55,    56,    -1,    58,    -1,    60,    61,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,    -1,   138,    -1,   140,    -1,    -1,
     143,   144,   145,   146,   147,    -1,   149,   150,   151,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,    -1,   217,   218,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    50,    -1,    52,    53,    54,    55,    56,
      -1,    58,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,   101,   102,   103,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,   113,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,
     127,   128,   129,   130,   131,   132,    -1,   134,   135,   136,
      -1,   138,    -1,   140,    -1,    -1,   143,   144,   145,   146,
     147,    -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,    -1,   206,
     207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     217,   218,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,
      -1,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
     101,   102,   103,    -1,   105,   106,    -1,    -1,   109,   110,
     111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,
      -1,   122,   123,   124,    -1,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,    -1,   138,    -1,   140,
      -1,    -1,   143,   144,   145,   146,   147,    -1,   149,   150,
     151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
     201,   202,   203,    -1,    -1,   206,   207,   208,   209,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   217,   218,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    50,    -1,    52,    53,    54,
      55,    56,    -1,    58,    -1,    60,    61,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,   101,   102,   103,    -1,
     105,   106,    -1,    -1,   109,   110,   111,   112,   113,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,
      -1,   126,   127,   128,   129,   130,   131,   132,    -1,   134,
     135,   136,    -1,   138,    -1,   140,    -1,    -1,   143,   144,
     145,   146,   147,    -1,   149,   150,   151,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,    -1,    -1,    -1,   201,   202,   203,     3,
      -1,   206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   217,   218,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,    -1,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     144,   145,   146,    -1,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
      -1,    -1,    -1,   207,   208,   209,   210,    19,    -1,    21,
      22,   215,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,   105,   106,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,    -1,
     132,    -1,   134,   135,   136,    -1,    -1,    -1,   140,    -1,
      -1,   143,   144,   145,   146,    -1,    -1,   149,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,    -1,    -1,    -1,   207,   208,   209,   210,    19,
      -1,    21,    22,   215,    24,    25,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,    13,    -1,   207,   208,   209,
     210,    19,    -1,    21,    22,   215,    24,    25,    26,    -1,
      -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
     128,   129,   130,    -1,   132,    -1,   134,   135,   136,   137,
      -1,    -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,
      -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,   164,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,
     208,   209,   210,    21,    22,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    54,    55,    56,    57,
      -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    72,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    85,    86,    -1,
      88,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
     128,   129,   130,    -1,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,   140,   141,    -1,   143,   144,   145,   146,    -1,
      -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    13,    -1,   207,
     208,   209,   210,    19,    -1,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,    -1,   132,    -1,   134,   135,
     136,   137,    -1,    -1,   140,    -1,    -1,   143,   144,   145,
     146,    -1,    -1,   149,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,   164,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    13,
      -1,   207,   208,   209,   210,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,    -1,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     144,   145,   146,    -1,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,   196,     3,    -1,    -1,    -1,   201,   202,   203,
      10,    11,    -1,   207,   208,   209,   210,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,    -1,    -1,   207,   208,   209,
     210,    19,    20,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    -1,    -1,    -1,    85,    -1,    -1,
      88,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,
      98,    99,    -1,   101,   102,   103,    -1,   105,   106,    -1,
      -1,   109,   110,   111,   112,   113,    -1,   115,    -1,    -1,
     118,    -1,    -1,    -1,   122,   123,   124,    -1,   126,   127,
     128,   129,   130,    -1,   132,    -1,   134,   135,   136,    -1,
      -1,    -1,   140,    -1,    -1,   143,   144,   145,   146,    -1,
      -1,   149,   150,   151,    -1,   153,    -1,    -1,    -1,    -1,
     158,   159,   160,   161,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,   196,    -1,
      -1,    -1,    -1,   201,   202,   203,    -1,    -1,    -1,   207,
     208,   209,   210,    19,    20,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    33,    34,    35,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,
      56,    -1,    -1,    -1,    60,    61,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,    -1,
      -1,    77,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
     106,    -1,    -1,   109,   110,   111,   112,   113,    -1,   115,
      -1,    -1,   118,    -1,    -1,    -1,   122,   123,   124,    -1,
     126,   127,   128,   129,   130,    -1,   132,    -1,   134,   135,
     136,    -1,    -1,    -1,   140,    -1,    -1,   143,   144,   145,
     146,    -1,    -1,   149,   150,   151,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
     196,    -1,    -1,    -1,    -1,   201,   202,   203,    -1,    13,
      -1,   207,   208,   209,   210,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    33,
      34,    35,    -1,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,   103,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,   113,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
     124,    -1,   126,   127,   128,   129,   130,    -1,   132,    -1,
     134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,   143,
     144,   145,   146,    -1,    -1,   149,   150,   151,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,   196,    -1,    -1,    -1,    -1,   201,   202,   203,
      -1,    -1,    -1,   207,   208,   209,   210,    19,    -1,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      -1,    33,    34,    35,    -1,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    -1,
      -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,    -1,   101,
     102,   103,    -1,   105,   106,    -1,    -1,   109,   110,   111,
     112,   113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
     122,   123,   124,    -1,   126,   127,   128,   129,   130,    -1,
     132,    -1,   134,   135,   136,    -1,    -1,    -1,   140,    -1,
      -1,   143,   144,   145,   146,    -1,    -1,   149,   150,   151,
      -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,
      -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   196,    -1,    -1,    -1,    -1,   201,
     202,   203,    -1,    -1,    -1,   207,   208,   209,   210,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    -1,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,   113,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,   126,   127,   128,   129,
     130,    -1,   132,    -1,   134,   135,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,   144,   145,   146,    -1,    -1,   149,
     150,   151,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    31,    -1,
      -1,   201,   202,   203,    37,    38,    -1,   207,   208,   209,
     210,    -1,    -1,    46,    47,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,   112,
     113,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,
     123,   124,    -1,   126,   127,    -1,   129,   130,    -1,   132,
      -1,   134,   135,   136,    -1,    -1,    -1,   140,    -1,    -1,
     143,   144,   145,   146,    -1,    -1,   149,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,    -1,    -1,   207,   208,   209,   210
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
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
     202,   203,   207,   208,   209,   210,   233,   292,   337,   339,
     368,   386,   388,   389,   391,    75,    89,    16,    62,   182,
     276,     3,   292,   416,   129,   271,   272,   386,   201,   225,
       3,    29,     0,    66,   211,    69,   117,   154,   181,   263,
     264,    87,   248,    14,    13,    15,   416,   292,   276,     4,
       5,     6,     7,     8,    10,    11,    13,    30,    31,    37,
      46,    52,    53,    54,    58,    94,   109,   131,   138,   147,
     151,   206,   215,   217,   218,   251,   252,   254,   277,   278,
     289,   290,   292,   315,   316,   317,   318,   319,   320,   329,
     330,   335,   336,   337,   338,   339,   355,   356,   368,   386,
      40,    20,   382,   383,   384,   386,   139,   271,   214,    13,
     273,   274,   139,    65,     3,    24,    25,    26,    27,    32,
      33,    35,    54,    56,    57,    63,    72,    85,    86,    88,
     103,   105,   106,   110,   128,   130,   141,   150,   151,   158,
     337,   339,   357,   358,   359,   360,   361,   362,   363,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   387,   389,
     390,   233,   225,   276,    28,   175,   276,   276,    74,   392,
     393,   276,   263,    13,    14,    71,   108,   185,   230,   231,
     232,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   314,   315,   386,   386,   163,   258,
      13,    58,   157,   237,   238,   246,   274,   277,    13,   247,
     315,   321,   315,   331,    13,    13,    13,    13,     4,    13,
      13,    13,     4,    13,   319,   319,    75,   259,   214,    13,
      36,    39,   220,   325,   382,   385,   217,   218,   327,   100,
     215,   221,   222,   328,   216,    13,    13,    13,    15,   151,
     329,   384,   244,   245,   315,   271,   275,   386,    20,     3,
      93,    13,    13,    93,   159,    13,    93,   159,    13,    13,
      13,   124,    13,   136,   364,   365,   367,   368,    32,    33,
      13,    93,   159,    13,    13,    13,    13,   164,   165,    13,
     164,   165,    13,    19,   102,    33,   385,   385,    15,    13,
     249,   265,   266,   315,    28,   249,   249,   155,   176,   398,
     402,   250,   392,    13,   300,   315,    13,   252,   253,   302,
     315,    13,    14,   214,    20,   116,    17,    90,    23,    40,
      41,    42,    43,    44,    45,    82,    90,    95,   108,   219,
     324,   326,    15,    15,   300,   157,   321,   168,   241,   241,
     238,   246,   259,   247,    14,   214,    14,   162,   332,   333,
     315,   321,   315,     5,    14,   315,    14,   136,   366,   368,
      13,   115,   194,   195,   253,   279,   280,   281,   282,   287,
     291,   292,   293,   294,   295,   296,   297,   258,   277,    14,
     321,   292,   220,   316,   317,   318,   319,    16,    62,   215,
     315,   380,    14,   315,   215,   386,   258,   214,    40,    14,
     214,    13,   255,    40,   111,     5,     5,   111,    13,     5,
     111,    13,     5,   377,     5,     5,     5,    13,   152,    13,
      13,   159,    13,    93,   159,     5,   111,    13,   377,     5,
     292,     5,   150,   150,     5,   150,   150,     5,    13,   139,
     387,    14,   230,   214,    21,    61,   267,   265,   113,   394,
       5,    10,    11,   401,   179,   405,   398,    14,   321,   230,
     357,   301,   302,     6,     9,   108,   323,   315,    40,    40,
      42,    13,   253,   322,     8,   108,   183,   184,   313,   315,
      23,    82,    95,    40,    16,    18,   142,   315,   381,   253,
     386,   386,   321,   241,   241,   258,    14,   321,   300,   315,
      64,   334,   332,    20,    14,   156,    14,   214,    13,    75,
      13,   280,   292,   293,    13,    13,    13,   382,    49,    76,
      83,    91,    94,   104,   119,   131,   214,   298,   382,   196,
     382,   414,   191,   192,   257,   411,   412,   413,    14,    14,
      14,   315,   120,   340,    14,    15,   241,   244,   315,   275,
     246,   188,   406,   407,     3,    13,    14,    14,    13,     5,
      14,    13,     5,    34,    38,    77,    92,    96,   112,   378,
     379,    14,    14,   214,    14,   214,    14,     5,   366,     5,
       5,    13,     5,   111,    13,    14,    13,     5,    14,    14,
     214,    14,    14,   167,   167,    14,   167,   167,    14,     5,
     292,    15,   213,    14,   265,   173,   268,   290,   386,   395,
     171,   172,   397,   132,   133,   399,   177,   178,   403,    14,
     323,    17,   321,   313,    67,   315,   322,   315,    15,    89,
     257,   148,   148,   315,    65,   357,   292,   315,     5,   315,
      14,    14,   292,   292,   292,   204,   205,   274,   283,   284,
     288,    91,   186,   119,   299,   280,   299,    91,   298,   186,
     299,   279,    91,    13,   197,   121,   283,   284,   286,   382,
     164,    28,    78,   260,   412,   411,   340,   340,    14,    13,
     341,   342,   386,   215,   386,    14,   189,   190,   187,   408,
     409,     5,   377,    14,   377,    14,   378,     5,     5,    14,
     214,    14,    14,     5,    14,    13,     5,   377,    14,     5,
     135,   164,   165,   164,   165,    14,   385,   387,   213,   174,
     177,   214,    15,     5,   169,   396,   400,   401,   315,    14,
     315,    17,    67,   386,    10,    11,   242,   243,   290,   260,
     315,   315,    14,    14,    14,    14,    14,    14,    14,    14,
      13,    13,   281,   281,   114,   156,   281,    91,   281,   280,
       5,    13,    28,   300,   193,   199,   410,    28,    80,   269,
     340,   342,   343,   344,    15,   177,   177,   275,    14,    14,
      14,    14,    14,     5,    14,   377,    14,    14,    14,   292,
     150,   150,   150,   150,    15,   395,   386,   170,   180,   399,
     315,   315,    15,   214,   269,   386,   336,   337,   300,   274,
     281,   114,   156,    14,     5,    13,   199,   300,   276,   300,
      14,   121,   345,   215,   386,    28,    28,   139,    14,    14,
     167,   167,   167,   167,   387,    15,   399,   115,   164,   404,
     242,    74,    74,   300,   274,   198,   415,    14,   395,    13,
      79,   261,   262,   315,    28,   263,    15,   275,   275,   386,
     386,   404,   149,   386,   386,    13,   415,    14,    14,   140,
     214,   321,   125,   133,   346,   347,   386,   267,   267,   152,
      82,    82,     5,    13,   261,    23,    51,   153,   329,   348,
     349,   350,   351,   268,   268,     4,    13,   285,   285,    14,
     261,   153,   329,   349,   352,   353,   132,   123,   123,    70,
     354,   139,   139,    58,   277,    14,    14,    14,    73,    73,
      17,    51,    78,   107,   149,   386,   386,     4,    14,   382,
     382,   352,   132,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
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
     282,   282,   282,   282,   282,   282,   283,   284,   285,   286,
     287,   287,   287,   288,   288,   289,   289,   289,   289,   290,
     290,   290,   290,   290,   291,   291,   292,   292,   292,   293,
     293,   293,   293,   294,   294,   295,   295,   295,   295,   296,
     297,   297,   298,   298,   298,   298,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   303,   303,   304,   304,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   307,   308,
     309,   309,   310,   310,   310,   310,   311,   311,   312,   312,
     313,   313,   313,   314,   315,   315,   315,   316,   316,   317,
     317,   318,   318,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   321,   321,   322,   322,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   325,   325,
     326,   327,   327,   328,   328,   328,   328,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   330,   331,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   335,   335,
     336,   336,   336,   336,   336,   336,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   338,   339,   339,
     339,   339,   339,   340,   340,   341,   342,   343,   344,   344,
     345,   345,   346,   346,   347,   347,   348,   348,   349,   349,
     349,   350,   351,   352,   352,   352,   353,   354,   354,   354,
     354,   354,   355,   355,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   356,   356,   356,   356,   357,   357,   357,
     357,   358,   359,   359,   359,   359,   360,   361,   361,   361,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   364,   364,   365,   365,   366,   366,   366,   367,
     367,   367,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   369,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   370,   370,   371,   371,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   373,   373,   373,   373,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   374,   374,   375,   375,
     375,   375,   376,   376,   376,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   377,   377,   377,
     377,   378,   378,   378,   379,   379,   379,   380,   380,   381,
     381,   381,   382,   382,   383,   383,   384,   385,   386,   386,
     387,   387,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     390,   390,   390,   390,   391,   391,   391,   391,   391,   392,
     392,   393,   394,   394,   395,   395,   396,   396,   397,   397,
     397,   398,   399,   399,   400,   400,   401,   401,   401,   402,
     402,   403,   403,   404,   404,   405,   405,   405,   406,   406,
     407,   407,   408,   408,   409,   410,   410,   410,   410,   411,
     412,   413,   413,   413,   414,   414,   415,   415,   416
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       3,     3,     3,     3,     3,     3,     9,     9,     3,     5,
       4,     4,     4,     0,     1,     1,     3,     5,     7,     1,
       3,     5,     7,     9,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     4,     4,     6,     5,     6,     5,     4,
       5,     4,     2,     2,     2,     1,     0,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       5,     6,     3,     5,     4,     6,     3,     4,     3,     4,
       1,     1,     1,     2,     1,     2,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     2,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     5,     0,     1,
       1,     2,     4,     4,     0,     2,     1,     1,     1,     1,
       5,     4,     6,     5,     5,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     0,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     2,     2,
       1,     2,     4,     1,     2,     1,     2,     0,     3,     2,
       2,     3,     3,     4,     4,     3,     3,     6,     6,     4,
       1,     4,     1,     6,     1,     1,     6,     1,     1,     1,
       1,     1,     1,     3,     5,     7,     6,     5,     2,     2,
       5,     4,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     4,     1,     1,     4,     1,     4,
       1,     6,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     7,     4,     4,     4,
       7,     7,     4,     4,     4,     1,     1,     1,     6,     4,
       6,     4,     6,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     1,     1,     4,     4,     5,     5,     4,
       6,     3,     6,     3,     4,     1,     1,     1,     6,     3,
       4,     1,     5,     2,     5,     2,     4,     6,     6,     5,
       7,     4,     6,     3,     4,     1,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     5,     0,     2,     1,     3,     0,     2,     0,     1,
       2,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       3,     1,     1,     1,     2,     0,     5,     6,     0,     1,
       9,     9,     0,     1,     8,     0,     1,     2,     1,     4,
       3,     2,     1,     2,     6,     5,     0,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, ParseResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, ParseResult* result, yyscan_t scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3499 "sqlparser_oracle_bison.cpp"
        break;

    case 4: /* STRING  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3505 "sqlparser_oracle_bison.cpp"
        break;

    case 5: /* INTNUM  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3511 "sqlparser_oracle_bison.cpp"
        break;

    case 6: /* BOOL  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3517 "sqlparser_oracle_bison.cpp"
        break;

    case 7: /* APPROXNUM  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3523 "sqlparser_oracle_bison.cpp"
        break;

    case 8: /* NULLX  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3529 "sqlparser_oracle_bison.cpp"
        break;

    case 9: /* UNKNOWN  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3535 "sqlparser_oracle_bison.cpp"
        break;

    case 10: /* QUESTIONMARK  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3541 "sqlparser_oracle_bison.cpp"
        break;

    case 11: /* PARAM  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3547 "sqlparser_oracle_bison.cpp"
        break;

    case 224: /* sql_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3553 "sqlparser_oracle_bison.cpp"
        break;

    case 225: /* stmt_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3559 "sqlparser_oracle_bison.cpp"
        break;

    case 226: /* stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3565 "sqlparser_oracle_bison.cpp"
        break;

    case 227: /* body_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3571 "sqlparser_oracle_bison.cpp"
        break;

    case 228: /* special_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3577 "sqlparser_oracle_bison.cpp"
        break;

    case 229: /* call_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3583 "sqlparser_oracle_bison.cpp"
        break;

    case 230: /* sql_argument_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3589 "sqlparser_oracle_bison.cpp"
        break;

    case 231: /* sql_argument  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3595 "sqlparser_oracle_bison.cpp"
        break;

    case 232: /* value_expression  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3601 "sqlparser_oracle_bison.cpp"
        break;

    case 233: /* sp_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3607 "sqlparser_oracle_bison.cpp"
        break;

    case 234: /* dql_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3613 "sqlparser_oracle_bison.cpp"
        break;

    case 235: /* dml_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3619 "sqlparser_oracle_bison.cpp"
        break;

    case 236: /* insert_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3625 "sqlparser_oracle_bison.cpp"
        break;

    case 237: /* insert_columns_and_source  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3631 "sqlparser_oracle_bison.cpp"
        break;

    case 238: /* from_constructor  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3637 "sqlparser_oracle_bison.cpp"
        break;

    case 239: /* delete_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3643 "sqlparser_oracle_bison.cpp"
        break;

    case 240: /* update_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3649 "sqlparser_oracle_bison.cpp"
        break;

    case 241: /* opt_returning_into  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3655 "sqlparser_oracle_bison.cpp"
        break;

    case 242: /* variable_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3661 "sqlparser_oracle_bison.cpp"
        break;

    case 243: /* variable  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3667 "sqlparser_oracle_bison.cpp"
        break;

    case 244: /* update_elem_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3673 "sqlparser_oracle_bison.cpp"
        break;

    case 245: /* update_elem  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3679 "sqlparser_oracle_bison.cpp"
        break;

    case 246: /* select_stmt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3685 "sqlparser_oracle_bison.cpp"
        break;

    case 247: /* query_expression  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3691 "sqlparser_oracle_bison.cpp"
        break;

    case 248: /* query_expression_body  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3697 "sqlparser_oracle_bison.cpp"
        break;

    case 249: /* query_term  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3703 "sqlparser_oracle_bison.cpp"
        break;

    case 250: /* query_primary  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3709 "sqlparser_oracle_bison.cpp"
        break;

    case 251: /* select_with_parens  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3715 "sqlparser_oracle_bison.cpp"
        break;

    case 252: /* subquery  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3721 "sqlparser_oracle_bison.cpp"
        break;

    case 253: /* table_subquery  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3727 "sqlparser_oracle_bison.cpp"
        break;

    case 254: /* row_subquery  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3733 "sqlparser_oracle_bison.cpp"
        break;

    case 255: /* cte_subquery  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3739 "sqlparser_oracle_bison.cpp"
        break;

    case 256: /* simple_table  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3745 "sqlparser_oracle_bison.cpp"
        break;

    case 257: /* opt_hierarchical_query_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3751 "sqlparser_oracle_bison.cpp"
        break;

    case 258: /* opt_where  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3757 "sqlparser_oracle_bison.cpp"
        break;

    case 259: /* opt_from_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3763 "sqlparser_oracle_bison.cpp"
        break;

    case 260: /* opt_groupby  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3769 "sqlparser_oracle_bison.cpp"
        break;

    case 261: /* grouping_element_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3775 "sqlparser_oracle_bison.cpp"
        break;

    case 262: /* grouping_element  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3781 "sqlparser_oracle_bison.cpp"
        break;

    case 263: /* opt_order_by  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3787 "sqlparser_oracle_bison.cpp"
        break;

    case 264: /* order_by  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3793 "sqlparser_oracle_bison.cpp"
        break;

    case 265: /* sort_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3799 "sqlparser_oracle_bison.cpp"
        break;

    case 266: /* sort_key  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3805 "sqlparser_oracle_bison.cpp"
        break;

    case 267: /* opt_asc_desc  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3811 "sqlparser_oracle_bison.cpp"
        break;

    case 268: /* opt_nulls_c  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3817 "sqlparser_oracle_bison.cpp"
        break;

    case 269: /* opt_having  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3823 "sqlparser_oracle_bison.cpp"
        break;

    case 270: /* with_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3829 "sqlparser_oracle_bison.cpp"
        break;

    case 271: /* with_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3835 "sqlparser_oracle_bison.cpp"
        break;

    case 272: /* common_table_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3841 "sqlparser_oracle_bison.cpp"
        break;

    case 273: /* opt_derived_column_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3847 "sqlparser_oracle_bison.cpp"
        break;

    case 274: /* simple_ident_list_with_parens  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3853 "sqlparser_oracle_bison.cpp"
        break;

    case 275: /* simple_ident_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3859 "sqlparser_oracle_bison.cpp"
        break;

    case 276: /* opt_distinct  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3865 "sqlparser_oracle_bison.cpp"
        break;

    case 277: /* select_expr_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3871 "sqlparser_oracle_bison.cpp"
        break;

    case 278: /* projection  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3877 "sqlparser_oracle_bison.cpp"
        break;

    case 279: /* from_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3883 "sqlparser_oracle_bison.cpp"
        break;

    case 280: /* table_reference  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3889 "sqlparser_oracle_bison.cpp"
        break;

    case 281: /* table_primary  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3895 "sqlparser_oracle_bison.cpp"
        break;

    case 282: /* table_primary_non_join  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3901 "sqlparser_oracle_bison.cpp"
        break;

    case 283: /* unpivot_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3907 "sqlparser_oracle_bison.cpp"
        break;

    case 284: /* pivot_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3913 "sqlparser_oracle_bison.cpp"
        break;

    case 285: /* select_expr_list_with_parens  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3919 "sqlparser_oracle_bison.cpp"
        break;

    case 286: /* partition_by  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3925 "sqlparser_oracle_bison.cpp"
        break;

    case 287: /* table_function  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3931 "sqlparser_oracle_bison.cpp"
        break;

    case 288: /* opt_simple_ident_list_with_parens  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3937 "sqlparser_oracle_bison.cpp"
        break;

    case 289: /* asterisk_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3943 "sqlparser_oracle_bison.cpp"
        break;

    case 290: /* column_ref  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3949 "sqlparser_oracle_bison.cpp"
        break;

    case 291: /* relation_factor_2  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3955 "sqlparser_oracle_bison.cpp"
        break;

    case 292: /* relation_factor  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3961 "sqlparser_oracle_bison.cpp"
        break;

    case 293: /* joined_table  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3967 "sqlparser_oracle_bison.cpp"
        break;

    case 294: /* cross_apply  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3973 "sqlparser_oracle_bison.cpp"
        break;

    case 295: /* qualified_join  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3979 "sqlparser_oracle_bison.cpp"
        break;

    case 296: /* cross_join  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3985 "sqlparser_oracle_bison.cpp"
        break;

    case 297: /* natural_join  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3991 "sqlparser_oracle_bison.cpp"
        break;

    case 298: /* join_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 3997 "sqlparser_oracle_bison.cpp"
        break;

    case 300: /* search_condition  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4003 "sqlparser_oracle_bison.cpp"
        break;

    case 301: /* boolean_term  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4009 "sqlparser_oracle_bison.cpp"
        break;

    case 302: /* boolean_factor  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4015 "sqlparser_oracle_bison.cpp"
        break;

    case 303: /* boolean_test  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4021 "sqlparser_oracle_bison.cpp"
        break;

    case 304: /* boolean_primary  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4027 "sqlparser_oracle_bison.cpp"
        break;

    case 305: /* predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4033 "sqlparser_oracle_bison.cpp"
        break;

    case 306: /* bool_function  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4039 "sqlparser_oracle_bison.cpp"
        break;

    case 307: /* comparison_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4045 "sqlparser_oracle_bison.cpp"
        break;

    case 308: /* quantified_comparison_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4051 "sqlparser_oracle_bison.cpp"
        break;

    case 309: /* between_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4057 "sqlparser_oracle_bison.cpp"
        break;

    case 310: /* like_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4063 "sqlparser_oracle_bison.cpp"
        break;

    case 311: /* in_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4069 "sqlparser_oracle_bison.cpp"
        break;

    case 312: /* null_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4075 "sqlparser_oracle_bison.cpp"
        break;

    case 313: /* null_value  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4081 "sqlparser_oracle_bison.cpp"
        break;

    case 314: /* exists_predicate  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4087 "sqlparser_oracle_bison.cpp"
        break;

    case 315: /* row_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4093 "sqlparser_oracle_bison.cpp"
        break;

    case 316: /* factor0  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4099 "sqlparser_oracle_bison.cpp"
        break;

    case 317: /* factor1  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4105 "sqlparser_oracle_bison.cpp"
        break;

    case 318: /* factor2  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4111 "sqlparser_oracle_bison.cpp"
        break;

    case 319: /* factor3  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4117 "sqlparser_oracle_bison.cpp"
        break;

    case 320: /* factor4  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4123 "sqlparser_oracle_bison.cpp"
        break;

    case 321: /* row_expr_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4129 "sqlparser_oracle_bison.cpp"
        break;

    case 322: /* in_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4135 "sqlparser_oracle_bison.cpp"
        break;

    case 323: /* truth_value  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4141 "sqlparser_oracle_bison.cpp"
        break;

    case 329: /* expr_const  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4147 "sqlparser_oracle_bison.cpp"
        break;

    case 330: /* case_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4153 "sqlparser_oracle_bison.cpp"
        break;

    case 331: /* case_arg  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4159 "sqlparser_oracle_bison.cpp"
        break;

    case 332: /* when_clause_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4165 "sqlparser_oracle_bison.cpp"
        break;

    case 333: /* when_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4171 "sqlparser_oracle_bison.cpp"
        break;

    case 334: /* case_default  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4177 "sqlparser_oracle_bison.cpp"
        break;

    case 335: /* func_expr  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4183 "sqlparser_oracle_bison.cpp"
        break;

    case 336: /* aggregate_windowed_function  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4189 "sqlparser_oracle_bison.cpp"
        break;

    case 337: /* aggregate_function_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4195 "sqlparser_oracle_bison.cpp"
        break;

    case 338: /* ranking_windowed_function  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4201 "sqlparser_oracle_bison.cpp"
        break;

    case 339: /* ranking_function_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4207 "sqlparser_oracle_bison.cpp"
        break;

    case 340: /* over_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4213 "sqlparser_oracle_bison.cpp"
        break;

    case 341: /* window_specification  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4219 "sqlparser_oracle_bison.cpp"
        break;

    case 342: /* window_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4225 "sqlparser_oracle_bison.cpp"
        break;

    case 343: /* window_specification_details  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4231 "sqlparser_oracle_bison.cpp"
        break;

    case 344: /* opt_existing_window_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4237 "sqlparser_oracle_bison.cpp"
        break;

    case 345: /* opt_window_partition_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4243 "sqlparser_oracle_bison.cpp"
        break;

    case 346: /* opt_window_frame_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4249 "sqlparser_oracle_bison.cpp"
        break;

    case 347: /* window_frame_units  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4255 "sqlparser_oracle_bison.cpp"
        break;

    case 348: /* window_frame_extent  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4261 "sqlparser_oracle_bison.cpp"
        break;

    case 349: /* window_frame_start  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4267 "sqlparser_oracle_bison.cpp"
        break;

    case 350: /* window_frame_preceding  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4273 "sqlparser_oracle_bison.cpp"
        break;

    case 351: /* window_frame_between  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4279 "sqlparser_oracle_bison.cpp"
        break;

    case 352: /* window_frame_bound  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4285 "sqlparser_oracle_bison.cpp"
        break;

    case 353: /* window_frame_following  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4291 "sqlparser_oracle_bison.cpp"
        break;

    case 354: /* opt_window_frame_exclusion  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4297 "sqlparser_oracle_bison.cpp"
        break;

    case 355: /* scalar_function  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4303 "sqlparser_oracle_bison.cpp"
        break;

    case 356: /* function_call_keyword  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4309 "sqlparser_oracle_bison.cpp"
        break;

    case 357: /* data_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4315 "sqlparser_oracle_bison.cpp"
        break;

    case 358: /* user_defined_type_name  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4321 "sqlparser_oracle_bison.cpp"
        break;

    case 359: /* relation_factor_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4327 "sqlparser_oracle_bison.cpp"
        break;

    case 360: /* reference_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4333 "sqlparser_oracle_bison.cpp"
        break;

    case 361: /* collection_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4339 "sqlparser_oracle_bison.cpp"
        break;

    case 362: /* predefined_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4345 "sqlparser_oracle_bison.cpp"
        break;

    case 363: /* interval_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4351 "sqlparser_oracle_bison.cpp"
        break;

    case 364: /* interval_qualifier  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4357 "sqlparser_oracle_bison.cpp"
        break;

    case 365: /* start_field  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4363 "sqlparser_oracle_bison.cpp"
        break;

    case 366: /* end_field  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4369 "sqlparser_oracle_bison.cpp"
        break;

    case 367: /* single_datetime_field  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4375 "sqlparser_oracle_bison.cpp"
        break;

    case 368: /* non_second_primary_datetime_field  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4381 "sqlparser_oracle_bison.cpp"
        break;

    case 369: /* boolean_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4387 "sqlparser_oracle_bison.cpp"
        break;

    case 370: /* datetime_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4393 "sqlparser_oracle_bison.cpp"
        break;

    case 371: /* numeric_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4399 "sqlparser_oracle_bison.cpp"
        break;

    case 372: /* exact_numeric_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4405 "sqlparser_oracle_bison.cpp"
        break;

    case 373: /* approximate_numeric_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4411 "sqlparser_oracle_bison.cpp"
        break;

    case 374: /* character_string_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4417 "sqlparser_oracle_bison.cpp"
        break;

    case 375: /* binary_large_object_string_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4423 "sqlparser_oracle_bison.cpp"
        break;

    case 376: /* national_character_string_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4429 "sqlparser_oracle_bison.cpp"
        break;

    case 377: /* large_object_length  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4435 "sqlparser_oracle_bison.cpp"
        break;

    case 378: /* char_length_units  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4441 "sqlparser_oracle_bison.cpp"
        break;

    case 379: /* multiplier  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4447 "sqlparser_oracle_bison.cpp"
        break;

    case 380: /* distinct_or_all  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4453 "sqlparser_oracle_bison.cpp"
        break;

    case 382: /* opt_as_label  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4459 "sqlparser_oracle_bison.cpp"
        break;

    case 383: /* as_label  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4465 "sqlparser_oracle_bison.cpp"
        break;

    case 384: /* label  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4471 "sqlparser_oracle_bison.cpp"
        break;

    case 385: /* collate_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4477 "sqlparser_oracle_bison.cpp"
        break;

    case 386: /* name_r  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4483 "sqlparser_oracle_bison.cpp"
        break;

    case 387: /* name_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4489 "sqlparser_oracle_bison.cpp"
        break;

    case 388: /* reserved_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4495 "sqlparser_oracle_bison.cpp"
        break;

    case 389: /* reserved_other  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4501 "sqlparser_oracle_bison.cpp"
        break;

    case 390: /* reserved_non_type  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4507 "sqlparser_oracle_bison.cpp"
        break;

    case 391: /* reserved  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4513 "sqlparser_oracle_bison.cpp"
        break;

    case 392: /* opt_for_update  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4519 "sqlparser_oracle_bison.cpp"
        break;

    case 393: /* for_update  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4525 "sqlparser_oracle_bison.cpp"
        break;

    case 394: /* opt_of_column_ref_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4531 "sqlparser_oracle_bison.cpp"
        break;

    case 395: /* column_ref_list  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4537 "sqlparser_oracle_bison.cpp"
        break;

    case 396: /* opt_ignore_lock  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4543 "sqlparser_oracle_bison.cpp"
        break;

    case 397: /* opt_wait_nowait  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4549 "sqlparser_oracle_bison.cpp"
        break;

    case 398: /* row_limiting_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4555 "sqlparser_oracle_bison.cpp"
        break;

    case 399: /* row_rows  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4561 "sqlparser_oracle_bison.cpp"
        break;

    case 400: /* opt_variable_v2  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4567 "sqlparser_oracle_bison.cpp"
        break;

    case 401: /* variable_v2  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4573 "sqlparser_oracle_bison.cpp"
        break;

    case 402: /* opt_offset_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4579 "sqlparser_oracle_bison.cpp"
        break;

    case 403: /* first_next  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4585 "sqlparser_oracle_bison.cpp"
        break;

    case 404: /* only_or_ties  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4591 "sqlparser_oracle_bison.cpp"
        break;

    case 405: /* opt_fetch_rows_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4597 "sqlparser_oracle_bison.cpp"
        break;

    case 406: /* opt_search_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4603 "sqlparser_oracle_bison.cpp"
        break;

    case 407: /* search_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4609 "sqlparser_oracle_bison.cpp"
        break;

    case 408: /* opt_cycle_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4615 "sqlparser_oracle_bison.cpp"
        break;

    case 409: /* cycle_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4621 "sqlparser_oracle_bison.cpp"
        break;

    case 410: /* connect_opt  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4627 "sqlparser_oracle_bison.cpp"
        break;

    case 411: /* connect_by  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4633 "sqlparser_oracle_bison.cpp"
        break;

    case 412: /* start_with  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4639 "sqlparser_oracle_bison.cpp"
        break;

    case 413: /* hierarchical_query_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4645 "sqlparser_oracle_bison.cpp"
        break;

    case 414: /* sample_clause  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4651 "sqlparser_oracle_bison.cpp"
        break;

    case 415: /* opt_seed_value  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4657 "sqlparser_oracle_bison.cpp"
        break;

    case 416: /* simple_table_alias  */
#line 95 "oracle.y"
            { delete(((*yyvaluep).node)); }
#line 4663 "sqlparser_oracle_bison.cpp"
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

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
#line 64 "oracle.y"
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
}

#line 4779 "sqlparser_oracle_bison.cpp"

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 246 "oracle.y"
{
    g_QuestMarkId = 0;
    (yyval.node) = (yyvsp[-1].node);
    result->result_tree_ = (yyvsp[-1].node);
    result->accept = true;
    YYACCEPT;
}
#line 4984 "sqlparser_oracle_bison.cpp"
    break;

  case 4:
#line 258 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
#line 4993 "sqlparser_oracle_bison.cpp"
    break;

  case 5:
#line 265 "oracle.y"
                { (yyval.node) = nullptr; }
#line 4999 "sqlparser_oracle_bison.cpp"
    break;

  case 11:
#line 275 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_BODYS, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &STMT_BODYS_SERIALIZE_FORMAT_ORA;
}
#line 5008 "sqlparser_oracle_bison.cpp"
    break;

  case 12:
#line 282 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_ALTER_SESSION, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &ALTER_SESSION_SERIALIZE_FORMAT_ORA;
}
#line 5017 "sqlparser_oracle_bison.cpp"
    break;

  case 13:
#line 287 "oracle.y"
{
    std::string val = "SET ";
    val += (yyvsp[-2].node)->text();
    delete((yyvsp[-2].node));
    val += " = ";
    val += (yyvsp[0].node)->text();
    delete((yyvsp[0].node));

    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 5032 "sqlparser_oracle_bison.cpp"
    break;

  case 14:
#line 298 "oracle.y"
{
    std::string val = "DECLARE ";
    val += (yyvsp[-1].node)->text();
    delete((yyvsp[-1].node));
    val += " ";
    val += (yyvsp[0].node)->text();
    delete((yyvsp[0].node));

    (yyval.node) = Node::makeTerminalNode(E_STRING, val);
}
#line 5047 "sqlparser_oracle_bison.cpp"
    break;

  case 15:
#line 312 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 5056 "sqlparser_oracle_bison.cpp"
    break;

  case 16:
#line 317 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-2].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SERIALIZE_FORMAT;
}
#line 5065 "sqlparser_oracle_bison.cpp"
    break;

  case 17:
#line 322 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node));
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 5074 "sqlparser_oracle_bison.cpp"
    break;

  case 18:
#line 327 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, (yyvsp[-3].node), nullptr);
    (yyval.node)->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
#line 5083 "sqlparser_oracle_bison.cpp"
    break;

  case 20:
#line 336 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5092 "sqlparser_oracle_bison.cpp"
    break;

  case 21:
#line 344 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 5101 "sqlparser_oracle_bison.cpp"
    break;

  case 22:
#line 349 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
#line 5110 "sqlparser_oracle_bison.cpp"
    break;

  case 30:
#line 376 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
#line 5119 "sqlparser_oracle_bison.cpp"
    break;

  case 31:
#line 384 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5128 "sqlparser_oracle_bison.cpp"
    break;

  case 32:
#line 389 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5137 "sqlparser_oracle_bison.cpp"
    break;

  case 33:
#line 394 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5146 "sqlparser_oracle_bison.cpp"
    break;

  case 34:
#line 399 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, 3, nullptr, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5155 "sqlparser_oracle_bison.cpp"
    break;

  case 35:
#line 404 "oracle.y"
{
    Node* src = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT VALUES");
    (yyval.node) = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, src);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 5165 "sqlparser_oracle_bison.cpp"
    break;

  case 36:
#line 413 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
#line 5174 "sqlparser_oracle_bison.cpp"
    break;

  case 37:
#line 422 "oracle.y"
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
#line 5191 "sqlparser_oracle_bison.cpp"
    break;

  case 38:
#line 439 "oracle.y"
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
#line 5209 "sqlparser_oracle_bison.cpp"
    break;

  case 39:
#line 454 "oracle.y"
          {(yyval.node) = NULL;}
#line 5215 "sqlparser_oracle_bison.cpp"
    break;

  case 40:
#line 456 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_RETURNING_INTO, 2, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &RETURNING_INTO_SERIALIZE_FORMAT;
}
#line 5224 "sqlparser_oracle_bison.cpp"
    break;

  case 42:
#line 464 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_VAR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5233 "sqlparser_oracle_bison.cpp"
    break;

  case 47:
#line 479 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5242 "sqlparser_oracle_bison.cpp"
    break;

  case 48:
#line 487 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
#line 5251 "sqlparser_oracle_bison.cpp"
    break;

  case 49:
#line 496 "oracle.y"
{
    (yyval.node) = (yyvsp[0].node);

}
#line 5260 "sqlparser_oracle_bison.cpp"
    break;

  case 50:
#line 504 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, (yyvsp[-3].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;

        (yyval.node)->setChild(E_DIRECT_SELECT_ORDER, (yyvsp[-2].node));
        (yyval.node)->setChild(E_DIRECT_SELECT_FOR_UPDATE, (yyvsp[-1].node));
        (yyval.node)->setChild(E_DIRECT_HINT_CLAUSE, (yyvsp[0].node));

}
#line 5274 "sqlparser_oracle_bison.cpp"
    break;

  case 51:
#line 514 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-3].node), nullptr, nullptr,nullptr);
    (yyval.node)->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;


        (yyval.node)->setChild(E_DIRECT_SELECT_ORDER, (yyvsp[-2].node));
        (yyval.node)->setChild(E_DIRECT_SELECT_FOR_UPDATE, (yyvsp[-1].node));
        (yyval.node)->setChild(E_DIRECT_HINT_CLAUSE, (yyvsp[0].node));
}
#line 5288 "sqlparser_oracle_bison.cpp"
    break;

  case 53:
#line 527 "oracle.y"
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
#line 5319 "sqlparser_oracle_bison.cpp"
    break;

  case 54:
#line 554 "oracle.y"
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
#line 5350 "sqlparser_oracle_bison.cpp"
    break;

  case 55:
#line 581 "oracle.y"
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
#line 5381 "sqlparser_oracle_bison.cpp"
    break;

  case 57:
#line 612 "oracle.y"
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
#line 5412 "sqlparser_oracle_bison.cpp"
    break;

  case 59:
#line 643 "oracle.y"
{
    if ((yyvsp[-1].node)->getChild(E_DIRECT_SELECT_WITH)) {
        yyerror(&(yylsp[-2]), result, scanner, "error use common table expression");
        YYABORT;
    }
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5425 "sqlparser_oracle_bison.cpp"
    break;

  case 60:
#line 656 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5434 "sqlparser_oracle_bison.cpp"
    break;

  case 64:
#line 669 "oracle.y"
    {
        (yyval.node) = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
        (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
    }
#line 5443 "sqlparser_oracle_bison.cpp"
    break;

  case 65:
#line 677 "oracle.y"
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
#line 5473 "sqlparser_oracle_bison.cpp"
    break;

  case 66:
#line 703 "oracle.y"
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
#line 5503 "sqlparser_oracle_bison.cpp"
    break;

  case 67:
#line 730 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5509 "sqlparser_oracle_bison.cpp"
    break;

  case 69:
#line 734 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5515 "sqlparser_oracle_bison.cpp"
    break;

  case 70:
#line 736 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
#line 5524 "sqlparser_oracle_bison.cpp"
    break;

  case 71:
#line 745 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FROM_SERIALIZE_FORMAT;
}
#line 5533 "sqlparser_oracle_bison.cpp"
    break;

  case 72:
#line 752 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5539 "sqlparser_oracle_bison.cpp"
    break;

  case 73:
#line 754 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
#line 5548 "sqlparser_oracle_bison.cpp"
    break;

  case 75:
#line 763 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5557 "sqlparser_oracle_bison.cpp"
    break;

  case 76:
#line 770 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"()"); }
#line 5563 "sqlparser_oracle_bison.cpp"
    break;

  case 78:
#line 773 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 5574 "sqlparser_oracle_bison.cpp"
    break;

  case 79:
#line 782 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5580 "sqlparser_oracle_bison.cpp"
    break;

  case 81:
#line 788 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_BY_SERIALIZE_FORMAT;
}
#line 5589 "sqlparser_oracle_bison.cpp"
    break;

  case 82:
#line 793 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORDER_SIBLINGS_BY_SERIALIZE_FORMAT;
}
#line 5598 "sqlparser_oracle_bison.cpp"
    break;

  case 84:
#line 802 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5607 "sqlparser_oracle_bison.cpp"
    break;

  case 85:
#line 810 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SORT_KEY, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
#line 5616 "sqlparser_oracle_bison.cpp"
    break;

  case 86:
#line 818 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "");
}
#line 5624 "sqlparser_oracle_bison.cpp"
    break;

  case 87:
#line 822 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
#line 5632 "sqlparser_oracle_bison.cpp"
    break;

  case 88:
#line 826 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
#line 5640 "sqlparser_oracle_bison.cpp"
    break;

  case 89:
#line 832 "oracle.y"
              { (yyval.node) = nullptr; }
#line 5646 "sqlparser_oracle_bison.cpp"
    break;

  case 90:
#line 833 "oracle.y"
                  {    (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS FIRST"); }
#line 5652 "sqlparser_oracle_bison.cpp"
    break;

  case 91:
#line 834 "oracle.y"
                 {    (yyval.node) = Node::makeTerminalNode(E_STRING, "NULLS LAST"); }
#line 5658 "sqlparser_oracle_bison.cpp"
    break;

  case 92:
#line 838 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5664 "sqlparser_oracle_bison.cpp"
    break;

  case 93:
#line 840 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
#line 5673 "sqlparser_oracle_bison.cpp"
    break;

  case 94:
#line 850 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
#line 5682 "sqlparser_oracle_bison.cpp"
    break;

  case 95:
#line 855 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
#line 5691 "sqlparser_oracle_bison.cpp"
    break;

  case 97:
#line 864 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5700 "sqlparser_oracle_bison.cpp"
    break;

  case 98:
#line 873 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, 5, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT_ORA;
}
#line 5709 "sqlparser_oracle_bison.cpp"
    break;

  case 99:
#line 880 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5715 "sqlparser_oracle_bison.cpp"
    break;

  case 101:
#line 886 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5724 "sqlparser_oracle_bison.cpp"
    break;

  case 103:
#line 895 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5733 "sqlparser_oracle_bison.cpp"
    break;

  case 104:
#line 902 "oracle.y"
                { (yyval.node) = nullptr; }
#line 5739 "sqlparser_oracle_bison.cpp"
    break;

  case 105:
#line 904 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 5747 "sqlparser_oracle_bison.cpp"
    break;

  case 106:
#line 908 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 5755 "sqlparser_oracle_bison.cpp"
    break;

  case 108:
#line 916 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5764 "sqlparser_oracle_bison.cpp"
    break;

  case 109:
#line 924 "oracle.y"
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
#line 5782 "sqlparser_oracle_bison.cpp"
    break;

  case 112:
#line 943 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 5791 "sqlparser_oracle_bison.cpp"
    break;

  case 116:
#line 957 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 5800 "sqlparser_oracle_bison.cpp"
    break;

  case 117:
#line 969 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5809 "sqlparser_oracle_bison.cpp"
    break;

  case 118:
#line 974 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5818 "sqlparser_oracle_bison.cpp"
    break;

  case 119:
#line 979 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5827 "sqlparser_oracle_bison.cpp"
    break;

  case 120:
#line 984 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5836 "sqlparser_oracle_bison.cpp"
    break;

  case 121:
#line 989 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), nullptr, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5845 "sqlparser_oracle_bison.cpp"
    break;

  case 122:
#line 994 "oracle.y"
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
#line 5899 "sqlparser_oracle_bison.cpp"
    break;

  case 123:
#line 1044 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5908 "sqlparser_oracle_bison.cpp"
    break;

  case 124:
#line 1049 "oracle.y"
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
#line 5962 "sqlparser_oracle_bison.cpp"
    break;

  case 125:
#line 1099 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 5971 "sqlparser_oracle_bison.cpp"
    break;

  case 126:
#line 1106 "oracle.y"
{
    Node* npvt = Node::makeTerminalNode(E_IDENTIFIER, "UNPIVOT");
    (yyval.node) = Node::makeNonTerminalNode(E_UNPIVOT_PIVOT, 5, npvt, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &PIVOT_CLAUSE_SERIALIZE_FORMAT;
}
#line 5981 "sqlparser_oracle_bison.cpp"
    break;

  case 127:
#line 1114 "oracle.y"
{
    Node* npvt = Node::makeTerminalNode(E_IDENTIFIER, "PIVOT");
    (yyval.node) = Node::makeNonTerminalNode(E_UNPIVOT_PIVOT, 5, npvt, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &PIVOT_CLAUSE_SERIALIZE_FORMAT;
}
#line 5991 "sqlparser_oracle_bison.cpp"
    break;

  case 128:
#line 1123 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6000 "sqlparser_oracle_bison.cpp"
    break;

  case 129:
#line 1131 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_PARTITION_BY, 1, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &PARTITION_BY_SERIALIZE_FORMAT;
}
#line 6009 "sqlparser_oracle_bison.cpp"
    break;

  case 130:
#line 1138 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "ONLY");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6020 "sqlparser_oracle_bison.cpp"
    break;

  case 131:
#line 1145 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONTAINERS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6031 "sqlparser_oracle_bison.cpp"
    break;

  case 132:
#line 1152 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SHARDS");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6042 "sqlparser_oracle_bison.cpp"
    break;

  case 133:
#line 1161 "oracle.y"
                { (yyval.node) = nullptr; }
#line 6048 "sqlparser_oracle_bison.cpp"
    break;

  case 135:
#line 1168 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STAR, "*");
}
#line 6056 "sqlparser_oracle_bison.cpp"
    break;

  case 136:
#line 1172 "oracle.y"
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, nullptr, (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6066 "sqlparser_oracle_bison.cpp"
    break;

  case 137:
#line 1178 "oracle.y"
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, nullptr, (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6076 "sqlparser_oracle_bison.cpp"
    break;

  case 138:
#line 1184 "oracle.y"
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    (yyval.node) = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), star_node);
    (yyval.node)->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
#line 6086 "sqlparser_oracle_bison.cpp"
    break;

  case 139:
#line 1193 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6096 "sqlparser_oracle_bison.cpp"
    break;

  case 140:
#line 1199 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6106 "sqlparser_oracle_bison.cpp"
    break;

  case 141:
#line 1205 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6116 "sqlparser_oracle_bison.cpp"
    break;

  case 142:
#line 1211 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), nullptr);
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6126 "sqlparser_oracle_bison.cpp"
    break;

  case 143:
#line 1217 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
    			(yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node), (yyvsp[-8].node));
    (yyval.node)->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
#line 6136 "sqlparser_oracle_bison.cpp"
    break;

  case 145:
#line 1289 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6145 "sqlparser_oracle_bison.cpp"
    break;

  case 146:
#line 1297 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 6154 "sqlparser_oracle_bison.cpp"
    break;

  case 147:
#line 1302 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 6163 "sqlparser_oracle_bison.cpp"
    break;

  case 148:
#line 1307 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 6172 "sqlparser_oracle_bison.cpp"
    break;

  case 153:
#line 1351 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_3_SERIALIZE_FORMAT;
}
#line 6182 "sqlparser_oracle_bison.cpp"
    break;

  case 154:
#line 1357 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "OUTER");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_3_SERIALIZE_FORMAT;
}
#line 6192 "sqlparser_oracle_bison.cpp"
    break;

  case 155:
#line 1365 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 6201 "sqlparser_oracle_bison.cpp"
    break;

  case 156:
#line 1370 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
#line 6211 "sqlparser_oracle_bison.cpp"
    break;

  case 157:
#line 1376 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 6220 "sqlparser_oracle_bison.cpp"
    break;

  case 158:
#line 1381 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
#line 6230 "sqlparser_oracle_bison.cpp"
    break;

  case 159:
#line 1390 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6240 "sqlparser_oracle_bison.cpp"
    break;

  case 160:
#line 1399 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL " + (yyvsp[-2].node)->text());
    delete((yyvsp[-2].node));
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-4].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6251 "sqlparser_oracle_bison.cpp"
    break;

  case 161:
#line 1406 "oracle.y"
{
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL");
    (yyval.node) = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, (yyvsp[-3].node), (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
#line 6261 "sqlparser_oracle_bison.cpp"
    break;

  case 162:
#line 1415 "oracle.y"
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
#line 6276 "sqlparser_oracle_bison.cpp"
    break;

  case 163:
#line 1426 "oracle.y"
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
#line 6291 "sqlparser_oracle_bison.cpp"
    break;

  case 164:
#line 1437 "oracle.y"
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
#line 6306 "sqlparser_oracle_bison.cpp"
    break;

  case 165:
#line 1448 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_JOIN_INNER, "INNER");
}
#line 6314 "sqlparser_oracle_bison.cpp"
    break;

  case 166:
#line 1454 "oracle.y"
                                { (yyval.ival) = 0; }
#line 6320 "sqlparser_oracle_bison.cpp"
    break;

  case 167:
#line 1455 "oracle.y"
                                { (yyval.ival) = 1; /*this is a flag*/}
#line 6326 "sqlparser_oracle_bison.cpp"
    break;

  case 169:
#line 1462 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_OR);
}
#line 6335 "sqlparser_oracle_bison.cpp"
    break;

  case 171:
#line 1471 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_AND);
}
#line 6344 "sqlparser_oracle_bison.cpp"
    break;

  case 173:
#line 1480 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
#line 6353 "sqlparser_oracle_bison.cpp"
    break;

  case 175:
#line 1489 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 6362 "sqlparser_oracle_bison.cpp"
    break;

  case 176:
#line 1494 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 6371 "sqlparser_oracle_bison.cpp"
    break;

  case 178:
#line 1503 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6380 "sqlparser_oracle_bison.cpp"
    break;

  case 187:
#line 1532 "oracle.y"
{
    Node * name = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_LIKE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6391 "sqlparser_oracle_bison.cpp"
    break;

  case 188:
#line 1541 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6400 "sqlparser_oracle_bison.cpp"
    break;

  case 189:
#line 1549 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode((yyvsp[-1].nodetype), E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6409 "sqlparser_oracle_bison.cpp"
    break;

  case 190:
#line 1557 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
#line 6418 "sqlparser_oracle_bison.cpp"
    break;

  case 191:
#line 1562 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
#line 6427 "sqlparser_oracle_bison.cpp"
    break;

  case 192:
#line 1570 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node), NULL);
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 6436 "sqlparser_oracle_bison.cpp"
    break;

  case 193:
#line 1575 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
#line 6445 "sqlparser_oracle_bison.cpp"
    break;

  case 194:
#line 1580 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 6454 "sqlparser_oracle_bison.cpp"
    break;

  case 195:
#line 1585 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
#line 6463 "sqlparser_oracle_bison.cpp"
    break;

  case 196:
#line 1593 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IN);
}
#line 6472 "sqlparser_oracle_bison.cpp"
    break;

  case 197:
#line 1598 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
#line 6481 "sqlparser_oracle_bison.cpp"
    break;

  case 198:
#line 1606 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS);
}
#line 6490 "sqlparser_oracle_bison.cpp"
    break;

  case 199:
#line 1611 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
#line 6499 "sqlparser_oracle_bison.cpp"
    break;

  case 201:
#line 1619 "oracle.y"
             { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NAN"); }
#line 6505 "sqlparser_oracle_bison.cpp"
    break;

  case 202:
#line 1620 "oracle.y"
               { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INFINITE"); }
#line 6511 "sqlparser_oracle_bison.cpp"
    break;

  case 203:
#line 1624 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
#line 6520 "sqlparser_oracle_bison.cpp"
    break;

  case 205:
#line 1634 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 6529 "sqlparser_oracle_bison.cpp"
    break;

  case 206:
#line 1639 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6538 "sqlparser_oracle_bison.cpp"
    break;

  case 208:
#line 1648 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6547 "sqlparser_oracle_bison.cpp"
    break;

  case 210:
#line 1657 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format((yyvsp[-1].nodetype));
}
#line 6556 "sqlparser_oracle_bison.cpp"
    break;

  case 212:
#line 1666 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POW);
}
#line 6565 "sqlparser_oracle_bison.cpp"
    break;

  case 214:
#line 1675 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_POS);
}
#line 6574 "sqlparser_oracle_bison.cpp"
    break;

  case 215:
#line 1680 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
#line 6583 "sqlparser_oracle_bison.cpp"
    break;

  case 219:
#line 1691 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6592 "sqlparser_oracle_bison.cpp"
    break;

  case 223:
#line 1702 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 6601 "sqlparser_oracle_bison.cpp"
    break;

  case 225:
#line 1711 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
#line 6610 "sqlparser_oracle_bison.cpp"
    break;

  case 228:
#line 1722 "oracle.y"
                        { (yyval.nodetype) = E_OP_LE; }
#line 6616 "sqlparser_oracle_bison.cpp"
    break;

  case 229:
#line 1723 "oracle.y"
                        { (yyval.nodetype) = E_OP_LT; }
#line 6622 "sqlparser_oracle_bison.cpp"
    break;

  case 230:
#line 1724 "oracle.y"
                        { (yyval.nodetype) = E_OP_GE; }
#line 6628 "sqlparser_oracle_bison.cpp"
    break;

  case 231:
#line 1725 "oracle.y"
                        { (yyval.nodetype) = E_OP_GT; }
#line 6634 "sqlparser_oracle_bison.cpp"
    break;

  case 232:
#line 1726 "oracle.y"
                        { (yyval.nodetype) = E_OP_EQ; }
#line 6640 "sqlparser_oracle_bison.cpp"
    break;

  case 233:
#line 1727 "oracle.y"
                        { (yyval.nodetype) = E_OP_NE; }
#line 6646 "sqlparser_oracle_bison.cpp"
    break;

  case 234:
#line 1728 "oracle.y"
                        { (yyval.nodetype) = E_OP_GE; }
#line 6652 "sqlparser_oracle_bison.cpp"
    break;

  case 235:
#line 1729 "oracle.y"
                        { (yyval.nodetype) = E_OP_LE; }
#line 6658 "sqlparser_oracle_bison.cpp"
    break;

  case 236:
#line 1730 "oracle.y"
                        { (yyval.nodetype) = E_OP_NE; }
#line 6664 "sqlparser_oracle_bison.cpp"
    break;

  case 237:
#line 1731 "oracle.y"
                        { (yyval.nodetype) = E_OP_NE; }
#line 6670 "sqlparser_oracle_bison.cpp"
    break;

  case 238:
#line 1735 "oracle.y"
                        { (yyval.nodetype) = E_OP_CNN; }
#line 6676 "sqlparser_oracle_bison.cpp"
    break;

  case 239:
#line 1736 "oracle.y"
                        { (yyval.nodetype) = E_OP_CNN; }
#line 6682 "sqlparser_oracle_bison.cpp"
    break;

  case 240:
#line 1742 "oracle.y"
{
    (yyval.nodetype) = Node::comp_all_some_any_op_form((yyvsp[-1].nodetype), (yyvsp[0].ival));
}
#line 6690 "sqlparser_oracle_bison.cpp"
    break;

  case 241:
#line 1748 "oracle.y"
                { (yyval.nodetype) = E_OP_ADD; }
#line 6696 "sqlparser_oracle_bison.cpp"
    break;

  case 242:
#line 1749 "oracle.y"
                { (yyval.nodetype) = E_OP_MINUS; }
#line 6702 "sqlparser_oracle_bison.cpp"
    break;

  case 243:
#line 1753 "oracle.y"
                { (yyval.nodetype) = E_OP_MUL; }
#line 6708 "sqlparser_oracle_bison.cpp"
    break;

  case 244:
#line 1754 "oracle.y"
                { (yyval.nodetype) = E_OP_DIV; }
#line 6714 "sqlparser_oracle_bison.cpp"
    break;

  case 245:
#line 1755 "oracle.y"
                { (yyval.nodetype) = E_OP_REM; }
#line 6720 "sqlparser_oracle_bison.cpp"
    break;

  case 246:
#line 1756 "oracle.y"
                { (yyval.nodetype) = E_OP_MOD; }
#line 6726 "sqlparser_oracle_bison.cpp"
    break;

  case 254:
#line 1767 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_STRING, "DEFAULT"); }
#line 6732 "sqlparser_oracle_bison.cpp"
    break;

  case 255:
#line 1768 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE " + (yyvsp[0].node)->text()); delete((yyvsp[0].node)); }
#line 6738 "sqlparser_oracle_bison.cpp"
    break;

  case 256:
#line 1769 "oracle.y"
                      { (yyval.node) = Node::makeTerminalNode(E_STRING,  "TIMESTAMP " + (yyvsp[0].node)->text()); delete((yyvsp[0].node));  }
#line 6744 "sqlparser_oracle_bison.cpp"
    break;

  case 257:
#line 1775 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
    (yyval.node)->serialize_format = Node::op_serialize_format(E_CASE);
}
#line 6753 "sqlparser_oracle_bison.cpp"
    break;

  case 258:
#line 1782 "oracle.y"
                { (yyval.node) = nullptr; }
#line 6759 "sqlparser_oracle_bison.cpp"
    break;

  case 261:
#line 1789 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
#line 6768 "sqlparser_oracle_bison.cpp"
    break;

  case 262:
#line 1797 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6777 "sqlparser_oracle_bison.cpp"
    break;

  case 263:
#line 1802 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WHEN_SERIALIZE_FORMAT;
}
#line 6786 "sqlparser_oracle_bison.cpp"
    break;

  case 264:
#line 1809 "oracle.y"
                { (yyval.node) = nullptr; }
#line 6792 "sqlparser_oracle_bison.cpp"
    break;

  case 265:
#line 1811 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, (yyvsp[0].node));
    (yyval.node)->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
#line 6801 "sqlparser_oracle_bison.cpp"
    break;

  case 270:
#line 1828 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6811 "sqlparser_oracle_bison.cpp"
    break;

  case 271:
#line 1834 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6821 "sqlparser_oracle_bison.cpp"
    break;

  case 272:
#line 1840 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), nullptr, (yyvsp[0].node));
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6831 "sqlparser_oracle_bison.cpp"
    break;

  case 273:
#line 1846 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-4].node),(yyvsp[-2].node), (yyvsp[-1].node), nullptr,  nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
#line 6841 "sqlparser_oracle_bison.cpp"
    break;

  case 274:
#line 1852 "oracle.y"
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
#line 6857 "sqlparser_oracle_bison.cpp"
    break;

  case 275:
#line 1864 "oracle.y"
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
#line 6873 "sqlparser_oracle_bison.cpp"
    break;

  case 276:
#line 1878 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
#line 6879 "sqlparser_oracle_bison.cpp"
    break;

  case 277:
#line 1879 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
#line 6885 "sqlparser_oracle_bison.cpp"
    break;

  case 278:
#line 1880 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
#line 6891 "sqlparser_oracle_bison.cpp"
    break;

  case 279:
#line 1881 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
#line 6897 "sqlparser_oracle_bison.cpp"
    break;

  case 280:
#line 1882 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
#line 6903 "sqlparser_oracle_bison.cpp"
    break;

  case 281:
#line 1883 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
#line 6909 "sqlparser_oracle_bison.cpp"
    break;

  case 282:
#line 1884 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
#line 6915 "sqlparser_oracle_bison.cpp"
    break;

  case 283:
#line 1885 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
#line 6921 "sqlparser_oracle_bison.cpp"
    break;

  case 284:
#line 1886 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
#line 6927 "sqlparser_oracle_bison.cpp"
    break;

  case 285:
#line 1887 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING"); }
#line 6933 "sqlparser_oracle_bison.cpp"
    break;

  case 286:
#line 1888 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV"); }
#line 6939 "sqlparser_oracle_bison.cpp"
    break;

  case 287:
#line 1893 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), nullptr, (yyvsp[0].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 6949 "sqlparser_oracle_bison.cpp"
    break;

  case 288:
#line 1901 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
#line 6955 "sqlparser_oracle_bison.cpp"
    break;

  case 289:
#line 1902 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
#line 6961 "sqlparser_oracle_bison.cpp"
    break;

  case 290:
#line 1903 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
#line 6967 "sqlparser_oracle_bison.cpp"
    break;

  case 291:
#line 1904 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
#line 6973 "sqlparser_oracle_bison.cpp"
    break;

  case 292:
#line 1905 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
#line 6979 "sqlparser_oracle_bison.cpp"
    break;

  case 293:
#line 1910 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ (yyvsp[0].node)->text()); delete((yyvsp[0].node));
}
#line 6987 "sqlparser_oracle_bison.cpp"
    break;

  case 294:
#line 1914 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, (yyvsp[0].node));
    (yyval.node)->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
#line 6996 "sqlparser_oracle_bison.cpp"
    break;

  case 295:
#line 1923 "oracle.y"
{ (yyval.node) = (yyvsp[-1].node); }
#line 7002 "sqlparser_oracle_bison.cpp"
    break;

  case 297:
#line 1932 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
#line 7011 "sqlparser_oracle_bison.cpp"
    break;

  case 298:
#line 1939 "oracle.y"
                { (yyval.node) = nullptr; }
#line 7017 "sqlparser_oracle_bison.cpp"
    break;

  case 300:
#line 1944 "oracle.y"
                { (yyval.node) = nullptr; }
#line 7023 "sqlparser_oracle_bison.cpp"
    break;

  case 301:
#line 1946 "oracle.y"
{ (yyval.node) = (yyvsp[0].node); }
#line 7029 "sqlparser_oracle_bison.cpp"
    break;

  case 302:
#line 1950 "oracle.y"
                { (yyval.node) = nullptr; }
#line 7035 "sqlparser_oracle_bison.cpp"
    break;

  case 303:
#line 1952 "oracle.y"
{
    std::string s3 = (yyvsp[0].node) ? (yyvsp[0].node)->text() : "";
    (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+s3);
    delete((yyvsp[-2].node)); delete((yyvsp[-1].node)); delete((yyvsp[0].node));
}
#line 7045 "sqlparser_oracle_bison.cpp"
    break;

  case 304:
#line 1960 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
#line 7051 "sqlparser_oracle_bison.cpp"
    break;

  case 305:
#line 1961 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
#line 7057 "sqlparser_oracle_bison.cpp"
    break;

  case 308:
#line 1970 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
#line 7063 "sqlparser_oracle_bison.cpp"
    break;

  case 309:
#line 1971 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
#line 7069 "sqlparser_oracle_bison.cpp"
    break;

  case 311:
#line 1976 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" PRECEDING"); delete((yyvsp[-1].node)); }
#line 7075 "sqlparser_oracle_bison.cpp"
    break;

  case 312:
#line 1981 "oracle.y"
{ (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+(yyvsp[-2].node)->text()+" AND "+(yyvsp[0].node)->text()); delete((yyvsp[-2].node)); delete((yyvsp[0].node)); }
#line 7081 "sqlparser_oracle_bison.cpp"
    break;

  case 314:
#line 1986 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
#line 7087 "sqlparser_oracle_bison.cpp"
    break;

  case 316:
#line 1991 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,(yyvsp[-1].node)->text()+" FOLLOWING"); delete((yyvsp[-1].node)); }
#line 7093 "sqlparser_oracle_bison.cpp"
    break;

  case 317:
#line 1995 "oracle.y"
                { (yyval.node) = nullptr; }
#line 7099 "sqlparser_oracle_bison.cpp"
    break;

  case 318:
#line 1996 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
#line 7105 "sqlparser_oracle_bison.cpp"
    break;

  case 319:
#line 1997 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
#line 7111 "sqlparser_oracle_bison.cpp"
    break;

  case 320:
#line 1998 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
#line 7117 "sqlparser_oracle_bison.cpp"
    break;

  case 321:
#line 1999 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
#line 7123 "sqlparser_oracle_bison.cpp"
    break;

  case 322:
#line 2004 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-2].node), nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7133 "sqlparser_oracle_bison.cpp"
    break;

  case 323:
#line 2010 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7143 "sqlparser_oracle_bison.cpp"
    break;

  case 324:
#line 2022 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		(yyvsp[-3].node), (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7153 "sqlparser_oracle_bison.cpp"
    break;

  case 325:
#line 2028 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7164 "sqlparser_oracle_bison.cpp"
    break;

  case 326:
#line 2035 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7175 "sqlparser_oracle_bison.cpp"
    break;

  case 327:
#line 2042 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-3].node), nullptr, nullptr, (yyvsp[-1].node));
    (yyval.node)->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
#line 7186 "sqlparser_oracle_bison.cpp"
    break;

  case 328:
#line 2049 "oracle.y"
{
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete((yyvsp[-1].node));
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, (yyvsp[-3].node), nullptr, nullptr, transcoding_name);
    (yyval.node)->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
#line 7199 "sqlparser_oracle_bison.cpp"
    break;

  case 329:
#line 2058 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7210 "sqlparser_oracle_bison.cpp"
    break;

  case 330:
#line 2065 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7221 "sqlparser_oracle_bison.cpp"
    break;

  case 331:
#line 2072 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, (yyvsp[-1].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7232 "sqlparser_oracle_bison.cpp"
    break;

  case 332:
#line 2079 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7243 "sqlparser_oracle_bison.cpp"
    break;

  case 333:
#line 2086 "oracle.y"
{
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-3].node), (yyvsp[-1].node));
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
#line 7256 "sqlparser_oracle_bison.cpp"
    break;

  case 334:
#line 2095 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7267 "sqlparser_oracle_bison.cpp"
    break;

  case 335:
#line 2102 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7278 "sqlparser_oracle_bison.cpp"
    break;

  case 336:
#line 2109 "oracle.y"
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT");
    (yyval.node) = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
            fun_name, (yyvsp[-1].node), (yyvsp[-3].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &FUN_EXTRACT_SERIALIZE_FORMAT_ORA;
}
#line 7289 "sqlparser_oracle_bison.cpp"
    break;

  case 341:
#line 2129 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7298 "sqlparser_oracle_bison.cpp"
    break;

  case 342:
#line 2137 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
#line 7307 "sqlparser_oracle_bison.cpp"
    break;

  case 343:
#line 2142 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), nullptr, nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
#line 7316 "sqlparser_oracle_bison.cpp"
    break;

  case 344:
#line 2147 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), nullptr);
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
#line 7325 "sqlparser_oracle_bison.cpp"
    break;

  case 345:
#line 2152 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, (yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].node), (yyvsp[-6].node));
    (yyval.node)->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
#line 7334 "sqlparser_oracle_bison.cpp"
    break;

  case 346:
#line 2161 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REF("+(yyvsp[-3].node)->text()+")SCOPE "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 7343 "sqlparser_oracle_bison.cpp"
    break;

  case 347:
#line 2169 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" ARRAY("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-4].node));
    delete((yyvsp[-1].node));
}
#line 7353 "sqlparser_oracle_bison.cpp"
    break;

  case 348:
#line 2175 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" ARRAY");
    delete((yyvsp[-1].node));
}
#line 7362 "sqlparser_oracle_bison.cpp"
    break;

  case 349:
#line 2180 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" MULTISET");
    delete((yyvsp[-1].node));
}
#line 7371 "sqlparser_oracle_bison.cpp"
    break;

  case 350:
#line 2188 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-4].node)->text()+" CHARACTER SET "+(yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-4].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7380 "sqlparser_oracle_bison.cpp"
    break;

  case 351:
#line 2193 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+" CHARACTER SET "+(yyvsp[0].node)->text());
    delete((yyvsp[-3].node));delete((yyvsp[0].node));
}
#line 7389 "sqlparser_oracle_bison.cpp"
    break;

  case 352:
#line 2198 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7398 "sqlparser_oracle_bison.cpp"
    break;

  case 354:
#line 2204 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 7407 "sqlparser_oracle_bison.cpp"
    break;

  case 361:
#line 2218 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTERVAL "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 7416 "sqlparser_oracle_bison.cpp"
    break;

  case 362:
#line 2226 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" TO "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[0].node));
}
#line 7425 "sqlparser_oracle_bison.cpp"
    break;

  case 364:
#line 2235 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));
    delete((yyvsp[-1].node));
}
#line 7435 "sqlparser_oracle_bison.cpp"
    break;

  case 367:
#line 2246 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7444 "sqlparser_oracle_bison.cpp"
    break;

  case 368:
#line 2251 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 7452 "sqlparser_oracle_bison.cpp"
    break;

  case 369:
#line 2258 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-3].node)->text()+"("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7461 "sqlparser_oracle_bison.cpp"
    break;

  case 371:
#line 2264 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7470 "sqlparser_oracle_bison.cpp"
    break;

  case 372:
#line 2269 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7479 "sqlparser_oracle_bison.cpp"
    break;

  case 373:
#line 2274 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SECOND");
}
#line 7487 "sqlparser_oracle_bison.cpp"
    break;

  case 374:
#line 2281 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "YEAR");
}
#line 7495 "sqlparser_oracle_bison.cpp"
    break;

  case 375:
#line 2285 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MONTH");
}
#line 7503 "sqlparser_oracle_bison.cpp"
    break;

  case 376:
#line 2289 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DAY");
}
#line 7511 "sqlparser_oracle_bison.cpp"
    break;

  case 377:
#line 2293 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "HOUR");
}
#line 7519 "sqlparser_oracle_bison.cpp"
    break;

  case 378:
#line 2297 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "MINUTE");
}
#line 7527 "sqlparser_oracle_bison.cpp"
    break;

  case 379:
#line 2301 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_HOUR");
}
#line 7535 "sqlparser_oracle_bison.cpp"
    break;

  case 380:
#line 2305 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_MINUTE");
}
#line 7543 "sqlparser_oracle_bison.cpp"
    break;

  case 381:
#line 2309 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_REGION");
}
#line 7551 "sqlparser_oracle_bison.cpp"
    break;

  case 382:
#line 2313 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMEZONE_ABBR");
}
#line 7559 "sqlparser_oracle_bison.cpp"
    break;

  case 383:
#line 2320 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BOOLEAN");
}
#line 7567 "sqlparser_oracle_bison.cpp"
    break;

  case 384:
#line 2327 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DATE");
}
#line 7575 "sqlparser_oracle_bison.cpp"
    break;

  case 385:
#line 2331 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7584 "sqlparser_oracle_bison.cpp"
    break;

  case 386:
#line 2336 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7593 "sqlparser_oracle_bison.cpp"
    break;

  case 387:
#line 2341 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7602 "sqlparser_oracle_bison.cpp"
    break;

  case 388:
#line 2346 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITH TIME ZONE");
}
#line 7610 "sqlparser_oracle_bison.cpp"
    break;

  case 389:
#line 2350 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIME WITHOUT TIME ZONE");
}
#line 7618 "sqlparser_oracle_bison.cpp"
    break;

  case 390:
#line 2354 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITH TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7627 "sqlparser_oracle_bison.cpp"
    break;

  case 391:
#line 2359 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-4].node)->text()+") WITHOUT TIME ZONE");
    delete((yyvsp[-4].node));
}
#line 7636 "sqlparser_oracle_bison.cpp"
    break;

  case 392:
#line 2364 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7645 "sqlparser_oracle_bison.cpp"
    break;

  case 393:
#line 2369 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITH TIME ZONE");
}
#line 7653 "sqlparser_oracle_bison.cpp"
    break;

  case 394:
#line 2373 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP WITHOUT TIME ZONE");
}
#line 7661 "sqlparser_oracle_bison.cpp"
    break;

  case 395:
#line 2377 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "TIMESTAMP");
}
#line 7669 "sqlparser_oracle_bison.cpp"
    break;

  case 398:
#line 2389 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7678 "sqlparser_oracle_bison.cpp"
    break;

  case 399:
#line 2394 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7687 "sqlparser_oracle_bison.cpp"
    break;

  case 400:
#line 2399 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7696 "sqlparser_oracle_bison.cpp"
    break;

  case 401:
#line 2404 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7705 "sqlparser_oracle_bison.cpp"
    break;

  case 402:
#line 2409 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-3].node)->text()+","+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-3].node));delete((yyvsp[-1].node));
}
#line 7714 "sqlparser_oracle_bison.cpp"
    break;

  case 403:
#line 2414 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7723 "sqlparser_oracle_bison.cpp"
    break;

  case 404:
#line 2419 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DEC");
}
#line 7731 "sqlparser_oracle_bison.cpp"
    break;

  case 405:
#line 2423 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "SMALLINT");
}
#line 7739 "sqlparser_oracle_bison.cpp"
    break;

  case 406:
#line 2427 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INTEGER");
}
#line 7747 "sqlparser_oracle_bison.cpp"
    break;

  case 407:
#line 2431 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "INT");
}
#line 7755 "sqlparser_oracle_bison.cpp"
    break;

  case 408:
#line 2435 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BIGINT");
}
#line 7763 "sqlparser_oracle_bison.cpp"
    break;

  case 409:
#line 2439 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NUMERIC");
}
#line 7771 "sqlparser_oracle_bison.cpp"
    break;

  case 410:
#line 2443 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DECIMAL");
}
#line 7779 "sqlparser_oracle_bison.cpp"
    break;

  case 411:
#line 2450 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7788 "sqlparser_oracle_bison.cpp"
    break;

  case 412:
#line 2455 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "DOUBLE PRECISION");
}
#line 7796 "sqlparser_oracle_bison.cpp"
    break;

  case 413:
#line 2459 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "FLOAT");
}
#line 7804 "sqlparser_oracle_bison.cpp"
    break;

  case 414:
#line 2463 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "REAL");
}
#line 7812 "sqlparser_oracle_bison.cpp"
    break;

  case 415:
#line 2470 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7821 "sqlparser_oracle_bison.cpp"
    break;

  case 416:
#line 2475 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7830 "sqlparser_oracle_bison.cpp"
    break;

  case 417:
#line 2480 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7839 "sqlparser_oracle_bison.cpp"
    break;

  case 418:
#line 2485 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7848 "sqlparser_oracle_bison.cpp"
    break;

  case 419:
#line 2490 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "VARCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7857 "sqlparser_oracle_bison.cpp"
    break;

  case 420:
#line 2495 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7866 "sqlparser_oracle_bison.cpp"
    break;

  case 421:
#line 2500 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER LARGE OBJECT");
}
#line 7874 "sqlparser_oracle_bison.cpp"
    break;

  case 422:
#line 2504 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7883 "sqlparser_oracle_bison.cpp"
    break;

  case 423:
#line 2509 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR LARGE OBJECT");
}
#line 7891 "sqlparser_oracle_bison.cpp"
    break;

  case 424:
#line 2513 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7900 "sqlparser_oracle_bison.cpp"
    break;

  case 425:
#line 2518 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CLOB");
}
#line 7908 "sqlparser_oracle_bison.cpp"
    break;

  case 426:
#line 2522 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHAR");
}
#line 7916 "sqlparser_oracle_bison.cpp"
    break;

  case 427:
#line 2526 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTER");
}
#line 7924 "sqlparser_oracle_bison.cpp"
    break;

  case 428:
#line 2533 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7933 "sqlparser_oracle_bison.cpp"
    break;

  case 429:
#line 2538 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BINARY LARGE OBJECT");
}
#line 7941 "sqlparser_oracle_bison.cpp"
    break;

  case 430:
#line 2542 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7950 "sqlparser_oracle_bison.cpp"
    break;

  case 431:
#line 2547 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "BLOB");
}
#line 7958 "sqlparser_oracle_bison.cpp"
    break;

  case 432:
#line 2554 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7967 "sqlparser_oracle_bison.cpp"
    break;

  case 433:
#line 2559 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER");
}
#line 7975 "sqlparser_oracle_bison.cpp"
    break;

  case 434:
#line 2563 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 7984 "sqlparser_oracle_bison.cpp"
    break;

  case 435:
#line 2568 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR");
}
#line 7992 "sqlparser_oracle_bison.cpp"
    break;

  case 436:
#line 2572 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8001 "sqlparser_oracle_bison.cpp"
    break;

  case 437:
#line 2577 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8010 "sqlparser_oracle_bison.cpp"
    break;

  case 438:
#line 2582 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8019 "sqlparser_oracle_bison.cpp"
    break;

  case 439:
#line 2587 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR VARYING("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8028 "sqlparser_oracle_bison.cpp"
    break;

  case 440:
#line 2592 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8037 "sqlparser_oracle_bison.cpp"
    break;

  case 441:
#line 2597 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NATIONAL CHARACTER LARGE OBJECT");
}
#line 8045 "sqlparser_oracle_bison.cpp"
    break;

  case 442:
#line 2601 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8054 "sqlparser_oracle_bison.cpp"
    break;

  case 443:
#line 2606 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR LARGE OBJECT");
}
#line 8062 "sqlparser_oracle_bison.cpp"
    break;

  case 444:
#line 2610 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB("+(yyvsp[-1].node)->text()+")");
    delete((yyvsp[-1].node));
}
#line 8071 "sqlparser_oracle_bison.cpp"
    break;

  case 445:
#line 2615 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCLOB");
}
#line 8079 "sqlparser_oracle_bison.cpp"
    break;

  case 446:
#line 2619 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "NCHAR");
}
#line 8087 "sqlparser_oracle_bison.cpp"
    break;

  case 447:
#line 2626 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-2].node)->text()+" "+(yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-2].node));delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8096 "sqlparser_oracle_bison.cpp"
    break;

  case 448:
#line 2631 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8105 "sqlparser_oracle_bison.cpp"
    break;

  case 449:
#line 2636 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[-1].node)->text()+" "+(yyvsp[0].node)->text());
    delete((yyvsp[-1].node));delete((yyvsp[0].node));
}
#line 8114 "sqlparser_oracle_bison.cpp"
    break;

  case 450:
#line 2641 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, (yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 8123 "sqlparser_oracle_bison.cpp"
    break;

  case 451:
#line 2649 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CHARACTERS");
}
#line 8131 "sqlparser_oracle_bison.cpp"
    break;

  case 452:
#line 2653 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "CODE_UNITS");
}
#line 8139 "sqlparser_oracle_bison.cpp"
    break;

  case 453:
#line 2657 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "OCTETS");
}
#line 8147 "sqlparser_oracle_bison.cpp"
    break;

  case 454:
#line 2664 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "K");
}
#line 8155 "sqlparser_oracle_bison.cpp"
    break;

  case 455:
#line 2668 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "M");
}
#line 8163 "sqlparser_oracle_bison.cpp"
    break;

  case 456:
#line 2672 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "G");
}
#line 8171 "sqlparser_oracle_bison.cpp"
    break;

  case 457:
#line 2679 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_ALL, "ALL");
}
#line 8179 "sqlparser_oracle_bison.cpp"
    break;

  case 458:
#line 2683 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
#line 8187 "sqlparser_oracle_bison.cpp"
    break;

  case 459:
#line 2689 "oracle.y"
                { (yyval.ival) = 0; }
#line 8193 "sqlparser_oracle_bison.cpp"
    break;

  case 460:
#line 2690 "oracle.y"
                { (yyval.ival) = 1; }
#line 8199 "sqlparser_oracle_bison.cpp"
    break;

  case 461:
#line 2691 "oracle.y"
                { (yyval.ival) = 2; }
#line 8205 "sqlparser_oracle_bison.cpp"
    break;

  case 462:
#line 2695 "oracle.y"
                { (yyval.node) = nullptr; }
#line 8211 "sqlparser_oracle_bison.cpp"
    break;

  case 464:
#line 2700 "oracle.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 8217 "sqlparser_oracle_bison.cpp"
    break;

  case 467:
#line 2711 "oracle.y"
{
    (yyval.node) = Node::makeTerminalNode(E_STRING, "COLLATE "+(yyvsp[0].node)->text());
    delete((yyvsp[0].node));
}
#line 8226 "sqlparser_oracle_bison.cpp"
    break;

  case 472:
#line 2730 "oracle.y"
            { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INT"); }
#line 8232 "sqlparser_oracle_bison.cpp"
    break;

  case 473:
#line 2731 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY"); }
#line 8238 "sqlparser_oracle_bison.cpp"
    break;

  case 474:
#line 2732 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BINARY"); }
#line 8244 "sqlparser_oracle_bison.cpp"
    break;

  case 475:
#line 2733 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
#line 8250 "sqlparser_oracle_bison.cpp"
    break;

  case 476:
#line 2734 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIME");  }
#line 8256 "sqlparser_oracle_bison.cpp"
    break;

  case 477:
#line 2735 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTERS"); }
#line 8262 "sqlparser_oracle_bison.cpp"
    break;

  case 478:
#line 2736 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NCHAR"); }
#line 8268 "sqlparser_oracle_bison.cpp"
    break;

  case 479:
#line 2740 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "INTERVAL"); }
#line 8274 "sqlparser_oracle_bison.cpp"
    break;

  case 480:
#line 2742 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CLOB"); }
#line 8280 "sqlparser_oracle_bison.cpp"
    break;

  case 481:
#line 2743 "oracle.y"
                    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BLOB"); }
#line 8286 "sqlparser_oracle_bison.cpp"
    break;

  case 482:
#line 2744 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NCLOB"); }
#line 8292 "sqlparser_oracle_bison.cpp"
    break;

  case 483:
#line 2745 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NUMERIC"); }
#line 8298 "sqlparser_oracle_bison.cpp"
    break;

  case 484:
#line 2746 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CHARACTER"); }
#line 8304 "sqlparser_oracle_bison.cpp"
    break;

  case 485:
#line 2747 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BIGINT"); }
#line 8310 "sqlparser_oracle_bison.cpp"
    break;

  case 486:
#line 2748 "oracle.y"
                    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DEC"); }
#line 8316 "sqlparser_oracle_bison.cpp"
    break;

  case 487:
#line 2749 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NATIONAL"); }
#line 8322 "sqlparser_oracle_bison.cpp"
    break;

  case 488:
#line 2750 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DOUBLE"); }
#line 8328 "sqlparser_oracle_bison.cpp"
    break;

  case 489:
#line 2751 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARYING"); }
#line 8334 "sqlparser_oracle_bison.cpp"
    break;

  case 490:
#line 2752 "oracle.y"
                    { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REAL"); }
#line 8340 "sqlparser_oracle_bison.cpp"
    break;

  case 491:
#line 2757 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
#line 8346 "sqlparser_oracle_bison.cpp"
    break;

  case 492:
#line 2758 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
#line 8352 "sqlparser_oracle_bison.cpp"
    break;

  case 493:
#line 2759 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
#line 8358 "sqlparser_oracle_bison.cpp"
    break;

  case 494:
#line 2760 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CAST"); }
#line 8364 "sqlparser_oracle_bison.cpp"
    break;

  case 495:
#line 2761 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
#line 8370 "sqlparser_oracle_bison.cpp"
    break;

  case 496:
#line 2762 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
#line 8376 "sqlparser_oracle_bison.cpp"
    break;

  case 497:
#line 2763 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FOLLOWING"); }
#line 8382 "sqlparser_oracle_bison.cpp"
    break;

  case 498:
#line 2764 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
#line 8388 "sqlparser_oracle_bison.cpp"
    break;

  case 499:
#line 2765 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
#line 8394 "sqlparser_oracle_bison.cpp"
    break;

  case 500:
#line 2766 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
#line 8400 "sqlparser_oracle_bison.cpp"
    break;

  case 501:
#line 2767 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
#line 8406 "sqlparser_oracle_bison.cpp"
    break;

  case 502:
#line 2768 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
#line 8412 "sqlparser_oracle_bison.cpp"
    break;

  case 503:
#line 2769 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECEDING"); }
#line 8418 "sqlparser_oracle_bison.cpp"
    break;

  case 504:
#line 2770 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
#line 8424 "sqlparser_oracle_bison.cpp"
    break;

  case 505:
#line 2771 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "RECURSIVE"); }
#line 8430 "sqlparser_oracle_bison.cpp"
    break;

  case 506:
#line 2772 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
#line 8436 "sqlparser_oracle_bison.cpp"
    break;

  case 507:
#line 2773 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
#line 8442 "sqlparser_oracle_bison.cpp"
    break;

  case 508:
#line 2774 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
#line 8448 "sqlparser_oracle_bison.cpp"
    break;

  case 509:
#line 2775 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SECOND"); }
#line 8454 "sqlparser_oracle_bison.cpp"
    break;

  case 510:
#line 2776 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "UNBOUNDED"); }
#line 8460 "sqlparser_oracle_bison.cpp"
    break;

  case 511:
#line 2777 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
#line 8466 "sqlparser_oracle_bison.cpp"
    break;

  case 512:
#line 2778 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
#line 8472 "sqlparser_oracle_bison.cpp"
    break;

  case 513:
#line 2779 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
#line 8478 "sqlparser_oracle_bison.cpp"
    break;

  case 514:
#line 2781 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OF"); }
#line 8484 "sqlparser_oracle_bison.cpp"
    break;

  case 515:
#line 2782 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
#line 8490 "sqlparser_oracle_bison.cpp"
    break;

  case 516:
#line 2783 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DESC"); }
#line 8496 "sqlparser_oracle_bison.cpp"
    break;

  case 517:
#line 2784 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
#line 8502 "sqlparser_oracle_bison.cpp"
    break;

  case 518:
#line 2785 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
#line 8508 "sqlparser_oracle_bison.cpp"
    break;

  case 519:
#line 2786 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
#line 8514 "sqlparser_oracle_bison.cpp"
    break;

  case 520:
#line 2787 "oracle.y"
                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "EXCLUDE"); }
#line 8520 "sqlparser_oracle_bison.cpp"
    break;

  case 521:
#line 2788 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "ASC"); }
#line 8526 "sqlparser_oracle_bison.cpp"
    break;

  case 522:
#line 2789 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }
#line 8532 "sqlparser_oracle_bison.cpp"
    break;

  case 523:
#line 2790 "oracle.y"
                                { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }
#line 8538 "sqlparser_oracle_bison.cpp"
    break;

  case 524:
#line 2791 "oracle.y"
                                        { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
#line 8544 "sqlparser_oracle_bison.cpp"
    break;

  case 525:
#line 2792 "oracle.y"
              { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "FIRST"); }
#line 8550 "sqlparser_oracle_bison.cpp"
    break;

  case 526:
#line 2793 "oracle.y"
              { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SAMPLE"); }
#line 8556 "sqlparser_oracle_bison.cpp"
    break;

  case 527:
#line 2794 "oracle.y"
              { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "SESSION"); }
#line 8562 "sqlparser_oracle_bison.cpp"
    break;

  case 528:
#line 2795 "oracle.y"
             { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "BEGIN"); }
#line 8568 "sqlparser_oracle_bison.cpp"
    break;

  case 529:
#line 2796 "oracle.y"
               { (yyval.node) = Node::makeTerminalNode(E_IDENTIFIER, "DECLARE"); }
#line 8574 "sqlparser_oracle_bison.cpp"
    break;

  case 539:
#line 2815 "oracle.y"
                { (yyval.node)=NULL; }
#line 8580 "sqlparser_oracle_bison.cpp"
    break;

  case 540:
#line 2817 "oracle.y"
{
    (yyval.node) = (yyvsp[0].node);
}
#line 8588 "sqlparser_oracle_bison.cpp"
    break;

  case 541:
#line 2824 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_FOR_UPDATE, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &FOR_UPDATE_FORMAT_HANA;
}
#line 8597 "sqlparser_oracle_bison.cpp"
    break;

  case 542:
#line 2830 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8603 "sqlparser_oracle_bison.cpp"
    break;

  case 543:
#line 2832 "oracle.y"
{
    Node * p_of = Node::makeTerminalNode(E_STRING, "OF");
    (yyval.node) = Node::makeNonTerminalNode(E_OF_COLUMS, 2, p_of, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8613 "sqlparser_oracle_bison.cpp"
    break;

  case 545:
#line 2841 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
#line 8622 "sqlparser_oracle_bison.cpp"
    break;

  case 546:
#line 2847 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8628 "sqlparser_oracle_bison.cpp"
    break;

  case 547:
#line 2848 "oracle.y"
                  { (yyval.node) = Node::makeTerminalNode(E_STRING, "SKIP LOCKED");}
#line 8634 "sqlparser_oracle_bison.cpp"
    break;

  case 548:
#line 2851 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8640 "sqlparser_oracle_bison.cpp"
    break;

  case 549:
#line 2852 "oracle.y"
             { (yyval.node) = Node::makeTerminalNode(E_NOWAIT, "NOWAIT");}
#line 8646 "sqlparser_oracle_bison.cpp"
    break;

  case 550:
#line 2854 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_WAIT_INT, 1,  (yyvsp[0].node));
    (yyval.node)->serialize_format = &WAIT_TIME_FORMAT;
}
#line 8655 "sqlparser_oracle_bison.cpp"
    break;

  case 551:
#line 2861 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_FETCH, 2,  (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8664 "sqlparser_oracle_bison.cpp"
    break;

  case 552:
#line 2867 "oracle.y"
     { (yyval.node) = Node::makeTerminalNode(E_STRING, "ROW");}
#line 8670 "sqlparser_oracle_bison.cpp"
    break;

  case 553:
#line 2868 "oracle.y"
        { (yyval.node) = Node::makeTerminalNode(E_STRING, "ROWS");}
#line 8676 "sqlparser_oracle_bison.cpp"
    break;

  case 554:
#line 2871 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8682 "sqlparser_oracle_bison.cpp"
    break;

  case 559:
#line 2880 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8688 "sqlparser_oracle_bison.cpp"
    break;

  case 560:
#line 2882 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_OFFSET_ROW, 2,  (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &OFFSET_SERIALIZE_FORMAT;
}
#line 8697 "sqlparser_oracle_bison.cpp"
    break;

  case 561:
#line 2889 "oracle.y"
           { (yyval.node) = Node::makeTerminalNode(E_STRING, "FIRST");}
#line 8703 "sqlparser_oracle_bison.cpp"
    break;

  case 562:
#line 2890 "oracle.y"
           { (yyval.node) = Node::makeTerminalNode(E_STRING, "NEXT");}
#line 8709 "sqlparser_oracle_bison.cpp"
    break;

  case 563:
#line 2893 "oracle.y"
          { (yyval.node) = Node::makeTerminalNode(E_STRING, "ONLY");}
#line 8715 "sqlparser_oracle_bison.cpp"
    break;

  case 564:
#line 2894 "oracle.y"
                { (yyval.node) = Node::makeTerminalNode(E_STRING, "WITH TIES");}
#line 8721 "sqlparser_oracle_bison.cpp"
    break;

  case 565:
#line 2897 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8727 "sqlparser_oracle_bison.cpp"
    break;

  case 566:
#line 2899 "oracle.y"
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
#line 8750 "sqlparser_oracle_bison.cpp"
    break;

  case 567:
#line 2918 "oracle.y"
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
#line 8772 "sqlparser_oracle_bison.cpp"
    break;

  case 568:
#line 2938 "oracle.y"
                  {(yyval.node) = nullptr;}
#line 8778 "sqlparser_oracle_bison.cpp"
    break;

  case 570:
#line 2943 "oracle.y"
{
    std::string name = "SEARCH DEPTH FIRST BY ";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EROA_SEARCH_CLAUSE, 5, prename, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEARCH_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8789 "sqlparser_oracle_bison.cpp"
    break;

  case 571:
#line 2950 "oracle.y"
{
    std::string name = "SEARCH BREADTH FIRST BY ";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EROA_SEARCH_CLAUSE, 5, prename, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SEARCH_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8800 "sqlparser_oracle_bison.cpp"
    break;

  case 572:
#line 2958 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8806 "sqlparser_oracle_bison.cpp"
    break;

  case 574:
#line 2964 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_CYCLE_CLAUSE, 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &CYCLE_CLAUSE_SERIALIZE_FORMAT_ORA;
}
#line 8815 "sqlparser_oracle_bison.cpp"
    break;

  case 575:
#line 2970 "oracle.y"
          {(yyval.node) = nullptr;}
#line 8821 "sqlparser_oracle_bison.cpp"
    break;

  case 576:
#line 2971 "oracle.y"
           {(yyval.node) = Node::makeTerminalNode(E_STRING, "NOCYCLE"); }
#line 8827 "sqlparser_oracle_bison.cpp"
    break;

  case 577:
#line 2972 "oracle.y"
                 {(yyval.node) = Node::makeTerminalNode(E_STRING, "NOCYCLE PRIOR"); }
#line 8833 "sqlparser_oracle_bison.cpp"
    break;

  case 578:
#line 2973 "oracle.y"
         {(yyval.node) = Node::makeTerminalNode(E_STRING, "PRIOR"); }
#line 8839 "sqlparser_oracle_bison.cpp"
    break;

  case 579:
#line 2977 "oracle.y"
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
#line 8854 "sqlparser_oracle_bison.cpp"
    break;

  case 580:
#line 2990 "oracle.y"
{
    std::string name = "START WITH";
    Node * prename  = Node::makeTerminalNode(E_STRING, name);
    (yyval.node) = Node::makeNonTerminalNode(EORA_START_WITH, 2, prename, (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8865 "sqlparser_oracle_bison.cpp"
    break;

  case 581:
#line 2999 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8874 "sqlparser_oracle_bison.cpp"
    break;

  case 582:
#line 3004 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[0].node), nullptr);
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8883 "sqlparser_oracle_bison.cpp"
    break;

  case 583:
#line 3009 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(EORA_HIERARCHICAL_CLAUSE, 2, (yyvsp[-1].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
#line 8892 "sqlparser_oracle_bison.cpp"
    break;

  case 584:
#line 3017 "oracle.y"
{
    Node * name = Node::makeTerminalNode(E_STRING, "SAMPLE BLOCK");
    (yyval.node) = Node::makeNonTerminalNode(EORA_SAMPLE_CLAUSE, 3, name, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SAMPLE_CLAUSE_SERIALIZE_FORMAT;
}
#line 8902 "sqlparser_oracle_bison.cpp"
    break;

  case 585:
#line 3023 "oracle.y"
{
    Node * name = Node::makeTerminalNode(E_STRING, "SAMPLE");
    (yyval.node) = Node::makeNonTerminalNode(EORA_SAMPLE_CLAUSE, 3, name, (yyvsp[-2].node), (yyvsp[0].node));
    (yyval.node)->serialize_format = &SAMPLE_CLAUSE_SERIALIZE_FORMAT;
}
#line 8912 "sqlparser_oracle_bison.cpp"
    break;

  case 586:
#line 3031 "oracle.y"
              {(yyval.node) = nullptr;}
#line 8918 "sqlparser_oracle_bison.cpp"
    break;

  case 587:
#line 3033 "oracle.y"
{
   (yyval.node) = Node::makeNonTerminalNode(EORA_SEED_VALUE, 1, (yyvsp[-1].node));
   (yyval.node)->serialize_format = &EORA_SEED_VALUE_SERIALIZE_FORMAT;
}
#line 8927 "sqlparser_oracle_bison.cpp"
    break;

  case 588:
#line 3041 "oracle.y"
{
    (yyval.node) = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, (yyvsp[-1].node), (yyvsp[0].node), nullptr, nullptr, nullptr);
    (yyval.node)->serialize_format = &ORA_AS_SERIALIZE_FORMAT;
}
#line 8936 "sqlparser_oracle_bison.cpp"
    break;


#line 8940 "sqlparser_oracle_bison.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp, yylsp, result, scanner);
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
#line 3048 "oracle.y"

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

