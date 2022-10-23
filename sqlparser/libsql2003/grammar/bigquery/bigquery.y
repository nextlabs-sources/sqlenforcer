%{
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

%}
/*********************************
 ** Section 2: Bison Parser Declarations
 *********************************/


// Specify code that is included in the generated .h and .c files
%code requires {
// %code requires block

#include "node.h"
}

// Auto update column and line number

// Define the names of the created files (defined in Makefile)
%output  "sqlparser_bigquery_bison.cpp"
%defines "sqlparser_bigquery_bison.h"

// Tell bison to create a reentrant parser
%define api.pure full

// Prefix the parser
%define api.prefix {bigquery_}
%define api.token.prefix {BIGQUERY_}

%define parse.error verbose
%locations

%initial-action {
	// Initialize
	@$.first_column = 0;
	@$.last_column = 0;
	@$.first_line = 0;
	@$.last_line = 0;
};


// Define additional parameters for yylex (http://www.gnu.org/software/bison/manual/html_node/Pure-Calling.html)
%lex-param   { yyscan_t scanner }

// Define additional parameters for yyparse
%parse-param { ParseResult* result }
%parse-param { yyscan_t scanner }


/*********************************
 ** Define all data-types (http://www.gnu.org/software/bison/manual/html_node/Union-Decl.html)
 *********************************/
%union
{
    struct Node* node;
    int    ival;
    NodeType nodetype;
}


/*********************************
 ** Destructor symbols
 *********************************/
%destructor { delete($$); }<node>


/*********************************
 ** Token Definition
 *********************************/
%token <node> NAME
%token <node> NAMES
%token <node> STR
%token <node> INTNUM
%token <node> BOOL_VAL
%token <node> APPROXNUM
%token <node> NULLX
%token <node> UNKNOWN
%token <node> QUESTIONMARK
%token <node> PARAM

//%right 	COLLATE
//%left	OR
//%left	AND
//%right 	NOT
//%left 	COMP_LE COMP_LT COMP_EQ COMP_GT COMP_GE COMP_NE
//%left 	CNNOP
//%left 	LIKE
//%nonassoc BETWEEN
//%nonassoc IN
//%nonassoc IS NULLX BOOL_VAL UNKNOWN
//%left 	'+' '-'
//%left 	'*' '/' '%' MOD
//%left 	'^'
%left   CROSS FULL INNER JOIN LEFT NATURAL RIGHT USING
%left 	UMINUS
%left 	'(' ')'
%left   '.'



%token ALL AND ANY AS ASC
       AVG
%token BETWEEN   BY
%token CALL CASE CAST
       CNNOP COALESCE CODE_UNITS COLLATE COMP_EQ
       COMP_GE COMP_GT COMP_LE COMP_LT COMP_NE
       CONVERT CORRESPONDING COUNT CROSS CUME_DIST
       CURRENT CURRENT_TIMESTAMP CURRENT_USER
%token  DAY DEC  DEFAULT DELETE
       DENSE_RANK DESC DISTINCT
%token ELSE END END_P ESCAPE ERROR EXCEPT EXCLUDE
%token EXISTS
%token FOLLOWING FOR FROM FULL
%token G GROUP GROUPING
%token HAVING HOUR
%token IN INNER INSERT  INTERSECT INTERVAL
       INTO IS
%token JOIN
%token K
%token LARGE LEFT LIKE
%token M MAX MIN MINUTE MOD MONTH
       MULTISET
%token NATIONAL NATURAL  NO NOT NULLIF
       NUMERIC
%token OBJECT OCTETS OF ON ONLY OR
       ORDER OTHERS OUTER OVER
%token PARTITION PERCENT_RANK PRECEDING PRECISION
%token RANGE RANK READ REAL RECURSIVE REF
       RIGHT ROW ROWS ROW_NUMBER
%token SCOPE SECOND SELECT SESSION_USER SET SETS SMALLINT
       SOME STDDEV_POP STDDEV_SAMP SUM SYSTEM_USER
%token THEN TIES   TO
%token UNBOUNDED UNION UPDATE USING
%token VALUES VARCHAR VARYING VAR_POP VAR_SAMP
%token WHEN WHERE WITH WITHOUT
%token YEAR
%token ZONE
%token LIMIT OFFSET ORDINAL SAFE_OFFSET SAFE_ORDINAL
%token REPLACE
%token NULLS FIRST LAST
%token ARRAY STRUCT INT64 FLOAT64 STRING BYTES DATETIME  DATE TIMESTAMP TIME BOOL
%token VALUE UNNEST
%token OP_LS OP_RS
/* ---------bigquery function---- */
%token FIRST_VALUE RESPECT IGNORE WINDOW LAST_VALUE NTH_VALUE LEAD LAG
       PERCENTILE_CONT PERCENTILE_DISC NTILE ARRAY_AGG CORR COVAR_POP COVAR_SAMP
       STRING_AGG ANY_VALUE COUNTIF SAFE_CAST ARRAY_CONCAT_AGG BIT_XOR LOGICAL_AND
       LOGICAL_OR APPROX_COUNT_DISTINCT APPROX_QUANTILES APPROX_TOP_COUNT
%token WEEK QUARTER DAYOFWEEK  DAYOFYEAR ISOWEEK  ISOYEAR MICROSECOND  MILLISECOND  SUNDAY
       MONDAY  TUESDAY  WEDNESDAY  THURSDAY  FRIDAY  SATURDAY  AT  EXTRACT
       DATE_ADD  DATE_SUB  DATE_DIFF  DATE_TRUNC  DATETIME_ADD  DATETIME_SUB  DATETIME_DIFF  DATETIME_TRUNC
       TIME_ADD  TIME_SUB  TIME_DIFF  TIME_TRUNC  TIMESTAMP_ADD  TIMESTAMP_SUB  TIMESTAMP_DIFF  TIMESTAMP_TRUNC
       TO_JSON_STRING  STDDEV  VARIANCE  STARTS_WITH  ENDS_WITH  REGEXP_CONTAINS  REGEXP_EXTRACT  REGEXP_REPLACE
       GENERATE_TIMESTAMP_ARRAY GENERATE_DATE_ARRAY SYSTEM_TIME
       IF



%type <node> sql_stmt
%type <node> stmt_list
%type <node> stmt
%type <node> dql_stmt
%type <node> dml_stmt
%type <node> call_stmt sp_name sql_argument_list sql_argument value_expression
%type <node> select_stmt
%type <node> update_stmt
%type <node> delete_stmt
%type <node> insert_stmt
//%type <node> merge_stmt
%type <node> insert_columns_and_source from_constructor
%type <node> opt_from_clause table_primary_non_join
%type <node> label opt_as_label as_label
%type <node> select_with_parens query_expression query_expression_body select_stmt_with_parens
%type <node> query_term query_primary simple_table
%type <node> select_expr_list
%type <node> opt_where opt_groupby opt_order_by order_by opt_having
%type <node> sort_list sort_key opt_asc_desc
%type <node> opt_distinct distinct_or_all projection projection_comma
%type <node> from_list table_reference table_primary relation_factor table_and_alias
%type <node> joined_table cross_join qualified_join natural_join qualified_join_2
%type <node> join_type join_on
%type <ival> join_outer
%type <node> expr_const
%type <node> search_condition boolean_term boolean_factor boolean_test boolean_primary truth_value
%type <node> predicate comparison_predicate between_predicate in_predicate like_predicate
%type <node> is_predicate  exists_predicate
%type <node> row_expr row_expr_list factor factor0 factor1 factor2 factor3 factor4
%type <nodetype> comp_op plus_minus_op star_div_percent_mod_op comp_all_some_any_op cnn_op bit_shift_op
%type <node> column_ref opt_array_index_type column_ref_bigquery
%type <node> case_expr func_expr in_expr function_call_keyword
%type <node> case_arg when_clause_list when_clause case_default
%type <node> with_clause with_list common_table_expr opt_derived_column_list
%type <node> simple_ident_list simple_ident_list_with_parens
%type <node> over_clause opt_over_clause window_name window_specification window_specification_details
%type <node> opt_existing_window_name opt_window_partition_clause
%type <node> opt_window_frame_clause window_frame_units window_frame_extent opt_window_frame_exclusion
%type <node> window_frame_start window_frame_between window_frame_preceding window_frame_bound
%type <node> window_frame_following
%type <node> aggregate_windowed_function ranking_windowed_function scalar_function
%type <node> aggregate_function_name ranking_function_name function_name  call_keyword bigquery_func_name custom_function_name
%type <node> update_elem_list update_elem
%type <node> collate_clause
%type <ival> all_some_any
%type <node>  non_second_primary_datetime_field
%type <node> name_r reserved datatype_reserved name_f
%type <node> grouping_element_list grouping_element
%type <node> subquery row_subquery table_subquery
%type <node> limit_num offset_num
%type <node> asterisk_expr asterisk_qualify except_expr repalce_expr
%type <node> opt_nulls
%type <node> struct_def struct_mumber_def name_2_type_list name_2_type
%type <node> array_def  array_mumber_def struct_type array_type
%type <node> data_type  predefined_type combination_type
%type <node> select_as_clause
%type <node> unnest_def with_as_num
%type <node> const_string numeric_num
%type <node> row_expr_as_label_list row_expr_as_label
%type <node> row_expr_op_as_label_list row_expr_op_as_label
%type <node> bigquery_function nonparens_boolean_primary parens_boolean_primary
%type <node> opt_respect_nulls  opt_window_clause window_clause window_list window_list_element
%type <node> string_function time_function datetime_function date_function
%type <node> interval_date_part interval_datetime_part interval_time_part opt_at_time_zone
%type <node> all_date_expression  timestamp_expression datetime_expression  date_expression for_system_time_as_of
%type <node> week_func week_ hour_part ext_day_part2 ext_day_part1 day_part datetime_part2 datetime_part date_part hour_day_part
%type <node> bool_row or_cond and_cond not_cond or_cond2 and_cond2 not_cond2 bool_primary_row bool_primary_row_sub
%type <node> predicate_row comparison_predicate_row between_predicate_row in_predicate_row like_predicate_row is_predicate_row exists_predicate_row


%start sql_stmt
%%
/*********************************
 ** Section 3: Grammar Definition
 *********************************/

// Defines our general input.
sql_stmt:
    stmt_list END_P
{
    $$ = $1;
    result->result_tree_ = $1;
    result->accept = true;
    YYACCEPT;
}
;

stmt_list:
    stmt
  | stmt ';' stmt_list
{
    $$ = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &SEMICOLON_LIST_SERIALIZE_FORMAT;
}
;

stmt:
    %empty 	{ $$ = nullptr; } /*EMPTY STATEMENT*/
  | dql_stmt
  | dml_stmt
  | call_stmt
;

call_stmt:
    CALL sp_name '(' sql_argument_list ')'
{
    $$ = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, $2, $4);
    $$->serialize_format = &CALL_SERIALIZE_FORMAT;
}
  | CALL sp_name '(' ')'
{
    $$ = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, $2, nullptr);
    $$->serialize_format = &CALL_SERIALIZE_FORMAT;
}
  | '{' CALL sp_name '(' sql_argument_list ')' '}'
{
    $$ = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, $3, $5);
    $$->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
  | '{' CALL sp_name '(' ')' '}'
{
    $$ = Node::makeNonTerminalNode(E_CALL, E_CALL_PROPERTY_CNT, $3, nullptr);
    $$->serialize_format = &CALL_SQL_SERVER_SERIALIZE_FORMAT;
}
;

