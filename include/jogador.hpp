#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include <iostream>


class Jogador{

  public:

  std::string nome;
  int num_barcos = 0;
  int num_submarino = 0;
  int num_cruzador = 0;
  int num_destroyer = 0;
  int num_p_avioes = 0;
  int pos_restantes = 14;
  char tabuleiro_ataque[12][24];
  char tabuleiro_defesa[12][24];

private:

};

void montar_tabuleiro(Jogador &J1_);
void alocar_barcos(Jogador &J1_);
void posicionar_barcos(Jogador &J1_);
void jogadas(Jogador &J1_, Jogador &J2_);

#endif
