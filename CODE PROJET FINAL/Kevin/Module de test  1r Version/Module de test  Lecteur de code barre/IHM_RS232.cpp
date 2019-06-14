//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "IHM_RS232.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TIHM_CodeBarre *IHM_CodeBarre;
//---------------------------------------------------------------------------

// IHM Lecteur code Barre
__fastcall TIHM_CodeBarre::TIHM_CodeBarre(TComponent* Owner) : TForm(Owner)
{
	portCom = new RS232() ;
}
//---------------------------------------------------------------------------

// Bouton de connexion au lecteur
void __fastcall TIHM_CodeBarre::Bouton_ConnexionClick(TObject *Sender)
{
	if (portCom->ouverture() == true)
	{
		Shape_Etat->Brush->Color = clGreen ;
	}

	else
	{
		Shape_Etat->Brush->Color = clRed ;
	}

	Bouton_Connexion->Visible = false ;
	Bouton_Deconnexion->Visible = true ;
}
//---------------------------------------------------------------------------

// Bouton de deconnexion du lecteur
void __fastcall TIHM_CodeBarre::Bouton_DeconnexionClick(TObject *Sender)
{
	portCom->fermer() ;
	Shape_Etat->Brush->Color = clRed ;

	Bouton_Connexion->Visible = true ;
	Bouton_Deconnexion->Visible = false ;
}
//---------------------------------------------------------------------------

// Bouton de reception du code barre avec l'affichage dans le Edit
void __fastcall TIHM_CodeBarre::Bouton_ReceptionClick(TObject *Sender)
{
	 char * CodeBarre = portCom->lecture() ;
	 Edit_Reception->Text = CodeBarre ;
}
//---------------------------------------------------------------------------