//
// Created by jeff on 2020/11/11.
//

#include "parser.h"
#include "sqlparser_hana_bison.h"
#include "sqlparser_hana_flex.h"
#include "serialize_format.h"


bool parser::parse_sqlhana(const std::string& sql, ParseResult* result) {
    yyscan_t scanner;
    YY_BUFFER_STATE state;

    if (hana_lex_init_extra(result, &scanner)) {
        //fprintf(stderr, "SQLParser2003: Error when initializing lexer!\n");
        return false;
    }

    const char* text = sql.c_str();
    state = hana__scan_string(text, scanner);

    // Parse the tokens.
    // If parsing fails, the result will contain an error object.
    hana_parse(result, scanner);
    hana__delete_buffer(state, scanner);
    hana_lex_destroy(scanner);

    return result->accept;
}



bool parser::compress_sqlhana(const std::string& src, std::string& out) {
    ParseResult r;
    if (!parse_sqlhana(src, &r))
        return false;
    if (!r.result_tree_)
        return true;

    out = r.result_tree_->serialize();
    return true;
}

bool parser::beautify_sqlhana(const std::string& src, std::string& out) {
    ParseResult r;
    if (!parse_sqlhana(src, &r))
        return false;
    if (!r.result_tree_)
        return true;
    _Buf b;
    _beautify_sql(&b, r.result_tree_);
    out = b.get_str();
    return true;
}