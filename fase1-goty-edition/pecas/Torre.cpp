
/**
 * Checa a movimentação da torre pelo tabuleiro,
 * retornando verdadeiro se a movimentação é válida.
 */#include <iostream>
#include "Torre.h"
#include "../lib/mathutils.h"

using namespace std;

/**
 * Constrói uma torre com base no tabuleiro e na cor.
 */
Torre::Torre(Tabuleiro _tabuleiro, bool _branco) {
    tabuleiro = _tabuleiro;
    branco = _branco;
}

/**
 * Desenha a torre.
 */
void Torre::desenha() {
    cout << (branco ? "T" : "t");
}

/**
 * Checa a movimentação da torre pelo tabuleiro,
 * retornando verdadeiro se a movimentação é válida.
 */
bool Torre::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    // off-bounds -> false
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    // offset de movimentação
    int offsetLinha = linhaDestino - linhaOrigem;
    int offsetColuna = colunaOrigem - colunaDestino;

    int l = sgn(offsetLinha);
    int c = sgn(offsetColuna);

    // validação de movimento
    if ((offsetColuna == 0) != (offsetLinha == 0)) {
        // checagem do caminho
        for (int i = linhaOrigem + l, j = colunaOrigem + c; i != linhaDestino && j != colunaDestino; i += l, j += c) {
            if (tabuleiro.posicoes[i][j].tipo != vazio) return false;
        }
        
        //checagem do destino
        return tabuleiro.posicoes[linhaDestino][colunaDestino].tipo == vazio || tabuleiro.posicoes[linhaDestino][colunaDestino].peca.branco != branco;
    }

    return false;
}