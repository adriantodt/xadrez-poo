#pragma once

#include<string>

using namespace std;

/**
 * Representa um dos jogadores do jogo.
 */
class Jogador {
public:
    string nome;

    /**
     * Constrói um jogador com o nome em branco.
     */
    Jogador();
    
    /**
     * Constrói um jogador com o nome definido.
     */
    Jogador(string nome);
};