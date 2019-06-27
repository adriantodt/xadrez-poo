#include "Jogo.h"

#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"

#include <iostream>
#include <fstream>
#include <limits>
#include <ctype.h>
#include <unistd.h>

std::string ver = "1.0";

using namespace std;

Jogo::Jogo() {
	estado = inicio;
	jogador1 = NULL;
	jogador2 = NULL;

    try {
	    tabuleiro = new Tabuleiro;

	    pecas = new Peca*[32];

	    int i = 0;
	    for (int branco = 1; branco >= 0; branco--) {
		    pecas[i++] = new Torre(branco);
		    pecas[i++] = new Cavalo(branco);
		    pecas[i++] = new Bispo(branco);
		    pecas[i++] = new Rei(branco);
		    pecas[i++] = new Dama(branco);
		    pecas[i++] = new Bispo(branco);
		    pecas[i++] = new Cavalo(branco);
		    pecas[i++] = new Torre(branco);

		    for (int j = 0; j < 8; j++) {
			    pecas[i++] = new Peao(branco);
		    }
	    }
    }
    catch (const std::bad_alloc&) {
        if (tabuleiro) delete tabuleiro;
	    if (pecas) {
            for (int i = 0; i < 32; i++) {
		        if (pecas[i]) delete pecas[i];
        	}
            delete pecas;
    	}
        throw "Falta de Memória.";
    }
}

Jogo::~Jogo() {
	if (jogador1) {
		delete jogador1;
	}
	if (jogador2) {
		delete jogador2;
	}
    if (tabuleiro) {
        delete tabuleiro;
    }
    if (pecas) {
    	for (int i = 0; i < 32; i++) {
	    	delete pecas[i];
	    }
	    delete pecas;
    }
}

void cls() {
	std::cout << "\x1B[2J\x1B[H";
}


Peca* Jogo::encontrarProximaPeca(TipoPeca tipo, bool branco) {
    for (int i = 0; i < 32; i++) {
        Peca* p = pecas[i];
        if (p->getTipo() == tipo && p->isBranco() == branco && p->isCapturada()) {
            p->setCapturada(false);
            return p;
        }
    }
    
    throw "Peça não encontrada!";
}

void Jogo::ui_menuPrincipal() {
	while (true) {
		cls();
		cout << endl;
		cout << " ┌──┤ Xadrez ├──────────────────────────┐" << endl;
		cout << " │                                      │ [ver " << ver << "]" << endl;
		cout << " │ [n] Iniciar um novo jogo             │" << endl;
		cout << " │                                      │" << endl;
		cout << " │ [l] Carregar um jogo em progresso    │" << endl;
		cout << " │                                      │" << endl;
		cout << " │ [q] Sair do jogo                     │" << endl;
		cout << " │                                      │" << endl;
		cout << " └┬─────────────────────────────────────┘" << endl;
		cout << "  └> ";
        char c = tolower(cin.get());
        cin.clear();

		if (c == 'n') {
			ui_novoJogo();
            return;
		} else if (c == 'l') {
			ui_carregarJogo();
            return;
		} else if (c == 'q') {
			ui_sairDoJogo();
            return;
		}
    }
}

void Jogo::ui_novoJogo() {
    cls();
    cout << endl;
	cout << " ┌──┤ Xadrez - Novo Jogo" << endl;
    cout << " │" << endl;
    cout << " │ Jogador 1: (Branco)" << endl;
    cout << " ├──> ";
    cin.ignore();
    std::string j1;
    std::getline(cin, j1);
    cout << " │" << endl;
    cout << " │ Jogador 2: (Preto)" << endl;
    cout << " ├──> ";
    std::string j2;
    std::getline(cin, j2);
    cout << " │" << endl;
    cin.clear();
    
    try {
        jogador1 = new Jogador(j1);
        jogador2 = new Jogador(j2);
    } catch (const std::bad_alloc&) {
        if (jogador1) delete jogador1;
        if (jogador2) delete jogador2;
        if (tabuleiro) delete tabuleiro;
	    if (pecas) {
            for (int i = 0; i < 32; i++) {
		        if (pecas[i]) delete pecas[i];
        	}
            delete pecas;
    	}
        throw "Falta de Memória.";
    }

    for (int i = 0; i < 16; i++) {
        jogador1->setPeca(i, pecas[i]);
        jogador2->setPeca(i, pecas[i + 16]);
	}

    int i = 0;
    for (int x = 7; x >= 0; x--) {
        tabuleiro->getPosicao(x, 0)->setPeca(pecas[i++]);                
    }
    for (int x = 7; x >= 0; x--) {
        tabuleiro->getPosicao(x, 1)->setPeca(pecas[i++]);                
    }
    for (int x = 7; x >= 0; x--) {
        tabuleiro->getPosicao(x, 7)->setPeca(pecas[i++]);                
    }
    for (int x = 7; x >= 0; x--) {
        tabuleiro->getPosicao(x, 6)->setPeca(pecas[i++]);                
    }

    estado = em_jogo_branco;
    ui_jogando();
    return;
}

