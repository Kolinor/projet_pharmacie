//---------------------------------------------------------------------------
//-- Class RS232 ------------------------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef RS232H
#define RS232H
#include <Windows.h>
#include <string.h>
//---------------------------------------------------------------------------

class RS232
{
	private :
		HANDLE hcom ;
		DCB serie ;

	public :
		bool ouverture() ;
		void fermeture() ;
		char * CodeBarre ;
		char * lecture() ;
};

#endif
