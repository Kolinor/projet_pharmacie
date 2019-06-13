//---------------------------------------------------------------------------
//-- PopUp_Confirmation_BilanExcel ------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef PopUp_Confirmation_BilanDesVentesH
#define PopUp_Confirmation_BilanDesVentesH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "BilanExcel.h"
//---------------------------------------------------------------------------

class TPopUp_Confirmation : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TButton *Bouton_Oui;
		TButton *Bouton_Non;
		TLabel *Label1;
		TLabel *Label2;
		void __fastcall Bouton_OuiClick(TObject *Sender);
		void __fastcall Bouton_NonClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TPopUp_Confirmation(TComponent* Owner);
		BilanExcel * Bilan ;
};

//---------------------------------------------------------------------------
extern PACKAGE TPopUp_Confirmation *PopUp_Confirmation;
//---------------------------------------------------------------------------
#endif
