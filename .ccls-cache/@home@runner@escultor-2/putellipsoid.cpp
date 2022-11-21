#include "putellipsoid.h"
#include <iostream>
#include <cmath>

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
  this->rx=rx;
  this->ry=ry;
  this->rz=rz;
}
putEllipsoid::~putEllipsoid(){
  std::cout<<"Elipsoid Destruida!";
}
void putEllipsoid::draw(Sculptor &s){
  
  s.setColor(r,g,b,a);
  
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nx; k++) {
        // calcula equação da esfera
        float eq =
            ((pow((float)(xcenter-i)/(rx), 2) ) + 
            (pow((float)(ycenter-j)/(ry), 2)) +
            (pow((float)(zcenter-k)/(rz), 2) ));

        // se resultado da equação for menor ou igual ao raio ao quadrado
        if (eq <= 1) {
          s.putVoxel(i, j, k); // desenha voxels
        }
      }
    }
  }
}