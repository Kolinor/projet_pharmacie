//---------------------------------------------------------------------------

#pragma hdrstop

#include "MysqlPharmacieManager.h"
#define __WIN__
#include "mysql.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MysqlPharmacieManager::MysqlPharmacieManager()
{
	this->mySql = new BDDSQL();
    this->mySql->connect("192.168.64.111","pharma","pharma","pharmacie");
}
//---------------------------------------------------------------------------
MysqlPharmacieManager::~MysqlPharmacieManager()
{
	delete this->mySql;
}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::selectOrdonnance(TStringGrid *excelOrdo)
{

}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::insertOrdonnance()
{
	string requeteOrdonnance="INSERT INTO `Ordonnance`(`Etat`, `Numero_Caisse`, `Date_Saisie_Ordonnance`) VALUES (0,1,now());";
	this->mySql->insert(requeteOrdonnance);
}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::insertMedicament()
{
    string requete="INSERT INTO `Medicament`(`Nom_Medicament`, `Hauteur`, `Largeur`, `Longueur`, `Quantite_Restante`, `Code_Barre`, `Prix`, `Nombre_Unite_Vendu`) VALUES ('Doliprane','10','50','20','30','84785','99.99','0');";
	this->mySql->insert(requete);
}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::insertTapiris(String cle,String value)
{
	String requete = "INSERT INTO `ParametreAutomate`(`Cle`, `Value`) VALUES ('" + cle + "', '" + value + "')";

	wchar_t * wStrReq = requete.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);

	mySql->insert(req);

	delete req;
}
