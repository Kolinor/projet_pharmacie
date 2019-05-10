//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : tapiris.h
Role ........ : faire les actions demandé par l'utilisateur sur le tapis
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
class tapiris;
	 struct ThreadDataTapiris
	{
		int piston;
		int delay;
		tapiris * tapis;
		ThreadDataTapiris(int piston,int delay, tapiris * tapis)
		{
			this->piston = piston;
			this->delay = delay;
			this->tapis = tapis;
		}
	};

//---------------------------------------------------------------------------

class tapiris
{
	private:
		bool etatCapteur;
		bool etatCaisse;
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
		//permet d'avtiver un piston avec un delay en ms
		void activePiston(int piston,int delay);
		//permet de déactiver un piston sert pour le debogage
		bool deactivatePiston(int piston);
		//permet d'allumer le moteur du tapis
		bool activeTapis();
		//permet de desactiver la moteur du tapis
		bool deactivateTapis();

		void activeCapteur();

		void deactivateCapteur();

		void newDrug(int caisse);
		//thread permmettant de ratracter un piston automatiquement
		static DWORD WINAPI threadDpiston(LPVOID lpParam);
		//thread permettant le mise en fonction automatique du tapiris
		static DWORD WINAPI threadCapteur(LPVOID lpParam);
		//thread permmettant d'activer un piston avec le numéro du piston et un delay en ms
		static DWORD WINAPI threadApiston(LPVOID lpParam);


};

#endif
