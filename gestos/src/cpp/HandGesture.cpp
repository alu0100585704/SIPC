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
pair<int,int> HandGesture::FeaturesDetection(Mat mask, Mat output_img) {
	
	vector<vector<Point> > contours;
	Mat temp_mask;
	mask.copyTo(temp_mask);
	int index = -1;

        // CODIGO 3.1
        // detección del contorno de la mano y selección del contorno más largo
        //...
    circle(temp_mask, Point (10,10), 5, Scalar(255));
        findContours(temp_mask,contours,cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        // pintar el contorno
        //...
        int aux_sz = 0;
            for(int i = 0; i < contours.size();i++)
                if(contours[i].size() > aux_sz){
                    aux_sz = contours[i].size();
                    index  = i;
                }
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
		
		
    map<float,vector<Point>> mayor;
    pair<float,vector<Point>> nodo;

		int cont = 0;
		for (int i = 0; i < defects.size(); i++) {
			Point s = contours[index][defects[i][0]];
			Point e = contours[index][defects[i][1]];
			Point f = contours[index][defects[i][2]];
			float depth = (float)defects[i][3] / 256.0;
			double angle = getAngle(s, e, f);
            if (angle < 90.00) //si el ángulo es mayor de 90 grados, ni siquiera insertes el punto en el map.
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
        map<float,vector<Point>>::reverse_iterator it_mayor;
        vector<pair<bool,Point>> gestos(4); //inicializo para contar los puntos
        pair <bool,Point> puntoGesto;
        it_mayor=mayor.rbegin();
        while ((it_mayor!= mayor.rend()) && (contador <4))
        {
            //marco los puntos mas a lejados y el inicio de cada uno de ellos
            circle(output_img, it_mayor->second[0], 5, Scalar(255,0,0), 3); //azul inicio
            circle(output_img, it_mayor->second[1], 5, Scalar(0,255,0), 3); //verde final
            circle(output_img, it_mayor->second[2], 5, Scalar(0,0,255), 3);
            contador++;
            it_mayor++;            

            //imshow("Reconocimiento", output_img);
            //QMessageBox::warning(nullptr,"Punto",QString("Valor profundiad %1").arg(it_mayor->first));
       }

        //en contador numero de dedos

        Rect boundRect;
        boundRect = boundingRect( contours[index]);

        boundRect.area();
        if (boundRect.area() < (distancia_mano*0.50))
               contador=-1;
        qDebug()<< boundRect.area();

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

        int gesto=0;
        pair<int,int> resultado(contador+1,gesto);
return resultado ;

}
