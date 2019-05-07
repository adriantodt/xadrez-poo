#pragma once

#include "Posicao.h"

/**
 *  Essa classe gerencia o tabuleiro do jogo.
 */
class Tabuleiro {
public:
    Posicao posicoes[8][8];

    /**
     * Constrói um tabuleiro vazio.
     */
    Tabuleiro();

    /**
     * Desenha o estado atual do tabuleiro.
     */
    void desenha();
    
    /**
     * Checa a movimentação de uma peça do tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};
