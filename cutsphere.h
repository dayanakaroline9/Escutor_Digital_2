#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
/**
  * @brief A classe cutSphere serve para apagar uma esfera na figura
*/

class cutSphere : public FiguraGeometrica {
protected:
   /**
    * @brief A classe cutSphere define a posição e cor do da esfera a ser apagada
    * @param xcenter é a posição x da esfera
    * @param ycenter é a posição y da esfera
    * @param zcenter é a posição z da esfera
    * @param radius é o raio das esfera
  */
  int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
  /**
    * @brief O contrutor da classe cutSphere faz a associação das dimensões e cor da esfera
  */
  cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /**
    * @brief O destrutor da classe cutSphere informa quando a esfera foi destruida
  */
  ~cutSphere();
  /**
    * @brief O método da draw classe cutSphere é responsável por apagar a esfera
    * @details O método draw recebe um ponteiro do tipo escultor
  */
  void draw(Sculptor &s);
  
};

#endif //CUTBOX_H