sql_argument_list:
    sql_argument
  | sql_argument ',' sql_argument_list
{
    $$ = Node::makeNonTerminalNode(E_STMT_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

sql_argument:
    value_expression
{
    $$ = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, $1, nullptr);
    $$->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
  | value_expression AS data_type
{
    $$ = Node::makeNonTerminalNode(E_SQL_ARGUMENT, E_SQL_ARGUMENT_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &SQL_ARGUMENT_SERIALIZE_FORMAT;
}
;

value_expression:
   row_expr		/* <common value expression> <row value expression> */

;

sp_name:
    relation_factor
;

dql_stmt:
    select_stmt
;

dml_stmt:
    update_stmt
  | delete_stmt
  | insert_stmt
//  | merge_stmt
;

//merge_stmt:
//    MERGE [INTO] column_ref opt_as_label USING column_ref ON search_condition when_clause_list

insert_stmt:
    INSERT INTO relation_factor insert_columns_and_source
{
    $$ = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, $3, $4);
    $$->serialize_format = &INSERT_SERIALIZE_FORMAT;
}
    |  INSERT relation_factor insert_columns_and_source
{
    $$ = Node::makeNonTerminalNode(E_INSERT, E_INSERT_PROPERTY_CNT, $2, $3);
    $$->serialize_format = &INSERT_SERIALIZE_FORMAT_V2;
}
;

insert_columns_and_source:
    				  select_stmt
{
    $$ = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, $1);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
  | simple_ident_list_with_parens select_stmt
{
    $$ = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, $1, $2);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
  | simple_ident_list_with_parens from_constructor
{
    $$ = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, $1, $2);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
  |                               from_constructor
{
    $$ = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, $1);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
  | DEFAULT VALUES
{
    Node* src = Node::makeTerminalNode(E_IDENTIFIER, "DEFAULT VALUES");
    $$ = Node::makeNonTerminalNode(E_INSERT_COLUMNS_AND_SOURCE, E_INSERT_COLUMNS_AND_SOURCE_PROPERTY_CNT, nullptr, src);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
;

from_constructor:
    VALUES row_expr_list
{
    $$ = Node::makeNonTerminalNode(E_VALUES_CTOR, E_VALUES_CTOR_PROPERTY_CNT, $2);
    $$->serialize_format = &TABLE_VALUE_CTOR_SERIALIZE_FORMAT;
}
;

/* sql2003 support <delete statement: searched> */
delete_stmt:
    DELETE FROM relation_factor opt_where
{
    $$ = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		$3,		    /* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,    /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		$4,		    /* E_DELETE_OPT_WHERE 6 */
    		nullptr 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    $$->serialize_format = &DELETE_SERIALIZE_FORMAT;
}
 |   DELETE table_and_alias opt_where
{
    $$ = Node::makeNonTerminalNode(E_DELETE, E_DELETE_PROPERTY_CNT,
    		nullptr,	/* E_DELETE_OPT_WITH 0 */
    		nullptr,	/* E_DELETE_OPT_TOP 1 */
    		$2,		    /* E_DELETE_DELETE_RELATION 2 */
    		nullptr,	/* E_DELETE_DELETE_RELATION_OPT_TABLE_HINT 3 */
    		nullptr,    /* E_DELETE_OPT_OUTPUT 4 */
    		nullptr,	/* E_DELETE_FROM_LIST 5 */
    		$3,		    /* E_DELETE_OPT_WHERE 6 */
    		nullptr 	/* E_DELETE_OPT_QUERY_HINT 7 */);
    $$->serialize_format = &DELETE_SERIALIZE_FORMAT_V2;
}
;

/* sql2003 support <update statement: searched> */
update_stmt:
  UPDATE table_and_alias  SET update_elem_list opt_from_clause opt_where
{
    $$ = Node::makeNonTerminalNode(E_UPDATE, E_UPDATE_PROPERTY_CNT,
        nullptr,	/* E_UPDATE_OPT_WITH 0 */
        nullptr,	/* E_UPDATE_OPT_TOP 1 */
        $2,		    /* E_UPDATE_UPDATE_RELATION 2 */
        nullptr,	/* E_UPDATE_UPDATE_RELATION_OPT_TABLE_HINT 3 */
        $4,		    /* E_UPDATE_UPDATE_ELEM_LIST 4 */
        nullptr,	/* E_UPDATE_OPT_OUTPUT 5 */
        $5,	        /* E_UPDATE_FROM_LIST 6 */
        $6,		    /* E_UPDATE_OPT_WHERE 7 */
        nullptr		/* E_UPDATE_OPT_QUERY_HINT 8 */);
    $$->serialize_format = &UPDATE_SERIALIZE_FORMAT;
}
;

table_and_alias:
    relation_factor opt_as_label
{
    if($2){
        $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
        $$->serialize_format = &AS_SERIALIZE_FORMAT;
    } else {
        $$=$1;
    }
}
;
update_elem_list:
    update_elem
  | update_elem ',' update_elem_list
{
    $$ = Node::makeNonTerminalNode(E_UPDATE_ELEM_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

update_elem:
    row_expr COMP_EQ row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_EQ, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &OP_EQ_SERIALIZE_FORMAT;
}
;

/* sql2003 support <direct select statement: multiple rows> */
select_stmt:
    query_expression
{
    $$ = $1;
   // $$->setChild(E_DIRECT_SELECT_ORDER, $2);
   // $$->setChild(3, $3);
}
;

limit_num:
    %empty { $$ = nullptr; }
    | LIMIT INTNUM offset_num
{
    $$ = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, $2, $3);
    $$->serialize_format = &LIMIT_NUM_FORMAT;
}
    | LIMIT QUESTIONMARK offset_num
{
    $$ = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, $2, $3);
    $$->serialize_format = &LIMIT_NUM_FORMAT;
}
    | LIMIT PARAM offset_num
{
    $$ = Node::makeNonTerminalNode(E_LIMIT_NUM, E_OP_BINARY_PROPERTY_CNT, $2, $3);
    $$->serialize_format = &LIMIT_NUM_FORMAT;
}
;


offset_num: %empty { $$ = nullptr; }
;
offset_num: OFFSET INTNUM
{
    $$ = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, $2);
    $$->serialize_format = &OFFSET_NUM_FORMAT;
}
    | OFFSET QUESTIONMARK
{
    $$ = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, $2);
    $$->serialize_format = &OFFSET_NUM_FORMAT;
}
    | OFFSET PARAM
{
    $$ = Node::makeNonTerminalNode(E_OFFSET_NUM, 1, $2);
    $$->serialize_format = &OFFSET_NUM_FORMAT;
}
;

query_expression:
    query_expression_body opt_order_by limit_num
{
    $$ = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, nullptr, $1, $2, $3,nullptr);
    $$->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}
  | with_clause query_expression_body  opt_order_by limit_num
{
    $$ = Node::makeNonTerminalNode(E_DIRECT_SELECT, E_DIRECT_SELECT_PROPERTY_CNT, $1, $2, $3, $4, nullptr);
    $$->serialize_format = &SELECT_DIRECT_SERIALIZE_FORMAT;
}

query_expression_body:
    query_term
  | query_expression_body UNION opt_distinct query_term
{
    Node* set_op = Node::makeTerminalNode(E_SET_UNION, "UNION");
    $$ = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        $3,                  /* E_SELECT_ALL_SPECIFIED 7 */
                        $1,                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        $4,                  /* E_SELECT_LATER_SELECT_STMT 9 */
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
    $$->serialize_format = &SELECT_UNION_SERIALIZE_FORMAT;
}
  | query_expression_body EXCEPT DISTINCT query_term
{
    Node * dist = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
    Node* set_op = Node::makeTerminalNode(E_SET_EXCEPT, "EXCEPT");
    $$ = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        dist,                  /* E_SELECT_ALL_SPECIFIED 7 */
                        $1,                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        $4,                  /* E_SELECT_LATER_SELECT_STMT 9 */
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
    $$->serialize_format = &SELECT_EXCEPT_SERIALIZE_FORMAT;
}
;

query_term:
    query_primary
  | query_term INTERSECT DISTINCT query_primary
{
    Node * dist = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
    Node* set_op = Node::makeTerminalNode(E_SET_INTERSECT, "INTERSECT");
    $$ = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                        nullptr,             /* E_SELECT_DISTINCT 0 */
                        nullptr,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                        nullptr,             /* E_SELECT_FROM_LIST 2 */
                        nullptr,             /* E_SELECT_OPT_WHERE 3 */
                        nullptr,             /* E_SELECT_GROUP_BY 4 */
                        nullptr,             /* E_SELECT_HAVING 5 */
                        set_op,              /* E_SELECT_SET_OPERATION 6 */
                        dist,                  /* E_SELECT_ALL_SPECIFIED 7 */
                        $1,                  /* E_SELECT_FORMER_SELECT_STMT 8 */
                        $4,                  /* E_SELECT_LATER_SELECT_STMT 9 */
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
    $$->serialize_format = &SELECT_INTERSECT_SERIALIZE_FORMAT;
}
;

