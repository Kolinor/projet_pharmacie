//---------------------------------------------------------------------------

#ifndef PARSERH
#define PARSERH
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

/*******************************************************
Nom ......... : parser.h
Role ........ : établir une connexion tcp
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class parser
{
    public:
        virtual void parse(vector<char>,SOCKET) = 0;
};

#endif
