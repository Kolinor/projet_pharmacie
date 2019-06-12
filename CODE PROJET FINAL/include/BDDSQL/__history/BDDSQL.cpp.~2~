//---------------------------------------------------------------------------

#pragma hdrstop

#include "BDDSQL.h"
#define __WIN__

//---------------------------------------------------------------------------
#pragma package(smart_init)

BDDSQL::BDDSQL()
{
	mysql=new MYSQL;
	mysql_init(mysql);
}
//---------------------------------------------------------------------------
BDDSQL::~BDDSQL()
{
  mysql_close(mysql);
}
//---------------------------------------------------------------------------
bool BDDSQL::connect(string host,string user,string password,string dbname)
{
	if (mysql_real_connect(
							mysql,
							host.c_str(), 				//ip bdd
							user.c_str(), 			   //user bdd
							password.c_str(),          //password of user
							dbname.c_str(),           //name of bdd
							0,
							NULL,
							0)!= NULL)
	{
		//MessageBox(NULL, L"C'est un succès !",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return true;
	}
	else
	{
		MessageBox(NULL, "Echec de connexion !","Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return false;
	}
}
//---------------------------------------------------------------------------
bool BDDSQL::insert(string requete)
{
	if(mysql_query(mysql,requete.c_str())==0)
	{
		//MessageBox(NULL, L"C'est un succès !",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return true;
	}
	else
	{
		MessageBox(NULL, "Echec pour la requete INSERT verfiez que les codes barres ne soient pas identique","Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return false;
	}

}
//---------------------------------------------------------------------------
vector< vector<std::string> > BDDSQL::select(string requete)
{
	std::vector< std::vector<string> > resultatRequete;
	std::vector<string> copie;
	MYSQL_RES *res; /* holds the result set */
	MYSQL_ROW row;
	int nbColones=0;

	mysql_query(this->mysql,requete.c_str());
	res = mysql_store_result(this->mysql);
	//resultatRequete.resize(mysql_num_rows(res)); //commenter selon Mr Gremont
	nbColones =  mysql_num_fields(res);


	 while ((row = mysql_fetch_row(res))) {

	   for(int j = 0; j < nbColones; j++)
	   {
		   if(row[j] != NULL)
		   {
				copie.push_back(row[j]);
		   }
	   }

	   resultatRequete.push_back(copie);
	   copie.clear();
	}
	if(res != NULL)
	mysql_free_result(res);

	return resultatRequete;
}
//---------------------------------------------------------------------------
bool BDDSQL::update(string requete){

	// Exécute une requête SQL
	mysql_query(this->mysql,requete.c_str());
	//si au moins une ligne à etait affecté on retourne true sinon false

	if(mysql_affected_rows(this->mysql)>0)
	{
		return true;
	}

	else
	{
		return false;
	}
}
