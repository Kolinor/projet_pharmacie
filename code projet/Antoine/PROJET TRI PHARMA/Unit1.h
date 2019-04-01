//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "BDDSQL.h"
#include <Vcl.Grids.hpp>
#include <string>
#include "MysqlPharmacieManager.h"
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TRadioButton *Rbt_Medicament;
	TRadioButton *Rbt_Automate;
	TGroupBox *Grb_Automate;
	TGroupBox *Grb_Medicament;
	TLabel *Lbl_Title;
	TComboBox *Cmb_Medicament;
	TLabel *Lbl_Consigne;
	TEdit *Edit_nomMedicament;
	TEdit *Edit_hauteur;
	TEdit *Edit_largeur;
	TLabel *Lbl_Nom_Medicament;
	TLabel *Lbl_Hauteur;
	TLabel *Lbl_Largeur;
	TLabel *Lbl_Longueur;
	TEdit *Edit_longueur;
	TEdit *Edit_codeBarre;
	TLabel *Lbl_Code_Barre;
	TLabel *Lbl_Prix;
	TEdit *Edit_prix;
	TStringGrid *StringGrid1;
	TEdit *Edit_cle;
	TEdit *Edit_value;
	TLabel *lbl_cle;
	TLabel *lbl_value;
	TButton *Btn_sendAutomate;
	TGroupBox *Grb_Ordonance;
	TRadioButton *Rbt_Ordonnance;
	TButton *Btn_sendMedicament;
	TButton *Btn_sendOrdonnance;
	void __fastcall Btn_sendAutomateClick(TObject *Sender);
private: BDDSQL sql;	// D�clarations utilisateur
		 MysqlPharmacieManager *manager;
public:		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
