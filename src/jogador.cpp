#include "jogador.hpp"
std::string linha_ = "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|";


void montar_tabuleiro(Jogador &J1_){
  for(int i = 1; i < 12; i++){
    for(int j = 0; j < 24; j++){
      J1_.tabuleiro_ataque[i][j] = '~';
      J1_.tabuleiro_defesa[i][j] = '~';
    }
  }

  for(int i = 0; i < 24; i++){
      J1_.tabuleiro_ataque[0][i] = '=';
      J1_.tabuleiro_defesa[0][i] = '=';
    }
  
  for(int i = 0; i < 24; i++){
      J1_.tabuleiro_ataque[11][i] = '=';
      J1_.tabuleiro_defesa[11][i] = '=';
    }

  for(int i = 0; i < 12; i++){
      J1_.tabuleiro_ataque[i][0] = '|';
      J1_.tabuleiro_defesa[i][0] = '|';
    }
  
  for(int i = 0; i < 12; i++){
      J1_.tabuleiro_ataque[i][23] = '|';
      J1_.tabuleiro_defesa[i][23] = '|';
    }
};

void alocar_barcos(Jogador &J1_){
  std::cout << '\n' << J1_.nome << ", digite a quantidade de barcos que quer no tabuleiro:";
  
std::cout << '\n' << '\n' << "Submarino(" << J1_.pos_restantes << " posições restantes): ";

std:: cin >> J1_.num_submarino;
  
  while(J1_.num_submarino < 0 || J1_.num_submarino > 14){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> J1_.num_submarino;
  }
  
J1_.pos_restantes = J1_.pos_restantes - J1_.num_submarino;

int pos_restantes_cruzador = (J1_.pos_restantes)/3;
  
if(pos_restantes_cruzador != 0){
std::cout << '\n' << "Cruzador(" << J1_.pos_restantes << " posições restantes ou até " << pos_restantes_cruzador << " unidades de Cruzador): ";
  
std:: cin >> J1_.num_cruzador;

  while(J1_.num_cruzador < 0 || J1_.num_cruzador > pos_restantes_cruzador){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> J1_.num_cruzador;
  }
  
J1_.pos_restantes = J1_.pos_restantes - 3*J1_.num_cruzador;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Cruzadores" << '\n';
}

int pos_restantes_destroyer = (J1_.pos_restantes)/4;

if(pos_restantes_destroyer != 0){
std::cout << '\n' << "Destroyer(" << J1_.pos_restantes << " posições restantes ou até " << pos_restantes_destroyer << " unidades de Destroyer): ";
  

  
std:: cin >> J1_.num_destroyer;

  while(J1_.num_destroyer < 0 || J1_.num_destroyer > pos_restantes_destroyer){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> J1_.num_destroyer;
  }
  
J1_.pos_restantes = J1_.pos_restantes - 4*J1_.num_destroyer;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Destroyers" << '\n';
}

int pos_restantes_p_avioes = (J1_.pos_restantes)/5;

if(pos_restantes_p_avioes != 0){
std::cout << '\n' << "Porta-aviões(" << J1_.pos_restantes << " posições restantes ou até " << pos_restantes_p_avioes << " unidades de Porta-avião): ";
  
  
std:: cin >> J1_.num_p_avioes;

  while(J1_.num_p_avioes < 0 || J1_.num_p_avioes > pos_restantes_p_avioes){
    std::cout << '\n' << "Número invávlido, digite novamente: ";
    std:: cin >> J1_.num_p_avioes;
  }

J1_.pos_restantes = J1_.pos_restantes - 5*J1_.num_p_avioes;
  
}

else{
  std::cout << '\n' << "Número insuficiente de casas para alocar Porta-aviões" << '\n';
}

  if(J1_.pos_restantes == 0){
    std::cout << '\n'<< linha_ << '\n' << "|                                              Pronto, todas as suas posições foram alocadas!                                                                         |";
  }

//------------------------------------------------------------------------------------------------------------------------------------------//
  
while(J1_.pos_restantes != 0){
  std::cout << '\n'<< linha_ << '\n';
  std::cout << '\n' << "Ainda faltam " << J1_.pos_restantes << " posição(ões) a serem preenchidas. Deseja finalizar sua alocação (1) ou adicionar mais barcos (2)?" << '\n' << '\n';

  int escolha;

  std::cin >> escolha;

  switch(escolha){
    case 1:
    J1_.pos_restantes = 0;
    std::cout << '\n'<< linha_ << '\n' << "Pronto, todas as suas posições foram alocadas!";
    break;

    case 2:
    std::cout << '\n' << "Qual tipo de barco deseja alocar?" << '\n' << '\n' << "Ainda lhe restam: " << '\n' << '\n';

    std::cout << "*Submarinos: " << J1_.pos_restantes << '\n' << '\n';

    if(J1_.pos_restantes/3 != 0){
       std::cout << "*Cruzadores: " << (J1_.pos_restantes/3) << '\n' << '\n';
    }

    if(J1_.pos_restantes/4 != 0){
       std::cout << "*Destroyers: " << (J1_.pos_restantes/4) << '\n' << '\n';
    }

    if(J1_.pos_restantes/5 != 0){
       std::cout << "*Porta-aviões: " << (J1_.pos_restantes/5) << '\n' << '\n';
    }

    std::cout << "Quer alocar quantos Submarinos? " << '\n' << '\n';

    int add_sub;
    std::cin >> add_sub;

      while(add_sub < 0 || add_sub > J1_.pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_sub;
      }

    J1_.pos_restantes -= add_sub;
    J1_.num_submarino += add_sub;

    if(J1_.pos_restantes/3 != 0){
       std::cout << '\n' << "Quer alocar quantos Cruzadores? " << '\n' << '\n';

    int add_cru;
    std::cin >> add_cru;

      while(add_cru < 0 || add_cru > J1_.pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_cru;
      }

    J1_.pos_restantes -= 3*add_cru;
    J1_.num_cruzador += add_cru;
    }

    if(J1_.pos_restantes/4 != 0){
       std::cout << '\n' << "Quer alocar quantos Destroyers? " << '\n' << '\n';

    int add_des;
    std::cin >> add_des;

      while(add_des < 0 || add_des > J1_.pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_des;
      }

    J1_.pos_restantes -= 4*add_des;
    J1_.num_destroyer += add_des;
    }

    if(J1_.pos_restantes/5 != 0){
       std::cout << '\n' << "Quer alocar quantos Porta-aviões? "<< '\n' << '\n';

    int add_pta;
    std::cin >> add_pta;

      while(add_pta < 0 || add_pta > J1_.pos_restantes){
        std::cout << '\n' << "Número invávlido, digite novamente: ";
        std:: cin >> add_pta;
      }

    J1_.pos_restantes -= 5*add_pta;
    J1_.num_p_avioes += add_pta;
    }

    if(J1_.pos_restantes == 0){
      std::cout << '\n'<< linha_ << '\n' << '\n' << "Pronto, todas as suas posições foram alocadas!" << '\n';
    }

    break;
    }
  }
  
};

