package emdb;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

import com.alibaba.fastjson.JSONObject;
import com.alibaba.fastjson.serializer.SerializerFeature;

/**
 * 
 * @author Joy
 *
 */
public class EMDBResultReturnJson {
	
    private List<String> columnName = new ArrayList();
    private List<List<Object>> columnValue = new ArrayList();   
    
    
    public static EMDBFileIter MakeFileIter(String strFolder){
        EMDBFileIter file = new EMDBFileIter(strFolder);
        return  file;
    }
    
    public static EMDBTask MakeTask(String strcontent,String strname,String strPath){
        EMDBTask task = new EMDBTask();
        File m_fileDir = new File(strPath);
        
        task.SetName(strname);
        if(null != m_fileDir) {
        	if(m_fileDir.isDirectory()) {
        		task.SetSqlPath(strPath);
        	}else {
        		String path = m_fileDir.getParent();			//Joy
        		task.SetSqlPath(path);
        	}
        }

        task.SetValue(strcontent);
        task.Parse();
        if (!task.Check())
            return null;
        return task;
    }
    
    public static List<Object> getDataConent(String userInfoPropFile, String strFolder, String filePath) {
    	List<Object> executeResultList = null;
        if (strFolder.isEmpty())
        {
            System.out.println("err: floder path is empty");
        }

        EMDBFileIter fit = MakeFileIter(strFolder);
        if (fit == null)
        {
            System.out.println("err: can't open path");
        }
        
        fit.fileInfo(strFolder);
        
        String strName = fit.GetFileName();
        String strContent = fit.GetFileContent();

       
        EMDBTask task = MakeTask(strContent, strName, strFolder);
        if (task == null) {
           System.out.println("err: can't open file-"+strName);
        }

        if (!task.DoPrepare(userInfoPropFile)) {
            System.out.println("err: prepare task error-"+strName);
        }

        boolean flag = true;
        String err = new String();
        for (int i = 0; i < task.GetActionCount(); ++i)
        {
        	EMDBResultSet executeResult = task.Excute(userInfoPropFile, i);
            if (executeResult == null) {
                flag = false;
                err ="ERROR: execute error-index "+i;
                break;
            }
            else {
            	executeResultList = EMDBResultSet.resultList(executeResult);
            	String str =resultSetToJson(executeResultList);// jsonFormat(resultSetToJson(executeResultList));
            	System.out.println(str);
            	createJsonFile(str, filePath+ "_result" + i +".json");
            }
        }

        if (!flag) {
            System.out.println("["+strName+"]"+err);
        }
        else {
            System.out.println("["+strName+"]"+"SUCCEED!");
        }


 	return executeResultList;
    }
    
    public static List<Object> getDataConentDBUser(String strFolder, String filePath) {
    	List<Object> executeResultList = null;
        if (strFolder.isEmpty())
        {
            System.out.println("err: floder path is empty");
        }

        EMDBFileIter fit = MakeFileIter(strFolder);
        if (fit == null)
        {
            System.out.println("err: can't open path");
        }
        
        fit.fileInfo(strFolder);
        
        String strName = fit.GetFileName();
        String strContent = fit.GetFileContent();

        EMDBTask task = MakeTask(strContent, strName, strFolder);
        if (task == null) {
           System.out.println("err: can't open file-"+strName);
        }

        if (!task.DoPrepareDBUser()) {
            System.out.println("err: prepare task error-"+strName);
        }

        boolean flag = true;
        String err = new String();
        for (int i = 0; i < task.GetActionCount(); ++i)
        {
        	EMDBResultSet executeResult = task.ExcuteDBUser(i);
            if (executeResult == null) {
                flag = false;
                err ="ERROR: execute error-index "+i;
                break;
            }
            else {
            	executeResultList = EMDBResultSet.resultList(executeResult);
            	String str =resultSetToJson(executeResultList);// jsonFormat(resultSetToJson(executeResultList));
            	System.out.println(str);
            	createJsonFile(str, filePath+ "_result" + i +".json");
            }
        }

        if (!flag) {
            System.out.println("["+strName+"]"+err);
        }
        else {
            System.out.println("["+strName+"]"+"SUCCEED!");
        }


 	return executeResultList;
    }
    
   
    
	public static String resultSetToJson(List<Object> resultList) {
		JSONObject setObj = new JSONObject();
		JSONObject nameValue =  new JSONObject();

		nameValue.put("PROPERTIES", resultList.get(1));
		nameValue.put("records", resultList.get(2));
		
		int a = 0;
		if(resultList.get(0).equals(true)) {
			a = 1;
		}
		else {
			a = 0;
		}
		setObj.put("RETURN", a);
		setObj.put("RESULT_SET", nameValue);

		
		return setObj.toString(SerializerFeature.PrettyFormat);
	}
	
	private static String getStr(int num) {
		StringBuffer str = new StringBuffer();
		for(int i = 0; i < num; i++) {
			str.append("\t");
		}
		return str.toString();
	}

	public static boolean createJsonFile(String str, String filePath) {
		boolean tag = true;
		
		File file = new File(filePath);
		
		if(!file.getParentFile().exists()) {
			file.getParentFile().mkdirs();
		}
		
		if(file.exists()) {
			file.delete();
		}
		
		try {
			file.createNewFile();
			Writer write = new OutputStreamWriter(new FileOutputStream(file));
			write.write(str);
			write.flush();
			write.close();
			
		} catch (IOException e) {
			tag = false;
			e.printStackTrace();
		}

		return tag;
	}
	
}
