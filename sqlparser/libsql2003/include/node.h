#ifndef NODE_H
#define NODE_H

#include <vector>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include "keydef.h"
#include <functional>
#include <set>
#include <sstream>
#include "Interface.h"
#include "EMDBType.h"

#define NODE_CHILDREN_DEBUG

std::string NodeTypeToString(NodeType tp);
extern int g_QuestMarkId;
class Node;
class ParseResult : public IParseResult {
public:
    ParseResult();
    virtual ~ParseResult();
    Node* result_tree_;
    bool accept;
    int errFirstLine;
    int errFirstColumn;
    std::string errDetail;
    std::stringstream buf_;
    char q_ = 0;
    EMDB_DB_TYPE type_;
    int _queest_markid = 0;
    int old_state_ = 0;

    // implement of IParseResult
    virtual bool IsAccept() const override;
    virtual INode* GetParseTree() override;
    virtual size_t GetErrorLine() const override;
    virtual size_t GetErrorColumn() const override;
    virtual std::string GetErrorDetail() const override;
    virtual IWhereCluase * CreateSimpleSelectWhereClause() const  override;
    virtual void ReleaseWhereClause(IWhereCluase * pw) const override ;
};

struct TerminalToken {
    //  after convert
    int i=0;
    double d=double(0);
    std::string str;

    // before convert
    std::string yytex;
    // for E_IDENTIFIER
    int line{0};
    int column{0};
};

struct _FmCB;

class Node : public INode {
public:
    static Node* makeTerminalNode(NodeType tp, const std::string&);
    static Node* makeNonTerminalNode(NodeType tp, int num, ...);

    static bool IsList(Node*);

    /*
     * we provide recursive and non_recursive interface
     * */
    static int ListLength(Node*);
    static int ListLengthNonRecursive(Node*);

    static void ToList(Node*, std::list<Node*>&);
    static void ToListNonRecursive(Node*, std::list<Node*>&);

    /*
     * compact format
     * */
    static std::string SerializeNonRecursive(Node* root);
    std::string serialize();
    void serialize(std::stringstream& buf);

    static Node* remove_parens(Node* node);
    static bool is_with_parens(Node* node);

    static void print(Node*, size_t i = 0);


    Node();
    virtual void operator=(const Node & node);
    virtual ~Node();
    Node* getParent();
    Node* setParent(Node*);
    Node* getChild(int key);
    Node** getChildRef(int key);
    bool setChild(int key, Node*);
    size_t getChildrenCount() const;
    std::string text();
    void set_text(const std::string& new_text);
    void swap(Node* src);

    NodeType nodeType_;
    bool isTerminalToken;
    TerminalToken terminalToken_;
    const _FmCB *serialize_format;
    int questmarkid_;

private:
#ifdef NODE_CHILDREN_DEBUG
    std::vector<Node*> children_;
#else
    Node** children_;
#endif
    size_t childrenCount_;
    Node* parent_;
private:
    static int GetKey(const std::string&);
    static bool Divide(const std::string&, std::vector<std::string>&);  // "abc{12}XYZ"

private:
    static Node* addjust_cross_join(Node* root, Node* cj);
private:
    static Node* check_expr_is_column_alias(Node* root);  // transact sql support column_alias=expr
    static bool  check_expr_table_hint(Node* root);       // transact sql support table hint
    static std::string convert_join_hint(int ival);       // transact sql support join hint
    static Node* make_query_hint(const std::string&);     // transact sql support query hint
    static Node* make_query_hint(const std::string&, Node*);
    static bool check_update_item(Node*, Node*&);
    friend int yyparse (ParseResult* result, yyscan_t scanner);
    static Node* NAME_CHAIN_TO_TABLE_IDENT(Node*);
    static Node* NAME_CHAIN_STAR_TO_NAME_FIELD(Node*);
    static Node* NAME_CHAIN_TO_NAME_FIELD(Node*);

