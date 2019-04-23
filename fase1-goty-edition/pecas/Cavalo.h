#include "../Tabuleiro.h"

class Cavalo {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;

    Cavalo(Tabuleiro tabuleiro, bool branco);

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};