#include <iostream>
#include "Rei.h"

using namespace std;

Rei::Rei(bool isBranco) : Peca(isBranco) {}

void Rei::desenha() {
    cout << (isBranco() ? "R" : "r");
}

bool Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // offset de movimentação
    int offL = linhaDestino - linhaOrigem;
    int offC = colunaDestino - colunaOrigem;

    // checagem de movimento e destino
    return ((offL != 0 || offC != 0) && (abs(offL <= 1) && abs(offC <= 1)));
}
