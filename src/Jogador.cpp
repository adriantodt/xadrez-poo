#include <fstream>
#include "Jogador.h"

Jogador::Jogador(string _nome) : nome(_nome) {
    pecas = new Peca*[12];
}

Jogador::~Jogador() {
    delete pecas;
}

string Jogador::getNome() {
    return nome;
}

void Jogador::setPeca(int pos, Peca *_peca) {
    pecas[pos] = _peca;
}

std::ifstream & operator>>(std::ifstream & is, Jogador *& obj) {
    is.read(reinterpret_cast<char*>(obj), sizeof(Jogador));
    return is;
}

std::ofstream & operator<<(std::ofstream & os, const Jogador *& obj) {
    os.write(reinterpret_cast<const char*>(obj), sizeof(Jogador));
    return os;
}
