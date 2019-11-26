#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>

#include <stdio.h>
#include <string>
#include <iostream>

#include <MyBGSubtractorColor.hpp>
#include <HandGesture.hpp>

#include <QCoreApplication>
#include <QApplication>
#include <QDebug>

#include <mainwindow.h>
using namespace std;
using namespace cv;



int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    MainWindow m;

    Mat frame, bgmask, out_frame;
	

	//Abrimos la webcam
    m.show();
a.exec();
    VideoCapture cap;
     cap.open(0);

	if (!cap.isOpened())
	{
		printf("\nNo se puede abrir la c�mara\n");
		return -1;
	}
        int cont = 0;
        while (frame.empty()&& cont < 2000 ) {

                cap >> frame;
                ++cont;
        }
        if (cont >= 2000) {
                printf("No se ha podido leer un frame v�lido\n");
                exit(-1);
        }


	// Creamos las ventanas que vamos a usar en la aplicaci�n
//qDebug()<< "espera 1";
	namedWindow("Reconocimiento");
	namedWindow("Fondo");



//qDebug()<< "espera 2";


        // creamos el objeto para la substracci�n de fondo
    MyBGSubtractorColor cuadrados(cap);
	// creamos el objeto para el reconocimiento de gestos

	// iniciamos el proceso de obtenci�n del modelo del fondo
	cuadrados.LearnModel();
    //qDebug()<< "espera 2";


	for (;;)
	{
		cap >> frame;
		//flip(frame, frame, 1);
		if (frame.empty())
		{
			printf("Le�do frame vac�o\n");
			continue;
		}
//		int c = cvWaitKey(40);
                int c = cv::waitKey(40);

		if ((char)c == 'q') break;

        using namespace std;
		// obtenemos la m�scara del fondo con el frame actual
                
                // CODIGO 2.1
                // limpiar la m�scara del fondo de ruido
                //...


		// deteccion de las caracter�sticas de la mano

                // mostramos el resultado de la sobstracci�n de fondo
		
                // mostramos el resultado del reconocimento de gestos

		imshow("Reconocimiento", frame);

		
	}
	
	destroyWindow("Reconocimiento");
	destroyWindow("Fondo");
    destroyWindow("Trackbars");
	cap.release();
    a.exec();
	return 0;
}
