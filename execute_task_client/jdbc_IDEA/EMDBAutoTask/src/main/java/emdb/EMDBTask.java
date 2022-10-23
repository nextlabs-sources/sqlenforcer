package emdb;

import java.io.File;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.sql.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import com.alibaba.fastjson.util.TypeUtils;

class TASK_Prepare{
    TASK_Prepare(){
        strSql = new String();
        connect = null;
    }
    String strSql;
    EMDBConnectInfo connect;
}

class Task_Action{
    Task_Action(){
        strSql = new String();
        connect = null;
        result = null;
    }
    String strSql;
    EMDBConnectInfo connect;
    EMDBResultSet result;
}

public class EMDBTask {
    public EMDBTask(){
        m_taskPrepare = new TASK_Prepare();
        m_listAction = new ArrayList<>();
    }

    boolean DoPrepare(String userInfoPropFile){
        if (m_taskPrepare.connect == null)
            return false;
        try {
            m_taskPrepare.connect.Connect(userInfoPropFile);
        }catch (ClassNotFoundException e){
            System.out.println("err: do prepare load driver-"+e.getMessage());
            return  false;
        }catch (SQLException e){
            System.out.println("err:do prepare failed-"+e.getMessage());
            return  false;
        }
        //ResultSet result
        try {
        	
            ResultSet result = m_taskPrepare.connect.Execute(m_taskPrepare.strSql);
            if(result != null) {
                result.close();
            }

        }catch (SQLException e){

            System.out.println("err:do prepare Execute failed-"+e.getMessage());
            return  false;
        }
        try {
            m_taskPrepare.connect.Close();
        }catch (SQLException e1){}
        return true;
    }
    
    boolean DoPrepareDBUser(){
        if (m_taskPrepare.connect == null)
            return false;
        try {
            m_taskPrepare.connect.ConnectDBUser();
        }catch (ClassNotFoundException e){
            System.out.println("err: do prepare load driver-"+e.getMessage());
            return  false;
        }catch (SQLException e){
            System.out.println("err:do prepare failed-"+e.getMessage());
            return  false;
        }
        //ResultSet result
        try {
        	
            ResultSet result = m_taskPrepare.connect.Execute(m_taskPrepare.strSql);

            if(result != null) {
                result.close();
            }

        }catch (SQLException e){

            System.out.println("err:do prepare Execute failed-"+e.getMessage());
            return  false;
        }
        try {
            m_taskPrepare.connect.Close();
        }catch (SQLException e1){}
        return true;
    }
    int GetActionCount(){
        return m_listAction.size();
    }
    EMDBResultSet Excute(String userInfoPropFile, int index){
        if (index > m_listAction.size())
            return null;
        EMDBConnectInfo connect = m_listAction.get(index).connect;

        try {
            connect.Connect(userInfoPropFile);
        }catch (ClassNotFoundException e){
            System.out.println("err: "+e.getMessage()+" at index"+index+" action0");
            return  null;
        }catch (SQLException e){
            System.out.println("err:"+e.getMessage()+" at index"+index+" action1");
            return  null;
        }
        //ResultSet result = new
        EMDBResultSet resultSet = new EMDBResultSet();
        try {
            ResultSet result =  connect.Execute(m_listAction.get(index).strSql);

            resultSet.Push_Ret(true);
            if (result != null){
                ResultSetMetaData rsmd = result.getMetaData();
                for (int i = 1; i <= rsmd.getColumnCount() ; i++) {

                    resultSet.Push_Header(rsmd.getColumnName(i));
                }

                while (result.next())
                {
                    int iSize = rsmd.getColumnCount();
                    List<Record> list = new ArrayList<>();
                    resultSet.Push_Record(list);
                    for(int i = 1 ; i <= iSize; ++i){
                        int iType = rsmd.getColumnType(i);
                        Record record = null;
                        switch(iType)
                        {

                            case java.sql.Types.NUMERIC:
                            case java.sql.Types.DECIMAL:
                            case java.sql.Types.REAL:
                            case java.sql.Types.FLOAT:
                            case java.sql.Types.DOUBLE: {
                                double dValue = result.getDouble(i );
                                record = new RecordD(dValue);
                                break;
                            }
                            case  java.sql.Types.TINYINT:
                            case  java.sql.Types.SMALLINT:
                            case  java.sql.Types.INTEGER:
                            case  java.sql.Types.BIGINT:
                            {
                                int iValue = result.getInt(i );
                                record = new RecordI(iValue);
                                break;
                            }
                            case  java.sql.Types.DATE: {
                                Date temp = result.getDate(i );
                                String sValue = temp.toString();
                                record = new RecordS(sValue);
                                break;
                            }
                            case  java.sql.Types.TIME: {
                                Time temp = result.getTime(i );
                                String sValue = temp.toString();
                                record = new RecordS(sValue);
                                break;
                            }
                            case  java.sql.Types.TIMESTAMP: {
                                Timestamp temp = result.getTimestamp(i );
                                String sValue = temp.toString();
                                sValue = sValue.substring(0, 19);
                                record = new RecordS(sValue);
                                break;
                            }
                            case  java.sql.Types.ARRAY: {
                                Array temp = result.getArray(i);
                                Object[] iValue = (Object[]) temp.getArray();
                                String sValue = Arrays.toString(iValue);
                                record = new RecordS(sValue);
                                break;
                            }
                            
                            default: {
                                String sValue = result.getString(i);
                                record = new RecordS(sValue);
                            }

                        }
                        if (result.wasNull()){
                            list.add(new RecordNull());
                        }else{
                            list.add(record);
                        }
                    }
                    assert (list.size() == iSize);
                }
            }
            
            if(result != null) {
                result.close();
            }

        }catch (SQLException e){
            System.out.println("err:"+e.getMessage()+" at index"+index+" action");


            resultSet.Push_Ret(false);

        }
        try {
            connect.Close();
        }catch (SQLException e1){
            // TODO: What?
        }

        return  resultSet;

    }
    
