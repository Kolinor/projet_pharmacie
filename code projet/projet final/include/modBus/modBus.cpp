//---------------------------------------------------------------------------

#pragma hdrstop

#include "modBus.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

modBus::modBus()
{
	tcp = new tcpClient();
}

modBus::~modBus()
{
	delete tcp;
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

bool modBus::writeWord(unsigned int mot, unsigned int valeur)
{
	unsigned char trame[12];
	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;

	trame[7] = 0x06;
	trame[8] = (mot & 0xFF00) >> 8;
	trame[9] = (mot & 0x00FF);
	trame[10] = (valeur & 0xFF00) >> 8;
	trame[11] = (valeur & 0x00FF);

	bool verif = tcp->sendChar(trame,12);
	return verif;
}

int modBus::readWord(unsigned int mot,char * buffer)
{
	unsigned char trame[12];
	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;

	trame[7] = 0x04;
	trame[8] = (mot & 0xFF00) >> 8;
	trame[9] = (mot & 0x00FF);
	trame[10] = 0x00;
	trame[11] = 0x03;

	tcp->sendChar(trame,12);
	int bytes = tcp->readChar(buffer);
    return bytes;
}
