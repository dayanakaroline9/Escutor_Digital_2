#ifndef WHITEOFF_H
#define WHITEOFF_H

#include "figurageometrica.h"

class whiteOff : public FiguraGeometrica {
protected:
  const char *filename; //arquivo
public:
  whiteOff(const char *filename);
  ~whiteOff();
  void draw(Sculptor &s);
};

#endif // WHITEOFF_H