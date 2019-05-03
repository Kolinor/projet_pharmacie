//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : tapiris.h
Role ........ : faire les actions demand� par l'utilisateur sur le tapis
Auteur ...... : Colin.B
Version ..... : V1.1 du 03/05/2019

Compilation : c++ builder
********************************************************/
//---------------------------------------------------------------------------

#ifndef tapirisH
#define tapirisH
#include "../include/modBus/modBus.h"
#include "../include/vector/Vector.h"

using namespace std;

//---------------------------------------------------------------------------

class tapiris
{
	private:
		//structure permettant de transmettre des variables � un thread
		struct ThreadDataTapiris
		{
			int piston;
			tapiris * tapis;
			ThreadDataTapiris(int piston, tapiris * tapis)
			{
				this->piston = piston;
				this->tapis = tapis;
			}
		};
//		struct ThreadDataCaisse
//		{
//			int caisse
//			tapiris * tapis;
//			ThreadDataCaisse(int caisse, tapiris * tapis)
//			{
//				this->caisse = caisse;
//				this->tapis = tapis;
//			}
//		};

		bool etatCapteur;
		Vector<int> vpiston;
		modBus * pmodBus;
		DWORD dwChars;
		HANDLE Thread;
	public:

		tapiris();
		~tapiris();
		//permet d'effectuer la connexion au tapis
		bool connected(string adress, unsigned short port);
		//permet d'arreter la connexion au tapiris
		void disconnect();
		//permet d'avtiver un piston
		bool activePiston(int piston);
		//permet de d�activer un piston sert pour le debogage
		bool deactivatePiston(int piston);
		//permet d'allumer le moteur du tapis
		bool activeTapis();
		//permet de desactiver la moteur du tapis
		bool deactivateTapis();
		void newDrug(int caisse);
		//thread permmettant de ratracter un piston automatiquement
		static DWORD WINAPI piston(LPVOID lpParam);
		//thread permettant le mise en fonction automatique du tapiris
		static DWORD WINAPI capteur(LPVOID lpParam);
};

#endif
