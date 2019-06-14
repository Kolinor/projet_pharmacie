#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vcl.h>
#include "../include/tapiris/tapiris.h"
//---------------------------------------------------------------------------
class threadEtat : public TThread
{
	private:
		tapiris * tapis;
		bool etatThread;
	protected:
		void __fastcall Execute();
		void __fastcall shpTapisM();
		void __fastcall shpTapisA();
		void __fastcall shpPiston1M();
		void __fastcall shpPiston1A();
		void __fastcall shpPiston2M();
		void __fastcall shpPiston2A();
		void __fastcall shpPiston3M();
		void __fastcall shpPiston3A();
		void __fastcall shpCapteur1D();
		void __fastcall shpCapteur1E();
		void __fastcall shpCapteur2D();
		void __fastcall shpCapteur2E();

	public:
		__fastcall threadEtat(bool CreateSuspended,tapiris * tapis);
		__fastcall ~threadEtat();
};
//---------------------------------------------------------------------------
#endif
