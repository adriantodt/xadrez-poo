#include<iostream>

using namespace std;

class Jogo {
};

class Jogador {
};

enum TipoPeca {
    vazio, rei, dama, cavalo, bispo, torre, peao
};

class Peca {
public:
    bool branco;
    bool capturada;

    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Posicao {
public:
    TipoPeca tipo;
    Peca peca;
    char linha;
    int coluna;
};

class Tabuleiro {
public:
    Posicao posicoes[8][8];

    void desenha() {
        cout << "  |1 2 3 4 5 6 7 8" << endl << "--+---------------" << endl;

        for (int y = 7; y >= 0; y--) {
            cout << (char)('A' + y) << " |";
            for (int x = 0; x < 8; x++) {
                Posicao p = posicoes[x][y];
                if (&(p.peca) != nullptr) {
                    p.peca.desenha();
                } else {
                    cout << ((x + y) % 2 == 0) ? "•" : "+";
                }
                cout << " ";
            }
            cout << endl;
        }
    }
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
        
        Posicao p = posicoes[linhaDestino][colunaDestino];
        if (&(p.peca) != nullptr) {
            return false;
        } else {
            return p.peca.checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        }
    }
};

class Rei {
public:
    bool branco;
    bool capturada;
    
    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Dama {
public:
    bool branco;
    bool capturada;
    
    void desenha() {
        cout << branco ? "D" : "d";
    }
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Cavalo {
public:
    bool branco;
    bool capturada;
    
    void desenha() {
        cout << branco ? "C" : "c";
    }
 
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Bispo {
public:
    bool branco;
    bool capturada;
    
    void desenha() {
        cout << branco ? "B" : "b";
    }
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Torre {
public:
    bool branco;
    bool capturada;
    
    void desenha() {
        cout << branco ? "T" : "t";
    }
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

class Peao {
public:
    bool branco;
    bool capturada;
    
    void desenha() {
        cout << branco ? "P" : "p";
    }
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        // off-bounds -> false
        if (linhaDestino < 0 || colunaDestino < 0 || linhaDestino > 7 || colunaDestino > 7) return false;
        
        // reorientar
        int moveLinhaOrigem = branco ? linhaOrigem : 7 - linhaOrigem;
        int moveColunaOrigem = branco ? colunaOrigem : 7 - colunaOrigem;
        int moveLinhaDestino = branco ? linhaDestino : 7 - linhaDestino;
        int moveColunaDestino = branco ? colunaDestino : 7 - colunaDestino;

        // offset de movimentação
        int offsetLinha = moveLinhaDestino - moveLinhaOrigem;
        int offsetColuna = moveColunaOrigem - moveColunaDestino;

        bool destinoOcupado = &(tabuleiro[linhaDestino][colunaDestino].peca) != nullptr;

        if (destinoOcupado && tabuleiro[linhaDestino][colunaDestino].peca.branco == this.branco) return false;

        //TODO MAPA K NESSES IF-ELSE

        // andar 2 casas no começo
        if (moveLinhaOrigem == 1 && moveLinhaDestino == 3 && offsetColuna == 0 && !destinoOcupado) return true;

        // andar 1 casa
        if (offsetColuna == 0 && offsetLinha == 1 && !destinoOcupado) return true;

        // comer peça
        if (offsetLinha == 1 && (offsetColuna == -1 || offsetColuna == 1) && destinoOcupado) return true;

        return false;
    }
};

int main() {
    Tabuleiro tabuleiro;
    tabuleiro.desenha();
    return 0;
}
