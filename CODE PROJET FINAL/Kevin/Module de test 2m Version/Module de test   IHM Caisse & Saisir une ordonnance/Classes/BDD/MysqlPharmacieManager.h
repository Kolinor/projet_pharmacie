//---------------------------------------------------------------------------
#ifndef MysqlPharmacieManagerH
#define MysqlPharmacieManagerH
#include "BDD.h"
#include "BDDSQL.h"
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------

class MysqlPharmacieManager
{
	private :
		String deriereCommandeCAISSE1;
		String deriereCommandeCAISSE2;
		String deriereCommandeCAISSE3;
		BDD *mySql;
	public :
		MysqlPharmacieManager();
		~MysqlPharmacieManager();
		bool createOrdonnance(String numeroCaisse);
		bool insertOrdonnance(String numeroCaisse, String Nom_Medicament, String quantite);
		bool insertMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
		bool updateMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
		bool insertTapiris(String cle,String value);
		bool selectMedicament();
		bool etatCommande(String idCommande);
		bool deleteMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
};

#endif
