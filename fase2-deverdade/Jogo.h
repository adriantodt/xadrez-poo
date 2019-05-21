#pragma once

#include <string>

#include "Tabuleiro.h"
#include "Jogador.h"

#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"

/**
 * Representa os estados do jogo.
 */
enum Estado {
    inicio,
    em_jogo,
    xeque,
    em_xeque_mate,
    afogamento
};

/**
 * Classe principal do jogo, que representa uma partida de xadrez.
 */
class Jogo {
private:
    Tabuleiro* tabuleiro;
    Peca** peças;
    Jogador* jogador1;
    Jogador* jogador2;
    Estado estado;

public:
    /**
     * Cria um novo jogo de xadrez
     */
    Jogo();

    /**
     * Destrói os recursos associados a esse tabuleiro
     */
    ~Jogo();

    void executar();
};