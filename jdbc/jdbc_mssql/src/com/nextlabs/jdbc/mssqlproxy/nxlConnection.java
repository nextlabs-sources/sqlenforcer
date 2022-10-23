package com.nextlabs.jdbc.mssqlproxy;

import java.sql.*;
import java.util.Map;
import java.util.Properties;
import java.util.concurrent.Executor;
import java.io.*;

import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.file.Path;
import java.nio.file.Paths;

//import java.util.Properties;
import java.util.*;
import java.util.logging.*;


public class nxlConnection implements  Connection {

    private String url;
    public Connection connection;
    public long enforcerContext;
    public nxlUserAttr userRunnable = null;
    public Properties _con_attr;
    public nxlMetaData meta;
    enum EMDB_DB_TYPE
    {
        DB_UNKNOW,
        DB_SQLSERVER,
        DB_ORACLE,
        DB_MYSQL,
        DB_HANA,
        DB_BIGQUERY,
        DB_DB2
    }
    public Properties userAttr = new Properties();
    final String USERATTRQUALIFY = "app.user.";
    static  final String SQL_QUERY_DBINFO_SQLSERVER = "SELECT SUSER_SNAME(),SCHEMA_NAME(),DB_NAME(),@@SERVERNAME;";
    static  final String SQL_QUERY_DBINFO_MYSQL = "select MID(USER(),1,LENGTH(USER())-INSTR(REVERSE(USER()),'@')),'schema',database(),@@hostname;";
    static  final String SQL_QUERY_DBINFO_ORACLE = "SELECT (SELECT USERNAME FROM USER_USERS), (select SYS_CONTEXT('USERENV','CURRENT_SCHEMA') from dual) ,(select INSTANCE_NAME from v$instance), (select HOST_NAME from v$instance) from DUAL";
    static  final String SQL_QUERY_DBINFO_HANA = "SELECT CURRENT_USER,CURRENT_SCHEMA AS SCHEMA_NAME,(SELECT TOP 1 DATABASE_NAME FROM SYS.M_DATABASES) AS DB_NAME, '' AS SERVER_NAME FROM DUMMY";
    static  final String SQL_QUERY_DBINFO_BIGQUERY = "SELECT SESSION_USER() as user, '' as schema, '' as dbname, '' as servername;";
    static  final String SQL_QUERY_DBINFO_DB2 = "select current user as a,current schema as b, current server as c, 'DB2' as d from sysibm.sysdummy1";

    private Properties queryJDBCSessionInfo(EMDB_DB_TYPE dbType) throws SQLException {
        String strSQL="";
        Properties properties = new Properties();
        if(dbType == EMDB_DB_TYPE.DB_SQLSERVER)
        {
            strSQL = SQL_QUERY_DBINFO_SQLSERVER;
        }
        else if(dbType == EMDB_DB_TYPE.DB_MYSQL) {
            strSQL = SQL_QUERY_DBINFO_MYSQL;
            //String s3 = this.connection.getSchema();
        }
        else if(dbType == EMDB_DB_TYPE.DB_ORACLE) {
            strSQL = SQL_QUERY_DBINFO_ORACLE;
        }
        else if(dbType == EMDB_DB_TYPE.DB_HANA) {
            strSQL = SQL_QUERY_DBINFO_HANA;
        }
        else if (dbType == EMDB_DB_TYPE.DB_BIGQUERY){
            strSQL = SQL_QUERY_DBINFO_BIGQUERY;
        }
         else if (dbType == EMDB_DB_TYPE.DB_DB2){
            strSQL = SQL_QUERY_DBINFO_DB2;
        }
        Statement statement = this.connection.createStatement();
        ResultSet rs = statement.executeQuery(strSQL);
        ResultSetMetaData rsmd = rs.getMetaData();
        int iSize =  rsmd.getColumnCount();
        while (rs.next())
        {
            if (iSize == 4){
                properties.setProperty("user",rs.getString(1));
                properties.setProperty("schema",rs.getString(2));
                properties.setProperty("dbName",rs.getString(3));
                properties.setProperty("serverName",rs.getString(4));
            }

        }
        rs.close();
        statement.close();
        return properties;
    }
    // private void initUserFromDB(EMDB_DB_TYPE dbtype, String user) throws SQLException {
    //     String  sql = "SELECT * FROM ";
    //     try{
    //         String model = nxlUtil.readCfgValue("","USERMODE","mode","");
    //         System.out.println("initUserFromDB MODE:"+model);

