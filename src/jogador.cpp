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
    std::cout << '\n'<< linha_ << '\n' << "|                                                                    Pronto, todas as suas posições foram alocadas!                                                                |";
  }

//------------------------------------------------------------------------------------------------------------------------------------------//
  
while(J1_.pos_restantes != 0){
  std::cout << '\n'<< linha_ << '\n';
  std::cout << '\n' << "Ainda faltam " << J1_.pos_restantes << " posição(ões) a serem preenchidas. Deseja finalizar sua alocação (1) ou adicionar mais barcos (2)?"<< '\n' << '\n' << "-> ";

  int escolha;

  std::cin >> escolha;

  while(escolha < 1 || escolha > 2){
    std::cout << "Opção errada, digite novamente: " << '\n' << '\n' << "-> ";
    std::cin >> escolha;
  }

  switch(escolha){
    case 1:

    
    while(J1_.pos_restantes == 14){
      std::cout << "Opção inválida, você precisa de pelo menos um barco no tabuleiro!" << '\n';

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
      std::cout << '\n'<< linha_ << '\n' << "|                                                                    Pronto, todas as suas posições foram alocadas!                                                                |";
    }

      
    }
      
    J1_.pos_restantes = 0;
    std::cout << '\n'<< linha_ << '\n' << "|                                                                    Pronto, todas as suas posições foram alocadas!                                                                |";
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
      std::cout << '\n'<< linha_ << '\n' << "|                                                                    Pronto, todas as suas posições foram alocadas!                                                                |";
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
      std::cout << "Ponha seus Submarinos no tabuleiro, começando pela linha e posteriormente a coluna: " << '\n';

      while(inicializador_subs != 0){

      std::cout << '\n' << "Linha -> ";
      std::cin >> _px;
      std::cout << '\n' << "Coluna -> ";
      std::cin >> _py;

      while(_px <= 0 || _px >=11 || _py <= 0 || _py >= 23 ){
        std::cout << '\n' << "Posição inválida, digite novamente: " << '\n';
        
        std::cout << '\n' << "Linha -> ";
        std::cin >> _px;
        std::cout << '\n' << "Coluna -> " << '\n';
        std::cin >> _py;
        
      }

      while(J1_.tabuleiro_defesa[_px][_py] == 'S'){
        std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
        
        std::cout << '\n' << "Linha -> ";
        std::cin >> _px;
        std::cout << '\n' << "Coluna -> " << '\n';
        std::cin >> _py;
      }

        J1_.tabuleiro_defesa[_px][_py] = 'S';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

      inicializador_barcos1 --;
      inicializador_subs --;
    }
      }

    if(J1_.num_cruzador != 0){
      std::cout << "Ponha seus Cruzadores no tabuleiro: " << '\n';

      while(inicializador_cru != 0){

        std::cout << "Deseja posicionar na vertical(1) ou horizontal(2)?" << '\n' << "-> ";

        int escolha_2;

        std::cin >> escolha_2;

        switch(escolha_2){
          case 1:

          std::cout << "Digite a coluna que quer posicionar o barco: " << '\n' << '\n' << "Coluna -> ";
          
          std::cin >> _py;

          while(_py <= 0 || _py >= 23){
            
          std::cout << '\n' << "Coluna inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
          std::cin >> _py;
          
      }
          break;

          case 2:

          std::cout << "Digite a linha que quer posicionar o barco: " << '\n' << '\n' << "Linha -> ";
          
          std::cin >> _px;

          while(_px <= 0 || _px >= 11){
            
          std::cout << '\n' << "Linha inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
          std::cin >> _px;
            
        }
          break;
        }

      if(escolha_2 == 1){
        std::cout << '\n' << "Agora, digite as linhas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Linha -> ";

        int contador_crz = 3;

        while(contador_crz !=0){
          std::cin >> _px;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'C';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_crz--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px2;

          std::cin >> _px2;

          while(abs(_px2 - _px) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          while(J1_.tabuleiro_defesa[_px2][_py] == 'S' || J1_.tabuleiro_defesa[_px2][_py] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: "<< '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          J1_.tabuleiro_defesa[_px2][_py] = 'C';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_crz--;

          std::cout << '\n' << '\n' << "Digite a última linha: " << '\n' << '\n' << "Linha -> ";

          int _px3;

          std::cin >> _px3;

          while(abs(_px3 - _px2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px3;
          }

          while(J1_.tabuleiro_defesa[_px3][_py] == 'S' || J1_.tabuleiro_defesa[_px3][_py] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px3;
          }

          J1_.tabuleiro_defesa[_px3][_py] = 'C';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

          contador_crz--;
        }
  
      }

      if(escolha_2 == 2){
        std::cout << '\n' << "Agora, digite as colunas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Coluna -> ";

        int contador_crz = 3;

        while(contador_crz !=0){
          std::cin >> _py;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'C';

          for(int i = 0; i < 12; i ++){
            for(int j = 0; j < 24; j++){
              std::cout << J1_.tabuleiro_defesa[i][j];
          }
        
          std::cout << '\n';
        }

          std::cout << '\n' << '\n';
          
          contador_crz--;

          std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py2;

          std::cin >> _py2;

          while(abs(_py2 - _py) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
            std::cin >> _py2;
          }

          while(J1_.tabuleiro_defesa[_px][_py2] == 'S' || J1_.tabuleiro_defesa[_px][_py2] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py2;
          }

          J1_.tabuleiro_defesa[_px][_py2] = 'C';

        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
            std::cout << '\n';
        }

            std::cout << '\n' << '\n';

          contador_crz--;

          std::cout << '\n' << '\n' << "Digite a última coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py3;

          std::cin >> _py3;

          while(abs(_py3 - _py2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py3;
          }

          while(J1_.tabuleiro_defesa[_px][_py3] == 'S' || J1_.tabuleiro_defesa[_px][_py3] == 'C'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py3;
          }

          J1_.tabuleiro_defesa[_px][_py3] = 'C';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_crz--;
        }
  
      }

      inicializador_barcos1 --;
      inicializador_cru --;
    }
      }

    if(J1_.num_destroyer != 0){
      std::cout << "Ponha seus Destroyers no tabuleiro: " << '\n';

      while(inicializador_des != 0){
      
      std::cout << "Deseja posicionar na vertical(1) ou horizontal(2)?" << '\n' << "-> ";

        int escolha_3;

        std::cin >> escolha_3;

        switch(escolha_3){
          case 1:

          std::cout << "Digite a coluna que quer posicionar o barco: " << '\n' << '\n' << "Coluna -> ";
          
          std::cin >> _py;

          while(_py <= 0 || _py >= 23){
            
          std::cout << '\n' << "Coluna inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
          std::cin >> _py;
          
      }
          break;

          case 2:

          std::cout << "Digite a linha que quer posicionar o barco: " << '\n' << '\n' << "Linha -> ";
          
          std::cin >> _px;

          while(_px <= 0 || _px >= 11){
            
          std::cout << '\n' << "Linha inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
          std::cin >> _px;
            
        }
          break;
        }

      if(escolha_3 == 1){
        std::cout << '\n' << "Agora, digite as linhas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Linha -> ";

        int contador_des = 4;

        while(contador_des !=0){
          std::cin >> _px;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C' || J1_.tabuleiro_defesa[_px][_py] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'D';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_des--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px2;

          std::cin >> _px2;

          while(abs(_px2 - _px) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          while(J1_.tabuleiro_defesa[_px2][_py] == 'S' || J1_.tabuleiro_defesa[_px2][_py] == 'C'|| J1_.tabuleiro_defesa[_px2][_py] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: "<< '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          J1_.tabuleiro_defesa[_px2][_py] = 'D';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_des--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px3;

          std::cin >> _px3;

          while(abs(_px3 - _px2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px3;
          }

          while(J1_.tabuleiro_defesa[_px3][_py] == 'S' || J1_.tabuleiro_defesa[_px3][_py] == 'C'|| J1_.tabuleiro_defesa[_px3][_py] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px3;
          }

          J1_.tabuleiro_defesa[_px3][_py] = 'D';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

          contador_des--;

          std::cout << '\n' << '\n' << "Digite a última linha: " << '\n' << '\n' << "Linha -> ";

          int _px4;

          std::cin >> _px4;

          while(abs(_px4 - _px3) > 1){
            std::cout << '\n' << "Quantidade de casas inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px4;
          }

          while(J1_.tabuleiro_defesa[_px4][_py] == 'S' || J1_.tabuleiro_defesa[_px4][_py] == 'C'|| J1_.tabuleiro_defesa[_px4][_py] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px4;
          }

          J1_.tabuleiro_defesa[_px4][_py] = 'D';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

          contador_des--;
        }
  
      }

      if(escolha_3 == 2){
        std::cout << '\n' << "Agora, digite as colunas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Coluna -> ";

        int contador_des = 4;

        while(contador_des !=0){
          std::cin >> _py;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C' || J1_.tabuleiro_defesa[_px][_py] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'D';

          for(int i = 0; i < 12; i ++){
            for(int j = 0; j < 24; j++){
              std::cout << J1_.tabuleiro_defesa[i][j];
          }
        
          std::cout << '\n';
        }

          std::cout << '\n' << '\n';
          
          contador_des--;

          std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py2;

          std::cin >> _py2;

          while(abs(_py2 - _py) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
            std::cin >> _py2;
          }

          while(J1_.tabuleiro_defesa[_px][_py2] == 'S' || J1_.tabuleiro_defesa[_px][_py2] == 'C'|| J1_.tabuleiro_defesa[_px][_py2] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py2;
          }

          J1_.tabuleiro_defesa[_px][_py2] = 'D';

        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
            std::cout << '\n';
        }

            std::cout << '\n' << '\n';

          contador_des--;

          std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py3;

          std::cin >> _py3;

          while(abs(_py3 - _py2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py3;
          }

          while(J1_.tabuleiro_defesa[_px][_py3] == 'S' || J1_.tabuleiro_defesa[_px][_py3] == 'C'|| J1_.tabuleiro_defesa[_px][_py3] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py3;
          }

          J1_.tabuleiro_defesa[_px][_py3] = 'D';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_des--;

        std::cout << '\n' << '\n' << "Digite a última coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py4;

          std::cin >> _py4;

          while(abs(_py4 - _py3) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py4;
          }

          while(J1_.tabuleiro_defesa[_px][_py4] == 'S' || J1_.tabuleiro_defesa[_px][_py4] == 'C'|| J1_.tabuleiro_defesa[_px][_py4] == 'D'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py3;
          }

          J1_.tabuleiro_defesa[_px][_py4] = 'D';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_des--;
        }
  
      }

      inicializador_barcos1 --;
      inicializador_des --;
    }
      }

    if(J1_.num_p_avioes != 0){
      std::cout << "Ponha seus Porta-Aviões no tabuleiro: " << '\n';

      while(inicializador_pt_a != 0){
      
      std::cout << "Deseja posicionar na vertical(1) ou horizontal(2)?" << '\n' << "-> ";

        int escolha_4;

        std::cin >> escolha_4;

        switch(escolha_4){
          case 1:

          std::cout << "Digite a coluna que quer posicionar o barco: " << '\n' << '\n' << "Coluna -> ";
          
          std::cin >> _py;

          while(_py <= 0 || _py >= 23){
            
          std::cout << '\n' << "Coluna inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
          std::cin >> _py;
          
      }
          break;

          case 2:

          std::cout << "Digite a linha que quer posicionar o barco: " << '\n' << '\n' << "Linha -> ";
          
          std::cin >> _px;

          while(_px <= 0 || _px >= 11){
            
          std::cout << '\n' << "Linha inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
          std::cin >> _px;
            
        }
          break;
        }

      if(escolha_4 == 1){
        std::cout << '\n' << "Agora, digite as linhas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Linha -> ";

        int contador_pta = 5;

        while(contador_pta !=0){
          std::cin >> _px;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C' || J1_.tabuleiro_defesa[_px][_py] == 'D'|| J1_.tabuleiro_defesa[_px][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'P';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px2;

          std::cin >> _px2;

          while(abs(_px2 - _px) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          while(J1_.tabuleiro_defesa[_px2][_py] == 'S' || J1_.tabuleiro_defesa[_px2][_py] == 'C'|| J1_.tabuleiro_defesa[_px2][_py] == 'D'|| J1_.tabuleiro_defesa[_px2][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: "<< '\n' << '\n' << "Linha -> ";
            std::cin >> _px2;
          }

          J1_.tabuleiro_defesa[_px2][_py] = 'P';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

  std::cout << '\n' << '\n';

          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px3;

          std::cin >> _px3;

          while(abs(_px3 - _px2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px3;
          }

          while(J1_.tabuleiro_defesa[_px3][_py] == 'S' || J1_.tabuleiro_defesa[_px3][_py] == 'C'|| J1_.tabuleiro_defesa[_px3][_py] == 'D'|| J1_.tabuleiro_defesa[_px3][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px3;
          }

          J1_.tabuleiro_defesa[_px3][_py] = 'P';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a próxima linha: " << '\n' << '\n' << "Linha -> ";

          int _px4;

          std::cin >> _px4;

          while(abs(_px4 - _px3) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px4;
          }

          while(J1_.tabuleiro_defesa[_px4][_py] == 'S' || J1_.tabuleiro_defesa[_px4][_py] == 'C'|| J1_.tabuleiro_defesa[_px4][_py] == 'D'|| J1_.tabuleiro_defesa[_px4][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px4;
          }

          J1_.tabuleiro_defesa[_px4][_py] = 'P';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a última linha: " << '\n' << '\n' << "Linha -> ";

          int _px5;

          std::cin >> _px5;

          while(abs(_px5 - _px4) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _px5;
          }

          while(J1_.tabuleiro_defesa[_px5][_py] == 'S' || J1_.tabuleiro_defesa[_px5][_py] == 'C'|| J1_.tabuleiro_defesa[_px5][_py] == 'D'|| J1_.tabuleiro_defesa[_px5][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _px5;
          }

          J1_.tabuleiro_defesa[_px5][_py] = 'P';

      std::cout << '\n' << "Seu Tabuleiro de Defesa: " << '\n' << '\n';
        
      for(int i = 0; i < 12; i ++){
        for(int j = 0; j < 24; j++){
          std::cout << J1_.tabuleiro_defesa[i][j];
      }
        
      std::cout << '\n';
  }

      std::cout << '\n' << '\n';

      contador_pta--;

        }
  
      }

      if(escolha_4 == 2){
        std::cout << '\n' << "Agora, digite as colunas (em sequência) que quer alocar seu barco: " << '\n' << '\n' << "Coluna -> ";

        int contador_pta = 5;

        while(contador_pta !=0){
          std::cin >> _py;

          while(J1_.tabuleiro_defesa[_px][_py] == 'S' || J1_.tabuleiro_defesa[_px][_py] == 'C' || J1_.tabuleiro_defesa[_px][_py] == 'D'|| J1_.tabuleiro_defesa[_px][_py] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py;
          }

          J1_.tabuleiro_defesa[_px][_py] = 'P';

          for(int i = 0; i < 12; i ++){
            for(int j = 0; j < 24; j++){
              std::cout << J1_.tabuleiro_defesa[i][j];
          }
        
          std::cout << '\n';
        }

          std::cout << '\n' << '\n';
          
          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py2;

          std::cin >> _py2;

          while(abs(_py2 - _py) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Coluna -> ";
            std::cin >> _py2;
          }

          while(J1_.tabuleiro_defesa[_px][_py2] == 'S' || J1_.tabuleiro_defesa[_px][_py2] == 'C'|| J1_.tabuleiro_defesa[_px][_py2] == 'D'|| J1_.tabuleiro_defesa[_px][_py2] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py2;
          }

          J1_.tabuleiro_defesa[_px][_py2] = 'P';

        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
            std::cout << '\n';
        }

            std::cout << '\n' << '\n';

          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py3;

          std::cin >> _py3;

          while(abs(_py3 - _py2) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py3;
          }

          while(J1_.tabuleiro_defesa[_px][_py3] == 'S' || J1_.tabuleiro_defesa[_px][_py3] == 'C'|| J1_.tabuleiro_defesa[_px][_py3] == 'D'|| J1_.tabuleiro_defesa[_px][_py3] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py3;
          }

          J1_.tabuleiro_defesa[_px][_py3] = 'P';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_pta--;

        std::cout << '\n' << '\n' << "Digite a próxima coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py4;

          std::cin >> _py4;

          while(abs(_py4 - _py3) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py4;
          }

          while(J1_.tabuleiro_defesa[_px][_py4] == 'S' || J1_.tabuleiro_defesa[_px][_py4] == 'C'|| J1_.tabuleiro_defesa[_px][_py4] == 'D'|| J1_.tabuleiro_defesa[_px][_py4] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py4;
          }

          J1_.tabuleiro_defesa[_px][_py4] = 'P';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_pta--;

          std::cout << '\n' << '\n' << "Digite a última coluna: " << '\n' << '\n' << "Coluna -> ";

          int _py5;

          std::cin >> _py5;

          while(abs(_py5 - _py4) > 1){
            std::cout << '\n' << "Posição inválida, digite novamente: " << '\n' << '\n' << "Linha -> ";
            std::cin >> _py5;
          }

          while(J1_.tabuleiro_defesa[_px][_py5] == 'S' || J1_.tabuleiro_defesa[_px][_py5] == 'C'|| J1_.tabuleiro_defesa[_px][_py5] == 'D'|| J1_.tabuleiro_defesa[_px][_py5] == 'P'){
            std::cout << '\n' << "Posição já alocada, digite outra: " << '\n';
            std::cin >> _py5;
          }

          J1_.tabuleiro_defesa[_px][_py5] = 'P';
          
        for(int i = 0; i < 12; i ++){
          for(int j = 0; j < 24; j++){
            std::cout << J1_.tabuleiro_defesa[i][j];
        }
        
        std::cout << '\n';
        }

        std::cout << '\n' << '\n';
          
          contador_pta--;
        }
  
      }

      inicializador_barcos1 --;
      inicializador_pt_a --;
    }
      }
  } 
  
};

void jogadas(Jogador &J1_, Jogador &J2_){
  std::cout << "Barcos posicionados, vamos iniciar as rodadas de ataque." << '\n' << '\n';

  int Px, Py, Px2, Py2;
  
  while(J2_.num_barcos != 0 || J1_.num_barcos != 0){

    std::cout << J1_.nome << ", aqui está o seu tabuleiro de defesa: " << '\n' << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n' << '\n';

    std::cout << J1_.nome << ", aqui está o seu tabuleiro de ataque: " << '\n' << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n' << '\n';
    
    std::cout << J1_.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> Px >> Py;

    while(J1_.tabuleiro_ataque[Px][Py] == '0'){
      std::cout << "Ataque vazio repetido, tente outra posição: " << '\n' << '\n' << "-> ";
      std::cin >> Px >> Py;
    };

    while(J1_.tabuleiro_ataque[Px][Py] == 'X'){
      std::cout << "Ataque em barco repetido, tente outra posição: " << '\n' << '\n' << "-> ";
      std::cin >> Px >> Py;
    }

    if(J2_.tabuleiro_defesa[Px][Py] == '~'){
      J1_.tabuleiro_ataque[Px][Py] = '0';
    }

    if(J2_.tabuleiro_defesa[Px][Py] == 'S' || J2_.tabuleiro_defesa[Px][Py] == 'C' || J2_.tabuleiro_defesa[Px][Py] == 'D' || J2_.tabuleiro_defesa[Px][Py] == 'P'){
      J2_.tabuleiro_defesa[Px][Py] = 'X';
      J1_.tabuleiro_ataque[Px][Py] = 'X';
      J2_.num_barcos --;
    }
    
    std::cout << '\n';

    std::cout << J1_.nome << ", aqui está o seu novo tabuleiro de ataque: " << '\n' << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J1_.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n';

    if(J2_.num_barcos == 0 || J1_.num_barcos == 0){
      break;}

     std::cout << J2_.nome << ", aqui está o seu tabuleiro de defesa: " << '\n' << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2_.tabuleiro_defesa[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n' << '\n';

    std::cout << J2_.nome << ", aqui está o seu tabuleiro de ataque: " << '\n' << '\n';

    for(int i = 0; i < 12; i ++){
    for(int j = 0; j < 24; j++){
      std::cout << J2_.tabuleiro_ataque[i][j];
    }
    std::cout << '\n';
  }
    std::cout << '\n' << '\n';
    
    std::cout << J2_.nome << ", digite onde quer fazer seu ataque: " << '\n' << '\n';

    std::cin >> Px2 >> Py2;

    while(J2_.tabuleiro_ataque[Px2][Py2] == '0'){
      std::cout << "Ataque vazio repetido, tente outra posição: " << '\n' << '\n' << "-> ";
      std::cin >> Px2 >> Py2;
    };

    while(J1_.tabuleiro_ataque[Px2][Py2] == 'X'){
      std::cout << "Ataque em barco repetido, tente outra posição: " << '\n' << '\n' << "-> ";
      std::cin >> Px2 >> Py2;
    };

    if(J1_.tabuleiro_defesa[Px2][Py2] == 'S' || J1_.tabuleiro_defesa[Px2][Py2] == 'C' || J1_.tabuleiro_defesa[Px2][Py2] == 'D' || J1_.tabuleiro_defesa[Px2][Py2] == 'P'){
      J1_.tabuleiro_defesa[Px2][Py2] = 'X';
      J2_.tabuleiro_ataque[Px2][Py2] = 'X';
      J1_.num_barcos --;
    }

    if(J1_.tabuleiro_defesa[Px2][Py2] == '~'){
      J2_.tabuleiro_ataque[Px2][Py2] = '0';
    }

    std::cout << '\n';

    std::cout << J2_.nome << ", aqui está o seu novo tabuleiro de ataque: " << '\n' << '\n';

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
