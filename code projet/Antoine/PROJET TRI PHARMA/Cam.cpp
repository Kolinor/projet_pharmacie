#pragma hdrstop

#include "Cam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

traitementImage::traitementImage(TForm *form, int width,int height, int top, int left)
{
	//Declaration du TAnimate

	Animate1 = new TAnimate(form->Owner);
	Animate1->Parent = form;

	Animate1->Width = width;
	Animate1->Height = height;
	Animate1->Left = left;
	Animate1->Top = top;
	Animate1->Visible = true;


	thresh = 50;
	imgCam =0;
	imgCamRef=0;
	storage = 0;

	taillePixel=0;


	Handle = Animate1->Handle;    // Attache le handle a un TAnimate

									//Créer une capture video de 640*480.
   Handle = capCreateCaptureWindow( NULL,WS_CHILD|WS_VISIBLE,0,0,Animate1->Width,Animate1->Height,Handle,0);
									//Connecter le driver.
   capDriverConnect(Handle, 0);

									//Initialiser le taux de rafraichissement a 66ms.
   capPreviewRate  (Handle, 66);

									//Démarer la preview video.
   capPreview      (Handle, true);



}

traitementImage::~traitementImage()
{
   capDriverDisconnect(Handle);
   Animate1->Visible = false;
   cvDestroyWindow("Verification du rectangle detecte");
}

void traitementImage::prendreImage(String nom)
{


	capCaptureSingleFrameOpen(Handle);        //lit le Handle

	capCaptureSingleFrame(Handle) ;      // Capture l'image

	capCaptureSingleFrameClose(Handle) ;   //Arrete la lecture

	capFileSaveDIB(Handle,nom.c_str());// Sauvegarde l'image avec le nom donne en parametre

}


