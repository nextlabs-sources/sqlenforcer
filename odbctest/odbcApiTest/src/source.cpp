#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <conio.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>

SQLHENV     hEnv = NULL;
SQLHDBC     hDbc = NULL;
SQLHSTMT    hStmt = NULL;
RETCODE     rc = NULL;

#define DISPLAY_MAX 50          // Arbitrary limit on column width to display
#define DISPLAY_FORMAT_EXTRA 3  // Per column extra display bytes (| <data> )
#define DISPLAY_FORMAT      L"%c %*.*s "
#define DISPLAY_FORMAT_C    L"%c %-*.*s "
#define NULL_SIZE           6   // <NULL>
#define PIPE                L'|'
SHORT   gHeight = 80;       // Users screen height


std::wstring stringToWstring(const std::string& str)
{
	LPCSTR pszSrc = str.c_str();
	int nLen = MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, NULL, 0);
	if (nLen == 0)
		return std::wstring(L"");

	wchar_t* pwszDst = new wchar_t[nLen];
	if (!pwszDst)
		return std::wstring(L"");

	MultiByteToWideChar(CP_ACP, 0, pszSrc, -1, pwszDst, nLen);
	std::wstring wstr(pwszDst);
	delete[] pwszDst;
	pwszDst = NULL;

	return wstr;
}

void HandleDiagnosticRecord(SQLHANDLE      hHandle,
	SQLSMALLINT    hType,
	RETCODE        RetCode)
{
	SQLSMALLINT iRec = 0;
	SQLINTEGER  iError;
	WCHAR       wszMessage[1000];
	WCHAR       wszState[SQL_SQLSTATE_SIZE + 1];


	if (RetCode == SQL_INVALID_HANDLE)
	{
		fwprintf(stderr, L"Invalid handle!\n");
		return;
	}

	while (SQLGetDiagRec(hType,
		hHandle,
		++iRec,
		wszState,
		&iError,
		wszMessage,
		(SQLSMALLINT)(sizeof(wszMessage) / sizeof(WCHAR)),
		(SQLSMALLINT *)NULL) == SQL_SUCCESS)
	{

		fwprintf(stderr, L"[%5.5s] %s (%d)\n", wszState, wszMessage, iError);
	}

}
#define TRYODBC(h, ht, x)   {   RETCODE rc = x;\
                                if (rc != SQL_SUCCESS) \
                                { \
                                    HandleDiagnosticRecord (h, ht, rc); \
                                } \
                                if (rc == SQL_ERROR) \
                                { \
                                    fwprintf(stderr, L"Error in " L#x L"\n"); \
                                    goto Exit;  \
                                }  \
                            }


/************************************************************************
/* SetConsole: sets console display size and video mode
/*
/*  Parameters
/*      siDisplaySize   Console display size
/*      fInvert         Invert video?
/************************************************************************/
void SetConsole(DWORD dwDisplaySize,
	BOOL  fInvert)
{
	HANDLE                          hConsole;
	CONSOLE_SCREEN_BUFFER_INFO      csbInfo;

	// Reset the console screen buffer size if necessary

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole != INVALID_HANDLE_VALUE)
	{
		if (GetConsoleScreenBufferInfo(hConsole, &csbInfo))
		{
			if (csbInfo.dwSize.X < (SHORT)dwDisplaySize)
			{
				csbInfo.dwSize.X = (SHORT)dwDisplaySize;
				SetConsoleScreenBufferSize(hConsole, csbInfo.dwSize);
			}

			gHeight = csbInfo.dwSize.Y;
		}

		if (fInvert)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(csbInfo.wAttributes | BACKGROUND_GREEN));
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (WORD)(csbInfo.wAttributes & ~(BACKGROUND_GREEN)));
		}
	}
}

/******************************************/
/* Structure to store information about   */
/* a column.
/******************************************/
typedef struct STR_BINDING {
	SQLSMALLINT         cDisplaySize;           /* size to display  */
	WCHAR               *wszBuffer;             /* display buffer   */
	SQLLEN              indPtr;                 /* size or null     */
	BOOL                fChar;                  /* character col?   */
	struct STR_BINDING  *sNext;                 /* linked list      */
} BINDING;

