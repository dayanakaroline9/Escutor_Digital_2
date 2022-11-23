#include "cutvoxel.h"
#include <iostream>

//associando as variaveis da classe
cutVoxel::cutVoxel(int x, int y, int z){
  this->x=x; this->y=y; this->z=z;
}
//informando que a figura foi destruida
cutVoxel::~cutVoxel(){
  std::cout<<"Voxel destruido!";
}
//apagando figura
void cutVoxel::draw(Sculptor &s){
  s.cutVoxel(x,y,z);
}