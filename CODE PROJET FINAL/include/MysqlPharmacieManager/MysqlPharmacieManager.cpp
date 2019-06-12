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
	String requeteOrdonnance="INSERT INTO `Ordonnance`(`Etat`, `Numero_Caisse`, `Date_Saisie_Ordonnance`) VALUES ('en attente', '" + numeroCaisse + "',now());";
	wchar_t * wStrReq = requeteOrdonnance.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);
	bool test =this->mySql->insert(req);
}
//---------------------------------------------------------------------------
bool MysqlPharmacieManager::insertOrdonnance(String numeroCaisse, String Nom_Medicament, String quantite)
{
   vector < vector<string> > id;
//numeroCaisse=1;

	if (numeroCaisse=="1")
	{

	String requeteCaisse1="SELECT `ID_Ordonnance` FROM `Ordonnance`WHERE `Numero_Caisse`= '1' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 0,1;";
	wchar_t * wStrReq1 = requeteCaisse1.c_str();
	int reqLength1 = wcslen(wStrReq1);
	char * req1 = new char[reqLength1 + 1];
	wcstombs(req1, wStrReq1, reqLength1);
	id=this->mySql->select(req1);

	}
	if (numeroCaisse==2){

	String requeteCaisse2="SELECT `ID_Ordonnance` FROM `Ordonnance`WHERE `Numero_Caisse`= '2' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 0,1;";
	wchar_t * wStrReq2 = requeteCaisse2.c_str();
	int reqLength2 = wcslen(wStrReq2);
	char * req2 = new char[reqLength2 + 1];
	wcstombs(req2, wStrReq2, reqLength2);
	id=this->mySql->select(req2);

	}
	if (numeroCaisse==3){

	String requeteCaisse3="SELECT `ID_Ordonnance` FROM `Ordonnance`WHERE `Numero_Caisse`= '3' ORDER BY `Date_Saisie_Ordonnance` DESC LIMIT 0,1;";
	wchar_t * wStrReq3 = requeteCaisse3.c_str();
	int reqLength3 = wcslen(wStrReq3);
	char * req3 = new char[reqLength3 + 1];
	wcstombs(req3, wStrReq3, reqLength3);
	id=this->mySql->select(req3);

	}

	//dans les valeurs je  cherche a mettre le nom du combobox et la quantit� magl
	String requeteOrdonnance="INSERT INTO `Ordonnance_Medicament_Association`(`ID_Ordonnance`, `Nom_Medicament`, `Quantite_Demande`, `Quantite_Delivree`) VALUES ('";
	 requeteOrdonnance+= id[0][0].c_str();
	 requeteOrdonnance+="','";
	 requeteOrdonnance+= Nom_Medicament ;
	 requeteOrdonnance+= "','" ;
	 requeteOrdonnance+= quantite;
	 requeteOrdonnance+= "','";
	 requeteOrdonnance+= "0";
	 requeteOrdonnance+= "')";
	wchar_t * wStrReq = requeteOrdonnance.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength + 1];
	wcstombs(req, wStrReq, reqLength);
	mySql->insert(req);
//INSERT INTO `Ordonnance_Medicament_Association`(`ID_Ordonnance`, `Nom_Medicament`
//, `Quantite_Demande`, `Quantite_Delivree`) VALUES ("4","Doliprane","1","1")
	delete req;
}
//---------------------------------------------------------------------------
bool BilanMois(String mois, String caisse, String medicament)
{
//String requete ;
//
//	if (caisse==0 && medicament==0)
//	{
//		String requete = "SELECT `Nom_Medicament`, `Prix`, `Nombre_Unite_Vendu` FROM `Medicament` WHERE
//	}
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

bool MysqlPharmacieManager::changerEtat(String etat, String id_ordonnance)
{
	String requete = "UPDATE `Ordonnance` SET `Etat` = '";
	requete += etat.c_str();
	requete += "' WHERE `ID_Ordonnance` = ";
	requete += id_ordonnance.c_str();

	wchar_t * wStrReq = requete.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength +1];
	wcstombs(req,wStrReq, reqLength);
	this->mySql->update(req);

}