query_primary:
    simple_table
    | '(' query_expression ')'	/* in  spec, here should be <query expression body> here generate a reduce/reduce error, however it works (all test passed) */
{
    if ($2->getChild(E_DIRECT_SELECT_WITH)) {
        yyerror(&@1, result, scanner, "error use common table expression");
        YYABORT;
    }
    $$ = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

/* here generate a reduce/reduce error, however it works (all test passed) */
select_with_parens:
    '(' query_expression ')'
{
    $$ = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

select_stmt_with_parens:
    '(' select_stmt ')'
{
    $$ = Node::makeNonTerminalNode(E_SELECT_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

subquery: select_with_parens;

table_subquery: select_stmt_with_parens;

row_subquery: subquery;

simple_table:
    SELECT opt_distinct select_as_clause select_expr_list opt_from_clause opt_where opt_groupby opt_having opt_window_clause
{
    $$ = Node::makeNonTerminalNode(E_SELECT, E_SELECT_PROPERTY_CNT,
                    $2,             /* E_SELECT_DISTINCT 0 */
                    $4,             /* E_SELECT_SELECT_EXPR_LIST 1 */
                    $5,             /* E_SELECT_FROM_LIST 2 */
                    $6,             /* E_SELECT_OPT_WHERE 3 */
                    $7,             /* E_SELECT_GROUP_BY 4 */
                    $8,             /* E_SELECT_HAVING 5 */
                    nullptr,        /* E_SELECT_SET_OPERATION 6 */
                    nullptr,        /* E_SELECT_ALL_SPECIFIED 7 */
                    nullptr,        /* E_SELECT_FORMER_SELECT_STMT 8 */
                    nullptr,        /* E_SELECT_LATER_SELECT_STMT 9 */
                    $9,             /* E_SELECT_ORDER_BY 10 */ /* WINDOW_CLAUSE */
                    nullptr,        /* E_SELECT_LIMIT 11 */
                    nullptr,        /* E_SELECT_FOR_UPDATE 12 */
                    nullptr,        /* E_SELECT_HINTS 13 */
                    nullptr,        /* E_SELECT_WHEN 14 */
                    nullptr,        /* E_SELECT_OPT_TOP 15 */
                    nullptr,        /* E_SELECT_OPT_WITH 16 */
                    nullptr,        /* E_SELECT_OPT_OPTION 17 */
	                nullptr,        /* E_SELECT_OPT_INTO 18 */
	                $3              /* E_SELECT_AS_CLAUSE 19*/
                    );
    if(NULL == $4){
        if(NULL != $5){
            yyerror(&@1, result, scanner, "Statement without FROM clause cannot have an WHERE");
            YYABORT;
        }
        if(NULL != $6){
            yyerror(&@1, result, scanner, "Statement without FROM clause cannot have an GROUP BY");
            YYABORT;
        }
        if(NULL != $7){
            yyerror(&@1, result, scanner, "Statement without FROM clause cannot have an HAVING");
            YYABORT;
        }
    }
    $$->serialize_format = &SELECT_SERIALIZE_FORMAT;
}
;

select_as_clause:
    %empty { $$=NULL; }
    |  AS STRUCT
{
    $$ = Node::makeTerminalNode(E_AS_STRUCT, "AS STRUCT");
}
    |  AS VALUE
{
    $$ = Node::makeTerminalNode(E_AS_STRUCT_VALUE, "AS VALUE");
}
;

opt_where:
    %empty 	{ $$ = nullptr; }
  | WHERE search_condition
{
    $$ = Node::makeNonTerminalNode(E_WHERE_CLAUSE, E_WHERE_CLAUSE_PROPERTY_CNT, $2);
    $$->serialize_format = &WHERE_SERIALIZE_FORMAT;
}
;

/* sql2003 not allow tableless */
opt_from_clause:
%empty { $$=nullptr; }
|FROM from_list
{
    $$ = Node::makeNonTerminalNode(E_FROM_CLAUSE, E_FROM_CLAUSE_PROPERTY_CNT, $2);
    $$->serialize_format = &FROM_SERIALIZE_FORMAT;
}
;

opt_groupby:
   %empty 	{ $$ = nullptr; }
  | GROUP BY opt_distinct grouping_element_list
{
    $$ = Node::makeNonTerminalNode(E_GROUP_BY, E_GROUP_BY_PROPERTY_CNT, $4, $3);
    $$->serialize_format = &GROUP_BY_SERIALIZE_FORMAT;
}
;

grouping_element_list:
    grouping_element
  | grouping_element ',' grouping_element_list
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

//BigQuery has rollup, but not GROUPING SETS
grouping_element:
    '(' ')'	{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"()"); }	/* sql2003 support <empty grouping set> */
  | row_expr								/* sql2003 support <ordinary grouping set> <rollup list> <cube list> */
  | GROUPING SETS '(' grouping_element_list ')'				/* sql2003 support <grouping sets specification> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING SETS");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, $4, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
;

opt_order_by:
    %empty 	{ $$ = nullptr; }
  | order_by
;

order_by:
    ORDER BY sort_list
{
    $$ = Node::makeNonTerminalNode(E_ORDER_BY, E_ORDER_BY_PROPERTY_CNT, $3, nullptr);
    $$->serialize_format = &ORDER_BY_SERIALIZE_FORMAT;
}
;

sort_list:
    sort_key
  | sort_key ',' sort_list
{
    $$ = Node::makeNonTerminalNode(E_SORT_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

sort_key:
    row_expr opt_asc_desc opt_nulls
{
    $$ = Node::makeNonTerminalNode(E_SORT_KEY, 3, $1, $2, $3);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
;

opt_asc_desc:
    %empty
{
    $$ = Node::makeTerminalNode(E_SORT_ASC, "");
}
  | ASC
{
    $$ = Node::makeTerminalNode(E_SORT_ASC, "ASC");
}
  | DESC
{
    $$ = Node::makeTerminalNode(E_SORT_DESC, "DESC");
}
;

opt_nulls:
    %empty {$$ = NULL;}
    | NULLS FIRST
{
    $$ = Node::makeTerminalNode(E_STRING, " NULLS FIRST");
}
    | NULLS LAST
{
    $$ = Node::makeTerminalNode(E_STRING, " NULLS LAST");
}
;

opt_having:
    %empty 	{ $$ = nullptr; }
  | HAVING search_condition
{
    $$ = Node::makeNonTerminalNode(E_HAVING, E_HAVING_PROPERTY_CNT, $2);
    $$->serialize_format = &HAVING_SERIALIZE_FORMAT;
}
;


/* sql2003 support RECURSIVE common table expression */
with_clause:
    WITH with_list
{
    $$ = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, $2);
    $$->serialize_format = &WITH_CLAUSE_SERIALIZE_FORMAT;
}
  | WITH RECURSIVE with_list
{
    $$ = Node::makeNonTerminalNode(E_OPT_WITH_CLAUSE, E_OPT_WITH_CLAUSE_PROPERTY_CNT, $3);
    $$->serialize_format = &WITH_RECURSIVE_CLAUSE_SERIALIZE_FORMAT;
}
;

with_list:
    common_table_expr
  | common_table_expr ',' with_list
{
    $$ = Node::makeNonTerminalNode(E_WITH_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

/*todo sql2003 support <search or cycle clause> */
common_table_expr:
    name_r opt_derived_column_list AS table_subquery
{
    $$ = Node::makeNonTerminalNode(E_COMMON_TABLE_EXPR, E_COMMON_TABLE_EXPR_PROPERTY_CNT, $1, $2, $4);
    $$->serialize_format = &COMMON_TABLE_EXPR_SERIALIZE_FORMAT;
}
;

opt_derived_column_list:
    %empty 	{ $$ = nullptr; }
  | simple_ident_list_with_parens
;

simple_ident_list_with_parens:
    '(' simple_ident_list ')'
{
    $$ = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

simple_ident_list:
    name_r
  | name_r ',' simple_ident_list
{
    $$ = Node::makeNonTerminalNode(E_SIMPLE_IDENT_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

opt_distinct:
   %empty 	{ $$ = nullptr; }
  | ALL
{
    $$ = Node::makeTerminalNode(E_ALL, "ALL");
}
  | DISTINCT
{
    $$ = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
;

select_expr_list:
    projection
  | projection_comma
  | projection_comma  select_expr_list
{
    $$ = Node::makeNonTerminalNode(E_SELECT_EXPR_LIST, E_LIST_PROPERTY_CNT, $1, $2);
    $$->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
;

projection_comma:
projection ','
{
    $$ = $1;
    $$->serialize_format = &EXPR_COMMA_SERIALIZE_FORMAT; /* Notice that the original value is SINGLE_SERIALIZE_FORMAT */
}
;
projection:
    row_expr_op_as_label
{
    $$ = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, $1);
    $$->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
  | asterisk_expr
{
    $$ = Node::makeNonTerminalNode(E_PROJECT_STRING, E_PROJECT_STRING_PROPERTY_CNT, $1);
    $$->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}

;


row_expr_op_as_label:
    row_expr opt_as_label
{
    if (!$2) {
    	$$ = $1;
    }
    else {
	    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
        $$->serialize_format = &AS_SERIALIZE_FORMAT;
    }
}
    | bool_row opt_as_label /* bigquery support bool_expr to row_expr */
{
    if (!$2) {
    	$$ = $1;
    }
    else {
	    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
        $$->serialize_format = &AS_SERIALIZE_FORMAT;
    }
}
;


asterisk_expr:
    asterisk_qualify
{
    $$ = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, $1, NULL, NULL);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    | asterisk_qualify except_expr
{
    $$ = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, $1, $2, NULL);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    | asterisk_qualify  repalce_expr
{
    $$ = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, $1, NULL, $2);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    | asterisk_qualify except_expr repalce_expr
{
    $$ = Node::makeNonTerminalNode(E_ASTERISK_EXPR, 3, $1, $2, $3);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
;

asterisk_qualify:
    '*'
{
    $$= Node::makeTerminalNode(E_STAR, "*");
}
    |name_r '.' '*'
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    $$ = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, NULL, NULL, $1, star_node);
    $$->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
    | name_r '.' name_r '.' '*'
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    $$ = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, NULL, $1, $3, star_node);
    $$->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
    | name_r '.' name_r '.' name_r '.' '*'
{
    Node* star_node = Node::makeTerminalNode(E_STAR, "*");
    $$ = Node::makeNonTerminalNode(E_ASTERISK_QUALIFY, 4, $1, $3, $5, star_node);
    $$->serialize_format = &ASTERISK_QUALIFY_SERIALIZE_FORMAT;
}
;
except_expr: EXCEPT simple_ident_list_with_parens
{
    $$ = Node::makeNonTerminalNode(E_EXCEPT_EXPR, 1, $2);
    $$->serialize_format = &EXCEPT_EXPR_SERIALIZE_FORMAT;
}
;
repalce_expr:
 REPLACE '(' row_expr_as_label_list ')'
{
    $$ = Node::makeNonTerminalNode(E_REPLACE_EXPR, 1, $3);
    $$->serialize_format = &REPLACE_EXPR_SERIALIZE_FORMAT;
}
;
row_expr_as_label_list:
  row_expr_as_label
| row_expr_as_label ',' row_expr_as_label_list
{
    $$ = Node::makeNonTerminalNode(E_ROW_EXPR_AS_LABEL_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;
row_expr_as_label: row_expr as_label
{
    $$ = Node::makeNonTerminalNode(E_ROW_EXPR_AS_LABEL, 2, $1, $2);
    $$->serialize_format = &ROW_EXPR_AS_SERIALIZE_FORMAT;
}
;

from_list:
    table_reference
  | table_reference ',' from_list
{
    $$ = Node::makeNonTerminalNode(E_FROM_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

table_reference:
    table_primary
    | joined_table
;

table_primary:
    table_primary_non_join
  | '(' joined_table ')'
{
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

/* todo sql2003 support LATERAL subquery */
/* todo sql2003 support <collection derived table> */
/* todo sql2003 support <table function derived table> */
/* todo sql2003 support <only spec> */
table_primary_non_join:
    relation_factor opt_as_label
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
    | relation_factor opt_as_label for_system_time_as_of
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, $3, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
    |  relation_factor opt_as_label with_as_num
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, $3, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
    | table_subquery opt_as_label /*opt_simple_ident_list_with_parens*/
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
    | unnest_def opt_as_label
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, nullptr, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
    | unnest_def opt_as_label with_as_num
{
    $$ = Node::makeNonTerminalNode(E_ALIAS, E_ALIAS_PROPERTY_CNT, $1, $2, nullptr, $3, nullptr);
    $$->serialize_format = &AS_SERIALIZE_FORMAT;
}
;

for_system_time_as_of:
   FOR SYSTEM_TIME AS OF STR
{
    $$ = Node::makeTerminalNode(E_STRING, "FOR SYSTEM_TIME AS OF "+$5->text());
    $$->terminalToken_.str = $5->terminalToken_.str;
    delete($5);
}
    |   FOR SYSTEM_TIME AS OF func_expr
{
    std::string ss = "";
    if($5!=NULL){ss += "FOR SYSTEM_TIME AS OF "; ss+=$5->text(); delete($5);}
    $$ = Node::makeTerminalNode(E_STRING, ss);
}
    |   FOR SYSTEM_TIME AS OF column_ref
{
    std::string ss = "";
    if($5!=NULL){ss += "FOR SYSTEM_TIME AS OF "; ss+=$5->text(); delete($5);}
    $$ = Node::makeTerminalNode(E_STRING, ss);
}
;

with_as_num:
   WITH OFFSET opt_as_label
{
    std::string ss = "WITH OFFSET ";
    if($3!=NULL){ss += "AS "; ss+=$3->text(); delete($3);}
    $$ = Node::makeTerminalNode(E_STRING, ss);
}
;

unnest_def:
    UNNEST '(' array_def ')'
{
    $$ = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, $3);
    $$->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
    |   UNNEST '('  ')'
{
    $$ = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, NULL);
    $$->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
    |   UNNEST '(' column_ref ')'
{
    $$ = Node::makeNonTerminalNode(E_UNNEST_DEF, 1, $3);
    $$->serialize_format = &UNNEST_DEF_SERIALIZE_FORMAT;
}
;

//opt_simple_ident_list_with_parens:
 // %empty 	{ $$ = nullptr; }
//  | simple_ident_list_with_parens
//;

/* keep these that can solve <identifier chain> in sql2003 */
column_ref:
	 name_r
{
    $$ = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    $1, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
    |   name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    $3, $1, nullptr, nullptr, nullptr);
    $$->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;
}
    |	name_r '.' name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                    $5, $3, $1, nullptr, nullptr);
    $$->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;

}
    |	name_r '.' name_r '.' name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_OP_NAME_FIELD, E_OP_NAME_FIELD_PROPERTY_CNT,
                 $7, $5, $3, $1, nullptr);
    $$->serialize_format = &OP_NAME_FIELD_SERIALIZE_FORMAT_4;

}
;
column_ref_bigquery:
    column_ref opt_array_index_type
{
    $$ = Node::makeNonTerminalNode(E_ARRAY_INDEX, 2, $1, $2);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
;
opt_array_index_type:
%empty {$$=NULL;}
| '[' OFFSET '(' INTNUM ')' ']'
{
    std::string val = "[OFFSET("+$4->text()+")]";
    delete($4);
    $$ = Node::makeTerminalNode(E_STRING, val);
}
| '[' ORDINAL '(' INTNUM ')' ']'
{
   std::string val = "[ORDINAL("+$4->text()+")]";
   delete($4);
   $$ = Node::makeTerminalNode(E_STRING, val);
}
| '[' SAFE_OFFSET '(' INTNUM ')' ']'
{
    std::string val = "[SAFE_OFFSET("+$4->text()+")]";
    delete($4);
    $$ = Node::makeTerminalNode(E_STRING, val);
}
| '[' SAFE_ORDINAL '(' INTNUM ')' ']'
{
   std::string val = "[SAFE_ORDINAL("+$4->text()+")]";
   delete($4);
   $$ = Node::makeTerminalNode(E_STRING, val);
}
;

/* keep these that can solve <identifier chain> in sql2003 */
relation_factor:
    	                         name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $1, nullptr, nullptr, nullptr);
    $$->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
  |                     name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $3, $1, nullptr, nullptr);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
  |            name_r '.' name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $5, $3, $1, nullptr);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
  |            name_r '.'      '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $4, nullptr, $1, nullptr);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}
  |   name_r '.' name_r '.' name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $7, $5, $3, $1);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
  |   name_r '.'      '.' name_r '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $6, $4, nullptr, $1);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
  |   name_r '.' name_r '.'      '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $6, nullptr, $3, $1);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
  |   name_r '.'      '.'      '.' name_r
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $5, nullptr, nullptr, $1);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_3;
}
;

custom_function_name:
    name_f
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $1, nullptr, nullptr, nullptr);
    $$->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
    | name_r '.' name_f
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $3, $1, nullptr, nullptr);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_1;
}
    | name_r '.' name_r '.' name_f
{
    $$ = Node::makeNonTerminalNode(E_TABLE_IDENT, E_TABLE_IDENT_PROPERTY_CNT, $5, $3, $1, nullptr);
    $$->serialize_format = &TABLE_IDENT_SERIALIZE_FORMAT_2;
}