    //         if(!model.equals("1"))
    //             return;
    //         String table = nxlUtil.readCfgValue("","USERMODE","mode_param2","");
    //         System.out.println("initUserFromDB table:"+table);
    //         if("".equals(table)) {
    //             throw  new Exception();
    //         }
    //         sql += table;
    //         // switch(dbtype) {
    //         //     case EMDB_DB_TYPE.DB_MYSQL:
    //         //     case EMDB_DB_TYPE.DB_SQLSERVER:
    //         //     case EMDB_DB_TYPE.DB_BIGQUERY:{ 
    //         //     } break;
    //         //     default:{
    //         //         throw  new Exception();
    //         //     } break;
    //         // }
    //         sql += " WHERE user_name = '";
    //         sql += user;
    //         sql += "'";
    //     } catch (Exception var5) {
    //         throw new SQLException("config.ini no schema.");
    //     }
    //     System.out.println("initUserFromDB sql:"+sql);
    //     try{
    //         PreparedStatement statement = this.connection.prepareStatement(sql);

    //         statement.executeQuery();

    //         ResultSet rs = statement.getResultSet();

    //         ResultSetMetaData rsmd = rs.getMetaData();
    //         while (rs.next()) /*get first row data*/
    //         {

    //             int iSize = rsmd.getColumnCount();
    //             for(int i = 1 ; i <= iSize; ++i){
    //                 String s = rs.getString(i);
    //                 if(s == null)
    //                     continue;
    //                 if( rsmd.getColumnType(i) == java.sql.Types.BOOLEAN ){
    //                     if(s.equals("0")) s = "false";
    //                     if(s.equals("1")) s = "true";
    //                 }

    //                 System.out.println("user_attr key:"+ rsmd.getColumnName(i) + " value:"+ s);
    //                 userAttr.setProperty(rsmd.getColumnName(i), s);
    //                 nxlEnforcer.SQLAddDBUserInfo(this.enforcerContext, rsmd.getColumnName(i), s);
    //             }
    //             break;
    //         }
    //         rs.close();
    //         statement.close();
    //     }catch (SQLException exc){
    //         System.out.println(exc.getCause());
    //         System.out.println(exc.getMessage());
    //         throw new SQLException("get user info from db generate error. detail:"+exc.getMessage());
    //     }
    // }
    private boolean initEnforceContext (Properties info) throws SQLException {
        DatabaseMetaData dbData = this.connection.getMetaData();
        String driverName = dbData.getDriverName();

        //System.out.println("driver_name:"+driverName);
        String userName = info.getProperty("user");
        String dataBaseName = info.getProperty("database");
        String serverName = info.getProperty("server");
        String schema = info.getProperty("schema");

        EMDB_DB_TYPE dbtype = EMDB_DB_TYPE.DB_SQLSERVER;
        if(serverName == null || userName == null || dataBaseName == null|| schema == null)
        {
            Properties properties = new Properties();
            properties = queryJDBCSessionInfo(dbtype);

            dataBaseName = properties.getProperty("dbName");
            serverName = properties.getProperty("serverName");
            userName = properties.getProperty("user");
            schema = properties.getProperty("schema");
        }
        if(userName == null || serverName == null || dataBaseName == null || schema ==null)
        {
            nxlEnforcer.SQLEnforcerWriteLog(4,"get resource attr failed!");
            return false;
        }

        nxlEnforcer.SQLEnforcerWriteLog(1,"userName: "+userName+" server: "+serverName+" db: "+dataBaseName+" sc: "+schema+" driver: "+driverName );

        this.enforcerContext = nxlEnforcer.SQLEnforcerNewContext(userName.trim(),"");
        nxlEnforcer.SQLEnforcerUserContext(this.enforcerContext,0,serverName.trim());
        nxlEnforcer.SQLEnforcerUserContext(this.enforcerContext,1,dataBaseName.trim());
        nxlEnforcer.SQLEnforcerUserContext(this.enforcerContext,2,schema.trim());
        nxlEnforcer.SQLEnforcerUserContext(this.enforcerContext,3,driverName.trim());
        nxlEnforcer.SQLEnforcerWriteLog(1,"SQLEnforcerNewContext succeed" );
        int iMode = 1;
        try {
            String model = nxlUtil.readCfgValue("","USERMODE","mode","");
            iMode = Integer.parseInt(model);
        } catch (IOException e) {
            nxlEnforcer.SQLEnforcerWriteLog(3,"read config USERMODE.mode failed, use default value(1)" );
            iMode = 1;
        }

        if (iMode == 1 || iMode < 0 || iMode > 2) {
            String connStr = "";
            try {
                String enc_connStr = nxlUtil.readCfgValue("","USERMODE","jdbc_conn_string","");
                connStr = nxlEnforcer.DecryptString(enc_connStr, true);
            } catch (Exception ex) {
                nxlEnforcer.SQLEnforcerWriteLog(4,"[USERMODE.jdbc_conn_string] is incorrect in config.ini. ");
                throw new SQLException("USERMODE.jdbc_conn_string is in wrong format");
            }
            userRunnable = new nxlUserAttr(connStr, userName,  this.enforcerContext, new Properties());
			userRunnable.sync_once_query();
            userRunnable.start();
        }
        nxlEnforcer.SQLEnforcerWriteLog(1,"initEnforceContext  succeed" );
        return true;
    }

