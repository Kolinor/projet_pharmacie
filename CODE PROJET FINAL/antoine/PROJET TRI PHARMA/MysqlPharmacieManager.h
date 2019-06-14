//---------------------------------------------------------------------------

#ifndef MysqlPharmacieManagerH
#define MysqlPharmacieManagerH
//---------------------------------------------------------------------------

#include "BDD.h"
#include "BDDSQL.h"
#include <Vcl.Grids.hpp>
//Crée la requete
class MysqlPharmacieManager
{
	private :
		BDD *mySql;
	public :
		MysqlPharmacieManager();
		~MysqlPharmacieManager();
		bool selectOrdonnance(TStringGrid *excelOrdo);
		bool insertOrdonnance();
		bool insertMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
		bool insertTapiris(String cle,String value);
		bool selectMedicament();

};
#endif
