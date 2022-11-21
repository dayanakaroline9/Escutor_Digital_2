#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class putEllipsoid : public FiguraGeometrica {
protected:
  int xcenter,ycenter, zcenter, rx, ry, rz; //POSIÇÃO
public:
  putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz);
  ~putEllipsoid();
  void draw(Sculptor &s);
  
};

#endif // PUTELLIPSOID_H