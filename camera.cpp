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
  
  namedWindow("test",1);
  int teinte = 50;
  int saturation = 127;
  int th = 5;
  int ts = 127;
  createTrackbar("Hue", "test", &teinte, 179);
  createTrackbar("Saturation", "test", &saturation, 255);
  createTrackbar("tolerance teinte", "test", &th, 80);
  createTrackbar("tolerance saturation", "test", &ts, 127);

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
    
    float h = teinte*180.0/100.0;
    float s = saturation*255.0/100;
    float tolerance = 3;
    Mat mask1(frame.size(), frame.depth(), 1);

    int tsup = (teinte + th)%180;
    int tinf = (teinte - th+360)%180;
    
    cout << "second" << "  " << ((max(abs(tsup-tinf)/(tsup-tinf)*tinf, 0)))  << "  à  " << tsup<< endl;
    cout << "first" << "  " <<  tinf << "   à  "  << ((max(abs(tsup-tinf)/(tsup-tinf)*tsup, 0))+179)%180 << endl;
    
    //inRange(hsv, Scalar(tinf , 0, 0), Scalar((max(abs(tsup-tinf)/(tsup-tinf)*tsup,179)), 255, 255), mask1);
    //inRange(hsv, Scalar( , 0, 0), Scalar( , 255, 255), mask1);
     //cout << "teinte : " << teinte << endl;
    //cout << "saturation : " << saturation << endl;
    //cout << "tolerance teinte : " << th << endl;
    //cout << "tolerance saturation : " << ts << endl;
    // Mat mask2(frame.size(), frame.depth(), 1);
    //inRange(hsv, Scalar(15-5, 0, 0), Scalar(15+5, 255, 255), mask2);
    //Mat mask3(frame.size(), frame.depth(), 1);
    //inRange(hsv, Scalar(25-5,0,0), Scalar(25+5, 255, 255), mask3);
    //add(mask1, mask2, iTraite);
    //Mat element = getStructuringElement( MORPH_RECT, Size(3, 3), Point(-1,-1));  // erosion
    //erode(mask1,mask1, element);
    //traitement pour transmission
    Mat iLive1;
    //Size size(80,60); //640*480
    //resize(mask1, iLive1, size);
    Size size2(80, 60);
    resize(frame, frame, size2);
    //imshow("1",iLive1);
    imshow("reference", frame);
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
