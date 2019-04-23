#!/bin/bash
g++ Peca.cpp Posicao.cpp Tabuleiro.cpp \
    pecas/Bispo.cpp pecas/Cavalo.cpp pecas/Dama.cpp pecas/Peao.cpp pecas/Rei.cpp pecas/Torre.cpp \
    testes/sandbox.cpp \
    -o teste