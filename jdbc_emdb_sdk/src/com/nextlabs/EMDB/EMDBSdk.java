package com.nextlabs.EMDB;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



public class EMDBSdk {
    public enum EMDBReturn{ EMDB_SUCCESS, EMDB_ERROR /* todo */, EMDB_INVALID_HANDLE }

    public enum EMDBResultCode{ EMDB_BLOCK_THIS_TEXT, EMDB_USE_NEW_TEXT }

    public static class EMDBUserCtx {
        protected EMDBUserCtx(long c) { this.user_ctx_ = c; }
        private long user_ctx_;
        protected void finalize( ) {
            EMDBSdk.EMDBFreeUserCtx_(user_ctx_);
        }
        public void EMDBSetUserCtxProperty(String key, String value) throws EMDBException {
            EMDBSdk.EMDBSetUserCtxProperty(this.user_ctx_, key, value);
        }
    }

    public static class EMDBResult {
        protected void init(int code, String detail) {
            if (code == EMDBResultCode.EMDB_BLOCK_THIS_TEXT.ordinal()) {
                this.code_ = EMDBResultCode.EMDB_BLOCK_THIS_TEXT;
            }
            else {
                this.code_ = EMDBResultCode.EMDB_USE_NEW_TEXT;
            }
            this.detail_ = detail;
        }
        public EMDBResultCode code() { return this.code_; }
        public String detail() { return this.detail_; }

        private EMDBResultCode code_;
        private String detail_;
    }

    public static class EMDBException extends Exception {
        private EMDBReturn value_;
        private String detail_;

        public EMDBException(EMDBReturn value, String detail) {
            super(detail);
            this.value_=value;
            this.detail_ = detail;
        }

        public EMDBReturn code() { return this.value_; }
        public String detail() { return this.detail_; }
    }

