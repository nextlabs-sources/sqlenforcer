package com.nextlabs.jdbc.hanaproxy;

public class  nxlResultSetAttr<T> {
    private int index;
    private String columnName;
    private String dataType;
    private T value;
    nxlResultSetAttr(int index,String columnName,String dataType,T value)
    {
        this.index = index;
        this.columnName = columnName;
        this.dataType = dataType;
        this.value = value;
    }
    public int getIndex()
    {
        return this.index;
    }
    public String getColumnName()
    {
        return this.columnName;
    }
    public String getDataType()
    {
        return this.dataType;
    }
    public Object getValue()
    {
        return this.value;
    }
    public void setIndex(int index)
    {
        this.index = index;
    }
    public void setColumnName(String columnName)
    {
        this.columnName = columnName;
    }
    public void setDataType(String dataType)
    {
        this.dataType = dataType;
    }
    public void setValue(T value)
    {
        this.value = value;
    }
}
