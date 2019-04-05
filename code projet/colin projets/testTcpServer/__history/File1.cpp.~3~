#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "tcpServer.h"
#include <stdio.h>
#include <iostream>

 int _tmain(int argc, _TCHAR* argv[]) 
{
	tcpServer * tcp;
	tcp = new tcpServer();

	tcp->start(502);
	system("PAUSE");

	tcp->sendMessage("test",5);
	system("PAUSE");

	return 0;
}