void Jogo::ui_jogando() {
    while (true) {
	    cls();
		cout << endl;
		cout << " ┌──┤ Xadrez ├─────────┐" << endl;
		cout << " └┬────────────────────┘" << endl;
        cout << "  └> " << jogador2->getNome();
        if (estado == em_jogo_preto || estado == em_xeque_preto) cout << " (Jogando)";
        cout << endl;
        tabuleiro->desenha();
        cout << "  ┌> " << jogador1->getNome();
        if (estado == em_jogo_branco || estado == em_xeque_branco) cout << " (Jogando)";
        cout << endl;

		cout << " ┌┴────────┤ Xadrez ├──┐" << endl;
        if (estado == em_xeque_branco) {
		    cout << " │ BRANCO EM XEQUE!!!  │" << endl;
		    cout << " ├─────────────────────┤" << endl;
        } else if (estado == em_xeque_preto) {
		    cout << " │ PRETO EM XEQUE!!!   │" << endl;
		    cout << " ├─────────────────────┤" << endl;
        } else {
			cout << " │                     │" << endl;
        }
        
		cout << " │ [m] Fazer jogada    │" << endl;
		cout << " │                     │" << endl;
		cout << " │ [s] Salvar jogo     │" << endl;
		cout << " │                     │" << endl;
		cout << " │ [q] Sair do jogo    │" << endl;
		cout << " │                     │" << endl;
		cout << " └┬────────────────────┘" << endl;
        std::string s;

        cout << "  └> ";
        char c = tolower(cin.get());

        if (c == 'm') {
            std::getline(cin, s);
            cin.clear();
            char v[4];
            int vLen = -1;
            for (int i = 0; s[i] != '\0' && vLen < 4; i++) {
                if (vLen == -1 && s[i] == ' ') {
                    vLen++;
                } else if (s[i] != ' ') {
                    v[vLen++] = toupper(s[i]);
                }
            }

            try {
                if (vLen != 4) throw "Entrada Inválida: Parâmetros insuficientes.";
                if (!isalpha(v[0])) throw "Entrada Inválida: [0] não é um caractére alfabético.";
                if (!isdigit(v[1])) throw "Entrada Inválida: [1] não é um caractére numérico.";
                if (!isalpha(v[2])) throw "Entrada Inválida: [2] não é um caractére alfabético.";
                if (!isdigit(v[3])) throw "Entrada Inválida: [3] não é um caractére numérico.";

                int xO = v[0] - 'A';
                int yO = v[1] - '1';
                int xD = v[2] - 'A';
                int yD = v[3] - '1';

                bool branco = estado == em_jogo_branco || estado == em_xeque_branco;

                Posicao *o = tabuleiro->getPosicao(xO, yO);
                Posicao *d = tabuleiro->getPosicao(xD, yD);

                if (o->getPeca() != NULL && o->getPeca()->isBranco() != branco) throw "Você não pode mover essa peça!";
                
                if (!tabuleiro->checaMovimento(xO, yO, xD, yD)) throw "Movimento inválido.";
                if ((estado == em_xeque_branco || estado == em_xeque_preto) && !tabuleiro->checaMoveXeque(xO, yO, xD, yD, branco)) throw "Movimento inválido.";
                
                if (d->getPeca() != NULL) {
                    d->getPeca()->setCapturada(true);
                }

                d->setPeca(o->getPeca());
                o->setPeca(NULL);

                if (tabuleiro->checaXeque(!branco)) {
                    if (tabuleiro->checaXequeMate(!branco)) {
                        estado = branco ? xeque_mate_preto : xeque_mate_branco;
                        ui_fimDoJogo();
                        return;
                    } else {
                        estado = branco ? em_xeque_preto : em_xeque_branco;
                    }
                } else {
                    estado = branco ? em_jogo_preto : em_jogo_branco;
                }
                
            } catch (const char *ex) {
                cout << ex << endl;
                sleep(2);
            }
        } else {
            cin.clear();
            if (c == 's') {
                ui_salvarJogo();
            } else if (c == 'q') {
                ui_fimDoJogo();
                return;
            }
        }
	}
}

