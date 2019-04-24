#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo peão.
 */
class Peao {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    /**
     * Constrói um peão com base no tabuleiro e na cor.
     */
    Peao(Tabuleiro tabuleiro, bool branco);

    /**
     * Desenha o peão.
     */
    void desenha();
    
    /**
     * Checa a movimentação do peão pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};