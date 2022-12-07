#include <iostream>
#include <string>
#include "jogador.h"

std::string Linha = "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";
std::string Boas_Vindas = "|                                                                   Olá, seja bem-vindo ao jogo de Batalha Naval!                                                                  |";
std::string Barra = "|                                                                                                                                                                                  |";
std::string Anuncio_Regras = "              As regras do jogo são as seguintes: ";
std::string Regras = "1) Cada jogador irá dispor de até 14 casas para alocar seus barcos; \n\n2) O jogador poderá escolher entre 4 tipos diferentes de barco: \n * Submarino (1 posição); \n * Cruzador (3 posições); \n * Destroyer (4 posições); \n * Porta-avião (5 posições); \n\n3) Serão gerados na tela dois tabuleiros, um para visualizar os barcos e ataques sofridos e outro para visualizar os ataques realizados ao seu inimigo; \n\n4) Ao receber ataques certeiros, o usuário será notificado da saúde de seus barcos; \n\n5) O usuário será notificado se estiver realizando ataques repetidos, podendo refazê-los; \n\n6) O jogo acaba quando todos os barcos de um dos jogadores for totalmente destruído; \n\n";

std::string Inicio_Jogo = "|--------------------------------------------------------------------------Agora vamos iniciar o jogo!-----------------------------------------------------------------------------|";

int main() {

std::cout << '\n' << Linha << "\n" << Barra << "\n" << Barra << "\n" << Boas_Vindas << "\n" << Barra << "\n" << Barra << "\n" << Linha;
std::cout << "\n" << "\n" << Anuncio_Regras;
std::cout << "\n" << "\n" << Regras;

std::cout << Inicio_Jogo;

Jogador J1, J2;
std::cout << '\n' << '\n' << "Digite o nome dos jogadores participantes: " << '\n' << '\n' << "1)";
std::cin >> J1.nome;
std::cout << '\n'<< "2)";
std::cin >> J2.nome;

//---------------------------------------------------------------------------------------------------------------//
int num_submarino;
int num_cruzador;
int num_destroyer;
int num_p_avioes;

//----------------------------------------------------------------------------------//
std::cout << '\n' << Linha << '\n' ;
std::cout << '\n' << J1.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
int pos_restantes = 14;
  
std::cout << '\n' << '\n' << "Submarino(" << pos_restantes << " posições restantes): ";

std:: cin >> num_submarino;
pos_restantes = pos_restantes - num_submarino;

int pos_restantes_cruzador = (pos_restantes)/3;
  
if(pos_restantes_cruzador != 0){
std::cout << '\n' << "Cruzador(" << pos_restantes << " posições restantes ou até " << pos_restantes_cruzador << " unidades de Cruzador): ";
  

  
std:: cin >> num_cruzador;
  
pos_restantes = pos_restantes - 3*num_cruzador;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Cruzadores" << '\n';
}

int pos_restantes_destroyer = (pos_restantes)/4;

if(pos_restantes_destroyer != 0){
std::cout << '\n' << "Destroyer(" << pos_restantes << " posições restantes ou até " << pos_restantes_destroyer << " unidades de Destroyer): ";
  

  
std:: cin >> num_destroyer;
  
pos_restantes = pos_restantes - 4*num_destroyer;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Destroyers" << '\n';
}

int pos_restantes_p_avioes = (pos_restantes)/5;

if(pos_restantes_p_avioes != 0){
std::cout << '\n' << "Porta-aviões(" << pos_restantes << " posições restantes ou até " << pos_restantes_p_avioes << " unidades de Porta-avião): ";
  
  
std:: cin >> num_p_avioes;

pos_restantes = pos_restantes - 4*num_p_avioes;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Porta-aviões" << '\n';
}

//------------------------------------------------------------------------------------------------------------------------------------------//
  
while(pos_restantes != 0){
  std::cout << '\n'<< Linha << '\n';
  std::cout << '\n' << "Ainda faltam " << pos_restantes << " posição(ões) a serem preenchidas. Deseja finalizar sua alocação (1) ou adicionar mais barcos (2)?" << '\n' << '\n';

  int escolha;

  std::cin >> escolha;

  switch(escolha){
    case 1:
    pos_restantes = 0;
    std::cout << '\n'<< Linha << '\n' << "Pronto, todas as suas posições foram alocadas!";
    break;

    case 2:
    std::cout << '\n' << "Qual tipo de barco deseja alocar?" << '\n' << '\n' << "Ainda lhe restam: " << '\n' << '\n';

    std::cout << "*Submarinos: " << pos_restantes << '\n' << '\n';

    if(pos_restantes/3 != 0){
       std::cout << "*Cruzadores: " << (pos_restantes/3) << '\n' << '\n';
    }

    if(pos_restantes/4 != 0){
       std::cout << "*Destroyers: " << (pos_restantes/4) << '\n' << '\n';
    }

    if(pos_restantes/5 != 0){
       std::cout << "*Porta-aviões: " << (pos_restantes/5) << '\n' << '\n';
    }

    std::cout << "Quer alocar quantos Submarinos? " << '\n' << '\n';

    int add_sub;
    std::cin >> add_sub;

    pos_restantes -= add_sub;
    num_submarino += add_sub;

    if(pos_restantes/3 != 0){
       std::cout << '\n' << "Quer alocar quantos Cruzadores? " << '\n' << '\n';

    int add_cru;
    std::cin >> add_cru;

    pos_restantes -= 3*add_cru;
    num_cruzador += add_cru;
    }

    if(pos_restantes/4 != 0){
       std::cout << '\n' << "Quer alocar quantos Destroyers? " << '\n' << '\n';

    int add_des;
    std::cin >> add_des;

    pos_restantes -= 4*add_des;
    num_destroyer += add_des;
    }

    if(pos_restantes/5 != 0){
       std::cout << '\n' << "Quer alocar quantos Porta-aviões? "<< '\n' << '\n';

    int add_pta;
    std::cin >> add_pta;

    pos_restantes -= 5*add_pta;
    num_p_avioes += add_pta;
    }

    if(pos_restantes == 0){
      std::cout << '\n'<< Linha << '\n' << '\n' << "Pronto, todas as suas posições foram alocadas!" << '\n';
    }

    break;
    }
  }

  //------------------------------------------------------------------------------------------------------------------------//
int num_submarino2;
int num_cruzador2;
int num_destroyer2;
int num_p_avioes2;
//---------------------------------------------------------------------------------//

std::cout << '\n' << Linha << '\n' ;
std::cout << '\n' << J2.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
int pos_restantes2 = 14;
  
std::cout << '\n' << '\n' << "Submarino(" << pos_restantes2 << " posições restantes): ";

std:: cin >> num_submarino2;
pos_restantes2 = pos_restantes2 - num_submarino2;

int pos_restantes_cruzador2 = (pos_restantes2)/3;
  
if(pos_restantes_cruzador2 != 0){
std::cout << '\n' << "Cruzador(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_cruzador2 << " unidades de Cruzador): ";
  

  
std:: cin >> num_cruzador2;
  
pos_restantes2 = pos_restantes2 - 3*num_cruzador2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Cruzadores" << '\n';
}

