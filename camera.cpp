#include "camera.hpp"


void initialiserCamera(VideoCapture cap, int fps, int largeur, int hauteur){
  if(!cap.set(CV_CAP_PROP_FPS,fps)){
    cout << "fps : " << fps << endl;
  }
  else{
    cout << "echec initialisation fps" << endl;
  }

  if(!cap.set(CV_CAP_PROP_FRAME_WIDTH,largeur)){
    cout << "largeur : " << largeur << endl;
  }
  else{
    cout << "echec initialisation largeur" << endl;
  }

  if(!cap.set(CV_CAP_PROP_FRAME_HEIGHT,hauteur)){
    cout << "hauteur : " << hauteur << endl;
  }
  else{
    cout << "echec initialisation hauteur" << endl;
  }
}


VideoCapture demarrerCamera(){
  // Connection de la camera
  VideoCapture cap(0);
  if (!cap.isOpened()){
    cerr << "ERROR: Unable to open the camera" << endl;
    return 0;
  }
  return cap;
}


void recuperationImage(VideoCapture cap, Mat *pImage){
  // Recuperation des images
  cap >> *pImage;
}


int arreterCamera(VideoCapture cap){
  // Arret de la camera
  cout << "Closing the camera" << endl;
  cap.release();
  destroyAllWindows();
  return 0;
}
