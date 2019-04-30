//---------------------------------------------------------------------------

#ifndef modBusH
#define modBusH
#include "../include/tcpClient/tcpClient.h"
//---------------------------------------------------------------------------

class modBus {

	private:
		char * trame;
		tcpClient * tcp;

	public:
		modBus();
		~modBus();
		bool writeWord(unsigned int mot, unsigned int valeur);
		char readWord(unsigned int mot);
		bool connected(string adress, unsigned short port);
		void disconnect();


};

#endif
