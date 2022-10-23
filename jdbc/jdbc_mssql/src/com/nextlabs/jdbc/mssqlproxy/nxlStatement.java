package com.nextlabs.jdbc.mssqlproxy;

import java.sql.*;
import java.util.List;
import java.util.logging.*;

public class nxlStatement implements Statement {
    private Statement statement;
    //private List<String> batchSql;
    private nxlConnection connection;
    private String sql;

    private void statementSQLEnforcerEvaluation( String sql) throws SQLException{
        //nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluation(this.connection.enforcerContext, sql);
        nxlMetaData meta = new nxlMetaData(this.connection.connection);
        nxlEnforcedSqlResult enforcedSqlResult = nxlEnforcer.SQLEnforcerEvaluationV2(this.connection.enforcerContext, sql, meta);
        if(enforcedSqlResult.isBlocked)
        {
            throw  new SQLException("NxlEnforcer access denied");
        }
        this.sql = enforcedSqlResult.enforcedSql; 
    }

    public nxlStatement(nxlConnection nxlconnection) throws SQLException {
        this.connection = nxlconnection;
        this.statement = nxlconnection.connection.createStatement();
    }
    public nxlStatement(nxlConnection nxlconnection,int resultSetType, int resultSetConcurrency) throws SQLException {
        this.connection = nxlconnection;
        this.statement = nxlconnection.connection.createStatement(resultSetType,resultSetConcurrency);
    }
    public  nxlStatement(nxlConnection nxlconnection,int resultSetType, int resultSetConcurrency, int resultSetHoldability) throws SQLException {
        this.connection = nxlconnection;
        this.statement = nxlconnection.connection.createStatement(resultSetType,resultSetConcurrency,resultSetHoldability);
    }

