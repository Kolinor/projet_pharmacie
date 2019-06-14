//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : tcpClient.h
Role ........ : serveur multiclient un seul thread
Auteur ...... : Colin.B
Version ..... : V1.1 du 02/04/2019

Compilation : c++ builder
********************************************************/
#include <iostream>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

#ifndef tcpClientH
#define tcpClientH
//---------------------------------------------------------------------------

class tcpClient
{
	private:
		WSADATA data;
		SOCKET sock;
		sockaddr_in hint;
		//char buffer[4096];


	public:
		tcpClient();
		~tcpClient();
		//permet d'ouvrir une connection en sp�cifiant l'adresse et le port
		bool connected(string adress, unsigned short port);
		//permet d'envoyer un string
		//bool sendString(string userInput);
		//permet de lire un string
		//string readString();
		//permet d'envoyer un char
		bool sendChar(char * buffer, int length);
		//permet de lire un char
		int readChar(char * buffer);


};

#endif