/************************************************************************
/* DisplayTitles: print the titles of all the columns and set the
/*                shell window's width
/*
/* Parameters:
/*      hStmt          Statement handle
/*      cDisplaySize   Total display size
/*      pBinding        list of binding information
/************************************************************************/

void DisplayTitles(HSTMT     hStmt,
	DWORD     cDisplaySize,
	BINDING   *pBinding)
{
	WCHAR           wszTitle[DISPLAY_MAX];
	SQLSMALLINT     iCol = 1;

	SetConsole(cDisplaySize + 2, TRUE);

	for (; pBinding; pBinding = pBinding->sNext)
	{
		TRYODBC(hStmt,
			SQL_HANDLE_STMT,
			SQLColAttribute(hStmt,
				iCol++,
				SQL_DESC_NAME,
				wszTitle,
				sizeof(wszTitle), // Note count of bytes!
				NULL,
				NULL));

		wprintf(DISPLAY_FORMAT_C,
			PIPE,
			pBinding->cDisplaySize,
			pBinding->cDisplaySize,
			wszTitle);
	}

Exit:
	wprintf(L" %c", PIPE);
	SetConsole(cDisplaySize + 2, FALSE);
	wprintf(L"\n");
}
/************************************************************************
/* AllocateBindings:  Get column information and allocate bindings
/* for each column.
/*
/* Parameters:
/*      hStmt      Statement handle
/*      cCols       Number of columns in the result set
/*      *lppBinding Binding pointer (returned)
/*      lpDisplay   Display size of one line
/************************************************************************/

void AllocateBindings(HSTMT         hStmt,
	SQLSMALLINT   cCols,
	BINDING       **ppBinding,
	SQLSMALLINT   *pDisplay)
{
	SQLSMALLINT     iCol;
	BINDING         *pThisBinding, *pLastBinding = NULL;
	SQLLEN          cchDisplay, ssType;
	SQLSMALLINT     cchColumnNameLength;

	*pDisplay = 0;

	for (iCol = 1; iCol <= cCols; iCol++)
	{
		pThisBinding = (BINDING *)(malloc(sizeof(BINDING)));
		if (!(pThisBinding))
		{
			fwprintf(stderr, L"Out of memory!\n");
			exit(-100);
		}

		if (iCol == 1)
		{
			*ppBinding = pThisBinding;
		}
		else
		{
			pLastBinding->sNext = pThisBinding;
		}
		pLastBinding = pThisBinding;


		// Figure out the display length of the column (we will
		// bind to char since we are only displaying data, in general
		// you should bind to the appropriate C type if you are going
		// to manipulate data since it is much faster...)

		TRYODBC(hStmt,
			SQL_HANDLE_STMT,
			SQLColAttribute(hStmt,
				iCol,
				SQL_DESC_DISPLAY_SIZE,
				NULL,
				0,
				NULL,
				&cchDisplay));


		// Figure out if this is a character or numeric column; this is
		// used to determine if we want to display the data left- or right-
		// aligned.

		// SQL_DESC_CONCISE_TYPE maps to the 1.x SQL_COLUMN_TYPE. 
		// This is what you must use if you want to work
		// against a 2.x driver.

		TRYODBC(hStmt,
			SQL_HANDLE_STMT,
			SQLColAttribute(hStmt,
				iCol,
				SQL_DESC_CONCISE_TYPE,
				NULL,
				0,
				NULL,
				&ssType));


		pThisBinding->fChar = (ssType == SQL_CHAR ||
			ssType == SQL_VARCHAR ||
			ssType == SQL_LONGVARCHAR);

		pThisBinding->sNext = NULL;

		// Arbitrary limit on display size
		if (cchDisplay > DISPLAY_MAX)
			cchDisplay = DISPLAY_MAX;

		// Allocate a buffer big enough to hold the text representation
		// of the data.  Add one character for the null terminator

		pThisBinding->wszBuffer = (WCHAR *)malloc((cchDisplay + 1) * sizeof(WCHAR));

		if (!(pThisBinding->wszBuffer))
		{
			fwprintf(stderr, L"Out of memory!\n");
			exit(-100);
		}

		// Map this buffer to the driver's buffer.   At Fetch time,
		// the driver will fill in this data.  Note that the size is 
		// count of bytes (for Unicode).  All ODBC functions that take
		// SQLPOINTER use count of bytes; all functions that take only
		// strings use count of characters.

		TRYODBC(hStmt,
			SQL_HANDLE_STMT,
			SQLBindCol(hStmt,
				iCol,
				SQL_C_TCHAR,
				(SQLPOINTER)pThisBinding->wszBuffer,
				(cchDisplay + 1) * sizeof(WCHAR),
				&pThisBinding->indPtr));


		// Now set the display size that we will use to display
		// the data.   Figure out the length of the column name

		TRYODBC(hStmt,
			SQL_HANDLE_STMT,
			SQLColAttribute(hStmt,
				iCol,
				SQL_DESC_NAME,
				NULL,
				0,
				&cchColumnNameLength,
				NULL));

		pThisBinding->cDisplaySize = max((SQLSMALLINT)cchDisplay, cchColumnNameLength);
		if (pThisBinding->cDisplaySize < NULL_SIZE)
			pThisBinding->cDisplaySize = NULL_SIZE;

		*pDisplay += pThisBinding->cDisplaySize + DISPLAY_FORMAT_EXTRA;

	}

	return;

Exit:

	exit(-1);

	return;
}

