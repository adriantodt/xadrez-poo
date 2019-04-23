#pragma once

enum TipoPeca {
    vazio, rei, dama, cavalo, bispo, torre, peao
};

class Peca {
public:
    bool branco;
    bool capturada;

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};
