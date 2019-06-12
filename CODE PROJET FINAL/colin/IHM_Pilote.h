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
__published:	// Composants g�r�s par l'EDI
	TGroupBox *lblIp;
	TButton *btnConnexion;
	TEdit *edtIp;
	TEdit *edtPort;
	TShape *shpConnexion;
	TButton *btnD�connexion;
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
	TTimer *tmRS232;
	void __fastcall btnD�connexionClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall tmRS232Timer(TObject *Sender);
private:	tapiris * pTapiris;
			threadEtat * pThreadEtat;
			SynchroEventListener * listener;
			Parser * parser;
			CRS232 * com;
			MysqlPharmacieManager * sql;
			TIniFile * conf;
		// D�clarations utilisateur
public:
		// D�clarations utilisateur
	__fastcall TIHM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIHM *IHM;
//---------------------------------------------------------------------------
#endif
