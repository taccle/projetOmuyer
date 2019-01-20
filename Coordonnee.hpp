#ifndef COORDONNEE_HPP
#define COORDONNEE_HPP

class Coordonnee{
public:

  Coordonnee();
  float getX();
  int getY();
  int getZ();
  int getT();
  void setX(float);
  void setY(int);
  void setZ(int);
  void setT(int);
  void afficherPosition();
  bool ok();

private:

  float m_x;
  int m_y;
  int m_z;
  int m_t;
};

#endif
