package emdb;

import java.io.*;
import java.sql.*;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Map.Entry;

class ColumnValue {
    public ColumnValue() {
        arrValue = new ArrayList<String>();
        iType = 0;
    }
    public String columnName;
    public int iType;
    public List<String> arrValue;
}
class LoadProperties{
    public LoadProperties()  {
        String path = this.getClass().getProtectionDomain().getCodeSource().getLocation().getPath();
        int lastIndex = path.lastIndexOf('/') + 1;
        path = path.substring(0, lastIndex);
        path += "jdbcConfig.properties";

        try {
            InputStream inputStream= new BufferedInputStream(new FileInputStream(path));
            properties=new Properties();
            properties.load(inputStream);
        }catch(Exception e){
            e.printStackTrace();
        }

        url= properties.getProperty("url");
        username = properties.getProperty("username");
        password = properties.getProperty("password");
        driverName = properties.getProperty("driverName");
    };
    private Properties properties;
    public String url;
    public String username;
    public String password;
    public String driverName;
}

/**
 * @author joy
 */
class LoadUserProperties{
    public static Properties loadUserProperties(String path)  {
        Properties oriProperties;
        Properties newProperties = new Properties();
        Map<String, String> resultMap = new HashMap<String, String>();
        try {
            InputStream inputStream= new BufferedInputStream(new FileInputStream(path));
            oriProperties=new Properties();
            oriProperties.load(inputStream);

            for (String key : oriProperties.stringPropertyNames()) {
                resultMap.put(key, oriProperties.getProperty(key));
            }

            for (Entry<String, String> entry : resultMap.entrySet()) {
                newProperties.put(entry.getKey(), entry.getValue());
            }
        }catch(Exception e){
            e.printStackTrace();
        }
        return newProperties;
    }
    

}

public class EMDBCustomExecute{

    private static final int QUERYSQL = 1;
    private static final int UPDATESQL = 2;
    private static final int EXECUTESQL = 3;
    private static List<ColumnValue> listColumnValue = new ArrayList<ColumnValue>();

    public static void toCustomExecute()  {
        try {
            LoadProperties property = new LoadProperties();
            
            //link driver
            Class.forName(property.driverName);
            //connect server
            Connection con = DriverManager.getConnection(property.url,property.username,property.password);
            System.out.println("connect secceed!");

            System.out.println(" MENU:");
            System.out.println(" QUIT/Q                  exit program");
            System.out.println(" QUERYSQL                1:use to query");
            System.out.println(" UPDATESQL               2:use to update");
            System.out.println(" EXECUTESQL              3:use to execute SQL");
            System.out.println(" PREPARE/CLOSEPREPARE    use PrepareStatement/Statement");
            System.out.println(" SETUSER file			 set user attr + properties filepath");
            Scanner sc = new Scanner(System.in);
            int iPolicy = EXECUTESQL;
            boolean bPrepareState = false;

            while(true)
            {
                try {
                    String strValue;
                    if (iPolicy == 1){
                        System.out.println("*Use to query");
                    }
                    else if (iPolicy == 2){
                        System.out.println("*Use to update");
                    }else{
                        System.out.println("*Use to execute SQL");
                    }

                    System.out.println(bPrepareState?"*Use PrepareStatement*":"*Use Statement");
                    System.out.println("Please Input Command/SQL:");
                    listColumnValue.removeAll(listColumnValue);
                    strValue = sc.nextLine();
                    String path;
                    
                    if(strValue.isEmpty())
                    {
                        continue;
                    }

                    if(strValue.compareToIgnoreCase("QUIT") == 0||strValue.compareToIgnoreCase("Q") == 0) {
                        con.close();
                        break;
                    }
                    else if(strValue.compareToIgnoreCase("QUERYSQL") == 0){
                        iPolicy = QUERYSQL;
                        continue;
                    }
                    else if(strValue.compareToIgnoreCase("UPDATESQL") == 0){
                        iPolicy = UPDATESQL;
                        continue;
                    }
                    else if(strValue.compareToIgnoreCase("EXECUTESQL") == 0){
                        iPolicy = EXECUTESQL;
                        continue;
                    }
                    else if(strValue.compareToIgnoreCase("PREPARE") == 0){
                        bPrepareState = true;
                        continue;
                    }else if(strValue.compareToIgnoreCase("CLOSEPREPARE") == 0){
                        bPrepareState = false;
                        continue;
                    }
                    
                    //Joy
                    else if(strValue.toUpperCase().contains("SETUSER")) {
                    	path = strValue.substring(strValue.lastIndexOf(" ") + 1);
                    	con.setClientInfo(LoadUserProperties.loadUserProperties(path));
                    	continue;
                    }
                    else{
                        int lastIndex = strValue.lastIndexOf(".") ;
                        if (lastIndex > 0) {
                            String stemp = strValue.substring(lastIndex);
                            if (stemp.equalsIgnoreCase(".sql")){
                                strValue = EMDBFileIter.GetFileContent(strValue);
                            }
                        }

                        switch(iPolicy)
                        {
                            case 1:
                            {
                                if(bPrepareState) {
                                    PreparedStatement statement = con.prepareStatement(strValue);
                                    statement.executeQuery();
                                    ResultSet rs = statement.getResultSet();
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }
                                    if(statement != null) {
                                    	statement.close();
                                    }
                                    
                                }
                                else {
                                    Statement statement = con.createStatement();
                                    ResultSet rs = statement.executeQuery(strValue);
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }
                                    if(statement != null) {
                                    	statement.close();
                                    }
                                }

                            }
                            break;
                            case 2:
                            {
                                if(bPrepareState) {
                                    PreparedStatement statement = con.prepareStatement(strValue);
                                    statement.executeUpdate();
                                    ResultSet rs = statement.getResultSet();
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }
                                    if(statement != null) {
                                    	statement.close();
                                    }
                                }else {
                                    Statement statement = con.createStatement();
                                    statement.executeUpdate(strValue);
                                    ResultSet rs = statement.getResultSet();
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }

                                    if(statement != null) {
                                    	statement.close();
                                    }
                                }

                            }
                            break;

                            case 3:
                            {
                                if(bPrepareState) {
                                    PreparedStatement statement = con.prepareStatement(strValue);
                                    statement.execute();
                                    ResultSet rs = statement.getResultSet();
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }
                                    if(statement != null) {
                                    	statement.close();
                                    }
                                }else {
                                    Statement statement = con.createStatement();
                                    statement.execute(strValue);
                                    ResultSet rs = statement.getResultSet();
                                    if(rs != null) {
                                        PushValue(rs);
                                        rs.close();
                                    }
                                    if(statement != null) {
                                    	statement.close();
                                    }
                                }

                            }
                            break;
                        }

