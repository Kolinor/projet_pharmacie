//---------------------------------------------------------------------------
#pragma hdrstop
#include "BilanExcel.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// Constructeur de la class et création de l'objet BDD
BilanExcel::BilanExcel()
{
	BDD = new MysqlPharmacieManager() ;
}
//---------------------------------------------------------------------------

// Méthode qui selectionne la periode à choisir
void BilanExcel::BilanPeriode(String periode)
{
	if (periode == "Jour" )
	{
		this->BilanJour();
	}

	else if (periode == "Semaine" )
	{
		this->BilanSemaine();
	}

	else if (periode == "Mois" )
	{
		this->BilanMois();
	}

	else if (periode == "Année" )
	{
		this->BilanAnnee();
	}
}
//---------------------------------------------------------------------------

// Méthode qui selectionne la periode et le médicament à choisir
void BilanExcel::BilanMedicament(String periode, String Medicament)
{
	if (periode == "Jour" )
	{
		this->BilanMedicamentJour(Medicament);
	}

	else if (periode == "Semaine" )
	{
		this->BilanMedicamentSemaine(Medicament);
	}

	else if (periode == "Mois" )
	{
		this->BilanMedicamentMois(Medicament);
	}

	else if (periode == "Année" )
	{
		this->BilanMedicamentAnnee(Medicament);
	}
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par jour dans un fichier .csv
void BilanExcel::BilanJour()
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes quotidient.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;
		this->FinalQuantiteVendu+= this->quantiteVendu ;
		this->FinalTotale+= this->Totale ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}

	fichierBilan << endl << "Bénéfice total" << ";;;;"<< this->FinalQuantiteVendu<< " ;;" ;
	fichierBilan << this->FinalTotale << " €" << endl;
	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par semaine dans un fichier .csv
void BilanExcel::BilanSemaine()
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes hebdomadaire.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;
		this->FinalQuantiteVendu+= this->quantiteVendu ;
		this->FinalTotale+= this->Totale ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}
	fichierBilan << endl << "Bénéfice total" << ";;;;"<< this->FinalQuantiteVendu<< " ;;" ;
	fichierBilan << this->FinalTotale << " €" << endl;
	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par mois dans un fichier .csv
void BilanExcel::BilanMois()
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes mensuelle.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;
		this->FinalQuantiteVendu+= this->quantiteVendu ;
		this->FinalTotale+= this->Totale ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}
	fichierBilan << endl << "Bénéfice total" << ";;;;"<< this->FinalQuantiteVendu<< " ;;" ;
	fichierBilan << this->FinalTotale << " €" << endl;
	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par année dans un fichier .csv
void BilanExcel::BilanAnnee()
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes annuelle.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;
		this->FinalQuantiteVendu+= this->quantiteVendu ;
		this->FinalTotale+= this->Totale ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}
	fichierBilan << endl << "Bénéfice total" << ";;;;"<< this->FinalQuantiteVendu<< " ;;" ;
	fichierBilan << this->FinalTotale << " €" << endl;
	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par jour et d'un médicament dans un fichier .csv
void BilanExcel::BilanMedicamentJour(String Medicament)
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes quotidient pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}
	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par semaine et d'un médicament dans un fichier .csv
void BilanExcel::BilanMedicamentSemaine(String Medicament)
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes hebdomadaire pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}

	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par mois et d'un médicament dans un fichier .csv
void BilanExcel::BilanMedicamentMois(String Medicament)
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes mensuelle pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}

	fichierBilan.close();
}
//---------------------------------------------------------------------------

// Méthode qui écrit le bilan par année et d'un médicament dans un fichier .csv
void BilanExcel::BilanMedicamentAnnee(String Medicament)
{
	ofstream fichierBilan("D:/Utilisateur/Kevin/Bureau/Bilan/Bilan des ventes annuelle pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	for(int i=0; i < bilan.size(); ++i)
	{
		this->medicament = bilan[i][0].c_str() ;
		this->prix = atoi(bilan[i][1].c_str());
		this->quantiteVendu = atoi(bilan[i][2].c_str()) ;
		this->Totale = this->quantiteVendu * this->prix ;

		fichierBilan << this->medicament.c_str() << ";;" ;
		fichierBilan << this->prix << " €" << ";;" ;
		fichierBilan << this->quantiteVendu<< ";;" ;
		fichierBilan << this->Totale << " €" << endl;
	}

	fichierBilan.close();
}
//---------------------------------------------------------------------------

