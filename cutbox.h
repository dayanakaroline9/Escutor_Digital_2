#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

/**
  * @brief A classe cutBox serve para apagar uma caixa
*/

class cutBox : public FiguraGeometrica {
protected:
  /**
    * @brief A classe cutBox define a posição e cor da caixa a ser apagada
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
    * @brief O contrutor da classe cutBox faz a associação das dimensões e cor da caixa
  */
  cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /**
    * @brief O destrutor da classe cutBox informa quando a caixa foi destruida
  */
  ~cutBox();
  /**
    * @brief O método da draw classe cutBox é responsável por apagar a caixa
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
  
};

#endif // PUTBOX_H