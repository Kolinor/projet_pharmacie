//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_Caisse.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TIHM *IHM;
//---------------------------------------------------------------------------

// Constructeur de l'IHM Caisse, cr�ation de l'objet BDD
__fastcall TIHM::TIHM(TComponent* Owner) : TForm(Owner)
{
	BDD = new MysqlPharmacieManager() ;
}
//---------------------------------------------------------------------------

// Bouton qui permet d'afficher l'interface de saisi de l'ordonnance
void __fastcall TIHM::Bouton_OrdonnanceClick(TObject *Sender)
{
	String caisse = ComboBox_Caisse->Text ;

	if (ComboBox_Caisse->Text != "")
	{
        Label_MsgCaisse->Visible = false;
		Ordonnance->Visible = true ;
		BDD->createOrdonnance(caisse) ;
	}

	else
	{
		Label_MsgCaisse->Visible = true;
    }
}
//---------------------------------------------------------------------------

// Bouton qui permet d'afficher l'interface de la visualisation de l'�tat des commandes
void __fastcall TIHM::Bouton_EtatCommandeClick(TObject *Sender)
{
    Form_Etat->Visible = true ;
}
//---------------------------------------------------------------------------

// Bouton qui permet d'afficher l'interface qui sert � t�l�charger les bilans de vente
void __fastcall TIHM::Bouton_BilanClick(TObject *Sender)
{
	Form_Bilan->Visible = true ;
}
//---------------------------------------------------------------------------

