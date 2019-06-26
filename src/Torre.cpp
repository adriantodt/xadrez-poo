#include <iostream>
#include <fstream>
#include "Torre.h"

using namespace std;

Torre::Torre(bool isBranco) : Peca(isBranco) {}

void Torre::desenha() {
    cout << (isBranco() ? "T" : "t");
}

bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaDestino - colunaOrigem;

    return (offsetColuna == 0) != (offsetLinha == 0);
}

TipoPeca Torre::getTipo() {
    return torre;
}
