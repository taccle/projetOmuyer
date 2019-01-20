#include "Coordonnee.hpp"

#include <iostream>

using namespace std;

Coordonnee::Coordonnee(){
  m_x = 42;
  m_y = 0;
  m_z = 0;
  m_t = 0;
}

float Coordonnee::getX(){
  return m_x;
}

int Coordonnee::getY(){
  return m_y;
}

int Coordonnee::getZ(){
  return m_z;
}

int Coordonnee::getT(){
  return m_t;
}

void Coordonnee::setX(float x){
  m_x = x;
}

void Coordonnee::setY(int y){
  m_y = y;
}

void Coordonnee::setZ(int z){
  m_z = z;
}

void Coordonnee::setT(int t){
  m_t = t;
}

void Coordonnee::afficherPosition(){
  cout << "-" << m_x << "-" << m_y
  << "-"<< m_z << "-" << m_t;
}

bool Coordonnee::ok(){
  if(m_x){
    return 1;
  }
  return 0;
}
