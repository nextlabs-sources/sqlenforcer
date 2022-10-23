package emdb;

import java.io.File;

public class EMDBMain {
    public static EMDBFileIter MakeFileIter(String strFolder){
        EMDBFileIter file = new EMDBFileIter(strFolder);
        return  file;
    }
    public static EMDBTask MakeTask(String strcontent,String strname,String strPath){
        EMDBTask task = new EMDBTask();
        task.SetName(strname);
        task.SetSqlPath(strPath);
        task.SetValue(strcontent);
        task.Parse();

        if (!task.Check())
        {
        	System.out.println("err:MakeTask-----Check failed ");
            return null;
        }
        return task;
    }




    public static void AutoRun(String userInfoPropFile, String strFolder){
        if (strFolder.isEmpty())
        {
            System.out.println("err: floder path is empty");
            return;
        }

        EMDBFileIter fit = MakeFileIter(strFolder);
        if (fit == null)
        {
            System.out.println("err: can't open path");
            return;
        }
        while (fit.Next())
        {
            String strName = fit.GetFileName();
            String strContent = fit.GetFileContent();
            EMDBTask task = MakeTask(strContent, strName, strFolder);

            if (task == null) {
               System.out.println("err: can't open file-"+strName);
                continue;
            }

            if (!task.DoPrepare(userInfoPropFile)) {
                System.out.println("err: prepare task error-"+strName);
                continue;
            }

            boolean flag = true;
            String err = new String();
            for (int i = 0; i < task.GetActionCount(); ++i)
            {
                EMDBResultSet expectResult = task.GetExpectResult(i);
                if (expectResult == null) {
                    flag = false;
                    err = "ERROR: read exprect-index "+i;
                    break;
                }
                EMDBResultSet executeResult = task.Excute(userInfoPropFile, i);
                if (executeResult == null) {
                    flag = false;
                    err ="ERROR: execute error-index "+i;
                    break;
                }

                if (!expectResult.CompareWith(executeResult)) {
                    flag = false;
                    err =  "ERROR: execute result is not expect -index "+i;
                    break;
                }


            }

            if (!flag) {
                System.out.println("["+strName+"]"+err);
            }
            else {
                System.out.println("["+strName+"]"+"SUCCEED!");
            }
        }

    }
    
    public static void AutoRunDBuser(String strFolder) {
        if (strFolder.isEmpty()) {
            System.out.println("err: floder path is empty");
            return;
        }

        EMDBFileIter fit = MakeFileIter(strFolder);
        if (fit == null) {
            System.out.println("err: can't open path");
            return;
        }
        while (fit.Next()) {
            String strName = fit.GetFileName();
            String strContent = fit.GetFileContent();

            EMDBTask task = MakeTask(strContent, strName, strFolder);
            if (task == null) {
                System.out.println("err: can't open file-" + strName);
                continue;
            }

            if (!task.DoPrepareDBUser()) {
                System.out.println("err: prepare task error-" + strName);
                continue;
            }

            boolean flag = true;
            String err = new String();
            for (int i = 0; i < task.GetActionCount(); ++i) {
                EMDBResultSet expectResult = task.GetExpectResult(i);
                if (expectResult == null) {
                    flag = false;
                    err = "ERROR: read exprect-index " + i;
                    break;
                }
                EMDBResultSet executeResult = task.ExcuteDBUser(i);
                if (executeResult == null) {
                    flag = false;
                    err = "ERROR: execute error-index " + i;
                    break;
                }

                if (!expectResult.CompareWith(executeResult)) {
                    flag = false;
                    err = "ERROR: execute result is not expect -index " + i;
                    break;
                }


            }

            if (!flag) {
                System.out.println("[" + strName + "]" + err);
            } else {
                System.out.println("[" + strName + "]" + "SUCCEED!");
            }
        }

    }

    public static void main(String[] args) {
        int isze = args.length;

        if (args.length == 0){
            EMDBCustomExecute.toCustomExecute();
        }
        else if(args.length == 1) {
        	String str = args[0];
        	AutoRunDBuser(str);
        }
        else if(args.length == 2) {
        	String path = args[0];
        	String str = args[1];
        	str.toLowerCase();
        	if(path.endsWith(".json") || path.endsWith(".JSON")) {
        		File file = new File(path);
            	String fileName = file.getName();
            	String name = fileName.substring(0, fileName.indexOf("."));
        		EMDBResultReturnJson.getDataConentDBUser(path, str+name);
        	}
        	else if(path.endsWith(".properties")) {
        		AutoRun(path, str);
        	}
        	else {
                System.out.println(isze);
                System.out.println(args[0]);

                System.out.println(args[1]);
                System.out.println("error: param is error");
        	}
        }
        //Joy
        else if(args.length == 3) {
        	String user_path = args[0];
        	String task_path = args[1];
        	File file = new File(task_path);
        	String fileName = file.getName();
        	String name = fileName.substring(0, fileName.indexOf("."));
        	
        	String result_path = args[2];
        	
        	EMDBResultReturnJson.getDataConent(user_path, task_path, result_path + name);
        }
        else {
            System.out.println(isze);
            System.out.println(args[0]);

            System.out.println(args[1]);
            System.out.println("error: param is error");
        }
    }
}
