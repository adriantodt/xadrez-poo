#include <iostream>
#include <fstream>
#include "Cavalo.h"

using namespace std;

Cavalo::Cavalo(bool isBranco) : Peca(isBranco) {}

void Cavalo::desenha() {
    cout << (isBranco() ? "C" : "c");
}

bool Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    int absOffsetLinha = abs(linhaDestino - linhaOrigem);
    int absOffsetColuna = abs(colunaDestino - colunaOrigem);
    return (absOffsetColuna == 2 && absOffsetLinha == 1) || (absOffsetLinha == 2 && absOffsetColuna == 1);
}

TipoPeca Cavalo::getTipo() {
    return cavalo;
}
