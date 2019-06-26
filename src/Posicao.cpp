#include <fstream>
#include "Posicao.h"

Posicao::Posicao(char _linha, int _coluna) {
    linha = _linha;
    coluna = _coluna;
    peca = nullptr;
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

std::ifstream & operator>>(std::ifstream & is, Posicao *& obj) {
    is.read(reinterpret_cast<char*>(obj), sizeof(Posicao));
    return is;    
}

std::ofstream & operator<<(std::ofstream & os, const Posicao *& obj) {
    os.write(reinterpret_cast<const char*>(obj), sizeof(Posicao));
    return os;
}
