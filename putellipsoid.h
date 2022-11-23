#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

/**
  * @brief A classe putEllipsoid serve para esculpir a Elipse
*/

class putEllipsoid : public FiguraGeometrica {
protected:
  /**
    * @brief A classe putSphere define a posição e cor do da esfera a ser desenhada
    * @param xcenter é a posição x da esfera
    * @param ycenter é a posição y da esfera
    * @param zcenter é a posição z da esfera
    * @param rx é o raio das esfera no eixo x
    * @param ry é o raio das esfera no eixo y
    * @param rz é o raio das esfera no eixo z
  */

  int xcenter,ycenter, zcenter, rx, ry, rz; //POSIÇÃO
public:
  /**
    * @brief O contrutor da classe putEllipsoid faz a associação das dimensões e cor da elipse
  */
  putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz,float r, float g, float b, float a);
  /**
    * @brief O destrutor da classe putEllpsoid informa quando a elipse foi destruida
  */
  ~putEllipsoid();
  /**
    * @brief O método da draw classe putEllipsoid é responsável por desenhar a elipse
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
  
};

#endif // PUTELLIPSOID_H