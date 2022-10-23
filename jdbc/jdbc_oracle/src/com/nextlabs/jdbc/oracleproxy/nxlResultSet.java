package com.nextlabs.jdbc.oracleproxy;

import java.io.InputStream;
import java.io.Reader;
import java.math.BigDecimal;
import java.net.URL;
import java.sql.*;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Map;
import java.util.logging.*;


public class nxlResultSet implements ResultSet {
    private ResultSet resultSet;
    private String tableName;
    private int columnCount;
    private List<nxlResultSetAttr> nxlResultSetAttrList;

    nxlResultSet(ResultSet resultSet) {
        this.resultSet = resultSet;
        try {
            ResultSetMetaData metaData = this.resultSet.getMetaData();
             this.columnCount = metaData.getColumnCount();
             this.nxlResultSetAttrList = new ArrayList<nxlResultSetAttr>();
            for (int index = 1;index<=this.columnCount;index++)
            {
                String columnName = metaData.getColumnName(index);
                String dataType = metaData.getColumnTypeName(index);
                nxlResultSetAttr model = new nxlResultSetAttr(index,columnName,dataType,null);
                this.nxlResultSetAttrList.add(model);
            }
        } catch (SQLException e) {
            nxlEnforcer.SQLEnforcerWriteLog(4,"nxlResultSet " + e.getMessage());
        }
    }
    private boolean enforcer(String action) throws SQLException {
        int row = this.resultSet.getRow();
        ResultSetMetaData metaData = this.resultSet.getMetaData();

        if(this.columnCount>0)
        {
            this.tableName = metaData.getTableName(1);
            for(int index=1;index<this.columnCount;index++)
            {
                //String a =  metaData.getTableName(index+1);
                if(!this.tableName.equals(metaData.getTableName(index+1)))
                {
                    return true;
                }
            }
        }
        else
        {
            return true;
        }
        for(int index = 0;index<this.nxlResultSetAttrList.size();index++)
        {
            if(action =="delete")
            {
                String value= this.resultSet.getString(index+1);
                nxlResultSetAttr model = this.nxlResultSetAttrList.get(index);
                model.setValue(value);
            }
            else if(action =="insert"||action =="update")
            {

            }
        }
        return false;
    }
    private <T> void setAttrValueByName(String columnLabel,T value) throws SQLException {
        int index = this.resultSet.findColumn(columnLabel);
        this.setAttrValueByIndex(index,value);
    }
    private <T> void setAttrValueByIndex(int index,T value) throws SQLException {
        nxlResultSetAttr nxlResultSetAttr = this.nxlResultSetAttrList.get(index-1);
        nxlResultSetAttr.setValue(value);
    }
    @Override
    public boolean next() throws SQLException {
        boolean result = this.resultSet.next();
        return result;
    }

    @Override
    public void close() throws SQLException {
        this.resultSet.close();
    }

    @Override
    public boolean wasNull() throws SQLException {
        boolean result = this.resultSet.wasNull();
        return result;
    }

    @Override
    public String getString(int columnIndex) throws SQLException {
        String result = this.resultSet.getString(columnIndex);
        return result;
    }

    @Override
    public boolean getBoolean(int columnIndex) throws SQLException {
        boolean result = this.resultSet.getBoolean(columnIndex);
        return result;
    }

    @Override
    public byte getByte(int columnIndex) throws SQLException {
        byte result = this.resultSet.getByte(columnIndex);
        return result;
    }

    @Override
    public short getShort(int columnIndex) throws SQLException {
        short result = this.resultSet.getShort(columnIndex);
        return result;
    }

    @Override
    public int getInt(int columnIndex) throws SQLException {
        int result = this.resultSet.getInt(columnIndex);
        return result;
    }

    @Override
    public long getLong(int columnIndex) throws SQLException {
        long result = this.resultSet.getLong(columnIndex);
        return result;
    }

    @Override
    public float getFloat(int columnIndex) throws SQLException {
        float result = this.resultSet.getFloat(columnIndex);
        return result;
    }

