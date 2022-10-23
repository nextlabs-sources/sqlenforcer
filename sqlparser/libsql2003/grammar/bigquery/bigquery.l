/**
 * lexer
 *
 *
 */


/***************************
 ** Section 1: Definitions
 ***************************/
%{

#include "node.h"
#include "sqlparser_bigquery_bison.h"
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define YYSTYPE         BIGQUERY_STYPE
#define YYLTYPE         BIGQUERY_LTYPE

std::string escape_double_quotation_bigquery(const std::string& src, char c) {
    assert(c == '"' || c == '`' || c == ']');
    std::string ret = "";
    for (size_t i = 0; i < src.length(); ++i) {
        if (src[i] == c && src[1+i] == c) {
            ret += c;
            ++i;    // skip one
        }
        else
            ret += src[i];
    }
    return ret;
}

#define YY_USER_ACTION \
		yylloc->first_line = yylloc->last_line; \
		yylloc->first_column = yylloc->last_column; \
		for(int i = 0; yytext[i] != '\0'; i++) { \
				if(yytext[i] == '\n') { \
						yylloc->last_line++; \
						yylloc->last_column = 0; \
				} \
				else { \
						yylloc->last_column++; \
				} \
		}

#define TOKEN(name) { return BIGQUERY_##name; }


%}


/***************************
 ** Section 2: Rules
 ***************************/

/* Define the output files */
%option header-file="sqlparser_bigquery_flex.h"
%option outfile="sqlparser_bigquery_flex.cpp"

/* Make reentrant */
%option reentrant
%option bison-bridge

/* performance tweeks */
%option never-interactive
%option batch

/* other flags */
%option noyywrap
%option nounput
%option warn
%option case-insensitive
%option prefix="bigquery_"
%option bison-locations
/* %option nodefault */


%x hint
%x sq
%x qq

