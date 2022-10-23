# AsmExtendCore
## Description
This project is used to bind method to ADO.NET.
## Usage
1. Determine the target file and the target method which you want to bind methods. For example: `System.Data.SqlClient.SqlCommand. get_CommandText()` in "System.Data.dll".

2. Build "AsmExtendCore.dll" with the same architecture as the target file from this project.

3. Use .NET assembly editor to open the target file. For example: [dnSpy](https://github.com/dnSpy/dnSpy).

4. Backup the original target files and then merge "AsmExtendCore.dll" with the target assembly. For example: When you use dnSpy, you can right click the target assembly and click "Merge with Assembly(C#)..." to merge "AsmExtendCore.dll".

5. Add class member `private ThreadRuntimeMgr m_theThreadRuntimeMgr` and initialize it in the right place. For example: When you use dnSpy, you can right click the target class and click "Add Class Members" to add `private ThreadRuntimeMgr m_theThreadRuntimeMgr`. After that, you should use `this.m_theThreadRuntimeMgr = new ThreadRuntimeMgr();` to initialize `m_theThreadRuntimeMgr` in the right constructor or in the default value.

6. Edit the target method, and use `MethodBindingInvoker.CheckAndInvokeBindMethodEx` to check and invoke bind method. For example: When you use dnSpy and the target method is `System.Data.SqlClient.SqlCommand. get_CommandText()`, you can right click the target method, click "Edit Method(C#)..." and then add the below code before the original code:

   >`try
   >{
   >  	string text = null;
   >  	MethodBase currentMethod = MethodBase.GetCurrentMethod();
   >  	if (MethodBindingInvoker.CheckAndInvokeBindMethodEx<string, SqlCommand>(ref text, this.m_theThreadRuntimeMgr, currentMethod, this, null))
   >  	{
   >    		return string.IsNullOrEmpty(text) ? "" : text;
   >  	}
   >}
   >catch (Exception ex)
   >{
   >  	if (ex.InnerException != null && MethodBindingInvoker.IsNeedToBeThrownOutException(ex.InnerException))
   >  	{
   >    		throw ex.InnerException.InnerException;
   >  	}
   >  	Logger.WriteLine(ex);
   >}`
   
7. Then it will load the AsmExtend plugins based on the AsmExtend config (You can check the comments in the files in the "Config" directory).

8. The default config path is "C:\ProgramData\Nextlabs\DAEforWin\DotNet\Config" and the default log path is "C:\ProgramData\Nextlabs\DAEforWin\DotNet\Logs".

9. You can set new config path and log path by setting registry value "AsmExtendConfigRoot" and "AsmExtendConfigRoot" in the key of "HKEY_LOCAL_MACHINE\SOFTWARE\Nextlabs". These registry values type should be string value, and the value data is the config or the log directory path.

