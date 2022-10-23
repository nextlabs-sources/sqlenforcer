package com.nextlabs.jdbc.driverproxy;
import java.sql.*;
import java.io.IOException;
public class nxlSqlException {
    private int iCode;
    private String strDetail;

 

    nxlSqlException()
    {
        this.iCode = ERR_NULL;
        this.strDetail = "";
    }
    public void SetInfo(int code, String detail) {
        this.iCode = code;
        this.strDetail = detail;
    }
    public boolean IsException(){
        return iCode!=ERR_NULL?true:false;
    }
    public String GetErrorString(){
        return "["+iCode+"]"+strDetail;
    }

    public static final int ERR_NULL = 0;
    public static final int ERR_EVALUATION_BLOCK = 42000;
	public static final int ERR_CONFIG = 42001;
	public static final int ERR_LIBRARY = 42002;
    public static final int ERR_POLICY = 42003;
	public static final int ERR_INITCONTEXT = 42004;
    public static final int ERR_USERINFO = 42005;
    public static final int ERR_PARSE = 42006;
}
