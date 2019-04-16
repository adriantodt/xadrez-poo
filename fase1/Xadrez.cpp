#include<iostream>

using namespace std;

class Jogo {
};

class Jogador {
};

class Peca {
public:
    void desenha();
    
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);

};

class Posicao {
public:
    Peca peca;
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
        
        Posicao p = posicoes[x][y];
        if (&(p.peca) != nullptr) {
            return false;
        } else {
            return p.peca.checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino);
        }
    }
};

class Rei {
};

class Dama {
};

class Cavalo {
};

class Bispo {
};

class Torre {
};

class Peao {
};

int main() {
    Tabuleiro tabuleiro;
    tabuleiro.desenha();
    return 0;
}
