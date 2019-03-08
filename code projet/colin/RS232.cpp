//---------------------------------------------------------------------------

#pragma hdrstop

#include "RS232.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool COM::ouverture()
{
	hcom = CreateFile(L"COM1",GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL); //on initialise le port com

	if (hcom == INVALID_HANDLE_VALUE) {
		return false;
	}

	GetCommState(hcom,&serie);
	serie.BaudRate = 9600; //on param�tre la class DCB
	serie.ByteSize = 8;
	serie.Parity = NOPARITY;
	serie.StopBits = ONESTOPBIT;
	SetCommState(hcom,&serie);
	return true;
}

void COM::fermer()
{
	CloseHandle(hcom); //on ferme le port com
}

bool COM::ecriture(char * str, int taille)
{
	unsigned long pt = 0;


	WriteFile(hcom, str, taille, &pt, NULL); //permet d'envoyer les donn�es sur le port
	PurgeComm(hcom, PURGE_TXCLEAR);

	return true;
}

char* COM::lecture() //permet de recevoir se qui arrive sur le prt com
{
	int taille = 10;
	char *chaine;
	unsigned long pt;

	pt = 0;
	chaine = new char[taille+1];
	chaine[0]='\0';
	ReadFile(hcom,chaine,taille,&pt,NULL);
	PurgeComm(hcom,PURGE_RXCLEAR);

	return chaine;
}
