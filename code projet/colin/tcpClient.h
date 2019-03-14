//---------------------------------------------------------------------------

#ifndef TCPCLIENTH
#define TCPCLIENTH
#include <windows.h>
#include <string>

using namespace std;

/*******************************************************
Nom ......... : tcpClient.h
Role ........ : établir une connexion tcp
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class tcpClient
{
        private:
                int sock;
                unsigned short port;
                struct sockaddr_in client;
                string adress;
        public:
                tcpClient();
                bool connected(string adress, unsigned short port);
                bool send(const unsigned char* data,unsigned int len);
                string read();
};

#endif
