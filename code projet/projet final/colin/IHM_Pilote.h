//---------------------------------------------------------------------------

#ifndef IHM_PiloteH
#define IHM_PiloteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "../include/modBus/modBus.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *Button1;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
private:	modBus * pmodBus;
		// D�clarations utilisateur
public:
		// D�clarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
