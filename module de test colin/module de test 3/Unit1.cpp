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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnConnexionClick(TObject *Sender)
{
	wchar_t* ip = edtIp->Text.c_str();
	wstring ws(ip);
	string strIp(ws.begin(), ws.end());
	pmodbus = new modBus();


	if (pmodbus->connected(strIp,edtPort->Text.ToInt()) == true) {
		shpConnexion->Brush->Color = clLime;
	}
	else
	{
        shpConnexion->Brush->Color = clRed;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pmodbus->writeWord(Edit1->Text.ToInt(),Edit2->Text.ToInt());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Memo1->Clear();
	char buffer[4096];

	pmodbus->readWord(Edit3->Text.ToInt(),Edit4->Text.ToInt(),buffer);
	Sleep(500);

	if(buffer[7] == 0x04)
	{
		if (buffer[12] == 1) {
			Memo1->Lines->Add("capteur 1 allume");
		}
		else
		{
			Memo1->Lines->Add("capteur 1 etteint");
		}

		if (buffer[14] == 1) {
			Memo1->Lines->Add("capteur 2 allume");
		}
		else
		{
			Memo1->Lines->Add("capteur 2 etteint");
		}

		if (buffer[10] == 1) {
			Memo1->Lines->Add("capteur 3 allume");
		}
		else
		{
			Memo1->Lines->Add("capteur 3 etteint");
		}

		if (buffer[16] == 1) {
			Memo1->Lines->Add("capteur 4 allume");
		}
		else
		{
			Memo1->Lines->Add("capteur 4 etteint");
		}


	}



}
//---------------------------------------------------------------------------

