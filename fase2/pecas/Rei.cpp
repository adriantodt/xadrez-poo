#include <iostream>
#include "Rei.h"

using namespace std;

/**
 * Constrói um rei com base no tabuleiro e na cor.
 */
Rei::Rei(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

/**
 * Desenha o rei.
 */
void Rei::desenha() {
    cout << (branco ? "R" : "r");
}

/**
 * Checa a movimentação do rei pelo tabuleiro,
 * retornando verdadeiro se a movimentação é válida.
 */
bool Rei::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;

    // offset de movimentação
    int offL = linhaDestino - linhaOrigem;
    int offC = colunaDestino - colunaOrigem;

    // checagem de movimento e destino
    return ((offL != 0 || offC != 0) && (abs(offL <= 1) && abs(offC <= 1)))
        && (tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco);
}