    private static String getRealDriverPath(String url){
        String configInfo = "jdbc_driver_path";
        String defaultPath = "";

        if(url.startsWith("jdbc:oracle")){
            configInfo = "oracle_path";
            defaultPath = "C:\\ProgramData\\Nextlabs\\DAEforWin\\Drivers\\ojdbc8.jar";
        } else if(url.startsWith("jdbc:sap")){
            configInfo = "hana_path";
            defaultPath = "C:\\ProgramData\\Nextlabs\\DAEforWin\\Drivers\\ngdbc.jar";
        } else if(url.startsWith("jdbc:sqlserver") || url.startsWith("jdbc:microsoft")){
            configInfo = "mssql_path";
            defaultPath = "C:\\ProgramData\\Nextlabs\\DAEforWin\\Drivers\\mssql-jdbc-9.2.0.jre8.jar";
        } else if(url.startsWith("jdbc:db2")){
            configInfo = "db2_path";
        } else if(url.startsWith("jdbc:bigquery")){
            configInfo = "bigquery_path";
        } else {
            configInfo = "jdbc_driver_path";
        }
        try {
            String driverPath = nxlUtil.readCfgValue("","JDBC",configInfo,"");

            if (driverPath.isEmpty() || driverPath.startsWith("["))
            {
                driverPath = defaultPath;
            }

            return driverPath;
        } catch (IOException e) {
            nxlEnforcer.SQLEnforcerWriteLog(4,"[JDBC.mssql_path] is incorrect in config.ini. "+ e.getMessage());
            //
        }
        return "";
    }

