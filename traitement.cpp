#include "traitement.hpp"



Mat seuillage(Mat image){
  Mat hsv;
  cvtColor(image,hsv,CV_BGR2HSV);
  vector<Mat> channels;
  split(hsv, channels);
  Mat Hue = channels[0];            // recuperation Hue
  Mat Saturation = channels[1];            // recuperation saturation
  Mat Value = channels[2];            // recuperation Value

  Mat mask(image.size(), image.depth(), 1);

  inRange(hsv, Scalar(30, 0, 0), Scalar(90, 255, 255), mask);

  return mask;
  // Mat elDilat = getStructuringElement(MORPH_RECT, Size(dilatation, dilatation), Point(-1, -1));
  // Mat elErod = getStructuringElement(MORPH_RECT, Size(erosion, erosion), Point(-1, -1));

  // erode(iTraite, iTraite, elErod);
  // dilate(iTraite, iTraite, elDilat);

  // GaussianBlur( iTraite, iTraite, Size(9,9), 2, 2);
}


void hough(Mat image, Mat* traitee, Coordonnee* a, int canny, int hou){
  Mat gris;
  int rayon = 0;
  //copie du flux
  image.copyTo(*traitee);
  //redimensionnement (pas forcèment nécessaire
  //il faut rempalcer le 1 par un 2 en quatrième argument de
  //HoughCircles)
  redimensionnement(traitee, 320, 240);
  //Il faut passer l'image en teinte de gris pour la
  //transformée de Hough
  cvtColor(*traitee, gris, CV_BGR2GRAY);
  vector<Vec3f> cercles;
  //Récupération des cercles de HoughCircles
  //4 : redimensionnement de l'image
  //5 : distance entre deux cercles
  //6 : paramètre pour le passage en canny
  //7 : petit/grand : détection facile/difficile
  //8/9 : plus petit/grand cercle
  HoughCircles(gris, cercles, CV_HOUGH_GRADIENT,1,1000,canny,hou,0,100);
  //ne prendre qu'un seul cercle ?
  for( size_t i = 0; i < cercles.size(); i++ )
  {
    //Récupération du centre et rayon
    Point centre(cvRound(cercles[i][0]), cvRound(cercles[i][1]));
    rayon = cercles[i][2];
    //cout << "\a" << endl;
    //Tracé du cercle
    //3 : rayon
    //4 : couleur
    //5 :
    //6 :
    circle( *traitee, centre, 10, Scalar(0,0,0), 3, 8, 0);
    circle( *traitee, centre, rayon, Scalar(255,0,255), 8, 0);
    (*a).setY(cercles[0][0]);
    (*a).setZ(cercles[0][1]);
   }
  (*a).setX(rToD(rayon));


}


void redimensionnement(Mat* pImage, int largeur, int hauteur){
  Size size(largeur, hauteur);
  resize(*pImage, *pImage, size);
}
