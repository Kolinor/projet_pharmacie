#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#include <iostream>
#include <string.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include "tcpClient.h"

 int _tmain(int argc, _TCHAR* argv[]) 
{
	tcpClient * tcp;
	tcp = new(tcpClient);
	char * buf;
	buf = new char() ;
	buf = "000000000006000600000000";
	tcp->connected("192.168.64.200", 502);
	tcp->sendChar(buf,sizeof(buf));
	tcp->sendString("yop");
	string coucou = tcp->readString();
	cout << coucou << endl;

	system("pause");

	return 0;
}
