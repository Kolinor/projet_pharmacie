//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_PopUp.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TConfirmation *Confirmation;
//---------------------------------------------------------------------------

__fastcall TConfirmation::TConfirmation(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TConfirmation::Bouton_OuiClick(TObject *Sender)
{
	Bilan = new BilanExcel() ;
	Bilan->recupererInformations() ;

	Confirmation->Visible = false ;
}
//---------------------------------------------------------------------------

void __fastcall TConfirmation::Bouton_NonClick(TObject *Sender)
{
	Confirmation->Visible = false ;
}
//---------------------------------------------------------------------------