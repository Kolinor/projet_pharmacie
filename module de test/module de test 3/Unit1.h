//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "include\modBus\modBus.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TPanel *Panel1;
	TGroupBox *GroupBox1;
	TShape *shpConnexion;
	TButton *btnConnexion;
	TEdit *edtIp;
	TEdit *edtPort;
	TButton *Button1;
	TEdit *Edit1;
	TGroupBox *GroupBox2;
	TEdit *Edit2;
	TLabel *Label1;
	TGroupBox *GroupBox3;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label2;
	TButton *Button2;
	TMemo *Memo1;
	TMemo *Memo2;
	void __fastcall btnConnexionClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:
	modBus * pmodbus;	// Déclarations utilisateur
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
