#include "Posicao.h"

class Tabuleiro {
public:
    Posicao posicoes[8][8];

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};