/* todo sql2003 support <union join> ??? */
joined_table:
    qualified_join
  | cross_join
  | natural_join
  | qualified_join_2
;

qualified_join:
    table_reference join_type JOIN table_primary join_on
{
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, $2, $1, $4, $5);
    $$->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
  | table_reference JOIN table_primary join_on
{
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $3, $4);
    $$->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
  | table_reference join_type JOIN table_primary USING simple_ident_list_with_parens
{
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, $2, $1, $4, $6);
    $$->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
  | table_reference JOIN table_primary USING simple_ident_list_with_parens
{
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $3, $5);
    $$->serialize_format = &JOINED_TB_USING_SERIALIZE_FORMAT;
}
;

join_on:
    ON  search_condition
{ $$ = $2; }
;

cross_join:
    table_reference CROSS JOIN table_primary
{
    Node* nd = Node::makeTerminalNode(E_JOIN_CROSS, "CROSS");
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $4, nullptr);
    $$->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
    | table_reference JOIN table_primary
{
    Node* nd = Node::makeTerminalNode(E_JOIN_INNER, "");
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $3, nullptr);
    $$->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
;

qualified_join_2:
    table_reference join_type JOIN table_primary
{
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, $2, $1, $4, NULL);
    $$->serialize_format = &JOINED_TB_1_SERIALIZE_FORMAT;
}
;

natural_join:
    table_reference NATURAL join_type JOIN table_primary
{
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL " + $3->text());
    delete($3);
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $5, nullptr);
    $$->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
  | table_reference NATURAL JOIN table_primary
{
    Node* nd = Node::makeTerminalNode(E_JOIN_NATURAL, "NATURAL");
    $$ = Node::makeNonTerminalNode(E_JOINED_TABLE, E_JOINED_TABLE_PROPERTY_CNT, nd, $1, $4, nullptr);
    $$->serialize_format = &JOINED_TB_2_SERIALIZE_FORMAT;
}
;

join_type:
    FULL join_outer
{
    if ($2)
    {
        $$ = Node::makeTerminalNode(E_JOIN_FULL, "FULL OUTER");
    }
    else
    {
        $$ = Node::makeTerminalNode(E_JOIN_FULL, "FULL");
    }
}
  | LEFT join_outer
{
    if ($2)
    {
        $$ = Node::makeTerminalNode(E_JOIN_LEFT, "LEFT OUTER");
    }
    else
    {
        $$ = Node::makeTerminalNode(E_JOIN_LEFT, "LEFT");
    }
}
  | RIGHT join_outer
{
    if ($2)
    {
        $$ = Node::makeTerminalNode(E_JOIN_RIGHT, "RIGHT OUTER");
    }
    else
    {
        $$ = Node::makeTerminalNode(E_JOIN_RIGHT, "RIGHT");
    }
}
  | INNER
{
    $$ = Node::makeTerminalNode(E_JOIN_INNER, "INNER");
}
;

join_outer:
   %empty                 { $$ = 0; }
  | OUTER                       { $$ = 1; /*this is a flag*/}
;

/* <search condition> grammar */
search_condition:
    boolean_term
  | search_condition OR boolean_term
{
    $$ = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_OR);
}
;

boolean_term:
    boolean_factor
  | boolean_term AND boolean_factor
{
    $$ = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_AND);
}
;

boolean_factor:
    boolean_test
  | NOT boolean_factor
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
;

boolean_test:
    predicate
    | boolean_primary
;

boolean_primary:
    nonparens_boolean_primary
    | parens_boolean_primary
;

parens_boolean_primary:
    '(' search_condition ')'
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

nonparens_boolean_primary:
    row_expr
;

/* todo sql2003 support <similar predicate> */
/* todo sql2003 support <unique predicate> */
/* todo sql2003 support <normalized predicate> */
/* todo sql2003 support <match predicate> */
/* todo sql2003 support <overlaps predicate> */
/* todo sql2003 support <distinct predicate> */
/* todo sql2003 support <member predicate> */
/* todo sql2003 support <submultiset predicate> */
/* todo sql2003 support <set predicate> */
/* todo sql2003 support <type predicate> */
predicate:
    comparison_predicate
  | between_predicate
  | in_predicate
  | like_predicate
  | is_predicate
  | exists_predicate
;

comparison_predicate:
    boolean_primary comp_all_some_any_op row_expr
{
    $$ = Node::makeNonTerminalNode($2, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

/*
quantified_comparison_predicate:
    boolean_primary comp_all_some_any_op table_subquery
{
    $$ = Node::makeNonTerminalNode($2, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;
*/

between_predicate:
    row_expr BETWEEN row_expr AND row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, $1, $3, $5);
    $$->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
  | row_expr NOT BETWEEN row_expr AND row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, $1, $4, $6);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
;

like_predicate:
    boolean_primary LIKE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
  | boolean_primary LIKE row_expr ESCAPE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, $1, $3, $5);
    $$->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
  | row_expr NOT LIKE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
  | row_expr NOT LIKE row_expr ESCAPE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, $1, $4, $6);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
;

in_predicate:
    row_expr IN in_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_IN);
}
  | row_expr NOT IN in_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
;

is_predicate:
  boolean_primary IS truth_value
{
    $$ = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_IS);
}
  | boolean_primary IS NOT truth_value
{
    $$ = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
;

exists_predicate:
    EXISTS table_subquery
{
    $$ = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
;

/* <row value ctor> */
row_expr:
    factor
  | row_expr collate_clause
{
    $$ = Node::makeNonTerminalNode(E_OP_COLLATE, E_OP_BINARY_PROPERTY_CNT, $1, $2);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
  | row_expr cnn_op factor
{
    $$ = Node::makeNonTerminalNode(E_OP_CNN, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

factor:
    factor0
  | factor bit_shift_op factor0
{
    $$ = Node::makeNonTerminalNode($2, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

factor0:
    factor1
  | factor0 plus_minus_op factor1
{
    $$ = Node::makeNonTerminalNode(E_OP_ADD, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

factor1:
    factor2
  | factor1 star_div_percent_mod_op factor2
{
    $$ = Node::makeNonTerminalNode(E_OP_MUL, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

factor2:
    factor3
  | factor2 '^' factor3
{
    $$ = Node::makeNonTerminalNode(E_OP_POW, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_POW);
}
;

factor3:
    factor4
  | '+' factor3
{
    $$ = Node::makeNonTerminalNode(E_OP_POS, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_POS);
}
  | '-' factor3
{
    $$ = Node::makeNonTerminalNode(E_OP_NEG, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_NEG);
}
  | '~' factor3
{
    $$ = Node::makeNonTerminalNode(E_BIT_OP_NOT, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_BIT_OP_NOT);
}
;

factor4:
    column_ref_bigquery
  | expr_const
  | row_subquery
  | case_expr
  | func_expr
  | struct_def
  | array_def
;

bool_row:
	or_cond
	| and_cond
	| not_cond
	| predicate_row
	| '(' bool_row ')'
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

or_cond:
 	bool_primary_row OR or_cond2
{
    $$ = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_OR);
}
    | and_cond OR or_cond2
{
    $$ = Node::makeNonTerminalNode(E_OP_OR, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_OR);
}
;

or_cond2:
	bool_primary_row
	| or_cond
	| and_cond
;

and_cond:
	bool_primary_row AND and_cond2
{
    $$ = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_AND);
}
    | not_cond AND and_cond2
{
    $$ = Node::makeNonTerminalNode(E_OP_AND, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_AND);
}
;

and_cond2:
	bool_primary_row
	| and_cond
	| not_cond
;

not_cond: NOT not_cond2
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT);
}
;

not_cond2:
	bool_primary_row
	| not_cond
;

bool_primary_row:
    bool_primary_row_sub
	| predicate_row

;

bool_primary_row_sub:
    row_expr
	| '(' bool_row ')'
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}

predicate_row:
    comparison_predicate_row
  | between_predicate_row
  | in_predicate_row
  | like_predicate_row
  | is_predicate_row
  | exists_predicate_row
;

comparison_predicate_row:
    bool_primary_row_sub comp_all_some_any_op bool_primary_row_sub
{
    $$ = Node::makeNonTerminalNode($2, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format($2);
}
;

between_predicate_row:
    row_expr BETWEEN row_expr AND row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_BTW, E_OP_TERNARY_PROPERTY_CNT, $1, $3, $5);
    $$->serialize_format = Node::op_serialize_format(E_OP_BTW);
}
  | row_expr NOT BETWEEN row_expr AND row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_BTW, E_OP_TERNARY_PROPERTY_CNT, $1, $4, $6);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_BTW);
}
;

like_predicate_row:
    bool_primary_row_sub LIKE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
  | bool_primary_row_sub LIKE row_expr ESCAPE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_LIKE, E_OP_TERNARY_PROPERTY_CNT, $1, $3, $5);
    $$->serialize_format = Node::op_serialize_format(E_OP_LIKE);
}
  | row_expr NOT LIKE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
  | row_expr NOT LIKE row_expr ESCAPE row_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_LIKE, E_OP_TERNARY_PROPERTY_CNT, $1, $4, $6);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_LIKE);
}
;

