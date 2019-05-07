#pragma once

#include "Peça.h"

/**
 * Salva o estado de uma posição do tabuleiro.
 */
class Posição {
private:
    Peça* peça;
    char linha;
    int coluna;
public:
    /**
     * Cria uma nova posição do tabuleiro.
     */
    Posição(char linha, int coluna);

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
    Peça* getPeça();

    /**
     * Define a peça que está nesta posição.
     */
    void setPeça(Peça *peça);
};