    public static Connection createRealConnection (String var1, Properties var2, String keyword) throws SQLException {
        Connection conn = null;
        String path = getRealDriverPath(var1);
        nxlEnforcer.SQLEnforcerWriteLog(1,  "load real driver [mssql_path]="+path);

        //hana_path = "C:/Program Files/Tableau/driver/ojdbc8.jar";
        Path driverPath = Paths.get(path);
        URL url_o = null;
        try{
            url_o  = driverPath.toUri().toURL();//new URL(str);
            List<URL> fileList = new ArrayList();
            fileList.add(url_o);
            URLClassLoader loader = URLClassLoader.newInstance((URL[])fileList.toArray(new URL[0]));
            ServiceLoader<Driver> loadedDrivers = ServiceLoader.load(Driver.class, loader);

            Iterator<Driver> driversIterator = loadedDrivers.iterator();
            while(driversIterator.hasNext()) {
                Driver driver = (Driver)driversIterator.next();
                String sname = driver.getClass().getName();
                int indexorc = sname.indexOf(keyword);
                int indexnxl = sname.indexOf("nextlabs");
                if(indexorc >= 0 && indexnxl < 0){
                    conn = driver.connect(var1,var2);
                    nxlEnforcer.SQLEnforcerWriteLog(1,  "real conection succeed drivername:" +sname);
                    if(conn != null)
                        break;
                }
            }

        } catch (MalformedURLException e2){
            nxlEnforcer.SQLEnforcerWriteLog(4, "real driver, create URLClassLoader failed " + e2.getMessage());
        }
        return conn;
    }

    nxlConnection(String var1, Properties var2) throws SQLException {
        //----get real url
        String real_url="";
        int indexnxl = var1.indexOf("status=nextlabs");
        if( indexnxl >= 1){
            this.url = var1.substring(0,indexnxl-1);
            real_url = this.url;
        }
        //-----get connection
        this.connection = nxlConnection.createRealConnection(real_url,var2,"SQLServer");
        if(this.connection == null){
            throw new SQLException("createRealConnection failed.");
        }
        //System.out.println("url:"+this.url);
        _con_attr = var2;
        this.initEnforceContext(var2);

        nxlEnforcer.SQLEnforcerWriteLog(1,"initEnforceContext succeed!" );
    }
    
