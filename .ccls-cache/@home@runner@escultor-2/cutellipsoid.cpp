#include "cutellipsoid.h"
#include <iostream>
#include <cmath>

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
  this->rx=rx;
  this->ry=ry;
  this->rz=rz;
}
cutEllipsoid::~cutEllipsoid(){
  std::cout<<"Elipsoid Destruida!";
}
void cutEllipsoid::draw(Sculptor &s){
  
 for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
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