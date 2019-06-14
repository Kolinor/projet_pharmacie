//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_Bilan.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Bilan *Form_Bilan;
//---------------------------------------------------------------------------

__fastcall TForm_Bilan::TForm_Bilan(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_Bilan::FormCreate(TObject *Sender)
{
	FDQuery1->Open("SELECT * FROM `Medicament` WHERE `Quantite_Restante` != 0");

	for (int i = 0; i < FDQuery1->RowsAffected; i++)
	{
		ComboBox_Medicament->Items->Add(DataSource1->DataSet->FieldByName("Nom_Medicament")->AsString);
		DataSource1->DataSet->FindNext();
	}

	Bilan = new BilanExcel() ;
}
//---------------------------------------------------------------------------


void __fastcall TForm_Bilan::Bouton_TelechargerClick(TObject *Sender)
{
	if (ComboBox_Periode->Text != "P�riode de vente")
	{
		String periode = ComboBox_Periode->Text ;

		if (ComboBox_Medicament->Text != "M�dicament")
		{
			String medicament = ComboBox_Medicament->Text ;
			Bilan->BilanMedicament(periode, medicament);
		}


		else
		{
			Bilan->BilanPeriode(periode);
		}

		Form_Bilan->~TForm_Bilan();
	}

	else
	{
		Label_Periode->Visible = true ;
	}
}
//---------------------------------------------------------------------------

