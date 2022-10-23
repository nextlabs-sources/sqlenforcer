package com.nextlabs.jdbc.oracleproxy;

import java.io.InputStream;
import java.io.Reader;
import java.math.BigDecimal;
import java.net.URL;
import java.sql.*;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;
import java.util.logging.*;

public class nxlPreparedStatement implements PreparedStatement {
    private PreparedStatement preparedStatement;
    private String sql;
    private Connection connection;
    private long enforcerContext;
    private Map<Integer,Object> params = new HashMap<Integer, Object>();

    private void prepareStatementSQLEnforcerEvaluation(String sql) throws SQLException{
        nxlMetaData meta = new nxlMetaData(this.connection);
        nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluationV2(this.enforcerContext, sql, meta);
        if(enforcedSqlResult.isBlocked)
        {
            throw  new SQLException("NxlEnforcer access denied");
        }
        this.sql = enforcedSqlResult.enforcedSql; 
    }

    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = this.connection.prepareStatement(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement1]:" + this.sql );
    }
    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql, int resultSetType, int resultSetConcurrency) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = connection.prepareStatement(this.sql,resultSetType,resultSetConcurrency);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement3]:" + this.sql );
    }
    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql, int resultSetType, int resultSetConcurrency, int resultSetHoldability) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = connection.prepareStatement(this.sql,resultSetType,resultSetConcurrency,resultSetHoldability);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement4]:" + this.sql );
    }
    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql, int autoGeneratedKeys) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = connection.prepareStatement(this.sql,autoGeneratedKeys);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement2]:" + this.sql );
    }
    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql, int[] columnIndexes) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = connection.prepareStatement(this.sql,columnIndexes);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement2]:" + this.sql );
    }
    public nxlPreparedStatement(Connection connection,long enforcerContext, String sql, String[] columnNames) throws SQLException {
        //this.sql = sql;
        this.connection = connection;
        this.enforcerContext = enforcerContext;
        this.prepareStatementSQLEnforcerEvaluation( sql);
        this.preparedStatement = connection.prepareStatement(this.sql,columnNames);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Connection.prepareStatement2]:" + this.sql );
    }

    @Override
    public ResultSet executeQuery() throws SQLException {
        ResultSet result = this.preparedStatement.executeQuery();
        nxlResultSet nxlResult = new nxlResultSet(result);
        return nxlResult;
    }

    @Override
    public int executeUpdate() throws SQLException {
        int result = this.preparedStatement.executeUpdate();
        return result;
    }

    @Override
    public void setNull(int parameterIndex, int sqlType) throws SQLException {
        this.params.put(parameterIndex,null);
        this.preparedStatement.setNull(parameterIndex,sqlType);
    }

    @Override
    public void setBoolean(int parameterIndex, boolean x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setBoolean(parameterIndex,x);
    }

    @Override
    public void setByte(int parameterIndex, byte x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setByte(parameterIndex,x);
    }

    @Override
    public void setShort(int parameterIndex, short x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setShort(parameterIndex,x);
    }

    @Override
    public void setInt(int parameterIndex, int x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setInt(parameterIndex,x);
    }

    @Override
    public void setLong(int parameterIndex, long x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setLong(parameterIndex,x);
    }

    @Override
    public void setFloat(int parameterIndex, float x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setFloat(parameterIndex,x);
    }

    @Override
    public void setDouble(int parameterIndex, double x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setDouble(parameterIndex,x);
    }

    @Override
    public void setBigDecimal(int parameterIndex, BigDecimal x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setBigDecimal(parameterIndex,x);
    }

    @Override
    public void setString(int parameterIndex, String x) throws SQLException {
        this.params.put(parameterIndex,x);
         this.preparedStatement.setString(parameterIndex,x);
    }

    @Override
    public void setBytes(int parameterIndex, byte[] x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setBytes(parameterIndex,x);
    }

    @Override
    public void setDate(int parameterIndex, Date x) throws SQLException {
        this.params.put(parameterIndex,x);
         this.preparedStatement.setDate(parameterIndex,x);
    }

    @Override
    public void setTime(int parameterIndex, Time x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setTime(parameterIndex,x);
    }

    @Override
    public void setTimestamp(int parameterIndex, Timestamp x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setTimestamp(parameterIndex,x);
    }

    @Override
    public void setAsciiStream(int parameterIndex, InputStream x, int length) throws SQLException {
        this.preparedStatement.setAsciiStream(parameterIndex,x,length);
    }

    @Override
    public void setUnicodeStream(int parameterIndex, InputStream x, int length) throws SQLException {
        this.preparedStatement.setUnicodeStream(parameterIndex,x,length);
    }

    @Override
    public void setBinaryStream(int parameterIndex, InputStream x, int length) throws SQLException {
         this.preparedStatement.setBinaryStream(parameterIndex,x,length);
    }

    @Override
    public void clearParameters() throws SQLException {
        this.params.clear();
        this.preparedStatement.clearParameters();
    }

    @Override
    public void setObject(int parameterIndex, Object x, int targetSqlType) throws SQLException {
        this.preparedStatement.setObject(parameterIndex,x,targetSqlType);
    }

    @Override
    public void setObject(int parameterIndex, Object x) throws SQLException {
        this.preparedStatement.setObject(parameterIndex,x);
    }

    @Override
    public boolean execute() throws SQLException {
        boolean result = this.preparedStatement.execute();
        return result;
    }

    @Override
    public void addBatch() throws SQLException {
        this.preparedStatement.addBatch();
    }

    @Override
    public void setCharacterStream(int parameterIndex, Reader reader, int length) throws SQLException {
        this.preparedStatement.setCharacterStream(parameterIndex,reader,length);
    }

    @Override
    public void setRef(int parameterIndex, Ref x) throws SQLException {
        this.preparedStatement.setRef(parameterIndex,x);
    }

    @Override
    public void setBlob(int parameterIndex, Blob x) throws SQLException {
        this.preparedStatement.setBlob(parameterIndex,x);
    }

    @Override
    public void setClob(int parameterIndex, Clob x) throws SQLException {
        this.preparedStatement.setClob(parameterIndex,x);
    }

    @Override
    public void setArray(int parameterIndex, Array x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setArray(parameterIndex,x);
    }

    @Override
    public ResultSetMetaData getMetaData() throws SQLException {
        ResultSetMetaData result = this.preparedStatement.getMetaData();
        return result;
    }

    @Override
    public void setDate(int parameterIndex, Date x, Calendar cal) throws SQLException {
        this.preparedStatement.setDate(parameterIndex,x,cal);
    }

    @Override
    public void setTime(int parameterIndex, Time x, Calendar cal) throws SQLException {
        this.preparedStatement.setTime(parameterIndex,x,cal);
    }

    @Override
    public void setTimestamp(int parameterIndex, Timestamp x, Calendar cal) throws SQLException {
        this.preparedStatement.setTimestamp(parameterIndex,x,cal);
    }

    @Override
    public void setNull(int parameterIndex, int sqlType, String typeName) throws SQLException {
        this.params.put(parameterIndex,null);
        this.preparedStatement.setNull(parameterIndex,sqlType,typeName);
    }

    @Override
    public void setURL(int parameterIndex, URL x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setURL(parameterIndex,x);
    }

    @Override
    public ParameterMetaData getParameterMetaData() throws SQLException {
        ParameterMetaData result = this.preparedStatement.getParameterMetaData();
        return result;
    }

    @Override
    public void setRowId(int parameterIndex, RowId x) throws SQLException {
        this.params.put(parameterIndex,x);
        this.preparedStatement.setRowId(parameterIndex,x);
    }

    @Override
    public void setNString(int parameterIndex, String value) throws SQLException {
        this.params.put(parameterIndex,value);
        this.preparedStatement.setNString(parameterIndex,value);
    }

    @Override
    public void setNCharacterStream(int parameterIndex, Reader value, long length) throws SQLException {
        this.preparedStatement.setNCharacterStream(parameterIndex,value,length);
    }

    @Override
    public void setNClob(int parameterIndex, NClob value) throws SQLException {
        this.preparedStatement.setNClob(parameterIndex,value);
    }

    @Override
    public void setClob(int parameterIndex, Reader reader, long length) throws SQLException {
        this.preparedStatement.setClob(parameterIndex,reader,length);
    }

    @Override
    public void setBlob(int parameterIndex, InputStream inputStream, long length) throws SQLException {
        this.preparedStatement.setBlob(parameterIndex,inputStream,length);
    }

    @Override
    public void setNClob(int parameterIndex, Reader reader, long length) throws SQLException {
        this.preparedStatement.setNClob(parameterIndex,reader,length);
    }

    @Override
    public void setSQLXML(int parameterIndex, SQLXML xmlObject) throws SQLException {
        this.preparedStatement.setSQLXML(parameterIndex,xmlObject);
    }

    @Override
    public void setObject(int parameterIndex, Object x, int targetSqlType, int scaleOrLength) throws SQLException {
        this.preparedStatement.setObject(parameterIndex,x,targetSqlType,scaleOrLength);
    }

    @Override
    public void setAsciiStream(int parameterIndex, InputStream x, long length) throws SQLException {
        this.preparedStatement.setAsciiStream(parameterIndex,x,length);
    }

    @Override
    public void setBinaryStream(int parameterIndex, InputStream x, long length) throws SQLException {
        this.preparedStatement.setBinaryStream(parameterIndex,x,length);
    }

    @Override
    public void setCharacterStream(int parameterIndex, Reader reader, long length) throws SQLException {
        this.preparedStatement.setCharacterStream(parameterIndex,reader,length);
    }

    @Override
    public void setAsciiStream(int parameterIndex, InputStream x) throws SQLException {
        this.preparedStatement.setAsciiStream(parameterIndex,x);
    }

    @Override
    public void setBinaryStream(int parameterIndex, InputStream x) throws SQLException {
        this.preparedStatement.setBinaryStream(parameterIndex,x);
    }

    @Override
    public void setCharacterStream(int parameterIndex, Reader reader) throws SQLException {
        this.preparedStatement.setCharacterStream(parameterIndex,reader);
    }

    @Override
    public void setNCharacterStream(int parameterIndex, Reader value) throws SQLException {
        this.preparedStatement.setNCharacterStream(parameterIndex,value);
    }

    @Override
    public void setClob(int parameterIndex, Reader reader) throws SQLException {
        this.preparedStatement.setClob(parameterIndex,reader);
    }

    @Override
    public void setBlob(int parameterIndex, InputStream inputStream) throws SQLException {
        this.preparedStatement.setBlob(parameterIndex,inputStream);
    }

    @Override
    public void setNClob(int parameterIndex, Reader reader) throws SQLException {
        this.preparedStatement.setNClob(parameterIndex,reader);
    }

    @Override
    public ResultSet executeQuery(String sql) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        ResultSet result = this.preparedStatement.executeQuery(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeQuery]:" + this.sql );
        return result;
    }

    @Override
    public int executeUpdate(String sql) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        int result = this.preparedStatement.executeUpdate(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeUpdate]:" + this.sql );
        return result;
    }

    @Override
    public void close() throws SQLException {
        this.preparedStatement.close();
    }

    @Override
    public int getMaxFieldSize() throws SQLException {
        int result = this.preparedStatement.getMaxFieldSize();
        return result;
    }

    @Override
    public void setMaxFieldSize(int max) throws SQLException {
        this.preparedStatement.setMaxFieldSize(max);
    }

    @Override
    public int getMaxRows() throws SQLException {
        int result = this.preparedStatement.getMaxRows();
        return result;
    }

    @Override
    public void setMaxRows(int max) throws SQLException {
        this.preparedStatement.setMaxRows(max);
    }

    @Override
    public void setEscapeProcessing(boolean enable) throws SQLException {
        this.preparedStatement.setEscapeProcessing(enable);
    }

    @Override
    public int getQueryTimeout() throws SQLException {
        int result = this.preparedStatement.getQueryTimeout();
        return result;
    }

    @Override
    public void setQueryTimeout(int seconds) throws SQLException {
        this.preparedStatement.setQueryTimeout(seconds);
    }

    @Override
    public void cancel() throws SQLException {
        this.preparedStatement.cancel();
    }

    @Override
    public SQLWarning getWarnings() throws SQLException {
        SQLWarning result = this.preparedStatement.getWarnings();
        return result;
    }

    @Override
    public void clearWarnings() throws SQLException {
        this.preparedStatement.clearWarnings();
    }

    @Override
    public void setCursorName(String name) throws SQLException {
        this.preparedStatement.setCursorName(name);
    }

    @Override
    public boolean execute(String sql) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        boolean result = this.preparedStatement.execute(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.execute]:" + this.sql );
        return result;
    }

    @Override
    public ResultSet getResultSet() throws SQLException {
        ResultSet result = this.preparedStatement.getResultSet();
        return result;
    }

    @Override
    public int getUpdateCount() throws SQLException {
        int result = this.preparedStatement.getUpdateCount();
        return result;
    }

    @Override
    public boolean getMoreResults() throws SQLException {
        boolean result = this.preparedStatement.getMoreResults();
        return result;
    }

    @Override
    public void setFetchDirection(int direction) throws SQLException {
        this.preparedStatement.setFetchDirection(direction);
    }

    @Override
    public int getFetchDirection() throws SQLException {
        int result = this.preparedStatement.getFetchDirection();
        return result;
    }

    @Override
    public void setFetchSize(int rows) throws SQLException {
        this.preparedStatement.setFetchSize(rows);
    }

    @Override
    public int getFetchSize() throws SQLException {
        int result = this.preparedStatement.getFetchSize();
        return result;
    }

    @Override
    public int getResultSetConcurrency() throws SQLException {
        int result = this.preparedStatement.getResultSetConcurrency();
        return result;
    }

    @Override
    public int getResultSetType() throws SQLException {
        int result = this.preparedStatement.getResultSetType();
        return result;
    }

    @Override
    public void addBatch(String sql) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation(sql);
        this.preparedStatement.addBatch(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.addBatch]:" + this.sql );
    }

    @Override
    public void clearBatch() throws SQLException {
        this.preparedStatement.clearBatch();
    }

    @Override
    public int[] executeBatch() throws SQLException {
        int[] result = this.preparedStatement.executeBatch();
        return result;
    }

    @Override
    public Connection getConnection() throws SQLException {
        Connection result = this.preparedStatement.getConnection();
        return result;
    }

    @Override
    public boolean getMoreResults(int current) throws SQLException {
        boolean result = this.preparedStatement.getMoreResults(current);
        return result;
    }

    @Override
    public ResultSet getGeneratedKeys() throws SQLException {
        ResultSet result = this.preparedStatement.getGeneratedKeys();
        return result;
    }

    @Override
    public int executeUpdate(String sql, int autoGeneratedKeys) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        int result = this.preparedStatement.executeUpdate(this.sql,autoGeneratedKeys);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeUpdate2]:" + this.sql );
        return result;
    }

    @Override
    public int executeUpdate(String sql, int[] columnIndexes) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        int result = this.preparedStatement.executeUpdate(this.sql,columnIndexes);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeUpdate2]:" + this.sql );
        return result;
    }

    @Override
    public int executeUpdate(String sql, String[] columnNames) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        int result = this.preparedStatement.executeUpdate(this.sql,columnNames);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeUpdate2]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, int autoGeneratedKeys) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        boolean result = this.preparedStatement.execute(this.sql,autoGeneratedKeys);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.execute2]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, int[] columnIndexes) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        boolean result = this.preparedStatement.execute(this.sql,columnIndexes);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.execute2]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, String[] columnNames) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        boolean result = this.preparedStatement.execute(this.sql,columnNames);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.execute]:" + this.sql );
        return result;
    }

    @Override
    public int getResultSetHoldability() throws SQLException {
        int result = this.preparedStatement.getResultSetHoldability();
        return result;
    }

    @Override
    public boolean isClosed() throws SQLException {
        boolean result = this.preparedStatement.isClosed();
        return result;
    }

    @Override
    public void setPoolable(boolean poolable) throws SQLException {
        this.preparedStatement.setPoolable(poolable);
    }

    @Override
    public boolean isPoolable() throws SQLException {
        boolean result = this.preparedStatement.isPoolable();
        return result;
    }

    @Override
    public void closeOnCompletion() throws SQLException {
        this.preparedStatement.closeOnCompletion();
    }

    @Override
    public boolean isCloseOnCompletion() throws SQLException {
        boolean result = this.preparedStatement.isCloseOnCompletion();
        return result;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
        T result = this.preparedStatement.unwrap(iface);
        return result;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        boolean result = this.preparedStatement.isWrapperFor(iface);
        return result;
    }

    @Override
    public void setObject(int parameterIndex, Object x, SQLType targetSqlType,
             int scaleOrLength) throws SQLException {
        this.preparedStatement.setObject(parameterIndex, x, targetSqlType, scaleOrLength);
    }

    
    @Override
    public void setObject(int parameterIndex, Object x, SQLType targetSqlType)
      throws SQLException {
        this.preparedStatement.setObject(parameterIndex, x, targetSqlType);
    }

    @Override
    public long executeLargeUpdate() throws SQLException {
        return this.preparedStatement.executeLargeUpdate();
    } 

        //4.2  extends by Statement

    @Override public long getLargeUpdateCount() throws SQLException {
        long result = this.preparedStatement.getLargeUpdateCount();
        return result;
    }


    @Override public void setLargeMaxRows(long max) throws SQLException {
        this.preparedStatement.setLargeMaxRows(max);
    }


    @Override public long getLargeMaxRows() throws SQLException {
        long result = this.preparedStatement.getLargeMaxRows();
        return result;
    }


    @Override public long[] executeLargeBatch() throws SQLException {
        long[] result = this.preparedStatement.executeLargeBatch();
        return result;
    }


    @Override public long executeLargeUpdate(String sql) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        long result = this.preparedStatement.executeLargeUpdate(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeLargeUpdate]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, int autoGeneratedKeys) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        long result = this.preparedStatement.executeLargeUpdate(this.sql,autoGeneratedKeys);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeLargeUpdate2]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, int columnIndexes[]) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        long result = this.preparedStatement.executeLargeUpdate(this.sql,columnIndexes);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeLargeUpdate2]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, String columnNames[]) throws SQLException {
        this.prepareStatementSQLEnforcerEvaluation( sql);
        long result = this.preparedStatement.executeLargeUpdate(this.sql,columnNames);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[PrepareSt.executeLargeUpdate2]:" + this.sql );
        return result;
    }
}
