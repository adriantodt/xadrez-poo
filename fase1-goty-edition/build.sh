#!/bin/bash
g++ lib/Vetor.cpp lib/mathutils.cpp \
    Peca.cpp Tabuleiro.cpp Jogador.cpp \
    pecas/Bispo.cpp pecas/Cavalo.cpp pecas/Dama.cpp pecas/Peao.cpp pecas/Rei.cpp pecas/Torre.cpp \
    Main.cpp \
    -o chess.app