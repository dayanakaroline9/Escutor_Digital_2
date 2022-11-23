#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

/**
  * @brief A classe Sculptor serve para esculpir voxels dentro de uma matriz de 3 dimensões.
  * @details A classe Sculptor define uma matriz 3D que poderá ser preenchida por voxels, cubos coloridos que podem ser organizados em formas geométricas.
  * @details Os voxels da matriz podem ser preenchidos com uma cor, que será definida no código de cores RGB (Red, Green, Blue) e também será informado o nível de transparência da cor selecionada.
*/

class Sculptor {
private:
  /**
    * @brief A classe Sculptor define uma Matriz do tipo Voxel usando ponteiro para struct.
    * @param v é um pronteiro para struct com 3 dimesões
    * @param nx é a dimensão da matriz no eixo X
    * @param ny é a dimensão da matriz no eixo Y
    * @param nz é a dimensão da matriz no eixo Z
    * @param r é o índice da cor vermelho
    * @param g é o índice da cor verde
    * @param b é o índice da cor azul
    * @param a é o índice de tranparência dos voxels
  */
  Voxel ***v;       // Matriz 3D
  int nx, ny, nz;   // Dimensões
  float r, g, b, a; // variaveis de cores
public:
  /**
    * @brief O contrutor da classe Sculptor faz a alocação dinâmica do ponteiro v.
    * @param _nx é dimensão em X da matriz (quantos voxels terá no eixo X)
    * @param _ny é dimensão em Y da matriz (quantos voxels terá no eixo Y)
    * @param _nz é dimensão em Z da matriz (quantos voxels terá no eixo Z)
  */
  Sculptor(int _nx, int _ny, int _nz);
  
  /**
    * @brief O descrutor libera memória que foi alocada para o ponteiro v.
  */
  ~Sculptor();

  /**
    * @brief A função setColor cadastra a sequência RGB e a tranparência dos voxels.
  */
  void setColor(float r, float g, float b, float a);

  /**
    * @brief A função putVoxel cadastra o estado de visibilidade do voxel e as coordenadas onde o voxel deve ser contruido.
    * @param x é posição X do voxel na matriz
    * @param y é posição Y do voxel na matriz
    * @param z é posição Z do voxel na matriz
  */
  void putVoxel(int x, int y, int z);

  /**
    * @brief A função cutVoxel deleta os voxel alterando o estado de visibilidade do voxel na posição (x,y,z).
  */
  void cutVoxel(int x, int y, int z);

   /**
    * @brief As funções getNx , getNy, getNz retornam as dimenções do Escultor
   */

  int getNx();
  int getNy();
  int getNz();

  /**
  * @brief A função writeOFF cria, escreve/altera, salva e fecha arquivo no formato OFF.
  * @details O formato de arquivo OFF possibilita vizualizar a forma geométrica em 3D através de softwares como o Mashlab.
  * @param filename é o nome.OFF do arquivo que deve ser criado ou alterado.
  * @details A função whiteOFF escreve ou atera no arquivo seguindo uma sequencia padrão dos arquivos.OFF.
  * @details OFF
  * @details NVertices  NFaces  NArestas
  * @details x[0]  y[0]  z[0]
  * @details ...
  * @details x[NVertices-1]  y[NVertices-1]  z[NVertices-1]
  * @details Nv v[0] v[1] ... v[Nv-1]  r g b a
  * @details Nv v[0] v[1] ... v[Nv-1]  r g b a
  * @details ...
  * @details Nv v[0] v[1] ... v[Nv-1]  r g b a

  * @details Na primeira linha escreve o tipo do arquivo.
  * @details Na segunda linha escreve a quantidade (tipo inteiro) de vétices, faces e arestas da forma geométrica.
  * @details A partir da terceira linha, escreve as coordenadas no plano 3D de cada vértice da figura.
  * @details Logo em seguinda, escreve nas próximas linhas a quantidade de vértices em cada face, as coordenadas dos vértices dessa face e a sequência de cor e transparência da face.
  * @details Cada cor é definida por 4 números em ponto flutuante, 3 referentes ao formato RGB e 1 referente à tranparência da cor.
  */
  
  void writeOFF(const char *filename);
};

#endif