//---------------------------------------------------------------------------
#ifndef MysqlPharmacieManagerH
#define MysqlPharmacieManagerH
#include "../BDD/BDD.h"
#include "../BDDSQL/BDDSQL.h"
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
		int selectCaisse(String codeBarre);
		bool changerEtat(String etat, String id_ordonnance);
		void updateQuantiteMedoc(String medicament, String quantite);

		// Méthodes pour télécharger les bilans des ventes
		vector < vector<string> > BilanAnnee();
		vector < vector<string> > BilanSemaine();
		vector < vector<string> > BilanMois();
		vector < vector<string> > BilanJour();
		vector < vector<string> > BilanAnneeMedicament(String medicament);
		vector < vector<string> > BilanSemaineMedicament(String medicament);
		vector < vector<string> > BilanMoisMedicament(String medicament);
		vector < vector<string> > BilanJourMedicament(String medicament);
};

#endif
