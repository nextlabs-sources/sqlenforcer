#include "parser.h"
#include "sqlparser_bigquery_bison.h"
#include "sqlparser_bigquery_flex.h"
//#include "sqlparser_tsql_bison.h"
//#include "sqlparser_tsql_flex.h"

#include "serialize_format.h"


bool parser::parse_sqlbigquery(const std::string& sql, ParseResult* result) {
    yyscan_t scanner;
    YY_BUFFER_STATE state;

    if (bigquery_lex_init_extra(result, &scanner)) {
        //fprintf(stderr, "SQLParser2003: Error when initializing lexer!\n");
        return false;
    }

    const char* text = sql.c_str();
    state = bigquery__scan_string(text, scanner);

    // Parse the tokens.
    // If parsing fails, the result will contain an error object.
    bigquery_parse(result, scanner);
    bigquery__delete_buffer(state, scanner);
    bigquery_lex_destroy(scanner);

    return result->accept;
}



bool parser::compress_sqlbigquery(const std::string& src, std::string& out) {
    ParseResult r;
    if (!parse_sqlbigquery(src, &r))
        return false;
    if (!r.result_tree_)
        return true;

    out = r.result_tree_->serialize();
    return true;
}

bool parser::beautify_sqlbigquery(const std::string& src, std::string& out) {
    ParseResult r;
    if (!parse_sqlbigquery(src, &r))
        return false;
    if (!r.result_tree_)
        return true;
    _Buf b;
    _beautify_sql(&b, r.result_tree_);
    out = b.get_str();
    return true;
}