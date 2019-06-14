//---------------------------------------------------------------------------
/*******************************************************
Nom ......... : modBus.h
Role ........ : cr�er la trame pr�te � envoyer au tcpClient
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
		//permet d'�crire sur les mots m�moire de l'automate
		bool writeWord(unsigned int mot, unsigned int valeur);
		//permet de lire les mots m�moires de l'automate
		int readWord(unsigned int mot,unsigned int nbLecture,char * buffer);
		//permet de se connecter � l'automate
		bool connected(string adress, unsigned short port);
		//permet de se connecter � l'automate
		void disconnect();


};

#endif