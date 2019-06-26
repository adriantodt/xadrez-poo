#include <iostream>
#include <fstream>
#include "Peao.h"

using namespace std;

Peao::Peao(bool isBranco) : Peca(isBranco) {}

void Peao::desenha() {
    cout << (isBranco() ? "P" : "p");
}

bool Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // reorientar
    int moveLinhaOrigem = isBranco() ? linhaOrigem : 7 - linhaOrigem;
    int moveColunaOrigem = isBranco() ? colunaOrigem : 7 - colunaOrigem;
    int moveLinhaDestino = isBranco() ? linhaDestino : 7 - linhaDestino;
    int moveColunaDestino = isBranco() ? colunaDestino : 7 - colunaDestino;

    // offset de movimentação
    int offsetLinha = moveLinhaDestino - moveLinhaOrigem;
    int offsetColuna = moveColunaDestino - moveColunaOrigem;

    return (moveColunaOrigem == 1 && moveColunaDestino == 3 && offsetLinha == 0)
        || (offsetLinha == 0 && offsetColuna == 1)
        || (offsetColuna == 1 && abs(offsetLinha) == 1);
}

TipoPeca Peao::getTipo() {
    return peao;
}
