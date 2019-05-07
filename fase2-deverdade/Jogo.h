#pragma once

#include <string>
#include "Tabuleiro.h"
#include "Jogador.h"

/**
 * Classe principal do jogo, que representa uma partida de xadrez.
 */
class Jogo {
private:
    Tabuleiro* tabuleiro;
    Peça** peças;
    Jogador* jogador1;
    Jogador* jogador2; 
public:
    /**
     * Cria um novo jogo de xadrez
     */
    Jogo(string nomeJogador1, string nomeJogador2);

    /**
     * Destrói os recursos associados a esse tabuleiro
     */
    ~Jogo();
};