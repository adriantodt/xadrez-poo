#pragma once

#include<string>

using namespace std;

/**
 * Representa um dos jogadores do jogo.
 */
class Jogador {
private:
    string nome;

public:
    /**
     * Constrói um jogador com o nome em branco.
     */
    Jogador();
    
    /**
     * Constrói um jogador com o nome definido.
     */
    Jogador(string nome);

    /**
     * Retorna o nome do jogador
     */
    string getNome();
};