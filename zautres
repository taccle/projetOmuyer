int direct()
{
  VideoCapture cap(0);
  if (!cap.isOpened()) {
    cerr << "ERROR: Unable to open the camera" << endl;
    return 0;
  }

  namedWindow("test",1);
  int teinte = 17;
  int saturation = 180;
  int th = 8;
  int ts = 77;
  createTrackbar("Hue", "test", &teinte, 179);
  createTrackbar("Saturation", "test", &saturation, 255);
  createTrackbar("tolerance teinte", "test", &th, 80);
  createTrackbar("tolerance saturation", "test", &ts, 127);

  int erosion = 6;
  createTrackbar("erosion", "test", &erosion, 30);
  int dilatation = 6;
  createTrackbar("dilatation", "test", &dilatation, 30);

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

    // float h = teinte*180.0/100.0;
    // float s = saturation*255.0/100;
    // float tolerance = 3;
    Mat mask1(frame.size(), frame.depth(), 1);
    Mat mask2(frame.size(), frame.depth(), 1);

    int tsup = (teinte + th)%180;
    int tinf = (teinte - th  + 360)%180;
    int ssup = (saturation + ts)%256;
    int sinf = (saturation - ts + 512)%256;

    //cout << "teinte" << "  " << (max(abs(tsup-tinf)/(tsup-tinf)*tinf, 0))  << "  à  " << tsup<< endl;
    //cout << "teinte" << "  " <<  tinf << "   à  "  << ((max(abs(tsup-tinf)/(tsup-tinf)*tsup, 0))+179)%180 << endl;

    //cout << "saturation" << "  " << (max(abs(ssup-sinf)/(ssup-sinf)*sinf, 0))  << "  à  " << ssup<< endl;
    //cout << "saturation" << "  " <<  sinf << "   à  "  << ((max(abs(ssup-sinf)/(ssup-sinf)*ssup, 0))+255)%256 << endl;

    inRange(hsv, Scalar( (max(abs(tsup-tinf)/(tsup-tinf)*tinf, 0)),  (max(abs(ssup-sinf)/(ssup-sinf)*sinf, 0)), 0), Scalar(tsup, ssup, 255), mask1);
    inRange(hsv, Scalar( tinf, sinf, 0), Scalar( ((max(abs(tsup-tinf)/(tsup-tinf)*tsup, 0))+179)%180, ((max(abs(ssup-sinf)/(ssup-sinf)*ssup, 0))+255)%256, 255), mask2);
    add(mask1, mask2, iTraite);

    Mat elDilat = getStructuringElement(MORPH_RECT, Size(dilatation, dilatation), Point(-1, -1));
    Mat elErod = getStructuringElement(MORPH_RECT, Size(erosion, erosion), Point(-1, -1));

    erode(iTraite, iTraite, elErod);
    dilate(iTraite, iTraite, elDilat);

    GaussianBlur( iTraite, iTraite, Size(9,9), 2, 2);

    Size size(80,60); //640*480
    resize(iTraite, iTraite, size);
    Size size2(80, 60);
    resize(frame, frame, size2);

    Mat gray;
    cvtColor(frame, gray, CV_BGR2GRAY);

    vector<Vec3f> circles;
    HoughCircles (iTraite, circles, CV_HOUGH_GRADIENT, 1, iTraite.rows/8, 200, 100, 0, 0);

    for( size_t i = 0; i < circles.size(); i++ )
      {
	cout << i  << endl;
	Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	int radius = cvRound(circles[i][2]);
	// circle center
	circle( frame, center, 3, Scalar(0,255,0), -1, 8, 0 );
	// circle outline
	circle( frame, center, radius, Scalar(0,0,255), 3, 8, 0 );
      }
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




    imshow("Image Traitee",iTraite);
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
