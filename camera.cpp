#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "camera.hpp"

using namespace cv;
using namespace std;

int direct()
{
  VideoCapture cap(0);
  if (!cap.isOpened()) {
    cerr << "ERROR: Unable to open the camera" << endl;
    return 0;
  }

  Mat frame;
  cout << "Start grabbing, press a key on Live window to terminate" << endl;
  while(1) {
    cap >> frame;
    if (frame.empty()) {
      cerr << "ERROR: Unable to grab from the camera" << endl;
      break;
    }

    //traitement
    Mat iTraite;
    Mat hsv;
    cvtColor(frame,hsv,CV_BGR2HSV);
    vector<Mat> channels;
    split(hsv, channels);
    Mat Hue = channels[0];            // recuperation Hue
    Mat Saturation = channels[1];            // recuperation saturation
    Mat Value = channels[2];            // recuperation Value

    float h = 7.5;
    float tolerance = 3;
    Mat mask1(frame.size(), frame.depth(), 1);
    inRange(hsv, Scalar(10,50,0), Scalar(35, 75, 255), mask1);
    // Mat mask2(frame.size(), frame.depth(), 1);
    //inRange(hsv, Scalar(15-5, 0, 0), Scalar(15+5, 255, 255), mask2);
    //Mat mask3(frame.size(), frame.depth(), 1);
    //inRange(hsv, Scalar(25-5,0,0), Scalar(25+5, 255, 255), mask3);
    //add(mask1, mask2, iTraite);
    Mat element = getStructuringElement( MORPH_RECT, Size(3, 3), Point(-1,-1));  // erosion
    erode(mask1,mask1, element);
    //traitement pour transmission
    Mat iLive1;
    Size size(160,100); //640*480
    resize(mask1, iLive1, size);
    imshow("1",iLive1);
    int key = cv::waitKey(1);
    key = (key==255) ? -1 : key; //#Solve bug in 3.2.0
    if (key>=0)
     break;
  }

  cout << "Closing the camera" << endl;
  cap.release();
  destroyAllWindows();
  return 0;
}
