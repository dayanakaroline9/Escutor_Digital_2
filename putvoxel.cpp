#include "putvoxel.h"
#include <iostream>

//associando as variaveis
putVoxel::putVoxel(int x, int y, int z,float r, float g, float b, float a){
  this->x=x; this->y=y; this->z=z;
  this->r=r; this->g=g; this->b=b; this->a=a;
}
//informando que o voxel foi destruido
putVoxel::~putVoxel(){
  std::cout<<"Voxel destruido!";
}
//desenhando voxel
void putVoxel::draw(Sculptor &s){
  s.putVoxel(x,y,z); //cria voxel 
}