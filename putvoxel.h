#ifndef PUTVOXEL_H
#define PUTVOXEL_HPUTBOX_H

#include "figurageometrica.h"

/**
  * @brief A classe putVoxel serve para esculpir o voxel da figura
*/

class putVoxel : public FiguraGeometrica {
protected:
 /**
    * @brief A classe putVoxel define a posição e cor do voxel a ser desenhado
    * @param x é a posição x do voxel
    * @param y é a posição y do voxel
    * @param z é a posição z do voxel
  */
  int x, y, z; // POSIÇÃO
public:
  /**
    * @brief O contrutor da classe putVoxel faz a associação das dimensões e cor do voxel
  */
  putVoxel(int x, int y, int z, float r, float g, float b, float a);
  /**
    * @brief O destrutor da classe putVoxel informa quando a figura foi destruida
  */
  ~putVoxel();
  /**
    * @brief O método da draw classe putVoxel é responsável por desenhar o voxel
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
};

#endif // PUTBOX_H