void Jogo::ui_carregarJogo() {
    cls();
    ifstream fin;
    fin.open("chess.txt");
    
	for (int i = 0; i < 32; i++) {
		pecas[i]->setCapturada(true);
	}

    std::string j1;
    std::getline(fin, j1);
    jogador1 = new Jogador(j1);
    std::string j2;
    std::getline(fin, j2);
    jogador2 = new Jogador(j2);
    std::string t;
    std::getline(fin, t);
    for (int i = 0; i < 64; i++) {
        Posicao* p = tabuleiro->getPosicao(i % 8, i / 8);

        char c = t[i];

        if (c == ' ') {
            p->setPeca(NULL);
        } else if  (c == 'B') {
            p->setPeca(encontrarProximaPeca(bispo, true));
        } else if  (c == 'C') {
            p->setPeca(encontrarProximaPeca(cavalo, true));
        } else if  (c == 'D') {
            p->setPeca(encontrarProximaPeca(dama, true));
        } else if  (c == 'P') {
            p->setPeca(encontrarProximaPeca(peao, true));
        } else if  (c == 'R') {
            p->setPeca(encontrarProximaPeca(rei, true));
        } else if  (c == 'T') {
            p->setPeca(encontrarProximaPeca(torre, true));
        } else if  (c == 'b') {
            p->setPeca(encontrarProximaPeca(bispo, false));
        } else if  (c == 'c') {
            p->setPeca(encontrarProximaPeca(cavalo, false));
        } else if  (c == 'd') {
            p->setPeca(encontrarProximaPeca(dama, false));
        } else if  (c == 'p') {
            p->setPeca(encontrarProximaPeca(peao, false));
        } else if  (c == 'r') {
            p->setPeca(encontrarProximaPeca(rei, false));
        } else if  (c == 't') {
            p->setPeca(encontrarProximaPeca(torre, false));
        } else {
            throw "Tabuleiro inválido!";
        }
    }

    int e;
    fin >> e;
    estado = (Estado) e;
    fin.close();

    ui_jogando();
    return;
}

void Jogo::ui_salvarJogo() {
    cls();
    ofstream fout;
    fout.open("chess.txt");

    char tB[] = "BCDPRT";
    char tP[] = "bcdprt";

    fout << jogador1->getNome() << endl << jogador2->getNome() << endl;

    for (int c = 0; c < 8; c++) {
        for (int l = 0; l < 8; l++) {
            Peca* p = tabuleiro->getPosicao(l, c)->getPeca();
            if (p == NULL) {
                fout << ' ';
            } else {
                int v = p->getTipo();
                fout << (p->isBranco() ? tB[v] : tP[v]);
            }
        }
    }
    fout << endl << estado << endl;
    

    fout.close();

	cout << endl;
	cout << " ┌──┤ Xadrez ├──────────────────────────┐" << endl;
	cout << " │                                      │ [ver " << ver << "]" << endl;
	cout << " │   Arquivo salvo como 'chess.txt'     │" << endl;
	cout << " │                                      │" << endl;
	cout << " └──────────────────────────────────────┘" << endl;
    sleep(3);
}

void Jogo::ui_fimDoJogo() {
    while (true) {
        cls();
		cout << endl;
	    cout << " ┌──┤ Xadrez ├─────────┐" << endl;
	    cout << " └┬────────────────────┘" << endl;
        cout << "  └┤ " << jogador1->getNome() << " VS " << jogador2->getNome() << endl;
        tabuleiro->desenha();
        cout << endl;
        cout << "  ┌┤ ";

        if (estado == em_xeque_branco) {
            cout << jogador1->getNome() << " foi posto em xeque e desistiu!" << endl;
        } else if (estado == em_xeque_preto) {
            cout << jogador2->getNome() << " foi posto em xeque e desistiu!" << endl;
        } else if (estado == xeque_mate_branco) {
            cout << jogador2->getNome() << " colocou " << jogador1->getNome() << " em xeque-mate!" << endl;
        } else if (estado == xeque_mate_preto) {
            cout << jogador1->getNome() << " colocou " << jogador2->getNome() << " em xeque-mate!" << endl;
        } else {
            cout << "Ambos os jogadores decidiram empate!" << endl;
        }

        cout << " ┌┴───────────────────────────────────┤ Xadrez ├──┐" << endl;
        cout << " │                                                │ [ver " << ver << "]" << endl;
        cout << " │   [b] Voltar ao menu principal                 │" << endl;
        cout << " │                                                │" << endl;
        cout << " │   [q] Sair do jogo                             │" << endl;
        cout << " │                                                │" << endl;
		cout << " └┬───────────────────────────────────────────────┘" << endl;
		cout << "  └> ";
        char c = tolower(cin.get());
        cin.clear();

        if (c == 'b') {
            for (int l = 0; l < 8; l++) for (int c = 0; c < 8; c++) tabuleiro->getPosicao(l, c)->setPeca(NULL);
            for (int i = 0; i < 8; i++) pecas[i]->setCapturada(false);
	        if (jogador1) {
		        delete jogador1;
	        }
	        if (jogador2) {
		        delete jogador2;
	        }
            ui_menuPrincipal();
            return;
        } else if (c == 'q') {
            ui_sairDoJogo();
            return;
        }
    }
    cls();
}

void Jogo::ui_sairDoJogo() {
    cls();
	cout << "[Xadrez ver " << ver << "] Obrigado por jogar! Volte sempre!" << endl << endl;
	exit(0);
}

void Jogo::executar() {
    ui_menuPrincipal();
}
