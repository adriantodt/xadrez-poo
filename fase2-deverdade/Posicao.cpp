#include "Posicao.h"

Posicao::Posicao(char _linha, int _coluna) {
    linha = _linha;
    coluna = _coluna;
}

char Posicao::getLinha() {
    return linha;
}

int Posicao::getColuna() {
    return coluna;
}

Peca* Posicao::getPeca() {
    return peca;
}

void Posicao::setPeca(Peca *_peca) {
    peca = _peca;
}