#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

/**
  * @brief A classe cutEllipsoid serve para apagar a Elipse
*/

class cutEllipsoid : public FiguraGeometrica {
protected:
  /**
    * @brief A classe cutEllipsoid define a posição e cor do da elipse a ser apagada
    * @param xcenter é a posição x da elipse
    * @param ycenter é a posição y da elipse
    * @param zcenter é a posição z da elipse
    * @param rx é o raio das elipse no eixo x
    * @param ry é o raio das elipse no eixo y
    * @param rz é o raio das elipse no eixo z
  */
  int xcenter,ycenter, zcenter, rx, ry, rz; //POSIÇÃO
public:
  /**
    * @brief O contrutor da classe cutEllipsoid faz a associação das dimensões e cor da elipse
  */
  cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz);
  /**
    * @brief O destrutor da classe cutEllpsoid informa quando a elipse foi destruida
  */
  ~cutEllipsoid();
  /**
    * @brief O método da draw classe cutEllipsoid é responsável por apagar a elipse
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
  
};

#endif // CUTELLIPSOID_H