//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_BilanDesVentes.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bouton_BilanVentesClick(TObject *Sender)
{
	// Affichage de la fenetre de confirmation
	Form2->Visible = true ;
}
//---------------------------------------------------------------------------