in_predicate_row:
    row_expr IN in_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_IN, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_IN);
}
  | row_expr NOT IN in_expr
{
    $$ = Node::makeNonTerminalNode(E_OP_NOT_IN, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_NOT_IN);
}
;

is_predicate_row:
  bool_primary_row_sub IS truth_value
{
    $$ = Node::makeNonTerminalNode(E_OP_IS, E_OP_BINARY_PROPERTY_CNT, $1, $3);
    $$->serialize_format = Node::op_serialize_format(E_OP_IS);
}
  | bool_primary_row_sub IS NOT truth_value
{
    $$ = Node::makeNonTerminalNode(E_OP_IS_NOT, E_OP_BINARY_PROPERTY_CNT, $1, $4);
    $$->serialize_format = Node::op_serialize_format(E_OP_IS_NOT);
}
;

exists_predicate_row:
    EXISTS table_subquery
{
    $$ = Node::makeNonTerminalNode(E_OP_EXISTS, E_OP_UNARY_PROPERTY_CNT, $2);
    $$->serialize_format = Node::op_serialize_format(E_OP_EXISTS);
}
;








struct_def:
     '(' row_expr_list ')'
{

    Node * node_list  = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  $2);
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    if($2->nodeType_ == E_EXPR_LIST){
        $$ = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, NULL, NULL, node_list);
        $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
    } else {
        $$ =   node_list;
    }
}
    | STRUCT  '(' row_expr_op_as_label_list ')'
{
    Node * node_struct = Node::makeTerminalNode(E_STRING,"STRUCT");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  $3);
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    $$ = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, node_struct, NULL, node_list);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    |  STRUCT  struct_mumber_def '(' row_expr_list ')'
{
    Node * node_struct = Node::makeTerminalNode(E_STRING,"STRUCT");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, 1,  $4);
    node_list->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;

    $$ = Node::makeNonTerminalNode(E_STRUCT_DEF, 3, node_struct, $2, node_list);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
;

row_expr_op_as_label_list:
    row_expr_op_as_label
    | row_expr_op_as_label ',' row_expr_op_as_label_list
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

struct_mumber_def:
   COMP_LT name_2_type_list COMP_GT
{
    $$ = Node::makeNonTerminalNode(E_STRUCT_MEMBER_DEF, 1, $2);
    $$->serialize_format = &MEMBER_DEF_SERIALIZE_FORMAT;
}
;

name_2_type_list:
  name_2_type
  | name_2_type ',' name_2_type_list
{
    $$ = Node::makeNonTerminalNode(E_NAME_TYPE_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

name_2_type:
  data_type
  |name_r data_type
{
    $$ = Node::makeNonTerminalNode(E_NAME_2_TYPE, 2, $1, $2);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
;

array_def:
    '[' row_expr_list ']'
{
    //square brackets
     Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  $2);
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    $$ = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, NULL, NULL, node_list);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    | ARRAY  '[' row_expr_list ']'
{
    Node * node_array = Node::makeTerminalNode(E_STRING,"ARRAY");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  $3);
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    $$ = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, node_array, NULL, node_list);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
    |  ARRAY array_mumber_def  '[' row_expr_list ']'
{
    Node * node_array = Node::makeTerminalNode(E_STRING,"ARRAY");

    Node * node_list = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_BRACKETS, 1,  $4);
    node_list->serialize_format = &SINGLE_WITH_BRACKETS_SERIALIZE_FORMAT;

    $$ = Node::makeNonTerminalNode(E_ARRAY_DEF, 3, node_array, $2, node_list);
    $$->serialize_format = &TRIPLE_SERIALIZE_FORMAT;
}
;

array_mumber_def:
    COMP_LT data_type COMP_GT
{
    $$ = Node::makeNonTerminalNode(E_ARRAY_MEMBER_DEF, 1, $2);
    $$->serialize_format = &MEMBER_DEF_SERIALIZE_FORMAT;
}
;


row_expr_list:
    row_expr
  | row_expr ',' row_expr_list
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

in_expr:
    table_subquery
  | '(' row_expr_list ')'
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST_WITH_PARENS, E_PARENS_PROPERTY_CNT, $2);
    $$->serialize_format = &SINGLE_WITH_PARENS_SERIALIZE_FORMAT;
}
;

truth_value: BOOL_VAL | UNKNOWN | NULLX
;

comp_op:
    COMP_LE		{ $$ = E_OP_LE; }
  | COMP_LT		{ $$ = E_OP_LT; }
  | COMP_GE		{ $$ = E_OP_GE; }
  | COMP_GT		{ $$ = E_OP_GT; }
  | COMP_EQ		{ $$ = E_OP_EQ; }
  | COMP_NE		{ $$ = E_OP_NE; }
  | COMP_GT COMP_EQ	{ $$ = E_OP_GE; }	/* this means qty >     = 15 is ok */
  | COMP_LT COMP_EQ	{ $$ = E_OP_LE; }	/* this means qty <     = 15 is ok */
  | COMP_LT COMP_GT	{ $$ = E_OP_NE; }	/* this means qty <     > 15 is ok */
  | '!' COMP_EQ		{ $$ = E_OP_NE; }	/* this means qty !     = 15 is ok */
;

cnn_op:
    CNNOP		{ $$ = E_OP_CNN; }
 // | CNNOP		{ $$ = E_OP_CNN; }	/* this means 'asd' |     | 'qwe' is ok */
;


comp_all_some_any_op:
    comp_op all_some_any
{
    $$ = Node::comp_all_some_any_op_form($1, $2);
}
;

bit_shift_op:
    OP_RS   { $$ = E_BIT_OP_RS; }
    | OP_LS { $$ = E_BIT_OP_LS; }
    | '&'   { $$ = E_BIT_OP_AND; }
    | '|'   { $$ = E_BIT_OP_OR; }
;

plus_minus_op:
    '+'		{ $$ = E_OP_ADD; }
  | '-'		{ $$ = E_OP_MINUS; }
;

star_div_percent_mod_op:
    '*'		{ $$ = E_OP_MUL; }
  | '/'		{ $$ = E_OP_DIV; }
;

expr_const:
    NULLX
  | INTNUM
  | APPROXNUM
  | QUESTIONMARK
  | PARAM
  //| DEFAULT		{ $$ = Node::makeTerminalNode(E_STRING, "DEFAULT"); }
  | const_string
  | numeric_num
   | BOOL_VAL
;

numeric_num:
    NUMERIC STR
{
    $$ = Node::makeTerminalNode(E_STRING, "NUMERIC"+$2->text());
    delete($2);
    $$->terminalToken_.str = $2->terminalToken_.str;
}
;

const_string:
    STR
    |TIME STR
{
    $$ = Node::makeTerminalNode(E_STRING, "TIME"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
    |TIMESTAMP STR
{
    $$ = Node::makeTerminalNode(E_STRING, "TIMESTAMP"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
    |DATE STR
{
    $$ = Node::makeTerminalNode(E_STRING, "DATE"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
    |DATETIME STR
{
    $$ = Node::makeTerminalNode(E_STRING, "DATETIME"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
;

/* sql2003 support <simple case> <searched case> */
case_expr:
    CASE case_arg when_clause_list case_default END
{
    $$ = Node::makeNonTerminalNode(E_CASE, E_CASE_PROPERTY_CNT, $2, $3, $4);
    $$->serialize_format = Node::op_serialize_format(E_CASE);
}
;

case_arg:
  %empty 	{ $$ = nullptr; }	/* sql2003 support <searched case> */
  | row_expr				/* sql2003 support <simple case> */
;

when_clause_list:
    when_clause
  | when_clause when_clause_list
{
    $$ = Node::makeNonTerminalNode(E_WHEN_LIST, E_LIST_PROPERTY_CNT, $1, $2);
    $$->serialize_format = &SPACE_LIST_SERIALIZE_FORMAT;
}
;

when_clause:
    WHEN search_condition THEN row_expr
{
    $$ = Node::makeNonTerminalNode(E_WHEN, E_WHEN_PROPERTY_CNT, $2, $4);
    $$->serialize_format = &WHEN_SERIALIZE_FORMAT;
}

;

case_default:
   %empty 	{ $$ = nullptr; }
  | ELSE row_expr
{
    $$ = Node::makeNonTerminalNode(E_CASE_DEFAULT, E_CASE_DEFAULT_PROPERTY_CNT, $2);
    $$->serialize_format = &ELSE_SERIALIZE_FORMAT;
}
;

/* todo */
func_expr:
    function_call_keyword
  | scalar_function
  | ranking_windowed_function
  | aggregate_windowed_function
  | bigquery_function
;

/* todo */
aggregate_windowed_function:
    aggregate_function_name '('                 row_expr ')' over_clause
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, $3, $5, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  | aggregate_function_name '('                 row_expr ')'
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  | aggregate_function_name '(' distinct_or_all row_expr ')' over_clause
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, $3, $4, nullptr, $6);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
  | aggregate_function_name '(' distinct_or_all row_expr ')'
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, $3, $4, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
  | aggregate_function_name '('                 '*'  ')' over_clause
{
    if (!Node::CHECK_FUNCTION_CALL_WITH_STAR($1))
    {
        yyerror(&@1, result, scanner, "error use *");
        YYABORT;
    }
    Node* star = Node::makeTerminalNode(E_STAR, "*");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, star, $5, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  | aggregate_function_name '('                 '*'  ')'
{
    if (!Node::CHECK_FUNCTION_CALL_WITH_STAR($1))
    {
        yyerror(&@1, result, scanner, "error use *");
        YYABORT;
    }
    Node* star = Node::makeTerminalNode(E_STAR, "*");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, star, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
;

aggregate_function_name:
    AVG			{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "AVG"); }
  | MAX			{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "MAX"); }
  | MIN			{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "MIN"); }
  | SUM			{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "SUM"); }
  | STDDEV_POP		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_POP"); }
  | STDDEV_SAMP		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV_SAMP"); }
  | VAR_POP		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "VAR_POP"); }
  | VAR_SAMP		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "VAR_SAMP"); }
  | COUNT		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "COUNT"); }
  | GROUPING		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "GROUPING"); }
;

ranking_windowed_function:
    ranking_function_name '('                      ')' over_clause
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, nullptr, $4, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
;

ranking_function_name:
    RANK		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "RANK"); }
  | DENSE_RANK		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "DENSE_RANK"); }
  | PERCENT_RANK	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "PERCENT_RANK"); }
  | CUME_DIST		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "CUME_DIST"); }
  | ROW_NUMBER		{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "ROW_NUMBER"); }
