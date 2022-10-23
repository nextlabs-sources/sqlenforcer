#include <exception>
#include <thread>
#include <iostream>
#include <shared_mutex>

#include <boost/polymorphic_cast.hpp>

#include "nanodbc/nanodbc.h"

void test_sql_server() noexcept {
    try {
        nanodbc::connection conn("Driver={ODBC Driver 17 for SQL Server};Server=10.23.57.189;UID=sa;PWD=123blue!;");
//  auto row = nanodbc::execute(conn, "SELECT customer_id, c_custkey, c_mktsegment, c_privilege_level, [Phone Number] FROM DevTestDB.dbo.CUSTOMER;");
//        auto row = nanodbc::execute(conn, "SELECT * FROM DevTestDB.dbo.CUSTOMER");
        auto row = nanodbc::execute(conn, "SELECT * FROM DevTestDB.dbo.CUSTOMER where 'DAE_APP_USER' <> 'Jim.Lee'");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_oracle() noexcept {
    try {
        nanodbc::connection conn("Driver={ODBC Driver 19 for Oracle};Dbq=10.23.57.7:1521/orclcdb.lab666.com;UID=system;PWD=123Blue!;");
//        auto row = nanodbc::execute(conn, "SELECT * FROM GUEST.DEV_CUSTOMER_MASK where 'DAE_APP_USER' <> 'louis'");
        auto row = nanodbc::execute(conn, "CREATE TABLE CASE_1482 AS SELECT CUSTOMER_ID,C_CUSTKEY,C_MKTSEGMENT,C_PRIVILEGE_LEVEL from GUEST.CUSTOMER1");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_mysql() noexcept {
    try {
        nanodbc::connection conn("Driver={MySQL ODBC 8.0 ANSI Driver};Server=10.23.57.106;Database=Autotest;User=guest;Password=123Blue!;");
        auto row = nanodbc::execute(conn, "SELECT * FROM CUSTOMER1 where 'DAE_APP_USER' <> 'louis'");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_psql() noexcept {
    try {
        nanodbc::connection conn("Driver=/usr/pgsql-14/lib/psqlodbca.so;Server=10.23.57.132;Port=5432;Database=psql;Uid=postgres;Pwd=123blue!;");
        auto row = nanodbc::execute(conn, "select * from public.DEV_CUSTOMER_MASK where 'DAE_APP_USER' <> 'joy'");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_hana() noexcept {
    try {
        nanodbc::connection conn("Driver={ODBC Driver for HANA};SERVERNODE=10.23.56.44:39015;UID=GUEST;PWD=123Blue123Blue;");
        auto row = nanodbc::execute(conn, "SELECT * FROM CUSTOMER1 where 'DAE_APP_USER' <> 'louis'");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_prefilter() noexcept {
    try {
        nanodbc::connection conn("Driver={ODBC Driver 17 for SQL Server};Server=10.23.57.189;UID=sa;PWD=123blue!;");
//  auto row = nanodbc::execute(conn, "SELECT customer_id, c_custkey, c_mktsegment, c_privilege_level, [Phone Number] FROM DevTestDB.dbo.CUSTOMER;");
//        auto row = nanodbc::execute(conn, "SELECT * FROM DevTestDB.dbo.CUSTOMER");
        auto row = nanodbc::execute(conn, "SELECT * FROM DevTestDB.dbo.CUSTOMER22 where 'DAE_APP_USER' <> 'Louis'");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void test_delete() noexcept {
    try {
        nanodbc::connection conn("Driver={ODBC Driver 17 for SQL Server};Server=10.23.57.189;UID=sa;PWD=123blue!;");
        auto row = nanodbc::execute(conn, "DELETE FROM DevTestDB.dbo.CUSTOMER WHERE customer_id=100 AND c_custkey='';");

        for (int i = 1; row.next(); ++i) {
            std::cout << i << ": "
                      << (row.is_null(0) ? "[NULL]" : row.get<std::string>(0)) << " "
                      << (row.is_null(1) ? "[NULL]" : row.get<std::string>(1)) << " "
                      << (row.is_null(2) ? "[NULL]" : row.get<std::string>(2)) << std::endl;
        }
    }
    catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

int main(int argc, char **argv) {
    test_delete();
}