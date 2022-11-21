#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

class Sculptor {
private:
  Voxel ***v;       // Matriz 3D
  int nx, ny, nz;   // Dimensões
  float r, g, b, a; // variaveis de cores
public:


  Sculptor(int _nx, int _ny, int _nz);
  
  ~Sculptor();

  void setColor(float r, float g, float b, float a);

  void putVoxel(int x, int y, int z);
  
  void cutVoxel(int x, int y, int z);
  
  void writeOFF(const char *filename);
};

#endif