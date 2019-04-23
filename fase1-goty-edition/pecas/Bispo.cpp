#include <iostream>
#include "Bispo.h"

using namespace std;

Bispo::Bispo(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

void Bispo::desenha() {
    cout << branco ? "B" : "b";
}

bool Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // offset de movimentação
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;

    int l = offsetLinha / abs(offsetLinha);
    int c = offsetColuna / abs(offsetColuna);

    if (offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna)) {
        for (int i = linhaOrigem + l, j = colunaOrigem + c; i != linhaDestino && j != colunaDestino; i += l, j += c) {
            if (tabuleiro.posicoes[i][j].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else {
        return false;
    }
}