package com.nextlabs.jdbc.mssqlproxy;

import java.sql.*;
import java.util.Properties;
import java.util.logging.Logger;
import java.io.*;
import java.util.logging.*;



public class nxlMSSDriver implements java.sql.Driver {
    static {
        try
        {
            DriverManager.registerDriver(new nxlMSSDriver());
        }
        catch (SQLException E)
        {
            throw new RuntimeException("Can't register driver!");
        }
    }


    @Override
    public Connection connect(String url, Properties info) throws SQLException{
        nxlEnforcer.SQLEnforcerWriteLog(1,"connect url:"+url );
        if (acceptsURL(url)) {
            url += ";status=nextlabs";
            Connection conn = new nxlConnection(url,info);
            if(conn != null){
                nxlEnforcer.SQLEnforcerWriteLog(1,"------connected!" );
            } else {
                nxlEnforcer.SQLEnforcerWriteLog(1,"------connect failed!" );
            }
            return conn;
        } else {
            //nxlEnforcer.SQLEnforcerWriteLog(3,"--acceptsURL return false url="+url );
            //throw new SQLException("Wrong url specified");
            return null ;
        }
    }

    @Override
    public boolean acceptsURL(String url) throws SQLException {
        if (url==null) {
            nxlEnforcer.SQLEnforcerWriteLog(4,"nxlMSSDriver.acceptsURL  url=null");
            throw new SQLException("Wrong url specified url=null");
        }
        int intIndex = url.indexOf("sqlserver");
        int status = url.indexOf("status=nextlabs");
        return (intIndex != -1) && (status == -1);
    }

    @Override
    public DriverPropertyInfo[] getPropertyInfo(String url, Properties info) throws SQLException {
        return new DriverPropertyInfo[0];
    }

    @Override
    public int getMajorVersion() {
        return 1;
    }

    @Override
    public int getMinorVersion() {
        return 0;
    }

    @Override
    public boolean jdbcCompliant() {
        return false;
    }

    @Override
    public Logger getParentLogger() throws SQLFeatureNotSupportedException {
        return null;
    }
}
