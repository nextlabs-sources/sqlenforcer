#include "gtest/gtest.h"
#include "enforcerwrapper.h"
#include "DAESqlServerSDK.h"
#include "PolicyExport.h"
#include <thread>

using namespace DAESqlServer;
using namespace std;

class SqlEnforcerTest : public ::testing::Test {
 public:
  SqlEnforcerTest()
    : result_handle_(nullptr),
      user_property_(new DAE_UserProperty[7]) {
    user_property_[0]._key = "uid";
    user_property_[0]._value = "test";
    user_property_[1]._key = "SERVICE_NAME";
    user_property_[1]._value = "Autotest";
    user_property_[2]._key = "cn";
    user_property_[2]._value = "Administrator";
    user_property_[3]._key = "APP_NAME";
    user_property_[3]._value = "client_app_name";
    user_property_[4]._key = "COMPUTER_NAME";
    user_property_[4]._value = "client_computer_name";
    user_property_[5]._key = "USER_IP";
    user_property_[5]._value = "10.22.12.4";
    user_property_[6]._key = "OWNER";
    user_property_[6]._value = "GUEST";

    DAEEnforcerMgr::Instance()->DAESqlServerInit("ProxyWorker_1");
    DAEEnforcerMgr::Instance()->DAENewResult(&result_handle_);
  }

  ~SqlEnforcerTest() {
    DAEEnforcerMgr::Instance()->DAEFreeResult(result_handle_);

    delete[] user_property_;
  }

  struct Result {
    DAESqlServer::DAE_ResultCode code_{ DAESqlServer::DAE_ResultCode::DAE_IGNORE };
    std::string detail_;
    std::string database_;
  };

  Result Enforce(const std::string& sql) const {
    Result result;
    const char* sqlnew = NULL;
    const char* db = NULL;

    DAEEnforcerMgr::Instance()->EnforceSQL_simpleV2(sql.c_str(), user_property_, 7, nullptr, 0, result_handle_);
    DAEEnforcerMgr::Instance()->DAEGetResult(result_handle_, &result.code_, &sqlnew, &db);

    result.detail_ = sqlnew;
    result.database_ = db;

    return result;
  }

  DAEResultHandle result_handle_;
  DAE_UserProperty* user_property_;
};

TEST(SimpleSqlEnforcerTest, DAESqlServerInit) {
  const auto init_result = DAEEnforcerMgr::Instance()->DAESqlServerInit("ProxyWorker_1");
  EXPECT_EQ(init_result, true);
}

TEST_F(SqlEnforcerTest, MaskSelectStatementTest) {
  const auto expect_code = DAESqlServer::DAE_ResultCode::DAE_ENFORCED;
  const auto expect_sql = "SELECT * FROM sa.CUSTOMER_MASK --NXLDAE";

  auto sql = "insert into sa.CUSTOMER_INSERT select * from sa.CUSTOMER_COPY where c_privilege_level = 2;";
  auto result = Enforce(sql);

//  EXPECT_EQ(result.code_, expect_code);
//  EXPECT_EQ(result.detail_, "SELECT TOP 200  CASE WHEN sa.customer_mask.C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE sa.customer_mask.c_mktsegment END  AS c_mktsegment  FROM sa.customer_mask WHERE ((sa.customer_mask.c_privilege_level >= 0 OR sa.customer_mask.c_privilege_level IS null) AND (sa.customer_mask.c_privilege_level < 10 OR sa.customer_mask.c_privilege_level IS null))  --NXLDAE");
//
  sql = "SELECT TOP 200 c_mktsegment FROM sa.customer_mask";
  result = Enforce(sql);

  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, "SELECT TOP 200  CASE WHEN sa.customer_mask.C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE c_mktsegment END  AS c_mktsegment  FROM sa.customer_mask WHERE ((sa.customer_mask.c_privilege_level >= 0 OR sa.customer_mask.c_privilege_level IS null) AND (sa.customer_mask.c_privilege_level < 10 OR sa.customer_mask.c_privilege_level IS null))  --NXLDAE");

  sql = "SELECT C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL) FROM sa.customer_mask GROUP BY\n"
        "sa.customer_mask.C_MKTSEGMENT,sa.customer_mask.C_PRIVILEGE_LEVEL order by\n"
        "C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL)";
  result = Enforce(sql);
  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, "SELECT  CASE WHEN sa.customer_mask.C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE C_MKTSEGMENT END  AS C_MKTSEGMENT , SUM(C_PRIVILEGE_LEVEL) FROM sa.customer_mask WHERE ((sa.customer_mask.c_privilege_level >= 0 OR sa.customer_mask.c_privilege_level IS null) AND (sa.customer_mask.c_privilege_level < 10 OR sa.customer_mask.c_privilege_level IS null)) GROUP BY sa.customer_mask.C_MKTSEGMENT, sa.customer_mask.C_PRIVILEGE_LEVEL  ORDER BY C_MKTSEGMENT , SUM(C_PRIVILEGE_LEVEL)  --NXLDAE");
