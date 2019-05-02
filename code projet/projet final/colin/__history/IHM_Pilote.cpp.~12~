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
	pTapiris = new tapiris();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	bool verifco = pTapiris->connected("192.168.64.200",502);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pTapiris->activePiston(1);
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

