//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_LecteurCodeBarre.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	LecteurCodeBarre = new RS232() ;
}
//---------------------------------------------------------------------------

// Ouvre la connexion RS232
 void __fastcall TForm1::Thread_LecteurCodeBarreBeforeRun(TIdThreadComponent *Sender)
{
	LecteurCodeBarre->ouverture() ;

	if (LecteurCodeBarre->ouverture()==true)
	{
		Label_MessageErreur->Visible = false ;
	}

	else
	   Label_MessageErreur->Visible = true ;
}
//---------------------------------------------------------------------------

// Recoit et affiche la trame du lecteur code barre
void __fastcall TForm1::Thread_LecteurCodeBarreRun(TIdThreadComponent *Sender)
{
	LecteurCodeBarre->lecture() ;
	Edit_CodeBarre->Text =  LecteurCodeBarre->CodeBarre ;
}
//---------------------------------------------------------------------------

// Ferme la connexion RS232
void __fastcall TForm1::Thread_LecteurCodeBarreAfterRun(TIdThreadComponent *Sender)
{
	LecteurCodeBarre->fermeture() ;
}
//---------------------------------------------------------------------------