    static bool CHECK_FUNCTION_CALL_WITH_STAR(Node*);


public:
    static NodeType comp_all_some_any_op_form(NodeType op, int all_some_any);
    static const _FmCB *op_serialize_format(NodeType tp);
    static char *strupr(char *str);

public:
    // implement INode
    virtual NodeType GetType();
    virtual INode* GetParent();
    virtual bool SetParent(INode* node);
    virtual INode* GetChild(int key);
    virtual bool SetChild(int key, INode* node);
    virtual size_t GetChildrenCount() const;
    virtual std::string Text();
    virtual bool IsTerminal() const;
    virtual std::string Serialize();
    virtual void Print();
};


void parser_bigquery_tbname(Node* pnode, std::string & db, std::string & schema, std::string & tb); // node need is e_ident
void parser_bigquery_field(Node* pnode, std::string & db, std::string & schema, std::string & tb, std::string & field);
void parser_db_field(Node* pnode, std::string & db, std::string & schema, std::string & tb, std::string & field);

// for copy
/*
{
switch (nodeType_)
{
case E_NULL:
case E_INT:
case E_DOUBLE:
case E_BOOL:
case E_STRING:
case E_IDENTIFIER:
case E_QUESTIONMARK:
case E_ALL:
case E_DISTINCT:
case E_STAR:
case E_TYPE_INTEGER:
case E_TYPE_BOOLEAN:
case E_TYPE_DOUBLE:
case E_TYPE_DATETIME:
case E_SET_UNION:
case E_SET_INTERSECT:
case E_SET_EXCEPT:
case E_SORT_ASC:
case E_SORT_DESC:
case E_JOIN_INNER:
case E_JOIN_FULL:
case E_JOIN_LEFT:
case E_JOIN_RIGHT:
case E_JOIN_CROSS:
case E_JOIN_NATURAL:
case E_STMT_LIST:
return nullptr;
case E_SELECT:
{
return proc(this);
}
case E_SELECT_WITH_PARENS:
case E_FROM_CLAUSE:
case E_WHERE_CLAUSE:
case E_LIMIT_CLAUSE:
case E_GROUP_BY:
case E_ORDER_BY:
case E_HAVING:
case E_WHEN:
case E_SORT_LIST:
case E_SORT_KEY:
case E_SELECT_EXPR_LIST:
case E_PROJECT_STRING:
case E_ALIAS:
case E_FROM_LIST:
case E_JOINED_TABLE:
case E_JOINED_TABLE_WITH_PARENS:
case E_OP_NAME_FIELD:
case E_OP_EXISTS:
case E_OP_POS:
case E_OP_NEG:
case E_OP_ADD:
case E_OP_MINUS:
case E_OP_MUL:
case E_OP_DIV:
case E_OP_REM:
case E_OP_POW:
case E_OP_MOD:
case E_OP_LE:
case E_OP_LT:
case E_OP_EQ:
case E_OP_GE:
case E_OP_GT:
case E_OP_NE:
case E_OP_LIKE:
case E_OP_NOT_LIKE:
case E_OP_AND:
case E_OP_OR:
case E_OP_NOT:
case E_OP_IS:
case E_OP_IS_NOT:
case E_OP_BTW:
case E_OP_NOT_BTW:
case E_OP_IN:
case E_OP_NOT_IN:
case E_OP_CNN:
case E_EXPR_LIST:
case E_EXPR_LIST_WITH_PARENS:
case E_CASE:
case E_CASE_DEFAULT:
case E_FUN_CALL:
case E_WHEN_LIST:
case E_TOP_CNT:
case E_TOP_PCT:
case E_TOP_CNT_TIES:
case E_TOP_PCT_TIES:
case E_SIMPLE_IDENT_LIST:
case E_SIMPLE_IDENT_LIST_WITH_PARENS:
case E_OPT_DERIVED_COLUMN_LIST:
case E_COMMON_TABLE_EXPR:
case E_WITH_LIST:
case E_OPT_WITH_CLAUSE:
default:
return nullptr;
}
}*/




#endif