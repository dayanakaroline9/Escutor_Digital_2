#include "putsphere.h"
#include <iostream>
#include <cmath>

//associando as variaveis da classe 
putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius,float r, float g, float b, float a){
  this->xcenter=xcenter;
  this->ycenter=ycenter;
  this->zcenter=zcenter;
  this->radius=radius;
  this->r=r; this->g=g; this->b=b; this->a=a;
}

//informando que a figura foi destruida
putSphere::~putSphere(){
  std::cout<<"Sphere destruida!";
}

//desenhando a figura
void putSphere:: draw(Sculptor &s){

  //seleciona a cor
  s.setColor(r,g,b,a);

  for (int i = 0; i < s.getNx(); i++) {
    for (int j = 0; j < s.getNx(); j++) {
      for (int k = 0; k < s.getNz(); k++) {
        // calcula equação da esfera
        float eq =
            (pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2));
        float r2 = pow(radius, 2); // raio ao quadrado

        // se resultado da equação for menor ou igual ao raio ao quadrado
        if (eq <= r2) {
          s.putVoxel(i, j, k); // add voxels
        }
      }
    }
  }
}


