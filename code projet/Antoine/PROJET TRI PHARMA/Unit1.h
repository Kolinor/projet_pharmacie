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
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.Comp.UI.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.MySQL.hpp>
#include <FireDAC.Phys.MySQLDef.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Vcl.DBGrids.hpp>
#include <string>
#include "MysqlPharmacieManager.h"
using namespace std;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TRadioButton *Rbt_addMedicament;
	TRadioButton *Rbt_Automate;
	TGroupBox *Grb_Automate;
	TGroupBox *Grb_addMedicament;
	TLabel *Lbl_Title;
	TComboBox *Cmb_MedicamentModifier;
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
	TEdit *Edit_cle;
	TEdit *Edit_value;
	TLabel *lbl_cle;
	TLabel *lbl_value;
	TButton *Btn_sendAutomate;
	TGroupBox *Grb_Ordonance;
	TRadioButton *Rbt_Ordonnance;
	TButton *Btn_sendMedicament;
	TButton *Btn_sendOrdonnance;
	TGroupBox *Grb_update;
	TRadioButton *Rbt_Update;
	TEdit *Edit_numeroCaisse;
	TLabel *Lbl_numeroCaisse;
	TLabel *Lbl_nombreMedicament;
	TEdit *Edit_nombreMedicament;
	TLabel *Lbl_nombreMedicamentSaisie;
	TButton *Bt_SupprimerDernierMedicamentSaisie;
	TButton *Bt_AjouterMedicament;
	TComboBox *Cmb_medicamentOrdonnance;
	TLabel *Lbl_MedicamentOrdonnance;
	TLabel *Lbl_nbrMédicamentAjoute;
	TButton *Btn_modifierMedicament;
	TFDGUIxWaitCursor *FDGUIxWaitCursor_Pharma;
	TDataSource *DataSource_Pharma;
	TFDQuery *FDQuery_Pharma;
	TFDConnection *FDConnection_Pharma;
	TDBGrid *DBGrid1;
	TDataSource *DataSource_update;
	TFDQuery *FDQuery_update;
	TButton *Bt_CreateOrdonnance;
	TLabel *Label1;
	TButton *Button1;
	void __fastcall Btn_sendAutomateClick(TObject *Sender);
	void __fastcall Btn_sendMedicamentClick(TObject *Sender);
	void __fastcall Rbt_addMedicamentClick(TObject *Sender);
	void __fastcall Rbt_AutomateClick(TObject *Sender);
	void __fastcall Rbt_OrdonnanceClick(TObject *Sender);
	void __fastcall Rbt_UpdateClick(TObject *Sender);
	void __fastcall Cmb_MedicamentModifierEnter(TObject *Sender);
	void __fastcall Bt_CreateOrdonnanceClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private: BDDSQL sql;	// Déclarations utilisateur
		 MysqlPharmacieManager *manager;
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
