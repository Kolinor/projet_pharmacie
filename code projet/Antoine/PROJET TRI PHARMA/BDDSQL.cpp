//---------------------------------------------------------------------------

#pragma hdrstop

#include "BDDSQL.h"
#define __WIN__

//---------------------------------------------------------------------------
#pragma package(smart_init)

	BDDSQL::BDDSQL()
	{
	mysql=mysql_init(NULL);
	}
//---------------------------------------------------------------------------
	BDDSQL::~BDDSQL()
	{
	  mysql_close(mysql);
	}
//---------------------------------------------------------------------------
bool BDDSQL::connect(string host,string user,string password,string dbname)
{
	if (mysql_real_connect(mysql,
							host.c_str(), 				//ip bdd
							user.c_str(), 			   //user bdd
							password.c_str(),          //password of user
							dbname.c_str(),           //name of bdd
							0,
							NULL,
							0))
	{
	 return true;
	}
	else
	{
	 return false;
	}
}
//---------------------------------------------------------------------------
bool BDDSQL::insert(string requete)
{

}
//---------------------------------------------------------------------------
vector< vector<std::string> > BDDSQL::select(string requete)
{

}
//---------------------------------------------------------------------------

