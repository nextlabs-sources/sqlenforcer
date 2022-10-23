//
// Created by jeff on 2020/12/2.
//


#include "microtest.h"
#include "nanodbc.h"
#include "nanodbc_nxl.h"

//TEST(ORI_TEST)
void test1()
{
   // ORIGINAL::nanodbc::string cnn_str_ = NANODBC_TEXT("Driver=Oracle 19 ODBC driver;Uid=guest;Pwd=123blue!;dbq=10.23.57.181:1521/orcl;");
  // ORIGINAL::nanodbc::string cnn_str_  = NANODBC_TEXT("Driver=Oracle 19 ODBC driver;Uid=GUEST;Pwd=123blue!;dbq=10.23.57.7:1522/ORCLCDB;");
   ORIGINAL::nanodbc::string cnn_str_  = NANODBC_TEXT("Driver=ODBC Driver 17 for SQL Server;Server=10.23.57.46,1433;Uid=sa;PWD=123blue!;Database=autotest");
  //  ORIGINAL::nanodbc::string cnn_str_ = NANODBC_TEXT("Driver={Oracle 19 ODBC driver};Uid=SYSTEM;Pwd=123456;dbq=10.23.57.7:1522/ORCLCDB;");
//   ORIGINAL::nanodbc::string cnn_str_  = NANODBC_TEXT("Driver=Simba ODBC Driver for Google BigQuery 64-bit;OAuthMechanism = 1;"
//                                                      "RefreshToken=1//0gjCRgy--nifiCgYIARAAGBASNwF-L9Ir52m0QREgjWcSX9XMCBr7jluzFsyXDGch76LpQd0YAJZcIqrY9xQxdDPn4Is6qm3W94g;"//
//                                                      "Catalog=jdbc-enforcer;");
   ORIGINAL::nanodbc::connection *cnn_ = NULL;
    try {
        cnn_ = new ORIGINAL::nanodbc::connection(cnn_str_);
    }
    catch (ORIGINAL::nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        return ;
    }
    if (!cnn_->connected()) {
        mt::printFailed("prepare: connect error");
        return ;
    }

//    ORIGINAL::nanodbc::statement  *stmt_ = NULL;
//    try {
//        stmt_ = new ORIGINAL::nanodbc::statement(*cnn_);
//    }
//    catch (ORIGINAL::nanodbc::database_error const& e) {
//        mt::printFailed(e.what());
//        return ;
//    }
//
//    if (!stmt_->connected()) {
//        mt::printFailed("prepare: statement error");
//        return ;
//    }


    ORIGINAL::nanodbc::string sql_ = NANODBC_TEXT("update autotest.sa.CUSTOMER_MASK  set\n"
                                                  "autotest.sa.CUSTOMER_MASK.c_mktsegment='testing' \n"
                                                  "where 1 = 1 ");
    //m_taskPrepare.strSqlPath;
    try {
        ORIGINAL::nanodbc::statement stmt(*cnn_, sql_);
        ORIGINAL::nanodbc::result results = ORIGINAL::nanodbc::execute(stmt);

 		short columns = results.columns();
 		ORIGINAL::nanodbc::string const null_value = NANODBC_TEXT("null");
 		int lenmax = 20;
        printf("---------------------------------------------result-------------------------------------------------------\n");
 		for (short col = 0; col < columns; ++col) {
            printf("|");
 			ORIGINAL::nanodbc::string colname = results.column_name(col);
 			int ilen = colname.length();
 			if(ilen > lenmax){
 			    colname = colname.substr(0,lenmax);
                printf("%s", colname.c_str());
 			} else {

                printf("%s", colname.c_str());
                for(int i = 0 ; i < lenmax-ilen;++i){
                    printf(" ");
                }

 			}

 		}
        printf("\n");

 		while (results.next()) {
 			for (short col = 0; col < columns; ++col) {
                printf("|");

 				int itype = results.column_datatype(col);
 				ORIGINAL::nanodbc::string value = results.get<ORIGINAL::nanodbc::string>(col, null_value);


                int ilen = value.length();
                if(ilen > lenmax){
                    value = value.substr(0,lenmax);
                    printf("%s", value.c_str());
                } else {

                    printf("%s", value.c_str());
                    for(int i = 0 ; i < lenmax-ilen;++i){
                        printf(" ");
                    }

                }

 			}
            printf("\n");
 		}
        printf("-----------------------------------------------end -----------------------------------------------------\n");
    }
    catch (ORIGINAL::nanodbc::database_error const& e) {
        mt::printFailed(e.what());
        return ;
    }

    return ;
}



#include <unistd.h>
#include <fstream>

