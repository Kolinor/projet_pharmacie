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
		bool writeWord();
		unsigned char* readWord();
		bool connected(string adress, unsigned short port);
		void disconnect();


};

#endif
