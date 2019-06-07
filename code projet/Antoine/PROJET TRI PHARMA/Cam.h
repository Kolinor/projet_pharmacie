#ifndef CamH
#define CamH
//---------------------------------------------------------------------------
#endif
// Inclue toute les librairie statique necessaire a openCV
#pragma comment(lib, "classe\camera\opencv\lib\cv2")
#pragma comment(lib, "classe\camera\opencv\lib\ml2")
#pragma comment(lib, "classe\camera\opencv\lib\cvaux2")
#pragma comment(lib, "classe\camera\opencv\lib\cvhaartraining2")
#pragma comment(lib, "classe\camera\opencv\lib\cxcore2")
#pragma comment(lib, "classe\camera\opencv\lib\cxts2")
#pragma comment(lib, "classe\camera\opencv\lib\highgui2")
#pragma comment(lib, "classe\camera\opencv\lib\cvcam2")


#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

#include "opencv\include\opencv\cv\include\cv.h"
#include "opencv\include\opencv\otherlibs\highgui\highgui.h"
#include <math.h>
#include <vfw.h>
#include <time.h>
#include <IniFiles.hpp>

class traitementImage
{
	public:

		traitementImage(TForm *form, int width,int height, int top, int left);
		~traitementImage();

		bool recupererTailleCommande(String img,int calibrage);
		void prendreImage(String name);
		int tabMesure[2];
		int taillePixel;
		int valCarreCalibrage;

		TAnimate *Animate1;
	private:
		HWND Handle;
		TIniFile *fichier;

		int thresh;
        float distanceEntreDeuxPoint(CvPoint pt1,CvPoint pt2);
		IplImage *imgCam,*imgCamRef;

		CvMemStorage* storage;

		double angle( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 );

		CvSeq* TrouverRectangle( IplImage* img, CvMemStorage* storage );
		void MesurerRectangle( IplImage* img, CvSeq* squares,int calibrage );

};

