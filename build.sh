#!/bin/bash
rm chess.app
cd src
g++ -O0 -o ../chess.app Bispo.cpp Cavalo.cpp Dama.cpp Jogador.cpp Jogo.cpp Main.cpp Peao.cpp Peca.cpp Posicao.cpp Rei.cpp Tabuleiro.cpp Torre.cpp
