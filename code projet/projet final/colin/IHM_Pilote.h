//---------------------------------------------------------------------------

#ifndef IHM_PiloteH
#define IHM_PiloteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "../include/tapiris/tapiris.h"
#include <Vcl.ExtCtrls.hpp>

using namespace std;

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *Button1;
	TButton *btnAllumerTapis;
	TButton *btnEteindreTapis;
	TButton *Button5;
	TGroupBox *GroupBox1;
	TButton *btnConnexion;
	TEdit *edtIp;
	TEdit *edtPort;
	TShape *shpConnexion;
	TButton *btnDéconnexion;
	TButton *btnActiveTapis;
	TGroupBox *Action;
	TButton *btnDesactiveTapis;
	TButton *Button7;
	TEdit *Edit1;
	TMemo *Memo1;
	TGroupBox *Etat;
	TLabel *lblTapis;
	TLabel *lblCapteur1;
	TLabel *lblCapteur2;
	TLabel *lblPiston1;
	TLabel *lblPiston2;
	TLabel *lblPiston3;
	TLabel *lblTapisRep;
	TLabel *lblCapteur1Rep;
	TLabel *lblCapteur2Rep;
	TLabel *lblPiston1Rep;
	TLabel *lblPiston2Rep;
	TLabel *lblPiston3Rep;
	TTimer *tmEtat;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnAllumerTapisClick(TObject *Sender);
	void __fastcall btnEteindreTapisClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall btnConnexionClick(TObject *Sender);
	void __fastcall btnDéconnexionClick(TObject *Sender);
	void __fastcall btnActiveTapisClick(TObject *Sender);
	void __fastcall btnDesactiveTapisClick(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall tmEtatTimer(TObject *Sender);
private:	tapiris * pTapiris;
		// Déclarations utilisateur
public:
		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
