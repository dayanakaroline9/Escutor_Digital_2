#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

/**
  * @brief A classe putSphere serve para esculpir a esfera
*/

class putSphere : public FiguraGeometrica {
protected:
  /**
    * @brief A classe putSphere define a posição e cor do da esfera a ser desenhada
    * @param xcenter é a posição x da esfera
    * @param ycenter é a posição y da esfera
    * @param zcenter é a posição z da esfera
    * @param radius é o raio das esfera
  */
  int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
  /**
    * @brief O contrutor da classe putSphere faz a associação das dimensões e cor da esfera
  */
  putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
  /**
    * @brief O destrutor da classe putSphere informa quando a esfera foi destruida
  */
  ~putSphere();
  /**
    * @brief O método da draw classe putSphere é responsável por desenhar a esfera
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
  
};

#endif // PUTBOX_H