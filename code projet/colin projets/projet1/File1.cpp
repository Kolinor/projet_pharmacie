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
	char buf[]="DONNEDONNER";
	tcp->connected("192.168.65.7", 9013);
	tcp->sendChar(buf,sizeof(buf));
//	tcp->sendString("DONNEDONNER\n");
	string coucou = tcp->readString();
	cout << coucou << endl;

	system("pause");

	return 0;
}
