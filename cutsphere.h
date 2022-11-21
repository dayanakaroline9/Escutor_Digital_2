#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class cutSphere : public FiguraGeometrica {
protected:
  int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
  cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  ~cutSphere();
  void draw(Sculptor &s);
  
};

#endif //CUTBOX_H