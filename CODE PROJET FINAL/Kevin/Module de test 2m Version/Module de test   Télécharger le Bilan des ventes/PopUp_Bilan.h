//---------------------------------------------------------------------------
//-- IHM_Confirmation_BilanExcel --------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef PopUp_BilanH
#define PopUp_BilanH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------

class TForm_PopUp : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TButton *Bouton_Oui;
		TButton *Bouton_Non;
		TLabel *Label1;
		TLabel *Label2;

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TForm_PopUp(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm_PopUp *Form_PopUp;
//---------------------------------------------------------------------------
#endif
