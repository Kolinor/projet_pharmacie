//---------------------------------------------------------------------------

#pragma hdrstop

#include "BDDSQL.h"
#define __WIN__

//---------------------------------------------------------------------------
#pragma package(smart_init)

	BDDSQL::BDDSQL(char ip,char login,char mdp)
	{
	mysql=mysql_init(NULL);
	}
//---------------------------------------------------------------------------
	BDDSQL::~BDDSQL()
	{
	  mysql_close(mysql);
    }
//---------------------------------------------------------------------------
	void sauvegardeBDD(char ip,char login,char mdp)
	{

	}
//---------------------------------------------------------------------------
	bool BDDSQL::connexionBDD(char* ip,char *login,char *mdp,char * bdd)
	{
		if (!mysql_real_connect(mysql, ip, login, mdp, bdd, 0, NULL, 0)) {
		 return false;
		}
		else
		{
		 return true;
		}
	}
//---------------------------------------------------------------------------
	void BDDSQL::restaurationBDD(char ip,char login,char mdp)
	{

	}
//---------------------------------------------------------------------------
	void BDDSQL::ajoutBDD(char ip,char login,char mdp)
	{

	}
//---------------------------------------------------------------------------
	void BDDSQL::suppressionBDD(char ip,char login,char mdp)
	{

	}
//---------------------------------------------------------------------------
	void BDDSQL::compareBDD(char ip,char login,char mdp)
	{

	}
