#include <iostream>
#include "../pecas/Bispo.h"
#include "../pecas/Cavalo.h"
#include "../pecas/Dama.h"
#include "../pecas/Rei.h"
#include "../pecas/Torre.h"
#include "../pecas/Peao.h"

using namespace std;

int main() {
    Tabuleiro tabuleiro;

    tabuleiro.desenha();

    return 0;
}


int main2() {
    Tabuleiro tabuleiro;
    Rei r(tabuleiro, true);
    Bispo b(tabuleiro, true);
    Cavalo c(tabuleiro, true);
    Dama d(tabuleiro, true);
    Torre t(tabuleiro, true);
    Peao p(tabuleiro, true);

    r.desenha();
    b.desenha();
    c.desenha();
    d.desenha();
    t.desenha();
    p.desenha();

    cout << (r.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (r.checaMovimento(1,1,3,3) ? "movimento válido" : "movimento inválido") << endl;

    cout << (b.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (b.checaMovimento(1,1,0,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (b.checaMovimento(1,1,2,1) ? "movimento válido" : "movimento inválido") << endl;

    cout << (t.checaMovimento(1,1,1,3) ? "movimento válido" : "movimento inválido") << endl;
    cout << (t.checaMovimento(1,1,3,1) ? "movimento válido" : "movimento inválido") << endl;
    cout << (t.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;

    cout << (p.checaMovimento(1,1,1,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(1,1,2,1) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(1,1,1,3) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(1,1,3,1) ? "movimento válido" : "movimento inválido") << endl;

    cout << (r.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (r.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (r.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;

    

    return 0;
}