                        ShowValue();
                    }

                }
                catch(SQLException e) {
                    System.out.println(e.getCause());
                    System.out.println(e.getMessage());
                }
            }
            con.close();
            sc.close();
        }
        catch(SQLException e) {
            e.printStackTrace();
        }  catch(ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    private static boolean PushValue(ResultSet rs) {
        try {
            ResultSetMetaData rsmd = rs.getMetaData();
            for (int i = 1; i < rsmd.getColumnCount() + 1; i++) {

                ColumnValue columnModel = new ColumnValue();
                columnModel.iType =   rsmd.getColumnType(i) ;
                columnModel.columnName = rsmd.getColumnName(i).toLowerCase();

                listColumnValue.add(columnModel);
            }
            String s = new String(" ");
            while (rs.next())
            {
                int iSize = listColumnValue.size();

                for(int i = 0 ; i < iSize; ++i){
                    ColumnValue columnModel = listColumnValue.get(i);
                    int iType = columnModel.iType;
                    
                    if(iType == 2003) {
                    	Array temp = rs.getArray(i+1);
                        Object[] iValue = (Object[]) temp.getArray();
                        s = Arrays.toString(iValue);
                    }
                    else {
                    	s = rs.getString(i+1);
                    }                
                	
                    if (rs.wasNull()) {
                		s = "  ";
                	}
                    columnModel.arrValue.add(s);
                }
            }
        }catch(Exception e) {
            e.printStackTrace();
        }

        return true;
    }
    private static final int MAXWIDTH = 24;// field width max
    
    private static boolean ShowValue() {
        int colSize  = listColumnValue.size();
        int rowSize = 0;
        if(colSize > 0)
        {
            ColumnValue columnModel = listColumnValue.get(0);
            rowSize = columnModel.arrValue.size();
            
        }
        else
        {
            System.out.print("-----------There is no output !-------------\n");
        }

        for(int i = 0 ; i < colSize; ++i)
        {
            System.out.print("-");
            for(int k = 0 ; k < MAXWIDTH;++k) {
                System.out.print("-");
            }
            System.out.print("-");
        }
        System.out.print("\n");

        //field
        for(int j = 0 ; j < colSize; ++j) {
            System.out.print("|");
            ColumnValue columnV = listColumnValue.get(j);
            int iLen = columnV.columnName.length();
            if(iLen > MAXWIDTH) {
                System.out.print(columnV.columnName.substring(0, MAXWIDTH-3));
                System.out.print("...");

            }else {
                System.out.print(columnV.columnName);
                for(int k = 0 ; k < MAXWIDTH-iLen;++k) {
                    System.out.print(" ");
                }
            }
            System.out.print("|");
        }
        System.out.print("\n");

        for(int i = 0 ; i < colSize; ++i)
        {
            System.out.print("|");
            for(int k = 0 ; k < MAXWIDTH;++k) {
                System.out.print("-");
            }
            System.out.print("|");
        }
        System.out.print("\n");
        //content
        
        for(int i = 0 ; i < rowSize; ++i) {
        	
            for(int j = 0 ; j < colSize; ++j) {
            	
                System.out.print("|");
                ColumnValue columnV = listColumnValue.get(j);
                String strV = columnV.arrValue.get(i);
                
                if(strV == null )
                    strV = "-null-";

                int iLen = strV.length();
                
                if(iLen > MAXWIDTH) {
                    System.out.print(strV.substring(0, MAXWIDTH-3));
                    System.out.print("...");
                    

                }else {
                	
                    System.out.print(strV);
                    for(int k = 0 ; k < MAXWIDTH-iLen;++k) {
                        System.out.print(" ");
                    }
                }
                System.out.print("|");
            }
            System.out.print("\n");

        }
        //footer line
        for(int i = 0 ; i < colSize; ++i)
        {
            System.out.print("-");
            for(int k = 0 ; k < MAXWIDTH;++k) {
                System.out.print("-");
            }
            System.out.print("-");
        }
        System.out.print("\n");

        return true;
    }
}




