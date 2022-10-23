 #include <stdio.h>
 #include <string>
 #include "odbcproxy.h"
 #include "enforcerwrapper.h"
 #include "config.h"
 #include "sqlexception.h"
 
 struct Cinitializer {
    Cinitializer() {
      
      printf("in nxlodbc Cinitializer\n");
      //load enforcer
      COdbcProxy* pOdbc = COdbcProxy::Instance();
      pOdbc->Init();

        //load config file
        const std::string strCfgFile = "/usr/nextlabs/daeforlinux/config/config.ini";
        if(NULL == theConfig){
          theConfig = new CConfig();
		      theConfig->ReadConfig(strCfgFile.c_str());
        }
        
         printf("in nxlodbc Cinitializer 0\n");
        theConfig->PrintConfigData();

		   //load enforcer
       if(Enforcer::Instance()->LoadEnforcer())
		   {
          printf("load enforcer success.\n");
          SqlException exc;
          Enforcer::Instance()->SQLEnforcerInit("odbc", strCfgFile.c_str(), &exc);
		   }

    }

    ~Cinitializer() {
      COdbcProxy::Instance()->UnInit();
    }
  };

 Cinitializer g_pInit;

 


 