#pragma once

#include "Jogo.h"
#include "pecas/Rei.h"
#include "pecas/Dama.h"
#include "pecas/Cavalo.h"
#include "pecas/Bispo.h"
#include "pecas/Torre.h"
#include "pecas/Peao.h"

using namespace std;

Jogo::Jogo(string nomeJogador1, string nomeJogador2) {
    tabuleiro = new Tabuleiro();
    pecas = new Peca*[24];
    jogador1 = new Jogador(nomeJogador1);
    jogador2 = new Jogador(nomeJogador2);
    for(int i = 0; i < 24; i++) {
        
    }
    
    
}

Jogo::~Jogo() {
    delete tabuleiro;
    delete pecas;
    delete jogador1;
    delete jogador2;
}