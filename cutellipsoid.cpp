#include "cutellipsoid.h"
#include <iostream>
#include <cmath>

//associando as variaveis da classe
cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
  this->rx=rx;
  this->ry=ry;
  this->rz=rz;
}
//informando que a figura foi destruida
cutEllipsoid::~cutEllipsoid(){
  std::cout<<"Elipsoid Destruida!";
}

//apagando a figura
void cutEllipsoid::draw(Sculptor &s){
  
 for (int i = 0; i < s.getNx(); i++) {
    for (int j = 0; j < s.getNy(); j++) {
      for (int k = 0; k < s.getNz(); k++) {
        // calcula equação da esfera
        float eq =
            ((pow((float)(xcenter-i)/(rx), 2) ) + 
            (pow((float)(ycenter-j)/(ry), 2)) +
            (pow((float)(zcenter-k)/(rz), 2) ));

        // se resultado da equação for menor ou igual ao raio ao quadrado
        if (eq <= 1) {
          s.cutVoxel(i, j, k); // deleta voxels
        }
      }
    }
  }
}