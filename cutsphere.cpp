#include "cutsphere.h"
#include <iostream>
#include <cmath>

//associando as variaveis da classe
cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
}
//informando quando a figura foi destruida
cutSphere::~cutSphere(){
  std::cout<<"Sphere destruida!";
}
//apagando a figura
void cutSphere:: draw(Sculptor &s){
   for (int i = 0; i < s.getNx(); i++) {
    for (int j = 0; j < s.getNy(); j++) {
      for (int k = 0; k < s.getNz(); k++) {
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