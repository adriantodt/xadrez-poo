#pragma once

#include "Peca.h"

class Posicao {
public:
    TipoPeca tipo;
    Peca peca;
    char linha;
    int coluna;

    Posicao();
    Posicao(char linha, int coluna);
};