#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo rei.
 */
class Rei {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;

    /**
     * Constrói um rei com base no tabuleiro e na cor.
     */
    Rei(Tabuleiro tabuleiro, bool branco);
    
    /**
     * Desenha o rei.
     */
    void desenha();
    
    /**
     * Checa a movimentação do rei pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};