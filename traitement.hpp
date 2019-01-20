#ifndef TRAITEMENT_HPP
#define TRAITEMENT_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <unistd.h>

#include "traitement.hpp"
#include "Coordonnee.hpp"
#include "calculs.hpp"


using namespace std;
using namespace cv;

Mat seuillage(Mat);
void hough(Mat, Mat*, Coordonnee*, int, int);
void redimensionnement(Mat*, int, int);


#endif
