//---------------------------------------------------------------------------
#ifndef BDDSQLH
#define BDDSQLH
#include "../BDD/BDD.h"
#include <stdlib.h>
#include <vcl.h>
#include <windows.h>
//---------------------------------------------------------------------------

class BDDSQL : public BDD
{
	private:
		   MYSQL *mysql;
	public:

		BDDSQL ();
		~BDDSQL ();
		bool connect(string host,string user,string password,string dbname);
		bool insert(string requete);
		bool update (string requete);
		vector< vector<std::string> > select(string requete);
};

#endif
