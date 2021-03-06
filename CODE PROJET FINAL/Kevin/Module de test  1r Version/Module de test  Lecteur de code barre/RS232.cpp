﻿//---------------------------------------------------------------------------
#pragma hdrstop
#include "RS232.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// Permet d'initialiser le port com
bool RS232::ouverture()
{
	hcom = CreateFile(L"COM1",GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL); //on initialise le port com

	if (hcom == INVALID_HANDLE_VALUE) {
		return false;
	}

	GetCommState(hcom,&serie);
	serie.BaudRate = 115200; //on paramètre la class DCB
	serie.ByteSize = 8;
	serie.Parity = NOPARITY;
	serie.StopBits = ONESTOPBIT;
	SetCommState(hcom,&serie);
	return true;
}

// Permet de fermer le port com
void RS232::fermer()
{
	CloseHandle(hcom);
}

// Permet de lire sur le port com
char* RS232::lecture()
{
	int taille = 8;
	char *chaine;
	unsigned long pt;

	pt = 0;
	chaine = new char[taille+1];
	chaine[0]='\0';
	ReadFile(hcom,chaine,taille,&pt,NULL);
	PurgeComm(hcom,PURGE_RXCLEAR);

	return chaine;
}
