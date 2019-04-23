#include "Posicao.h"

Posicao::Posicao() {
    tipo = vazio;
}

Posicao::Posicao(char _linha, int _coluna) {
    linha = _linha;
    coluna = _coluna;
    tipo = vazio;
}