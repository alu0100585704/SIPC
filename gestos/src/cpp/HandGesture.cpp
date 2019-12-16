#include <HandGesture.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/video/background_segm.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
#include <QDebug>
#include <QMessageBox>
using namespace cv;
using namespace std;

HandGesture::HandGesture() {
	
}


double HandGesture::getAngle(Point s, Point e, Point f) {
	
	double v1[2],v2[2];
	v1[0] = s.x - f.x;
	v1[1] = s.y - f.y;

	v2[0] = e.x - f.x;
	v2[1] = e.y - f.y;

	double ang1 = atan2(v1[1],v1[0]);
	double ang2 = atan2(v2[1],v2[0]);

	double angle = ang1 - ang2;
	if (angle > CV_PI) angle -= 2 * CV_PI;
	if (angle < -CV_PI) angle += 2 * CV_PI;
	return (angle * 180.0/CV_PI);
}
pair<int,int> HandGesture::FeaturesDetection(Mat &mask, Mat &output_img, std::vector<Point> &traza_) {
	
	vector<vector<Point> > contours;
	Mat temp_mask;
	mask.copyTo(temp_mask);
	int index = -1;

        // CODIGO 3.1
        // detecci√≥n del contorno de la mano y selecci√≥n del contorno m√°s largo
        //...
    circle(temp_mask, Point (10,10), 1, Scalar(255));
        findContours(temp_mask,contours,cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // pintar el contorno
        //...
        int aux_sz = 0;
            for(int i = 0; i < contours.size();i++)
                if(contours[i].size() > aux_sz){
                    aux_sz = contours[i].size();
                    index  = i;
                }

        // AquÌ voy a intentar limpiar y solo coger el contorno si cuadra con unos valores relaciÛn entre el area del rectangulo y el numero de puntos
            //de un contorno
           /*Rect boundRectAux;
           int resolucion,areaMano,numeroPixelContorno,margenSuperior,margenInferior,margen;


           resolucion=output_img.rows*output_img.cols; // la proporciÛn puede cambiar dependiendo de la c·mar, y por tanto todo lo dem·s.
           areaMano=resolucion*0.35; //mas o menos un 35% debe de ser el rect·ngulo del area de la mano


           boundRectAux = boundingRect(contours[index]);
           numeroPixelContorno=boundRectAux.area()*0.0070; //este porcentaje es el numero de pixeles que deberÌan conformar el contorno
           margen=numeroPixelContorno*0.20; //margen de 2% superior e inferior

           if ((contours[index].size() > numeroPixelContorno-margen) &&  (contours[index].size() < numeroPixelContorno+margen))
            {
               putText(output_img,"Mano Detectada",Point(100,130),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
               drawContours(output_img,contours, index, cv::Scalar(255,255,255), 2, 8, vector<Vec4i>(), 0, Point());
           }
*/
   drawContours(output_img,contours, index, cv::Scalar(305,49,43), 2, 8, vector<Vec4i>(), 0, Point());



	//obtener el convex hull	
	vector<int> hull;
	convexHull(contours[index],hull);
	
	// pintar el convex hull
	Point pt0 = contours[index][hull[hull.size()-1]];
	for (int i = 0; i < hull.size(); i++)
	{
		Point pt = contours[index][hull[i]];
        //line(output_img, pt0, pt, Scalar(0, 0, 255), 2, cv::CV_AA);
        line(output_img, pt0, pt, Scalar(0, 0, 255), 2, cv::LINE_AA);
		pt0 = pt;
	}
	
        //obtener los defectos de convexidad
	vector<Vec4i> defects;
	convexityDefects(contours[index], hull, defects);
		

    Rect boundRect;
    boundRect = boundingRect( contours[index]);

    multimap<float,vector<Point>> mayor;
    pair<float,vector<Point>> nodo;

		int cont = 0;
		for (int i = 0; i < defects.size(); i++) {
			Point s = contours[index][defects[i][0]];
			Point e = contours[index][defects[i][1]];
			Point f = contours[index][defects[i][2]];
			float depth = (float)defects[i][3] / 256.0;
			double angle = getAngle(s, e, f);
//            if ((angle < 100.00) && ((int)depth > 50) && ((int) depth < 160)) //si el √°ngulo es mayor de 90 grados, ni siquiera insertes el punto en el map.
if ((angle < 90.00) && (depth>90)) //si el √°ngulo es mayor de 90 grados, ni siquiera insertes el punto en el map.
                {
                    nodo.second.resize(3);
                    nodo.first=depth;
                    nodo.second[0]=s;
                    nodo.second[1]=e;
                    nodo.second[2]=f;
                    mayor.insert(nodo);

                 }

     // CODIGO 3.2
                        // filtrar y mostrar los defectos de convexidad
                        //...

                }
        int contador=0;
        multimap<float,vector<Point>>::reverse_iterator it_mayor;
        vector<pair<bool,Point>> gestos(4); //inicializo para contar los puntos
        pair <bool,Point> puntoGesto;
        it_mayor=mayor.rbegin();
        while ((it_mayor!= mayor.rend()) && (contador <4))
        {
            //marco los puntos mas a lejados y el inicio de cada uno de ellos
            circle(output_img, it_mayor->second[0], 5, Scalar(255,0,0), 3); //azul inicio
            circle(output_img, it_mayor->second[1], 5, Scalar(0,255,0), 3); //verde final
            circle(output_img, it_mayor->second[2], 5, Scalar(0,0,255), 3);
//      switch (contador)
//            {
//                case 0:
              // putText(output_img,"C: " + std::to_string(contador) + " P: " + std::to_string((int) it_mayor->first) +  " A:" + std::to_string((int)getAngle(it_mayor->second[0], it_mayor->second[1], it_mayor->second[2])),Point(30,430),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
//                 break;
//            case 1:

//                break;
//            case 2:
//                break;
//            case 3:
//                   break;
//            }

            contador++;
            it_mayor++;            

            //imshow("Reconocimiento", output_img);
            //QMessageBox::warning(nullptr,"Punto",QString("Valor profundiad %1").arg(it_mayor->first));
       }

putText(output_img,"Area : " + std::to_string(boundRect.area()),Point(350,30),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
        //en contador numero de dedos
        //putText(output_img,std::to_string(contours[index].size()),Point(30,230),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
        //putText(output_img,std::to_string(hull.size()),Point(30,330),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
        //putText(output_img,std::to_string(output_img.rows*output_img.cols),Point(30,130),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
        if (boundRect.area() < (distancia_mano*0.45))
        {
               contador=-1;
               traza_.resize(0);
            }

        int gesto=0;
               if ((boundRect.height < boundRect.width) && (contador<3) && contador > -1)
                        gesto=1;
               else if  ((boundRect.height > boundRect.width) && (contador==4))
                    gesto=2;

         //output_img.rows*output_img.cols;
         int centrox=(boundRect.width / 2) + boundRect.x;
         int centroy=(boundRect.height / 2) + boundRect.y;

         if (centroy <= (output_img.rows /2) && centrox <= (output_img.cols /3))
                putText(output_img,"Superior/Izquierda ",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (centroy > (output_img.rows /2) && centrox <= (output_img.cols /3))
                putText(output_img,"Inferior/Izquierda ",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (centroy < (output_img.rows /2) && centrox > (output_img.cols /3) && centrox < (output_img.cols * 2 /3))
                putText(output_img,"Superior/Centro",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (centroy > (output_img.rows /2) && centrox > (output_img.cols /3) && centrox < (output_img.cols * 2 /3))
                putText(output_img,"Inferior/Centro ",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (centroy < (output_img.rows /2) && centrox > (output_img.cols * 2 /3))
                putText(output_img,"Superior/Derecha",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (centroy > (output_img.rows /2) && centrox > (output_img.cols * 2 /3))
                putText(output_img,"Inferior/Derecha",Point(250,400),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);

         if (contador==1)
        {
         putText(output_img,"Pintando",Point(350,300),FONT_HERSHEY_COMPLEX,1,Scalar(255),1);
            it_mayor=mayor.rbegin();
            traza_.push_back(it_mayor->second[2]);

          for (int i=0; i < traza_.size(); i++)
                       circle(output_img, traza_[i], 5, Scalar(250,120,200), 3);

        }


/*        vector<Point2f>centers( contours.size() );
        vector<float>radius( contours.size() );
        for( size_t i = 0; i < contours.size(); i++ )
        {
            approxPolyDP( contours[i], contours_poly[i], 3, true );
            boundRect[i] = boundingRect( contours_poly[i] );
            minEnclosingCircle( contours_poly[i], centers[i], radius[i] );
        }
        Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
        for( size_t i = 0; i< contours.size(); i++ )
        {
            Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
            drawContours( drawing, contours_poly, (int)i, color );

  */


        pair<int,int> resultado(contador+1,gesto);
return resultado ;

}

