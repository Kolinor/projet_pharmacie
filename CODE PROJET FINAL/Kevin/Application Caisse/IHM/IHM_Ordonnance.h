//---------------------------------------------------------------------------
//-- IHM_Ordonnance ---------------------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_OrdonnanceH
#define IHM_OrdonnanceH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "IHM_Caisse.h"
#include "MysqlPharmacieManager.h"
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
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

class TOrdonnance : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TLabel *Label_Medicaments;
		TLabel *Label_Quantite;
		TComboBox *ComboBox_Medicaments;
		TButton *Bouton_OK;
		TEdit *Edit_Quantite;
		TStringGrid *StringGrid_Ordonnance;
		TButton *Bouton_Supprimer;
		TButton *Bouton_Valider;
	TFDConnection *f_Ordonnance;
	TFDQuery *FDQuery_Ordonnance;
	TDataSource *DataSource_Ordonnance;
	TFDGUIxWaitCursor *FDGUIxWaitCursor_Ordonnance;
		void __fastcall Bouton_OKClick(TObject *Sender);
		void __fastcall Bouton_SupprimerClick(TObject *Sender);
		void __fastcall Bouton_ValiderClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TOrdonnance(TComponent* Owner);
		MysqlPharmacieManager * BDD ;
};

//---------------------------------------------------------------------------
extern PACKAGE TOrdonnance *Ordonnance;
//---------------------------------------------------------------------------
#endif
