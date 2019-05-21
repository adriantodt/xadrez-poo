#include <iostream>
#include "Dama.h"

using namespace std;

Dama::Dama(bool isBranco) : Peca(isBranco) {}

void Dama::desenha() {
    cout << (isBranco() ? "D" : "d");
}

bool Dama::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;
    return (offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna)) || ((offsetColuna == 0) != (offsetLinha == 0));
}
