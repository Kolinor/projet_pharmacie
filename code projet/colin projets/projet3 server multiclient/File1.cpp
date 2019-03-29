#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#include <iostream>
#include <WS2tcpip.h>
#include <sstream>

#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>

using namespace std;

 int _tmain(int argc, _TCHAR* argv[])
{

	WSADATA wsData;
	WORD ver = MAKEWORD(2,2);

	int ws0k = WSAStartup(ver, &wsData);
	if (ws0k != 0) {
		cerr << "Impossible d'initialiser winsock" << endl;
	}

	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		cerr << "impossible de creer la socket" << endl;
	}

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(9013);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	listen(listening, SOMAXCONN);

	fd_set master;
	FD_ZERO(&master);

	FD_SET(listening, &master);

	while (true)
	{
		fd_set copy = master;

		int socketCount = select(0, &copy, 0, 0, 0);

		for (int i = 0; i < socketCount; i++) {
			SOCKET sock =  copy.fd_array[i];
			if (sock == listening) {
				SOCKET client = accept(listening, 0, 0);

				FD_SET(client, &master);

				string welcomeMsg = "Bienvenue sur le serveur\r\n";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() +1, 0);
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
				else {
					for (int i = 0; i < master.fd_count; i++) {
						SOCKET outSock = master.fd_array[i];
						if (outSock != listening && outSock != sock) {
							ostringstream ss;
							ss << "SOCKET #" << sock << ":" << buf << "\r\n";
							string strOut = ss.str();


							send(outSock, strOut.c_str(), strOut.size()+1, 0);
						}
					}
                }
            }
		}
    }



	WSACleanup;
	system("pause");
	return 0;
}