/************************************************************************
/* DisplayResults: display results of a select query
/*
/* Parameters:
/*      hStmt      ODBC statement handle
/*      cCols      Count of columns
/************************************************************************/
void DisplayResults(HSTMT       hStmt,
	SQLSMALLINT cCols)
{
	BINDING         *pFirstBinding, *pThisBinding;
	SQLSMALLINT     cDisplaySize;
	RETCODE         RetCode = SQL_SUCCESS;
	int             iCount = 0;

	// Allocate memory for each column 

	AllocateBindings(hStmt, cCols, &pFirstBinding, &cDisplaySize);

	// Set the display mode and write the titles

	DisplayTitles(hStmt, cDisplaySize + 1, pFirstBinding);


	// Fetch and display the data

	bool fNoData = false;

	do {
		// Fetch a row

		if (iCount++ >= gHeight - 2)
		{
			int     nInputChar;
			bool    fEnterReceived = false;

			while (!fEnterReceived)
			{
				wprintf(L"              ");
				SetConsole(cDisplaySize + 2, TRUE);
				wprintf(L"   Press ENTER to continue, Q to quit (height:%hd)", gHeight);
				SetConsole(cDisplaySize + 2, FALSE);

				nInputChar = _getch();
				wprintf(L"\n");
				if ((nInputChar == 'Q') || (nInputChar == 'q'))
				{
					goto Exit;
				}
				else if ('\r' == nInputChar)
				{
					fEnterReceived = true;
				}
				// else loop back to display prompt again
			}

			iCount = 1;
			DisplayTitles(hStmt, cDisplaySize + 1, pFirstBinding);
		}

		TRYODBC(hStmt, SQL_HANDLE_STMT, RetCode = SQLFetch(hStmt));

		if (RetCode == SQL_NO_DATA_FOUND)
		{
			fNoData = true;
		}
		else
		{

			// Display the data.   Ignore truncations

			for (pThisBinding = pFirstBinding;
				pThisBinding;
				pThisBinding = pThisBinding->sNext)
			{
				if (pThisBinding->indPtr != SQL_NULL_DATA)
				{
					wprintf(pThisBinding->fChar ? DISPLAY_FORMAT_C : DISPLAY_FORMAT,
						PIPE,
						pThisBinding->cDisplaySize,
						pThisBinding->cDisplaySize,
						pThisBinding->wszBuffer);
				}
				else
				{
					wprintf(DISPLAY_FORMAT_C,
						PIPE,
						pThisBinding->cDisplaySize,
						pThisBinding->cDisplaySize,
						L"<NULL>");
				}
			}
			wprintf(L" %c\n", PIPE);
		}
	} while (!fNoData);

	SetConsole(cDisplaySize + 2, TRUE);
	wprintf(L"%*.*s", cDisplaySize + 2, cDisplaySize + 2, L" ");
	SetConsole(cDisplaySize + 2, FALSE);
	wprintf(L"\n");

Exit:
	// Clean up the allocated buffers

	while (pFirstBinding)
	{
		pThisBinding = pFirstBinding->sNext;
		free(pFirstBinding->wszBuffer);
		free(pFirstBinding);
		pFirstBinding = pThisBinding;
	}
}

