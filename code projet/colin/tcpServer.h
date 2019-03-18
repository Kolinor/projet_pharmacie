//---------------------------------------------------------------------------

#ifndef TCPSERVERH
#define TCPSERVERH
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

/*******************************************************
Nom ......... : tcpServer.h
Role ........ : établir une connexion tcp
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class tcpServer
{
        private:
                unsigned short port;
                vector<char*> buffer;
                struct sockaddr_in server;

        public:
            tcpServer();
            bool start(unsigned short port);
            void stop();
            bool send(const unsigned char* data,unsigned int len);
            vector<char*> read();
};

#endif
