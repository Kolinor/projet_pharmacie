//---------------------------------------------------------------------------

#ifndef IHM_PiloteH
#define IHM_PiloteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "../include/tapiris/tapiris.h"
#include "../include/RS232/RS232.h"
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
	TGroupBox *lblIp;
	TButton *btnConnexion;
	TEdit *edtIp;
	TEdit *edtPort;
	TShape *shpConnexion;
	TButton *btnDéconnexion;
	TGroupBox *Action;
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
	TLabel *Label1;
	TLabel *lblPort;
	TButton *btnNouveauMédicament;
	TButton *Button2;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall btnAllumerTapisClick(TObject *Sender);
	void __fastcall btnEteindreTapisClick(TObject *Sender);
	void __fastcall btnConnexionClick(TObject *Sender);
	void __fastcall btnDéconnexionClick(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btnNouveauMédicamentClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);

private:	tapiris * pTapiris;
			threadEtat * pThreadEtat;
			RS232 * com;
		// Déclarations utilisateur
public:
		// Déclarations utilisateur
	__fastcall TIHM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIHM *IHM;
//---------------------------------------------------------------------------
#endif
