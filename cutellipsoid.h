#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class cutEllipsoid : public FiguraGeometrica {
protected:
  int xcenter,ycenter, zcenter, rx, ry, rz; //POSIÇÃO
public:
  cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz);
  ~cutEllipsoid();
  void draw(Sculptor &s);
  
};

#endif // CUTELLIPSOID_H