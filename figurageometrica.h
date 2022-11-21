#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica{
protected:
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