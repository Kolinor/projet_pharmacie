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
		//MessageBox(NULL, L"C'est un succ�s !",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return true;
	}
	else
	{
		MessageBox(NULL, L"Echec de connexion !",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return false;
	}
}
//---------------------------------------------------------------------------
bool BDDSQL::insert(string requete)
{
	if(mysql_query(mysql,requete.c_str())==0)
	{
		//MessageBox(NULL, L"C'est un succ�s !",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return true;
	}
	else
	{
		MessageBox(NULL, L"Echec pour la requete INSERT",L"Alert", MB_ICONWARNING | MB_YESNOCANCEL);
		return false;
	}

}
//---------------------------------------------------------------------------
vector< vector<std::string> > BDDSQL::select(string requete)
{
		vector< vector<std::string> > vec;

//		 mysql_query(&mysql, "SELECT * FROM scores");
		//D�claration des objets
//        MYSQL_RES *result = NULL;
//        MYSQL_ROW row;
//        int i = 1;

		//On met le jeu de r�sultat dans le pointeur result
//        result = mysql_use_result(&mysql);
		//Tant qu'il y a encore un r�sultat ...
//        while ((row = mysql_fetch_row(result)))
//		{
//		   printf("Resultat %ld\n", i);
//           i++;
//		}
		//Lib�ration du jeu de r�sultat
//		mysql_free_result(result);
    return vec;
}
//---------------------------------------------------------------------------

