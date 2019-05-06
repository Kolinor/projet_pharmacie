//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "threadConnection.h"

#include "Unit1.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important : les m�thodes et les propri�t�s des objets de la VCL ne peuvent �tre
//   utilis�es que dans une m�thode appel�e en utilisant Synchronize, comme :
//
//      Synchronize(UpdateCaption);
//
//   o� UpdateCaption serait de la forme :
//
//      void __fastcall TMonThread::UpdateCaption()
//      {
//        Form1->Caption = "Mise � jour dans un thread";
//      }
//---------------------------------------------------------------------------

__fastcall threadConnection::threadConnection(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall threadConnection::Execute()
{
        //----  Placer le code du thread ici  ----
		tcp = new tcpClient();
		if (tcp->connected("192.168.64.200",502) == true)
		{
			this->etatCon = true;
		}
		else {
			this->etatCon = false;
		}
		Synchronize(shapeConnection);
//		WaitForSingleObject(, INFINITE);
}
//---------------------------------------------------------------------------
void __fastcall threadConnection::shapeConnection()
{
	if (etatCon == true) {
		Form1->Shape1->Brush->Color = clLime ;
	}
	else {
		Form1->Shape1->Brush->Color = clRed;
	}
}