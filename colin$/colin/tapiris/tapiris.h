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
#include "../modBus/modBus.h"
#include "../vector/Vector.h"
#include "../carte/carte.h"

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
		Vector<int> caisse1;
		Vector<int> caisse2;
		int etat[7]; // tapis, piston1, piston2, piston3, capteur1, capteur2, capteur3
		int etatCapt3;
		int testDtapis;
		int testAtapis;
		HANDLE mutex;
		HANDLE mutex1;

		//thread permmettant de ratracter un piston automatiquement
		static DWORD WINAPI threadDpiston(LPVOID lpParam);
		//thread permettant le mise en fonction automatique du tapiris
		static DWORD WINAPI threadCapteur(LPVOID lpParam);
		//thread permmettant d'activer un piston avec le num�ro du piston et un delay en ms
		static DWORD WINAPI threadApiston(LPVOID lpParam);
		//thread permmettant d'actionner le piston pour pousser les médicaments sur le convoyeur
		static DWORD WINAPI threadCapt3(LPVOID lpParam);
		static DWORD WINAPI threadAtapis(LPVOID lpParam);

	public:

		tapiris();
		~tapiris();
		//permet d'effectuer la connexion au tapis
		bool connected(string adress, unsigned short port);
		//permet d'arreter la connexion au tapiris
		void disconnect();
		//permet d'avtiver un piston (1,2,3) avec un delay en ms
		void activePiston(int piston,int delay);
		//permet de d�activer un piston sert pour le debogage
		bool deactivatePiston(int piston);
		//permet d'allumer le moteur du tapis
		bool activeTapis();
		//permet de desactiver la moteur du tapis
		bool deactivateTapis();

		void activeCapteur();

		void deactivateCapteur();
		//permet de sortir le m�dicament � la caisse associ�e(1,2,3)
		void newDrug(int caisse);

		int etatReturn(int idx);
		int test();
		int test1();





};

#endif
