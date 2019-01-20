#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <unistd.h>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

#include "traitement.hpp"
#include "Coordonnee.hpp"


using namespace std;
using namespace cv;


void initialiserCamera(VideoCapture, int, int, int);
VideoCapture demarrerCamera();
int arreterCamera(VideoCapture);
void recuperationImage(VideoCapture, Mat*);
void modif(int*);
void afficherVideo(String, Mat*, bool);
void trackBar(int*, int*, int*);

#endif