    @Override
    public double getDouble(int columnIndex) throws SQLException {
        double result = this.resultSet.getDouble(columnIndex);
        return result;
    }

    @Override
    public BigDecimal getBigDecimal(int columnIndex, int scale) throws SQLException {
        BigDecimal result = this.resultSet.getBigDecimal(columnIndex,scale);
        return result;
    }

    @Override
    public byte[] getBytes(int columnIndex) throws SQLException {
        byte[] result = this.resultSet.getBytes(columnIndex);
        return result;
    }

    @Override
    public Date getDate(int columnIndex) throws SQLException {
        Date result = this.resultSet.getDate(columnIndex);
        return result;
    }

    @Override
    public Time getTime(int columnIndex) throws SQLException {
        Time result = this.resultSet.getTime(columnIndex);
        return result;
    }

    @Override
    public Timestamp getTimestamp(int columnIndex) throws SQLException {
        Timestamp result = this.resultSet.getTimestamp(columnIndex);
        return result;
    }

    @Override
    public InputStream getAsciiStream(int columnIndex) throws SQLException {
        InputStream result = this.resultSet.getAsciiStream(columnIndex);
        return result;
    }

    @Override
    public InputStream getUnicodeStream(int columnIndex) throws SQLException {
        InputStream result = this.resultSet.getUnicodeStream(columnIndex);
        return result;
    }

    @Override
    public InputStream getBinaryStream(int columnIndex) throws SQLException {
        InputStream result = this.resultSet.getBinaryStream(columnIndex);
        return result;
    }

    @Override
    public String getString(String columnLabel) throws SQLException {
        String result = this.resultSet.getString(columnLabel);
        return result;
    }

    @Override
    public boolean getBoolean(String columnLabel) throws SQLException {
        boolean result = this.resultSet.getBoolean(columnLabel);
        return result;
    }

    @Override
    public byte getByte(String columnLabel) throws SQLException {
        byte result = this.resultSet.getByte(columnLabel);
        return result;
    }

    @Override
    public short getShort(String columnLabel) throws SQLException {
        short result = this.resultSet.getShort(columnLabel);
        return result;
    }

    @Override
    public int getInt(String columnLabel) throws SQLException {
        int result = this.resultSet.getInt(columnLabel);
        return result;
    }

    @Override
    public long getLong(String columnLabel) throws SQLException {
        long result = this.resultSet.getLong(columnLabel);
        return result;
    }

    @Override
    public float getFloat(String columnLabel) throws SQLException {
        float result = this.resultSet.getFloat(columnLabel);
        return result;
    }

    @Override
    public double getDouble(String columnLabel) throws SQLException {
        double result = this.resultSet.getDouble(columnLabel);
        return result;
    }

    @Override
    public BigDecimal getBigDecimal(String columnLabel, int scale) throws SQLException {
        BigDecimal result = this.resultSet.getBigDecimal(columnLabel,scale);
        return result;
    }

    @Override
    public byte[] getBytes(String columnLabel) throws SQLException {
        byte[] result = this.resultSet.getBytes(columnLabel);
        return result;
    }

    @Override
    public Date getDate(String columnLabel) throws SQLException {
        Date result = this.resultSet.getDate(columnLabel);
        return result;
    }

    @Override
    public Time getTime(String columnLabel) throws SQLException {
        Time result = this.resultSet.getTime(columnLabel);
        return result;
    }

    @Override
    public Timestamp getTimestamp(String columnLabel) throws SQLException {
        Timestamp result = this.resultSet.getTimestamp(columnLabel);
        return result;
    }

    @Override
    public InputStream getAsciiStream(String columnLabel) throws SQLException {
        InputStream result = this.resultSet.getAsciiStream(columnLabel);
        return result;
    }

    @Override
    public InputStream getUnicodeStream(String columnLabel) throws SQLException {
        InputStream result = this.resultSet.getUnicodeStream(columnLabel);
        return result;
    }

