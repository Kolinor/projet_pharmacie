#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include "tcpClient.h"

 int _tmain(int argc, _TCHAR* argv[]) 
{
	tcpClient * pTcpClient;
	pTcpClient = new tcpClient;

	if (pTcpClient->connected("192.168.65.15",9013) == true)
	{
		cout << "connecte au serveur" << endl;
	}
	system("pause");

	if (pTcpClient->sendString("je suis un test") == true) {
		cout << "message bien envoye" << endl;

    }


	system("pause");
	string test = pTcpClient->readString();
	cout << "server>" << test << endl;
	system("pause");



	return 0;
}
