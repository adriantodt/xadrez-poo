#include <iostream>
#include "Dama.h"

using namespace std;

void Dama::desenha() {
    cout << branco ? "D" : "d";
}

bool Dama::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // offset de movimentação
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;

    int l = offsetLinha / abs(offsetLinha);
    int c = offsetColuna / abs(offsetColuna);

    if (offsetColuna == 0 && offsetLinha != 0) {
        for(int i = linhaOrigem + l; i != linhaDestino; i += l) {
            if (tabuleiro.posicoes[i][colunaDestino].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else if (offsetColuna != 0 && offsetLinha == 0) {
        for(int i = colunaOrigem + c; i != colunaDestino; i += c) {
            if (tabuleiro.posicoes[linhaDestino][i].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else if (offsetColuna != 0 && offsetLinha != 0 && abs(offsetLinha) == abs(offsetColuna)) {
        for (int i = linhaOrigem + l, j = colunaOrigem + c; i != linhaDestino && j != colunaDestino; i += l, j += c) {
            if (tabuleiro.posicoes[i][j].tipo != vazio) return false;
        }
        
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    } else {
        return false;
    }
}