#include<string>
#include<vector>

using namespace std;

enum Estado {
    inicio,
    em_jogo,
    xeque,
    em_xeque_mate,
    afogamento
};

class Jogo {
public:
    Jogador jogadorBranco;
    Jogador jogadorNegro;
    Tabuleiro tabuleiro;
    Estado estado;
    bool brancoJoga;
};

class Jogador {
public:
    string nome;
    Peca pecas[16];
    vector<Peca> pecasAtivas;
};

class Tabuleiro {
public:
    Posicao posicoes[8][8];
};

class Posicao {
public:
    char linha;
    int coluna;
    Peca peca;
};

class Peca {
public:
    bool branco;
    Tabuleiro tabuleiro;
    
    virtual bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    );

    virtual void desenha();
};

class Rei : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    ) {
        if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;

        int offL = linhaDestino - linhaOrigem;
        int offC = colunaDestino - colunaOrigem;
    
        return (offL != 0 || offC != 0) && (offL > 1 || offL < -1 || offC > 1 || offC < -1);
    }
};

class Dama : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    );
};

class Cavalo : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    );
    
};

class Bispo : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    );
    
};

class Torre : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    );
    
};

class Peao : public Peca {
public:
    bool checaMovimento(
        int linhaOrigem,
        int colunaOrigem,
        int linhaDestino,
        int colunaDestino
    ) {
        // off-bounds -> false
        if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) {
            return false;
        }

        // reorientar
        int moveLinhaOrigem = branco ? linhaOrigem : 7 - linhaOrigem;
        int moveColunaOrigem = branco ? colunaOrigem : 7 - colunaOrigem;
        int moveLinhaDestino = branco ? linhaDestino : 7 - linhaDestino;
        int moveColunaDestino = branco ? colunaDestino : 7 - colunaDestino;

        // offset de movimentação
        int offsetLinha = moveLinhaDestino - moveLinhaOrigem;
        int offsetColuna = moveColunaOrigem - moveColunaDestino;

        bool destinoOcupado = tabuleiro[linhaDestino][colunaDestino].peca != nullptr;


        //TODO MAPA K NESSES IF-ELSE

        // andar 2 casas no começo
        if (moveLinhaOrigem == 1 && moveLinhaDestino == 3 && offsetColuna == 0 && !destinoOcupado) {
            return true;
        }

        // andar 1 casa
        if (offsetColuna == 0 && offsetLinha == 1 && !destinoOcupado) {
            return true;
        }

        // comer peça
        if (offsetLinha == 1 && (offsetColuna == -1 || offsetColuna == 1) && destinoOcupado) {
            return true;
        }

        return false;
    }
};