    @Override
    public InputStream getBinaryStream(String columnLabel) throws SQLException {
        InputStream result = this.resultSet.getBinaryStream(columnLabel);
        return result;
    }

    @Override
    public SQLWarning getWarnings() throws SQLException {
        SQLWarning result = this.resultSet.getWarnings();
        return result;
    }

    @Override
    public void clearWarnings() throws SQLException {
        this.resultSet.clearWarnings();
    }

    @Override
    public String getCursorName() throws SQLException {
        String result = this.resultSet.getCursorName();
        return result;
    }

    @Override
    public ResultSetMetaData getMetaData() throws SQLException {
        ResultSetMetaData result = this.resultSet.getMetaData();
        return result;
    }

    @Override
    public Object getObject(int columnIndex) throws SQLException {
        Object result = this.resultSet.getObject(columnIndex);
        return result;
    }

    @Override
    public Object getObject(String columnLabel) throws SQLException {
        Object result = this.resultSet.getObject(columnLabel);
        return result;
    }

    @Override
    public int findColumn(String columnLabel) throws SQLException {
        int result = this.resultSet.findColumn(columnLabel);
        return result;
    }

    @Override
    public Reader getCharacterStream(int columnIndex) throws SQLException {
        Reader result = this.resultSet.getCharacterStream(columnIndex);
        return result;
    }

    @Override
    public Reader getCharacterStream(String columnLabel) throws SQLException {
        Reader result = this.resultSet.getCharacterStream(columnLabel);
        return result;
    }

    @Override
    public BigDecimal getBigDecimal(int columnIndex) throws SQLException {
        BigDecimal result = this.resultSet.getBigDecimal(columnIndex);
        return result;
    }

    @Override
    public BigDecimal getBigDecimal(String columnLabel) throws SQLException {
        BigDecimal result = this.resultSet.getBigDecimal(columnLabel);
        return result;
    }

    @Override
    public boolean isBeforeFirst() throws SQLException {
        boolean result = this.resultSet.isBeforeFirst();
        return result;
    }

    @Override
    public boolean isAfterLast() throws SQLException {
        boolean result = this.resultSet.isAfterLast();
        return result;
    }

    @Override
    public boolean isFirst() throws SQLException {
        boolean result = this.resultSet.isFirst();
        return result;
    }

    @Override
    public boolean isLast() throws SQLException {
        boolean result = this.resultSet.isLast();
        return result;
    }

    @Override
    public void beforeFirst() throws SQLException {
        this.resultSet.beforeFirst();
    }

    @Override
    public void afterLast() throws SQLException {
        this.resultSet.afterLast();
    }

    @Override
    public boolean first() throws SQLException {
        boolean result = this.resultSet.first();
        return result;
    }

    @Override
    public boolean last() throws SQLException {
        boolean result = this.resultSet.last();
        return result;
    }

    @Override
    public int getRow() throws SQLException {
        int result = this.resultSet.getRow();
        return result;
    }

    @Override
    public boolean absolute(int row) throws SQLException {
        boolean result = this.resultSet.absolute(row);
        return result;
    }

    @Override
    public boolean relative(int rows) throws SQLException {
        boolean result = this.resultSet.relative(rows);
        return result;
    }

    @Override
    public boolean previous() throws SQLException {
        boolean result = this.resultSet.previous();
        return result;
    }

    @Override
    public void setFetchDirection(int direction) throws SQLException {
        this.resultSet.setFetchDirection(direction);
    }

    @Override
    public int getFetchDirection() throws SQLException {
        int result = this.resultSet.getFetchDirection();
        return result;
    }

    @Override
    public void setFetchSize(int rows) throws SQLException {
        this.resultSet.setFetchSize(rows);
    }

    @Override
    public int getFetchSize() throws SQLException {
        int result = this.resultSet.getFetchSize();
        return result;
    }

    @Override
    public int getType() throws SQLException {
        int result = this.resultSet.getType();
        return result;
    }

    @Override
    public int getConcurrency() throws SQLException {
        int result = this.resultSet.getConcurrency();
        return result;
    }

