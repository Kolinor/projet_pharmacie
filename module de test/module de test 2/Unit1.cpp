﻿//---------------------------------------------------------------------------

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
	delete trame;
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
	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	tcp = new tcpClient();
	if (tcp->connected("192.168.64.200",502) == true)
	{
		Shape1->Brush->Color = clLime;
	}
	else
	{
		Shape1->Brush->Color = clRed;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
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
	trame[9] = 0x07;
	trame[10] = 0x00;
	trame[11] = 0x01;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
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
	trame[9] = 0x07;
	trame[10] = 0x00;
	trame[11] = 0x00;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
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
	trame[9] = 0x05;
	trame[10] = 0x00;
	trame[11] = 0x01;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
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
	trame[9] = 0x05;
	trame[10] = 0x00;
	trame[11] = 0x00;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
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
	trame[9] = 0x00;
	trame[10] = 0x00;
	trame[11] = 0x00;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
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
	trame[9] = 0x00;
	trame[10] = 0x00;
	trame[11] = 0x01;

	tcp->sendChar(trame,12);
	delete trame;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	delete tcp;
    Shape1->Brush->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Memo1->Clear();
	unsigned char * trame;
	trame = new unsigned char[12];
	trame[0] = 0x00;
	trame[1] = 0x00;
	trame[2] = 0x00;
	trame[3] = 0x00;
	trame[4] = 0x00;
	trame[5] = 0x06;
	trame[6] = 0x00;
	trame[7] = 0x04;
	trame[8] = 0x00;
	trame[9] = 0x01;
	trame[10] = 0x00;
	trame[11] = 0x04;

	tcp->sendChar(trame,12);
	delete trame;


	char buffer[4096];
	int bytes = tcp->readChar(buffer);
	Sleep(500);

	if(buffer[7] == 0x04)
	{
		if (buffer[14] == 1) {
			Memo1->Lines->Add("capteur 1 allume");
		}
		else {
			Memo1->Lines->Add("capteur 1 etteint");
		}

		if (buffer[12] == 1) {
			Memo1->Lines->Add("capteur 2 allume");
		}
		else {
			Memo1->Lines->Add("capteur 2 etteint");
		}

		if (buffer[10] == 1) {
			Memo1->Lines->Add("capteur 3 allume");
		}
		else {
			Memo1->Lines->Add("capteur 3 etteint");
		}
		if (buffer[16] == 1) {
			Memo1->Lines->Add("capteur 4 allume");
		}
		else {
			Memo1->Lines->Add("capteur 4 etteint");
		}
	}


}
//---------------------------------------------------------------------------

