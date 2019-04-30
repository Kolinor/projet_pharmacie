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
	pmodBus = new modBus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	bool verifco = pmodBus->connected("192.168.64.200",502);

//	unsigned char * test = new unsigned char[14];
	unsigned char * trame;
	trame = new unsigned char[14];
	int bytes = pmodBus->readWord(0001);



	if (trame[14] == 1) {
		Memo1->Lines->Add("capteur 1 allum�");
	}
	else {
		Memo1->Lines->Add("capteur 1 �tteint");
	}

	if (trame[12] == 1) {
		Memo1->Lines->Add("capteur 2 allum�");
	}
	else {
		Memo1->Lines->Add("capteur 2 �tteint");
	}

	if (trame[10] == 1) {
		Memo1->Lines->Add("capteur 3 allum�");
	}
	else {
		Memo1->Lines->Add("capteur 3 �tteint");
	}

}
//---------------------------------------------------------------------------

