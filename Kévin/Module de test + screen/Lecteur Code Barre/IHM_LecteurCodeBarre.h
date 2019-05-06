//---------------------------------------------------------------------------
//-- IHM_lecteurCodeBarre ---------------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_LecteurCodeBarreH
#define IHM_LecteurCodeBarreH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "RS232.h"
#include <IdBaseComponent.hpp>
#include <IdThreadComponent.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TGroupBox *Groupe_CodeBarre;
		TLabel *Label_CodeBarre;
		TLabel *Label_MessageErreur;
		TEdit *Edit_CodeBarre;
		TIdThreadComponent *Thread_LecteurCodeBarre;
		void __fastcall Thread_LecteurCodeBarreRun(TIdThreadComponent *Sender);
		void __fastcall Thread_LecteurCodeBarreBeforeRun(TIdThreadComponent *Sender);
		void __fastcall Thread_LecteurCodeBarreAfterRun(TIdThreadComponent *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TForm1(TComponent* Owner);
		RS232 * LecteurCodeBarre ;
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
