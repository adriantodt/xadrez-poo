#include <iostream>
#include "Bispo.h"

using namespace std;

Bispo::Bispo(bool isBranco) : Peca(isBranco) {}

void Bispo::desenha() {
    cout << (isBranco() ? "B" : "b");
}

bool Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;
    return offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna);
}
