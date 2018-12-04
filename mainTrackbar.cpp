#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
  // Read original image
  Mat src = imread("balle.jpg");
  //if fail to read the image
  if (!src.data)
    {
      cout << "Error loading the image" << endl;
      return -1;
    }

Size size(412, 232);
resize(src,src,size);

// Create a window
namedWindow("My Window", 1);

//Create trackbar to change brightness
int iSliderValue1 = 50;
createTrackbar("Brightness", "My Window", &iSliderValue1, 100);
//Create trackbar to change contrast
int iSliderValue2 = 50;
createTrackbar("Contrast", "My Window", &iSliderValue2, 100);
//wait for you to press a key
waitKey(0);

while (true)
    {
    Mat dst;
    int iBrightness = iSliderValue1 - 50;
    double dContrast = iSliderValue2 / 50.0;
    src.convertTo(dst, -1, dContrast, iBrightness);
    //show the brightness and contrast adjusted image
    imshow("My Window", dst);
    // Wait until user press some key for 50ms
    //waitKey(0);
    int iKey = waitKey(50);
    //if user press 'ESC' key
    /*{
    break;
    }
    */
    }
return 0;
}
