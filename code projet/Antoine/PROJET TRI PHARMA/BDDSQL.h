//---------------------------------------------------------------------------

#ifndef BDDSQLH
#define BDDSQLH
//---------------------------------------------------------------------------
#include "mysql.h"
class BDDSQL {

private:
       MYSQL *mysql;
public:

	BDDSQL (char ip,char login,char mdp);
	~BDDSQL ();
	bool connexionBDD (char *ip,char *login,char* mdp, char* bdd);
	void sauvegardeBDD (char ip,char login,char mdp);
	void restaurationBDD (char ip,char login,char mdp);
	void ajoutBDD (char ip,char login,char mdp);
	void suppressionBDD (char ip,char login,char mdp);
	void compareBDD (char ip,char login,char mdp);

};










#endif
