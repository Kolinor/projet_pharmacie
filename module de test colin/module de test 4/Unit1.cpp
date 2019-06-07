//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
	pTapiris->newDrug(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (pTapiris->connected("192.168.64.200",502) == true) {
		Shape1->Brush->Color = clLime;

		pTapiris->activeCapteur();
	}
	else {
		Shape1->Brush->Color = clRed;
    }
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
	pTapiris->activePiston(3,0);
}
//---------------------------------------------------------------------------