bool execute_sql(NXL::nanodbc::connection & conn,  NXL::nanodbc::string & sql){
    try {
        NXL::nanodbc::statement stmt(conn, sql);
        NXL::nanodbc::result results = NXL::nanodbc::execute(stmt);
        short columns = results.columns();
        NXL::nanodbc::string const null_value = NANODBC_TEXT("null");
        int lenmax = 20;
        printf("---------------------------------------------result-------------------------------------------------------\n");
        for (short col = 0; col < columns; ++col) {
            printf("|");
            NXL::nanodbc::string colname = results.column_name(col);
            int ilen = colname.length();
            if(ilen > lenmax){
                colname = colname.substr(0,lenmax);
                printf("%s", colname.c_str());
            } else {

                printf("%s", colname.c_str());
                for(int i = 0 ; i < lenmax-ilen;++i){
                    printf(" ");
                }

            }

        }
        printf("\n");
        if(columns == 0){
            printf("            no result           \n");
        } else {
            while (results.next()) {
                for (short col = 0; col < columns; ++col) {
                    printf("|");

                    int itype = results.column_datatype(col);
                    NXL::nanodbc::string value = results.get<NXL::nanodbc::string>(col, null_value);


                    int ilen = value.length();
                    if(ilen > lenmax){
                        value = value.substr(0,lenmax);
                        printf("%s", value.c_str());
                    } else {

                        printf("%s", value.c_str());
                        for(int i = 0 ; i < lenmax-ilen;++i){
                            printf(" ");
                        }

                    }

                }
                printf("\n");
            }
        }

        printf("-----------------------------------------------end -----------------------------------------------------\n");
    }
    catch (NXL::nanodbc::database_error const& e) {
        printf("\n");
        mt::printFailed(e.what());
        return false;
    }
    return true;
}

TEST(ODBC_CLIENT)
{
    char *buffer;
    if((buffer = getcwd(NULL, 0)) == NULL)
    {
        perror("getcwd error");
        return;
    }

    std::string connstr_path(buffer);
//    unsigned  int pos = connstr_path.rfind('/');
//    std::string path = connstr_path.substr(0, pos+1) + "conn_str.txt";
    std::string path = connstr_path + "/conn_str.txt";
    printf("connection path: %s\n", path.c_str());
    std::ifstream t(path);
    std::string conn_str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

   // NXL::nanodbc::string cnn_str_ = NANODBC_TEXT("Driver=Oracle 19 ODBC driver;Uid=guest;Pwd=123blue!;dbq=10.23.57.181:1521/orcl;");
    //NXL::nanodbc::string cnn_str_ = NANODBC_TEXT("Driver={Oracle 21 ODBC driver};Uid=SYSTEM;Pwd=123456;dbq=10.23.57.7:1522/ORCLCDB;");
//    NXL::nanodbc::string cnn_str_ = NANODBC_TEXT("Driver=ODBC Driver 17 for SQL Server;Server=10.23.57.46,1433;Uid=GUEST;PWD=123blue!;Database=autotest");
//    NXL::nanodbc::string cnn_str_1  = NANODBC_TEXT("Driver=Simba ODBC Driver for Google BigQuery 64-bit;OAuthMechanism = 1;"
//                                                  "RefreshToken=1//0gjCRgy--nifiCgYIARAAGBASNwF-L9Ir52m0QREgjWcSX9XMCBr7jluzFsyXDGch76LpQd0YAJZcIqrY9xQxdDPn4Is6qm3W94g;"//
//                                                  "Catalog=jdbc-enforcer;");

    NXL::nanodbc::string cnn_str_ = NANODBC_TEXT(conn_str);
    try {
        NXL::nanodbc::connection cnn_(cnn_str_);
        if (!cnn_.connected()) {
            mt::printFailed("prepare: connect error");
            return ;
        }

        std::string input;
        std::string sql_;
        while (true) {
            sql_.clear();
            input.clear();
            std::cout << std::endl;
            std::cout << "Please input menu command, SQL or  SQL file path:" << std::endl;
            getline(std::cin, input);
            if(input.length() < 1){
                continue;
            }
            if(input[0] == '/'){
                //path
                std::ifstream t(input);
                std::string sql((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
                sql_ = sql;
                printf("sql:%s\n", sql.c_str());
            } else {
                sql_ = input;
            }

            if(sql_.length() > 10){
                NXL::nanodbc::string sql = NANODBC_TEXT(sql_);
                execute_sql(cnn_, sql);
                continue;
            } else {
                printf("COMMAND EXIT :%s\n", sql_.c_str());
                break;
            }
        }
    }
    catch (NXL::nanodbc::database_error const& e) {
        printf("\n");
        mt::printFailed(e.what());
        return ;
    }

    //NXL::nanodbc::string sql_ = NANODBC_TEXT("select C_CHAR as 'c' , C_VARC, C_NCHAR, C_NVARc, C_NTEXT from jeff.TEST_c ss");
    //NXL::nanodbc::string sql_ = NANODBC_TEXT("select C_BINT, C_NUM, C_BIT, C_SMINT, C_DEC, C_SM_MONEY, C_INT, C_TINT, C_MONEY, C_FLOAT, C_REAL FROM jeff.TEST");
    //NXL::nanodbc::string sql_ = NANODBC_TEXT("select * FROM Autotest.customer");
    //m_taskPrepare.strSqlPath;

    return ;
}


TEST_MAIN()
