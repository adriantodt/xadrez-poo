#include <iostream>
#include <fstream>
#include "Tabuleiro.h"

#include <unistd.h>


using namespace std;

Tabuleiro::Tabuleiro() {
    posicoes = new Posicao*[64];

    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            posicoes[l + c * 8] = new Posicao(l + 'A', c + 1);
        }
    }
}

Tabuleiro::~Tabuleiro() {
    for (int i = 0; i < 64; i++) {
        delete posicoes[i];
    }
    delete posicoes;
}


Posicao* Tabuleiro::getPosicao(int x, int y) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        throw "Posição inválida.";
    }

    return posicoes[x + y * 8];
}

void Tabuleiro::desenha() {
    cout << " ┌──┬───────────────┬──┐" << endl;
    cout << " │  │A B C D E F G H│  │" << endl;
    cout << " ├──┼───────────────┼──┤" << endl;

    for (int y = 7; y >= 0; y--) {
        cout << " │" << (char)('1' + y) << " │";
        for (int x = 0; x < 8; x++) {
            Posicao* pos = posicoes[x + y * 8];
            Peca *p = pos->getPeca();
            if (p) {
                p->desenha();
            } else {
                cout << (((x + y) % 2 == 0) ? "•" : "+");
            }
            if (x < 7) cout << " ";
        }
        cout << "│ " << (char)('1' + y) << "│" << endl;
    }

    cout << " ├──┼───────────────┼──┤" << endl;
    cout << " │  │A B C D E F G H│  │" << endl;
    cout << " └──┴───────────────┴──┘" << endl;
}

int sgn(int v) {
    return (v > 0) ? 1 : ((v < 0) ? -1 : 0);
}
    
bool Tabuleiro::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Posicao* origem = getPosicao(linhaOrigem, colunaOrigem);
    Posicao* destino = getPosicao(linhaDestino, colunaDestino);
    Peca* pecaOrigem = origem->getPeca();
    Peca* pecaDestino = destino->getPeca();

    if (pecaOrigem == NULL) {
        throw "Não existe peça na posição indicada.";
    }

    if (!pecaOrigem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) return false;

    TipoPeca tipo = pecaOrigem->getTipo();

    if (tipo == bispo || tipo == dama || tipo == torre) {
        int l = sgn(linhaDestino - linhaOrigem);
        int c = sgn(colunaDestino - colunaOrigem);
        for (int i = linhaOrigem + l, j = colunaOrigem + c; i != linhaDestino || j != colunaDestino; i += l, j += c) {
            if (getPosicao(i, j)->getPeca() != NULL) return false;
        }
    } else if (tipo == peao) {
        int absOffLinha = abs(linhaDestino - linhaOrigem);
        int absOffColuna = abs(colunaDestino - colunaOrigem);

        if ((absOffLinha == 0) != (pecaDestino == NULL)) return false;
    } else if (tipo == rei) {
        int l = sgn(linhaDestino - linhaOrigem);
        int c = sgn(colunaDestino - colunaOrigem);
        for (int i = linhaOrigem + l, j = colunaOrigem + c; i != linhaDestino || j != colunaDestino; i += l, j += c) {
            if (getPosicao(i, j)->getPeca() != NULL) return false;
        }
        if (!checaMoveXeque(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, pecaOrigem->isBranco())) return false;
    }

    if (pecaDestino == NULL) return true;

    if (pecaOrigem->isBranco() == pecaDestino->isBranco()) return false;

    return true;
}

int Tabuleiro::encontrarRei(bool branco) {
    for (int i = 0; i < 64; i++) {
        Posicao* p = posicoes[i];
        if (p->getPeca() != NULL && p->getPeca()->getTipo() == rei) return i;
    }
    throw "Rei não está no Tabuleiro";
}

bool Tabuleiro::checaMoveXeque(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool branco) {
    Posicao* origem = getPosicao(linhaOrigem, colunaOrigem);
    Posicao* destino = getPosicao(linhaDestino, colunaDestino);
    Peca* pecaOrigem = origem->getPeca();
    Peca* pecaDestino = destino->getPeca();

    if (pecaOrigem == NULL) {
        throw "Não existe peça na origem.";
    }

    if (pecaDestino != NULL && pecaOrigem->isBranco() == pecaDestino->isBranco()) {
        return false;
    }

    destino->setPeca(pecaOrigem);
    origem->setPeca(NULL);

    int colunaRei = encontrarRei(branco);
    int linhaRei = colunaRei % 8;
    colunaRei = colunaRei / 8;

    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            Posicao* pos = getPosicao(l,c);

            if (
                (l != linhaRei || c != colunaRei)
                && pos->getPeca() != NULL
                && pos->getPeca()->isBranco() != branco
                && checaMovimento(l, c, linhaRei, colunaRei)
            ) {
                // debug
                Posicao* posRei = getPosicao(linhaRei,colunaRei);
                std::string tipos[] = { "bispo", "cavalo", "dama", "peao", "rei", "torre" };
                cerr << tipos[pos->getPeca()->getTipo()] << " at " << pos->getLinha() << pos->getColuna() << " can check king at " << posRei->getLinha() << posRei->getColuna() << endl;

                origem->setPeca(pecaOrigem);
                destino->setPeca(pecaDestino);
                return false;
            }
        }
    }

    origem->setPeca(pecaOrigem);
    destino->setPeca(pecaDestino);
    return true;
}

bool Tabuleiro::checaXeque(bool branco) {
    int colunaRei = encontrarRei(branco);
    int linhaRei = colunaRei % 8;
    colunaRei = colunaRei / 8;

    Posicao* r = getPosicao(linhaRei, colunaRei);
    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            Posicao* pos = getPosicao(l,c);

            if (
                (l != linhaRei || c != colunaRei)
                && pos->getPeca() != NULL
                && pos->getPeca()->isBranco() != branco
                && checaMovimento(l, c, linhaRei, colunaRei)
            ) return true;
        }
    }

    return false;
}

bool Tabuleiro::checaXequeMate(bool branco) {
    int colunaRei = encontrarRei(branco);
    int linhaRei = colunaRei % 8;
    colunaRei = colunaRei / 8;
    
    for (int c = -1; c <= 1; c++) {
        for (int l = -1; l <= 1; l++) {
            if (c != 0 || l != 0) {
                int linhaDestino = linhaRei + l;
                int colunaDestino = colunaRei + c;
                if (linhaDestino >= 0 && linhaDestino <= 8 && colunaDestino >= 0 && colunaDestino <= 8) {
                    Posicao* pos = getPosicao(linhaDestino, colunaDestino);
                    if (pos->getPeca() != NULL && checaMoveXeque(linhaRei, colunaRei, linhaDestino, colunaDestino, branco)) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}


