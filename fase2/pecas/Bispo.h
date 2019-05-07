#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo bispo.
 */
class Bispo  {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    /**
     * Constrói um bispo com base no tabuleiro e na cor.
     */
    Bispo(Tabuleiro tabuleiro, bool branco);

    /**
     * Desenha o bispo.
     */
    void desenha();
    
    /**
     * Checa a movimentação do bispo pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};