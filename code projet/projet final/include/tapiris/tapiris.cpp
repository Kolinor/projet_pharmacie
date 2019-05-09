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
	Thread = CreateThread(NULL,0,this->threadCapteur,this,0,NULL);
	return connected;
}

void tapiris::disconnect()
{
	this->~tapiris();
}

void tapiris::activePiston(int piston, int delay)
{
	Thread = CreateThread(NULL,0,this->threadApiston,new ThreadDataTapiris(piston,delay,this),0,NULL);
}

DWORD WINAPI tapiris::threadApiston(LPVOID lpParam)
{
	ThreadDataTapiris * apiston = (ThreadDataTapiris*)lpParam;
	int npiston = apiston->piston;
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
		Sleep(apiston->delay);
		verif = apiston->tapis->pmodBus->writeWord(pist,1);
		HANDLE Thread = CreateThread(NULL,0,apiston->tapis->threadDpiston,new ThreadDataTapiris(apiston->piston,apiston->delay,apiston->tapis),0,NULL);
	}
	delete apiston;
	return 0;
}

DWORD WINAPI tapiris::threadDpiston(LPVOID lpParam)
{
	ThreadDataTapiris * dpiston = (ThreadDataTapiris*)lpParam;
	Sleep(200);

	unsigned int pist;
	if (dpiston->piston == 1) {
		pist = 6;
	}
	if (dpiston->piston == 2) {
		pist = 7;
	}
	if (dpiston->piston == 3) {
		pist = 5;
	}

	dpiston->tapis->pmodBus->writeWord(pist,0);
	delete dpiston;
	return 0;
}

bool tapiris::activeTapis()
{
	bool verif = pmodBus->writeWord(0,0);
	return verif;
}

bool tapiris::deactivateTapis()
{
	bool verif = pmodBus->writeWord(0,1);
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


DWORD WINAPI tapiris::threadCapteur(LPVOID lpParam)
{
	tapiris * tapis = (tapiris*)lpParam;

	char buffer[4096];
	bool test = true;
	int bytes;

	bool captState[2];
	captState[0] = false;
	captState[1] = false;
	captState[2] = false;



	while(tapis->etatCapteur == true || test == false)
	{
		ZeroMemory(buffer, 4096);
		test = tapis->pmodBus->readWord(1,3,buffer);

		if(buffer[7] == 0x04)
		{
			if (buffer[12] == 1) {
				if(captState[0] == false)
				{
					tapis->activePiston(1,280);
					captState[0] = true;
				}
			}
			else
			{
				captState[0] = false;
			}

			if (buffer[14] == 1) {
				if(captState[1] == false)
				{
					tapis->activePiston(2,280);
					captState[1] = true;
				}

			}
			else
			{
				captState[1] = false;
			}

			if (buffer[10] == 1) {
				if(captState[2] == false)
				{
					//action à executer ici pour lire la caisse
					tapis->vpiston.push_back(2);
					captState[2] = true;
				}
			}
			else
			{
				captState[2] = false;
            }
		}

		Sleep(100);

	}
	delete tapis;
	return 0;
}

void tapiris::newDrug(int caisse)
{

}
