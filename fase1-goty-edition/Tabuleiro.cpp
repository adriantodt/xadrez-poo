#include <iostream>
#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro() {
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            Posicao p = posicoes[i][j];
            p.linha = (char)('A' + i);
            p.coluna = j + 1;
        }
    }
}

void Tabuleiro::desenha() {
    cout << "  |1 2 3 4 5 6 7 8" << endl << "--+---------------" << endl;

    for (int y = 7; y >= 0; y--) {
        cout << (char)('A' + y) << " |";
        for (int x = 0; x < 8; x++) {
            Posicao p = posicoes[x][y];
            if (p.tipo != vazio) {
                p.peca.desenha();
            } else {
                cout << (((x + y) % 2 == 0) ? "•" : "+");
            }
            cout << " ";
        }
        cout << endl;
    }
}

bool Tabuleiro::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
    
    Posicao p = posicoes[linhaDestino][colunaDestino];
    if (p.tipo == vazio) {
        return false;
    } else {
        return p.peca.checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
    }
}