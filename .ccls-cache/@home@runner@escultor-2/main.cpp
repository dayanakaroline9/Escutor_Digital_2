#include <fstream>
#include <iostream>

#include "sculptor.h"
#include "figurageometrica.h"
#include "voxel.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>

// teste da classe Sculptor, construindo um foguete

int main() {
  // cria um escultor cuja matriz tem 50x50x50 voxels
  Sculptor t(100, 100, 100);

  std::vector<FiguraGeometrica*> figs;
  std::vector<FiguraGeometrica*>::iterator itf;

  std::ifstream fin;

  fin.open("figura.txt");

  if(!fin.is_open()){
    std::cout << "nao abriu arquivo figura\n";
    exit(EXIT_FAILURE);
  }

  std::string s;
  float r, g, b;
  while(fin.good()){
    // processa a linha
    fin >> s;
    if(!fin.good())
      break;
    std::cout << "leu " << s << std::endl;
    if(s.compare("reta")==0){
      int x0, x1,  y0, y1, z0, z1;
      fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
      fin >> r >> g >> b;
      figs.push_back(new putBox(x0,y0,z0,x1,y1,z1));
    }
    if(s.compare("retangulo")==0){
      int x0, y0, x1, y1;
      fin >> x0 >> y0 >> x1 >> y1;
      fin >> r >> g >> b;
      figs.push_back(new Retangulo(x0,y0,x1,y1,r,g,b));
    }
    if(s.compare("circulo")==0){
      int x0, y0, raio;
      fin >> x0 >> y0 >> raio;
      fin >> r >> g >> b;
      figs.push_back(new Circulo(x0,y0,raio,r,g,b));
    }
  }


/*  figs.push_back(new Reta(0,0,3,3,1,1,1));
  figs.push_back(new Retangulo);
  figs.push_back(new Circulo);
  figs.push_back(new Reta(1,2,3,4,1,0,1));
  figs.push_back(new Circulo);
*/

  for(auto it: figs){
    it->draw();
  }

  for(itf = figs.begin(); itf!=figs.end(); itf++){
    delete *itf;
  }


  
  return 0;
}