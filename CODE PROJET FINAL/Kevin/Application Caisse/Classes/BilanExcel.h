//---------------------------------------------------------------------------
//-- Classe BilanExcel ------------------------------------------------------
//-- Développé par VUILLEMENOT Kevin (BTS SN2) ------------------------------
//-- Projet : Tri Pharmacie  ------------------------------------------------
//-- En collaboration avec : BEAUVISAGE Colin et VALENTINI Antoine ----------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef BilanExcelH
#define BilanExcelH
#include <fstream>
#include <iostream>
using namespace std ;
#include "MysqlPharmacieManager.h"
//---------------------------------------------------------------------------

class BilanExcel
{
	private :
		vector < vector<string> > bilan ;
		string medicament ; long quantiteVendu ; long double Totale, prix, FinalTotale, FinalQuantiteVendu ;

		// Methodes par periode ou medicaments qui inscrivent dans un nouveau fichier
		void BilanJour();
		void BilanSemaine();
		void BilanMois();
		void BilanAnnee();
		void BilanMedicamentJour(String Medicament);
		void BilanMedicamentSemaine(String Medicament);
		void BilanMedicamentMois(String Medicament);
		void BilanMedicamentAnnee(String Medicament);


	public :
		// Création du fichier template Excel s'il n'existe pas deja
		BilanExcel() ;

		// Methodes qui permettent d'appeler des méthodes pour ecrire dans un fichier
		void  BilanPeriode(String periode) ;
		void  BilanMedicament(String periode, String Medicament) ;

		// Objet BDD
		MysqlPharmacieManager * BDD ;
};

#endif
