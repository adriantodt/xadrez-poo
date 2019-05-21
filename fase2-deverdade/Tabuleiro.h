#pragma once

#include "Posicao.h"

/**
 *  Essa classe gerencia o tabuleiro do jogo.
 */
class Tabuleiro {
private:
    Posicao** posicoes;

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
     * Checa a movimentacao de uma peça do tabuleiro,
     * retornando verdadeiro se a movimentacao é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};
