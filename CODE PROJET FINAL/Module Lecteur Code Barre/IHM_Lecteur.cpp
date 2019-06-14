//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_Lecteur.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_RS232 *Form_RS232;
//---------------------------------------------------------------------------

__fastcall TForm_RS232::TForm_RS232(TComponent* Owner) : TForm(Owner)
{
	listener = new SynchroEventListener() ;
	parser = new LineParser() ;
}
//---------------------------------------------------------------------------


void __fastcall TForm_RS232::Timer_RS232Timer(TObject *Sender)
{
	while (listener->getMessages().Size() > 0)
	{
		Message * msg = listener->getMessages().Get();
		this->Memo_RS232->Lines->Add("Ligne re�ue : ");
		UnicodeString str = UnicodeString();
		for (int i = 0; i < msg->getData().size(); i++)
		{
			str += msg->getData()[i];
		}
		this->Memo_RS232->Lines->Add(str);
		delete msg;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_RS232::Bouton_ConnexionClick(TObject *Sender)
{
	int Baud = ComboBox_Baud->Text.ToInt() ;
	int DataSize = ComboBox_DataSize->Text.ToInt() ;
	wchar_t * COM = ComboBox_Com->Text.c_str() ;
	int len = wcslen(COM);
	char * conversion = new char[len + 1];
	wcstombs(conversion, COM, len);
	conversion[len] = '\0';

	parser->addSerialEventListener(listener) ;
	comm = new CRS232(conversion, Baud, DataSize, NOPARITY, ONESTOPBIT, parser) ;
}
//---------------------------------------------------------------------------