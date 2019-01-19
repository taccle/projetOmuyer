#include "affichage.hpp"


void afficherVideo(string fenetre, Mat *pImage, bool taille){
  if(taille){
    redimensionnement(pImage, 80, 60);
  }
  imshow(fenetre, *pImage);
  waitKey(1);
}


void trackBar(int* run, int* cleanData){
  namedWindow("test",1);
  createTrackbar("run", "test", run, 1);
  createTrackbar("cleanData", "test", cleanData, 1);
}
