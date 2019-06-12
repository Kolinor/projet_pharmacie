#pragma hdrstop

#include "threadEtat.h"
#include "IHM_Pilote.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall threadEtat::threadEtat(bool CreateSuspended,tapiris * tapis)
		: TThread(CreateSuspended)
{
	this->tapis = tapis;
	this->etatThread = true;
}
//---------------------------------------------------------------------------

__fastcall threadEtat::~threadEtat()
{
	this->etatThread = false;
}

//---------------------------------------------------------------------------
void __fastcall threadEtat::Execute()
{
	while (this->etatThread == true) {
		if (tapis->etatReturn(0) == 1) {
			Synchronize(shpTapisM);
		}
		else {
			Synchronize(shpTapisA);
		}

		if (tapis->etatReturn(1) == 1) {
			Synchronize(shpPiston1M);
		}
		else {
			Synchronize(shpPiston1A);
		}

		if (tapis->etatReturn(2) == 1) {
			Synchronize(shpPiston2M);
		}
		else {
			Synchronize(shpPiston2A);
		}

		if (tapis->etatReturn(3) == 1) {
			Synchronize(shpPiston3M);
		}
		else {
			Synchronize(shpPiston3A);
		}

		if (tapis->etatReturn(4) == 1) {
			Synchronize(shpCapteur1D);
		}
		else {
			Synchronize(shpCapteur1E);
		}

		if (tapis->etatReturn(5) == 1) {
			Synchronize(shpCapteur2D);
		}
		else {
			Synchronize(shpCapteur2E);
		}

		if (tapis->etatReturn(6) == 1) {
			Synchronize(shpCapteur3D);
		}
		else {
			Synchronize(shpCapteur3E);
		}


		Sleep(10);
	}
}
//---------------------------------------------------------------------------
void __fastcall threadEtat::shpTapisM()
{
	IHM->shpTapis->Brush->Color = clLime;
}

void __fastcall threadEtat::shpTapisA()
{
	IHM->shpTapis->Brush->Color = clRed;
}

void __fastcall threadEtat::shpPiston1M()
{
	IHM->shpPiston1->Brush->Color = clLime;
}

void __fastcall threadEtat::shpPiston1A()
{
	IHM->shpPiston1->Brush->Color = clRed;
}

void __fastcall threadEtat::shpPiston2M()
{
	IHM->shpPiston2->Brush->Color = clLime;
}

void __fastcall threadEtat::shpPiston2A()
{
	IHM->shpPiston2->Brush->Color = clRed;
}

void __fastcall threadEtat::shpPiston3M()
{
	IHM->shpPiston3->Brush->Color = clLime;
}

void __fastcall threadEtat::shpPiston3A()
{
	IHM->shpPiston3->Brush->Color = clRed;
}

void __fastcall threadEtat::shpCapteur1D()
{
	IHM->shpCapteur1->Brush->Color = clLime;
}

void __fastcall threadEtat::shpCapteur1E()
{
	IHM->shpCapteur1->Brush->Color = clRed;
}

void __fastcall threadEtat::shpCapteur2D()
{
	IHM->shpCapteur2->Brush->Color = clLime;
}

void __fastcall threadEtat::shpCapteur2E()
{
	IHM->shpCapteur2->Brush->Color = clRed;
}

void __fastcall threadEtat::shpCapteur3D()
{
	IHM->shpCapteur3->Brush->Color = clLime;
}

void __fastcall threadEtat::shpCapteur3E()
{
	IHM->shpCapteur3->Brush->Color = clRed;
}
