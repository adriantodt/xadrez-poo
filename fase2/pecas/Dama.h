#pragma once

#include "../Tabuleiro.h"

/**
 * Representa uma peça do tipo dama.
 */
class Dama {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    /**
     * Constrói uma dama com base no tabuleiro e na cor.
     */
    Dama(Tabuleiro tabuleiro, bool branco);

    /**
     * Desenha a dama.
     */
    void desenha();
    
    /**
     * Checa a movimentação da dama pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};