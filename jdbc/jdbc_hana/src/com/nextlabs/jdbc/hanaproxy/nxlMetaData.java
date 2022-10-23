package com.nextlabs.jdbc.hanaproxy;

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

        String schema = strs[1];
        String table_ = strs[2];
        //
        /*
        *              "\t--,length AS COLUMN_SIZE\n" +
                "\t--,scale AS DECIMAL_DIGITS\n" +
                "\t--,is_nullable AS NULLABLE\n" +
                "\t--,default_value AS COLUMN_DEF\n" +
                "\t--,comments AS REMARKS\n" +
                "\t--,cs_data_type_id\n" +
                "\t--,cs_data_type_name\n" +
                "\t--,compression_type\n" +
                "\t--,index_type \n" +
                "\t--,position AS ORDINAL_POSITION\n" +
        * */
        String sql = "SELECT column_name AS COLUMN_NAME\n" +
                "\t,DATA_TYPE_NAME AS TYPE_NAME\n" +
                "\tFROM SYS.TABLE_COLUMNS \n" +
                "\tWHERE \tschema_name = '"+schema+"' AND \ttable_name = '"+table_+"'  \n" +
                "\tORDER BY position";
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