    @Override
    public Statement createStatement() throws SQLException {
       nxlStatement statement = new nxlStatement(this);
       return statement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql) throws SQLException {
        nxlPreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql);
        return preparedStatement;
    }

    @Override
    public CallableStatement prepareCall(String sql) throws SQLException {
        nxlMetaData meta = new nxlMetaData(this.connection);
        nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluationV2(this.enforcerContext, sql, meta);
        if(enforcedSqlResult.isBlocked){
            nxlEnforcer.SQLEnforcerWriteLog(1,  "[prepareCall 1] deny_sql="+sql);
            throw  new SQLException("NxlEnforcer access denied");
        } else {
            nxlEnforcer.SQLEnforcerWriteLog(1,  "[prepareCall 1] sql="+enforcedSqlResult.enforcedSql);
        }
        CallableStatement callableStatement = this.connection.prepareCall(enforcedSqlResult.enforcedSql);
        return callableStatement;
    }

    @Override
    public String nativeSQL(String sql) throws SQLException {
        String result = this.connection.nativeSQL(sql);
        return result;
    }

    @Override
    public void setAutoCommit(boolean autoCommit) throws SQLException {
        this.connection.setAutoCommit(autoCommit);
    }

    @Override
    public boolean getAutoCommit() throws SQLException {
        boolean result = this.connection.getAutoCommit();
        return result;
    }

    @Override
    public void commit() throws SQLException {
        this.connection.commit();
    }

    @Override
    public void rollback() throws SQLException {
        this.connection.rollback();
    }

    @Override
    public void close() throws SQLException {
		if(userRunnable!=null) {
			userRunnable.exit = true;
            userRunnable.interrupt();
        }
        this.connection.close();
    }

    @Override
    public boolean isClosed() throws SQLException {
        boolean result = this.connection.isClosed();
        return result;
    }

    @Override
    public DatabaseMetaData getMetaData() throws SQLException {
        DatabaseMetaData result = this.connection.getMetaData();
        return result;
    }

    @Override
    public void setReadOnly(boolean readOnly) throws SQLException {
        this.connection.setReadOnly(readOnly);
    }

    @Override
    public boolean isReadOnly() throws SQLException {
        boolean result = this.connection.isReadOnly();
        return result;
    }

    @Override
    public void setCatalog(String catalog) throws SQLException {
        this.connection.setCatalog(catalog);
    }

    @Override
    public String getCatalog() throws SQLException {
        String result = this.connection.getCatalog();
        return result;
    }

    @Override
    public void setTransactionIsolation(int level) throws SQLException {
        this.connection.setTransactionIsolation(level);
    }

    @Override
    public int getTransactionIsolation() throws SQLException {
        int result = this.connection.getTransactionIsolation();
        return result;
    }

    @Override
    public SQLWarning getWarnings() throws SQLException {
        SQLWarning result = this.connection.getWarnings();
        return result;
    }

    @Override
    public void clearWarnings() throws SQLException {
        this.connection.clearWarnings();
    }

    @Override
    public Statement createStatement(int resultSetType, int resultSetConcurrency) throws SQLException {
        Statement statement = new nxlStatement(this,resultSetType,resultSetConcurrency);
        return statement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql, int resultSetType, int resultSetConcurrency) throws SQLException {
        PreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql,resultSetType,resultSetConcurrency);
        return preparedStatement;
    }

    @Override
    public CallableStatement prepareCall(String sql, int resultSetType, int resultSetConcurrency) throws SQLException {
        nxlMetaData meta = new nxlMetaData(this.connection);
        nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluationV2(this.enforcerContext, sql, meta);
        if(enforcedSqlResult.isBlocked)
        {
            nxlEnforcer.SQLEnforcerWriteLog(1,"[prepareCall 3] deny_sql:" + sql );
            throw  new SQLException("NxlEnforcer access denied");
        }else{
             nxlEnforcer.SQLEnforcerWriteLog(1,"[prepareCall 3] new_sql:" + enforcedSqlResult.enforcedSql );
        }
        CallableStatement callableStatement = this.connection.prepareCall(enforcedSqlResult.enforcedSql,resultSetType,resultSetConcurrency);
        return callableStatement;
    }

    @Override
    public Map<String, Class<?>> getTypeMap() throws SQLException {
        Map<String, Class<?>> result = this.connection.getTypeMap();
        return result;
    }

    @Override
    public void setTypeMap(Map<String, Class<?>> map) throws SQLException {
        this.connection.setTypeMap(map);
    }

    @Override
    public void setHoldability(int holdability) throws SQLException {
        this.connection.setHoldability(holdability);
    }

    @Override
    public int getHoldability() throws SQLException {
        int result = this.connection.getHoldability();
        return result;
    }

    @Override
    public Savepoint setSavepoint() throws SQLException {
        Savepoint result = this.connection.setSavepoint();
        return result;
    }

    @Override
    public Savepoint setSavepoint(String name) throws SQLException {
        Savepoint result = this.setSavepoint(name);
        return result;
    }

    @Override
    public void rollback(Savepoint savepoint) throws SQLException {
        this.connection.rollback(savepoint);
    }

    @Override
    public void releaseSavepoint(Savepoint savepoint) throws SQLException {
        this.connection.releaseSavepoint(savepoint);
    }

    @Override
    public Statement createStatement(int resultSetType, int resultSetConcurrency, int resultSetHoldability) throws SQLException {
        Statement statement = new nxlStatement(this,resultSetType,resultSetConcurrency,resultSetHoldability);
        return statement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql, int resultSetType, int resultSetConcurrency, int resultSetHoldability) throws SQLException {
        PreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql,resultSetType,resultSetConcurrency,resultSetHoldability);
        return preparedStatement;
    }

    @Override
    public CallableStatement prepareCall(String sql, int resultSetType, int resultSetConcurrency, int resultSetHoldability) throws SQLException {
        nxlMetaData meta = new nxlMetaData(this.connection);
        nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluationV2(this.enforcerContext, sql, meta);
        if(enforcedSqlResult.isBlocked)
        {
            nxlEnforcer.SQLEnforcerWriteLog(1,"[prepareCall 4] deny_sql:" + sql );
            throw  new SQLException("NxlEnforcer access denied");
        }else{
             nxlEnforcer.SQLEnforcerWriteLog(1,"[prepareCall 4] new_sql:" + enforcedSqlResult.enforcedSql );
        }
        CallableStatement callableStatement = this.connection.prepareCall(enforcedSqlResult.enforcedSql,resultSetType,resultSetConcurrency,resultSetHoldability);
        return callableStatement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql, int autoGeneratedKeys) throws SQLException {
        PreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql,autoGeneratedKeys);
        return preparedStatement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql, int[] columnIndexes) throws SQLException {
        PreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql,columnIndexes);
        return preparedStatement;
    }

    @Override
    public PreparedStatement prepareStatement(String sql, String[] columnNames) throws SQLException {
        PreparedStatement preparedStatement = new nxlPreparedStatement(this.connection, this.enforcerContext, sql,columnNames);
        return preparedStatement;
    }

    @Override
    public Clob createClob() throws SQLException {
        Clob result = this.connection.createClob();
        return result;
    }

    @Override
    public Blob createBlob() throws SQLException {
        Blob result = this.connection.createBlob();
        return result;
    }

    @Override
    public NClob createNClob() throws SQLException {
        NClob result = this.connection.createNClob();
        return result;
    }

    @Override
    public SQLXML createSQLXML() throws SQLException {
        SQLXML result = this.connection.createSQLXML();
        return result;
    }

    @Override
    public boolean isValid(int timeout) throws SQLException {
        boolean result = this.connection.isValid(timeout);
        return result;
    }

    @Override
    public void setClientInfo(String name, String value) throws SQLClientInfoException {
        if(name.startsWith(USERATTRQUALIFY)){
            String key = name.substring(9);
            userAttr.setProperty(key, value);
            nxlEnforcer.SQLAddDBUserInfo(this.enforcerContext, key, value);
            return;
        }
        this.connection.setClientInfo(name, value);
    }

    @Override
    public void setClientInfo(Properties properties) throws SQLClientInfoException {
        Properties temp = new Properties();
        for (String key_in : properties.stringPropertyNames()) {
            //System.out.println(key + "=" + properties.getProperty(key));
            if(key_in.startsWith(USERATTRQUALIFY)){
                String key = key_in.substring(9);
                userAttr.setProperty(key, properties.getProperty(key_in));
                nxlEnforcer.SQLAddDBUserInfo(this.enforcerContext, key, properties.getProperty(key_in));
            } else {
                temp.setProperty(key_in, properties.getProperty(key_in));
            }
        }
        if(!temp.stringPropertyNames().isEmpty()){
            this.connection.setClientInfo(temp);
        }
    }

    @Override
    public String getClientInfo(String name) throws SQLException {
        if(name.startsWith(USERATTRQUALIFY)){
            String key = name.substring(9);
            String result = userAttr.getProperty(key);
            return result;
        } else {
            String result = this.connection.getClientInfo(name);
            return result;
        }
    }

    @Override
    public Properties getClientInfo() throws SQLException {
        Properties result = this.connection.getClientInfo();
        for (String key_user : userAttr.stringPropertyNames()){
            String key = USERATTRQUALIFY + key_user;
            result.setProperty(key, userAttr.getProperty(key_user));
        }
        return result;
    }

    @Override
    public Array createArrayOf(String typeName, Object[] elements) throws SQLException {
        Array result = this.connection.createArrayOf(typeName,elements);
        return result;
    }

    @Override
    public Struct createStruct(String typeName, Object[] attributes) throws SQLException {
        Struct result = this.connection.createStruct(typeName,attributes);
        return result;
    }

    @Override
    public void setSchema(String schema) throws SQLException {
        this.connection.setSchema(schema);
    }

    @Override
    public String getSchema() throws SQLException {
        String result = this.connection.getSchema();
        return result;
    }

    @Override
    public void abort(Executor executor) throws SQLException {
        this.connection.abort(executor);
    }

    @Override
    public void setNetworkTimeout(Executor executor, int milliseconds) throws SQLException {
        this.connection.setNetworkTimeout(executor,milliseconds);
    }

    @Override
    public int getNetworkTimeout() throws SQLException {
        int result = this.connection.getNetworkTimeout();
        return result;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
        T result = this.connection.unwrap(iface);
        return result;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        boolean result = this.connection.isWrapperFor(iface);
        return result;
    }
}
