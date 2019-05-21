#pragma once

#include "Peca.h"

/**
 * Representa uma peça do tipo peão.
 */
class Peao : public Peca {
public:
    Peao(bool isBranco);
    
    /**
     * Desenha a peça.
     */
    virtual void desenha();
    
    /**
     * Checa a movimentação da peça pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

};