#pragma once

#include "Posicao.h"

/**
 *  Essa classe gerencia o tabuleiro do jogo.
 */
class Tabuleiro {
private:
    Posicao** posicoes;

    /**
     * Encontra a posição (no vetor 'posicoes') onde o rei está;
     */
    int encontrarRei(bool branco);
public:
    /**
     * Constrói um tabuleiro vazio.
     */
    Tabuleiro();

    /**
     * Destrói o tabuleiro.
     */
    ~Tabuleiro();

    /**
     * Desenha o estado atual do tabuleiro.
     */
    void desenha();

    /**
      * Obtém uma posição do tabuleiro.
      */
    Posicao* getPosicao(int x, int y);
    
    /**
     * Checa a movimentacao de uma peça do tabuleiro,
     * retornando verdadeiro se a movimentacao é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

    /**
     * Checa se o movimento do rei pode causar um xeque.
     * Retorna verdadeiro se o movimento é seguro.
     */
    bool checaMoveXeque(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool branco);
    
    /**
     * Checa se o lado está em xeque (e possívelmente em xeque-mate)
     * Retorna verdadeiro se em xeque ou possível xeque-mate.
     */
    bool checaXeque(bool branco);

    /**
     * Assumindo que o lado está em xeque, checa se o lado está em xeque-mate.
     * Retorna verdadeiro se em xeque-mate.
     */
    bool checaXequeMate(bool branco);
};

