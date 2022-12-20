#include <iostream>
#include <string>
#include "jogador.hpp"
#include "texto.hpp"

int main() {

std::string Linha;
std::string Barra;
    
boas_vindas();
setar_linha_barra(Linha, Barra);

Jogador J1, J2;
std::cout << '\n' << '\n' << "Digite o nome dos jogadores participantes: " << '\n' << '\n' << "1)";
std::cin >> J1.nome;
std::cout << '\n'<< "2)";
std::cin >> J2.nome;

std::cout << '\n' << Linha << '\n' ;
  
alocar_barcos(J1);

std::cout << '\n' << Linha << '\n' ;

alocar_barcos(J2); 

std::cout << '\n' << "Vamos dar início ao posicionamento das peças no tabuleiro!" << '\n' << '\n';

  J1.num_barcos = J1.num_submarino + J1.num_cruzador + J1.num_destroyer + J1.num_p_avioes;
  J2.num_barcos = J2.num_submarino + J2.num_cruzador + J2.num_destroyer + J2.num_p_avioes;

montar_tabuleiro(J1);

montar_tabuleiro(J2);
  
posicionar_barcos(J1);

posicionar_barcos(J2);

jogadas(J1, J2);

fim_do_jogo();
  
  return 0;
}
