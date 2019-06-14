//---------------------------------------------------------------------------
//-- IHM_Etat ---------------------------------------------------------------
//-- D�velopp� par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_EtatH
#define IHM_EtatH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
class ThreadEtat;
//---------------------------------------------------------------------------

class TForm_Etat : public TForm
{
	// Composants g�r�s par l'EDI
	__published:
		TStringGrid *StringGrid_Etat;
		TFDConnection *f;
		TFDQuery *FDQuery1;
		TDataSource *DataSource1;
		TFDGUIxWaitCursor *FDGUIxWaitCursor1;
		TButton *Bouton_Quitter;
		void __fastcall Bouton_QuitterClick(TObject *Sender);

	// D�clarations utilisateur
	private:
		ThreadEtat * Thread ;

	// D�clarations utilisateur
	public:
		__fastcall TForm_Etat(TComponent* Owner);

};

//---------------------------------------------------------------------------
extern PACKAGE TForm_Etat *Form_Etat;
//---------------------------------------------------------------------------
#endif