    EMDBResultSet ExcuteDBUser(int index){
        if (index > m_listAction.size())
            return null;
        EMDBConnectInfo connect = m_listAction.get(index).connect;

        try {
            connect.ConnectDBUser();
        }catch (ClassNotFoundException e){
            System.out.println("err: "+e.getMessage()+" at index"+index+" action0");
            return  null;
        }catch (SQLException e){
            System.out.println("err:"+e.getMessage()+" at index"+index+" action1");
            return  null;
        }

        EMDBResultSet resultSet = new EMDBResultSet();
        try {
            ResultSet result =  connect.Execute(m_listAction.get(index).strSql);

            resultSet.Push_Ret(true);
            if (result != null){
                ResultSetMetaData rsmd = result.getMetaData();
                for (int i = 1; i <= rsmd.getColumnCount() ; i++) {

                    resultSet.Push_Header(rsmd.getColumnName(i));
                }

                while (result.next())
                {
                    int iSize = rsmd.getColumnCount();
                    List<Record> list = new ArrayList<>();
                    resultSet.Push_Record(list);
                    for(int i = 1 ; i <= iSize; ++i){
                        int iType = rsmd.getColumnType(i);
                        Record record = null;
                        switch(iType)
                        {

                            case java.sql.Types.NUMERIC:
                            case java.sql.Types.DECIMAL:
                            case java.sql.Types.REAL:
                            case java.sql.Types.FLOAT:
                            case java.sql.Types.DOUBLE: {
                                double dValue = result.getDouble(i );
                                record = new RecordD(dValue);
                                break;
                            }
                            case  java.sql.Types.TINYINT:
                            case  java.sql.Types.SMALLINT:
                            case  java.sql.Types.INTEGER:
                            case  java.sql.Types.BIGINT:
                            {
                                int iValue = result.getInt(i );
                                record = new RecordI(iValue);
                                break;
                            }
                            case  java.sql.Types.DATE: {
                                Date temp = result.getDate(i );
                                String sValue = temp.toString();
                                record = new RecordS(sValue);
                                break;
                            }
                            case  java.sql.Types.TIME: {
                                Time temp = result.getTime(i );
                                String sValue = temp.toString();
                                record = new RecordS(sValue);
                                break;
                            }
                            case  java.sql.Types.TIMESTAMP: {
                                Timestamp temp = result.getTimestamp(i );
                                String sValue = temp.toString();
                                sValue = sValue.substring(0, 19);
                                record = new RecordS(sValue);
                                break;
                            }
                            
                            case  java.sql.Types.ARRAY: {
                                Array temp = result.getArray(i);
                                Object[] iValue = (Object[]) temp.getArray();
                                String sValue = Arrays.toString(iValue);
                                record = new RecordS(sValue);
                                break;
                            }
                            
                            default: {
                                String sValue = result.getString(i);
                                record = new RecordS(sValue);
                            }

                        }
                        if (result.wasNull()){
                            list.add(new RecordNull());
                        }else{
                            list.add(record);
                        }
                    }
                    assert (list.size() == iSize);
                }
            }
            
            if(result != null) {
                result.close();
            }

        }catch (SQLException e){
            System.out.println("err:"+e.getMessage()+" at index"+index+" action");


            resultSet.Push_Ret(false);

        }
        try {
            connect.Close();
        }catch (SQLException e1){}

        return  resultSet;

    }
    
    EMDBResultSet GetExpectResult( int index){
        if (index > m_listAction.size())
            return null;
        return  m_listAction.get(index).result;
    }
    String GetTaskName(){
        return m_strTaskName;
    }


