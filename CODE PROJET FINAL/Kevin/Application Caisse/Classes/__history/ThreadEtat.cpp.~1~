//---------------------------------------------------------------------------
#pragma hdrstop
#include "IHM_Etat.h"
#include "ThreadEtat.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall ThreadEtat::ThreadEtat(bool CreateSuspended, TForm_Etat * IHMEtat) : TThread(CreateSuspended)
{
	this->etatThread = true;
	this->IHMEtat = IHMEtat;
}
//---------------------------------------------------------------------------

__fastcall ThreadEtat::~ThreadEtat()
{
	this->etatThread = false;
}
//---------------------------------------------------------------------------

// Méthode qui execute les méthodes EtatCaisse
void __fastcall ThreadEtat::Execute()
{
	while(this->etatThread == true)
	{
		Synchronize(EtatCaisse1) ;
		Synchronize(EtatCaisse2) ;
		Synchronize(EtatCaisse3) ;
		Sleep(2000);
	}
}
//---------------------------------------------------------------------------

// Méthode qui récupère la dernière commande de la caisse 1 avec sa date
void __fastcall ThreadEtat::EtatCaisse1()
{
	IHMEtat->FDQuery1->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '1' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
	IHMEtat->StringGrid_Etat->Cells[0][1] = IHMEtat->DataSource1->DataSet->FieldByName("Numero_Caisse")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[1][1] = IHMEtat->DataSource1->DataSet->FieldByName("Etat")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[2][1] = IHMEtat->DataSource1->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;
}
//---------------------------------------------------------------------------

// Méthode qui récupère la dernière commande de la caisse 2 avec sa date
void __fastcall ThreadEtat::EtatCaisse2()
{
	IHMEtat->FDQuery1->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '2' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
	IHMEtat->StringGrid_Etat->Cells[0][2] = IHMEtat->DataSource1->DataSet->FieldByName("Numero_Caisse")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[1][2] = IHMEtat->DataSource1->DataSet->FieldByName("Etat")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[2][2] = IHMEtat->DataSource1->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;
}
//---------------------------------------------------------------------------

// Méthode qui récupère la dernière commande de la caisse 3 avec sa date
void __fastcall ThreadEtat::EtatCaisse3()
{
	IHMEtat->FDQuery1->Open("SELECT `Numero_Caisse`,`Etat`,`Date_Saisie_Ordonnance` FROM `Ordonnance` WHERE `Numero_Caisse`= '3' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 1");
	IHMEtat->StringGrid_Etat->Cells[0][3] = IHMEtat->DataSource1->DataSet->FieldByName("Numero_Caisse")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[1][3] = IHMEtat->DataSource1->DataSet->FieldByName("Etat")->AsString ;
	IHMEtat->StringGrid_Etat->Cells[2][3] = IHMEtat->DataSource1->DataSet->FieldByName("Date_Saisie_Ordonnance")->AsString ;
}
//---------------------------------------------------------------------------
