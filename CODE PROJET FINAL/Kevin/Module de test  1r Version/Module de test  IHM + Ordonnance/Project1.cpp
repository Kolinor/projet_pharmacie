//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("IHM\IHM_Caisse.cpp", IHM);
USEFORM("IHM\IHM_SaisieOrdonnance.cpp", SaisieOrdonnance);
USEFORM("IHM\PopUp_Confirmation_BilanDesVentes.cpp", PopUp_Confirmation);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TIHM), &IHM);
		Application->CreateForm(__classid(TSaisieOrdonnance), &SaisieOrdonnance);
		Application->CreateForm(__classid(TPopUp_Confirmation), &PopUp_Confirmation);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
