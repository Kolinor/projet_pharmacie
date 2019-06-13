//---------------------------------------------------------------------------
//-- IHM_PopUp --------------------------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
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
	// Composants gérés par l'EDI
	__published:
		TLabel *Label1;
		TLabel *Label2;
		TButton *Bouton_Oui;
		TButton *Bouton_Non;
	void __fastcall Bouton_OuiClick(TObject *Sender);
	void __fastcall Bouton_NonClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TConfirmation(TComponent* Owner);
		BilanExcel * Bilan ;
};

//---------------------------------------------------------------------------
extern PACKAGE TConfirmation *Confirmation;
//---------------------------------------------------------------------------
#endif
