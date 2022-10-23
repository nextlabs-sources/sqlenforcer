package com.nextlabs.jdbc.driverproxy;

import java.sql.*;

public class nxlMetaData {
    private static final String SQL_FORMAT_QUERY_META_DATA_SQLSERVER
            = "SELECT COLUMN_NAME, DATA_TYPE FROM %s.INFORMATION_SCHEMA.COLUMNS" +
            " WHERE TABLE_SCHEMA = '%s' AND TABLE_NAME  = '%s'";
    private static final String SQL_FORMAT_QUERY_META_DATA_ORACLE
            = "SELECT COLUMN_NAME, DATA_TYPE FROM ALL_TAB_COLUMNS " +
            "WHERE OWNER = '%s' AND TABLE_NAME = '%s' ORDER BY COLUMN_ID";
    private static final String SQL_FORMAT_QUERY_META_DATA_HANA
            = "SELECT column_name AS COLUMN_NAME, DATA_TYPE_NAME AS TYPE_NAME FROM SYS.TABLE_COLUMNS " +
            "WHERE schema_name = '%s' AND table_name = '%s' ORDER BY position";
    private static final String SQL_FORMAT_QUERY_META_DATA_MYSQL
            = "SELECT COLUMN_NAME, COLUMN_TYPE FROM INFORMATION_SCHEMA.COLUMNS " +
            "WHERE LOWER(TABLE_SCHEMA) = LOWER('%s') AND LOWER(TABLE_NAME) = LOWER('%s')";
    private static final String SQL_FORMAT_QUERY_META_DATA_POSTGRESQL
            = "SELECT COLUMN_NAME, UDT_NAME FROM INFORMATION_SCHEMA.COLUMNS " +
            "WHERE LOWER(TABLE_CATALOG) = LOWER('%s') AND LOWER(TABLE_SCHEMA)=LOWER('%s') AND LOWER(TABLE_NAME) = LOWER('%s')";

    private Connection conn;

    public nxlMetaData(Connection c) {
        conn = c;
    }

    public String queryMetaData(String table) {
        nxlEnforcer.SQLEnforcerWriteLog(1, "queryMetaData begin! table=" + table);
        String ret = "";

        try {
            String sql = getQueryMetaDataSql(table);
            nxlEnforcer.SQLEnforcerWriteLog(1, "queryMetaData sql:" + sql);

            if (conn == null) {
                return ret;
            }
            Statement statement = conn.createStatement();
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next()) {
                String col = rs.getString(1);
                String tp = rs.getString(2);
                ret += col + "." + tp + "{}";
            }
        } catch (Exception e) {
            nxlEnforcer.SQLEnforcerWriteLog(3, "queryMetaData failed! :" + e.getMessage());
        }

        nxlEnforcer.SQLEnforcerWriteLog(1, "queryMetaData succeed! meta:" + ret);

        return ret;

    }

    public String getQueryMetaDataSql(String tableName) throws IllegalArgumentException, SQLException {
        String[] strs = tableName.split("\\.");

        if (strs.length != 3) {
            throw new IllegalArgumentException("Wrong format table: " + tableName);
        }

        String sql = "";
        DatabaseMetaData dbData = this.conn.getMetaData();
        String driverName = dbData.getDriverName();

        if (driverName.toLowerCase().contains("sql server")) {
            sql = String.format(SQL_FORMAT_QUERY_META_DATA_SQLSERVER, strs[0], strs[1], strs[2]);
        } else if (driverName.toLowerCase().contains("oracle")) {
            sql = String.format(SQL_FORMAT_QUERY_META_DATA_ORACLE, strs[1], strs[2]);
        } else if (driverName.toLowerCase().contains("hdb")) {
            sql = String.format(SQL_FORMAT_QUERY_META_DATA_HANA, strs[1], strs[2]);
        } else if (driverName.toLowerCase().contains("mysql")) {
            sql = String.format(SQL_FORMAT_QUERY_META_DATA_MYSQL, strs[1], strs[2]);
        } else if (driverName.toLowerCase().contains("postgresql")) {
            sql = String.format(SQL_FORMAT_QUERY_META_DATA_POSTGRESQL, strs[0], strs[1], strs[2]);
        }

        return sql;
    }
}