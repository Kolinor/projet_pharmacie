//---------------------------------------------------------------------------

#ifndef MODBUSH
#define MODBUSH
#include <windows.h>

/*******************************************************
Nom ......... : modbus.h
Role ........ : gérer l'automate 
Auteur ...... : Colin.B
Version ..... : V1.1 du 14/03/2019

Compilation : c++ builder
********************************************************/

//---------------------------------------------------------------------------
class modbus
{
    private:
        char word;
	public:
        bool writeWord(unsigned char word);
        void readWord(unsigned char word);
        bool connected(string adress,unsigned short port);
        void disconnected();
        
};

#endif
