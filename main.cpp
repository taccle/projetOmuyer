#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

#include "camera.hpp"
#include "affichage.hpp"
#include "traitement.hpp"
#include "calculs.hpp"
#include "Coordonnee.hpp"

using namespace std;
using namespace cv;

//sudo modprobe bcm2835-v4l2

int main(int, char**)
{

  VideoCapture cap(0);
  Mat frame;
  Mat traite;
  int rayon;
  vector<int> dist;
  int run = 1;
  int cleanData = 0;
  trackBar(&run, &cleanData);
  while(run){
    if (cleanData){
      cleanData = 0;
      dist.clear();
      cout << "cleaning the datas" << endl;
    }
    // Récupération de l'image
    recuperationImage(cap, &frame);
    // Traitement de l'images
    rayon = Hough(frame, &traite);
    // Affichage
    distance(rayon, &dist);
    for(int i = 0; i<dist.size(); i++){
      cout << dist[i] << "   ";
    }
    afficherVideo("brut", &frame, true);
    afficherVideo("traitee", &traite, false);

    // Quitter la fonction avec appui sur une touche

  }
  //Mat frame;
  //std:: thread t1(recuperationImage, cap, &frame);
  //std:: thread t2(afficherFlux, &frame);

  //t1.join();
  //t2.join();

  arreterCamera(cap);

	return 0 ;
}


//Appui d'un bouton pour nettoyer les données
//On lance un chrono
//A chaque fois qu'on choppe la balle on associe sa taille,
//  sa postition, et un chrono
// création d'une classe lancé
