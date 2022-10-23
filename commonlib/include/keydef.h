#ifndef KEY_DEF_H
#define KEY_DEF_H

#include <list>
#include <string>
#include <set>
#include "node_struct.h"

enum NodeType {
    E_NODETYPE_BEGIN = 0,

    /* terminal */
    E_NULL,
    E_INT,
    E_DOUBLE,
    E_BOOL,
    E_STRING,
    E_IDENTIFIER,
    E_TEMP_VARIABLE,
    E_QUESTIONMARK,
    E_PARAMETER,
    E_ALL,
    E_DISTINCT,
    E_STAR,

    E_DATA_TYPE,

    E_SET_UNION,
    E_SET_INTERSECT,
    E_SET_EXCEPT,

    E_SORT_ASC,
    E_SORT_DESC,

    E_JOIN_INNER,
    E_JOIN_FULL,
    E_JOIN_LEFT,
    E_JOIN_RIGHT,
    E_JOIN_CROSS,
    E_JOIN_NATURAL,


    /* nonterminal */
    E_SP_EXECUTESQL,

    E_DIRECT_SELECT,

    E_STMT_LIST,
    E_SELECT,
    E_SELECT_WITH_PARENS,


    E_FROM_CLAUSE,


    E_WHERE_CLAUSE,

    E_LIMIT_CLAUSE,

    E_GROUP_BY,

    E_ORDER_BY,
    E_HAVING,
    E_WHEN,



    E_SORT_LIST,

    E_SORT_KEY,

    E_SELECT_EXPR_LIST,

    E_PROJECT_STRING,
    E_ALIAS,


    E_FROM_LIST,

    E_JOINED_TABLE,
    E_JOINED_TABLE_WITH_PARENS,




    E_OP_NAME_FIELD,
    E_OP_EXISTS,
    E_OP_POS,
    E_OP_NEG,
    E_OP_ADD,
    E_OP_MINUS,
    E_OP_MUL,
    E_OP_DIV,
    E_OP_REM,
    E_OP_POW,
    E_OP_MOD,

    E_BIT_OP_AND,// &
    E_BIT_OP_OR, // |
    E_BIT_OP_NOT,// ~
    E_BIT_OP_LS,// <<
    E_BIT_OP_RS,// >>

    E_OP_LE,
    E_OP_LT,
    E_OP_EQ,
    E_OP_GE,
    E_OP_GT,
    E_OP_NE,

    E_OP_LE_ALL,
    E_OP_LT_ALL,
    E_OP_EQ_ALL,
    E_OP_GE_ALL,
    E_OP_GT_ALL,
    E_OP_NE_ALL,

    E_OP_LE_SOME,
    E_OP_LT_SOME,
    E_OP_EQ_SOME,
    E_OP_GE_SOME,
    E_OP_GT_SOME,
    E_OP_NE_SOME,

    E_OP_LE_ANY,
    E_OP_LT_ANY,
    E_OP_EQ_ANY,
    E_OP_GE_ANY,
    E_OP_GT_ANY,
    E_OP_NE_ANY,

    E_OP_LIKE,
    E_OP_NOT_LIKE,
    E_OP_AND,
    E_OP_OR,
    E_OP_NOT,
    E_OP_IS,
    E_OP_IS_NOT,
    E_OP_BTW,
    E_OP_NOT_BTW,
    E_OP_IN,
    E_OP_NOT_IN,
    E_OP_CNN,               // STRING CONNECTOR
    E_OP_AND_SPC,

    E_OP_ASS,
    E_OP_ASS_ADD,
    E_OP_ASS_MINUS,
    E_OP_ASS_MUL,
    E_OP_ASS_DIV,
    E_OP_ASS_REM,
    E_OP_ASS_BIT_AND,
    E_OP_ASS_BIT_OR,
    E_OP_ASS_BIT_XOR,

    E_OP_COLLATE,

    E_EXPR_LIST,
    E_EXPR_LIST_WITH_PARENS,
    E_EXPR_LIST_WITH_BRACKETS,

    E_CASE,
    E_CASE_DEFAULT,

    E_FUN_CALL,

    E_WHEN_LIST,

    E_TOP_CNT,
    E_TOP_PCT,
    E_TOP_CNT_TIES,
    E_TOP_PCT_TIES,

