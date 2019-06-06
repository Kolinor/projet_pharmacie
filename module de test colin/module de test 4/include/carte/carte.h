//---------------------------------------------------------------------------

#ifndef Class_CarteH
#define Class_CarteH
#include "K8055D.h"
//---------------------------------------------------------------------------
#endif
class carte
{
	public:
		carte();
		~carte();
		int Connexion(int adr);
		int lecture_analog(int chan);


	private:
		int adr;
		int chan;
};