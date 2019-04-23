//---------------------------------------------------------------------------
//-- IHM_BilanDesVentes -----------------------------------------------------
//-- D�velopp� par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_BilanDesVentesH
#define IHM_BilanDesVentesH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "IHM_Confirmation_BilanDesVentes.h"
#include "BilanExcel.h"
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
	// Composants g�r�s par l'EDI
	__published:
	TButton *Bouton_BilanVentes;
	void __fastcall Bouton_BilanVentesClick(TObject *Sender);

	// D�clarations utilisateur
	private:

	// D�clarations utilisateur
	public:
		__fastcall TForm1(TComponent* Owner);
		BilanExcel * Bilan ;
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