;

over_clause:
    OVER window_name
{
    $$ = Node::makeTerminalNode(E_IDENTIFIER, "OVER "+ $2->text()); delete($2);
}
  | OVER window_specification
{
    $$ = Node::makeNonTerminalNode(E_OVER_CLAUSE, 1, $2);
    $$->serialize_format = &OVER_CLAUSE_SERIALIZE_FORMAT;
}
;

opt_over_clause:
    %empty 	{ $$ = nullptr; }
    | over_clause
;

window_specification:
    '(' window_specification_details ')'
{ $$ = $2; }
;

window_name:
    name_r
;

window_specification_details:
    opt_existing_window_name opt_window_partition_clause opt_order_by opt_window_frame_clause
{
    $$ = Node::makeNonTerminalNode(E_WINDOW_SPECIFIC, E_WINDOW_SPECIFIC_PROPERTY_CNT, $1, $2, $3, $4);
    $$->serialize_format = &WINDOW_SPECIFIC_CLAUSE_SERIALIZE_FORMAT;
}
;

opt_existing_window_name:
   %empty 	{ $$ = nullptr; }
  | window_name
;

opt_window_partition_clause:
    %empty  { $$ = nullptr; }
  | PARTITION BY row_expr_list
{ $$ = $3; }
;

opt_window_frame_clause:
  %empty  { $$ = nullptr; }
  | window_frame_units window_frame_extent opt_window_frame_exclusion
{
    std::string s3 = $3 ? $3->text() : "";
    $$ = Node::makeTerminalNode(E_IDENTIFIER, $1->text()+" "+$2->text()+" "+s3);
    delete($1); delete($2); delete($3);
}
;

window_frame_units:
    ROWS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"ROWS"); }
  | RANGE	{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"RANGE"); }
;

window_frame_extent:
    window_frame_start
  | window_frame_between
;

window_frame_start:
    UNBOUNDED PRECEDING		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED PRECEDING"); }
  | CURRENT ROW			{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"CURRENT ROW"); }
  | window_frame_preceding
;

window_frame_preceding:
    expr_const PRECEDING	{ $$ = Node::makeTerminalNode(E_IDENTIFIER,$1->text()+" PRECEDING"); delete($1); }
;

window_frame_between:
    BETWEEN window_frame_bound AND window_frame_bound
{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "BETWEEN "+$2->text()+" AND "+$4->text()); delete($2); delete($4); }
;

window_frame_bound:
    window_frame_start
  | UNBOUNDED FOLLOWING		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"UNBOUNDED FOLLOWING"); }
  | window_frame_following
;

window_frame_following:
    expr_const FOLLOWING	{ $$ = Node::makeTerminalNode(E_IDENTIFIER,$1->text()+" FOLLOWING"); delete($1); }
;

opt_window_frame_exclusion:
    %empty  { $$ = nullptr; }
  | EXCLUDE CURRENT ROW		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE CURRENT ROW"); }
  | EXCLUDE GROUP		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE GROUP"); }
  | EXCLUDE TIES		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE TIES"); }
  | EXCLUDE NO OTHERS		{ $$ = Node::makeTerminalNode(E_IDENTIFIER,"EXCLUDE NO OTHERS"); }
;

scalar_function:
    custom_function_name '('                      ')'
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  | custom_function_name '('  row_expr_list ')'
{
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		$1, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
;

non_second_primary_datetime_field:
    YEAR
{
    $$ = Node::makeTerminalNode(E_STRING, "YEAR");
}
    | MONTH
{
    $$ = Node::makeTerminalNode(E_STRING, "MONTH");
}
    | DAY
{
    $$ = Node::makeTerminalNode(E_STRING, "DAY");
}
    | HOUR
{
    $$ = Node::makeTerminalNode(E_STRING, "HOUR");
}
    | MINUTE
{
    $$ = Node::makeTerminalNode(E_STRING, "MINUTE");
}
    | WEEK
{
    $$ = Node::makeTerminalNode(E_STRING, "WEEK");
}
    | QUARTER
{
    $$ = Node::makeTerminalNode(E_STRING, "QUARTER");
}
;

/* todo function_call_keyword with sql2003 keyword */
/* Function call syntax using official SQL 2003 keywords.
     Because the function name is an official token */
function_call_keyword:
////// bigquery function already contained this
//non_second_primary_datetime_field '(' row_expr ')'
//{
//$$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
//                               $1, $3, nullptr, nullptr, nullptr);
//$$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
//}
//|
  RIGHT '(' ')'
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "RIGHT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  | LEFT '(' ')'
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "LEFT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  |                            CAST '('    row_expr AS data_type ')'	/* sql2003 support <cast specification> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CAST");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
  |                         CONVERT '(' row_expr USING relation_factor ')'	/* sql2003 support <transcoding> */
{
    Node* transcoding_name = Node::makeTerminalNode(E_STRING, $5->text());
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT");
    delete($5);
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		fun_name, $3, nullptr, nullptr, transcoding_name);
    $$->serialize_format = &FUN_CALL_USING_SERIALIZE_FORMAT;
}
  |                        COALESCE '('            row_expr_list ')'	/* sql2003 support <case abbreviation> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  |               CURRENT_TIMESTAMP		'('	')'		/* sql2003 support <current timestamp value function> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  |               CURRENT_TIMESTAMP '('            INTNUM    ')'	/* sql2003 support <current timestamp value function> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
  |                    CURRENT_USER					/* sql2003 support <general value specification> */
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, nullptr, nullptr, nullptr, nullptr);
    $$->serialize_format = &SINGLE_SERIALIZE_FORMAT;
}
  |                        NULLIF '('          row_expr ',' row_expr ')'	/* sql2003 support <case abbreviation> */
{
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, expr_list, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_1_OVER_SERIALIZE_FORMAT;
}
;



/* todo sql2003 support <row type> */
data_type:
    predefined_type
    | combination_type
;

predefined_type:
INT64  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "INT64");}
| NUMERIC  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "NUMERIC");}
| FLOAT64  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "FLOAT64");}
| BOOL  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "BOOL");}
| STRING  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "STRING");}
| BYTES  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "BYTES");}
| DATE  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "DATE");}
| DATETIME  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "DATETIME");}
| TIME  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "TIME");}
| TIMESTAMP  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "TIMESTAMP");}
| ARRAY  { $$ = Node::makeTerminalNode(E_PRE_DEF_TYPE, "ARRAY");}
;

combination_type:
    struct_type
    |array_type
;

struct_type:
    STRUCT struct_mumber_def
{
    $$ = Node::makeNonTerminalNode(E_STRUCT_TYPE, 1, $2 );
    $$->serialize_format = &STRUCT_TYPE_SERIALIZE_FORMAT;
}
;
array_type:
    ARRAY array_mumber_def
{
    $$ = Node::makeNonTerminalNode(E_ARRAY_TYPE, 1, $2);
    $$->serialize_format = &ARRAY_TYPE_SERIALIZE_FORMAT;
}
;


distinct_or_all:
    ALL
{
    $$ = Node::makeTerminalNode(E_ALL, "ALL");
}
  | DISTINCT
{
    $$ = Node::makeTerminalNode(E_DISTINCT, "DISTINCT");
}
;

all_some_any:
     %empty 	{ $$ = -1; }
  |  ALL		{ $$ = 0; }
  | SOME	{ $$ = 1; }
  | ANY		{ $$ = 2; }
;

opt_as_label:
   %empty 	{ $$ = nullptr; }
  | as_label
;

as_label:
    AS label
  {
    $$ = $2;
  }
  | label
;

label:
    name_r
;

collate_clause:
    COLLATE relation_factor
{
    $$ = Node::makeTerminalNode(E_STRING, "COLLATE "+$2->text());
    delete($2);
}
;

/* NAME with some non-reserved words */
name_r:
    NAME
  | reserved
  | function_name
;

/* custom function name need without db fuction name */
name_f:
    NAME
  | reserved
;

