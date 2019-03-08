//---------------------------------------------------------------------------

#ifndef RS232H
#define RS232H
#include <windows.h>
//---------------------------------------------------------------------------
class COM
{
	private:
		HANDLE hcom;
		DCB serie;
		OVERLAPPED over;


	public:

		bool ouverture(); //permet d'initialiser le port com
		void fermer(); //permet de fermer le port com
		bool ecriture(char* str, int taille); //permet d'�crire sur le port com
		char* lecture(); //permet de lire sur le port com

};

#endif