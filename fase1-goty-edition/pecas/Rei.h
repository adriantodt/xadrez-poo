#include "../Tabuleiro.h"

class Rei {
public:
    Tabuleiro tabuleiro;
    bool branco;
    bool capturada;

    Rei(Tabuleiro tabuleiro, bool branco);
    
    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};