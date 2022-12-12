#include <iostream>
#include <string>
#include "jogador.h"

std::string Linha = "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";
std::string Boas_Vindas = "|                                                                   Olá, seja bem-vindo ao jogo de Batalha Naval!                                                                  |";
std::string Barra = "|                                                                                                                                                                                  |";
std::string Anuncio_Regras = "                                                                       As regras do jogo são as seguintes: ";
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
int num_submarino = 0;
int num_cruzador = 0;
int num_destroyer = 0;
int num_p_avioes = 0;

//-------------------------------------------------------------------------------------------------------------//
std::cout << '\n' << Linha << '\n' ;
std::cout << '\n' << J1.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
int pos_restantes = 14;
  
std::cout << '\n' << '\n' << "Submarino(" << pos_restantes << " posições restantes): ";

std:: cin >> num_submarino;
  
  while(num_submarino < 0 || num_submarino > 14){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_submarino;
  }
  
pos_restantes = pos_restantes - num_submarino;

int pos_restantes_cruzador = (pos_restantes)/3;
  
if(pos_restantes_cruzador != 0){
std::cout << '\n' << "Cruzador(" << pos_restantes << " posições restantes ou até " << pos_restantes_cruzador << " unidades de Cruzador): ";
  
std:: cin >> num_cruzador;

  while(num_cruzador < 0 || num_cruzador > pos_restantes_cruzador){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_cruzador;
  }
  
pos_restantes = pos_restantes - 3*num_cruzador;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Cruzadores" << '\n';
}

int pos_restantes_destroyer = (pos_restantes)/4;

if(pos_restantes_destroyer != 0){
std::cout << '\n' << "Destroyer(" << pos_restantes << " posições restantes ou até " << pos_restantes_destroyer << " unidades de Destroyer): ";
  

  
std:: cin >> num_destroyer;

  while(num_destroyer < 0 || num_destroyer > pos_restantes_destroyer){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_destroyer;
  }
  
pos_restantes = pos_restantes - 4*num_destroyer;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Destroyers" << '\n';
}

int pos_restantes_p_avioes = (pos_restantes)/5;

if(pos_restantes_p_avioes != 0){
std::cout << '\n' << "Porta-aviões(" << pos_restantes << " posições restantes ou até " << pos_restantes_p_avioes << " unidades de Porta-avião): ";
  
  
std:: cin >> num_p_avioes;

  while(num_p_avioes < 0 || num_p_avioes > pos_restantes_p_avioes){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_p_avioes;
  }

pos_restantes = pos_restantes - 5*num_p_avioes;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Porta-aviões" << '\n';
}

  if(pos_restantes == 0){
    std::cout << '\n'<< Linha << '\n' << "Pronto, todas as suas posições foram alocadas!";
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

      while(add_sub < 0 || add_sub > pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_sub;
      }

    pos_restantes -= add_sub;
    num_submarino += add_sub;

    if(pos_restantes/3 != 0){
       std::cout << '\n' << "Quer alocar quantos Cruzadores? " << '\n' << '\n';

    int add_cru;
    std::cin >> add_cru;

      while(add_cru < 0 || add_cru > pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_cru;
      }

    pos_restantes -= 3*add_cru;
    num_cruzador += add_cru;
    }

    if(pos_restantes/4 != 0){
       std::cout << '\n' << "Quer alocar quantos Destroyers? " << '\n' << '\n';

    int add_des;
    std::cin >> add_des;

      while(add_des < 0 || add_des > pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_des;
      }

    pos_restantes -= 4*add_des;
    num_destroyer += add_des;
    }

    if(pos_restantes/5 != 0){
       std::cout << '\n' << "Quer alocar quantos Porta-aviões? "<< '\n' << '\n';

    int add_pta;
    std::cin >> add_pta;

      while(add_pta < 0 || add_pta > pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_pta;
      }

    pos_restantes -= 5*add_pta;
    num_p_avioes += add_pta;
    }

    if(pos_restantes == 0){
      std::cout << '\n'<< Linha << '\n' << '\n' << "Pronto, todas as suas posições foram alocadas!" << '\n';
    }

    break;
    }
  }

