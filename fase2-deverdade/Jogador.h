#pragma once

#include<string>
#include "Peca.h"

using namespace std;

/**
 * Representa um dos jogadores do jogo.
 */
class Jogador {
private:
    string nome;
    Peca** pecas;

public:
    /**
     * Constrói um jogador com o nome definido.
     */
    Jogador(string nome);

    /**
     * Destrói o jogador.
     */
    ~Jogador();

    /**
     * Retorna o nome do jogador.
     */
    string getNome();

    /**
     * Põe a peça na posição definida.
     */
    void setPeca(int pos, Peca *_peca);
};