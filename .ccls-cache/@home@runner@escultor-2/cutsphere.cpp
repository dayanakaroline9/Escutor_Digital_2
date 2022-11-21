#include "cutsphere.h"
#include <iostream>
#include <cmath>

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
}
cutSphere::~cutSphere(){
  std::cout<<"Sphere destruida!";
}

void cutSphere:: draw(Sculptor &s){
   for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        // calcula equação da esfera
        float eq =
            (pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2));
        float r2 = pow(radius, 2); // raio ao quadrado

        // se resultado da equação for menor ou igual ao raio ao quadrado
        if (eq <= r2) {
          s.cutVoxel(i, j, k); // deleta voxels
        }
      }
    }
  }
}