void posicionar_barcos(Jogador &J1_){
  int _px , _py, _px2, _py2;
  
  std::cout << J1_.nome << ", posicione suas peças no tabuleiro." << '\n' << '\n';

  std::cout << "Você dispõe de " << J1_.num_barcos << " barcos sendo eles: "<< '\n' << '\n';

  std::cout << J1_.num_submarino << " Submarino(s)" << '\n' << '\n' << J1_.num_cruzador << " Cruzador(es)" << '\n' << '\n' << J1_.num_destroyer << " Destroyer(s)"
    << '\n' << '\n' << J1_.num_p_avioes << " Porta-avião(ões)";

  int inicializador_barcos1 = J1_.num_barcos;
  int inicializador_subs = J1_.num_submarino;
  int inicializador_cru = J1_.num_cruzador;
  int inicializador_des = J1_.num_destroyer;
  int inicializador_pt_a = J1_.num_p_avioes;
  
  std::cout << '\n' << '\n' << "Onde quer posicioná-los? Digite a linha e a sua respectiva coluna" << '\n';

  while(inicializador_barcos1 != 0){
    if(J1_.num_submarino != 0){
      std::cout << "Ponha seus Submarinos no tabuleiro: " << '\n';

      while(inicializador_subs != 0){
      
      std::cin >> _px >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23 ){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        std::cin >> _px >> _py;
      }

      while(J1_.tabuleiro_defesa[_px][_py] == 'b'){
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }

        J1_.tabuleiro_defesa[_px][_py] = 'b';

      inicializador_barcos1 --;
      inicializador_subs --;
    }
      }

    if(J1_.num_cruzador != 0){
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

      while(J1_.tabuleiro_defesa[_px][_py] == 'b' || J1_.tabuleiro_defesa[_py][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px] == 'b'
        || J1_.tabuleiro_defesa[_py + 1][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 1] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1_.tabuleiro_defesa[_px][_py] = 'b';
          J1_.tabuleiro_defesa[_py][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 1][_py] = 'b';
        }

        else{J1_.tabuleiro_defesa[_px][_py] = 'b';
        J1_.tabuleiro_defesa[_px][_px] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 1] = 'b';}


      inicializador_barcos1 --;
      inicializador_cru --;
    }
      }

    if(J1_.num_destroyer != 0){
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

      while(J1_.tabuleiro_defesa[_px][_py] == 'b' || J1_.tabuleiro_defesa[_py][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px] == 'b'
        || J1_.tabuleiro_defesa[_py + 1][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 1] == 'b' || J1_.tabuleiro_defesa[_py + 2][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 2] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1_.tabuleiro_defesa[_px][_py] = 'b';
          J1_.tabuleiro_defesa[_py][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 1][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 2][_py] = 'b';
        }

        else{J1_.tabuleiro_defesa[_px][_py] = 'b';
        J1_.tabuleiro_defesa[_px][_px] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 1] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 2] = 'b';}

      inicializador_barcos1 --;
      inicializador_des --;
    }
      } 

    if(J1_.num_p_avioes != 0){
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

      while(J1_.tabuleiro_defesa[_px][_py] == 'b' || J1_.tabuleiro_defesa[_py][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px] == 'b'
        || J1_.tabuleiro_defesa[_py + 1][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 1] == 'b' || J1_.tabuleiro_defesa[_py + 2][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 2] == 'b' || J1_.tabuleiro_defesa[_py + 3][_py] == 'b' || J1_.tabuleiro_defesa[_px][_px + 3] == 'b'){
        
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        std::cin >> _px >> _py;
      }
        if(_px > _py){
          J1_.tabuleiro_defesa[_px][_py] = 'b';
          J1_.tabuleiro_defesa[_py][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 1][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 2][_py] = 'b';
          J1_.tabuleiro_defesa[_py + 3][_py] = 'b';
          
        }

        else{J1_.tabuleiro_defesa[_px][_py] = 'b';
        J1_.tabuleiro_defesa[_px][_px] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 1] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 2] = 'b';
        J1_.tabuleiro_defesa[_px][_px + 3] = 'b';}

      inicializador_barcos1 --;
      inicializador_pt_a --;
    }
      }
  } 

  for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }

  std::cout << '\n' << '\n';
  
};

