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
		String deriereCommandeCAISSE1;
		String deriereCommandeCAISSE2;
		String deriereCommandeCAISSE3;
		BDD *mySql;
	public :
		MysqlPharmacieManager();
		~MysqlPharmacieManager();
		bool selectOrdonnance(TStringGrid *excelOrdo);
		bool createOrdonnance(String numeroCaisse);
		bool insertOrdonnance(String numeroCaisse, String Nom_Medicament, String quantite);
		bool insertMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
		bool updateMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
		bool insertTapiris(String cle,String value);
		bool selectMedicament();

		vector < vector<string> > BilanAnnee();
		vector < vector<string> > BilanSemaine();
		vector < vector<string> > BilanMois();
		vector < vector<string> > BilanJour();

		vector < vector<string> > BilanAnneeMedicament(String medicament);
		vector < vector<string> > BilanSemaineMedicament(String medicament);
		vector < vector<string> > BilanMoisMedicament(String medicament);
		vector < vector<string> > BilanJourMedicament(String medicament);

		//SELECT `Nom_Medicament`, `Prix`, `Nombre_Unite_Vendu` FROM `Medicament` WHERE 1
		bool etatCommande(String idCommande);
		bool deleteMedicament(String nomMedicament,String hauteur, String largeur, String longueur, String codeBarre, String prix);
};
#endif
