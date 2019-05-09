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
bool MysqlPharmacieManager::createOrdonnance(String numeroCaisse)
{
	String requeteOrdonnance="INSERT INTO `Ordonnance`(`Etat`, `Numero_Caisse`, `Date_Saisie_Ordonnance`) VALUES (`en attente`, '" + numeroCaisse + "',now());";
	wchar_t * wStrReq = requeteOrdonnance.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);
	this->mySql->insert(req);
// stocker dans derniereCommandeCAISSE
	if (numeroCaisse==1){
	this->deriereCommandeCAISSE1="SELECT `ID_Ordonnance` FROM `Ordonnance` WHERE `ID_Ordonnance`= '" + numeroCaisse + "' );";
	}
	if (numeroCaisse==2){
	this->deriereCommandeCAISSE2="SELECT `ID_Ordonnance` FROM `Ordonnance` WHERE `ID_Ordonnance`= '" + numeroCaisse + "' );";
	}
	if (numeroCaisse==3){
	this->deriereCommandeCAISSE3="SELECT `ID_Ordonnance` FROM `Ordonnance` WHERE `ID_Ordonnance`= '" + numeroCaisse + "' )";;
	}
}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::insertOrdonnance(String numeroCaisse, String Nom_Medicament, String quantite)
{
String id=0;

	if (numeroCaisse==1){
	id=this->deriereCommandeCAISSE1;
	}
	if (numeroCaisse==2){
	id=this->deriereCommandeCAISSE2;
	}
	if (numeroCaisse==3){
	id=this->deriereCommandeCAISSE3;
	}

	//dans les valeurs je  cherche a mettre le nom du combobox et la quantité magl
	String requeteOrdonnance="INSERT INTO `Ordonnance_Medicament_Association`(`ID_Ordonnance`, `Nom_Medicament`, `Quantite_Demande`) VALUES ('" + id + "','" + Nom_Medicament + "','" + quantite + "');";
	wchar_t * wStrReq = requeteOrdonnance.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);
	this->mySql->insert(req);
}
//---------------------------------------------------------------------------
// une methode ou je prend le nom medoc depuis un combo box et je recupere son id//
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