bool traitementImage::recupererTailleCommande(String img,int calibrage)
{
	int *tabMesure;
		// create memory storage that will contain all the dynamic data
	storage = cvCreateMemStorage(0);

		AnsiString lenom ;
	lenom = img ;
	if(!cvLoadImage(lenom.c_str(), 1 ))
	{
		return false;
	}
	imgCamRef = cvLoadImage(lenom.c_str(), 1 );



	imgCam = cvCloneImage( imgCamRef );

		cvSetImageROI(imgCam,cvRect(255, 147, 243, 176 ));

	// detecte et mesure le rectangle de l'image
	 MesurerRectangle( imgCam, TrouverRectangle( imgCam, storage ),calibrage );

	// wait for key.
	// Also the function cvWaitKey takes care of event processing

	// release both images
	cvReleaseImage( &imgCam );
	cvReleaseImage( &imgCamRef );
	// clear memory storage - reset free space position
	cvClearMemStorage( storage );

	return true;
}
//---------------------------------------------------------------------------
double traitementImage::angle( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 )
{
	double dx1 = pt1->x - pt0->x;
	double dy1 = pt1->y - pt0->y;
	double dx2 = pt2->x - pt0->x;
	double dy2 = pt2->y - pt0->y;
	return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

CvSeq* traitementImage::TrouverRectangle( IplImage* img, CvMemStorage* storage )
{
	CvSeq* contours;
	int i, c, l, N = 11;
	CvSize sz = cvSize( img->width & -2, img->height & -2 );
	IplImage* timg = cvCloneImage( img ); // make a copy of input image
	IplImage* gray = cvCreateImage( sz, 8, 1 );
	IplImage* pyr = cvCreateImage( cvSize(sz.width/2, sz.height/2), 8, 3 );
    IplImage* tgray;
	CvSeq* result;
    double s, t;
	// Instancie un object CvSeq
	CvSeq* squares = cvCreateSeq( 0, sizeof(CvSeq), sizeof(CvPoint), storage );

	//Redimensione l'image de facon a ce que ses cote soi divisible par 2
	cvSetImageROI( timg, cvRect( 0, 0, sz.width, sz.height ));



	// Instancie un objet IplImage
	tgray = cvCreateImage( sz, 8, 1 );

	// Boucle de detection de rectangle dans chaque plan de couleur
	for( c =0; c < 3; c++ )
	{
		// Extrait le plan de couleur souhaite
		cvSetImageCOI( timg, c+1 );
		cvCopy( timg, tgray, 0 );

		// Essaie plusieur niveau de Threshold afin de trouve celui qui correspond le mieux au niveau présent sur l'image
		for( l = 0; l < N; l++ )
        {


				// Applique le Threshold
				cvThreshold( tgray, gray, (l+1)*255/N, 255, CV_THRESH_BINARY );


			// On envoie l'image a la fonction de detection des contour
			cvFindContours( gray, storage, &contours, sizeof(CvContour),CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

			// On parcours les contour detecté afin de voir si les angle sont bien a 90°
			while( contours )
			{
				//Renvoie un probable rectangle de l'image
                result = cvApproxPoly( contours, sizeof(CvContour), storage,
                    CV_POLY_APPROX_DP, cvContourPerimeter(contours)*0.02, 0 );
				// Si le total est egale a 4 on a alors un rectangle
                if( result->total == 4 &&
					fabs(cvContourArea(result,CV_WHOLE_SEQ)) > 1000 &&
                    cvCheckContourConvexity(result) )
				{
					s = 0;

					for( i = 0; i < 5; i++ )
					{
						// Grace a la fonction angle on verifi grace a 3 point sur l'image si le rectangle est bien forme
						// de 4 angle droit
						if( i >= 2 )
						{
                            t = fabs(angle(
							(CvPoint*)cvGetSeqElem( result, i ),
							(CvPoint*)cvGetSeqElem( result, i-2 ),
							(CvPoint*)cvGetSeqElem( result, i-1 )));
                            s = s > t ? s : t;
						}
					}

					//A plus ou moins 0,3 degree on enregistre le rectangle detecté
					if( s < 0.3 )
						for( i = 0; i < 4; i++ )
							cvSeqPush( squares,
								(CvPoint*)cvGetSeqElem( result, i ));
				}

				// On passe au contour suivant
				contours = contours->h_next;
			}
		}
	}

	// vide tout les pointeur
	cvReleaseImage( &gray );
	cvReleaseImage( &pyr );
	cvReleaseImage( &tgray );
	cvReleaseImage( &timg );

	return squares;
}

// Permet de calcule la taille en cm d'un pixel
//grace a un carre de 10cm dessine sur une feuille
// et prit en photo par la camera
void traitementImage::MesurerRectangle( IplImage* img, CvSeq* squares,int calibrage )
{

	CvSeqReader reader;
	IplImage* cpy = cvCloneImage( img );
	int i;

	// Initialise la lecture des rectangle detecte
	cvStartReadSeq( squares, &reader, 0);
	CvPoint pt[4], *rect = pt;
		int count = 4;
		 int compteurRech = 0;
		// Lit les point des quatre vertical

		//|| pt[0].x > img->width-30  || pt[0].y > img->height-30 || pt[1].x > img->width-30 || pt[1].y > img->height-30 || pt[2].x > img->width-30 || pt[2].y > img->height-30 || pt[3].x > img->width-30 || pt[3].y > img->height-30
		while(pt[0].x < 20 || pt[0].y < 20 || pt[1].x < 20 || pt[1].y < 20
		|| pt[2].x < 20 || pt[2].y < 20|| pt[3].x < 20 || pt[3].y < 20)
		{
			CV_READ_SEQ_ELEM( pt[0], reader );
			CV_READ_SEQ_ELEM( pt[1], reader );
			CV_READ_SEQ_ELEM( pt[2], reader );
			CV_READ_SEQ_ELEM( pt[3], reader );
			 compteurRech++ ;
			 if(compteurRech == 20)
			 {
				 break;
			 }
		}
			//Demande de calibrage
			if(calibrage == 1)
			{
				// Mesure le cote du carre
				taillePixel =this->distanceEntreDeuxPoint(pt[0],pt[1]);

				  taillePixel =  abs(pt[0].y - pt[1].y);

				//Affiche le resultat sur l'ihm
			   //	Memo1->Lines->Add(mesure1);
				//Memo1->Lines->Add(mesure2);

				// calcul et stock dans une variable globale de la classe le nombre de pixel pour 1 centimétre
				taillePixel = taillePixel/valCarreCalibrage;

			}
			else
			{
			   if( abs(pt[0].x - pt[1].x) <10)
			   {
				   tabMesure[0] =this->distanceEntreDeuxPoint(pt[0],pt[1]);
				   tabMesure[1] =  this->distanceEntreDeuxPoint(pt[1],pt[2]);
			   }
			   else
			   {
				tabMesure[0] = this->distanceEntreDeuxPoint(pt[1],pt[2]);
				tabMesure[1] = this->distanceEntreDeuxPoint(pt[0],pt[1]);

               }
				// Mesure le cote du carre

				tabMesure[0] = tabMesure[0]/taillePixel ;
				tabMesure[1] =  tabMesure[1]/taillePixel;
			}


		//Memo1->Lines->Add(taillePixel);
         // initialize reader of the sequence
    cvStartReadSeq( squares, &reader, 0 );


		//dessine les rectangle detecte sur l'image de base
		cvPolyLine( imgCamRef, &rect, &count, 1, 1, CV_RGB(0,255,0), 3, CV_AA, 0 );

		// Point qui permet de determine a partir de ou on selectionne l'image a affiche
		CvPoint point;
		point.x = 0;
		point.y = 0;

		cvCopyMakeBorder( cpy,cpy,point,1, cvScalarAll(0) );
		 cvSetImageROI(imgCamRef,cvRect( 165, 0, 418, 346 ));
		 cvNamedWindow("Verification du rectangle detecte",1);
		//Affiche l'image dans la fenetre Source
		cvShowImage( "Verification du rectangle detecte", imgCamRef );
		//Vide le pointeur
		cvReleaseImage( &cpy );
}

float traitementImage::distanceEntreDeuxPoint(CvPoint pt1,CvPoint pt2)
{
	return sqrt(pow((double)(pt1.x-pt2.x),2)+pow((double)(pt1.y-pt2.y),2));
}
