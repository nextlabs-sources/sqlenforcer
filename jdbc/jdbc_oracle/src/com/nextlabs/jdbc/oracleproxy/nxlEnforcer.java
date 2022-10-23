package com.nextlabs.jdbc.oracleproxy;
import java.sql.*;
import java.io.*;
import java.util.logging.*;

public class nxlEnforcer {
    static {
        String cfg_path = "";
        String sys32_64 = System.getProperty("sun.arch.data.model");
        String os = System.getProperty("os.name");
        String filePath = "";
        if (os.toLowerCase().contains("windows")) {
            cfg_path = "C:\\ProgramData\\Nextlabs\\DAEforWin\\config\\config.ini";
            String path = "";

            try {
                path = nxlUtil.readCfgValue("","GLOBAL","install_path","");
            } catch (IOException e) {
                nxlLogger.getInstance().log(Level.SEVERE," ----read config GLOBAL.install_path failed : "+ e.getMessage());
            }
            if(sys32_64.compareTo("64") == 0){
                filePath = path+"\\Common\\bin64\\sqlenforcer.dll";                
            }else{
                filePath = path+"\\Common\\bin32\\sqlenforcer.dll";    
                //System.load(path+"\\Common\\bin32\\sqlenforcer.dll");
            }
        }
        else {
            cfg_path = "/usr/nextlabs/daeforlinux/config/config.ini";
            //cfg_path = "/home/joy_wu/DAEforWin/config/config.ini";
            String path = "";
            try {
                path = nxlUtil.readCfgValue("","GLOBAL","install_path","");

            } catch (IOException e) {
                nxlLogger.getInstance().log(Level.SEVERE," ----read config GLOBAL.install_path failed : "+ e.getMessage());
            }

            if(sys32_64.compareTo("64") == 0){
                filePath = path+"/Common/bin64/libsqlenforcer.so";   
                //System.load(path+"/Common/bin64/libsqlenforcer.so");
            }else{
                filePath = path+"/Common/bin32/libsqlenforcer.so"; 
                //System.load(path+"/Common/bin32/libsqlenforcer.so");
            }
        }

        loadEnforcerDll(filePath);
        try{
           bInited = SQLEnforcerInit("jdbc",cfg_path);
        }catch (Exception e) {
            nxlLogger.getInstance().log(Level.SEVERE," SQLEnforcerInit failed : "+ e.getMessage());
        }
        try{
            String loglevelS = nxlUtil.readCfgValue("","LOG","level","");
            logLevel = Integer.parseInt(loglevelS);
        }catch (Exception e) {
            nxlLogger.getInstance().log(Level.SEVERE," ----read config LOG.level failed : "+ e.getMessage());
        }
        
    }
    public static boolean bInited;
    public static int logLevel ; 

    public static void loadEnforcerDll(String str){
        try{
            File filesource = new File(str);
            Long startTs = System.currentTimeMillis();
            String timestr = String.valueOf(startTs);
            String userHome = System.getProperty("user.home");
            String newpath = userHome;

            if (nxlUtil.isWindows()) {
                newpath += "/AppData/Local/NextLabs";
            } else {
                newpath += "/tmp/NextLabs";
            }

            File newpathF = new File(newpath);
            if (!newpathF.exists()) {
                newpathF.mkdirs();//
            }
            nxlUtil.deleteDirectory(newpath);

            String newFilePath =  newpath + "/temp_dll_" + timestr;

            if (nxlUtil.isWindows()) {
                newFilePath += ".dll";
            } else {
                newFilePath += ".so";
            }

            File filedest = new File(newFilePath);
            if(!filedest.exists()){
                filedest.createNewFile();
            }
            nxlUtil.copyFileUsingFileChannels(filesource,filedest);
            System.load(newFilePath);

        } catch(Throwable t){
            nxlLogger.getInstance().log(Level.SEVERE,"LoadDLL System.load failed in "+ str);
        }
    }

    private native boolean sqlEnforcerInit(String moduleName,String configFile, nxlSqlException exc);
    private native long sqlEnforcerNewContext(String userID,String password, nxlSqlException exc);
    private native void sqlEnforcerFreeContext(String userID);
    //private native nxlEnforcedSqlResult sqlEnforcerEvaluation(long context,String sqlText, nxlSqlException exc);
    private native nxlEnforcedSqlResult sqlEnforcerEvaluationV2(long context,String sqlText, nxlMetaData meta, nxlSqlException exc);
    private native void  sqlEnforcerUserContext(long enforcerContext,int contextType,String contextInfo);
    private native int sqlEnforcerWriteLog(int level,String message);
    private native void sqlAddDBUserInfo(long enforcerContext, String attr, String val);
    private native String decryptString(String src, boolean isdecrypt);

    public static boolean SQLEnforcerInit(String moduleName,String configFile)throws SQLException{
        nxlSqlException exc = new nxlSqlException();
        //System.out.println("CONFIG PATH:"+configFile);
        boolean bRet = new nxlEnforcer().sqlEnforcerInit(moduleName,configFile,exc);
        if( exc.IsException() )
            throw  new SQLException(exc.GetErrorString());
        return bRet;
    }
    public static long SQLEnforcerNewContext(String userID,String password)throws SQLException{
        if(!bInited){
            throw  new SQLException("DAE initialize failed.");
        }
        nxlSqlException exc = new nxlSqlException();
        long lRet = new nxlEnforcer().sqlEnforcerNewContext(userID,password,exc);
        if( exc.IsException() )
            throw  new SQLException(exc.GetErrorString());
        return lRet;
    }
    public static void SQLEnforcerFreeContext(String userID)throws SQLException{
        if(!bInited){
            throw  new SQLException("DAE initialize failed.");
        }
        new nxlEnforcer().sqlEnforcerFreeContext(userID);
    }

    public static nxlEnforcedSqlResult SQLEnforcerEvaluationV2(long context,String sqlText, nxlMetaData meta)throws SQLException{
        if(!bInited){
            throw  new SQLException("DAE initialize failed.");
        }
        nxlSqlException exc = new nxlSqlException();
        nxlEnforcedSqlResult ret =  new nxlEnforcer().sqlEnforcerEvaluationV2(context, sqlText, meta, exc);
        if( exc.IsException() )
            throw  new SQLException(exc.GetErrorString());
        return ret;
    }

    public static void SQLEnforcerUserContext(long enforcerContext,int contextType,String contextInfo)throws SQLException{
        if(!bInited){
            throw  new SQLException("DAE initialize failed.");
        }
        new nxlEnforcer().sqlEnforcerUserContext(enforcerContext,contextType,contextInfo);
    }
    public static int SQLEnforcerWriteLog(int level,String message){
        if(logLevel <= level){
            return new nxlEnforcer().sqlEnforcerWriteLog(level,message);
        } else {
            return 0;
        }
    }

    public static void SQLAddDBUserInfo(long enforcerContext, String attr, String val) {
        new nxlEnforcer().sqlAddDBUserInfo(enforcerContext, attr, val);
    }

    public static String DecryptString( String src, boolean isdecrypt)throws SQLException {
        if(!bInited){
            throw  new SQLException("DAE initialize failed.");
        }
        return new nxlEnforcer().decryptString(src, isdecrypt);
    }


}
