#ifndef TRAITEMENT_HPP
#define TRAITEMENT_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <unistd.h>

#include "traitement.hpp"


using namespace std;
using namespace cv;

Mat seuillage(Mat);
int Hough(Mat, Mat*);
void redimensionnement(Mat*, int, int);


#endif
