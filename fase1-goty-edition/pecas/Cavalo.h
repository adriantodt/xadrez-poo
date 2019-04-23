#include "Tabuleiro.h"

class Cavalo {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;
    
    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};