#ifndef LANCER_HPP
#define LANCER_HPP

#include <vector>

#include "Coordonnee.hpp"

class Lancer{
public:
  Lancer();
  void ajouter(Coordonnee);
  void afficher();
  void calculVitesse();

private:
  std::vector<Coordonnee> m_l;
  float m_vitesseX;
};

#endif