int MysqlPharmacieManager::selectCaisse(String codeBarre)
{
	vector < vector<string> > repCaisse;
	vector < vector<string> > repOrdo;

	String requete = "SELECT `Ordonnance`.`Numero_Caisse`, `Ordonnance`.`ID_Ordonnance`, `Ordonnance_Medicament_Association`.`Nom_Medicament`";
	requete += " FROM `Ordonnance` INNER JOIN `Ordonnance_Medicament_Association` ON";
	requete += "`Ordonnance`.`ID_Ordonnance` = `Ordonnance_Medicament_Association`.`ID_Ordonnance`";
	requete += "INNER JOIN `Medicament` ON `Medicament`.`Nom_Medicament` = `Ordonnance_Medicament_Association`.`Nom_Medicament`";
	requete += "WHERE `Medicament`.`Code_Barre` =";
	requete += codeBarre;
	requete += " AND `Ordonnance_Medicament_Association`.`Quantite_Delivree` <";
	requete += "`Ordonnance_Medicament_Association`.`Quantite_Demande` AND";
	requete += "`Ordonnance`.`Etat` = 'en attente' order by `Ordonnance`.`Date_Saisie_Ordonnance` asc limit 1;";


	wchar_t * wStrReq = requete.c_str();
	int reqLength = wcslen(wStrReq);
	char * req = new char[reqLength +1];
	wcstombs(req,wStrReq, reqLength);
	repCaisse = this->mySql->select(req);


	string id;
	string medicament;
	int caisse;
	if (repCaisse.size() != 0) {
		caisse = atoi(repCaisse[0][0].c_str());
		id = repCaisse[0][1];
		medicament = repCaisse[0][2];

		String requete1 = "UPDATE `Ordonnance_Medicament_Association` SET `Quantite_Delivree`= Quantite_Delivree+1 ";
		requete1 += "WHERE `Quantite_Demande` > `Quantite_Delivree` ";
		requete1 += "AND `Ordonnance_Medicament_Association`.`ID_Ordonnance` = ";
		requete1 += id.c_str();
		requete1 += " AND `Ordonnance_Medicament_Association`.`Nom_Medicament` = '";
		requete1 += medicament.c_str();
		requete1 += "'";
		wchar_t * wStrReq1 = requete1.c_str();
		int reqLength1 = wcslen(wStrReq1);
		char * req1 = new char[reqLength1 +1];
		wcstombs(req1,wStrReq1, reqLength1);
		this->mySql->update(req1);

		String requete2 = "SELECT `Ordonnance_Medicament_Association`.`ID_Ordonnance`, `Ordonnance_Medicament_Association`.`Quantite_Demande`, `Ordonnance_Medicament_Association`.`Quantite_Delivree` FROM `Ordonnance` ";
		requete2 += "INNER JOIN `Ordonnance_Medicament_Association` ON `Ordonnance`.`ID_Ordonnance` = `Ordonnance_Medicament_Association`.`ID_Ordonnance` ";
		requete2 += "INNER JOIN `Medicament` ON `Medicament`.`Nom_Medicament` = `Ordonnance_Medicament_Association`.`Nom_Medicament` ";
		requete2 += "WHERE `Ordonnance_Medicament_Association`.`Quantite_Delivree` < `Ordonnance_Medicament_Association`.`Quantite_Demande` ";
		requete2 += "AND `Ordonnance_Medicament_Association`.`ID_Ordonnance` = ";
		requete2 += id.c_str();

		wchar_t * wStrReq2 = requete2.c_str();
		int reqLength2 = wcslen(wStrReq2);
		char * req2 = new char[reqLength2 +1];
		wcstombs(req2,wStrReq2, reqLength2);
		repOrdo = this->mySql->select(req2);

		if (repOrdo.size() == 0 ) {
			string etat = "terminer";
			this->changerEtat(etat.c_str(),id.c_str());
		}


	}
	else {
		caisse = 3;
	}





	return caisse;

}
