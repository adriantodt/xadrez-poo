#include <iostream>
#include <fstream>
#include "Dama.h"

using namespace std;

Dama::Dama(bool isBranco) : Peca(isBranco) {}

void Dama::desenha() {
    cout << (isBranco() ? "D" : "d");
}

bool Dama::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaDestino - colunaOrigem;
    return (offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna)) || ((offsetColuna == 0) != (offsetLinha == 0));
}

TipoPeca Dama::getTipo() {
    return dama;
}