//
  sql = "SELECT C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL) FROM sa.customer_mask GROUP BY\n"
        "sa.CUSTOMER_MASK.C_MKTSEGMENT,sa.CUSTOMER_MASK.C_PRIVILEGE_LEVEL order by\n"
        "C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL)";
  result = Enforce(sql);
  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, "SELECT  CASE WHEN sa.customer_mask.C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE C_MKTSEGMENT END  AS C_MKTSEGMENT , SUM(C_PRIVILEGE_LEVEL) FROM sa.customer_mask WHERE ((sa.customer_mask.c_privilege_level >= 0 OR sa.customer_mask.c_privilege_level IS null) AND (sa.customer_mask.c_privilege_level < 10 OR sa.customer_mask.c_privilege_level IS null)) GROUP BY sa.CUSTOMER_MASK.C_MKTSEGMENT, sa.CUSTOMER_MASK.C_PRIVILEGE_LEVEL  ORDER BY C_MKTSEGMENT , SUM(C_PRIVILEGE_LEVEL)  --NXLDAE");

  sql = "SELECT C_MKTSegMENT, SUM(C_PRIVILegE_LEVEL) FROM sa.custoMEr_mask GROUP BY\n"
        "sa.CUSTOMer_MASK.C_MKTSEGMenT,sa.CUSTOMER_maSK.C_PRivILEGE_LEVEL order by\n"
        "C_mkTSEGMENT, SUM(C_prIVILEGE_LEVEL)";
  result = Enforce(sql);
  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, "SELECT  CASE WHEN sa.custoMEr_mask.C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE C_MKTSegMENT END  AS C_MKTSegMENT , SUM(C_PRIVILegE_LEVEL) FROM sa.custoMEr_mask WHERE ((sa.custoMEr_mask.c_privilege_level >= 0 OR sa.custoMEr_mask.c_privilege_level IS null) AND (sa.custoMEr_mask.c_privilege_level < 10 OR sa.custoMEr_mask.c_privilege_level IS null)) GROUP BY sa.CUSTOMer_MASK.C_MKTSEGMenT, sa.CUSTOMER_maSK.C_PRivILEGE_LEVEL  ORDER BY C_mkTSEGMENT , SUM(C_prIVILEGE_LEVEL)  --NXLDAE");

//
//  sql = "SELECT C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL) FROM sa.customer_mask GROUP BY\n"
//        "C_MKTSEGMENT,C_PRIVILEGE_LEVEL order by C_MKTSEGMENT, SUM(C_PRIVILEGE_LEVEL)";
//  Enforce(sql);
}

TEST_F(SqlEnforcerTest, ExecuteStatementTest) {
  const auto expect_code = DAESqlServer::DAE_ResultCode::DAE_ENFORCED;
  const auto expect_sql = "SELECT [$Table].[customer_id] AS [customer_id], [$Table].[c_custkey] AS [c_custkey],  CASE WHEN [$Table].C_PRIVILEGE_LEVEL = 1 THEN '**test#@/' ELSE [$Table].[c_mktsegment] END  AS [c_mktsegment] , [$Table].[c_privilege_level] AS [c_privilege_level] FROM [sa].[CUSTOMER_MASK] AS [$Table] WHERE (([$Table].c_privilege_level >= 0 OR [$Table].c_privilege_level IS null) AND ([$Table].c_privilege_level < 10 OR [$Table].c_privilege_level IS null))  --NXLDAE";

  auto sql = "EXECUTE sp_executesql N'select [$Table].[customer_id] as [customer_id],\n"
                        "    [$Table].[c_custkey] as [c_custkey],\n"
                        "    [$Table].[c_mktsegment] as [c_mktsegment],\n"
                        "    [$Table].[c_privilege_level] as [c_privilege_level]\n"
                        "from [sa].[CUSTOMER_MASK] as [$Table]'";
  auto result = Enforce(sql);


  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, expect_sql);

  sql = "execute sp_executesql N'select [$Table].[customer_id] as [customer_id],\n"
        "\n"
        "    [$Table].[c_custkey] as [c_custkey],\n"
        "\n"
        "    [$Table].[c_mktsegment] as [c_mktsegment],\n"
        "\n"
        "    [$Table].[c_privilege_level] as [c_privilege_level]\n"
        "\n"
        "from [sa].[CUSTOMER_MASK] as [$Table]'";
//
//  sql = "sp_executesql N'select [$Table].[customer_id] as [customer_id],\n"
//         "    [$Table].[c_custkey] as [c_custkey],\n"
//         "    [$Table].[c_mktsegment] as [c_mktsegment],\n"
//         "    [$Table].[c_privilege_level] as [c_privilege_level]\n"
//         "from [sa].[CUSTOMER_MASK] as [$Table]';";
  result = Enforce(sql);

  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, expect_sql);
}

TEST_F(SqlEnforcerTest, SelectStatementTest) {
  const auto expect_code = DAESqlServer::DAE_ResultCode::DAE_IGNORE;
  const auto expect_sql = "";

  auto sql = "update sa.customer_maskttt set C_MKTSEGMENT = 'test' where customer_id < @P0 and 'DAE_APP_USER' <> @P1; select SCOPE_IDENTITY() AS GENERATED_KEYS";
  auto result = Enforce(sql);


  EXPECT_EQ(result.code_, expect_code);
  EXPECT_EQ(result.detail_, expect_sql);
}