    E_SIMPLE_IDENT_LIST,
    E_SIMPLE_IDENT_LIST_WITH_PARENS,
    E_OPT_DERIVED_COLUMN_LIST,
    E_COMMON_TABLE_EXPR,
    E_WITH_LIST,
    E_OPT_WITH_CLAUSE,

    E_TABLE_IDENT,
    E_OFFSET_FETCH,
    E_FOR_CLAUSE,
    E_WITH_TABLE_HINT,
    E_TABLE_HINT_LIST,
    E_TABLE_HINT_NOEXPAND,
    E_OPTION_CLAUSE,
    E_QUERY_HINT_LIST,
    E_QUERY_HINT,

    E_PROC_IDENT,
    E_OVER_CLAUSE,
    E_ROWS_CLAUSE,
    E_RANGE_CLAUSE,

    E_TABLE_VALUE_CTOR,
    E_TABLE_VALUE_CTOR_PARENS,

    E_FOR_SYSTEM_TIME,
    E_PIVOT_TABLE,
    E_UNPIVOT_TABLE,
    E_PIVOT_CLAUSE,
    E_UNPIVOT_CLAUSE,

    E_TEMP_VAR_FUN_CALL,
    E_INTO_CLAUSE,

    E_CREATE_TABLE,

    E_RELATION_FACTOR_LIST,
    E_DROP_TABLE,

    E_UPDATE,
    E_UPDATE_ELEM_LIST,
    E_UPDATE_ELEM,
    E_DML_SELECT_LIST,
    E_DML_SELECT_ITEM,
    E_OUTPUT_CLAUSE,
    E_USE,
    E_DELETE,
    E_NAME_CHAIN,

    E_INSERT,
    E_INSERT_COLUMNS_AND_SOURCE,
    E_VALUES_CTOR,

    E_CALL,
    E_SQL_ARGUMENT,
    E_SQL_ARGUMENT_LIST,

    E_NODETYPE_END,

    E_LIMIT_NUM,
    E_OFFSET_NUM,
    E_PARAM,

    E_ASTERISK_EXPR,
    E_ASTERISK_QUALIFY,
    /*-------BIGQUERY--------*/
    E_EXCEPT_EXPR,
    E_REPLACE_EXPR,
    E_ROW_EXPR_AS_LABEL,
    E_ROW_EXPR_AS_LABEL_LIST,
    E_STRUCT_DEF,
    E_ARRAY_DEF,
    E_NAME_TYPE_LIST,
    E_NAME_2_TYPE,
    E_STRUCT_MEMBER_DEF,
    E_ARRAY_MEMBER_DEF,
    E_DATA_TYPE_LIST,
    E_PRE_DEF_TYPE,
    E_STRUCT_TYPE,
    E_ARRAY_TYPE,
    E_AS_STRUCT_VALUE,
    E_AS_STRUCT,
    E_UNNEST_DEF,
    E_SELECT_EXPR_COMMA,
    E_ARRAY_INDEX,
    E_WINDOW_SPECIFIC,
    /*-------ORACLE--------*/
    E_STMT_BODYS,
    EORA_PARAM,
    EORA_FETCH_ROW,
    E_VAR_LIST,
    EORA_RETURNING_INTO,
    EORA_OFFSET_ROW,
    EROA_SEARCH_CLAUSE,
    EORA_CYCLE_CLAUSE,
    EORA_START_WITH,
    EORA_CONNECT_BY,
    EORA_HIERARCHICAL_CLAUSE,
    EORA_SEED_VALUE,
    EORA_SAMPLE_CLAUSE,
    EORA_OFFSET_FETCH,
    EORA_PARTITION_BY,
    EORA_ALTER_SESSION,

