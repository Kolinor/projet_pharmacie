//---------------------------------------------------------------------------

#ifndef BDDH
#define BDDH
//---------------------------------------------------------------------------


#include <vector>
#include <stdlib.h>

using namespace std;
class BDD {

private:

public:

	BDD();
	~BDD();
	virtual bool connect(string host,string user,string password,string dbname)=0;
	virtual bool insert(string requete)=0;
	virtual vector< vector<std::string> > select(std::string requete)=0;
//	virtual bool save(string requete)=0;
//	virtual bool restore(string requete)=0;

//	virtual void compareBDD(string requete)=0;

};

#endif