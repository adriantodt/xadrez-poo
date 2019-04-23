#include <iostream>
#include "Rei.h"

using namespace std;

Rei::Rei(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

void Rei::desenha() {
    cout << branco ? "R" : "r";
}

bool Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;

    int offL = linhaDestino - linhaOrigem;
    int offC = colunaDestino - colunaOrigem;

    return ((offL != 0 || offC != 0) && (abs(offL <= 1) && abs(offC <= 1)))
        && (tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco);
}