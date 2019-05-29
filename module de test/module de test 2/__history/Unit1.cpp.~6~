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

	pThreadConnection = new threadConnection(true);
	pThreadConnection->OnTerminate = finThread;
	EnableWindow(Handle, false);

}

//---------------------------------------------------------------------------
void __fastcall  TForm1::finThread(TObject *Sender)
{
		EnableWindow(Handle, true);
		delete pThreadConnection;
		pThreadConnection = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	  if(pThreadConnection) Action = caNone;
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
