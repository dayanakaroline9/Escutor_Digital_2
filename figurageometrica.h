#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief A Classe FiguraGeometrica serve para criar figuras usando o escultor de voxels.
*/

class FiguraGeometrica{
protected:
  /**
   * @brief A classe FiguraGeometrica define a cor da figura a ser desenhada.
   * @param r é o indice da cor vermelho
   * @param g é o indice da cor verde
   * @param b é o indice da cor azul
   * @param a é o indice de transparencia da figura
  */
  float r, g, b, a; // cor
public:
  // o destrutor virtual
  // forca que na alocacao dinamica
  // o destrutor da SUBCLASSE seja
  // chamado ao inves do da SUPERCLASSE
  virtual ~FiguraGeometrica();
  // classe abstrata porque tem
  // PELO MENOS um metodo
  // VIRTUAL PURO
  virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_H