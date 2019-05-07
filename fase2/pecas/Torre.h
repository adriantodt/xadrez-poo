#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo torre.
 */
class Torre {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;

    /**
     * Constrói uma torre com base no tabuleiro e na cor.
     */
    Torre(Tabuleiro tabuleiro, bool branco);
    
    /**
     * Desenha a torre.
     */
    void desenha();
    
    /**
     * Checa a movimentação da torre pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};