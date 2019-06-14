//---------------------------------------------------------------------------
//-- IHM_Confirmation_BilanExcel --------------------------------------------
//-- D�velopp� par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_Confirmation_BilanDesVentesH
#define IHM_Confirmation_BilanDesVentesH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "BilanExcel.h"
//---------------------------------------------------------------------------

class TForm2 : public TForm
{
	// Composants g�r�s par l'EDI
	__published:
	TButton *Bouton_Oui;
	TButton *Bouton_Non;
		TLabel *Label1;
		TLabel *Label2;
		void __fastcall Bouton_OuiClick(TObject *Sender);
		void __fastcall Bouton_NonClick(TObject *Sender);

	// D�clarations utilisateur
	private:

	// D�clarations utilisateur
	public:
		__fastcall TForm2(TComponent* Owner);
		BilanExcel * Bilan ;
};

//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif