#include <iostream>
#include "Peao.h"

using namespace std;

Peao::Peao(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

void Peao::desenha() {
    cout << branco ? "P" : "p";
}

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

    if (destinoOcupado && tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco == branco) return false;

    //TODO MAPA K NESSES IF-ELSE

    // andar 2 casas no começo
    if (moveLinhaOrigem == 1 && moveLinhaDestino == 3 && offsetColuna == 0 && !destinoOcupado) return true;

    // andar 1 casa
    if (offsetColuna == 0 && offsetLinha == 1 && !destinoOcupado) return true;

    // comer peça
    if (offsetLinha == 1 && (offsetColuna == -1 || offsetColuna == 1) && destinoOcupado) return true;

    return false;
}