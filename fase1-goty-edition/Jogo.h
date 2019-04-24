#pragma once

#include "Tabuleiro.h"

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
public:
    Tabuleiro tabuleiro;
};