//---------------------------------------------------------------------------
//-- Classe ThreadEtat ------------------------------------------------------
//-- D�velopp� par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef ThreadEtatH
#define ThreadEtatH
#include "IHM_Etat.h"
#include <vcl.h>
//---------------------------------------------------------------------------

class ThreadEtat : public TThread
{
	private:
		bool etatThread;
		TForm_Etat * IHMEtat;

	protected:
		void __fastcall Execute();
		void __fastcall EtatCaisse1();
		void __fastcall EtatCaisse2();
		void __fastcall EtatCaisse3();

	public:
		__fastcall ThreadEtat(bool CreateSuspended, TForm_Etat * IHMEtat);
		__fastcall ~ThreadEtat();
};

#endif
