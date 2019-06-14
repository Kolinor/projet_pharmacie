#pragma once

#include <Windows.h>
#include "Parser.h"

class CRS232
{
	HANDLE hCom;
	Parser * parser;

	bool stopThread;
	void receive();
	void startReceiveThread();

	HANDLE threadHandle;
	static DWORD WINAPI receiveThread(LPVOID params);

public:
	CRS232(char * port, int bRate, int bSize, int parity, int stopByte, Parser * parser);
	~CRS232();

	void sendBuf(char * buf, int len);
};

