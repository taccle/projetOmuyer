#ifndef AFFICHAGE_HPP
#define AFFICHAGE_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <mutex>
#include <unistd.h>

#include "traitement.hpp"

using namespace std;
using namespace cv;

void afficherVideo(string, Mat*, bool);
void trackBar(int*, int*);

#endif
