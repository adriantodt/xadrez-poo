#pragma once

#include <string>

#include "Tabuleiro.h"
#include "Jogador.h"

/**
 * Representa os estados do jogo.
 */
enum Estado {
	inicio, em_jogo_branco, em_jogo_preto, em_xeque_branco, em_xeque_preto, xeque_mate_branco, xeque_mate_preto
};

/**
 * Classe principal do jogo, que representa uma partida de xadrez.
 */
class Jogo {
private:
	Tabuleiro* tabuleiro;
	Peca** pecas;
	Jogador* jogador1;
	Jogador* jogador2;
	Estado estado;

    void ui_menuPrincipal();
    void ui_novoJogo();
    void ui_carregarJogo();
    void ui_sairDoJogo();
    void ui_jogando();
    void ui_salvarJogo();
    void ui_fimDoJogo();

    /**
     * Encontra a próxima peça capturada no vetor 'pecas'
     * Usado para carregar tabuleiros de jogos, que 'descaptura' as peças que estão presentes no tabuleiro.
     */
    Peca* encontrarProximaPeca(TipoPeca tipo, bool branco);
public:
	/**
	 * Cria um novo jogo de xadrez
	 */
	Jogo();

	/**
	 * Destrói os recursos associados a esse tabuleiro
	 */
	~Jogo();

	void executar();
};
