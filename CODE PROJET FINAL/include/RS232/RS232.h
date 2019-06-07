//---------------------------------------------------------------------------

#ifndef RS232H
#define RS232H
#include <windows.h>
#include <vector>
#include "../include/vector/Vector.h"

using namespace std;

//---------------------------------------------------------------------------
class RS232
{
	private:
		HANDLE hcom;
		DCB serie;
		OVERLAPPED over;
		DWORD event;

		Vector<int> codeBarre;
		int copy;


		DWORD dwChars;
		HANDLE Thread;
		bool etatThread;

		HANDLE mutex;

		static DWORD WINAPI threadLecture(LPVOID lpParam);

	public:
		RS232();
		~RS232();
		bool ouverture();
		void fermer();
		bool ecriture(char* str);
		void lecture();
		void recup(int chaine);
		int vectorCodeBarre();


};




#endif
