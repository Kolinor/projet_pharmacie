//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM_Pilote.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIHM *IHM;
//---------------------------------------------------------------------------
__fastcall TIHM::TIHM(TComponent* Owner)
	: TForm(Owner)
{
	com = new RS232();
	if (com->ouverture() == false) {
		IHM->Close();
	}

}
//---------------------------------------------------------------------------

void __fastcall TIHM::Button1Click(TObject *Sender)
{
	pTapiris->activePiston(1,0);
	pTapiris->activePiston(2,0);
}
//---------------------------------------------------------------------------

void __fastcall TIHM::btnAllumerTapisClick(TObject *Sender)
{
	pTapiris->activeTapis();
	btnAllumerTapis->Visible = false;
	btnEteindreTapis->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TIHM::btnEteindreTapisClick(TObject *Sender)
{
	pTapiris->deactivateTapis();
	btnAllumerTapis->Visible = true;
	btnEteindreTapis->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TIHM::btnConnexionClick(TObject *Sender)
{
	wchar_t* ip = edtIp->Text.c_str();
	wstring ws(ip);
	string strIp(ws.begin(), ws.end());
	pTapiris = new tapiris();


	if (pTapiris->connected(strIp,edtPort->Text.ToInt()) == true) {
		shpConnexion->Brush->Color = clLime;
		btnConnexion->Visible = false;
		btnDéconnexion->Visible = true;
		Action->Visible = true;
		Etat->Visible = true;

		pTapiris->activeCapteur();
		//threadEtat
		pThreadEtat = new threadEtat(false, pTapiris);
	}
	else
	{
		 MessageBox(
		  NULL,
		  L"Ip ou/et port non connue(s)",
		  NULL,
		  MB_OK);
		shpConnexion->Brush->Color = clRed;
		Action->Visible = false;
		Etat->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TIHM::btnDéconnexionClick(TObject *Sender)
{
	pTapiris->deactivateCapteur();
	pTapiris->deactivateTapis();
	delete pThreadEtat;
	pThreadEtat = NULL;
	delete pTapiris;

	shpConnexion->Brush->Color = clRed;
	btnDéconnexion->Visible = false;
	btnConnexion->Visible = true;
	Action->Visible = false;
	btnAllumerTapis->Visible = true;
	btnEteindreTapis->Visible = false;
	Etat->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TIHM::Button7Click(TObject *Sender)
{
	pTapiris->newDrug(Edit1->Text.ToInt());
}

//---------------------------------------------------------------------------

void __fastcall TIHM::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (btnConnexion->Visible == false) {
		this->btnDéconnexionClick(Sender);
	}
}
//---------------------------------------------------------------------------

void __fastcall TIHM::btnNouveauMédicamentClick(TObject *Sender)
{
	pTapiris->activePiston(3,0);
}
//---------------------------------------------------------------------------

void __fastcall TIHM::Button2Click(TObject *Sender)
{

	Label3->Caption = "test";
	Label2->Caption = com->vectorCodeBarre();

}
//---------------------------------------------------------------------------

