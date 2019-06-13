//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "PopUp_Confirmation_BilanDesVentes.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TPopUp_Confirmation *PopUp_Confirmation;
//---------------------------------------------------------------------------

__fastcall TPopUp_Confirmation::TPopUp_Confirmation(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TPopUp_Confirmation::Bouton_OuiClick(TObject *Sender)
{
	Bilan = new BilanExcel() ;
	Bilan->recupererInformations() ;

	PopUp_Confirmation->Visible = false ;
}
//---------------------------------------------------------------------------

void __fastcall TPopUp_Confirmation::Bouton_NonClick(TObject *Sender)
{
	PopUp_Confirmation->Visible = false ;
}
//---------------------------------------------------------------------------
