package com.nextlabs.jdbc.oracleproxy;

import java.sql.*;
import java.util.Map;
import java.util.Properties;
import java.util.concurrent.Executor;
import java.util.logging.*;

public class nxlUserAttr extends  Thread  {
    public volatile boolean exit = false;
    private String url;
    private String userName;
    private long enforcerContext;
    private String table;
    private Properties _con_attr;

    public nxlUserAttr(String url,String user, long enforce, Properties con_attr) {
        this.url = url;
        this.userName = user;
        this.enforcerContext = enforce;
        this._con_attr = con_attr;
    } 

    @Override
    public void run() {        
        try{
            
            String mode_p4 = nxlUtil.readCfgValue("","USERMODE","sync_time","");
            long iref = 1;

            try {
                iref = Integer.parseInt(mode_p4);
            } catch (Exception exc) {
                nxlEnforcer.SQLEnforcerWriteLog(3,"nxlUserAttr.run exception :" + exc.getMessage() );
            }

            if (iref <= 0 || iref > 365)
            {
                iref = 1;
            }

            iref *= 86400000; // = 24 * 60 * 60 * 1000
            String table = nxlUtil.readCfgValue("","USERMODE","user_info","");
            //System.out.println("user table:"+table);
            if("".equals(table)) {
                return;
            }
           int idot =  table.lastIndexOf('.');
           String attr = table.substring(idot+1);
           String tb = table.substring(0, idot);
            //System.out.println("user table="+tb+" user attr="+attr);

            String  sql = "SELECT * FROM ";
            sql += tb;
            sql += " WHERE ";
            sql += attr;
            sql += " = '";
            sql += userName;
            sql += "'";
            //System.out.println("user sql:"+sql);
            //System.out.println("url2:"+this.url);

            
            nxlEnforcer.SQLEnforcerWriteLog(1,"nxlUserAttr.run sql: "+sql);

			boolean b = false;
            while(!b){
				b = this.exit;
				sleep(iref);
                Connection con =  nxlConnection.createRealConnection(this.url,this._con_attr,"");
                if(con == null){
                    throw new SQLException("nxlUserAttr.sync_once_query createRealConnection failed.");
                }
                //DriverManager.getConnection(this.url+";status=nextlabs",this._con_attr );
                PreparedStatement statement = con.prepareStatement(sql);
                statement.executeQuery();
                ResultSet rs = statement.getResultSet();
                ResultSetMetaData rsmd = rs.getMetaData();
                while (rs.next()) /*get first row data*/
                {
                    int iSize = rsmd.getColumnCount();
                    for(int i = 1 ; i <= iSize; ++i){
                        String s = rs.getString(i);
                        if(s == null)
                            continue;
                        if( rsmd.getColumnType(i) == java.sql.Types.BOOLEAN ){
                            if(s.equals("0")) s = "false";
                            if(s.equals("1")) s = "true";
                        }
                        //System.out.println("user_attr key:"+ rsmd.getColumnName(i) + " value:"+ s);
                        //userAttr.setProperty(rsmd.getColumnName(i), s);
                        nxlEnforcer.SQLAddDBUserInfo(this.enforcerContext, rsmd.getColumnName(i), s);
                    }
                    break;
                }
                rs.close();
                statement.close();
                con.close();
               
            }


        } catch ( InterruptedException e ) {
            //System.out.println( "Thread interrupted..." );
            //nxlEnforcer.SQLEnforcerWriteLog(3,"----nxlUserAttr.run InterruptedException " +  e.getMessage() );
        } catch (Exception exc) {
            nxlEnforcer.SQLEnforcerWriteLog(3,"nxlUserAttr.run Exception " +  exc.getMessage() );
            //throw new SQLException("config.ini no user table");
        }
    } 
	
	public void sync_once_query(){
		try{
            String table = nxlUtil.readCfgValue("","USERMODE","user_info","");
            //System.out.println("user table:"+table);
            if("".equals(table)) {
                return;
            }
            int idot =  table.lastIndexOf('.');
            String attr = table.substring(idot+1);
            String tb = table.substring(0, idot);
            //System.out.println("user table="+tb+" user attr="+attr);

            String  sql = "SELECT * FROM ";
            sql += tb;
            sql += " WHERE ";
            sql += attr;
            sql += " = '";
            sql += userName;
            sql += "'";

            nxlEnforcer.SQLEnforcerWriteLog(1,"nxlUserAttr.sync_once_query sql: "+sql);

            //System.out.println("user sql:"+sql);
            //System.out.println("url3:"+this.url);
            Connection con  = nxlConnection.createRealConnection(this.url,this._con_attr,"");
            if(con == null){
                throw new SQLException("nxlUserAttr.sync_once_query createRealConnection failed.");
            }
            //DriverManager.getConnection(this.url+";status=nextlabs",this._con_attr );
            PreparedStatement statement = con.prepareStatement(sql);

            statement.executeQuery();
			ResultSet rs = statement.getResultSet();
			ResultSetMetaData rsmd = rs.getMetaData();
			while (rs.next()) /*get first row data*/
			{
				int iSize = rsmd.getColumnCount();
				for(int i = 1 ; i <= iSize; ++i){
					String s = rs.getString(i);
					if(s == null)
						continue;
					if( rsmd.getColumnType(i) == java.sql.Types.BOOLEAN ){
						if(s.equals("0")) s = "false";
						if(s.equals("1")) s = "true";
					}
					//System.out.println("user_attr key:"+ rsmd.getColumnName(i) + " value:"+ s);
					//userAttr.setProperty(rsmd.getColumnName(i), s);
					nxlEnforcer.SQLAddDBUserInfo(this.enforcerContext, rsmd.getColumnName(i), s);
				}
				break;
			}
			rs.close();
			
            statement.close();
            con.close();

        }  catch (Exception exc) {
            nxlEnforcer.SQLEnforcerWriteLog(4, "Failed to do nxlUserAttr.sync_once_query.");
            //throw new SQLException("config.ini no user table");
        }
	}
		
}