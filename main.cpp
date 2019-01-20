#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <qapplication.h>
#include <qpushbutton.h>
#include <QLCDNumber>
#include <QSlider>
#include <QLabel>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
#include <unistd.h>

#include "camera.hpp"
#include "Fenetre.hpp"
#include "traitement.hpp"
#include "calculs.hpp"
#include "Coordonnee.hpp"
#include "Lancer.hpp"

using namespace std;
using namespace cv;

//sudo modprobe bcm2835-v4l2
//LIBS += `pkg-config opencv --cflags --libs`


int main()
{

  auto t0 = Clock::now();
  auto t1 = Clock::now();
  int delta;
  VideoCapture cap(0);
  Mat frame;
  Mat traite;
  vector<int> dist;
  Coordonnee coord = Coordonnee();
  Lancer monLancer = Lancer();
  int run = 1;
  int canny=188;
  double fps;
  int hou=23;
  trackBar(&run, &canny, &hou);
  while(run){
    //fps = cap.get(CV_CAP_PROP_FPS);
    //cout << fps << endl;
    recuperationImage(cap, &frame);

    t1 = Clock::now();
    delta = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()/1000000;
    coord.setT(delta);
    hough(frame, &traite, &coord, canny, hou);
    if(coord.ok()){
      monLancer.ajouter(coord);
      cout << '\a' << endl;
      //monLancer.afficher();
      monLancer.calculVitesse();

      //on l'ajoute au lancer
      //a partir des dix dernieres mesures on calcule sa position
      //lorsqu'elle sera arrivée
    }

    //distance(rayon, &dist);
    //afficherVideo("brut", &frame, true);
    afficherVideo("traitee", &traite, true);


    usleep(100);
  }
  monLancer.afficher();
  arreterCamera(cap);
	return 0 ;
}

//classe coordonnees
//classe lancé
//timer


// On lance un chrono
// A chaque image on récupère un rayon et une position
// sa postition, et un chrono
// création d'une classe lancé

//Mat frame;
//std:: thread t1(recuperationImage, cap, &frame);
//std:: thread t2(afficherFlux, &frame);

//t1.join();
//t2.join();
