//---------------------------------------------------------------------------

#ifndef TCPSERVERH
#define TCPSERVERH
#include <windows.h>
#include <string>

using namespace std;

/*******************************************************
Nom ......... : communication.h
Role ........ : établir une connexion (classe abstraite)
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class communication
{
        public:
            virtual bool connected(string adress,unsigned short port) = 0;
            virtual void disconnected() = 0;
            virtual string read() = 0;
            virtual send (const unsigned char* data, unsigned int len) = 0;
};

#endif
