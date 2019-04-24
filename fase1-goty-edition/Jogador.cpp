#include "Jogador.h"

/**
 * Constrói um jogador com o nome em branco.
 */
Jogador::Jogador() {
    nome = "";
}

/**
 * Constrói um jogador com o nome definido.
 */
Jogador::Jogador(string _nome) {
    nome = _nome;
}