//---------------------------------------------------------------------------
#ifndef RS232H
#define RS232H
#include <windows.h>
//---------------------------------------------------------------------------
class RS232
{
	private:
		HANDLE hcom;
		DCB serie;
		// OVERLAPPED over;

	public:

		// Permet d'initialiser le port com
		bool ouverture();

		// Permet de fermer le port com
		void fermer();

		// Permet de lire sur le port com
		char* lecture();
};
#endif