    @Override
    public ResultSet executeQuery(String sql) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        ResultSet resultSet = this.statement.executeQuery(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeQuery]:" + this.sql );
        return resultSet;
    }

    @Override
    public int executeUpdate(String sql) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        int result = this.statement.executeUpdate(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeUpdate]:" + this.sql );
        return result;
    }

    @Override
    public void close() throws SQLException {
        this.statement.close();
    }

    @Override
    public int getMaxFieldSize() throws SQLException {
        int result = this.statement.getMaxFieldSize();
        return result;
    }

    @Override
    public void setMaxFieldSize(int max) throws SQLException {
        this.statement.setMaxFieldSize(max);
    }

    @Override
    public int getMaxRows() throws SQLException {
        int result = this.statement.getMaxRows();
        return result;
    }

    @Override
    public void setMaxRows(int max) throws SQLException {
        this.statement.setMaxRows(max);
    }

    @Override
    public void setEscapeProcessing(boolean enable) throws SQLException {
        this.statement.setEscapeProcessing(enable);
    }

    @Override
    public int getQueryTimeout() throws SQLException {
        int result = this.statement.getQueryTimeout();
        return result;
    }

    @Override
    public void setQueryTimeout(int seconds) throws SQLException {
        this.statement.setQueryTimeout(seconds);
    }

    @Override
    public void cancel() throws SQLException {
        this.statement.cancel();
    }

    @Override
    public SQLWarning getWarnings() throws SQLException {
        SQLWarning result = this.statement.getWarnings();
        return result;
    }

    @Override
    public void clearWarnings() throws SQLException {
        this.statement.clearWarnings();
    }

    @Override
    public void setCursorName(String name) throws SQLException {
        this.setCursorName(name);
    }

    @Override
    public boolean execute(String sql) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        boolean result = this.statement.execute(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.execute]:" + this.sql );
        return result;
    }

    @Override
    public ResultSet getResultSet() throws SQLException {
        ResultSet result = this.statement.getResultSet();
        return result;
    }

    @Override
    public int getUpdateCount() throws SQLException {
        int result = this.statement.getUpdateCount();
        return result;
    }

    @Override
    public boolean getMoreResults() throws SQLException {
        boolean result = this.statement.getMoreResults();
        return result;
    }

    @Override
    public void setFetchDirection(int direction) throws SQLException {
       this.statement.setFetchDirection(direction);
    }

    @Override
    public int getFetchDirection() throws SQLException {
        int result = this.statement.getFetchDirection();
        return result;
    }

    @Override
    public void setFetchSize(int rows) throws SQLException {
        this.statement.setFetchSize(rows);
    }

    @Override
    public int getFetchSize() throws SQLException {
        int result = this.statement.getFetchSize();
        return result;
    }

    @Override
    public int getResultSetConcurrency() throws SQLException {
        int result = this.statement.getResultSetConcurrency();
        return result;
    }

    @Override
    public int getResultSetType() throws SQLException {
        int result = this.statement.getResultSetType();
        return result;
    }

    @Override
    public void addBatch(String sql) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        this.statement.addBatch(this.sql);
        nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.addBatch]:" + this.sql );
    }

    @Override
    public void clearBatch() throws SQLException {
        //this.batchSql.clear();
        this.statement.clearBatch();
    }

    @Override
    public int[] executeBatch() throws SQLException {
        int[] result = this.statement.executeBatch();
        return result;
    }

    @Override
    public Connection getConnection() throws SQLException {
        Connection connection = this.statement.getConnection();
        return connection;
    }

    @Override
    public boolean getMoreResults(int current) throws SQLException {
        boolean result = this.statement.getMoreResults(current);
        return result;
    }

    @Override
    public ResultSet getGeneratedKeys() throws SQLException {
        ResultSet result = this.statement.getGeneratedKeys();
        return result;
    }

    @Override
    public int executeUpdate(String sql, int autoGeneratedKeys) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        int result = this.statement.executeUpdate(this.sql,autoGeneratedKeys);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeUpdate]:" + this.sql );
        return result;
    }

    @Override
    public int executeUpdate(String sql, int[] columnIndexes) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        int result = this.statement.executeUpdate(this.sql,columnIndexes);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeUpdate]:" + this.sql );
        return result;
    }

    @Override
    public int executeUpdate(String sql, String[] columnNames) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        int result = this.statement.executeUpdate(this.sql,columnNames);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeUpdate]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, int autoGeneratedKeys) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        boolean result = this.statement.execute(this.sql,autoGeneratedKeys);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.execute2]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, int[] columnIndexes) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        boolean result = this.statement.execute(this.sql,columnIndexes);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.execute2]:" + this.sql );
        return result;
    }

    @Override
    public boolean execute(String sql, String[] columnNames) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        boolean result = this.statement.execute(this.sql,columnNames);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.execute2]:" + this.sql );
        return result;
    }

    @Override
    public int getResultSetHoldability() throws SQLException {
        int result = this.statement.getResultSetHoldability();
        return result;
    }

    @Override
    public boolean isClosed() throws SQLException {
        boolean result = this.statement.isClosed();
        return result;
    }

    @Override
    public void setPoolable(boolean poolable) throws SQLException {
        this.statement.setPoolable(poolable);
    }

    @Override
    public boolean isPoolable() throws SQLException {
        boolean result = this.statement.isPoolable();
        return result;
    }

    @Override
    public void closeOnCompletion() throws SQLException {
        this.statement.closeOnCompletion();
    }

    @Override
    public boolean isCloseOnCompletion() throws SQLException {
        boolean result = this.statement.isCloseOnCompletion();
        return result;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
         T result = this.statement.unwrap(iface);
        return result;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        boolean result = this.statement.isWrapperFor(iface);
        return result;
    }
    //4.2

    @Override public long getLargeUpdateCount() throws SQLException {
        long result = this.statement.getLargeUpdateCount();
        return result;
    }


    @Override public void setLargeMaxRows(long max) throws SQLException {
        this.statement.setLargeMaxRows(max);
    }


    @Override public long getLargeMaxRows() throws SQLException {
        long result = this.statement.getLargeMaxRows();
        return result;
    }


    @Override public long[] executeLargeBatch() throws SQLException {
        long[] result = this.statement.executeLargeBatch();
        return result;
    }


    @Override public long executeLargeUpdate(String sql) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        long result = this.statement.executeLargeUpdate(this.sql);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeLargeUpdate]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, int autoGeneratedKeys) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        long result = this.statement.executeLargeUpdate(this.sql,autoGeneratedKeys);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeLargeUpdate]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, int columnIndexes[]) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        long result = this.statement.executeLargeUpdate(this.sql,columnIndexes);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeLargeUpdate]:" + this.sql );
        return result;
    }


    @Override public long executeLargeUpdate(String sql, String columnNames[]) throws SQLException {
        this.statementSQLEnforcerEvaluation(sql);
        long result = this.statement.executeLargeUpdate(this.sql,columnNames);
         nxlEnforcer.SQLEnforcerWriteLog(1,"[Statement.executeLargeUpdate]:" + this.sql );
        return result;
    }

}
