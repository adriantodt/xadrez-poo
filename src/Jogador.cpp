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

