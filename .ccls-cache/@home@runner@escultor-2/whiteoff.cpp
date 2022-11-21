#include "whiteoff.h"
#include <iostream>
#include <fstream>
#include <iomanip>

whiteOff::whiteOff(const char *filename){
  
}
whiteOff::~whiteOff(){
  
}
void whiteOff:: draw(Sculptor &s){
  
  // criando fluxo de arquivo
  std::ofstream fout;

  int vt = 0;
  int f = 0;
  int tmp = 0;

  // abrindo arquivo
  fout.open(filename);

  fout << "OFF" << std::endl; // escreve o tipo do arquivo

  // definindo dimensões
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn == true) {
          vt = vt + 8; // oito vertices
          f = f + 6;   // seis faces
        }
      }
    }
  }

  // escrevendo as dimensões
  // NVertices       NFaces          NArestas
  fout << vt << " " << f << " " << 0 << std::endl;

  // fixando as cores em 2 casas decimais para forçar aparecer em ponto
  // flutuante
  fout << std::fixed;
  fout << std::setprecision(2);

  // loop que percorre a matriz 3D
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        // se o voxel estiver ativo
        if (v[i][j][k].isOn == true) {

          // Escreve as coordenadas espaciais tridimensionais dos NVertices
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].isOn == true) {
          // escreve especificações das faces
          //      Nv          v[0]            v[1]                    ...
          //      v[Nv-1]            r g b a
          fout << 4 << " " << tmp + 0 << " " << tmp + 3 << " " << tmp + 2 << " "
               << tmp + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          fout << 4 << " " << tmp + 4 << " " << tmp + 5 << " " << tmp + 6 << " "
               << tmp + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          fout << 4 << " " << tmp + 0 << " " << tmp + 1 << " " << tmp + 5 << " "
               << tmp + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          fout << 4 << " " << tmp + 0 << " " << tmp + 4 << " " << tmp + 7 << " "
               << tmp + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          fout << 4 << " " << tmp + 3 << " " << tmp + 7 << " " << tmp + 6 << " "
               << tmp + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          fout << 4 << " " << tmp + 1 << " " << tmp + 2 << " " << tmp + 6 << " "
               << tmp + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " "
               << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
          tmp += 8;
        }
      }
    }
  }

  // fecha arquivo
  fout.close();

  std::cout << ".off salvo com sucesso" << std::endl;
}