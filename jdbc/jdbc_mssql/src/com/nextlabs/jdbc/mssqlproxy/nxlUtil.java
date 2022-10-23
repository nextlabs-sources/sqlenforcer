package com.nextlabs.jdbc.mssqlproxy;

import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.nio.channels.FileChannel;
import java.util.logging.*;

public class nxlUtil {
    public static boolean isLinux() {
        String osName = System.getProperty("os.name").toLowerCase();
        return osName.contains("linux");
    }

    public static boolean isWindows() {
        String osName = System.getProperty("os.name").toLowerCase();
        return osName.contains("windows");
    }

    public static String readCfgValue(String file, String section, String variable, String defaultValue) throws IOException {
        String cfg_path = "";
        String os = System.getProperty("os.name");
        if (os.toLowerCase().contains("windows")) {
            cfg_path = "C:\\ProgramData\\Nextlabs\\DAEforWin\\Config\\config.ini";
        }
        else {
            cfg_path = "/usr/nextlabs/daeforlinux/config/config.ini";
            //cfg_path = "/home/joy_wu/DAEforWin/config/config.ini";/*todo this need modify */
        }

        String strLine, value = "";
        int lineNumber = 0;
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(cfg_path),"UTF-8"));
        boolean isInSection = false;
        try {
            while ((strLine = bufferedReader.readLine()) != null) {
                ++lineNumber;

                if (1 == lineNumber) {
                    strLine = removeUTF8BOM(strLine);
                }
                
                String strLine1 = strLine.trim();
                if(strLine1.length() <= 1){
                    continue;
                }
                strLine = strLine1.split("[;]")[0];

                if(!strLine.isEmpty()){
                    strLine = strLine1;
                } else {
                    continue;
                }

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

    private static String removeUTF8BOM(String s) {
        // FEFF because this is the Unicode char represented by the UTF-8 byte order mark (EF BB BF).
        final String UTF8_BOM = "\uFEFF";

        if (s.startsWith(UTF8_BOM)) {
            s = s.substring(1);
        }

        return s;
    }

    public static void copyFileUsingFileChannels(File source, File dest) throws IOException {
        FileChannel inputChannel = null;
        FileChannel outputChannel = null;
        try {
            inputChannel = new FileInputStream(source).getChannel();
            outputChannel = new FileOutputStream(dest).getChannel();
            outputChannel.transferFrom(inputChannel, 0, inputChannel.size());
        } finally {
            inputChannel.close();
            outputChannel.close();
        }
    }

    public static boolean deleteFile(String fileName) {
        try {
            File file = new File(fileName);
            if (file.exists() && file.isFile()) {
                if(file.delete()){
                    //nxlUtil.loger.log(Level.INFO,"deleted file:"+fileName);   
                }
            }
        } catch (Exception e){
            nxlLogger.getInstance().log(Level.SEVERE, "deleteFile failed:"+e.getMessage());
        }
        return true;

    }

    public static boolean deleteDirectory(String dir) {
        if (!dir.endsWith(File.separator))
            dir = dir + File.separator;
        File dirFile = new File(dir);
        if ((!dirFile.exists()) || (!dirFile.isDirectory())) {
            return false;
        }
        boolean flag = true;
        //
        File[] files = dirFile.listFiles();
        for (int i = 0; i < files.length; i++) {
            //
            if (files[i].isFile()) {
                boolean tflag = deleteFile(files[i].getAbsolutePath());
                if (tflag) flag = tflag;
            }
            //
            else if (files[i].isDirectory()) {
                boolean tflag = deleteDirectory(files[i]
                        .getAbsolutePath());
                if (tflag) flag = tflag;
            }
        }
        return flag;
    }


}
