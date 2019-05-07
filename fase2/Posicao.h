#pragma once

#include "Peca.h"

/**
 * Salva o estado de uma posição do tabuleiro.
 */
class Posicao {
public:
    TipoPeca tipo;
    Peca peca;
    char linha;
    int coluna;
};