void jogadas(Jogador &J1_, Jogador &J2_){
  std::cout << "Barcos posicionados, vamos iniciar as rodadas de ataque." << '\n' << '\n';

  int Px, Py, Px2, Py2;
  
  while(J2_.num_barcos != 0 || J1_.num_barcos != 0){
    
    std::cout << J1_.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> Px >> Py;

    J1_.tabuleiro_ataque[Px][Py] = '0';

    if(J2_.tabuleiro_defesa[Px][Py] == 'b'){
      J2_.tabuleiro_defesa[Px][Py] = 'X';
      J1_.tabuleiro_ataque[Px][Py] = 'X';
      J2_.num_barcos --;
    }

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2_.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    if(J2_.num_barcos == 0 || J1_.num_barcos == 0){
      break;}

  std::cout << J2_.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> Px2 >> Py2;

    J2_.tabuleiro_ataque[Px2][Py2] = '0';

    if(J1_.tabuleiro_defesa[Px2][Py2] == 'b'){
      J1_.tabuleiro_defesa[Px2][Py2] = 'X';
      J2_.tabuleiro_ataque[Px2][Py2] = 'X';
      J1_.num_barcos --;
    }
    

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2_.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';


    if(J2_.num_barcos == 0 || J1_.num_barcos == 0){
      break;}
  }

  if(J1_.num_barcos == 0){
    std::cout << "Parabéns, " << J2_.nome << ", você ganhou!!";
  }

  else if(J2_.num_barcos == 0){
    std::cout << "Parabéns, " << J1_.nome << ", você ganhou!!";
  }
};
