package com.nextlabs.jdbc.driverproxy;

import java.io.File;
import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;

public class nxlLogger {
    private static final String loggerName = "DAE_driver_jdbc";
    private static final String logFileName = "driver_jdbc.log";
    private static final String logDirForWindows = "C:\\ProgramData\\Nextlabs\\DAEforWin\\log";
    private static final String logDirForLinux = "~/NextLabs/DAEForLinux/jdbc";
    private static volatile nxlLogger instance = null;

    public static nxlLogger getInstance() {
        if (instance == null) {
            synchronized (nxlLogger.class) {
                if (instance == null) {
                    instance = new nxlLogger();
                }
            }
        }

        return instance;
    }

    private nxlLogger() {
        logger = Logger.getLogger(loggerName);
        logger.setUseParentHandlers(false);

        try {
            String defaultLogDir = nxlUtil.isWindows() ? logDirForWindows : logDirForLinux;
            String logDir = nxlUtil.readCfgValue("","LOG","dir_path",defaultLogDir);

            File theDir = new File(logDir);
            if (!theDir.exists()) {
                theDir.mkdirs();
            }

            String logFilePattern = logDir + File.separatorChar + logFileName;

            FileHandler fh = new FileHandler(logFilePattern,true);
            SimpleFormatter sf = new SimpleFormatter();
            fh.setFormatter(sf);
            logger.addHandler(fh);
        } catch (IOException e) {
            System.err.println("Error happened in add FileHandler for logger: " + e.getMessage());
        }

        String logLevel = "3";

        try {
            logLevel= nxlUtil.readCfgValue("","LOG","level","3");
        } catch (IOException e) {
            String errMsg = " ----read config GLOBAL.install_path failed : " + e.getMessage();
            System.err.println(errMsg);
        }

        if(logLevel.equals("-1")){
            logger.setLevel(Level.OFF);
        } else if(logLevel.equals("0")){
            logger.setLevel(Level.FINER);
        } else if(logLevel.equals("1")){
            logger.setLevel(Level.FINE);
        } else if(logLevel.equals("2")){
            logger.setLevel(Level.INFO);
        } else if(logLevel.equals("3")){
            logger.setLevel(Level.WARNING);
        } else if(logLevel.equals("4")){
            logger.setLevel(Level.SEVERE);
        } else if(logLevel.equals("5")){
            logger.setLevel(Level.SEVERE);
        } else {
            logger.setLevel(Level.WARNING);
        }
    }

    public void log(Level level, String msg) {
        logger.log(level, msg);
    }

    private Logger logger = null;
}
