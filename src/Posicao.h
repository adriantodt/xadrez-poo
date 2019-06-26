#pragma once

#include "Peca.h"

/**
 * Salva o estado de uma posição do tabuleiro.
 */
class Posicao {
private:
    Peca* peca;
    char linha;
    int coluna;

public:
    /**
     * Cria uma nova posição do tabuleiro.
     */
    Posicao(char linha, int coluna);

    /**
     * Retorna a linha onde esta posição se encontra.
     */
    char getLinha();

    /**
     * Retorna a coluna onde esta posição se encontra.
     */
    int getColuna();

    /**
     * Retorna a peça que está nesta posição.
     */
    Peca* getPeca();

    /**
     * Define a peça que está nesta posição.
     */
    void setPeca(Peca *peca);
};
