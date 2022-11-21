#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

class putBox : public FiguraGeometrica {
protected:
  int x0, x1,  y0, y1, z0, z1; //POSIÇÃO
public:
  putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ~putBox();
  void draw(Sculptor &s);
};

#endif // PUTBOX_H