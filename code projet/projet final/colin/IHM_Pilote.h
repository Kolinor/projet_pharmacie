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
#include "threadEtat.h"

using namespace std;

//---------------------------------------------------------------------------
class TIHM : public TForm
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
	TGroupBox *Etat;
	TLabel *lblTapis;
	TLabel *lblCapteur1;
	TLabel *lblCapteur2;
	TLabel *lblPiston1;
	TLabel *lblPiston2;
	TLabel *lblPiston3;
	TShape *shpTapis;
	TShape *shpCapteur1;
	TShape *shpCapteur2;
	TShape *shpPiston1;
	TShape *shpPiston2;
	TShape *shpPiston3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnAllumerTapisClick(TObject *Sender);
	void __fastcall btnEteindreTapisClick(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall btnConnexionClick(TObject *Sender);
	void __fastcall btnDéconnexionClick(TObject *Sender);
	void __fastcall btnActiveTapisClick(TObject *Sender);
	void __fastcall btnDesactiveTapisClick(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	tapiris * pTapiris;
			threadEtat * pThreadEtat;
		// Déclarations utilisateur
public:
		// Déclarations utilisateur
	__fastcall TIHM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIHM *IHM;
//---------------------------------------------------------------------------
#endif