reserved:   //this is non-reserved
     non_second_primary_datetime_field	%prec UMINUS
    | datatype_reserved
    | CALL			%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "CALL"); }
    | CODE_UNITS	%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "CODE_UNITS"); }
    | CORRESPONDING	%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "CORRESPONDING"); }
    //| DEC			%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "DEC"); }
    //| DELETE		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "DELETE"); }//by jeff
    | G 			%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "G"); }
    | INSERT		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "INSERT"); }
    | K				%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "K"); }
    | LARGE			%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "LARGE"); }
    | M				%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "M"); }
    | MOD			%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "MOD"); }
    | MULTISET		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "MULTISET"); }
    | NATIONAL		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "NATIONAL"); }
    //| NUMERIC		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "NUMERIC"); }
    | OBJECT		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "OBJECT"); }
    | OCTETS        %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "OCTETS"); }
    | ONLY          %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ONLY"); }
    | OTHERS        %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "OTHERS"); }
    | PRECISION     %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "PRECISION"); }
    | READ         %prec UMINUS     { $$ = Node::makeTerminalNode(E_IDENTIFIER, "READ"); }
    | REAL         %prec UMINUS     { $$ = Node::makeTerminalNode(E_IDENTIFIER, "REAL"); }
    | REF           %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "REF"); }
    | ROW           %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ROW"); }
    | SCOPE         %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SCOPE"); }
    | SECOND        %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SECOND"); }
    | SESSION_USER  %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SESSION_USER"); }
    | SETS          %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SETS"); }
    | SMALLINT       %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SMALLINT"); }
    | SYSTEM_USER     %prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_USER"); }
    | TIES           %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIES"); }
    //| UPDATE        %prec UMINUS    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "UPDATE"); }    //by jeff
    | VARCHAR        %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "VARCHAR"); }
    | VARYING        %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "VARYING"); }
    | WITHOUT        %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "WITHOUT"); }
    | ZONE  		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "ZONE"); }
    | OFFSET  		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "OFFSET"); }
    | ORDINAL        %prec UMINUS   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ORDINAL"); }
    | SAFE_ORDINAL  		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_ORDINAL"); }
    | SAFE_OFFSET  		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_OFFSET"); }
    | DAYOFWEEK         { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DAYOFWEEK"); }
    | DAYOFYEAR         { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DAYOFYEAR"); }
    | ISOWEEK           { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ISOWEEK"); }
    | ISOYEAR           { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ISOYEAR"); }
    | MICROSECOND       { $$ = Node::makeTerminalNode(E_IDENTIFIER, "MICROSECOND"); }
    | MILLISECOND       { $$ = Node::makeTerminalNode(E_IDENTIFIER, "MILLISECOND"); }
    | SUNDAY            { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SUNDAY"); }
    | MONDAY            { $$ = Node::makeTerminalNode(E_IDENTIFIER, "MONDAY"); }
    | TUESDAY           { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TUESDAY"); }
    | WEDNESDAY         { $$ = Node::makeTerminalNode(E_IDENTIFIER, "WEDNESDAY"); }
    | THURSDAY          { $$ = Node::makeTerminalNode(E_IDENTIFIER, "THURSDAY"); }
    | FRIDAY            { $$ = Node::makeTerminalNode(E_IDENTIFIER, "FRIDAY"); }
    | SATURDAY          { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SATURDAY"); }
    | AT                { $$ = Node::makeTerminalNode(E_IDENTIFIER, "AT"); }
;

function_name:
    aggregate_function_name	%prec UMINUS
    | ranking_function_name	%prec UMINUS
    | bigquery_func_name %prec UMINUS
    | call_keyword %prec UMINUS
;
call_keyword:
     CONVERT		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "CONVERT"); }//
    | NULLIF		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "NULLIF"); }
    | COALESCE		%prec UMINUS	{ $$ = Node::makeTerminalNode(E_IDENTIFIER, "COALESCE"); }//
    //| CURRENT_TIMESTAMP	%prec UMINUS { $$ = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_TIMESTAMP"); }
    //| CURRENT_USER		%prec UMINUS { $$ = Node::makeTerminalNode(E_IDENTIFIER, "CURRENT_USER"); }

;
bigquery_func_name:
     FIRST_VALUE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE"); }
    | LAST_VALUE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE"); }
    | NTH_VALUE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE"); }
    | LEAD { $$ = Node::makeTerminalNode(E_IDENTIFIER, "LEAD"); }
    | LAG { $$ = Node::makeTerminalNode(E_IDENTIFIER, "LAG"); }
    | PERCENTILE_CONT { $$ = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT"); }
    | PERCENTILE_DISC { $$ = Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC"); }
    | NTILE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "NTILE"); }
    | ARRAY_AGG { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_AGG"); }
    | CORR { $$ = Node::makeTerminalNode(E_IDENTIFIER, "CORR"); }
    | COVAR_POP { $$ = Node::makeTerminalNode(E_IDENTIFIER, "COVAR_POP"); }
    | COVAR_SAMP { $$ = Node::makeTerminalNode(E_IDENTIFIER, "COVAR_SAMP"); }
    | STRING_AGG { $$ = Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG"); }
    | ANY_VALUE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ANY_VALUE"); }
    | COUNTIF { $$ = Node::makeTerminalNode(E_IDENTIFIER, "COUNTIF"); }
    | SAFE_CAST { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_CAST"); }
    | ARRAY_CONCAT_AGG { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_CONCAT_AGG"); }
    | BIT_XOR { $$ = Node::makeTerminalNode(E_IDENTIFIER, "BIT_XOR"); }
    | LOGICAL_AND { $$ = Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_AND"); }
    | LOGICAL_OR { $$ = Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_OR"); }
    | APPROX_COUNT_DISTINCT { $$ = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_COUNT_DISTINCT"); }
    | APPROX_QUANTILES { $$ = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_QUANTILES"); }
    | APPROX_TOP_COUNT { $$ = Node::makeTerminalNode(E_IDENTIFIER, "APPROX_TOP_COUNT"); }
 /* date datetime time timestamp func */
    | EXTRACT  { $$ = Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT"); }
    | DATE_ADD { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATE_ADD"); }
    | DATE_SUB { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATE_SUB"); }
    | DATE_DIFF { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATE_DIFF"); }
    | DATE_TRUNC { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATE_TRUNC"); }
    | DATETIME_ADD { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_ADD"); }
    | DATETIME_SUB { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_SUB"); }
    | DATETIME_DIFF { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_DIFF"); }
    | DATETIME_TRUNC { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_TRUNC"); }
    | TIME_ADD { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIME_ADD"); }
    | TIME_SUB { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIME_SUB"); }
    | TIME_DIFF { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIME_DIFF"); }
    | TIME_TRUNC { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIME_TRUNC"); }
    | TIMESTAMP_ADD { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_ADD"); }
    | TIMESTAMP_SUB { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_SUB"); }
    | TIMESTAMP_DIFF { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_DIFF"); }
    | TIMESTAMP_TRUNC { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC"); }
/* string func */
    | TO_JSON_STRING { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING"); }
    | STDDEV { $$ = Node::makeTerminalNode(E_IDENTIFIER, "STDDEV"); }
    | VARIANCE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "VARIANCE"); }
    | STARTS_WITH { $$ = Node::makeTerminalNode(E_IDENTIFIER, "STARTS_WITH"); }
    | ENDS_WITH { $$ = Node::makeTerminalNode(E_IDENTIFIER, "ENDS_WITH"); }
    | REGEXP_CONTAINS { $$ = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_CONTAINS"); }
    | REGEXP_EXTRACT { $$ = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_EXTRACT"); }
    | REGEXP_REPLACE { $$ = Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_REPLACE"); }
    | GENERATE_TIMESTAMP_ARRAY { $$ = Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_TIMESTAMP_ARRAY"); }
    | GENERATE_DATE_ARRAY { $$ = Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_DATE_ARRAY"); }
    | SYSTEM_TIME { $$ = Node::makeTerminalNode(E_IDENTIFIER, "SYSTEM_TIME"); }
;
datatype_reserved:
    INT64       { $$ = Node::makeTerminalNode(E_IDENTIFIER, "INT64"); }
    | FLOAT64     { $$ = Node::makeTerminalNode(E_IDENTIFIER, "FLOAT64"); }
    | STRING      { $$ = Node::makeTerminalNode(E_IDENTIFIER, "STRING"); }
    | BYTES       { $$ = Node::makeTerminalNode(E_IDENTIFIER, "BYTES"); }
    | DATETIME    { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATETIME"); }
    | DATE        { $$ = Node::makeTerminalNode(E_IDENTIFIER, "DATE"); }
    | TIMESTAMP   { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP"); }
    | TIME        { $$ = Node::makeTerminalNode(E_IDENTIFIER, "TIME"); }
    | BOOL        { $$ = Node::makeTerminalNode(E_IDENTIFIER, "BOOL"); }
;

// https://cloud.google.com/bigquery/docs/reference/standard-sql/functions-and-operators
bigquery_function:
    date_function
    | datetime_function
    | time_function
    | string_function
    | ARRAY subquery
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $2, nullptr, nullptr, nullptr);
    $$->serialize_format = &DOUBLE_SERIALIZE_FORMAT;
}
    | FIRST_VALUE '('  value_expression opt_respect_nulls ')'   over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "FIRST_VALUE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  $3, $4, nullptr, $6);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LAST_VALUE '('  value_expression opt_respect_nulls ')'   over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAST_VALUE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $4, nullptr, $6);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | NTH_VALUE '(' value_expression ',' expr_const opt_respect_nulls ')'   over_clause
{   //NTH_VALUE (value_expression, constant_integer_expression [{RESPECT | IGNORE} NULLS]) over_clause
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "NTH_VALUE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list, $6, nullptr, $8);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LEAD '(' value_expression ')'   over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LEAD '(' value_expression ',' INTNUM ')'   over_clause
{   //LEAD (value_expression[, offset [, default_expression]])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $7);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LEAD '(' value_expression ',' INTNUM ',' value_expression ')'   over_clause
{   //LEAD (value_expression[, offset [, default_expression]])
    Node* expr_list1 = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list1->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, expr_list1, $7);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LEAD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $9);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LAG '(' value_expression ')'   over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LAG '(' value_expression ',' INTNUM ')'   over_clause
{
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $7);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LAG '(' value_expression ',' INTNUM ',' value_expression ')'   over_clause
{   //LAG (value_expression[, offset [, default_expression]])
    Node* expr_list1 = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list1->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, expr_list1, $7);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LAG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $9);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | PERCENTILE_CONT '(' row_expr ',' expr_const opt_respect_nulls ')'   over_clause
{   //PERCENTILE_CONT (value_expression, percentile [{RESPECT | IGNORE} NULLS])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_CONT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list,$6, nullptr, $8);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | PERCENTILE_DISC '(' row_expr ',' expr_const opt_respect_nulls ')'   over_clause
{   //PERCENTILE_DISC (value_expression, percentile [{RESPECT | IGNORE} NULLS])
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "PERCENTILE_DISC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name,  expr_list,$6, nullptr, $8);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | NTILE '(' value_expression ')'   over_clause
{   //NTILE(constant_integer_expression)
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "NTILE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | ARRAY_AGG '(' opt_distinct row_expr opt_respect_nulls opt_order_by limit_num ')' opt_over_clause
{   //ARRAY_AGG([DISTINCT] expression [{IGNORE|RESPECT} NULLS] [ORDER BY key [{ASC|DESC}] [, ... ]] [LIMIT n]) [OVER (...)]
    std::string ss = "";
    if($5){ss+= $5->text(); delete($5); }
    if($6){ss+= ss.empty() ? $6->text() : " " + $6->text(); delete($6); }
    if($7){ss+= ss.empty() ? $7->text() : " " + $7->text(); delete($7); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_AGG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $4,  transcoding_nod, $9);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | CORR '(' row_expr ',' row_expr ')' opt_over_clause
{   //CORR(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "CORR");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $7);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | COVAR_POP '(' row_expr ',' row_expr ')' opt_over_clause
{   //COVAR_POP(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COVAR_POP");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $7);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | COVAR_SAMP '(' row_expr ',' row_expr ')' opt_over_clause
{   //COVAR_SAMP(X1, X2)  [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $3, $5);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COVAR_SAMP");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, expr_list, nullptr, nullptr, $7);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | STRING_AGG '(' opt_distinct row_expr opt_respect_nulls opt_order_by limit_num ')' opt_over_clause
{   //STRING_AGG([DISTINCT] expression [, delimiter]  [ORDER BY key [{ASC|DESC}] [, ... ]]  [LIMIT n]) [OVER (...)]
    std::string ss = "";
    if($5){ss+= $5->text(); delete($5); }
    if($6){ss+= ss.empty() ? $6->text() : " " + $6->text(); delete($6); }
    if($7){ss+= ss.empty() ? $7->text() : " " + $7->text(); delete($7); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $4,  transcoding_nod, $9);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | STRING_AGG '(' opt_distinct row_expr ',' expr_const opt_respect_nulls opt_order_by limit_num ')' opt_over_clause
{   //STRING_AGG([DISTINCT] expression [, delimiter]  [ORDER BY key [{ASC|DESC}] [, ... ]]  [LIMIT n]) [OVER (...)]
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $4, $6);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    std::string ss = "";
    if($7){ss+= $7->text(); delete($7); }
    if($8){ss+= ss.empty() ? $8->text() : " " + $8->text(); delete($8); }
    if($9){ss+= ss.empty() ? $9->text() : " " + $9->text(); delete($9); }
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STRING_AGG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, expr_list,  transcoding_nod, $11);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | ANY_VALUE '(' value_expression ')'   opt_over_clause
{   //ANY_VALUE(expression)  [OVER (...)]
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ANY_VALUE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | COUNTIF '(' search_condition ')'   opt_over_clause
{   //COUNTIF(expression)  [OVER (...)]
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "COUNTIF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | SAFE_CAST '(' row_expr AS data_type ')'
{
    Node* fun_name = Node::makeTerminalNode(E_IDENTIFIER, "SAFE_CAST");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
    		fun_name, $3, nullptr, nullptr, $5);
    $$->serialize_format = &FUN_CALL_AS_SERIALIZE_FORMAT;
}
    | ARRAY_CONCAT_AGG '(' row_expr opt_order_by limit_num ')'
{   //ARRAY_CONCAT_AGG(expression  [ORDER BY key [{ASC|DESC}] [, ... ]] [LIMIT n])
    std::string ss = "";
    if($4){ss+= $4->text(); delete($4);}
    if($5){ss+= ss.empty() ? $5->text() : " " + $5->text(); delete($5);}
    Node* transcoding_nod = Node::makeTerminalNode(E_STRING, ss);

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ARRAY_CONCAT_AGG");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3,  transcoding_nod, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | BIT_XOR '(' opt_distinct row_expr ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "BIT_XOR");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $4, nullptr,  nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LOGICAL_AND '(' search_condition ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_AND");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | LOGICAL_OR '(' search_condition ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "LOGICAL_OR");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, nullptr, nullptr, nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | APPROX_COUNT_DISTINCT '(' opt_distinct row_expr ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_COUNT_DISTINCT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $4, nullptr,  nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | APPROX_QUANTILES '(' opt_distinct row_expr ',' INTNUM opt_respect_nulls ')'
{
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $4, $6);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;

    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_QUANTILES");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, expr_list, $7, nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | APPROX_TOP_COUNT '(' opt_distinct row_expr ',' INTNUM ')'
{
    Node* expr_list = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $4, $6);
    expr_list->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "APPROX_TOP_COUNT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, expr_list, nullptr,  nullptr);
    $$->serialize_format = &FUN_CALL_DIS_OVER_SERIALIZE_FORMAT;
}
    | IF '(' search_condition ',' row_expr ',' row_expr ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "IF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
;

opt_window_clause:
    %empty {$$ = NULL;}
    | window_clause
;

window_clause:
    WINDOW window_list
{
    $$ = Node::makeTerminalNode(E_STRING, " WINDOW "+ $2->text());
    delete($2);
}
;

window_list:
    window_list_element
    | window_list_element ',' window_list
{
    $$ = Node::makeNonTerminalNode(E_EXPR_LIST, E_LIST_PROPERTY_CNT, $1, $3);
    $$->serialize_format = &COMMA_LIST_SERIALIZE_FORMAT;
}
;

window_list_element:
    NAME AS NAME
{
    $$ = Node::makeTerminalNode(E_STRING,  $1->text() + " AS " + $3->text() );
    delete($1);
    delete($3);

}
    |  NAME AS window_specification
{
    $$ = Node::makeTerminalNode(E_STRING,  $1->text() + " AS " + $3->text() );
    delete($1);
    delete($3);
}
;

opt_respect_nulls:
    %empty { $$ = NULL;}
    | RESPECT NULLS
{
    $$ =  Node::makeTerminalNode(E_STRING, " RESPECT NULLS ");
}
    | IGNORE NULLS
{
    $$ =  Node::makeTerminalNode(E_STRING, " IGNORE NULLS ");
}
;

date_part:
    day_part
    | hour_part
    | ext_day_part1
    | ext_day_part2
    | week_func
    | DATE  { $$ =  Node::makeTerminalNode(E_STRING, " DATE");}
    | DATETIME  { $$ =  Node::makeTerminalNode(E_STRING, "DATETIME");}
    | TIME { $$ =  Node::makeTerminalNode(E_STRING, "TIME");}
;

datetime_part:
    hour_part
    | day_part
;

datetime_part2:
    hour_part
    | day_part
    | ext_day_part2
    | week_func
;

day_part:
    DAY { $$ =  Node::makeTerminalNode(E_STRING, "DAY"); }
    | WEEK { $$ =  Node::makeTerminalNode(E_STRING, "WEEK"); }
    | MONTH { $$ =  Node::makeTerminalNode(E_STRING, "MONTH"); }
    | QUARTER { $$ =  Node::makeTerminalNode(E_STRING, "QUARTER"); }
    | YEAR { $$ =  Node::makeTerminalNode(E_STRING, "YEAR"); }
;
ext_day_part1:
    DAYOFWEEK { $$ =  Node::makeTerminalNode(E_STRING, "DAYOFWEEK"); }
    | DAYOFYEAR { $$ =  Node::makeTerminalNode(E_STRING, "DAYOFYEAR"); }
;
ext_day_part2:
     ISOWEEK { $$ =  Node::makeTerminalNode(E_STRING, "ISOWEEK"); }
    | ISOYEAR { $$ =  Node::makeTerminalNode(E_STRING, "ISOYEAR"); }
;
hour_part:
    MICROSECOND { $$ =  Node::makeTerminalNode(E_STRING, "MICROSECOND"); }
    | MILLISECOND { $$ =  Node::makeTerminalNode(E_STRING, "MILLISECOND"); }
    | SECOND { $$ =  Node::makeTerminalNode(E_STRING, "SECOND"); }
    | MINUTE { $$ =  Node::makeTerminalNode(E_STRING, "MINUTE"); }
    | HOUR { $$ =  Node::makeTerminalNode(E_STRING, "HOUR"); }
;
hour_day_part:
    hour_part
    | DAY { $$ =  Node::makeTerminalNode(E_STRING, "DAY"); }
;
week_func:
    WEEK '(' week_ ')' { $$ =  Node::makeTerminalNode(E_STRING, "WEEK("+$3->text()+")"); delete($3); }
;
week_:
    SUNDAY  { $$ =  Node::makeTerminalNode(E_STRING, "SUNDAY"); }
    | MONDAY { $$ =  Node::makeTerminalNode(E_STRING, "MONDAY"); }
    | TUESDAY { $$ =  Node::makeTerminalNode(E_STRING, "TUESDAY"); }
    | WEDNESDAY { $$ =  Node::makeTerminalNode(E_STRING, "WEDNESDAY"); }
    | THURSDAY { $$ =  Node::makeTerminalNode(E_STRING, "THURSDAY"); }
    | FRIDAY { $$ =  Node::makeTerminalNode(E_STRING, "FRIDAY"); }
    | SATURDAY { $$ =  Node::makeTerminalNode(E_STRING, "SATURDAY"); }
;

date_expression:
    name_r
    | DATE STR
{
    $$ = Node::makeTerminalNode(E_STRING, "DATE"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
;

datetime_expression:
    name_r
    | DATETIME STR
{
    $$ = Node::makeTerminalNode(E_STRING, "DATETIME"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
;

timestamp_expression:
    name_r
    | func_expr
    | TIMESTAMP STR
{
    $$ = Node::makeTerminalNode(E_STRING, "TIMESTAMP"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
    | TIME STR
{
    $$ = Node::makeTerminalNode(E_STRING, "TIME"+$2->text());
    $$->terminalToken_.str = $2->terminalToken_.str;
    delete($2);
}
;

all_date_expression:
    name_r
    | const_string
;

opt_at_time_zone:
    %empty { $$ =NULL;}
    | AT TIME ZONE STR { $$ = Node::makeTerminalNode(E_STRING, " AT TIME ZONE "+$4->text()); delete($4); }
;

interval_date_part:
    INTERVAL row_expr day_part
{
    std::string node = " INTERVAL ";
    node += $2->text();    delete($2);
    node += " ";
    node += $3->text();    delete($3);
    $$ = Node::makeTerminalNode(E_STRING, node);
}
;

interval_datetime_part:
    INTERVAL row_expr datetime_part
{
    std::string node = " INTERVAL ";
    node += $2->text();    delete($2);
    node += " ";
    node += $3->text();    delete($3);
    $$ = Node::makeTerminalNode(E_STRING, node);
}
;

interval_time_part:
    INTERVAL row_expr hour_day_part
{
    std::string node = " INTERVAL ";
    node += $2->text();    delete($2);
    node += " ";
    node += $3->text();    delete($3);
    $$ = Node::makeTerminalNode(E_STRING, node);
}
;

date_function:
    EXTRACT '(' date_part FROM all_date_expression opt_at_time_zone ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "EXTRACT");
    std::string s_param;
    s_param += $3->text(); delete($3);
    s_param += " FROM ";
    s_param += $5->text(); delete($5);
    if($6){ s_param += $6->text(); delete($6); }
    Node * param = Node::makeTerminalNode(E_STRING, s_param);
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, param, NULL, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | DATE_ADD '(' date_expression ',' interval_date_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_ADD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | DATE_SUB '(' date_expression ',' interval_date_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_SUB");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | DATE_DIFF '(' date_expression ',' date_expression ',' date_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_DIFF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    //| DATE( row_expr_list )  /* supported already */
    | DATE_TRUNC '(' date_expression ',' date_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATE_TRUNC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | GENERATE_DATE_ARRAY '(' row_expr ',' row_expr ',' interval_date_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_DATE_ARRAY");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    //| FORMAT_DATE '(' STR ',' date_expression ')'
    //| UNIX_DATE '(' date_expression ')'
;

datetime_function:
    DATETIME_ADD  '(' datetime_expression ',' interval_datetime_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_ADD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | DATETIME_SUB  '(' datetime_expression ',' interval_datetime_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_SUB");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | DATETIME_DIFF  '(' datetime_expression ',' datetime_expression ',' datetime_part2 ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_DIFF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
   // | DATETIME '(' row_expr_list ')'
    | DATETIME_TRUNC '(' datetime_expression ',' datetime_part2 ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "DATETIME_TRUNC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    // FORMAT_DATETIME '(' STR ',' datetime_expression ')'
;
time_function:
    TIME_ADD '(' timestamp_expression ',' interval_time_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_ADD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TIME_SUB '(' timestamp_expression ',' interval_time_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_SUB");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TIME_DIFF '(' timestamp_expression ',' timestamp_expression ',' hour_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_DIFF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    // | TIME '(' row_expr_list ')'
    | TIME_TRUNC '(' timestamp_expression ',' hour_part  ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIME_TRUNC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    //| FORMAT_TIME  '(' STR ',' datetime_expression ')'
    | TIMESTAMP_ADD '(' timestamp_expression ',' interval_time_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_ADD");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TIMESTAMP_SUB '(' timestamp_expression ',' interval_time_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_SUB");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TIMESTAMP_DIFF '(' timestamp_expression ',' timestamp_expression ',' hour_day_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_DIFF");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    // | TIMESTAMP '(' row_expr_list ')'
    | TIMESTAMP_TRUNC '(' timestamp_expression ',' datetime_part2  ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TIMESTAMP_TRUNC '(' timestamp_expression ',' datetime_part2 ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TIMESTAMP_TRUNC");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    //| FORMAT_TIMESTAMP  '(' STR ',' datetime_expression ')'

    | GENERATE_TIMESTAMP_ARRAY '(' row_expr ',' row_expr ',' interval_datetime_part ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "GENERATE_TIMESTAMP_ARRAY");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
;

string_function:
    TO_JSON_STRING '(' name_r ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
                name, $3, NULL, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | TO_JSON_STRING '(' name_r ',' search_condition ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "TO_JSON_STRING");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | STDDEV '(' opt_distinct row_expr  ')' opt_over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STDDEV");
    std::string s_param;
    if($3) {s_param += "DISTINCT "; delete($3);}
    Node * param = Node::makeTerminalNode(E_STRING, s_param + $4->text());  delete($4);
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, param, NULL, NULL, $6);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | VARIANCE '(' opt_distinct row_expr  ')' opt_over_clause
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "VARIANCE");
    std::string s_param;
    if($3) { s_param += "DISTINCT "; delete($3); }
    Node * param = Node::makeTerminalNode(E_STRING, s_param + $4->text());  delete($4);
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, param, NULL, NULL,  $6);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | STARTS_WITH '(' name_r ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "STARTS_WITH");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | ENDS_WITH  '(' name_r ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "ENDS_WITH");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | REGEXP_CONTAINS '(' name_r ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_CONTAINS");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | REGEXP_EXTRACT '(' name_r ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_EXTRACT");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, NULL, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
    | REGEXP_REPLACE '(' name_r ',' STR ',' STR ')'
{
    Node * name =  Node::makeTerminalNode(E_IDENTIFIER, "REGEXP_REPLACE");
    $$ = Node::makeNonTerminalNode(E_FUN_CALL, E_FUN_CALL_PROPERTY_CNT,
        		name, $3, $5, $7, NULL);
    $$->serialize_format = &FUN_CALL_BIGQUERY_S_FORMAT;
}
;



%%
/*********************************
 ** Section 4: Additional C code
 *********************************/


