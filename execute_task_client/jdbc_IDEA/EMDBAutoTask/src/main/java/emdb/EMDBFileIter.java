package emdb;
import java.io.*;

import com.alibaba.fastjson.JSONObject;

public class EMDBFileIter {

    EMDBFileIter(String strPath){
        m_fileDir = new File(strPath);
        m_iCurFile = 0;
    }



    boolean Next() {

        if (null != m_fileDir && m_fileDir.isDirectory()) {
            File[] files = m_fileDir.listFiles();
            if (m_iCurFile >= files.length) {
                return false;
            }

            if (null != files) {

                int iIndex = m_iCurFile;
                m_iCurFile++;

                if (!files[iIndex].isDirectory() ) {

                    String strFileName = files[iIndex].getAbsolutePath();
                    if (strFileName.endsWith(".JSON") || strFileName.endsWith(".json")){
                        m_strName = files[iIndex].getName();
                        m_strContent = GetFileContent(strFileName);
                        //return true;
                    }
                    else
                        return Next();
                }
                else
                    return  Next();

            }
        }

        return true;
    }
 
    /**
     * Joy
     * @param path
     */
    public static void fileInfo (String path) {
    	File file = new File(path);

    	if(null != m_fileDir) {
    		String strFileName = file.getAbsolutePath();
    		if (strFileName.endsWith(".JSON") || strFileName.endsWith(".json")){
                m_strName = file.getName();
                m_strContent = GetFileContent(strFileName);
            }
    	}

    }
    
    String GetFileName() {
        return  m_strName;
    }
    String GetFileContent() {
        return m_strContent;
    }

    public static String GetFileContent(String strPath){
        String strRet = new String();
        File file = new File(strPath);
        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader(file));
            String tempString = null;
            int line = 1;
            while ((tempString = reader.readLine()) != null) {

                strRet+=tempString;
                strRet+="\n";
            }
            if(reader != null){
            	reader.close();
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
        return strRet;
    }
    
    /**
     * Joy
     * @param path
     * @return
     */
    
    public static JSONObject getConnectStr(String path) {
    	
    	if (path.isEmpty())
        {
            System.out.println("err: config file path is empty");
        }

    	File file = new File(path);
    	try {
			BufferedReader br = new BufferedReader(
					new FileReader(file));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	if(null != m_fileDir) {
    		String strFileName = file.getAbsolutePath();
    		if (strFileName.endsWith(".JSON") || strFileName.endsWith(".json")){
                m_strName = file.getName();
                m_strContent = GetFileContent(strFileName);
            }
    	}
    	
    	JSONObject jsodj = JSONObject.parseObject(m_strContent);
        return jsodj;
    }

    static File m_fileDir;
    int m_iCurFile;
    static String m_strName;
    static String m_strContent;
}
