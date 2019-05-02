//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : tcpServer.h
Role ........ : serveur multiclient un seul thread
Auteur ...... : Colin.B
Version ..... : V1.1 du 02/04/2019

Compilation : c++ builder
********************************************************/

#ifndef tcpServerH
#define tcpServerH

#include <tchar.h>
#include <iostream>
#include <WS2tcpip.h>
#include <sstream>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#define BUF_SIZE 255

using namespace std;

//---------------------------------------------------------------------------

class tcpServer
{

	private:
		SOCKET listening;
		SOCKET client;
		WSADATA wsData;
		sockaddr_in hint;
		TCHAR msgBuf[BUF_SIZE];
		size_t cchStringSize;
		DWORD dwChars;
		HANDLE Thread;
		bool etatThread;

	public:
		tcpServer();
		~tcpServer();
		//sert � demarrer le serveur
		bool start(unsigned short port);
		//sert � arreter le serveur
		void stop();
		//sert � envoyer un message
		bool sendMessage(const unsigned char* buf, unsigned int lenght);
		//thread pour le lecture
		static DWORD WINAPI receive( LPVOID lpParam );



};


#endif
