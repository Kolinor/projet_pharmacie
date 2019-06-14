//---------------------------------------------------------------------------
//-- IHM_Caisse ------------------ ------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef IHM_CaisseH
#define IHM_CaisseH
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "PopUp_Confirmation_BilanDesVentes.h"
#include "IHM_SaisieOrdonnance.h"
#include "MysqlPharmacieManager.h"
//---------------------------------------------------------------------------

class TIHM : public TForm
{
	// Composants gérés par l'EDI
	__published:
		TButton *Bouton_Ordonnance;
		TButton *Bouton_EtatCommande;
		TButton *Bouton_Bilan;
		TComboBox *ComboBox_Caisse;
		TLabel *Label_Caisse;
		void __fastcall Bouton_BilanClick(TObject *Sender);
		void __fastcall Bouton_OrdonnanceClick(TObject *Sender);

	// Déclarations utilisateur
	private:

	// Déclarations utilisateur
	public:
		__fastcall TIHM(TComponent* Owner);
		MysqlPharmacieManager * BDD ;
};

//---------------------------------------------------------------------------
extern PACKAGE TIHM *IHM;
//---------------------------------------------------------------------------
#endif