    /* ------ HANA ------ */
    E_OP_MEMBER,
    E_OP_NOT_MEMBER,
    E_TABLE_VAR,
    E_TOP_CLAUSE,
    E_FOR_UPDATE,
    E_WAIT_INT,
    E_HINT_CLAUSE,
    E_FOR,
    E_NOWAIT,
    E_CONSTRUCT_FROM_TABLE,
    E_CONSTRUCT_COL_LIST,
    E_CONSTRUCT_COL,
    E_UPSERT,
    E_REPLACE,
    E_POINT_VALUE,
    E_UNNEST_TABLE,
    E_COLLECT_VAL_LIST,
    E_COLLECT_VAL,
    E_AS_DERIVED_PART,
    E_INSERT_SELECT,
    E_AGG_ORDER,
    E_CASE_JOIN, E_CASE_JOIN_WHEN_LIST, E_CASE_JOIN_WHEN, E_CASE_JOIN_RET, E_CASE_JOIN_ELSE, E_CASE_JOIN_TABLE,
    E_LATERAL_QUERY,
    E_ASSOCIATED_TABLE ,    E_ASSOCIATED_REF_LIST,     E_ASSOCIATED_REF,
    E_ORDER_BY_EXPR, E_ORDER_BY_CLAUSE, E_WITHIN_GROUP,
    E_OF_COLUMS,
    E_TIME_TRAVEL,
    E_FOR_CLAUSE_HANA,  E_RETURNS_CLAUSE, E_OPTION_STRING,
    E_OP_LIKE_REGEXPR,
    E_SET_HANA,
    /*-----------DB2------*/
    E_SPECIAL_CLAUSE_LIST,
    E_DB2_CONSTRUCT_TABLE,
    E_COLUMN_DEFINED,
    E_INSERT_COLUMNS_AND_SOURCE_DB2,
    /*---------SQLSERVER------*/
    E_UNPIVOT_PIVOT,



    E_SPECIAL_TERMINAL
};

