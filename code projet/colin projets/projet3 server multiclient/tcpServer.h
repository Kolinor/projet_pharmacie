//---------------------------------------------------------------------------

#ifndef tcpServerH
#define tcpServerH

#include <tchar.h>
#include <iostream>
#include <WS2tcpip.h>
#include <sstream>
#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>

using namespace std;

//---------------------------------------------------------------------------

class tcpServer
{

	private:
		SOCKET listening;
		SOCKET client;
		char buffer[4096];
		WSADATA wsData;
		sockaddr_in hint;
		fd_set master;
		bool etat;

	public:
		tcpSever();
		bool start(unsigned short port);
		bool sendMessage(const unsigned char* buf, unsigned int lenght);
		bool read();



};


#endif