space         [ \t\n\r\f]
non_newline   [^\n\r]
sql_comment   (("--"|"#"){non_newline}*)
whitespace    ({space}+|{sql_comment})
hint_begin    (\/\*\+({space}*hint{space}+)?)
c_cmt_begin   \/\*(?:[^\+])
c_cmt_end     \*+\/
c_cmt_cnt     ([^*]|\*+[^/*])*
c_comment     ({c_cmt_begin}{c_cmt_cnt}{c_cmt_end})
comment       ({c_comment}|{sql_comment})
identifer         ([A-Za-z_][A_Za-z0-9_]*)
system_variable  (@@[A-Za-z_][A_Za-z0-9_]*)
temp_variable (@[A-Za-z_][A_Za-z0-9_]*)


backslash     \\
quote         '
bquote        [Bb][']
rquote        [Rr][']
rbquote       [Rr][Bb][']
sqbegin       {quote}
sqend         {quote}
sqdouble      {quote}{quote}
sqescape      {backslash}{quote}
sqcontent     [^'\\]*

sqoctal       [\\][0-7]{1,3}
sqnewline     {quote}{whitespace}{quote}


qq          ["]
b_qq        [Bb]["]
r_qq        [Rr]["]
rb_qq       [Rr][Br]["]
db_qq       {qq}{qq}
sp_qq       {backslash}{qq}
qq_content     [^"\\]*



/***************************
 ** Section 3: Rules
 ***************************/
%%
ALL                 TOKEN(ALL)              /* SQL-2003-R */
AND                 TOKEN(AND)              /* SQL-2003-R */
ANY                 TOKEN(ANY)              /* SQL-2003-R */
AS                  TOKEN(AS)               /* SQL-2003-R */
ASC                 TOKEN(ASC)              /* SQL-2003-N */
AVG                 TOKEN(AVG)              /* SQL-2003-N */
BETWEEN             TOKEN(BETWEEN)          /* SQL-2003-R */
BY                  TOKEN(BY)               /* SQL-2003-R */
CASE                TOKEN(CASE)             /* SQL-2003-R */
CAST                TOKEN(CAST)             /* SQL-2003-R */
CALL                TOKEN(CALL)             /* SQL-2003-R */
COALESCE            TOKEN(COALESCE)         /* SQL-2003-N */
CODE_UNITS          TOKEN(CODE_UNITS)       /* SQL-2003-N */
COLLATE             TOKEN(COLLATE)          /* SQL-2003-R */
CONVERT             TOKEN(CONVERT)          /* SQL-2003-N */
CORRESPONDING       TOKEN(CORRESPONDING)    /* SQL-2003-R */
COUNT               TOKEN(COUNT)            /* SQL-2003-N */
CROSS               TOKEN(CROSS)            /* SQL-2003-R */
CUME_DIST           TOKEN(CUME_DIST)        /* SQL-2003-N */
CURRENT             TOKEN(CURRENT)          /* SQL-2003-R */
CURRENT_TIMESTAMP   TOKEN(CURRENT_TIMESTAMP)/* SQL-2003-R */
CURRENT_USER        TOKEN(CURRENT_USER)     /* SQL-2003-R */
DAY                 TOKEN(DAY)              /* SQL-2003-R */
DEC                 TOKEN(DEC)              /* SQL-2003-R */
DEFAULT             TOKEN(DEFAULT)          /* SQL-2003-R */
DELETE              TOKEN(DELETE)           /* SQL-2003-R */
DENSE_RANK          TOKEN(DENSE_RANK)       /* SQL-2003-N */
DESC                TOKEN(DESC)             /* SQL-2003-N */
DISTINCT            TOKEN(DISTINCT)         /* SQL-2003-R */
ELSE                TOKEN(ELSE)             /* SQL-2003-R */
END                 TOKEN(END)              /* SQL-2003-R */
END_P               TOKEN(END_P)            /* LEX-INNER  */
ESCAPE              TOKEN(ESCAPE)           /* SQL-2003-R */
EXCEPT              TOKEN(EXCEPT)           /* SQL-2003-R */
EXCLUDE             TOKEN(EXCLUDE)          /* SQL-2003-N */
EXISTS              TOKEN(EXISTS)           /* SQL-2003-R */
FOLLOWING           TOKEN(FOLLOWING)        /* SQL-2003-N */
FOR                 TOKEN(FOR)              /* SQL-2003-R */
FROM                TOKEN(FROM)             /* SQL-2003-R */
FULL                TOKEN(FULL)             /* SQL-2003-R */
G                   TOKEN(G)                /* SQL-2003-N */
GROUP               TOKEN(GROUP)            /* SQL-2003-R */
GROUPING            TOKEN(GROUPING)         /* SQL-2003-R */
HAVING              TOKEN(HAVING)           /* SQL-2003-R */
HOUR                TOKEN(HOUR)             /* SQL-2003-R */
IN                  TOKEN(IN)               /* SQL-2003-R */
INNER               TOKEN(INNER)            /* SQL-2003-R */
INSERT              TOKEN(INSERT)           /* SQL-2003-R */
INTERSECT           TOKEN(INTERSECT)        /* SQL-2003-R */
INTERVAL            TOKEN(INTERVAL)         /* SQL-2003-R */
INTO                TOKEN(INTO)             /* SQL-2003-R */
IS                  TOKEN(IS)               /* SQL-2003-R */
JOIN                TOKEN(JOIN)             /* SQL-2003-R */
K                   TOKEN(K)                /* SQL-2003-N */
LARGE               TOKEN(LARGE)            /* SQL-2003-R */
LEFT                TOKEN(LEFT)             /* SQL-2003-R */
LIKE                TOKEN(LIKE)             /* SQL-2003-R */
M                   TOKEN(M)                /* SQL-2003-N */
MAX                 TOKEN(MAX)              /* SQL-2003-N */
MIN                 TOKEN(MIN)              /* SQL-2003-N */
MINUTE              TOKEN(MINUTE)           /* SQL-2003-R */
MOD                 TOKEN(MOD)              /* SQL-2003-N, here is reserved as an operator */
MONTH               TOKEN(MONTH)            /* SQL-2003-R */
MULTISET            TOKEN(MULTISET)         /* SQL-2003-R */
NATIONAL            TOKEN(NATIONAL)         /* SQL-2003-R */
NATURAL             TOKEN(NATURAL)          /* SQL-2003-R */
NO                  TOKEN(NO)               /* SQL-2003-R */
NOT                 TOKEN(NOT)              /* SQL-2003-R */
NULLIF              TOKEN(NULLIF)           /* SQL-2003-N */
NUMERIC             TOKEN(NUMERIC)          /* SQL-2003-R */
OBJECT              TOKEN(OBJECT)           /* SQL-2003-N */
OCTETS              TOKEN(OCTETS)           /* SQL-2003-N */
OF                  TOKEN(OF)               /* SQL-2003-R */
ON                  TOKEN(ON)               /* SQL-2003-R */
ONLY                TOKEN(ONLY)             /* SQL-2003-R */
OR                  TOKEN(OR)               /* SQL-2003-R */
ORDER               TOKEN(ORDER)            /* SQL-2003-R */
OTHERS              TOKEN(OTHERS)           /* SQL-2003-N */
OUTER               TOKEN(OUTER)            /* SQL-2003-R */
OVER                TOKEN(OVER)             /* SQL-2003-R */
PARTITION           TOKEN(PARTITION)        /* SQL-2003-R */
PERCENT_RANK        TOKEN(PERCENT_RANK)     /* SQL-2003-N */
PRECEDING           TOKEN(PRECEDING)        /* SQL-2003-N */
PRECISION           TOKEN(PRECISION)        /* SQL-2003-R */
RANGE               TOKEN(RANGE)            /* SQL-2003-R */
RANK                TOKEN(RANK)             /* SQL-2003-N */
READ                TOKEN(READ)             /* SQL-2003-N */
REAL                TOKEN(REAL)             /* SQL-2003-R */
RECURSIVE           TOKEN(RECURSIVE)        /* SQL-2003-R */
REF                 TOKEN(REF)              /* SQL-2003-R */
RIGHT               TOKEN(RIGHT)            /* SQL-2003-R */
ROW                 TOKEN(ROW)              /* SQL-2003-R */
ROWS                TOKEN(ROWS)             /* SQL-2003-R */
ROW_NUMBER          TOKEN(ROW_NUMBER)       /* SQL-2003-N */
SCOPE               TOKEN(SCOPE)            /* SQL-2003-? */
SECOND              TOKEN(SECOND)           /* SQL-2003-R */
SELECT              TOKEN(SELECT)           /* SQL-2003-R */
SESSION_USER        TOKEN(SESSION_USER)     /* SQL-2003-R */
SET                 TOKEN(SET)              /* SQL-2003-R */
SETS                TOKEN(SETS)             /* SQL-2003-N */
SMALLINT            TOKEN(SMALLINT)         /* SQL-2003-R */
SOME                TOKEN(SOME)             /* SQL-2003-R */
STDDEV_POP          TOKEN(STDDEV_POP)       /* SQL-2003-N */
STDDEV_SAMP         TOKEN(STDDEV_SAMP)      /* SQL-2003-N */
SUM                 TOKEN(SUM)              /* SQL-2003-N */
SYSTEM_USER         TOKEN(SYSTEM_USER)      /* SQL-2003-R */
THEN                TOKEN(THEN)             /* SQL-2003-R */
TIES                TOKEN(TIES)             /* SQL-2003-N */
TO                  TOKEN(TO)               /* SQL-2003-R */
UNBOUNDED           TOKEN(UNBOUNDED)        /* SQL-2003-N */
UNION               TOKEN(UNION)            /* SQL-2003-R */
UPDATE              TOKEN(UPDATE)           /* SQL-2003-R */
USING               TOKEN(USING)            /* SQL-2003-R */
VALUES              TOKEN(VALUES)           /* SQL-2003-R */
VARCHAR             TOKEN(VARCHAR)          /* SQL-2003-R */
VARYING             TOKEN(VARYING)          /* SQL-2003-R */
VAR_POP             TOKEN(VAR_POP)          /* SQL-2003-R */
VAR_SAMP            TOKEN(VAR_SAMP)         /* SQL-2003-R */
WHEN                TOKEN(WHEN)             /* SQL-2003-R */
WHERE               TOKEN(WHERE)            /* SQL-2003-R */
WITH                TOKEN(WITH)             /* SQL-2003-R */
WITHOUT             TOKEN(WITHOUT)          /* SQL-2003-R */
YEAR                TOKEN(YEAR)             /* SQL-2003-R */
ZONE                TOKEN(ZONE)             /* SQL-2003-N */
LIMIT               TOKEN(LIMIT)            /* bigquery */
OFFSET              TOKEN(OFFSET)           /* bigquery */
REPLACE             TOKEN(REPLACE)          /* bigquery */
NULLS               TOKEN(NULLS)            /* bigquery */
FIRST               TOKEN(FIRST)            /* bigquery */
LAST                TOKEN(LAST)             /* bigquery */
ORDINAL             TOKEN(ORDINAL)          /* bigquery */
SAFE_OFFSET         TOKEN(SAFE_OFFSET)      /* bigquery */
SAFE_ORDINAL        TOKEN(SAFE_ORDINAL)     /* bigquery */
STRUCT              TOKEN(STRUCT)           /* bigquery datatype */
INT64               TOKEN(INT64)            /* bigquery */
FLOAT64             TOKEN(FLOAT64)          /* bigquery */
STRING              TOKEN(STRING)           /* bigquery */
BYTES               TOKEN(BYTES)            /* bigquery */
DATETIME            TOKEN(DATETIME)         /* bigquery */
ARRAY               TOKEN(ARRAY)            /* bigquery */
DATE                TOKEN(DATE)             /* bigquery */
TIME                TOKEN(TIME)             /* bigquery */
TIMESTAMP           TOKEN(TIMESTAMP)        /* bigquery */
BOOL                TOKEN(BOOL)             /* bigquery */
VALUE               TOKEN(VALUE)            /* bigquery  no reserved */
UNNEST              TOKEN(UNNEST)           /* bigquery */
FIRST_VALUE         TOKEN(FIRST_VALUE)      /* bigquery function */
RESPECT             TOKEN(RESPECT)          /* bigquery function */
IGNORE              TOKEN(IGNORE)           /* bigquery function */
WINDOW              TOKEN(WINDOW)           /* bigquery function */
LAST_VALUE          TOKEN(LAST_VALUE)       /* bigquery function */
NTH_VALUE           TOKEN(NTH_VALUE)        /* bigquery function */
LEAD                TOKEN(LEAD)             /* bigquery function */
LAG                 TOKEN(LAG)              /* bigquery function */
PERCENTILE_CONT     TOKEN(PERCENTILE_CONT)  /* bigquery function */
PERCENTILE_DISC     TOKEN(PERCENTILE_DISC)  /* bigquery function */
NTILE               TOKEN(NTILE)            /* bigquery function */
ARRAY_AGG           TOKEN(ARRAY_AGG)        /* bigquery function */
CORR                TOKEN(CORR)             /* bigquery function */
COVAR_POP           TOKEN(COVAR_POP)        /* bigquery function */
COVAR_SAMP          TOKEN(COVAR_SAMP)       /* bigquery function */
STRING_AGG          TOKEN(STRING_AGG)       /* bigquery function */
ANY_VALUE           TOKEN(ANY_VALUE)        /* bigquery function */
COUNTIF             TOKEN(COUNTIF)          /* bigquery function */
SAFE_CAST           TOKEN(SAFE_CAST)        /* bigquery function */
ARRAY_CONCAT_AGG    TOKEN(ARRAY_CONCAT_AGG) /* bigquery function */
BIT_XOR             TOKEN(BIT_XOR)          /* bigquery function */
LOGICAL_AND         TOKEN(LOGICAL_AND)      /* bigquery function */
LOGICAL_OR          TOKEN(LOGICAL_OR)       /* bigquery function */
APPROX_COUNT_DISTINCT     TOKEN(APPROX_COUNT_DISTINCT)       /* bigquery function */
APPROX_QUANTILES          TOKEN(APPROX_QUANTILES)            /* bigquery function */
APPROX_TOP_COUNT          TOKEN(APPROX_TOP_COUNT)            /* bigquery function */
AT                  TOKEN(AT)      /* bigquery function */
WEEK                TOKEN(WEEK)      /* bigquery function */
QUARTER             TOKEN(QUARTER)      /* bigquery function */
DAYOFWEEK           TOKEN(DAYOFWEEK)      /* bigquery function */
DAYOFYEAR           TOKEN(DAYOFYEAR)      /* bigquery function */
ISOWEEK             TOKEN(ISOWEEK)      /* bigquery function */
ISOYEAR             TOKEN(ISOYEAR)      /* bigquery function */
MICROSECOND         TOKEN(MICROSECOND)      /* bigquery function */
MILLISECOND         TOKEN(MILLISECOND)      /* bigquery function */
SUNDAY              TOKEN(SUNDAY)      /* bigquery function */
MONDAY              TOKEN(MONDAY)      /* bigquery function */
TUESDAY             TOKEN(TUESDAY)      /* bigquery function */
WEDNESDAY           TOKEN(WEDNESDAY)      /* bigquery function */
THURSDAY            TOKEN(THURSDAY)      /* bigquery function */
FRIDAY              TOKEN(FRIDAY)      /* bigquery function */
SATURDAY            TOKEN(SATURDAY)      /* bigquery function */
EXTRACT             TOKEN(EXTRACT)      /* bigquery function */
DATE_ADD            TOKEN(DATE_ADD)      /* bigquery function */
DATE_SUB            TOKEN(DATE_SUB)      /* bigquery function */
DATE_DIFF           TOKEN(DATE_DIFF)      /* bigquery function */
DATE_TRUNC          TOKEN(DATE_TRUNC)      /* bigquery function */
DATETIME_ADD        TOKEN(DATETIME_ADD)      /* bigquery function */
DATETIME_SUB        TOKEN(DATETIME_SUB)      /* bigquery function */
DATETIME_DIFF       TOKEN(DATETIME_DIFF)      /* bigquery function */
DATETIME_TRUNC      TOKEN(DATETIME_TRUNC)      /* bigquery function */
TIME_ADD            TOKEN(TIME_ADD)      /* bigquery function */
TIME_SUB            TOKEN(TIME_SUB)      /* bigquery function */
TIME_DIFF           TOKEN(TIME_DIFF)      /* bigquery function */
TIME_TRUNC          TOKEN(TIME_TRUNC)      /* bigquery function */
TIMESTAMP_ADD       TOKEN(TIMESTAMP_ADD)      /* bigquery function */
TIMESTAMP_SUB       TOKEN(TIMESTAMP_SUB)      /* bigquery function */
TIMESTAMP_DIFF      TOKEN(TIMESTAMP_DIFF)      /* bigquery function */
TIMESTAMP_TRUNC     TOKEN(TIMESTAMP_TRUNC)      /* bigquery function */
TO_JSON_STRING      TOKEN(TO_JSON_STRING)      /* bigquery function */
STDDEV              TOKEN(STDDEV)      /* bigquery function */
VARIANCE            TOKEN(VARIANCE)      /* bigquery function */
STARTS_WITH         TOKEN(STARTS_WITH)      /* bigquery function */
ENDS_WITH           TOKEN(ENDS_WITH)      /* bigquery function */
REGEXP_CONTAINS     TOKEN(REGEXP_CONTAINS)      /* bigquery function */
REGEXP_EXTRACT      TOKEN(REGEXP_EXTRACT)      /* bigquery function */
REGEXP_REPLACE      TOKEN(REGEXP_REPLACE)      /* bigquery function */
GENERATE_DATE_ARRAY TOKEN(GENERATE_DATE_ARRAY)     /* bigquery function */
GENERATE_TIMESTAMP_ARRAY TOKEN(GENERATE_TIMESTAMP_ARRAY)     /* bigquery function */
SYSTEM_TIME         TOKEN(SYSTEM_TIME)          /* bigquery */
IF                  TOKEN(IF)                   /* bigquery function */

NULL    {
    yylval->node = Node::makeTerminalNode(E_NULL, yytext);
    return BIGQUERY_NULLX;
}

("0X"|"0x")[0-9a-fA-F]+ {
    Node* nd = Node::makeTerminalNode(E_INT, yytext);
    yylval->node = nd;
    return BIGQUERY_INTNUM;
}

[0-9]+  {
    Node* nd = Node::makeTerminalNode(E_INT, yytext);
    yylval->node = nd;
    nd->terminalToken_.i = atoi(yytext);
    return BIGQUERY_INTNUM;
}



[0-9]+E[-+]?[0-9]+ |
[0-9]+"."[0-9]*E[-+]?[0-9]+ |
"."[0-9]+E[-+]?[0-9]+ {
    Node* nd = Node::makeTerminalNode(E_DOUBLE, yytext);
    yylval->node = nd;
    nd->terminalToken_.d = atof(yytext);
    return BIGQUERY_APPROXNUM;
}

[0-9]+"."[0-9]* |
"."[0-9]+ {
    Node* nd = Node::makeTerminalNode(E_DOUBLE, yytext);
    yylval->node = nd;
    nd->terminalToken_.d = atof(yytext);
    return BIGQUERY_APPROXNUM;
}

TRUE    {
    Node* nd = Node::makeTerminalNode(E_BOOL, yytext);
    yylval->node = nd;
    nd->terminalToken_.i = 1;
    return BIGQUERY_BOOL_VAL;
}

UNKNOWN {
    yylval->node = Node::makeTerminalNode(E_NULL, yytext);
    return BIGQUERY_UNKNOWN;
}

FALSE   {
    Node* nd = Node::makeTerminalNode(E_BOOL, yytext);
    yylval->node = nd;
    nd->terminalToken_.i = 0;
    return BIGQUERY_BOOL_VAL;
}


{sqbegin}   {
    BEGIN(sq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << '\'';
}
{bquote}    {
    BEGIN(sq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "B'";
}
{rquote}    {
    BEGIN(sq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "R'";
}
{rbquote} {
    BEGIN(sq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "RB'";
}

<sq>{sqdouble} {
    ((ParseResult*)yyextra)->buf_ << "''";
}

<sq>{sqescape}  {
    ((ParseResult*)yyextra)->buf_ << "\\'";
}

<sq>{backslash} {
    ((ParseResult*)yyextra)->buf_ << '\\';
}

<sq>{sqcontent} {
    ((ParseResult*)yyextra)->buf_ << yytext;
}

<sq>{sqend} {
    BEGIN(INITIAL);
    ((ParseResult*)yyextra)->buf_ << '\'';
    Node* nd = Node::makeTerminalNode(E_STRING, ((ParseResult*)yyextra)->buf_.str().c_str());
    nd->terminalToken_.str = ((ParseResult*)yyextra)->buf_.str();
    yylval->node = nd;
    return BIGQUERY_STR;
}
<sq><<EOF>>  {
  //fprintf(stderr, "[SQL-Lexer-Error] Unterminated string\n");
  return BIGQUERY_ERROR;
}


{qq}  {
    BEGIN(qq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << '"';
}
{b_qq}   {
    BEGIN(qq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "B\"";
}
{r_qq}   {
    BEGIN(qq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "R\"";
}
{rb_qq} {
    BEGIN(qq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
    ((ParseResult*)yyextra)->buf_ << "RB\"";
}

<qq>{db_qq}  {
    ((ParseResult*)yyextra)->buf_ << "\"\"";
}
<qq>{sp_qq}  {
    ((ParseResult*)yyextra)->buf_ << "\\\"";
}
<qq>{backslash} {
    ((ParseResult*)yyextra)->buf_ << '\\';
}
<qq>{qq_content} {
    ((ParseResult*)yyextra)->buf_ << yytext;
}
<qq>{qq}  {
    BEGIN(INITIAL);
    ((ParseResult*)yyextra)->buf_ << '"';
    Node* nd = Node::makeTerminalNode(E_STRING, ((ParseResult*)yyextra)->buf_.str().c_str());
    nd->terminalToken_.str = ((ParseResult*)yyextra)->buf_.str();
    yylval->node = nd;
    return BIGQUERY_STR;
}
<qq><<EOF>>   {
  //fprintf(stderr, "[SQL-Lexer-Error] Unterminated string\n");
  return BIGQUERY_ERROR;
}



`(``|[^`\\\n])+` {  /* todo table can contain '-' but field */
    Node* nd = Node::makeTerminalNode(E_IDENTIFIER, yytext);
    yylval->node = nd;
    nd->terminalToken_.str = escape_double_quotation_bigquery(std::string(yytext+1, yytext + strlen(yytext) - 1), '`');
    nd->terminalToken_.line = yylloc->first_line;
    nd->terminalToken_.column = yylloc->first_column;
    return BIGQUERY_NAME;
}

@`(``|[^`\\\n])+` {  /* todo table can contain '-' but field */
    Node* nd = Node::makeTerminalNode(E_PARAMETER, yytext);
    yylval->node = nd;
    nd->terminalToken_.str = escape_double_quotation_bigquery(std::string(yytext+1, yytext + strlen(yytext) - 1), '`');
    nd->terminalToken_.line = yylloc->first_line;
    nd->terminalToken_.column = yylloc->first_column;
    return BIGQUERY_PARAM;
}


@[A-Za-z_][A-Za-z0-9_]* {
	Node* nd = Node::makeTerminalNode(E_PARAMETER, yytext);
	yylval->node = nd;
	nd->terminalToken_.str = std::string(yytext+1, yytext + strlen(yytext));
	nd->terminalToken_.line = yylloc->first_line;
    nd->terminalToken_.column = yylloc->first_column;
	return BIGQUERY_PARAM;
}

[A-Za-z_][A-Za-z0-9_\-]* {
	Node* nd = Node::makeTerminalNode(E_IDENTIFIER, yytext);
	yylval->node = nd;
	nd->terminalToken_.str = yytext;
	nd->terminalToken_.line = yylloc->first_line;
    nd->terminalToken_.column = yylloc->first_column;
	return BIGQUERY_NAME;
}

{comment}   { /* ignore */ }
[ \t\r\n]+  { /* ignore */ }

[-+&~|^/%*(){}\[\],.;!$] { return yytext[0];}

"||"    { return BIGQUERY_CNNOP; }
"="     { return BIGQUERY_COMP_EQ; }
">="    { return BIGQUERY_COMP_GE; }
">"     { return BIGQUERY_COMP_GT; }
"<="    { return BIGQUERY_COMP_LE; }
"<"     { return BIGQUERY_COMP_LT; }
"<>"    { return BIGQUERY_COMP_NE; }
"!="    { return BIGQUERY_COMP_NE; }
">>"    { return BIGQUERY_OP_RS; }
"<<"    { return BIGQUERY_OP_LS; }

""

"?"     {
    Node* nd = Node::makeTerminalNode(E_QUESTIONMARK, yytext);
    yylval->node = nd;
    return BIGQUERY_QUESTIONMARK;
}


<<EOF>>    { return BIGQUERY_END_P; }

.   {
    //fprintf(stderr, "[SQL-Lexer-Error] Unknown Character: %c\n", yytext[0]);
    return BIGQUERY_ERROR;   /* todo ignore or return ERROR */
}
%%
/***************************
 ** Section 3: User code
 ***************************/

//int yyerror(const char *msg) {
//    fprintf(stderr, "[SQL-Lexer-Error] %s\n",msg); return BIGQUERY_ERROR;
//}
