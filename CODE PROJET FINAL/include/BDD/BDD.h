//---------------------------------------------------------------------------
#ifndef BDDH
#define BDDH
#include <vector>
#include <stdlib.h>
#include "../include SQL/mysql.h"
using namespace std;
//---------------------------------------------------------------------------

class BDD
{
	private:

	public:

		BDD();
		~BDD();
		virtual bool connect(string host,string user,string password,string dbname)=0;
		virtual bool insert(string requete)=0;
		virtual bool update (string requete)=0;
		virtual vector< vector<std::string> > select(std::string requete)=0;
};

#endif
