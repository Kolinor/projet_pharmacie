//---------------------------------------------------------------------------

#pragma hdrstop

#include "tcpServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

tcpServer::tcpServer()
{
	this->etatThread = true;
	WORD ver = MAKEWORD(2,2);

	int ws0k = WSAStartup(ver, &wsData);
	if (ws0k != 0) {
		cerr << "Impossible d'initialiser winsock" << endl;
	}

	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		cerr << "impossible de creer la socket" << endl;
	}

}

tcpServer::~tcpServer()
{
	this->etatThread = false;
	WSACleanup;
}

bool tcpServer::start(unsigned short port)
{
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);
	Thread = CreateThread( NULL, 0,Thread_no_1, this, 0, NULL);



	return true;

}

bool tcpServer::stop()
{
	tcpServer::~tcpServer();

}

bool tcpServer::sendMessage(const unsigned char* buf, unsigned int length)
{
	bool verif;

	if (length > 0) {
		send(client, buf, length, 0);
		verif = true;
	}
	else
	{
		verif = false;
	}
	return verif;
}

DWORD WINAPI tcpServer::Thread_no_1( LPVOID lpParam )
{
	tcpServer * thisThread = (tcpServer*)lpParam;

	fd_set master;
	FD_ZERO(&master);
	FD_SET(thisThread->listening, &master);


	while (thisThread->etatThread == true)
	{
		fd_set copy = master;

		int socketCount = select(0, &copy, 0, 0, 0);

		for (int i = 0; i < socketCount; i++) {
			SOCKET sock =  copy.fd_array[i];
			if (sock == thisThread->listening) {
				thisThread->client = accept(thisThread->listening, 0, 0);

				FD_SET(thisThread->client, &master);

				string welcomeMsg = "Serveur pharmacie\r\n";
				send(thisThread->client, welcomeMsg.c_str(), welcomeMsg.size() +1, 0);
			}
			else
			{
				char buf[4096];
				ZeroMemory(buf, 4096);


				int bytesIn = recv(sock,buf,4096,0);
				if (bytesIn <= 0) {
					closesocket(sock);
					FD_CLR(sock, &master);
				}
				else
				{
					send(sock, buf, strlen(buf)+1,0);
					cout<<buf<<endl;
				}
			}
		}
	}

    return 0;
}


