package com.nextlabs.jdbc.mssqlproxy;

import java.sql.*;
import java.util.logging.*;

public class nxlMetaData {
    private Connection conn;
    public nxlMetaData(Connection c) {
        conn = c;
    }
    public String queryMetaData(String table){
        //
        nxlEnforcer.SQLEnforcerWriteLog(1,"queryMetaData begin! table="+table );
        String ret = "";
        

        String[] strs = table.split("\\.");
        
        if(strs.length != 3){
            //
            return ret;
        }
        String database = strs[0];
        String schema = strs[1];
        String table_ = strs[2];
        //
        String sql =  " select COLUMN_NAME, DATA_TYPE from " + database + ".information_schema.columns where " +
                        "TABLE_SCHEMA = '"+schema+"' " +
                        "AND TABLE_NAME  = '"+table_+"'";

        nxlEnforcer.SQLEnforcerWriteLog(1,"queryMetaData sql:"+sql );
        try{
            if(conn==null){
                return ret;
            }
            Statement statement = conn.createStatement();
            ResultSet rs = statement.executeQuery(sql);
            while (rs.next())
            {
                String col = rs.getString(1);
                String tp = rs.getString(2);
                ret+= col+"."+tp+"{}";
            }
        }catch (SQLException e){
            nxlEnforcer.SQLEnforcerWriteLog(3,"queryMetaData failed! :"+ e.getMessage() );
        }

        nxlEnforcer.SQLEnforcerWriteLog(1,"queryMetaData succeed! meta:"+ret );

        return ret;

    }
}