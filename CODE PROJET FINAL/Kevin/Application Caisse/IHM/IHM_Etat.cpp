//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_Etat.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Etat *Form_Etat;
//---------------------------------------------------------------------------

//  Constructeur, cr�ation d'un Thread et du tableau d'affichage de l'�tat de l'ordonnance
__fastcall TForm_Etat::TForm_Etat(TComponent* Owner) : TForm(Owner)
{
	this->threadEtatT = true;
	Thread = CreateThread(NULL,0,this->threadEtat,this,0,NULL);

	StringGrid_Etat->Cells[0][0]= "Caisse n�" ;
	StringGrid_Etat->Cells[1][0] = "Etat de la commande" ;
	StringGrid_Etat->Cells[2][0] = "Date de la commande" ;
}
//---------------------------------------------------------------------------

// Bouton qui permet de quitter l'IHM Etat des commandes et le Thread
void __fastcall TForm_Etat::Bouton_QuitterClick(TObject *Sender)
{
	this->threadEtatT = false;
	Form_Etat->Visible = false ;
}
//---------------------------------------------------------------------------

// M�thode Thread qui permet de r�cuperer l'�tat des commandes en temps r�el
DWORD WINAPI TForm_Etat::threadEtat(LPVOID lpParam)
{
	TForm_Etat * IHMEtat = (TForm_Etat*)lpParam;

	while (IHMEtat->threadEtatT == true)
	{
		IHMEtat->FDQuery_Etat->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '1' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
		IHMEtat->StringGrid_Etat->Cells[0][1] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Numero_Caisse")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[1][1] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Etat")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[2][1] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;

		IHMEtat->FDQuery_Etat->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '2' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
		IHMEtat->StringGrid_Etat->Cells[0][2] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Numero_Caisse")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[1][2] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Etat")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[2][2] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;

		IHMEtat->FDQuery_Etat->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '3' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
		IHMEtat->StringGrid_Etat->Cells[0][3] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Numero_Caisse")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[1][3] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Etat")->AsString ;
		IHMEtat->StringGrid_Etat->Cells[2][3] = IHMEtat->DataSource_Etat->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;
		Sleep(100);
	}
	return 0;
}

// A la fermeture de l'IHM Etat le thread ce termine
void __fastcall TForm_Etat::FormClose(TObject *Sender, TCloseAction &Action)
{
	this->threadEtatT = false;
}
//---------------------------------------------------------------------------

