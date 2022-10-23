package emdb;

import java.sql.*;

public class EMDBConnectInfo {
    public EMDBConnectInfo(String username,String password, String drivername, String url){
        m_username = username;
        m_password = password;
        m_driverName = drivername;
        m_url = url;
    }
    public void Connect(String userPropFile)throws SQLException ,ClassNotFoundException{
        //link driver
        Class.forName(m_driverName);
        //connect server
        m_connection = DriverManager.getConnection(m_url,m_username,m_password);

        if(m_connection != null) {
            if (m_url.toLowerCase().contains("nextlabs")) {
                m_connection.setClientInfo(LoadUserProperties.loadUserProperties(userPropFile));
            }
        }
    }
    public void ConnectDBUser()throws SQLException, ClassNotFoundException{
        //link driver
        Class.forName(m_driverName);
        //connect server
        m_connection = DriverManager.getConnection(m_url,m_username,m_password);
    }
    public ResultSet Execute(String sql)throws SQLException{
        if (m_connection != null){
            Statement statement = m_connection.createStatement();
             if (statement.execute(sql)){
                 return statement.getResultSet();
             }
             if(statement != null) {
                 statement.close();
             }
        }
        return null;
    }
    public void Close()throws SQLException{
        m_connection.close();
    }
    Connection m_connection;


    private String m_username;
    private String m_password;
    private String m_driverName;
    private String m_url;
}