    void SetName(String str) {
        m_strTaskName = str;
    }
    void SetValue(String str){
        m_strValue = str;
    }
    void SetSqlPath(String str){
        m_strSqlPath = str;
    }
 

    
    
    
    //Joy
    public static final String separator = File.separator;

    
    void Parse(){
        if (m_strValue.isEmpty())
            return;
        JSONObject jsroot = JSONObject.parseObject(m_strValue);
        if (jsroot == null)
            return;
        JSONObject JSPREPARE = jsroot.getJSONObject("PREPARE");
        if (JSPREPARE == null)
            return;
        m_taskPrepare.strSql = EMDBFileIter.GetFileContent(m_strSqlPath + separator + JSPREPARE.getString("SQL_PATH"));

        JSONObject connstr = EMDBFileIter.getConnectStr(m_strSqlPath + separator + "config" + separator + "connectStr_config.json");

        JSONObject JSCONNECT = null;
        String prepareStrValue = JSPREPARE.getString("JDBC_CONNECT_PROP");
        String prepare_connect_str = connstr.getString(prepareStrValue);
        if( prepare_connect_str != null) {
        	JSCONNECT = connstr.getJSONObject(prepareStrValue).getJSONObject("JDBC_CONNECT_PROP");
        }
        else {
        	System.out.println("Error: Failed to find the related prepare connect_str");
        }

        m_taskPrepare.connect = new EMDBConnectInfo(
                JSCONNECT.getString("username"),
                JSCONNECT.getString("password"),
                JSCONNECT.getString("driverName"),
                JSCONNECT.getString("url")
        );

        JSONArray JSAction = jsroot.getJSONArray("ACTION");
        int iLenAct = JSAction.size();
        for (int i = 0 ; i < iLenAct;++i){
            Task_Action act = new Task_Action();
            m_listAction.add(act);
            JSONObject JSAct = JSAction.getJSONObject(i);

            act.strSql = EMDBFileIter.GetFileContent(m_strSqlPath + separator + JSAct.getString("SQL_PATH"));	//Joy: to run in Windows and Linux
            
            
            JSONObject JSActCONNECT = null;
            
            String actionStrValue = JSAct.getString("JDBC_CONNECT_PROP");
            String connect_str = connstr.getString(actionStrValue);
            if( connect_str != null) {
            	JSActCONNECT = connstr.getJSONObject(actionStrValue).getJSONObject("JDBC_CONNECT_PROP");
            }
            else {
            	System.out.println("Error: Failed to find the related action" + i + " connect_str");
            }

            act.connect = new EMDBConnectInfo(
                    JSActCONNECT.getString("username"),
                    JSActCONNECT.getString("password"),
                    JSActCONNECT.getString("driverName"),
                    JSActCONNECT.getString("url")
            );
            EMDBResultSet result =  new EMDBResultSet();
            act.result = result;
            JSONObject JSActExpect = JSAct.getJSONObject("EXPECT_RET");
            JSONObject JSActResult = JSActExpect.getJSONObject("RESULT_SET");
            result.Push_Ret(JSActExpect.getInteger("RETURN")==1?true:false);

            if (JSActResult != null){
                JSONArray arrProperties = JSActResult.getJSONArray("PROPERTIES");
                for (int j = 0 ; j < arrProperties.size();++j){
                    result.Push_Header(arrProperties.getString(j));
                }

                JSONArray arrRecords = JSActResult.getJSONArray("records");
                if (arrRecords != null){
                    for (int j = 0 ; j < arrRecords.size();++j){
                        JSONArray records = arrRecords.getJSONArray(j);
                        if (records == null)
                            continue;
                        List<Record> list = new ArrayList<>();
                        result.Push_Record(list);
                        for (int k = 0 ; k < records.size(); ++k){
                            Object obj = records.get(k);
                            if (obj == null){
                                list.add(new RecordNull());
                            }
                            else if (obj instanceof Integer || obj instanceof Short||obj instanceof BigInteger){
                                int iValue = TypeUtils.castToInt(obj);
                                list.add(new RecordI(iValue));
                            }
                            else if (obj instanceof BigDecimal || obj instanceof Double || obj instanceof Float){
                                double dValue = TypeUtils.castToDouble(obj);
                                list.add(new RecordD(dValue));
                            }
                            else {
                                String sValue = TypeUtils.castToString(obj);
                                list.add(new RecordS(sValue));
                            }
                        }

                    }
                }

            }

        }



    }
    public String GetStrSql()
    {
    	return m_taskPrepare.strSql;
    }
    boolean Check(){
        if (m_taskPrepare.strSql.isEmpty())
        {
        	System.out.println("check------1 , content:"+m_taskPrepare.strSql);
            return  false;
        }
        if (m_taskPrepare.connect == null)
        {
        	System.out.println("check------2");
            return  false;
        }
        if (m_listAction.size() <= 0)
        {
        	System.out.println("check------3");
            return  false;
        }
        for (int i = 0 ; i < m_listAction.size(); ++i){
            Task_Action t = m_listAction.get(i);
            if (t == null)
            {
            	System.out.println("check------4");
                return false;
            }
            if (t.strSql.isEmpty())
            {
            	System.out.println("check------5");
                return false;
            }
            if (t.connect == null)
            {
            	System.out.println("check------6");
                return  false;
            }
            if (t.result == null)
            {
            	System.out.println("check------7");
                return  false;
            }
        }
        return  true;

    }

    String m_strTaskName;
    String m_strValue;
    String m_strSqlPath;

    TASK_Prepare m_taskPrepare;
    List<Task_Action> m_listAction;
}