//-----------------------------------------------------------------------------------------------------------------------------------------------------------//
int num_submarino2 = 0;
int num_cruzador2 = 0;
int num_destroyer2 = 0;
int num_p_avioes2 = 0;
//----------------------------------------------------------------------------------------------------------------------------------------------------------//

std::cout << '\n' << Linha << '\n' ;
std::cout << '\n' << J2.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
int pos_restantes2 = 14;
  
std::cout << '\n' << '\n' << "Submarino(" << pos_restantes2 << " posições restantes): ";

std:: cin >> num_submarino2;
  
  while(num_submarino2 < 0 || num_submarino2 > 14){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_submarino2;
  }
  
pos_restantes2 = pos_restantes2 - num_submarino2;

int pos_restantes_cruzador2 = (pos_restantes2)/3;
  
if(pos_restantes_cruzador2 != 0){
std::cout << '\n' << "Cruzador(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_cruzador2 << " unidades de Cruzador): ";
  
std:: cin >> num_cruzador2;

  while(num_cruzador2 < 0 || num_cruzador2 > pos_restantes_cruzador2){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_cruzador2;
  }
  
pos_restantes2 = pos_restantes2 - 3*num_cruzador2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Cruzadores" << '\n';
}

int pos_restantes_destroyer2 = (pos_restantes2)/4;

if(pos_restantes_destroyer2 != 0){
std::cout << '\n' << "Destroyer(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_destroyer2 << " unidades de Destroyer): ";
  

  
std:: cin >> num_destroyer2;

  while(num_destroyer2 < 0 || num_destroyer2 > pos_restantes_destroyer2){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_destroyer2;
  }
  
pos_restantes2 = pos_restantes2 - 4*num_destroyer2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Destroyers" << '\n';
}

int pos_restantes_p_avioes2 = (pos_restantes2)/5;

if(pos_restantes_p_avioes2 != 0){
std::cout << '\n' << "Porta-aviões(" << pos_restantes2 << " posições restantes ou até " << pos_restantes_p_avioes2 << " unidades de Porta-avião): ";
  
  
std:: cin >> num_p_avioes2;

  while(num_p_avioes2 < 0 || num_p_avioes2 > pos_restantes_p_avioes2){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> num_p_avioes2;
  }

pos_restantes2 = pos_restantes2 - 5*num_p_avioes2;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Porta-aviões" << '\n';
}

  if(pos_restantes2 == 0){
    std::cout << '\n'<< Linha << '\n' << "Pronto, todas as suas posições foram alocadas!";
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
    std::cout << '\n'<< Linha << '\n' << "Pronto, todas as suas posições foram alocadas!";
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

      while(add_sub2 < 0 || add_sub2 > pos_restantes2){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_sub2;
      }

    pos_restantes2 -= add_sub2;
    num_submarino2 += add_sub2;

    if(pos_restantes2/3 != 0){
       std::cout << '\n' << "Quer alocar quantos Cruzadores? " << '\n' << '\n';

    int add_cru2;
    std::cin >> add_cru2;

      while(add_cru2 < 0 || add_cru2 > pos_restantes2){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_cru2;
      }

    pos_restantes2 -= 3*add_cru2;
    num_cruzador2 += add_cru2;
    }

    if(pos_restantes2/4 != 0){
       std::cout << '\n' << "Quer alocar quantos Destroyers? " << '\n' << '\n';

    int add_des2;
    std::cin >> add_des2;

      while(add_des2 < 0 || add_des2 > pos_restantes2){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_des2;
      }

    pos_restantes2 -= 4*add_des2;
    num_destroyer2 += add_des2;
    }

    if(pos_restantes2/5 != 0){
       std::cout << '\n' << "Quer alocar quantos Porta-aviões? "<< '\n' << '\n';

    int add_pta2;
    std::cin >> add_pta2;

      while(add_pta2 < 0 || add_pta2 > pos_restantes2){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_pta2;
      }

    pos_restantes2 -= 5*add_pta2;
    num_p_avioes2 += add_pta2;
    }

    if(pos_restantes2 == 0){
      std::cout << '\n'<< Linha << '\n' << '\n' << "Pronto, todas as suas posições foram alocadas!" << '\n';
    }

    break;
    }
  }
