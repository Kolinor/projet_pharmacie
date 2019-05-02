//---------------------------------------------------------------------------

#pragma hdrstop

#include "tapiris.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

tapiris::tapiris()
{
	pmodBus = new modBus();
}

tapiris::~tapiris()
{
    delete pmodBus;
}

bool tapiris::connected(string adress, unsigned short port)
{
	bool connected = pmodBus->connected(adress,port);
	return connected;
}

bool tapiris::activePiston(int piston)
{
	npiston = piston;
	bool verif = false;
	unsigned int pist;
	if (npiston == 1) {
		pist = 0006;
	}
	if (npiston == 2) {
		pist = 0007;
	}
	if (npiston == 3) {
		pist = 0005;
	}
	if (npiston <= 3 && npiston >= 1) {
		verif = pmodBus->writeWord(pist,0001);
		Thread = CreateThread(NULL,0,this->piston,this,0,NULL);
	}
	return verif;
}

DWORD WINAPI tapiris::piston( LPVOID lpParam)
{
	tapiris * thisThread = (tapiris*)lpParam;
	Sleep(300);
	unsigned int pist;
	if (thisThread->npiston == 1) {
		pist = 0006;
	}
	if (thisThread->npiston == 2) {
		pist = 0007;
	}
	if (thisThread->npiston == 3) {
		pist = 0005;
	}
	thisThread->pmodBus->writeWord(pist,0000);
	return 0;
}

bool tapiris::activeTapis()
{
	bool verif = pmodBus->writeWord(0000,0000);
	return verif;
}

bool tapiris::deactivateTapis()
{
	bool verif = pmodBus->writeWord(0000,0001);
	return verif;
}
