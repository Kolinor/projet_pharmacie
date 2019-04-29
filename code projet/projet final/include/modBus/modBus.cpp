//---------------------------------------------------------------------------

#pragma hdrstop

#include "modBus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

modBus::modBus()
{
	tcp = new tcpClient();
	trame = new unsigned char[12];

	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;
}

modBus::~modBus()
{
	delete tcp;
	delete trame;
}

bool modBus::connected(string adress, unsigned short port)
{
	bool connected = tcp->connected(adress,port);
	return connected;
}

void modBus::disconnect()
{
	delete tcp;
}

bool modBus::writeWord(unsigned char mot, unsigned char valeur)
{
	trame[7] = 0x06
	trame[8] =
}
