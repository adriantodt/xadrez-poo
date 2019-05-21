#include <iostream>
#include "Tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro() {
    posicoes = new Posicao*[64];

    for (int i = 0; i < 64; i++) {
        posicoes[i] = new Posicao(i % 8 + 'A', i / 8);
    }
}

Tabuleiro::~Tabuleiro() {
    for (int i = 0; i < 64; i++) {
        delete posicoes[i];
    }
    delete posicoes;
}

void Tabuleiro::desenha() {
    cout << "  |1 2 3 4 5 6 7 8" << endl << "--+---------------" << endl;

    for (int y = 7; y >= 0; y--) {
        cout << (char)('A' + y) << " |";
        for (int x = 0; x < 8; x++) {
            Posicao* pos = posicoes[x + y * 8];
            Peca *p = pos->getPeca();
            if (p) {
                p->desenha();
            } else {
                cout << (((x + y) % 2 == 0) ? "•" : "+");
            }
            cout << " ";
        }
        cout << endl;
    }
}
    
bool Tabuleiro::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    return false; //TODO
}
