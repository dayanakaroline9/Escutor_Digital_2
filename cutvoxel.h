#ifndef CUTVOXEL_H
#define CUTVOXEL_HPUTBOX_H

#include "figurageometrica.h"

/**
  * @brief A classe cutVoxel serve para apagar um voxel da figura
*/

class cutVoxel : public FiguraGeometrica {
protected:
 /**
    * @brief A classe cutVoxel define a posição e cor do voxel a ser apagado
    * @param x é a posição x do voxel
    * @param y é a posição y do voxel
    * @param z é a posição z do voxel
  */
  int x,y,z; //POSIÇÃO
public:
  /**
    * @brief O contrutor da classe cutVoxel faz a associação das dimensões e cor do voxel
  */
  cutVoxel(int x, int y, int z);
  /**
    * @brief O destrutor da classe cutVoxel informa quando a figura foi destruida
  */
  ~cutVoxel();
  /**
    * @brief O método da draw classe cutVoxel é responsável por deletar o voxel da figura
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
};

#endif // CUTBOX_H