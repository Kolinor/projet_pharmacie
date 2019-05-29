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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tcp = new tcpClient();
	tcp->connected("192.168.64.200",502);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	unsigned char * trame;
	trame = new unsigned char[12];
	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;
	trame[7] = 0x06;
	trame[8] = 0x00;
	trame[9] = 0x06;
	trame[10] = 0x00;
	trame[11] = 0x01;

	tcp->sendChar(trame,12);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	unsigned char * trame;
	trame = new unsigned char[12];
	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;
	trame[7] = 0x06;
	trame[8] = 0x00;
	trame[9] = 0x06;
	trame[10] = 0x00;
	trame[11] = 0x00;

	tcp->sendChar(trame,12);
}
//---------------------------------------------------------------------------
