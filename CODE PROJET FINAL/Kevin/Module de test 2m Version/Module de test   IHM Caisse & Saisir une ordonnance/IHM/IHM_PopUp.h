//---------------------------------------------------------------------------
//-- IHM_PopUp --------------------------------------------------------------
//-- D�velopp� par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_PopUpH
#define IHM_PopUpH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "BilanExcel.h"
//---------------------------------------------------------------------------

class TConfirmation : public TForm
{
	// Composants g�r�s par l'EDI
	__published:
		TLabel *Label1;
		TLabel *Label2;
		TButton *Bouton_Oui;
		TButton *Bouton_Non;
	void __fastcall Bouton_OuiClick(TObject *Sender);
	void __fastcall Bouton_NonClick(TObject *Sender);

	// D�clarations utilisateur
	private:

	// D�clarations utilisateur
	public:
		__fastcall TConfirmation(TComponent* Owner);
		BilanExcel * Bilan ;
};

//---------------------------------------------------------------------------
extern PACKAGE TConfirmation *Confirmation;
//---------------------------------------------------------------------------
#endif
