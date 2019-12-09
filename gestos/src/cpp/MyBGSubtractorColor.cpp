#include <MyBGSubtractorColor.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <QMessageBox>
using namespace cv;
using namespace std;



MyBGSubtractorColor::MyBGSubtractorColor(VideoCapture vc) {

    cap = vc;
    lower_bounds = vector<Scalar>();
    upper_bounds = vector<Scalar>();
    means = vector<Scalar>();
    reiniciarHIGHGUI_=false;
    mediaTodosLosCuadrados_=0;
	h_low = 12;
    h_up = 7;
	l_low = 30;
	l_up = 40;
	s_low = 80;
	s_up = 80;
    dilation=0;
    mediana=1;
    ero=0;
    max_horiz_samples=3;
    max_vert_samples=6;
    sample_size=20;
    distance_between_samples=30;
    aplicarMediaTotal_=false;

    namedWindow("Trackbars");
	createTrackbar("H low:", "Trackbars", &h_low, 100, &MyBGSubtractorColor::Trackbar_func);
	createTrackbar("H high:", "Trackbars", &h_up, 100, &MyBGSubtractorColor::Trackbar_func);
	createTrackbar("L low:", "Trackbars", &l_low, 100, &MyBGSubtractorColor::Trackbar_func);
	createTrackbar("L high:", "Trackbars", &l_up, 100, &MyBGSubtractorColor::Trackbar_func);
	createTrackbar("S low:", "Trackbars", &s_low, 100, &MyBGSubtractorColor::Trackbar_func);
	createTrackbar("S high:", "Trackbars", &s_up, 100, &MyBGSubtractorColor::Trackbar_func);
    //createTrackbar("Mediana:", "Trackbars", &mediana, 100, &MyBGSubtractorColor::Trackbar_func);
    createTrackbar("Dilation", "Trackbars", &dilation, 25, &MyBGSubtractorColor::Trackbar_func);
    createTrackbar("Erosion", "Trackbars", &ero, 25, &MyBGSubtractorColor::Trackbar_func);
    createTrackbar("MAX_HORIZ_SAMPLES", "Trackbars", &max_horiz_samples, 50, nullptr);
    createTrackbar("MAX_VERT_SAMPLES", "Trackbars", &max_vert_samples, 50, nullptr);
    createTrackbar("SAMPLE_SIZE", "Trackbars", &sample_size, 150, &MyBGSubtractorColor::Trackbar_func);
    createTrackbar("DISTANCE_BEWEEN_SAMPLES", "Trackbars", &distance_between_samples, 50, &MyBGSubtractorColor::Trackbar_func);
    createTrackbar("Distancia de la mano", "Trackbars", &distancia_mano, 150000, &MyBGSubtractorColor::Trackbar_func);
}

void MyBGSubtractorColor::Trackbar_func(int, void*)
{

}

