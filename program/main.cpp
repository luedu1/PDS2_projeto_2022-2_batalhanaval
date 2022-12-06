#include <iostream>
#include <string>
#include "jogador.h"

std::string Linha = "|------------------------------------------------------------------------------------------------------------------------------------|";
std::string Boas_Vindas = "|                                           Olá, seja bem-vindo ao jogo de Batalha Naval!                                            |";
std::string Barra = "|                                                                                                                                    |";
std::string Anuncio_Regras = "              As regras do jogo são as seguintes: ";
std::string Regras = "1) Cada jogador irá dispor de até 14 casas para alocar seus barcos; \n\n2) O jogador poderá escolher entre 4 tipos diferentes de barco: \n * Submarino (1 posição); \n * Cruzador (3 posições); \n * Destroyer (4 posições); \n * Porta-avião (5 posições); \n\n3) Serão gerados na tela dois tabuleiros, um para visualizar os barcos e ataques sofridos e outro para visualizar os ataques realizados ao seu inimigo; \n\n4) Ao receber ataques certeiros, o usuário será notificado da saúde de seus barcos; \n\n5) O usuário será notificado se estiver realizando ataques repetidos, podendo refazê-los; \n\n6) O jogo acaba quando todos os barcos de um dos jogadores for totalmente destruído; \n\n";

int main() {

std::cout << '\n' << Linha << "\n" << Barra << "\n" << Barra << "\n" << Boas_Vindas << "\n" << Barra << "\n" << Barra << "\n" << Linha;
std::cout << "\n" << "\n" << Anuncio_Regras;
std::cout << "\n" << "\n" << Regras;

Jogador J1, J2;
std::cout << "|---------------------------------------------------Agora vamos iniciar o jogo!-------------------------------------------------------|";
std::cout << '\n' << '\n' << "Digite o nome dos jogadores participantes: " << '\n' << '\n' << "1)";
std::cin >> J1.nome;
std::cout << '\n'<< "2)";
std::cin >> J2.nome;

std::cout << '\n' << J1.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
int pos_restantes = 14;
  
std::cout << '\n' << '\n' << "Submarino(" << pos_restantes << " posições restantes): ";
int num_submarino;
std:: cin >> num_submarino;
pos_restantes = pos_restantes - num_submarino;

int pos_restantes_cruzador = (pos_restantes)/3;
  
if(pos_restantes_cruzador != 0){
std::cout << '\n' << "Cruzador(" << pos_restantes << " posições restantes ou até " << pos_restantes_cruzador << " unidades de Cruzador): ";
  
int num_cruzador;
  
std:: cin >> num_cruzador;
  
pos_restantes = pos_restantes - 3*num_cruzador;
  
}

else{
  std::cout << "Número insuficiente de casas para alocar Cruzadores" << '\n' << '\n';
}

int pos_restantes_destroyer = (pos_restantes)/4;

if(pos_restantes_destroyer != 0){
std::cout << '\n' << "Destroyer(" << pos_restantes << " posições restantes ou até " << pos_restantes_destroyer << " unidades de Destroyer): ";
  
int num_destroyer;
  
std:: cin >> num_destroyer;
  
pos_restantes = pos_restantes - 4*num_destroyer;
  
}

else{
  std::cout << "Número insuficiente de casas para alocar Destroyers" << '\n' << '\n';
}

int pos_restantes_p_avioes = (pos_restantes)/5;

if(pos_restantes_p_avioes != 0){
std::cout << '\n' << "Porta-aviões(" << pos_restantes << " posições restantes ou até " << pos_restantes_p_avioes << " unidades de Porta-avião): ";
  
int num_p_avioes;
  
std:: cin >> num_p_avioes;

pos_restantes = pos_restantes - 4*num_p_avioes;
  
}

else{
  std::cout << "Número insuficiente de casas para alocar Porta-aviões" << '\n' << '\n';
}


while(pos_restantes != 0){
  std::cout << "Ainda faltam " << pos_restantes << " posições a serem preenchidas. Deseja finalizar sua alocação (1) ou adicionar mais barcos (2)?";

  int escolha;

  std::cin >> escolha;

  switch(escolha){
    case '1':
    pos_restantes = 0;
    std::cout << '\n' << "Pronto, todas as suas posições foram alocadas!";
    break;

    case '2':
    std::cout << "TESTE";
    break;
  }
}
  return 0;
}
