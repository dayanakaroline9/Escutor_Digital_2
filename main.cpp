#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//usando arquivos

#include "cutbox.h"
#include "cutellipsoid.h"
#include "cutsphere.h"
#include "cutvoxel.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "putellipsoid.h"
#include "putsphere.h"
#include "putvoxel.h"
#include "sculptor.h"
#include "voxel.h"

// teste da classe Sculptor, construindo um foguete

int main() {
  // define um ponteiro do tipo sculptor
  Sculptor *f;

  //cria um vetor de figuras
  std::vector<FiguraGeometrica *> figs;
  std::vector<FiguraGeometrica *>::iterator itf;

  //começando a leitura do arquivo
  std::ifstream fin;

  fin.open("foguete.txt"); //abre arquivo

  //verifica se arquivo não abriu e mostra mensagem
  if (!fin.is_open()) {
    std::cout << "nao abriu arquivo figura\n";
    exit(EXIT_FAILURE);
  }

  //cria uma string para receber a leitura do arquivo
  std::string s;
  
  float r, g, b, a; //cor
  int nx, ny, nz; //dimensão

  //quando houver informações a serem lidas
  while (fin.good()) {

    // processa primeira linha
    fin >> s; //ler primeira palavra
    if (!fin.good())
      break;
    std::cout << "leu " << s << std::endl;

    //verifica palavras para ler dados corretamente

    if (s.compare("dim") == 0) {

      fin >> nx >> ny >> nz; // ler as dimensões
    }

    //ler desenha voxel
    if (s.compare("putvoxel") == 0) {
      int x, y, z;
      float r, g, b, a;
      fin >> x >> y >> z;
      fin >> r >> g >> b >> a;

      figs.push_back(new putVoxel(x, y, z, r, g, b, a));
    }

    //ler corta voxel
    if (s.compare("cutvoxel") == 0) {
      int x, y, z;
      fin >> x >> y >> z;

      figs.push_back(new cutVoxel(x, y, z));
    }

    //ler desenha caixa
    if (s.compare("putbox") == 0) {
      int x0, x1, y0, y1, z0, z1;
      float r, g, b, a;
      fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
      fin >> r >> g >> b >> a;

      figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
    }

    //ler corta caixa
    if (s.compare("cutbox") == 0) {
      int x0, x1, y0, y1, z0, z1;
      fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;

      figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));
    }

    //ler desenha esfera
    if (s.compare("putsphere") == 0) {
      int xcenter, ycenter, zcenter, radius;
      float r, g, b, a;
      fin >> xcenter >> ycenter >> zcenter >> radius;
      fin >> r >> g >> b >> a;

      figs.push_back(
          new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
    }

    //ler corta esfera
    if (s.compare("cutsphere") == 0) {
      int xcenter, ycenter, zcenter, radius;
      fin >> xcenter >> ycenter >> zcenter >> radius;

      figs.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
    }

    //ler corta elipse
    if (s.compare("putellipsoid") == 0) {
      int xcenter, ycenter, zcenter, rx, ry, rz;
      float r, g, b, a;
      fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
      fin >> r >> g >> b >> a;

      figs.push_back(
          new putEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
    }

    //ler corta elipse
    if (s.compare("cutellipsoid") == 0) {
      int xcenter, ycenter, zcenter, rx, ry, rz;
      fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;

      figs.push_back(new cutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
    }
  }

  //cria um sculptor 
  f = new Sculptor(nx, ny, nz);

  //armazena figuras 
  for (size_t i = 0; i < figs.size(); i++) {
    figs[i]->draw(*f);
  }
  
  //registra formas geometricas no arquivo OFF
  f->writeOFF("testando.off");

  //liberando memoria alocada
  for (size_t i = 0; i < figs.size(); i++) {
    delete figs[i];
  }

  return 0;
}