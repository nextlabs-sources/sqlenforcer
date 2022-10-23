//
// Created by jeff on 2020/4/7.
//

#ifndef EMDB_TEST_MASK_H
#define EMDB_TEST_MASK_H
#include "./third_party/microtest.h"
#include "commfun.h"
#include "config.h"
#include "nanodbc.h"
#include "Interface.h"

#include "userattr.h"
#include "userattr_export.h"
#include "SqlException.h"
#include "sqlenforcer_export.h"
#include <sqlext.h>
#include "EMMaskDef.h"

#include "parser.h"

MaskConditionMap   *map_mask = NULL;

void TStmtVisit(IPlan*, IStmt*){}
void BaseTableColumnVisit_(IPlan*, IColumnsRefItem*) {}
void StartNewStmt_(IPlan*, uint64_t last_stmt) {}
void WhereClauseVisit_(IPlan* plan, IWhereCluase* wc) {
    if(wc && plan){
        wc->AddCondition("1 > 0");
        wc->AddMaskCondition(map_mask) ;
    }


}
void ErrorOccur_(IPlan*) {}



/*
TEST(parser){

    if(NULL == map_mask)
        map_mask = new MaskConditionMap;
    do{
        MaskItemMap * map = new MaskItemMap;
        {
            MaskItem * pitem = new MaskItem;
            pitem->_symbols = "\\'***";
            pitem->_format = "xx[ms]xxx";
            pitem->_condition = "a.num>=123";
            pitem->_qulify = "a.";
            pitem->_cond_fields.insert("level");
            map->insert(std::make_pair("departmenT", pitem));
        }
//        {
//            MaskItem * pitem = new MaskItem;
//            pitem->_symbols = "***";
//            pitem->_format = "[ms]";
//            pitem->_condition = "a.num<123";
//            pitem->_qulify = "a.";
//            pitem->_cond_fields.insert("num");
//            map->insert(std::make_pair("c_mktsegment", pitem));
//        }
        map_mask->insert(std::make_pair("customer_mask", map));
    } while(0);
    auto it = map_mask->find("customer_masK");
    if(it == map_mask->end())
    {
        MaskItemMap * map = new MaskItemMap;
        {
            MaskItem * pitem = new MaskItem;
            pitem->_symbols = "\\'***";
            pitem->_format = "xx[ms]xxx";
            pitem->_condition = "level > 0";
            pitem->_qulify = "tb.";
            pitem->_cond_fields.insert("level");
            map->insert(std::make_pair("department", pitem));
        }
        {
            MaskItem * pitem = new MaskItem;
            pitem->_symbols = "***";
            pitem->_format = "[ms]";
            pitem->_condition = "a.num<123";
            pitem->_qulify = "a.";
            pitem->_cond_fields.insert("num");
            map->insert(std::make_pair("c_mktsegment", pitem));
        }
        map_mask->insert(std::make_pair("customer_masK", map));
    }

    std::vector<std::string> vec;

    vec.push_back("SELECT * from sa.customer as tb group by (department, bb, cc)");
    vec.push_back("SELECT a.customer_id A_cus_id,  a.c_mktsegment, a.department  FROM EMDB_1_2.customer_mask a  GROUP BY a.customer_id, a.c_mktsegment");
    for(auto it : vec){
        printf("ori:%s\n", it.c_str());
        IParseResult* pPasrset = ParseSql(it, DBMS_SQL2003);
        ASSERT_NOTNULL(pPasrset);

        void *context = (void*)100;
        IPlan* pPlan = CreatePlan(stmtVisit_,
                           BaseTableColumnVisit_,
                           StartNewStmt_,
                           WhereClauseVisit_,
                           ErrorOccur_,
                           context,
                           pPasrset);

        ASSERT_NOTNULL(pPlan);
        VisitPlan(pPlan);

        INode * pnode = pPasrset->GetParseTree();
        std::string strOutSql = pnode->Serialize();
        printf("new:%s\n", strOutSql.c_str());
        do{
            for(auto it: *map_mask){
                for(auto itsub: *(it.second)){
                    delete(itsub.second);
                }
                it.second->clear();
                delete(it.second);
            }
            map_mask->clear();
        } while(0);

        DestroyPlan(pPlan);
        DestroyParseResult(pPasrset);
    }
}*/

