#include "Lancer.hpp"

#include <iostream>

using namespace std;

Lancer::Lancer(){
  vector<Coordonnee> a;
  m_l = a;
  m_vitesseX = 0;
}

void Lancer::ajouter(Coordonnee a){
  m_l.push_back(a);
}

void Lancer::afficher(){
  for(int i = 0; i < m_l.size(); i++){
    m_l[i].afficherPosition();
    cout << "-" << m_vitesseX << endl;
  }
}

void Lancer::calculVitesse(){
  int s = m_l.size();
  int j=0;
  m_vitesseX = 0;
  if(s<10){
    m_vitesseX = 0;
  }
  else{
    //abs(dernierX - dernierX-10)/(tempsX - tempsX-10)
    m_vitesseX = float((m_l[s-1].getX()-m_l[s-2].getX()))/
    (m_l[s-1].getT()-m_l[s-2].getT());
    //cout << m_vitesseX*1000 << endl;
  }
}
