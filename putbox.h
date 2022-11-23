#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"


/**
  * @brief A classe putBox serve para esculpir uma caixa
*/


class putBox : public FiguraGeometrica {
protected:
  /**
    * @brief A classe putBox define a posição e cor da caixa a ser desenhado
    * @param x0 é a posição x0 da caixa
    * @param y0 é a posição y0 da caixa
    * @param z0 é a posição z0 da caixa
    * @param x1 é a posição x1 da caixa
    * @param y1 é a posição y1 da caixa
    * @param z1 é a posição z1 da caixa
  */
  int x0, x1,  y0, y1, z0, z1; //POSIÇÃO
public:

  /**
    * @brief O contrutor da classe putBox faz a associação das dimensões e cor da caixa
  */
  putBox(int x0, int x1, int y0, int y1, int z0, int z1,float r, float g, float b, float a);
  /**
    * @brief O destrutor da classe putBox informa quando a caixa foi destruida
  */
  ~putBox();
  /**
    * @brief O método da draw classe putBox é responsável por desenhar a caixa
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
};

#endif // PUTBOX_H