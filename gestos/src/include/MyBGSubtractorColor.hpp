#pragma once

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define MAX_HORIZ_SAMPLES 3
#define MAX_VERT_SAMPLES 6
#define SAMPLE_SIZE 20
#define DISTANCE_BETWEEN_SAMPLES 30

class MyBGSubtractorColor {

public:

    MyBGSubtractorColor(cv::VideoCapture vc);
    bool LearnModel();
	void ObtainBGMask(cv::Mat frame, cv::Mat &bgmask);
    bool reiniciarHIGHGUI_;
    bool aplicarMediaTotal_;
    int max_samples;
private:
    int h_low,h_up,l_low,l_up,s_low,s_up,dilation,mediana,ero;
    int max_horiz_samples,max_vert_samples,sample_size,distance_between_samples;
    cv::VideoCapture cap;
	
	std::vector<cv::Scalar> means;
    cv::Scalar  mediaTodosLosCuadrados_;
    std::vector<cv::Scalar> lower_bounds;
	std::vector<cv::Scalar> upper_bounds;    
    static void Trackbar_func(int, void*);
};
