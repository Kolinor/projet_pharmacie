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
#include "../include/MysqlPharmacieManager/MysqlPharmacieManager.h"
#include "../include/RS232/CRS232.h"
#include "../include/RS232/LineParser.h"
#include "../include/RS232/SynchroEventListener.h"
#include <Vcl.ExtCtrls.hpp>
#include "threadEtat.h"
#include <iostream>
#include <conio.h>
#include <IniFiles.hpp>

using namespace std;

//---------------------------------------------------------------------------
class TIHM : public TForm
{
__published:	// Composants gérés par l'EDI
	TGroupBox *lblIp;
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
	TLabel *lbl;
	TLabel *lblPort;
	TTimer *tmRS232;
	TLabel *lbl_adr;
	TLabel *lbl_port;
	TShape *shpCapteur3;
	TLabel *lblCapteur3;
	void __fastcall tmRS232Timer(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	tapiris * pTapiris;
			threadEtat * pThreadEtat;
			SynchroEventListener * listener;
			Parser * parser;
			CRS232 * com;
			MysqlPharmacieManager * sql;
			TIniFile * conf;
		// Déclarations utilisateur
public:
		// Déclarations utilisateur
	__fastcall TIHM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIHM *IHM;
//---------------------------------------------------------------------------
#endif
