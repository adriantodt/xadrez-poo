#include <iostream>
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
    int offsetColuna = moveColunaOrigem - moveColunaDestino;

    return (moveLinhaOrigem == 1 && moveLinhaDestino == 3 && offsetColuna == 0)
        || (offsetColuna == 0 && offsetLinha == 1)
        || (offsetLinha == 1 && (offsetColuna == -1 || offsetColuna == 1));
}
