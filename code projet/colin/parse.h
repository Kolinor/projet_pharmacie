//---------------------------------------------------------------------------

#ifndef PARSEH
#define PARSEH
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

/*******************************************************
Nom ......... : parse.h
Role ........ : établir une connexion tcp
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class parse
{
        private:
            vector<char> buffer;

        public:
            void parse(vector<char>,SOCKET);
};

#endif
