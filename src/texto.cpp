#include "texto.hpp"


void boas_vindas(){

  std::string linha = "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";

std::string barra = "|                                                                                                                                                                                  |";
  
  std::string Boas_Vindas = "|                                                                   Olá, seja bem-vindo ao jogo de Batalha Naval!                                                                  |";

  std::string Anuncio_Regras = "                                                                       As regras do jogo são as seguintes: ";
  std::string Regras = "1) Cada jogador irá dispor de até 14 casas para alocar seus barcos; \n\n2) O jogador poderá escolher entre 4 tipos diferentes de barco: \n * Submarino (1 posição); \n * Cruzador (3 posições); \n * Destroyer (4 posições); \n * Porta-avião (5 posições); \n\n3) Serão gerados na tela dois tabuleiros, um para visualizar os barcos e ataques sofridos e outro para visualizar os ataques realizados ao seu inimigo; \n\n4) Ao receber ataques certeiros, o usuário será notificado da saúde de seus barcos; \n\n5) O usuário será notificado se estiver realizando ataques repetidos, podendo refazê-los; \n\n6) O jogo acaba quando todos os barcos de um dos jogadores for totalmente destruído; \n\n";

  std::string Inicio_Jogo = "|--------------------------------------------------------------------------Agora vamos iniciar o jogo!-----------------------------------------------------------------------------|";

  
std::cout << '\n' << linha << "\n" << barra << "\n" << barra << "\n" << Boas_Vindas << "\n" << barra << "\n" << barra << "\n" << linha;
std::cout << "\n" << "\n" << Anuncio_Regras;
std::cout << "\n" << "\n" << Regras;

std::cout << Inicio_Jogo;

};

void setar_linha_barra(std::string& S1, std::string& S2){
  std::string x = "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";

  S1 = x;

std::string y = "|                                                                                                                                                                                  |";
  S2 = y;
};

void fim_do_jogo(){
  std::cout << '\n' << '\n' << "|-------------------------------------------------------------FIM DO JOGO!-----------------------------------------------------------------|";
  
};
