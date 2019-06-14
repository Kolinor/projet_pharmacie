//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("IHM\IHM_Bilan.cpp", Form_Bilan);
USEFORM("IHM\IHM_Ordonnance.cpp", Ordonnance);
USEFORM("IHM\IHM_Etat.cpp", Form_Etat);
USEFORM("IHM\IHM_Caisse.cpp", IHM);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TIHM), &IHM);
		Application->CreateForm(__classid(TForm_Etat), &Form_Etat);
		Application->CreateForm(__classid(TOrdonnance), &Ordonnance);
		Application->CreateForm(__classid(TForm_Bilan), &Form_Bilan);
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