    @Override
    public boolean rowUpdated() throws SQLException {
        boolean result = this.resultSet.rowUpdated();
        return result;
    }

    @Override
    public boolean rowInserted() throws SQLException {
        boolean result = this.resultSet.rowInserted();
        return result;
    }

    @Override
    public boolean rowDeleted() throws SQLException {
        boolean result = this.resultSet.rowDeleted();
        return result;
    }

    @Override
    public void updateNull(int columnIndex) throws SQLException {
        this.setAttrValueByIndex(columnIndex,null);
        this.resultSet.updateNull(columnIndex);
    }

    @Override
    public void updateBoolean(int columnIndex, boolean x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateBoolean(columnIndex,x);
    }

    @Override
    public void updateByte(int columnIndex, byte x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateByte(columnIndex,x);
    }

    @Override
    public void updateShort(int columnIndex, short x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateShort(columnIndex,x);
    }

    @Override
    public void updateInt(int columnIndex, int x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateInt(columnIndex,x);
    }

    @Override
    public void updateLong(int columnIndex, long x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateLong(columnIndex,x);
    }

    @Override
    public void updateFloat(int columnIndex, float x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateFloat(columnIndex,x);
    }

    @Override
    public void updateDouble(int columnIndex, double x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateDouble(columnIndex,x);
    }

    @Override
    public void updateBigDecimal(int columnIndex, BigDecimal x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateBigDecimal(columnIndex,x);
    }

    @Override
    public void updateString(int columnIndex, String x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateString(columnIndex,x);
    }

    @Override
    public void updateBytes(int columnIndex, byte[] x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateBytes(columnIndex,x);
    }

    @Override
    public void updateDate(int columnIndex, Date x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateDate(columnIndex,x);
    }

    @Override
    public void updateTime(int columnIndex, Time x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateTime(columnIndex,x);
    }

    @Override
    public void updateTimestamp(int columnIndex, Timestamp x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateTimestamp(columnIndex,x);
    }

