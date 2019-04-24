#pragma once

#include "Tabuleiro.h"

enum Estado {
    inicio,
    em_jogo,
    xeque,
    em_xeque_mate,
    afogamento
};

class Jogo {
public:
    Tabuleiro tabuleiro;
};