const std::string str_arr[] = {
    "E_NODETYPE_BEGIN",
    /* terminal */
    "E_NULL",
    "E_INT",
    "E_DOUBLE",
    "E_BOOL",
    "E_STRING",
    "E_IDENTIFIER",
    "E_TEMP_VARIABLE",
    "E_QUESTIONMARK",
    "E_PARAMETER",
    "E_ALL",
    "E_DISTINCT",
    "E_STAR",

    "E_DATA_TYPE",

    "E_SET_UNION",
    "E_SET_INTERSECT",
    "E_SET_EXCEPT",

    "E_SORT_ASC",
    "E_SORT_DESC",

    "E_JOIN_INNER",
    "E_JOIN_FULL",
    "E_JOIN_LEFT",
    "E_JOIN_RIGHT",
    "E_JOIN_CROSS",
    "E_JOIN_NATURAL",


    /* nonterminal */
    "E_SP_EXECUTESQL",
    "E_DIRECT_SELECT",

    "E_STMT_LIST",
    "E_SELECT",
    "E_SELECT_WITH_PARENS",


    "E_FROM_CLAUSE",


    "E_WHERE_CLAUSE",

    "E_LIMIT_CLAUSE",

    "E_GROUP_BY",

    "E_ORDER_BY",
    "E_HAVING",
    "E_WHEN",



    "E_SORT_LIST",

    "E_SORT_KEY",

    "E_SELECT_EXPR_LIST",

    "E_PROJECT_STRING",
    "E_ALIAS",


    "E_FROM_LIST",

    "E_JOINED_TABLE",
    "E_JOINED_TABLE_WITH_PARENS",




    "E_OP_NAME_FIELD",
    "E_OP_EXISTS",
    "E_OP_POS",
    "E_OP_NEG",
    "E_OP_ADD",
    "E_OP_MINUS",
    "E_OP_MUL",
    "E_OP_DIV",
    "E_OP_REM",
    "E_OP_POW",
    "E_OP_MOD",

    "E_BIT_OP_AND",// &
    "E_BIT_OP_OR", // |
    "E_BIT_OP_NOT",// ~
    "E_BIT_OP_LS",// <<
    "E_BIT_OP_RS",// >>

    "E_OP_LE",
    "E_OP_LT",
    "E_OP_EQ",
    "E_OP_GE",
    "E_OP_GT",
    "E_OP_NE",

    "E_OP_LE_ALL",
    "E_OP_LT_ALL",
    "E_OP_EQ_ALL",
    "E_OP_GE_ALL",
    "E_OP_GT_ALL",
    "E_OP_NE_ALL",

    "E_OP_LE_SOME",
    "E_OP_LT_SOME",
    "E_OP_EQ_SOME",
    "E_OP_GE_SOME",
    "E_OP_GT_SOME",
    "E_OP_NE_SOME",

    "E_OP_LE_ANY",
    "E_OP_LT_ANY",
    "E_OP_EQ_ANY",
    "E_OP_GE_ANY",
    "E_OP_GT_ANY",
    "E_OP_NE_ANY",

    "E_OP_LIKE",
    "E_OP_NOT_LIKE",
    "E_OP_AND",
    "E_OP_OR",
    "E_OP_NOT",
    "E_OP_IS",
    "E_OP_IS_NOT",
    "E_OP_BTW",
    "E_OP_NOT_BTW",
    "E_OP_IN",
    "E_OP_NOT_IN",
    "E_OP_CNN",               // STRING CONNECTOR
    "E_OP_AND_SPC",

    "E_OP_ASS",
    "E_OP_ASS_ADD",
    "E_OP_ASS_MINUS",
    "E_OP_ASS_MUL",
    "E_OP_ASS_DIV",
    "E_OP_ASS_REM",
    "E_OP_ASS_BIT_AND",
    "E_OP_ASS_BIT_OR",
    "E_OP_ASS_BIT_XOR",

    "E_OP_COLLATE",

    "E_EXPR_LIST",
    "E_EXPR_LIST_WITH_PARENS",
    "E_EXPR_LIST_WITH_BRACKETS",

    "E_CASE",
    "E_CASE_DEFAULT",

    "E_FUN_CALL",

    "E_WHEN_LIST",

    "E_TOP_CNT",
    "E_TOP_PCT",
    "E_TOP_CNT_TIES",
    "E_TOP_PCT_TIES",

    "E_SIMPLE_IDENT_LIST",
    "E_SIMPLE_IDENT_LIST_WITH_PARENS",
    "E_OPT_DERIVED_COLUMN_LIST",
    "E_COMMON_TABLE_EXPR",
    "E_WITH_LIST",
    "E_OPT_WITH_CLAUSE",

    "E_TABLE_IDENT",
    "E_OFFSET_FETCH",
    "E_FOR_CLAUSE",
    "E_WITH_TABLE_HINT",
    "E_TABLE_HINT_LIST",
    "E_TABLE_HINT_NOEXPAND",
    "E_OPTION_CLAUSE",
    "E_QUERY_HINT_LIST",
    "E_QUERY_HINT",

    "E_PROC_IDENT",
    "E_OVER_CLAUSE",
    "E_ROWS_CLAUSE",
    "E_RANGE_CLAUSE",

    "E_TABLE_VALUE_CTOR",
    "E_TABLE_VALUE_CTOR_PARENS",

    "E_FOR_SYSTEM_TIME",
    "E_PIVOT_TABLE",
    "E_UNPIVOT_TABLE",
    "E_PIVOT_CLAUSE",
    "E_UNPIVOT_CLAUSE",

    "E_TEMP_VAR_FUN_CALL",
    "E_INTO_CLAUSE",

    "E_CREATE_TABLE",

    "E_RELATION_FACTOR_LIST",
    "E_DROP_TABLE",

    "E_UPDATE",
    "E_UPDATE_ELEM_LIST",
    "E_UPDATE_ELEM",
    "E_DML_SELECT_LIST",
    "E_DML_SELECT_ITEM",
    "E_OUTPUT_CLAUSE",
    "E_USE",
    "E_DELETE",
    "E_NAME_CHAIN",

    "E_INSERT",
    "E_INSERT_COLUMNS_AND_SOURCE",
    "E_VALUES_CTOR",

    "E_CALL",
    "E_SQL_ARGUMENT",
    "E_SQL_ARGUMENT_LIST",

    "E_NODETYPE_END",

    "E_LIMIT_NUM",
    "E_OFFSET_NUM",
    "E_PARAM",

    "E_ASTERISK_EXPR",
    "E_ASTERISK_QUALIFY",
    /*-------BIGQUERY--------*/
    "E_EXCEPT_EXPR",
    "E_REPLACE_EXPR",
    "E_ROW_EXPR_AS_LABEL",
    "E_ROW_EXPR_AS_LABEL_LIST",
    "E_STRUCT_DEF",
    "E_ARRAY_DEF",
    "E_NAME_TYPE_LIST",
    "E_NAME_2_TYPE",
    "E_STRUCT_MEMBER_DEF",
    "E_ARRAY_MEMBER_DEF",
    "E_DATA_TYPE_LIST",
    "E_PRE_DEF_TYPE",
    "E_STRUCT_TYPE",
    "E_ARRAY_TYPE",
    "E_AS_STRUCT_VALUE",
    "E_AS_STRUCT",
    "E_UNNEST_DEF",
    "E_SELECT_EXPR_COMMA",
    "E_ARRAY_INDEX",
    "E_WINDOW_SPECIFIC",
    /*-------ORACLE--------*/
    "EORA_PARAM",
    "EORA_FETCH_ROW",
    "E_VAR_LIST",
    "EORA_RETURNING_INTO",
    "EORA_OFFSET_ROW",
    "EROA_SEARCH_CLAUSE",
    "EORA_CYCLE_CLAUSE",
    "EORA_START_WITH",
    "EORA_CONNECT_BY",
    "EORA_HIERARCHICAL_CLAUSE",
    "EORA_SEED_VALUE",
    "EORA_SAMPLE_CLAUSE",
    "EORA_OFFSET_FETCH",
    "EORA_PARTITION_BY",

    /* ------ HANA ------ */
    "E_OP_MEMBER",
    "E_OP_NOT_MEMBER",
    "E_TABLE_VAR",
    "E_TOP_CLAUSE",
    "E_FOR_UPDATE",
    "E_WAIT_INT",
    "E_HINT_CLAUSE",
    "E_FOR",
    "E_NOWAIT",
    "E_CONSTRUCT_FROM_TABLE",
    "E_CONSTRUCT_COL_LIST",
    "E_CONSTRUCT_COL",
    "E_UPSERT",
    "E_REPLACE",
    "E_POINT_VALUE",
    "E_UNNEST_TABLE",
    "E_COLLECT_VAL_LIST",
    "E_COLLECT_VAL",
    "E_AS_DERIVED_PART",
    "E_INSERT_SELECT",
    "E_AGG_ORDER",
    "E_CASE_JOIN", "E_CASE_JOIN_WHEN_LIST", "E_CASE_JOIN_WHEN", "E_CASE_JOIN_RET", "E_CASE_JOIN_ELSE", "E_CASE_JOIN_TABLE",
    "E_LATERAL_QUERY",
    "E_ASSOCIATED_TABLE ",    "E_ASSOCIATED_REF_LIST",     "E_ASSOCIATED_REF",
    "E_ORDER_BY_EXPR", "E_ORDER_BY_CLAUSE", "E_WITHIN_GROUP",
    "E_OF_COLUMS",
    "E_TIME_TRAVEL",
    "E_FOR_CLAUSE_HANA",  "E_RETURNS_CLAUSE", "E_OPTION_STRING",


    "E_SPECIAL_TERMINAL"
};

