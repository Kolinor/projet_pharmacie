//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	this->manager = new MysqlPharmacieManager();


	this->manager->insertOrdonnance();

//	sql.connect("192.168.64.111","pharma","pharma","pharmacie");
	//	string requete="INSERT INTO pharmacie.test (id) VALUES (25);";
//	string requete="INSERT INTO `Medicament`(`Nom_Medicament`, `Hauteur`, `Largeur`, `Longueur`, `Quantite_Restante`, `Code_Barre`, `Prix`, `Nombre_Unite_Vendu`) VALUES ('Doliprane','10','50','20','30','84785','99.99','0');";
//	string requeteOrdonnance="INSERT INTO `Ordonnance`(`Etat`, `Numero_Caisse`, `Date_Saisie_Ordonnance`) VALUES (0,1,now());";
//	string requeteUpdateMedicament="UPDATE `Medicament` SET `ID_Medicament`=[value-1],`Nom_Medicament`=[value-2],`Hauteur`=[value-3],`Largeur`=[value-4],`Longueur`=[value-5],`Quantite_Restante`=[value-6],`Code_Barre`=[value-7],`Prix`=[value-8],`Nombre_Unite_Vendu`=[value-9] WHERE 1);";

//	sql.insert(requete);
//	sql.insert(requeteOrdonnance);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Btn_sendAutomateClick(TObject *Sender)
{
	manager->insertTapiris(Edit_cle->Text, Edit_value->Text);
	Edit_value->Clear();
    Edit_cle->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Btn_sendMedicamentClick(TObject *Sender)
{
	manager->insertMedicament(Edit_nomMedicament->Text , Edit_hauteur->Text , Edit_largeur->Text , Edit_longueur->Text , Edit_codeBarre->Text , Edit_prix->Text);
	Edit_nomMedicament->Clear();
	Edit_longueur->Clear();
	Edit_largeur->Clear();
	Edit_hauteur->Clear();
	Edit_codeBarre->Clear();
    Edit_prix->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Rbt_addMedicamentClick(TObject *Sender)
{
//	Grb_addMedicament->Visible=true;
//	Grb_Automate->Visible=false;
//	Grb_Ordonance->Visible=false;
//	Grb_update->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rbt_AutomateClick(TObject *Sender)
{
//	Grb_addMedicament->Visible=false;
//	Grb_Automate->Visible=true;
//	Grb_Ordonance->Visible=false;
//	Grb_update->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rbt_OrdonnanceClick(TObject *Sender)
{
//	Grb_addMedicament->Visible=false;
//	Grb_Automate->Visible=false;
//	Grb_Ordonance->Visible=true;
//	Grb_update->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rbt_UpdateClick(TObject *Sender)
{
//	Grb_addMedicament->Visible=false;
//	Grb_Automate->Visible=false;
//	Grb_Ordonance->Visible=false;
//	Grb_update->Visible=true;
}
//---------------------------------------------------------------------------