bool  MyBGSubtractorColor::LearnModel() {


	Mat frame, tmp_frame, hls_frame;
	std::vector<cv::Point> samples_positions;


    namedWindow("Cubre los cuadrados con la mano y pulsa espacio");

  char c;
    do {

      max_samples = max_horiz_samples * max_vert_samples;
      lower_bounds.resize(max_samples);
      upper_bounds.resize(max_samples);
      means.resize(max_samples);
      samples_positions.resize(0);

        cap >> frame;


        //almacenamos las posiciones de las esquinas de los cuadrados
        Point p;
        for (int i = 0; i < max_horiz_samples; i++) {
            for (int j = 0; j < max_vert_samples; j++) {
                p.x = frame.cols / 2 + (-max_horiz_samples / 2 + i)*(sample_size + distance_between_samples);
                p.y = frame.rows / 2 + (-max_vert_samples / 2 + j)*(sample_size+ distance_between_samples);
                samples_positions.push_back(p);
            }
        }

        flip(frame, frame, 1);

        frame.copyTo(tmp_frame);

        //dibujar los cuadrados

        for (int i = 0; i < max_samples; i++) {
            rectangle(tmp_frame, Rect(samples_positions[i].x, samples_positions[i].y,
                      sample_size, sample_size), Scalar(0, 255, 0), 2);
        }


        imshow("Cubre los cuadrados con la mano y pulsa espacio", tmp_frame);

        c = cv::waitKey(40);

    }  while (((char)c != ' ') && (!reiniciarHIGHGUI_));


if (!reiniciarHIGHGUI_)
{

        // CODIGO 1.1
        // Obtener las regiones de interÃ©s y calcular la media de cada una de ellas
        // almacenar las medias en la variable means
        // ...

        cvtColor(frame, hls_frame, cv::COLOR_BGR2HLS);
	for (int i = 0; i < max_samples; i++) {
        Mat roi = hls_frame(Rect(samples_positions[i].x, samples_positions[i].y,sample_size, sample_size));
        means[i]=mean(roi);
        mediaTodosLosCuadrados_[0]=mediaTodosLosCuadrados_[0] + means[i][0];
        mediaTodosLosCuadrados_[1]=mediaTodosLosCuadrados_[1] + means[i][1];
        mediaTodosLosCuadrados_[2]=mediaTodosLosCuadrados_[2] + means[i][2];
	}
		
    mediaTodosLosCuadrados_[0]=mediaTodosLosCuadrados_[0] /max_samples;
    mediaTodosLosCuadrados_[1]=mediaTodosLosCuadrados_[1] /max_samples;
    mediaTodosLosCuadrados_[2]=mediaTodosLosCuadrados_[2] /max_samples;
    means.push_back(mediaTodosLosCuadrados_); //agrego media de todos los puntos al final del vector

        destroyWindow("Cubre los cuadrados con la mano y pulsa espacio");
 }
 return reiniciarHIGHGUI_;
}
void  MyBGSubtractorColor::ObtainBGMask(cv::Mat frame, cv::Mat &bgmask) {
        
        // CODIGO 1.2
        // Definir los rangos mÃ¡ximos y mÃ­nimos para cada canal (HLS) 
        // umbralizar las imÃ¡genes para cada rango y sumarlas para
        // obtener la mÃ¡scara final con el fondo eliminado
        //...
	
 Mat hls_frame, tmp_frame;
Mat acc(frame.rows,frame.cols,CV_8U);
acc.setTo(Scalar (0));
Scalar aux;
    // CODIGO 1.2
    // Definir los rangos máximos y mínimos para cada canal (HLS)
    // umbralizar las imágenes para cada rango y sumarlas para
    // obtener la máscara final con el fondo eliminado
    //...
 cvtColor(frame, hls_frame, cv::COLOR_BGR2HLS);


        for (int i = 0; i < max_samples; i++)
            {
                    aux[0] = means[i][0];
                    aux[1] = means[i][1];
                    aux[2] = means[i][2];
                    Scalar low, high;

                        if((aux[0]-h_low)<0)
                            low[0] = 0;
                        else
                            low[0] = aux[0]-h_low;

                        if((aux[1]-l_low)<0)
                            low[1] = 0;
                        else
                            low[1] = aux[1]-l_low;

                        if((aux[2]-s_low)<0)
                            low[2] = 0;
                        else
                            low[2] = aux[2]-s_low;
                        if((aux[0]+h_up)>255)
                            high[0] = 255;
                        else
                            high[0] = aux[0]+h_up;
                        if((aux[1]+l_up)>255)
                            high[1] = 255;
                        else
                            high[1] = aux[1]+l_up;
                        if((aux[2]+s_up)>255)
                            high[2] = 255;
                        else
                            high[2] = aux[2]+s_up;

                    inRange(hls_frame, low, high, tmp_frame);
                    acc = acc +tmp_frame;
            }

        acc.copyTo(bgmask);
medianBlur(bgmask, bgmask,mediana);
Mat element = getStructuringElement(MORPH_RECT, Size(2*dilation + 1, 2*dilation + 1),Point(dilation,dilation));
Mat erosion = getStructuringElement(MORPH_RECT, Size(2*ero + 1, 2*ero + 1),Point(ero,ero));
dilate(bgmask,bgmask,element);
erode(bgmask,bgmask,erosion);

}

