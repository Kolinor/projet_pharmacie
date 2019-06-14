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
bool MysqlPharmacieManager::insertMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix)
{
	String requete="INSERT INTO `Medicament`(`Nom_Medicament`, `Hauteur`, `Largeur`, `Longueur`, `Quantite_Restante`, `Code_Barre`, `Prix`, `Nombre_Unite_Vendu`) VALUES ('" + nomMedicament + "','" + hauteur.ToInt() + "','" + largeur.ToInt() + "' , '" + longueur.ToInt() + "' , '"+ 0 + "' , '" + codeBarre.ToInt() + "' , '" + prix.ToInt() + "' , '" + 0 + "');";

	wchar_t * wStrReq = requete.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);

	this->mySql->insert(req);
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
bool MysqlPharmacieManager::selectMedicament()
{

}
