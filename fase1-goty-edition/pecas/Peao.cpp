#include <iostream>
#include "Peao.h"

using namespace std;

/**
 * Constrói um peão com base no tabuleiro e na cor.
 */
Peao::Peao(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

/**
 * Desenha o peão.
 */
void Peao::desenha() {
    cout << (branco ? "P" : "p");
}

/**
 * Checa a movimentação do peão pelo tabuleiro,
 * retornando verdadeiro se a movimentação é válida.
 */
bool Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // reorientar
    int moveLinhaOrigem = branco ? linhaOrigem : 7 - linhaOrigem;
    int moveColunaOrigem = branco ? colunaOrigem : 7 - colunaOrigem;
    int moveLinhaDestino = branco ? linhaDestino : 7 - linhaDestino;
    int moveColunaDestino = branco ? colunaDestino : 7 - colunaDestino;

    // offset de movimentação
    int offsetLinha = moveLinhaDestino - moveLinhaOrigem;
    int offsetColuna = moveColunaOrigem - moveColunaDestino;

    bool destinoOcupado = tabuleiro.posicoes[linhaDestino][colunaDestino].tipo != vazio;

    // se destino ocupado
    if (destinoOcupado && tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco == branco) return false;

    // andar 2 casas no começo
    if (moveLinhaOrigem == 1 && moveLinhaDestino == 3 && offsetColuna == 0) {
        return tabuleiro.posicoes[linhaDestino + (branco ? 1 : -1)][colunaDestino].tipo == vazio && !destinoOcupado;
    }

    // andar 1 casa
    if (offsetColuna == 0 && offsetLinha == 1) return !destinoOcupado;

    // comer peça
    if (offsetLinha == 1 && (offsetColuna == -1 || offsetColuna == 1)) return destinoOcupado;

    return false;
}