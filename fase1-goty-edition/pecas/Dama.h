#include "Tabuleiro.h"

class Dama {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    Dama(Tabuleiro tabuleiro, bool branco);

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};