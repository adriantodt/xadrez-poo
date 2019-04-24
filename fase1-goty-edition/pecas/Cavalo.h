#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo cavalo.
 */
class Cavalo {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;

    /**
     * Constrói um cavalo com base no tabuleiro e na cor.
     */
    Cavalo(Tabuleiro tabuleiro, bool branco);

    /**
     * Desenha o cavalo.
     */
    void desenha();
    
    /**
     * Checa a movimentação do cavalo pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};