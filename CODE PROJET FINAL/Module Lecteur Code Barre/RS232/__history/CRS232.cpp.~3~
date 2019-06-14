#include "CRS232.h"



CRS232::CRS232(char * port, int bRate, int bSize, int parity, int stopByte, Parser * parser)
{
	hCom = CreateFile(port, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL) ;
	DCB conf;
	GetCommState(hCom, &conf);
	conf.BaudRate = bRate;
	conf.ByteSize = bSize;
	conf.Parity = parity;
	conf.StopBits = stopByte;
	SetCommState(hCom, &conf);

	this->parser = parser;

	stopThread = false;
	startReceiveThread();
}



CRS232::~CRS232()
{
	CloseHandle(hCom);
}

void CRS232::startReceiveThread()
{
	DWORD threadId;
	threadHandle = CreateThread(NULL, NULL, CRS232::receiveThread, this, NULL, &threadId);
}

DWORD WINAPI CRS232::receiveThread(LPVOID params)
{
	CRS232 * comm = (CRS232 *)params;

	if (comm != NULL)
	{
		while (!comm->stopThread)
		{
			comm->receive();
		}
	}
	
	return 0;
}

void CRS232::receive()
{
	char buffer[1];
	DWORD nbBytes;

	if (ReadFile(hCom, buffer, 1, &nbBytes, NULL) == TRUE)
	{
		if(parser != NULL)
			parser->parse(buffer, nbBytes);
	}
}

void CRS232::sendBuf(char * buf, int len)
{
	// Non implémentée, car inusité dans le cadre de cette étude.
}