//------------------------------------------------------------------------------------------------------------------------------------------------//

  std::cout << '\n' << "Vamos dar início ao posicionamento das peças no tabuleiro!" << '\n' << '\n';

  int _px , _py, _px2, _py2;

  J1.num_barcos = num_submarino + num_cruzador + num_destroyer + num_p_avioes;
  J2.num_barcos = num_submarino2 + num_cruzador2 + num_destroyer2 + num_p_avioes2;

//-----------------------------------------------------------------------------------------------------------------------------------------------//
  for(int i = 1; i < 12; i++){
    for(int j = 0; j < 24; j++){
      J1.tabuleiro_ataque[i][j] = '~';
      J1.tabuleiro_defesa[i][j] = '~';
    }
  }

  for(int i = 0; i < 24; i++){
      J1.tabuleiro_ataque[0][i] = '=';
      J1.tabuleiro_defesa[0][i] = '=';
    }
  for(int i = 0; i < 24; i++){
      J1.tabuleiro_ataque[11][i] = '=';
      J1.tabuleiro_defesa[11][i] = '=';
    }

  for(int i = 0; i < 12; i++){
      J1.tabuleiro_ataque[i][0] = '|';
      J1.tabuleiro_defesa[i][0] = '|';
    }
  for(int i = 0; i < 12; i++){
      J1.tabuleiro_ataque[i][23] = '|';
      J1.tabuleiro_defesa[i][23] = '|';
    }

  for(int i = 1; i < 12; i++){
    for(int j = 0; j < 24; j++){
      J2.tabuleiro_ataque[i][j] = '~';
      J2.tabuleiro_defesa[i][j] = '~';
    }
  }

  for(int i = 0; i < 24; i++){
      J2.tabuleiro_ataque[0][i] = '=';
      J2.tabuleiro_defesa[0][i] = '=';
    }
  for(int i = 0; i < 24; i++){
      J2.tabuleiro_ataque[11][i] = '=';
      J2.tabuleiro_defesa[11][i] = '=';
    }

  for(int i = 0; i < 12; i++){
      J2.tabuleiro_ataque[i][0] = '|';
      J2.tabuleiro_defesa[i][0] = '|';
    }
  for(int i = 0; i < 12; i++){
      J2.tabuleiro_ataque[i][23] = '|';
      J2.tabuleiro_defesa[i][23] = '|';
    }


  //-----------------------------------------------------------------------------------------------------------------------------------------//
  std::cout << J1.nome << ", posicione suas peças no tabuleiro." << '\n' << '\n';

  std::cout << "Você dispõe de " << J1.num_barcos << " barcos sendo eles: "<< '\n' << '\n';

  std::cout << num_submarino << " Submarino(s)" << '\n' << '\n' << num_cruzador << " Cruzador(es)" << '\n' << '\n' << num_destroyer << " Destroyer(s)"
    << '\n' << '\n' << num_p_avioes << " Porta-avião(ões)";

  int inicializador_barcos1 = J1.num_barcos;
  int inicializador_subs = num_submarino;
  int inicializador_cru = num_cruzador;
  int inicializador_des = num_destroyer;
  int inicializador_pt_a = num_p_avioes;
  
  std::cout << '\n' << '\n' << "Onde quer posicioná-los? Digite a linha e a sua respectiva coluna" << '\n';

  while(inicializador_barcos1 != 0){
    if(num_submarino != 0){
      std::cout << "Ponha seus Submarinos no tabuleiro: " << '\n';

      while(inicializador_subs != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23 ){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      while(J1.tabuleiro_defesa[_px][_py] == 'b'){
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }

        J1.tabuleiro_defesa[_px][_py] = 'b';

      inicializador_barcos1 --;
      inicializador_subs --;
    }
      }

    if(num_cruzador != 0){
      std::cout << "Ponha seus Cruzadores no tabuleiro (lembrando, só será alocado se digitar uma diferença de 2 unidades de casa): " << '\n';

      while(inicializador_cru != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
          
      }

        int diferenca = _px - _py;

        if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }

        while(diferenca != 2){
          std::cout << diferenca << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca = _px - _py;

          if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }
          
        }

      while(J1.tabuleiro_defesa[_px][_py] == 'b' || J1.tabuleiro_defesa[_py][_py] == 'b' || J1.tabuleiro_defesa[_px][_px] == 'b'
        || J1.tabuleiro_defesa[_py + 1][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 1] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1.tabuleiro_defesa[_px][_py] = 'b';
          J1.tabuleiro_defesa[_py][_py] = 'b';
          J1.tabuleiro_defesa[_py + 1][_py] = 'b';
        }

        else{J1.tabuleiro_defesa[_px][_py] = 'b';
        J1.tabuleiro_defesa[_px][_px] = 'b';
        J1.tabuleiro_defesa[_px][_px + 1] = 'b';}


      inicializador_barcos1 --;
      inicializador_cru --;
    }
      }

    if(num_destroyer != 0){
      std::cout << "Ponha seus Destroyers no tabuleiro (lembrando, só será alocado se digitar uma diferença de 3 unidades de casa): " << '\n';

      while(inicializador_des != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      int diferenca = _px - _py;

        if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }

        while(diferenca != 3){
          std::cout << diferenca << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca = _px - _py;

          if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }
          
        }

      while(J1.tabuleiro_defesa[_px][_py] == 'b' || J1.tabuleiro_defesa[_py][_py] == 'b' || J1.tabuleiro_defesa[_px][_px] == 'b'
        || J1.tabuleiro_defesa[_py + 1][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 1] == 'b' || J1.tabuleiro_defesa[_py + 2][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 2] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1.tabuleiro_defesa[_px][_py] = 'b';
          J1.tabuleiro_defesa[_py][_py] = 'b';
          J1.tabuleiro_defesa[_py + 1][_py] = 'b';
          J1.tabuleiro_defesa[_py + 2][_py] = 'b';
        }

        else{J1.tabuleiro_defesa[_px][_py] = 'b';
        J1.tabuleiro_defesa[_px][_px] = 'b';
        J1.tabuleiro_defesa[_px][_px + 1] = 'b';
        J1.tabuleiro_defesa[_px][_px + 2] = 'b';}

      inicializador_barcos1 --;
      inicializador_des --;
    }
      }

    if(num_p_avioes != 0){
      std::cout << "Ponha seus Porta-Aviões no tabuleiro (lembrando, só será alocado se digitar uma diferença de 4 unidades de casa): " << '\n';

      while(inicializador_pt_a != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      
      int diferenca = _px - _py;

        if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }

        while(diferenca != 4){
          std::cout << diferenca << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca = _px - _py;

          if(diferenca < 0){
          diferenca = -1 * (diferenca);
        }
          
        }

      while(J1.tabuleiro_defesa[_px][_py] == 'b' || J1.tabuleiro_defesa[_py][_py] == 'b' || J1.tabuleiro_defesa[_px][_px] == 'b'
        || J1.tabuleiro_defesa[_py + 1][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 1] == 'b' || J1.tabuleiro_defesa[_py + 2][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 2] == 'b' || J1.tabuleiro_defesa[_py + 3][_py] == 'b' || J1.tabuleiro_defesa[_px][_px + 3] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1.tabuleiro_defesa[_px][_py] = 'b';
          J1.tabuleiro_defesa[_py][_py] = 'b';
          J1.tabuleiro_defesa[_py + 1][_py] = 'b';
          J1.tabuleiro_defesa[_py + 2][_py] = 'b';
          J1.tabuleiro_defesa[_py + 3][_py] = 'b';
          
        }

        else{J1.tabuleiro_defesa[_px][_py] = 'b';
        J1.tabuleiro_defesa[_px][_px] = 'b';
        J1.tabuleiro_defesa[_px][_px + 1] = 'b';
        J1.tabuleiro_defesa[_px][_px + 2] = 'b';
        J1.tabuleiro_defesa[_px][_px + 3] = 'b';}

      inicializador_barcos1 --;
      inicializador_pt_a --;
    }
      }
  } 

  for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }

  std::cout << '\n' << '\n';


  //---------------------------------------------------------------------------------------------------------------------------------//
  
    std::cout << J2.nome << ", posicione suas peças no tabuleiro." << '\n' << '\n';

  std::cout << "Você dispõe de " << J2.num_barcos << " barcos sendo eles: "<< '\n' << '\n';

  std::cout << num_submarino2 << " Submarino(s)" << '\n' << '\n' << num_cruzador2 << " Cruzador(es)" << '\n' << '\n' << num_destroyer2 << " Destroyer(s)"
    << '\n' << '\n' << num_p_avioes2 << " Porta-avião(ões)";

  int inicializador_barcos2 = J2.num_barcos;
  int inicializador_subs2 = num_submarino2;
  int inicializador_cru2 = num_cruzador2;
  int inicializador_des2 = num_destroyer2;
  int inicializador_pt_a2 = num_p_avioes2;
  
  std::cout << '\n' << '\n' << "Onde quer posicioná-los? Digite a linha e a sua respectiva coluna" << '\n';

  while(inicializador_barcos2 != 0){
    if(num_submarino2 != 0){
      std::cout << "Ponha seus Submarinos no tabuleiro: " << '\n';

      while(inicializador_subs2 != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23 ){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      while(J2.tabuleiro_defesa[_px][_py] == 'b'){
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }

        J2.tabuleiro_defesa[_px][_py] = 'b';

      inicializador_barcos2 --;
      inicializador_subs2 --;
    }
      }

    if(num_cruzador2 != 0){
      std::cout << "Ponha seus Cruzadores no tabuleiro (lembrando, só será alocado se digitar uma diferença de 2 unidades de casa): " << '\n';

      while(inicializador_cru2 != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
          
      }

        int diferenca2 = _px - _py;

        if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }

        while(diferenca2 != 2){
          std::cout << diferenca2 << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca2 = _px - _py;

          if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }
          
        }

      while(J2.tabuleiro_defesa[_px][_py] == 'b' || J2.tabuleiro_defesa[_py][_py] == 'b' || J2.tabuleiro_defesa[_px][_px] == 'b'
        || J2.tabuleiro_defesa[_py + 1][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 1] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J2.tabuleiro_defesa[_px][_py] = 'b';
          J2.tabuleiro_defesa[_py][_py] = 'b';
          J2.tabuleiro_defesa[_py + 1][_py] = 'b';
        }

        else{J2.tabuleiro_defesa[_px][_py] = 'b';
        J2.tabuleiro_defesa[_px][_px] = 'b';
        J2.tabuleiro_defesa[_px][_px + 1] = 'b';}


      inicializador_barcos2 --;
      inicializador_cru2 --;
    }
      }

    if(num_destroyer2 != 0){
      std::cout << "Ponha seus Destroyers no tabuleiro (lembrando, só será alocado se digitar uma diferença de 3 unidades de casa): " << '\n';

      while(inicializador_des2 != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      int diferenca2 = _px - _py;

        if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }

        while(diferenca2 != 3){
          std::cout << diferenca2 << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca2 = _px - _py;

          if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }
          
        }

      while(J2.tabuleiro_defesa[_px][_py] == 'b' || J2.tabuleiro_defesa[_py][_py] == 'b' || J2.tabuleiro_defesa[_px][_px] == 'b'
        || J2.tabuleiro_defesa[_py + 1][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 1] == 'b' || J2.tabuleiro_defesa[_py + 2][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 2] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J2.tabuleiro_defesa[_px][_py] = 'b';
          J2.tabuleiro_defesa[_py][_py] = 'b';
          J2.tabuleiro_defesa[_py + 1][_py] = 'b';
          J2.tabuleiro_defesa[_py + 2][_py] = 'b';
        }

        else{J2.tabuleiro_defesa[_px][_py] = 'b';
        J2.tabuleiro_defesa[_px][_px] = 'b';
        J2.tabuleiro_defesa[_px][_px + 1] = 'b';
        J2.tabuleiro_defesa[_px][_px + 2] = 'b';}

      inicializador_barcos2 --;
      inicializador_des2 --;
    }
      }

    if(num_p_avioes2 != 0){
      std::cout << "Ponha seus Porta-Aviões no tabuleiro (lembrando, só será alocado se digitar uma diferença de 4 unidades de casa): " << '\n';

      while(inicializador_pt_a2 != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      
      int diferenca2 = _px - _py;

        if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }

        while(diferenca2 != 4){
          std::cout << diferenca2 << '\n';
          std::cout << '\n' << "Quantidade invalida de casas, digite novamente: " << '\n';
          std::cin >> _px >> _py;
          diferenca2 = _px - _py;

          if(diferenca2 < 0){
          diferenca2 = -1 * (diferenca2);
        }
          
        }

      while(J2.tabuleiro_defesa[_px][_py] == 'b' || J2.tabuleiro_defesa[_py][_py] == 'b' || J2.tabuleiro_defesa[_px][_px] == 'b'
        || J2.tabuleiro_defesa[_py + 1][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 1] == 'b' || J2.tabuleiro_defesa[_py + 2][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 2] == 'b' || J2.tabuleiro_defesa[_py + 3][_py] == 'b' || J2.tabuleiro_defesa[_px][_px + 3] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J2.tabuleiro_defesa[_px][_py] = 'b';
          J2.tabuleiro_defesa[_py][_py] = 'b';
          J2.tabuleiro_defesa[_py + 1][_py] = 'b';
          J2.tabuleiro_defesa[_py + 2][_py] = 'b';
          J2.tabuleiro_defesa[_py + 3][_py] = 'b';
          
        }

        else{J2.tabuleiro_defesa[_px][_py] = 'b';
        J2.tabuleiro_defesa[_px][_px] = 'b';
        J2.tabuleiro_defesa[_px][_px + 1] = 'b';
        J2.tabuleiro_defesa[_px][_px + 2] = 'b';
        J2.tabuleiro_defesa[_px][_px + 3] = 'b';}

      inicializador_barcos2 --;
      inicializador_pt_a2 --;
    }
      }
  }  

  for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }

  std::cout << "Barcos posicionados, vamos iniciar as rodadas de ataque." << '\n' << '\n';
  
  while(J2.num_barcos != 0 || J1.num_barcos != 0){
    
    std::cout << J1.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> _px >> _py;

    J1.tabuleiro_ataque[_px][_py] = '0';

    if(J2.tabuleiro_defesa[_px][_py] == 'b'){
      J2.tabuleiro_defesa[_px][_py] = 'X';
      J1.tabuleiro_ataque[_px][_py] = 'X';
      J2.num_barcos --;
    }


    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    if(J2.num_barcos == 0 || J1.num_barcos == 0){
      break;}

  std::cout << J2.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> _px2 >> _py2;

    J2.tabuleiro_ataque[_px2][_py2] = '0';

    if(J1.tabuleiro_defesa[_px2][_py2] == 'b'){
      J1.tabuleiro_defesa[_px2][_py2] = 'X';
      J2.tabuleiro_ataque[_px2][_py2] = 'X';
      J1.num_barcos --;
    }
    

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';


    if(J2.num_barcos == 0 || J1.num_barcos == 0){
      break;}
  }

  if(J1.num_barcos == 0){
    std::cout << "Parabéns, " << J2.nome << ", você ganhou!!";
  }

  else if(J2.num_barcos == 0){
    std::cout << "Parabéns, " << J1.nome << ", você ganhou!!";
  }

  std::cout << '\n' << '\n' << "|-------------------------------------------------------------FIM DO JOGO!-----------------------------------------------------------------|";
  
  return 0;
}
