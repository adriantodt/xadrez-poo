#include "Jogo.h"

#include "Bispo.h"
#include "Cavalo.h"
#include "Dama.h"
#include "Peao.h"
#include "Rei.h"
#include "Torre.h"

using namespace std;

Jogo::Jogo() {
    estado = inicio;
    jogador1 = NULL;
    jogador2 = NULL;
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

Jogo::~Jogo() {
    if (jogador1) {
        delete jogador1;
    }
    if (jogador2) {
        delete jogador2;
    }
    for (int i = 0; i < 32; i++) {
        delete pecas[i];
    }

    delete pecas;
}

void Jogo::executar() {

}