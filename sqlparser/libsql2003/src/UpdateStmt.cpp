#include "UpdateStmt.h"
#include "ResultPlan.h"
#include "LogicPlan.h"
#include "TableRef.h"
#include "LocalTableMgr.h"
#include <assert.h>
#include "where_clause.h"
#include "commfun.h"

namespace resolve {
    UpdateStmt::~UpdateStmt() {
        delete(update_table_);
        update_table_ = nullptr;
        for (auto it : update_items_){
            delete(it);
        }

        update_items_.clear();
        delete(_where_clause);
    }

    bool UpdateStmt::set_update_table(
            ResultPlan* plan,
            NodeType type,
            const std::string& schema_name,
            const std::string& table_name,
            TableRef*& out_table_ref) {

        uint64_t out_query_id = OB_INVALID_ID;
        size_t out_index = 0;
        bool fd = false;

 //       uint64_t local_table_id = OB_INVALID_ID;

        for (TableRef* tbi : table_items_) {
            if (tbi->check_is_ref(schema_name, table_name)) {
//                if (tbi->get_table_ref_type() == TableRef::BASE_TABLE_DIRECT_REF) {
//                    local_table_id = dynamic_cast<BaseTableRef*>(tbi)->GetTableID();
//                }
                update_table_ = tbi->clone();
                fd = true;
                break;
            }
        }

        if (!fd) {
            for (TableRef* tbi : table_items_) {
                if (tbi->get_table_ref_type() == TableRef::BASE_TABLE_ALIAS_REF) {
                    BaseTableAliasRef* t = dynamic_cast<BaseTableAliasRef*>(tbi);
                    if (CommonFun::CaseInsensitiveEquals(t->GetTableName(), table_name) &&
                        CommonFun::CaseInsensitiveEquals(t->GetSchemaName(), schema_name)) {
                        //local_table_id = t->GetTableID();
                        update_table_ = tbi->clone();
                        fd = true;
                        break;
                    }
                }
            }
        }

        if (schema_name.length() > 0) {

        }
        else {
            if (!fd) {
                fd = check_in_cte(table_name, out_query_id, out_index);
                // if from list contains this cte and specific alias, error
                // todo
            }
        }

//        if (local_table_id != OB_INVALID_ID) {
//            size_t cnt1 = 0, cnt2 = 0;
//            for (TableRef* tbi : table_items_) {
//                if (tbi->get_table_ref_type() == TableRef::BASE_TABLE_DIRECT_REF &&
//                    local_table_id == dynamic_cast<BaseTableRef*>(tbi)->GetTableID() )
//                    ++cnt1;
//                else if (tbi->get_table_ref_type() == TableRef::BASE_TABLE_ALIAS_REF&&
//                    local_table_id == dynamic_cast<BaseTableAliasRef*>(tbi)->GetTableID()) {
//                    ++cnt1;
//                    ++cnt2;
//                }
//            }
//            /*
//             * https://docs.microsoft.com/zh-cn/sql/t-sql/queries/update-transact-sql?view=sql-server-2017#TargetObjects
//             * If the object being updated is the same as the object in the FROM clause and there is only one reference
//             * to the object in the FROM clause, an object alias may or may not be specified. If the object being updated
//             * appears more than one time in the FROM clause, one, and only one, reference to the object must not specify
//             * a table alias. All other references to the object in the FROM clause must include an object alias
//             * */
//            assert(cnt1 >= 1);
//            if (cnt1 > 1)
//                assert(cnt1 - cnt2 == 1);
//            /*
//             * here we can confirm which basic table is update,
//             * however in some case, the really updateable basic is confirmed until the set list
//             * */
//            //update_table_ = local_table_id;
//        }

        if (!fd) {
            std::string schema_name1 = schema_name.length() > 0 ? schema_name : plan->local_table_mgr->get_default_schema();
            BaseTableRef* tb = type == NodeType::E_ALIAS ? new BaseTableAliasRef : new BaseTableRef;
            tb->query_id_ = this->query_id_;
            tb->base_table_id_ = plan->local_table_mgr->get_local_table_id(schema_name1+"."+table_name);
            tb->table_id_ = tb->base_table_id_;
            tb->table_name_ = table_name;
            tb->schema_name_ = schema_name1;

            for (TableRef* it : table_items_) {
                if (CommonFun::CaseInsensitiveEquals(tb->get_table_name(), it->get_table_name())) {
                    /* ambiguous table name at from clause error */
                    assert(false);
                }
            }
            update_table_ = tb;
            out_table_ref = tb;
        }

        return true;
    }

    bool UpdateStmt::IsBasicTableOrAlias() {
        if (update_table_ == nullptr)
            return false;
        else {
            auto tp = update_table_->get_table_ref_type();
            return tp == TableRef::BASE_TABLE_DIRECT_REF ||
                    tp == TableRef::BASE_TABLE_ALIAS_REF;
        }
    }

    ITableItem* UpdateStmt::GetUpdateTable() {
        return update_table_;
    }

    const std::vector<IUpdateItem *> &UpdateStmt::get_update_items() {
        return update_items_;
    }

    void UpdateStmt::add_update_item(IUpdateItem *item) {
        update_items_.push_back(item);
    }


}