enum StmtType {
    E_NONE,
    E_STMT_TYPE_CREATE_TABLE,
    E_STMT_TYPE_DROP_TABLE,
    E_STMT_TYPE_SELECT,
    E_STMT_TYPE_UPDATE,
    E_STMT_TYPE_DELETE,
    E_STMT_TYPE_INSERT,
    E_STMT_TYPE_USE,
    E_STMT_TYPE_CALL,
};

enum TableItemType {
    E_UNKNOWN,
    E_BASIC_TABLE,
    E_BASIC_TABLE_WITH_ALIAS,
    E_DERIVED_TABLE,
    E_CTE_TABLE,
};

#define OB_INVALID_ID  0
#define OB_APP_MIN_COLUMN_ID  500

const std::set<std::string> TABLE_HINT_WORDS{
    "INDEX", "FORCESEEK", "FORCESCAN", "HOLDLOCK", "NOLOCK",
    "NOWAIT", "PAGLOCK", "READCOMMITTED", "READCOMMITTEDLOCK",
    "READPAST", "READUNCOMMITTED", "REPEATABLEREAD", "ROWLOCK",
    "SERIALIZABLE", "SNAPSHOT", "SPATIAL_WINDOW_MAX_CELLS",
    "TABLOCK", "TABLOCKX", "UPDLOCK", "XLOCK"
};


#ifndef YYtypeDEF_YY_SCANNER_T
#define YYtypeDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif



#endif