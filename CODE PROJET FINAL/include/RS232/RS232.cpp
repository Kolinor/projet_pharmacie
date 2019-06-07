//---------------------------------------------------------------------------

#pragma hdrstop

#include "RS232.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

RS232::RS232()
{
	this->etatThread = true;
    this->lecture();
}

RS232::~RS232()
{
	this->etatThread = false;
}

bool RS232::ouverture()
{
	hcom = CreateFile(L"COM2",GENERIC_WRITE|GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,NULL);

	if (hcom == INVALID_HANDLE_VALUE) {
		return false;
	}

	GetCommState(hcom,&serie);
	serie.BaudRate = 115200;
	serie.ByteSize = 8;
	serie.Parity = NOPARITY;
	serie.StopBits = ONESTOPBIT;
	SetCommState(hcom,&serie);

	return true;
}

void RS232::fermer()
{
	CloseHandle(hcom);
}

bool RS232::ecriture(char * str)
{


	unsigned long pt = 0;

	WriteFile(hcom, str, strlen(str), &pt, NULL);
	PurgeComm(hcom, PURGE_TXCLEAR);

	return true;

	
}

void RS232::lecture()
{
	over.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	SetCommMask(hcom, EV_RXCHAR);
	PurgeComm(hcom, PURGE_RXCLEAR);
	Thread = CreateThread(NULL,0,this->threadLecture,this,0,NULL);
}

DWORD WINAPI RS232::threadLecture(LPVOID lpParam)
{
	RS232 * com = (RS232*)lpParam;
	int taille = 8;
	char *chaine;
	int code;
	unsigned long pt = 0;
	chaine = new char[taille];

	while (FALSE == WaitCommEvent(com->hcom,&com->event,&com->over))
	{

		WaitForSingleObject(com->mutex,INFINITE);
		ZeroMemory(chaine, taille);
		chaine[0]= '\0';
		ReadFile(com->hcom,chaine,10,&pt,&com->over);
		if (chaine[0] >= '0' && chaine[9] <= '9' && pt > 0) {
			code = atoi(chaine);
			com->recup(code);
		}

		PurgeComm(com->hcom, PURGE_RXCLEAR);
		ReleaseMutex(com->mutex);
		Sleep(200);
	}
	delete chaine;



	return 0;
}

void RS232::recup(int chaine)
{
	WaitForSingleObject(mutex,INFINITE);
	if (chaine > 0 && chaine <10000) {
		this->codeBarre.push_back(chaine);
	}

	ReleaseMutex(mutex);
}

int RS232::vectorCodeBarre()
{
	WaitForSingleObject(mutex,INFINITE);
	copy = codeBarre.pop_front();
	ReleaseMutex(mutex);
	return copy;
}


