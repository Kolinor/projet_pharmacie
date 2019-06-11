//---------------------------------------------------------------------------
#ifndef IHM_LecteurH
#define IHM_LecteurH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "CRS232.h"
#include "LineParser.h"
#include <conio.h>
#include "SynchroEventListener.h"
#include <Vcl.ExtCtrls.hpp>
#include <iostream>
//---------------------------------------------------------------------------

class TForm_RS232 : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TMemo *Memo_RS232;
		TTimer *Timer_RS232;
		TComboBox *ComboBox_Com;
		TComboBox *ComboBox_Baud;
		TComboBox *ComboBox_DataSize;
		TLabel *Label_Name;
		TLabel *Label_Baud;
		TLabel *Label_DataSize;
		TLabel *Label3;
		TButton *Bouton_Connexion;
		TGroupBox *GroupBox_Serial;
		void __fastcall Timer_RS232Timer(TObject *Sender);
		void __fastcall Bouton_ConnexionClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TForm_RS232(TComponent* Owner);

	SynchroEventListener * listener ;
	Parser * parser ;
	CRS232 * comm ;
};

//---------------------------------------------------------------------------
extern PACKAGE TForm_RS232 *Form_RS232;
//---------------------------------------------------------------------------
#endif
