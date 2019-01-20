#include "calculs.hpp"



float rToD(int rayon){
  float d = 0;
  if(rayon){
    //on a un rayon
    //2.5x*x+19.5x+50
    d = (7.7908)*exp(-0.063*rayon);
    //cout << '\a';
    //(*dist).push_back(rayon);
  }

  return d;
}
