//---------------------------------------------------------------------------

#ifndef tapirisH
#define tapirisH
#include "../include/modBus/modBus.h"
//---------------------------------------------------------------------------

class tapiris
{
	private:
		int npiston;
		modBus * pmodBus;
		size_t cchStringSize;
		DWORD dwChars;
		HANDLE Thread;
	public:
		tapiris();
		~tapiris();
		bool connected(string adress, unsigned short port);
		bool activePiston(int piston);
		bool activeTapis();
		bool deactivateTapis();
		static DWORD WINAPI piston(LPVOID lpParam);
};

#endif