#include "emdb_sdk.h"

#define EMDBReturnCHECK(name) \
    if(name!=EMDB_SUCCESS) return;\

TEST(MASK_2)
//void test()
{
    EMDBReturn RT =  EMDBInit("jdbc");

    EMDBUserCtxHandle hd;
    RT = EMDBNewUserCtx("Google", "jdbc-enforcer", "","BigQuery", &hd);
    EMDBReturnCHECK(RT)


    RT = EMDBSetUserCtxProperty(hd, "name", "Joy Wu");
    EMDBReturnCHECK(RT)
    RT = EMDBSetUserCtxProperty(hd, "department", "QA");
    RT = EMDBSetUserCtxProperty(hd, "level", "3");
    RT = EMDBSetUserCtxProperty(hd, "checked", "true");
    RT = EMDBSetUserCtxProperty(hd, "age", "24");
    RT = EMDBSetUserCtxProperty(hd, "city", "");
    RT = EMDBSetUserCtxProperty(hd, "countrycode", "18");
    RT = EMDBSetUserCtxProperty(hd, "salary", "1200.0");

    std::vector<std::string> vec;
    //vec.push_back("DELETE FROM EMDB_1_2.customer");
    //vec.push_back("update EMDB_1_2.customer set c_mktsegment = 'retail' where c_mktsegment\n"
     //            "is null and customer_id not between 2 and 14");
    vec.push_back("SELECT * FROM EMDB_1_2.customer_mask, EMDB_1_2.customer_mask2");
    //vec.push_back("SELECT A.c_mktsegment, A.c_custkey, A.c_privilege_level FROM jdbc-enforcer.`EMDB_1_2.customer` AS A");
    //vec.push_back("SELECT `A`.salary, `A`.customer_id,  `A`.c_mktsegment, `A`.c_privilege_level FROM jdbc-enforcer.`EMDB_1_2.customer_mask` AS `A`, `EMDB_1_2.customer` AS `B`");
    //vec.push_back("insert into EMDB_1_2.customer_insert (customer_id, c_custkey, c_mktsegment, c_privilege_level) select customer_id, c_custkey, c_mktsegment, c_privilege_level from EMDB_1_2.customer_default where customer_id=1");
    //vec.push_back("INSERT INTO EMDB_1_2.customer_insert (customer_id, c_custkey, c_mktsegment, c_privilege_level) values('123')");

    // vec.push_back("SELECT a.customer_id,a.c_custkey, a.c_privilege_level FROM EMDB_1_2.customer a");
    //vec.push_back("SELECT customer_id, c_privilege_level FROM `jdbc-enforcer.EMDB_1_2`.customer");
   //vec.push_back("SELECT customer_id, c_privilege_level FROM jdbc-enforcer2.EMDB_1_2.customer");
//
//    vec.push_back("SELECT A.customer_id, A.c_privilege_level FROM `jdbc-enforcer.EMDB_1_2.customer` AS A");
//    vec.push_back("SELECT A.customer_id, A.c_privilege_level FROM jdbc-enforcer.`EMDB_1_2.customer` AS A");
//    vec.push_back("SELECT A.customer_id, A.c_privilege_level FROM `jdbc-enforcer.EMDB_1_2`.customer AS A");
//    vec.push_back("SELECT A.customer_id, A.c_privilege_level FROM jdbc-enforcer.EMDB_1_2.customer AS A");
//    vec.push_back("DELETE FROM EMDB_1_2.customer_delete");
//    vec.push_back("SELECT customer_id,c_mktsegment, sum(c_privilege_level) FROM\n"
//    "`jdbc-enforcer.EMDB_1_2.customer` group by 1,c_mktsegment");
//    vec.push_back("select customer.c_mktsegment from EMDB_1_2.customer where customer_id in (1, 8)");
//    vec.push_back("update EMDB_1_2.customer_update set c_mktsegment = 'retail' where c_mktsegment\n"
//                  "is null and customer_id not between 2 and 14");
    //vec.push_back("with a as(select customer_id,c_mktsegment from EMDB_1_2.customer) select * from a where a.customer_id<100;");

    for(auto sql:vec){

        //std::string sql = vec[0];
       // std::string sql = "SELECT customer_id, c_privilege_level FROM `jdbc-enforcer.EMDB_1_2.customer`";
        printf("ori:%s\n", sql.c_str());

        EMDBResultHandle result;
        RT = EMDBNewResult(&result);
        EMDBReturnCHECK(RT)

        RT = EMDBEvalSql(sql.c_str(), hd,  result);
        EMDBReturnCHECK(RT)


        EMDBResultCode code;
        RT = EMDBResultGetCode( result, &code);
        EMDBReturnCHECK(RT)

        const char * output = NULL;
        RT = EMDBResultGetDetail( result, &output);
        EMDBReturnCHECK(RT)

        std::string newsql;
        if(code == EMDB_USE_NEW_TEXT){
            newsql = output;
        }
        printf("new:%s\n", newsql.c_str());

        RT = EMDBFreeResult(result);

        sleep(20);
    }
    RT = EMDBClearUserCtxProperty(hd);
    RT = EMDBFreeUserCtx(hd);

}

