#ifndef FENETRE_HPP
#define FENETRE_HPP

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <qapplication.h>
#include <qpushbutton.h>
#include <QLCDNumber>
#include <QSlider>
#include <QLabel>

#include "traitement.hpp"

using namespace std;
using namespace cv;

class Fenetre : public QWidget
{
public:
  Fenetre();
  void afficherImage(Mat);
  void changerTaille(int);

private:
  QPushButton *m_bouton;
};

#endif
