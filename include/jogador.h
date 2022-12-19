#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>

class Jogador{
  public:
  std::string nome;
  int num_barcos;
  //std::string Nome;
  char tabuleiro_ataque[12][24];
  char tabuleiro_defesa[12][24];

  void get_nome();

};


#endif
