//---------------------------------------------------------------------------

#ifndef BDDSQLH
#define BDDSQLH
//---------------------------------------------------------------------------
#include "mysql.h"
#include "BDD.h"

class BDDSQL : public BDD{

private:
       MYSQL *mysql;
public:

	BDDSQL ();
	~BDDSQL ();
//	bool connexionBDD (char *ip,char *login,char* mdp, char* bdd);
//	void sauvegardeBDD (char ip,char login,char mdp);
//	void restaurationBDD (char ip,char login,char mdp);
//	void ajoutMedicamentBDD (char ip,char login,char mdp);
//	void suppressionBDD (char ip,char login,char mdp);
//	void compareBDD (char ip,char login,char mdp);
	bool connect(string host,string user,string password,string dbname);
	bool insert(string requete);
vector< vector<std::string> > select(string requete);

};










#endif
