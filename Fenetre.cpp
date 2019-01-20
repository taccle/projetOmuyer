#include "Fenetre.hpp"

Fenetre::Fenetre() : QWidget()
{
  setFixedSize(300, 150);
  m_bouton = new QPushButton("Quitter", this);
  m_bouton->setFont(QFont("Comic Sans MS", 14));
  m_bouton->move(110, 50);
  QObject::connect(m_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

// QApplication app(argc, argv);
// Fenetre test;
// test.show();
// app.exec();

void Fenetre::afficherImage(Mat frame){
//   cvtColor(frame, frame,CV_BGR2RGB);
//   redimensionnement(&frame, 80, 60);
//   QImage image((const uchar *) frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
//   QLabel myLabel;
//   myLabel.setPixmap(QPixmap::fromImage(image));
//   myLabel.show();
}

// void afficherVideo(string fenetre, Mat *pImage, bool taille){
//   if(taille){
//     redimensionnement(pImage, 80, 60);
//   }
//   imshow(fenetre, *pImage);
//   waitKey(1);
// }
//
//
// void trackBar(int* run, int* cleanData){
  // namedWindow("test",1);
  // createTrackbar("run", "test", run, 1);
  // createTrackbar("cleanData", "test", cleanData, 1);
    // QPushButton hello( "Hello world!", 0 );
    // hello.resize( 100, 30 );
    //
    // hello.show();
//}

// int main( int argc, char **argv )
// {
//
//
//   QPushButton hello( "Hello world!", 0 );
//   hello.resize( 100, 30 );
//
//   hello.show();
//   return a.exec();
// }