#include "QueryCAZPolicyOpr.h"
#include <set>
TEST(condition){
//    {
//        const std::string str = "not(integer_c-!=1a)";
//        printf("input: %s\n",str.c_str());
//        const std::string test = "A";
//        ConditionInfo info(test,test,test,EMDB_DB_UNKNOW,NULL,NULL);
//        std::set<std::string> fields;
//        std::string ret = parser_condition(str, info, fields);
//        printf("output: %s\n",ret.c_str());
//    }
//    {
//        const std::string str = "is not null(123integer_c!=1)";
//        printf("input: %s\n",str.c_str());
//        const std::string test = "A";
//        ConditionInfo info(test,test,test,EMDB_DB_UNKNOW,NULL,NULL);
//        std::set<std::string> fields;
//        std::string ret = parser_condition(str, info, fields);
//        printf("output: %s\n",ret.c_str());
//    }
//    {
//        const std::string str = "is not null(#123integer_c!=1)";
//        printf("input: %s\n",str.c_str());
//        const std::string test = "A";
//        ConditionInfo info(test,test,test,EMDB_DB_UNKNOW,NULL,NULL);
//        std::set<std::string> fields;
//        std::string ret = parser_condition(str, info, fields);
//        printf("output: %s\n",ret.c_str());
//    }
//    {
//        const std::string str = "is not null(integer_c!='1''";
//        printf("input: %s\n",str.c_str());
//        const std::string test = "A";
//        ConditionInfo info(test,test,test,EMDB_DB_UNKNOW,NULL,NULL);
//        std::set<std::string> fields;
//        std::string ret = parser_condition(str, info, fields);
//        printf("output: %s\n",ret.c_str());
//    }
//    {
//        const std::string str = "AND OR IS NOT NULL ";
//        printf("input: %s\n",str.c_str());
//        const std::string test = "A";
//        ConditionInfo info(test,test,test,EMDB_DB_BIGQUERY,NULL,NULL);
//        std::set<std::string> fields;
//        std::string ret = parser_condition(str, info, fields);
//        printf("output: %s\n",ret.c_str());
//    }
}

#endif //EMDB_TEST_MASK_H
