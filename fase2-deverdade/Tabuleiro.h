#pragma once

#include "Posição.h"

/**
 *  Essa classe gerencia o tabuleiro do jogo.
 */
class Tabuleiro {
    Posição* posições;
public:

    /**
     * Constrói um tabuleiro vazio.
     */
    Tabuleiro();

    /**
     * Destrói o tabuleiro.
     */
    ~Tabuleiro();

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
