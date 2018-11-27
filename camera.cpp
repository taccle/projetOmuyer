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
    Mat gray;
    Mat sized;
    Size size(160,100); //640*480
    resize(frame, sized, size);
    cvtColor(sized, gray, CV_BGR2GRAY);
    imshow("Live",gray);
    int key = cv::waitKey(1);
    key = (key==255) ? -1 : key; //#Solve bug in 3.2.0
    if (key>=0)
      break;
  }
  cout << frame.size() << endl;

  cout << "Closing the camera" << endl;
  cap.release();
  destroyAllWindows();
  cout << "bye!" <<endl;
  return 0;
}
