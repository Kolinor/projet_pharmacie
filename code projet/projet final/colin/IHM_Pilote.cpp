//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM_Pilote.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	bool verifco = pTapiris->connected("192.168.64.200",502);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pTapiris->activePiston(1,0);
	pTapiris->activePiston(2,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    pTapiris->activeTapis();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	pTapiris->deactivateTapis();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
//	pTapiris->test();
//	pTapiris->deactivatePiston(1);
//	pTapiris->deactivatePiston(2);
//	pTapiris->deactivatePiston(3);
	pTapiris->activePiston(3,0);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	pTapiris->disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnConnexionClick(TObject *Sender)
{
	wchar_t* ip = edtIp->Text.c_str();
	wstring ws(ip);
	string strIp(ws.begin(), ws.end());
	pTapiris = new tapiris();


	if (pTapiris->connected(strIp,edtPort->Text.ToInt()) == true) {
		shpConnexion->Brush->Color = clLime;
		btnConnexion->Visible = false;
		btnDéconnexion->Visible = true;

	}
	else
	{
        shpConnexion->Brush->Color = clRed;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btnDéconnexionClick(TObject *Sender)
{
	delete pTapiris;

	shpConnexion->Brush->Color = clRed;
	btnDéconnexion->Visible = false;
	btnConnexion->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnActiveTapisClick(TObject *Sender)
{
	pTapiris->activeCapteur();
    btnActiveTapis->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnDesactiveTapisClick(TObject *Sender)
{
    pTapiris->deactivateCapteur();
}
//---------------------------------------------------------------------------

