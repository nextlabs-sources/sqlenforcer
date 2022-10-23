package com.nextlabs.jdbc.oracleproxy;

import java.sql.*;
import java.util.logging.*;

public class nxlMetaData {
    private Connection conn;
    public nxlMetaData(Connection c) {
        conn = c;
    }
    public String queryMetaData(String table){  //hana
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
        String sql = "SELECT COLUMN_NAME, DATA_TYPE FROM ALL_TAB_COLUMNS WHERE OWNER = '" + schema + "' AND TABLE_NAME = '" + table_ + "' ORDER BY COLUMN_ID";

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
                if(col.length() > 0 && tp.length() > 0){
                    ret+= col+"."+tp+"{}";
                }
            }
        }catch (SQLException e){
            nxlEnforcer.SQLEnforcerWriteLog(3,"queryMetaData failed! :"+ e.getMessage() );
        }

        nxlEnforcer.SQLEnforcerWriteLog(1,"queryMetaData succeed! meta:"+ret );

        return ret;

    }
}