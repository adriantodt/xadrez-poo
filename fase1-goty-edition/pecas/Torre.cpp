#include <iostream>
#include "Torre.h"

using namespace std;

Torre::Torre(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

void Torre::desenha() {
    cout << branco ? "T" : "t";
}

bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // offset de movimentação
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;

    int d;

    if (offsetColuna == 0 && offsetLinha != 0) {
        d = offsetLinha / abs(offsetLinha);

        for(int i = linhaOrigem + d; i != linhaDestino; i += d) {
            if (tabuleiro.posicoes[i][colunaDestino].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else if (offsetColuna != 0 && offsetLinha == 0) {
        d = offsetColuna / abs(offsetColuna);

        for(int i = colunaOrigem + d; i != colunaDestino; i += d) {
            if (tabuleiro.posicoes[linhaDestino][i].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else {
        return false;
    }
}