RETCODE DriverConnect(int inputCode)
{
	RETCODE rc = NULL;
#define CONNECTSTRING_SIZE      1000
	WCHAR       wszInput[CONNECTSTRING_SIZE];
	CHAR        szInput[CONNECTSTRING_SIZE];
	SQLCHAR szOutConnStr[1024 + 1] = { 0 };
	SQLWCHAR szOutConnStrW[1024 + 1] = { 0 };
	std::cin.clear();
	std::cin.ignore();
	switch (inputCode)
	{
	case 1:
		wprintf(L"Enter the connect string:\n");
		if (_fgetts(wszInput, CONNECTSTRING_SIZE - 1, stdin))
		{
			std::wstring a = L"\n";
			if (!wcscmp(wszInput,a.c_str()))
			{
				rc = SQLDriverConnect(hDbc,
					GetDesktopWindow(),
					//L"Driver={NXL ODBC Driver 1.0};LowerConn={Driver=SQL Server Native Client 11.0;Server=tcp:bard-sp2016.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01}",
					L"Driver=ODBC Driver 13 for SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01;\n",
					//L"Driver=ODBC Driver 13 for SQL Server;Server=np:\\\\10.23.60.115\\pipe\\sql\\query;Uid=sa;PWD=123blue!;Database=test01",
					//L"Driver=SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Database=test01;Integrated Security=true",
					//L"dsn=www;Uid=sa;Pwd=123blue;",
					SQL_NTS,
					szOutConnStrW,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
			else if (*wszInput)
			{
				rc = SQLDriverConnect(hDbc,
					GetDesktopWindow(),
					wszInput,
					SQL_NTS,
					szOutConnStrW,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
		}
		break;
	case 2:
		wprintf(L"Enter the connect string:\n");
		if (fgets(szInput, CONNECTSTRING_SIZE - 1, stdin))
		{
			std::string a = "\n";
			if (!strcmp(szInput, a.c_str()))
			{
				rc = SQLDriverConnectA(hDbc,
					GetDesktopWindow(),
					//L"Driver={NXL ODBC Driver 1.0};LowerConn={Driver=SQL Server Native Client 11.0;Server=tcp:bard-sp2016.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01}",
					(SQLCHAR*)"Driver=ODBC Driver 13 for SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01;",
					//L"Driver=ODBC Driver 13 for SQL Server;Server=np:\\\\10.23.60.115\\pipe\\sql\\query;Uid=sa;PWD=123blue!;Database=test01",
					//L"Driver=SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Database=test01;Integrated Security=true",
					//L"dsn=www;Uid=sa;Pwd=123blue;",
					SQL_NTS,
					szOutConnStr,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
			else if (*szInput)
			{
				rc = SQLDriverConnectA(hDbc,
					GetDesktopWindow(),
					(SQLCHAR*)szInput,
					SQL_NTS,
					szOutConnStr,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
		}
		break;
	case 3:
		wprintf(L"Enter the connect string:\n");
		if (_fgetts(wszInput, CONNECTSTRING_SIZE - 1, stdin))
		{
			std::wstring a = L"\n";
			if (!wcscmp(wszInput, a.c_str()))
			{
				rc = SQLDriverConnect(hDbc,
					GetDesktopWindow(),
					//L"Driver={NXL ODBC Driver 1.0};LowerConn={Driver=SQL Server Native Client 11.0;Server=tcp:bard-sp2016.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01}",
					L"Driver=ODBC Driver 13 for SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Uid=sa;PWD=123blue!;Database=test01;\n",
					//L"Driver=ODBC Driver 13 for SQL Server;Server=np:\\\\10.23.60.115\\pipe\\sql\\query;Uid=sa;PWD=123blue!;Database=test01",
					//L"Driver=SQL Server;Server=tcp:bard-dbc-executer.qapf1.qalab01.nextlabs.com,1433;Database=test01;Integrated Security=true",
					//L"dsn=www;Uid=sa;Pwd=123blue;",
					SQL_NTS,
					szOutConnStrW,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
			else if (*wszInput)
			{
				rc = SQLDriverConnect(hDbc,
					GetDesktopWindow(),
					wszInput,
					SQL_NTS,
					szOutConnStrW,
					1024,
					NULL,
					SQL_DRIVER_COMPLETE);
			}
		}
	default:
		break;
	}
	return rc;
}
RETCODE Connect(int inputCode)
{
	RETCODE rc = NULL;
	std::cin.clear();
	std::cin.ignore();
	std::string dsn;
	std::string uid;
	std::string pwd;
	std::wstring wdsn;
	std::wstring wuid;
	std::wstring wpwd;
	switch (inputCode)
	{
	case 4:
		wprintf(L"Enter DSN UID PWD:\n");
		std::cin >> dsn >> uid >> pwd;
		wdsn = stringToWstring(dsn);
		wuid = stringToWstring(uid);
		wpwd = stringToWstring(pwd);
		rc = SQLConnect(hDbc, (SQLWCHAR*)(wdsn.c_str()), SQL_NTS, (SQLWCHAR*)(wuid.c_str()), SQL_NTS, (SQLWCHAR*)(wpwd.c_str()), SQL_NTS);
		break;
	case 5:
		wprintf(L"Enter DSN UID PWD:\n");
		std::cin >> dsn >> uid >> pwd;
		rc = SQLConnectA(hDbc, (SQLCHAR*)(dsn.c_str()), SQL_NTS, (SQLCHAR*)(uid.c_str()), SQL_NTS, (SQLCHAR*)(pwd.c_str()), SQL_NTS);
		break;
	case 6:
		wprintf(L"Enter DSN UID PWD:\n");
		std::cin >> dsn >> uid >> pwd;
		wdsn = stringToWstring(dsn);
		wuid = stringToWstring(uid);
		wpwd = stringToWstring(pwd);
		rc = SQLConnectW(hDbc, (SQLWCHAR*)(wdsn.c_str()), SQL_NTS, (SQLWCHAR*)(wuid.c_str()), SQL_NTS, (SQLWCHAR*)(wpwd.c_str()), SQL_NTS);
	default:
		break;
	}
	return rc;
}
RETCODE BroswerConnect(int inputCode)
{
	RETCODE rc = SQL_NEED_DATA;
#define CONNECTSTRING_SIZE      1000
	WCHAR       wszInput[CONNECTSTRING_SIZE];
	CHAR        szInput[CONNECTSTRING_SIZE];
	SQLCHAR szOutConnStr[CONNECTSTRING_SIZE];
	SQLWCHAR szOutConnStrW[CONNECTSTRING_SIZE];
	SQLSMALLINT cbConnStrOut;
	std::cin.clear();
	std::cin.ignore();
	switch (inputCode)
	{
	case 7:
		while (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
		{
			wprintf(L"Enter the connect string:\n");
			if (_fgetts(wszInput, CONNECTSTRING_SIZE -1, stdin))
			{
				if (*wszInput)
				{
				    int length = wcslen(wszInput);
					if (wszInput[length - 1] == '\n')
					{
						wszInput[length - 1] = '\0';
					}
					rc = SQLBrowseConnect(hDbc,
						wszInput,
						//L"DSN=www;UID=sa;PWD=123blue!;Trusted_Connection=No;WSID=MORETON;", 
						SQL_NTS,
						NULL,
						CONNECTSTRING_SIZE,
						&cbConnStrOut);
					wprintf(L"back connect string:%s\n", szOutConnStrW);
				}
			}
		}
		break;
	case 8:
		while (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
		{
			wprintf(L"Enter the connect string:\n");
			if (fgets(szInput, CONNECTSTRING_SIZE - 1, stdin))
			{
				if (*szInput)
				{
					int length = strlen(szInput);
					if (szInput[length - 1] == '\n')
					{
						szInput[length - 1] = '\0';
					}

					rc = SQLBrowseConnectA(hDbc,
						(SQLCHAR*)szInput,
						//(SQLCHAR*)"DSN=www;UID=sa;PWD=123blue!;Trusted_Connection=No;WSID=MORETON;",
						SQL_NTS,
						szOutConnStr,
						CONNECTSTRING_SIZE,
						&cbConnStrOut);
					wprintf(L"back connect string:%S\n", szOutConnStr);
				}
			}
		}
		break;
	case 9:
		while (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
		{
			wprintf(L"Enter the connect string:\n");
			if (_fgetts(wszInput, CONNECTSTRING_SIZE - 1, stdin))
			{
				if (*wszInput)
				{
					int length = wcslen(wszInput);
					if (wszInput[length - 1] == '\n')
					{
						wszInput[length - 1] = '\0';
					}
					rc = SQLBrowseConnectW(hDbc,
						wszInput,
						//L"DSN=www;UID=sa;PWD=123blue!;Trusted_Connection=No;WSID=MORETON;",
						SQL_NTS,
						szOutConnStrW,
						CONNECTSTRING_SIZE,
						&cbConnStrOut);
					wprintf(L"back connect string:%s\n", szOutConnStrW);
				}
			}
		}
	default:
		break;
	}
	return rc;
}
void ExecResults(RETCODE RetCode)
{
	switch (RetCode)
	{
	case SQL_SUCCESS_WITH_INFO:
	{
		HandleDiagnosticRecord(hStmt, SQL_HANDLE_STMT, RetCode);
	}
	case SQL_SUCCESS:
	{
		// If this is a row-returning query, display
		// results
		HandleDiagnosticRecord(hStmt, SQL_HANDLE_STMT, RetCode);
		do
		{
			SQLSMALLINT sNumResults = 0;
			SQLNumResultCols(hStmt, &sNumResults);
			if (sNumResults == 0)
			{
				break;
			}
			wprintf(L"result: col:%Id\n", sNumResults);
			DisplayResults(hStmt, sNumResults);
			wprintf(L"\n");
		} while (SQLMoreResults(hStmt) == SQL_SUCCESS);
		break;
	}
	case SQL_ERROR:
	{
		HandleDiagnosticRecord(hStmt, SQL_HANDLE_STMT, RetCode);
		break;
	}
	default:
		fwprintf(stderr, L"Unexpected return code %hd!\n", RetCode);
	}
}
void ExecDirect(int inputCode)
{
	RETCODE     RetCode;
#define SQL_QUERY_SIZE      1000
	WCHAR       wszInput[SQL_QUERY_SIZE];
	CHAR        szInput[SQL_QUERY_SIZE];
	std::cin.clear();
	std::cin.ignore();
	switch (inputCode)
	{
	case 1:
		wprintf(L"Enter SQL commands, type (control)Z to exit\nSQL COMMAND>");
		while (_fgetts(wszInput, SQL_QUERY_SIZE - 1, stdin))
		{
			// Execute the query
			if (!(*wszInput))
			{
				wprintf(L"SQL COMMAND>");
				continue;
			}
#if 0
			SQLPrepare(hStmt, wszInput, SQL_NTS);
			RetCode = SQLExecute(hStmt);
#else
			RetCode = SQLExecDirect(hStmt, wszInput, SQL_NTS);
			wprintf(L"SQLExecDirect return:%d\n", RetCode);
#endif
			ExecResults(RetCode);
			rc = SQLCloseCursor(hStmt);
			rc = SQLFreeStmt(hStmt, SQL_CLOSE);
			wprintf(L"SQL COMMAND>");
		}
		break;
	case 2:
		wprintf(L"Enter SQL commands, type (control)Z to exit\nSQL COMMAND>");
		while (fgets(szInput, SQL_QUERY_SIZE - 1, stdin))
		{
			// Execute the query
			if (!(*szInput))
			{
				wprintf(L"SQL COMMAND>");
				continue;
			}
#if 0
			SQLPrepare(hStmt, wszInput, SQL_NTS);
			RetCode = SQLExecute(hStmt);
#else
			RetCode = SQLExecDirectA(hStmt, (SQLCHAR*)szInput, SQL_NTS);
			wprintf(L"SQLExecDirectA return:%d\n", RetCode);
#endif
			ExecResults(RetCode);
			rc = SQLCloseCursor(hStmt);
			rc = SQLFreeStmt(hStmt, SQL_CLOSE);
			wprintf(L"SQL COMMAND>");
		}
		break;
	case 3:
		wprintf(L"Enter SQL commands, type (control)Z to exit\nSQL COMMAND>");
		while (fgetws(wszInput, SQL_QUERY_SIZE - 1, stdin))
		{
			// Execute the query
			if (!(*wszInput))
			{
				wprintf(L"SQL COMMAND>");
				continue;
			}
#if 0
			SQLPrepare(hStmt, wszInput, SQL_NTS);
			RetCode = SQLExecute(hStmt);
#else
			RetCode = SQLExecDirectW(hStmt, wszInput, SQL_NTS);
			wprintf(L"SQLExecDirectW return:%d\n", RetCode);
#endif
			ExecResults(RetCode);
			rc = SQLCloseCursor(hStmt);
			rc = SQLFreeStmt(hStmt, SQL_CLOSE);
			wprintf(L"SQL COMMAND>");
		}
		break;
	default:
		break;
	}
}
RETCODE connectToDB(int inputCode)
{
	RETCODE rc = NULL;
	switch (inputCode)
	{
	case 1:
		rc = DriverConnect(1);
		break;
	case 2:
		rc = DriverConnect(2);
		break;
	case 3:
		rc = DriverConnect(3);
		break;
	case 4:
		rc = Connect(4);
		break;
	case 5:
		rc = Connect(5);
		break;
	case 6:
		rc = Connect(6);
		break;
	case 7:
		rc = BroswerConnect(7);
		break;
	case 8:
		rc = BroswerConnect(8);
		break;
	case 9:
		rc = BroswerConnect(9);
		break;
	default:
		break;
	}
	return rc;
}
int main(int argc, char* argv[])
{

	// Allocate an environment
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) == SQL_ERROR)
	{
		fwprintf(stderr, L"Unable to allocate an environment handle\n");
		exit(-1);
	}
	// Register this as an application that expects 3.x behavior,
	// you must register something if you use AllocHandle
    rc = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	if (rc != SQL_SUCCESS)
	{
		fwprintf(stderr, L"Unable to SQLSetEnvAttr with version 3.0\n");
		exit(-1);
	}
	// Allocate a connection
	rc = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
	if (rc != SQL_SUCCESS)
	{
		fwprintf(stderr, L"Unable to allocate connect handle\n");
		exit(-1);
	}
	wprintf(L"/**********************************/\n");
	wprintf(L"Select sql connect function\n");
	wprintf(L"select SQLDriverConnect enter 1\n");
	wprintf(L"select SQLDriverConnectA enter 2\n");
	wprintf(L"select SQLDriverConnectW enter 3\n");
	wprintf(L"select SQLConnect enter 4\n");
	wprintf(L"select SQLConnectA enter 5\n");
	wprintf(L"select SQLConnectW enter 6\n");
	wprintf(L"select SQLBrowseConnect enter 7\n");
	wprintf(L"select SQLBrowseConnectA enter 8\n");
	wprintf(L"select SQLBrowseConnectW enter 9\n");
	wprintf(L"/**********************************/\n");
	int inputCode;
	std::cin >> inputCode;
	rc = connectToDB(inputCode);
	if (SQL_SUCCESS != rc)
	{
		HandleDiagnosticRecord(hDbc, SQL_HANDLE_DBC, rc);
	}
	if (rc == SQL_ERROR)
	{
		HandleDiagnosticRecord(hDbc, SQL_HANDLE_DBC, rc);
		exit(-1);
	}

	fwprintf(stderr, L"Connected!\n");

	rc = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
	if (rc == SQL_ERROR)
	{
		fwprintf(stderr, L"allocate stmt handle failed.\n");
		HandleDiagnosticRecord(hDbc, SQL_HANDLE_DBC, rc);
		exit(-1);
	}
	wprintf(L"/**********************************/\n");
	wprintf(L"Select execute query function\n");
	wprintf(L"select SQLExecDirect enter 1\n");
	wprintf(L"select SQLExecDirectA enter 2\n");
	wprintf(L"select SQLExecDirectW enter 3\n");
	wprintf(L"/**********************************/\n");
	std::cin >> inputCode;
	ExecDirect(inputCode);
	SQLDisconnect(hDbc);
	return 0;
}