    @Override
    public void updateAsciiStream(int columnIndex, InputStream x, int length) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateAsciiStream(columnIndex,x,length);
    }

    @Override
    public void updateBinaryStream(int columnIndex, InputStream x, int length) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateBinaryStream(columnIndex,x,length);
    }

    @Override
    public void updateCharacterStream(int columnIndex, Reader x, int length) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateCharacterStream(columnIndex,x,length);
    }

    @Override
    public void updateObject(int columnIndex, Object x, int scaleOrLength) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateObject(columnIndex,x,scaleOrLength);
    }

    @Override
    public void updateObject(int columnIndex, Object x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateObject(columnIndex,x);
    }

    @Override
    public void updateNull(String columnLabel) throws SQLException {
        this.setAttrValueByName(columnLabel,null);
        this.resultSet.updateNull(columnLabel);
    }

    @Override
    public void updateBoolean(String columnLabel, boolean x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateBoolean(columnLabel,x);
    }

    @Override
    public void updateByte(String columnLabel, byte x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateByte(columnLabel,x);
    }

    @Override
    public void updateShort(String columnLabel, short x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateShort(columnLabel,x);
    }

    @Override
    public void updateInt(String columnLabel, int x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateInt(columnLabel,x);
    }

    @Override
    public void updateLong(String columnLabel, long x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateLong(columnLabel,x);
    }

    @Override
    public void updateFloat(String columnLabel, float x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateFloat(columnLabel,x);
    }

    @Override
    public void updateDouble(String columnLabel, double x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateDouble(columnLabel,x);
    }

    @Override
    public void updateBigDecimal(String columnLabel, BigDecimal x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateBigDecimal(columnLabel,x);
    }

    @Override
    public void updateString(String columnLabel, String x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateString(columnLabel,x);
    }

    @Override
    public void updateBytes(String columnLabel, byte[] x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateBytes(columnLabel,x);
    }

    @Override
    public void updateDate(String columnLabel, Date x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateDate(columnLabel,x);
    }

    @Override
    public void updateTime(String columnLabel, Time x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateTime(columnLabel,x);
    }

    @Override
    public void updateTimestamp(String columnLabel, Timestamp x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateTimestamp(columnLabel,x);
    }

    @Override
    public void updateAsciiStream(String columnLabel, InputStream x, int length) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateAsciiStream(columnLabel,x,length);
    }

    @Override
    public void updateBinaryStream(String columnLabel, InputStream x, int length) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateBinaryStream(columnLabel,x,length);
    }

    @Override
    public void updateCharacterStream(String columnLabel, Reader reader, int length) throws SQLException {
        this.setAttrValueByName(columnLabel,reader);
        this.resultSet.updateCharacterStream(columnLabel,reader,length);
    }

    @Override
    public void updateObject(String columnLabel, Object x, int scaleOrLength) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateObject(columnLabel,x,scaleOrLength);
    }

    @Override
    public void updateObject(String columnLabel, Object x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateObject(columnLabel,x);
    }

    @Override
    public void insertRow() throws SQLException {
        this.enforcer("insert");
        this.resultSet.insertRow();
    }

    @Override
    public void updateRow() throws SQLException {

        this.enforcer("update");
        this.resultSet.updateRow();
     // to do enforce this.nxlResultSetAttrList this.tableName action-update
    }

    @Override
    public void deleteRow() throws SQLException {
        this.enforcer("delete");
        this.resultSet.deleteRow();
        // to do enforce this.nxlResultSetAttrList this.tableName action-delete
    }


    @Override
    public void refreshRow() throws SQLException {
        this.resultSet.refreshRow();
        // update current row ,use the db data again  . so we query the result to update the attribute model
        // not know the data type ,give a object data in replace
        try {
            ResultSetMetaData metaData = this.resultSet.getMetaData();
            this.columnCount = metaData.getColumnCount();
            this.nxlResultSetAttrList = new ArrayList<nxlResultSetAttr>();
            for (int index = 1;index<=this.columnCount;index++)
            {
                String columnName = metaData.getColumnName(index);
                String dataType = metaData.getColumnTypeName(index);
                nxlResultSetAttr model = new nxlResultSetAttr(index,columnName,dataType,null);
                this.nxlResultSetAttrList.add(model);
            }
        } catch (SQLException e) {
            nxlEnforcer.SQLEnforcerWriteLog(4,"nxlResultSet.refreshRow " + e.getMessage());
        }
    }

    @Override
    public void cancelRowUpdates() throws SQLException {
        this.resultSet.cancelRowUpdates();
    }

    @Override
    public void moveToInsertRow() throws SQLException {
        this.resultSet.moveToInsertRow();
    }

    @Override
    public void moveToCurrentRow() throws SQLException {
        //??? is need to initialize this.nxlResultSetAttrList or not
        this.resultSet.moveToCurrentRow();
    }

    @Override
    public Statement getStatement() throws SQLException {
        Statement result = this.resultSet.getStatement();
        return result;
    }

    @Override
    public Object getObject(int columnIndex, Map<String, Class<?>> map) throws SQLException {
        Object result = this.resultSet.getObject(columnIndex,map);
        return result;
    }

    @Override
    public Ref getRef(int columnIndex) throws SQLException {
        Ref result = this.resultSet.getRef(columnIndex);
        return result;
    }

    @Override
    public Blob getBlob(int columnIndex) throws SQLException {
        Blob result = this.resultSet.getBlob(columnIndex);
        return result;
    }

    @Override
    public Clob getClob(int columnIndex) throws SQLException {
        Clob result = this.resultSet.getClob(columnIndex);
        return result;
    }

    @Override
    public Array getArray(int columnIndex) throws SQLException {
        Array result = this.resultSet.getArray(columnIndex);
        return result;
    }

    @Override
    public Object getObject(String columnLabel, Map<String, Class<?>> map) throws SQLException {
        Object result = this.resultSet.getObject(columnLabel,map);
        return result;
    }

    @Override
    public Ref getRef(String columnLabel) throws SQLException {
        Ref result = this.resultSet.getRef(columnLabel);
        return result;
    }

    @Override
    public Blob getBlob(String columnLabel) throws SQLException {
        Blob result = this.resultSet.getBlob(columnLabel);
        return result;
    }

    @Override
    public Clob getClob(String columnLabel) throws SQLException {
        Clob result = this.resultSet.getClob(columnLabel);
        return result;
    }

    @Override
    public Array getArray(String columnLabel) throws SQLException {
        Array result = this.resultSet.getArray(columnLabel);
        return result;
    }

    @Override
    public Date getDate(int columnIndex, Calendar cal) throws SQLException {
        Date result = this.resultSet.getDate(columnIndex,cal);
        return result;
    }

    @Override
    public Date getDate(String columnLabel, Calendar cal) throws SQLException {
        Date result = this.resultSet.getDate(columnLabel,cal);
        return result;
    }

    @Override
    public Time getTime(int columnIndex, Calendar cal) throws SQLException {
        Time result = this.resultSet.getTime(columnIndex,cal);
        return result;
    }

    @Override
    public Time getTime(String columnLabel, Calendar cal) throws SQLException {
        Time result = this.resultSet.getTime(columnLabel,cal);
        return result;
    }

    @Override
    public Timestamp getTimestamp(int columnIndex, Calendar cal) throws SQLException {
        Timestamp result = this.resultSet.getTimestamp(columnIndex,cal);
        return result;
    }

    @Override
    public Timestamp getTimestamp(String columnLabel, Calendar cal) throws SQLException {
        Timestamp result = this.resultSet.getTimestamp(columnLabel,cal);
        return result;
    }

    @Override
    public URL getURL(int columnIndex) throws SQLException {
        URL result = this.resultSet.getURL(columnIndex);
        return result;
    }

    @Override
    public URL getURL(String columnLabel) throws SQLException {
        URL result = this.resultSet.getURL(columnLabel);
        return result;
    }

    @Override
    public void updateRef(int columnIndex, Ref x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateRef(columnIndex,x);
    }

    @Override
    public void updateRef(String columnLabel, Ref x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateRef(columnLabel,x);
    }

    @Override
    public void updateBlob(int columnIndex, Blob x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateBlob(columnIndex,x);
    }

    @Override
    public void updateBlob(String columnLabel, Blob x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateBlob(columnLabel,x);
    }

    @Override
    public void updateClob(int columnIndex, Clob x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateClob(columnIndex,x);
    }

    @Override
    public void updateClob(String columnLabel, Clob x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateClob(columnLabel,x);
    }

    @Override
    public void updateArray(int columnIndex, Array x) throws SQLException {
        this.setAttrValueByIndex(columnIndex,x);
        this.resultSet.updateArray(columnIndex,x);
    }

    @Override
    public void updateArray(String columnLabel, Array x) throws SQLException {
        this.setAttrValueByName(columnLabel,x);
        this.resultSet.updateArray(columnLabel,x);
    }

    @Override
    public RowId getRowId(int columnIndex) throws SQLException {
        RowId result = this.resultSet.getRowId(columnIndex);
        return result;
    }

    @Override
    public RowId getRowId(String columnLabel) throws SQLException {
        RowId result = this.resultSet.getRowId(columnLabel);
        return result;
    }

    @Override
    public void updateRowId(int columnIndex, RowId x) throws SQLException {
        this.resultSet.updateRowId(columnIndex,x);
    }

    @Override
    public void updateRowId(String columnLabel, RowId x) throws SQLException {
        this.resultSet.updateRowId(columnLabel,x);
    }

    @Override
    public int getHoldability() throws SQLException {
        int result = this.resultSet.getHoldability();
        return result;
    }

    @Override
    public boolean isClosed() throws SQLException {
        boolean result = this.resultSet.isClosed();
        return result;
    }

    @Override
    public void updateNString(int columnIndex, String nString) throws SQLException {
        this.setAttrValueByIndex(columnIndex,nString);
        this.resultSet.updateNString(columnIndex,nString);
    }

    @Override
    public void updateNString(String columnLabel, String nString) throws SQLException {
        this.setAttrValueByName(columnLabel,nString);
        this.resultSet.updateNString(columnLabel,nString);
    }

    @Override
    public void updateNClob(int columnIndex, NClob nClob) throws SQLException {
        this.setAttrValueByIndex(columnIndex,nClob);
        this.resultSet.updateNClob(columnIndex,nClob);
    }

    @Override
    public void updateNClob(String columnLabel, NClob nClob) throws SQLException {
        this.setAttrValueByName(columnLabel,nClob);
        this.resultSet.updateNClob(columnLabel,nClob);
    }

    @Override
    public NClob getNClob(int columnIndex) throws SQLException {
        NClob result = this.resultSet.getNClob(columnIndex);
        return result;
    }

    @Override
    public NClob getNClob(String columnLabel) throws SQLException {
        NClob result = this.resultSet.getNClob(columnLabel);
        return result;
    }

    @Override
    public SQLXML getSQLXML(int columnIndex) throws SQLException {
        SQLXML result = this.resultSet.getSQLXML(columnIndex);
        return result;
    }

    @Override
    public SQLXML getSQLXML(String columnLabel) throws SQLException {
        SQLXML result = this.resultSet.getSQLXML(columnLabel);
        return result;
    }

    @Override
    public void updateSQLXML(int columnIndex, SQLXML xmlObject) throws SQLException {
        this.setAttrValueByIndex(columnIndex,xmlObject);
        this.resultSet.updateSQLXML(columnIndex,xmlObject);
    }

    @Override
    public void updateSQLXML(String columnLabel, SQLXML xmlObject) throws SQLException {
        this.setAttrValueByName(columnLabel,xmlObject);
        this.resultSet.updateSQLXML(columnLabel,xmlObject);
    }

    @Override
    public String getNString(int columnIndex) throws SQLException {
        String result = this.resultSet.getNString(columnIndex);
        return result;
    }

    @Override
    public String getNString(String columnLabel) throws SQLException {
        String result = this.resultSet.getNString(columnLabel);
        return result;
    }

    @Override
    public Reader getNCharacterStream(int columnIndex) throws SQLException {
        Reader result = this.resultSet.getNCharacterStream(columnIndex);
        return result;
    }

    @Override
    public Reader getNCharacterStream(String columnLabel) throws SQLException {
        Reader result = this.resultSet.getNCharacterStream(columnLabel);
        return result;
    }

    @Override
    public void updateNCharacterStream(int columnIndex, Reader x, long length) throws SQLException {
        this.resultSet.updateNCharacterStream(columnIndex,x,length);
    }

    @Override
    public void updateNCharacterStream(String columnLabel, Reader reader, long length) throws SQLException {
        this.resultSet.updateNCharacterStream(columnLabel,reader,length);
    }

    @Override
    public void updateAsciiStream(int columnIndex, InputStream x, long length) throws SQLException {
        this.resultSet.updateAsciiStream(columnIndex,x,length);
    }

    @Override
    public void updateBinaryStream(int columnIndex, InputStream x, long length) throws SQLException {
        this.resultSet.updateBinaryStream(columnIndex,x,length);
    }

    @Override
    public void updateCharacterStream(int columnIndex, Reader x, long length) throws SQLException {
        this.resultSet.updateCharacterStream(columnIndex,x,length);
    }

    @Override
    public void updateAsciiStream(String columnLabel, InputStream x, long length) throws SQLException {
        this.resultSet.updateAsciiStream(columnLabel,x,length);
    }

    @Override
    public void updateBinaryStream(String columnLabel, InputStream x, long length) throws SQLException {
        this.resultSet.updateBinaryStream(columnLabel,x,length);
    }

    @Override
    public void updateCharacterStream(String columnLabel, Reader reader, long length) throws SQLException {
        this.resultSet.updateCharacterStream(columnLabel,reader,length);
    }

    @Override
    public void updateBlob(int columnIndex, InputStream inputStream, long length) throws SQLException {
        this.resultSet.updateBlob(columnIndex,inputStream,length);
    }

    @Override
    public void updateBlob(String columnLabel, InputStream inputStream, long length) throws SQLException {
        this.resultSet.updateBlob(columnLabel,inputStream,length);
    }

    @Override
    public void updateClob(int columnIndex, Reader reader, long length) throws SQLException {
        this.resultSet.updateClob(columnIndex,reader,length);
    }

    @Override
    public void updateClob(String columnLabel, Reader reader, long length) throws SQLException {
        this.resultSet.updateClob(columnLabel,reader,length);
    }

    @Override
    public void updateNClob(int columnIndex, Reader reader, long length) throws SQLException {
        this.resultSet.updateNClob(columnIndex,reader,length);
    }

    @Override
    public void updateNClob(String columnLabel, Reader reader, long length) throws SQLException {
        this.resultSet.updateNClob(columnLabel,reader,length);
    }

    @Override
    public void updateNCharacterStream(int columnIndex, Reader x) throws SQLException {
        this.resultSet.updateNCharacterStream(columnIndex,x);
    }

    @Override
    public void updateNCharacterStream(String columnLabel, Reader reader) throws SQLException {
        this.resultSet.updateNCharacterStream(columnLabel,reader);
    }

    @Override
    public void updateAsciiStream(int columnIndex, InputStream x) throws SQLException {
        this.resultSet.updateAsciiStream(columnIndex,x);
    }

    @Override
    public void updateBinaryStream(int columnIndex, InputStream x) throws SQLException {
        this.resultSet.updateBinaryStream(columnIndex,x);
    }

    @Override
    public void updateCharacterStream(int columnIndex, Reader x) throws SQLException {
        this.resultSet.updateCharacterStream(columnIndex,x);
    }

    @Override
    public void updateAsciiStream(String columnLabel, InputStream x) throws SQLException {
        this.resultSet.updateAsciiStream(columnLabel,x);
    }

    @Override
    public void updateBinaryStream(String columnLabel, InputStream x) throws SQLException {
        this.resultSet.updateBinaryStream(columnLabel,x);
    }

    @Override
    public void updateCharacterStream(String columnLabel, Reader reader) throws SQLException {
        this.resultSet.updateCharacterStream(columnLabel,reader);
    }

    @Override
    public void updateBlob(int columnIndex, InputStream inputStream) throws SQLException {
        this.resultSet.updateBlob(columnIndex,inputStream);
    }

    @Override
    public void updateBlob(String columnLabel, InputStream inputStream) throws SQLException {
        this.resultSet.updateBlob(columnLabel,inputStream);
    }

    @Override
    public void updateClob(int columnIndex, Reader reader) throws SQLException {
        this.resultSet.updateClob(columnIndex,reader);
    }

    @Override
    public void updateClob(String columnLabel, Reader reader) throws SQLException {
        this.resultSet.updateClob(columnLabel,reader);
    }

    @Override
    public void updateNClob(int columnIndex, Reader reader) throws SQLException {
        this.resultSet.updateNClob(columnIndex,reader);
    }

    @Override
    public void updateNClob(String columnLabel, Reader reader) throws SQLException {
        this.resultSet.updateNClob(columnLabel,reader);
    }

    @Override
    public <T> T getObject(int columnIndex, Class<T> type) throws SQLException {
        T result = this.resultSet.getObject(columnIndex,type);
        return result;
    }

    @Override
    public <T> T getObject(String columnLabel, Class<T> type) throws SQLException {
        T result = this.resultSet.getObject(columnLabel,type);
        return result;
    }

    @Override
    public <T> T unwrap(Class<T> iface) throws SQLException {
        T result = this.resultSet.unwrap(iface);
        return result;
    }

    @Override
    public boolean isWrapperFor(Class<?> iface) throws SQLException {
        boolean result = this.resultSet.isWrapperFor(iface);
        return result;
    }
}
