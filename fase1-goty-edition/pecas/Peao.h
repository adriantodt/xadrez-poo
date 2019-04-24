#pragma once

#include "../Tabuleiro.h"

class Peao {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    Peao(Tabuleiro tabuleiro, bool branco);

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};