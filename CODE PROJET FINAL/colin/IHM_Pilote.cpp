//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHM_Pilote.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIHM *IHM;
//---------------------------------------------------------------------------
__fastcall TIHM::TIHM(TComponent* Owner)
	: TForm(Owner)
{
	listener = new SynchroEventListener();
	parser = new LineParser();

	UnicodeString test = "COM1";
	wchar_t * COM = test.c_str();
	int len = wcslen(COM);
	char * conversion = new char[len + 1];
	wcstombs(conversion, COM, len);
	conversion[len] = '\0';
	parser->addSerialEventListener(listener) ;
	com = new CRS232(conversion,9600,8,NOPARITY,ONESTOPBIT, parser);
	sql = new MysqlPharmacieManager();
	pTapiris = new tapiris();
	conf = new TIniFile("C:\\Program Files (x86)\\PharmaciePilote\\conf.ini");
							  //C:\\Program_Files_(x86)\\PharmaciePilote\\conf.ini
							  //C:\\Users\\Administrateur\\Documents\\GitHub\\projet_pharmacie\\CODE PROJET FINAL\\colin\\conf.ini
	char adrSave[50];
	char portSave[50];

	String adresse = conf->ReadString("Adresse","adr","");
	wcstombs(adrSave,adresse.c_str(),adresse.Length()+1);
	String port = conf->ReadString("Port","port","");
	wcstombs(portSave,port.c_str(),port.Length()+1);

	if (pTapiris->connected(adrSave,atoi(portSave)) == true) {

		lbl_adr->Caption = adresse;
		lbl_port->Caption = port;
		pTapiris->activeCapteur();
		//threadEtat
		pThreadEtat = new threadEtat(false, pTapiris);

		tmRS232->Enabled = true;
//        pTapiris->activeTapis();
	}
	else {
         MessageBox(
		  NULL,
		  "Impossible de se connecter",
		  NULL,
		  MB_OK);
		IHM->Close();
	}


}
//---------------------------------------------------------------------------
void __fastcall TIHM::tmRS232Timer(TObject *Sender)
{
	while (listener->getMessages().Size() > 0)
	{
		Message * msg = listener->getMessages().Get();
		UnicodeString str = UnicodeString();
		for (int i = 0; i < msg->getData().size(); i++)
		{   if (msg->getData()[i] != '\r') {
				str += msg->getData()[i];
			}

		}

		int caisse = sql->selectCaisse(str);
		pTapiris->newDrug(caisse);
		delete msg;
	}
}
//---------------------------------------------------------------------------
void __fastcall TIHM::FormClose(TObject *Sender, TCloseAction &Action)
{
	pTapiris->deactivateTapis();
}
//---------------------------------------------------------------------------

