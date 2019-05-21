#include <iostream>
#include "Torre.h"

using namespace std;

Torre::Torre(bool isBranco) : Peca(isBranco) {}

void Torre::desenha() {
    cout << (isBranco() ? "T" : "t");
}

bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;

    return (offsetColuna == 0) != (offsetLinha == 0);
}
