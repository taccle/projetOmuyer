#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



int main()
{
  // >>> LECTURE, TRAITEMENT ET ANALYSE D'UNE IMAGE SAUVEGARDEE <<<

  // Lecture
  Mat I = imread("/home/pi/Documents/projetOmuyer/etallonage/balle.jpg", CV_LOAD_IMAGE_COLOR);
  //Mat imCo = imread("balle.jpg", CV_LOAD_IMAGE_COLOR);
  if (!I.data) {
    cout << "Erreur de lecture du fichier image" << endl;
    return -1;
  }
  
  Mat dest;
  Size size(400,400);
  //resize(I,dest,size);
  
  //imshow("dest.jpg", dest);
  //imshow("image",I);
  //waitKey(0);
 
  Mat hsv;
  cvtColor(I,hsv,CV_BGR2HSV);
  vector<Mat> channels;
  split(hsv, channels);
  Mat Hue = channels[0];            // recuperation Hue
  Mat Saturation = channels[1];            // recuperation saturation
  Mat Value = channels[2];            // recuperation Value
  
  float h;
  float tolerance;
  Mat mask(I.size(), I.depth(),1);
  for (int i=0; i<=90; i++){
    inRange(hsv, Scalar(i*2-2,0,0), Scalar(i*2+3, 255, 255), mask);
    resize(mask,dest,size);
    imshow(to_string(i),dest);
    waitKey(0);
  }
}
