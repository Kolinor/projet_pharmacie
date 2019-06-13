//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_Caisse.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TIHM *IHM;
//---------------------------------------------------------------------------

__fastcall TIHM::TIHM(TComponent* Owner) : TForm(Owner)
{
	BDD = new MysqlPharmacieManager() ;
}
//---------------------------------------------------------------------------

void __fastcall TIHM::Bouton_OrdonnanceClick(TObject *Sender)
{
	String caisse = ComboBox_Caisse->Text ;
	if (ComboBox_Caisse->Text != "")
	{
		Ordonnance->Visible = true ;
        BDD->createOrdonnance(caisse) ;
	}
}
//---------------------------------------------------------------------------
void __fastcall TIHM::Bouton_BilanClick(TObject *Sender)
{
	Confirmation->Visible = true ;
}
//---------------------------------------------------------------------------
void __fastcall TIHM::Bouton_EtatCommandeClick(TObject *Sender)
{
    Form_Etat->Visible = true ;
}
//---------------------------------------------------------------------------

