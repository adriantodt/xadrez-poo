#include <iostream>
#include "Cavalo.h"

using namespace std;

Cavalo::Cavalo(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

void Cavalo::desenha() {
    cout << (branco ? "C" : "c");
}

bool Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // offset de movimentação
    int absOffsetLinha = abs(linhaDestino - linhaOrigem);
    int absOffsetColuna = abs(colunaOrigem - colunaDestino);

    // validação de movimento
    if ((absOffsetColuna == 2 && absOffsetLinha == 1) || (absOffsetLinha == 2 && absOffsetColuna == 1)) {
        //checagem do destino
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    }
    
    return false;
}