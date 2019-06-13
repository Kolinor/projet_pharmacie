//---------------------------------------------------------------------------
#pragma hdrstop
#include "BilanExcel.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

BilanExcel::BilanExcel()
{
	BDD = new MysqlPharmacieManager() ;
}


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

void BilanExcel::BilanJour()
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes quotidient.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanSemaine()
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes hebdomadaire.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanMois()
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes mensuelle.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanAnnee()
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes annuelle.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnnee();

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanMedicamentJour(String Medicament)
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes quotidient pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanMedicamentSemaine(String Medicament)
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes hebdomadaire pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanMedicamentMois(String Medicament)
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes mensuelle pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	// Appele de la méthode pour DL le bilan de l'année
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

void BilanExcel::BilanMedicamentAnnee(String Medicament)
{
	ofstream fichierBilan("C:/Users/Kevin/Desktop/Bilan/Bilan des ventes annuelle pour un medicament.csv", ios::out | ios::trunc) ;
	fichierBilan << "Médicaments" << ";;" << "Prix " << ";;" << "Quantité vendu" << ";;"  << "Total\n\n" ;
	this->bilan = BDD->BilanAnneeMedicament(Medicament);

	// Appele de la méthode pour DL le bilan de l'année
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

