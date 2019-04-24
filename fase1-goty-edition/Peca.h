#pragma once

/**
 * Representa todos os tipos de peça, incluindo o caso de não haver uma peça.
 */
enum TipoPeca {
    vazio, rei, dama, cavalo, bispo, torre, peao
};

/**
 * Representa uma peça do tabuleiro.
 */
class Peca {
public:
    bool branco;
    bool capturada;

    /**
     * Desenha a peça.
     */
    void desenha();
    
    /**
     * Checa a movimentação da peça pelo tabuleiro,
     * retornando verdadeiro se a movimentação é válida.
     */
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};