int pos_restantes_destroyer2 = (pos_restantes2)/4;

if(pos_restantes_destroyer2 != 0){
std::cout << '\n' << "Destroyer(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_destroyer2 << " unidades de Destroyer): ";
  

  
std:: cin >> num_destroyer2;
  
pos_restantes2 = pos_restantes2 - 4*num_destroyer2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Destroyers" << '\n';
}

int pos_restantes_p_avioes2 = (pos_restantes2)/5;

if(pos_restantes_p_avioes2 != 0){
std::cout << '\n' << "Porta-aviões(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_p_avioes2 << " unidades de Porta-avião): ";
  

  
std:: cin >> num_p_avioes2;

pos_restantes2 = pos_restantes2 - 4*num_p_avioes2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Porta-aviões" << '\n';
}

//------------------------------------------------------------------------------------------------------------------------------------------//
  
while(pos_restantes2 != 0){
  std::cout << '\n'<< Linha << '\n';
  std::cout << '\n' << "Ainda faltam " << pos_restantes2 << " posição(ões) a serem preenchidas. Deseja finalizar sua alocação (1) ou adicionar mais barcos (2)?" << '\n' << '\n';

  int escolha2;

  std::cin >> escolha2;

  switch(escolha2){
    case 1:
    pos_restantes2 = 0;
    std::cout << '\n'<< Linha << '\n' << '\n' << "Pronto, todas as suas posições foram alocadas!" << '\n';
    break;

    case 2:
    std::cout << '\n' << "Qual tipo de barco deseja alocar?" << '\n' << '\n' << "Ainda lhe restam: " << '\n' << '\n';

    std::cout << "*Submarinos: " << pos_restantes2 << '\n' << '\n';

    if(pos_restantes2/3 != 0){
       std::cout << "*Cruzadores: " << (pos_restantes2/3) << '\n' << '\n';
    }

    if(pos_restantes2/4 != 0){
       std::cout << "*Destroyers: " << (pos_restantes2/4) << '\n' << '\n';
    }

    if(pos_restantes2/5 != 0){
       std::cout << "*Porta-aviões: " << (pos_restantes2/5) << '\n' << '\n';
    }

    std::cout << "Quer alocar quantos Submarinos? " << '\n' << '\n';

    int add_sub2;
    std::cin >> add_sub2;

    pos_restantes2 -= add_sub2;
    num_submarino2 += add_sub2;

    if(pos_restantes2/3 != 0){
       std::cout << '\n' << "Quer alocar quantos Cruzadores? " << '\n' << '\n';

    int add_cru2;
    std::cin >> add_cru2;

    pos_restantes2 -= 3*add_cru2;
    num_cruzador2 += add_cru2;
    }

    if(pos_restantes2/4 != 0){
       std::cout << '\n' << "Quer alocar quantos Destroyers? " << '\n' << '\n';

    int add_des2;
    std::cin >> add_des2;

    pos_restantes2 -= 4*add_des2;
    num_destroyer2 += add_des2;
    }

    if(pos_restantes2/5 != 0){
       std::cout << '\n' << "Quer alocar quantos Porta-aviões? "<< '\n' << '\n';

    int add_pta2;
    std::cin >> add_pta2;

    pos_restantes2 -= 5*add_pta2;
    num_p_avioes2 += add_pta2;
    }

    if(pos_restantes2 == 0){
      std::cout << '\n'<< Linha << '\n' <<'\n' << "Pronto, todas as suas posições foram alocadas!" << '\n' << Linha << '\n';
    }

    break;
    }
  }
//---------------------------------------------------------------------------------------------------------//

  std::cout << '\n' << "Vamos dar início a alocação das peças no tabuleiro!" << '\n' << '\n';

  std::cout << J1.nome << ", esse é o seu tabuleiro atual: " << '\n' << '\n';

  std::cout << "|---------------------------|" << '\n';

  for(int i = 0; i < 9; i++){
    std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << '\n';
  }
  
  std::cout << "|---------------------------|" << '\n';

  std::cout << '\n' << "Onde você quer colocar seus barcos?";
  
  return 0;
}
