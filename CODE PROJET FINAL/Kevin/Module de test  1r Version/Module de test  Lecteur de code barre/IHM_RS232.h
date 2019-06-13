//---------------------------------------------------------------------------
#ifndef IHM_RS232H
#define IHM_RS232H
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "RS232.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------

class TIHM_CodeBarre : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TEdit *Edit_Reception;
		TButton *Bouton_Connexion;
		TButton *Bouton_Reception;
		TButton *Bouton_Deconnexion;
		TShape *Shape_Etat;
		TGroupBox *GroupBox_Reception;
		void __fastcall Bouton_ConnexionClick(TObject *Sender);
		void __fastcall Bouton_DeconnexionClick(TObject *Sender);
		void __fastcall Bouton_ReceptionClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TIHM_CodeBarre(TComponent* Owner);
		RS232 * portCom ;
};

//---------------------------------------------------------------------------
extern PACKAGE TIHM_CodeBarre *IHM_CodeBarre;
//---------------------------------------------------------------------------
#endif
