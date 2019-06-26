#include <iostream>
#include <fstream>
#include "Bispo.h"

using namespace std;

Bispo::Bispo(bool isBranco) : Peca(isBranco) {}

void Bispo::desenha() {
    cout << (isBranco() ? "B" : "b");
}

bool Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaDestino - colunaOrigem;
    return offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna);
}

TipoPeca Bispo::getTipo() {
    return bispo;
}
