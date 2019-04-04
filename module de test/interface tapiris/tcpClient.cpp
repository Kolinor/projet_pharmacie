//---------------------------------------------------------------------------

#pragma hdrstop

#include "tcpClient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

tcpClient::tcpClient()
{
	WORD ver = MAKEWORD(2,2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) {
		cerr << "impossible de d�marrer winsock" << wsResult << endl;
		return;
	}

	this->sock = socket(AF_INET, SOCK_STREAM,0);
	if (sock == INVALID_SOCKET) {
		cerr << "impossible de creer le socket" << WSAGetLastError() << endl;
		WSACleanup();
		return;
	}

}

bool tcpClient::connected(string adress, unsigned short port)
{
	bool result;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, adress.c_str(), &hint.sin_addr);



	int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR) {
		closesocket(sock);
		WSACleanup();
		result = false;
	}
	else {
		result = true;
	}
	return result;
}

bool tcpClient::sendString(string userInput)
{
	bool result;


	if (userInput.size() > 0) {
		int sendResult = send(sock, userInput.c_str(), userInput.size()+1 ,0);

		if (sendResult != SOCKET_ERROR) {
			result = true;
		}
		else {
			result = false;
		}
	}


	return result;
}

string tcpClient::readString()
{
	ZeroMemory(buffer, 4096);
	int bytesReceived = recv(sock, buffer, 4096,0);
	if (bytesReceived > 0) {
		return string(buffer, 0, bytesReceived);
	}
}

bool tcpClient::sendChar(char * buf, int length)
{
	bool result;

	if (length > 0) {
		int sendResult = send(sock, buf, length ,0);

		if (sendResult != SOCKET_ERROR) {
			result = true;
		}
		else {
			result = false;
		}
	}


	return result;
}

int tcpClient::readChar(char * buffer)
{
	ZeroMemory(buffer, 4096);
	int bytesReceived = recv(sock, buffer, 4096,0);
	if (bytesReceived > 0) {
		return bytesReceived;
	}

}

tcpClient::~tcpClient()
{
	closesocket(sock);
    WSACleanup();
}
