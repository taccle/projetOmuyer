#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <unistd.h>


using namespace std;
using namespace cv;

extern mutex m;

void initialiserCamera(VideoCapture, int, int, int);
VideoCapture demarrerCamera();
int arreterCamera(VideoCapture);
void recuperationImage(VideoCapture, Mat*);
void modif(int*);

#endif
