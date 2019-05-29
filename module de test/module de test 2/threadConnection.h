//---------------------------------------------------------------------------

#ifndef threadConnectionH
#define threadConnectionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "tcpClient.h"
//---------------------------------------------------------------------------
class threadConnection : public TThread
{
private:
		bool etatCon;
		tcpClient * tcp;
protected:
		void __fastcall Execute();
		void __fastcall shapeConnection();
public:
		__fastcall threadConnection(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
