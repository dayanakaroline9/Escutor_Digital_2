#ifndef VOXEL_H
#define VOXEL_H

//Estrutura Voxel
//um voxel é contruido pela cor em RGB, a tranparencia e um estado de visibilidade

struct Voxel {
  float r,g,b; // Colors
  float a; // Transparency
  bool isOn; // Included or not
};

#endif // VOXEL_H