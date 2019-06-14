//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : modBus.h
Role ........ : creer la trame prete a envoyer au tcpClient
Auteur ...... : Colin.B
Version ..... : V1.1 du 03/05/2019

Compilation : c++ builder
********************************************************/
//---------------------------------------------------------------------------

#ifndef modBusH
#define modBusH
#include "../tcpClient/tcpClient.h"
//---------------------------------------------------------------------------

class modBus {

	private:
		char * trame;
		tcpClient * tcp;

	public:
		modBus();
		~modBus();
		//permet d'ecrire sur les mots memoire de l'automate
		bool writeWord(unsigned int mot, unsigned int valeur);
		//permet de lire les mots memoires de l'automate
		int readWord(unsigned int mot,unsigned int nbLecture,char * buffer);
		//permet de se connecter à l'automate
		bool connected(string adress, unsigned short port);
		//permet de se connecter à l'automate
		void disconnect();


};

#endif