    public static void EMDBInit(String module_name, String config_file_path) throws EMDBException {
        int rc = EMDBInit_(module_name, config_file_path);
        if (rc == EMDBReturn.EMDB_SUCCESS.ordinal()) {
            // success
        }
        else if (rc == EMDBReturn.EMDB_INVALID_HANDLE.ordinal()) {
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        }
        /* extension */
        else {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "UNKNOWN ERROR");
        }
    }

    public static EMDBUserCtx EMDBNewUserCtx(String server_name, String database_name, String schema_name) throws EMDBException {
        if (server_name == null || server_name.length() <= 0 ||
                database_name == null || database_name.length() <= 0 ||
                    schema_name == null || schema_name.length() <= 0) {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "server_name, database_name, schema_name is necessary");
        }
        long ret = EMDBNewUserCtx_(server_name, database_name, schema_name);
        if (ret <= 0) {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "ALLOC USERCTX ERROR");
        }
        return new EMDBUserCtx(ret);
    }

    protected static void EMDBFreeUserCtx(long user_ctx) throws EMDBException {
        int rc = EMDBFreeUserCtx_(user_ctx);
        if (rc == EMDBReturn.EMDB_SUCCESS.ordinal()) {
            // success
        }
        else if (rc == EMDBReturn.EMDB_INVALID_HANDLE.ordinal()) {
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        }
        /* extension */
        else {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "UNKNOWN ERROR");
        }
    }

    protected static void EMDBSetUserCtxProperty(long user_ctx, String key, String value) throws EMDBException {
        int rc = EMDBSetUserCtxProperty_(user_ctx, key, value);
        if (rc == EMDBReturn.EMDB_SUCCESS.ordinal()) {
            // success
        }
        else if (rc == EMDBReturn.EMDB_INVALID_HANDLE.ordinal()) {
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        }
        /* extension */
        else {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "UNKNOWN ERROR");
        }
    }

    protected static void EMDBClearUserCtxProperty(long user_ctx) throws EMDBException {
        int rc = EMDBClearUserCtxProperty_(user_ctx);
        if (rc == EMDBReturn.EMDB_SUCCESS.ordinal()) {
            // success
        }
        else if (rc == EMDBReturn.EMDB_INVALID_HANDLE.ordinal()) {
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        }
        /* extension */
        else {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "UNKNOWN ERROR");
        }
    }

    public static EMDBResult EMDBEvalSql(String sql, EMDBUserCtx user_ctx) throws EMDBException {
        if (user_ctx == null)
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        EMDBResult result = new EMDBResult();
        int rc = EMDBEvalSql_(sql, user_ctx.user_ctx_, result);
        if (rc == EMDBReturn.EMDB_SUCCESS.ordinal()) {
            return result;
        }
        else if (rc == EMDBReturn.EMDB_INVALID_HANDLE.ordinal()) {
            throw new EMDBException(EMDBReturn.EMDB_INVALID_HANDLE, "INVALID HANDLE");
        }
        /* extension */
        else {
            throw new EMDBException(EMDBReturn.EMDB_ERROR, "UNKNOWN ERROR");
        }
    }



    private static native int EMDBInit_(String module_name, String config_file_path);

    private static native long EMDBNewUserCtx_(String server_name, String database_name, String schema_name);

    private static native int EMDBFreeUserCtx_(long user_ctx);

    private static native int EMDBSetUserCtxProperty_(long user_ctx, String key, String value);

    private static native int EMDBClearUserCtxProperty_(long user_ctx);

    private static native int EMDBEvalSql_(String sql, long user_ctx, EMDBResult result);

    public static void main(String[] args) {

    }

    static {
        String path = "";
        try {
            path = readCfgValue("C:\\ProgramData\\Nextlabs\\DAEforWin\\config\\config.ini","GLOBAL","install_path","");
        } catch (IOException e) {
            e.printStackTrace();
        }
        String sys32_64 = System.getProperty("sun.arch.data.model");
        String os = System.getProperty("os.name");
        if (os.toLowerCase().contains("windows")) {
            if(sys32_64.compareTo("64") == 0){
                System.load(path+"\\Common\\bin64\\sqlenforcer.dll");
            }else{
                System.load(path+"\\Common\\bin32\\sqlenforcer.dll");
            }
        }
        else {
            if(sys32_64.compareTo("64") == 0){
                System.load(path+"\\Common\\bin64\\sqlenforcer.so");
            }else{
                System.load(path+"\\Common\\bin32\\sqlenforcer.so");
            }
        }
    }

     /**
     * @param file
     * @param section
     * @param variable
     * @param defaultValue
     * @return value
     * @throws IOException
     */
    private static String readCfgValue(String file, String section, String variable, String defaultValue) throws IOException {
        String strLine, value = "";
        BufferedReader bufferedReader = new BufferedReader(new FileReader(file));
        boolean isInSection = false;
        try {
            while ((strLine = bufferedReader.readLine()) != null) {
                strLine = strLine.trim();
                strLine = strLine.split("[;]")[0];
                Pattern p;
                Matcher m;
                p = Pattern.compile("\\[\\w+]");//Pattern.compile("file://[//s*.*//s*//]");
                m = p.matcher((strLine));
                if (m.matches()) {
                    p = Pattern.compile("\\[" + section + "\\]");//Pattern.compile("file://[//s*" + section + "file://s*//]");
                    m = p.matcher(strLine);
                    if (m.matches()) {
                        isInSection = true;
                    } else {
                        isInSection = false;
                    }
                }
                if (isInSection == true) {
                    strLine = strLine.trim();
                    String[] strArray = strLine.split("=");
                    if (strArray.length == 1) {
                        value = strArray[0].trim();
                        if (value.equalsIgnoreCase(variable)) {
                            value = "";
                            return value;
                        }
                    } else if (strArray.length == 2) {
                        value = strArray[0].trim();
                        if (value.equalsIgnoreCase(variable)) {
                            value = strArray[1].trim();
                            return value;
                        }
                    } else if (strArray.length > 2) {
                        value = strArray[0].trim();
                        if (value.equalsIgnoreCase(variable)) {
                            value = strLine.substring(strLine.indexOf("=") + 1).trim();
                            return value;
                        }
                    }
                }
            }
        } finally {
            bufferedReader.close();
        }
        return defaultValue;
    }
};