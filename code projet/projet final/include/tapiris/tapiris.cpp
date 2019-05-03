//---------------------------------------------------------------------------

#pragma hdrstop

#include "tapiris.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

tapiris::tapiris()
{

}

tapiris::~tapiris()
{
	this->deactivatePiston(1);
	this->deactivatePiston(2);
	this->deactivatePiston(3);
	this->deactivateTapis();

	this->etatCapteur = false;
	delete pmodBus;
}

bool tapiris::connected(string adress, unsigned short port)
{
	pmodBus = new modBus();
	bool connected = pmodBus->connected(adress,port);
	this->etatCapteur = true;
	Thread = CreateThread(NULL,0,this->capteur,this,0,NULL);
	return connected;
}

void tapiris::disconnect()
{
	this->~tapiris();
}

bool tapiris::activePiston(int piston)
{
	int npiston = piston;
	bool verif = false;
	unsigned int pist;
	if (npiston == 1) {
		pist = 6;
	}
	if (npiston == 2) {
		pist = 7;
	}
	if (npiston == 3) {
		pist = 5;
	}
	if (npiston <= 3 && npiston >= 1) {
		verif = pmodBus->writeWord(pist,1);
		Thread = CreateThread(NULL,0,this->piston,new ThreadDataTapiris(piston, this),0,NULL);
	}
	return verif;
}

DWORD WINAPI tapiris::piston(LPVOID lpParam)
{
	ThreadDataTapiris * piston = (ThreadDataTapiris*)lpParam;
	Sleep(300);

	unsigned int pist;
	if (piston->piston == 1) {
		pist = 6;
	}
	if (piston->piston == 2) {
		pist = 7;
	}
	if (piston->piston == 3) {
		pist = 5;
	}

	piston->tapis->pmodBus->writeWord(pist,0);
	delete piston;
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

bool tapiris::deactivatePiston(int piston)
{
	int npiston = piston;
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
		verif = pmodBus->writeWord(pist,0000);
	}
	return verif;
}


DWORD WINAPI tapiris::capteur(LPVOID lpParam)
{
	tapiris * tapis = (tapiris*)lpParam;

	char buffer[4096];
	bool test = true;
	int tabPiece[2];
	int bytes;
	while(tapis->etatCapteur == true || test == false)
	{
		ZeroMemory(buffer, 4096);
		test = tapis->pmodBus->readWord(1,3,buffer);;

		if (buffer[12] == 1 && tabPiece[0] != 1) {
			tapis->activePiston(1);
			tabPiece[0] = 1;
		}
		else
		{
			tabPiece[0] = 0;
		}

		if (buffer[14] == 1 && tabPiece[1] != 1) {
			tapis->activePiston(2);
			tabPiece[1] = 1;
		}
		else
		{
			tabPiece[1] = 0;
		}

		Sleep(500);

	}
	return 0;
}

void tapiris::newDrug(int caisse)
{

}
