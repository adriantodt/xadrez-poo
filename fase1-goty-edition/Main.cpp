/**
 * Nome do Arquivo: Main.cpp
 * 
 * Autores:
 *  - Adrian Todt Monteiro da Silva     759458
 *  - Diego Tupinambá                   760922
 *  - Victor Mendes                     756206
 * 
 * Turma: POO 2019/1
 * 
 * Descrição:
 *     Faz testes em todos os métodos
 *     do programa e imprime os resultados.
 * 
 * Data de Conclusão: 24 de abril de 2019
 */

#include <iostream>
#include "Jogo.h"
#include "pecas/Bispo.h"
#include "pecas/Cavalo.h"
#include "pecas/Dama.h"
#include "pecas/Rei.h"
#include "pecas/Torre.h"
#include "pecas/Peao.h"

using namespace std;

/**
 * Início do programa.
 */
int main() {
    Jogo jogo;

    // imprime um tabuleiro vazio
    cout << "tabuleiro:" << endl;
    jogo.tabuleiro.desenha();

    cout << endl;

    Rei r(jogo.tabuleiro, false);
    Bispo b(jogo.tabuleiro, false);
    Cavalo c(jogo.tabuleiro, false);
    Dama d(jogo.tabuleiro, false);
    Torre t(jogo.tabuleiro, false);
    Peao p(jogo.tabuleiro, false);

    // testa a impressão das peças
    cout << "peças pretas: ";
    r.desenha();
    b.desenha();
    c.desenha();
    d.desenha();
    t.desenha();
    p.desenha();

    r.branco = true;
    b.branco = true;
    c.branco = true;
    d.branco = true;
    t.branco = true;
    p.branco = true;

    cout << endl << "peças brancas: ";
    r.desenha();
    b.desenha();
    c.desenha();
    d.desenha();
    t.desenha();
    p.desenha();

    // testa a checagem de validação das peças
    cout << endl << endl << "rei:" << endl;
    cout << (r.checaMovimento(1,1,2,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (r.checaMovimento(1,1,3,3) ? "movimento válido" : "movimento inválido") << endl;

    cout << endl << "bispo:" << endl;
    cout << (b.checaMovimento(1,1,5,5) ? "movimento válido" : "movimento inválido") << endl;
    cout << (b.checaMovimento(1,1,1,5) ? "movimento válido" : "movimento inválido") << endl;

    cout << endl << "torre:" << endl;
    cout << (t.checaMovimento(1,1,1,5) ? "movimento válido" : "movimento inválido") << endl;
    cout << (t.checaMovimento(1,1,5,5) ? "movimento válido" : "movimento inválido") << endl;

    cout << endl << "cavalo:" << endl;
    cout << (c.checaMovimento(1,1,3,2) ? "movimento válido" : "movimento inválido") << endl;
    cout << (c.checaMovimento(1,1,3,3) ? "movimento válido" : "movimento inválido") << endl;

    cout << endl << "dama:" << endl;
    cout << (d.checaMovimento(1,1,5,5) ? "movimento válido" : "movimento inválido") << endl;
    cout << (d.checaMovimento(1,1,3,2) ? "movimento válido" : "movimento inválido") << endl;

    cout << endl << "peao branco:" << endl;
    cout << (p.checaMovimento(1,1,2,1) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(1,1,3,1) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(2,1,3,1) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(2,1,5,1) ? "movimento válido" : "movimento inválido") << endl;

    p.branco = false;

    cout << endl << "peao negro:" << endl;
    cout << (p.checaMovimento(6,6,5,6) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(6,6,4,6) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(5,6,4,6) ? "movimento válido" : "movimento inválido") << endl;
    cout << (p.checaMovimento(5,6,3,6) ? "movimento válido" : "movimento inválido") << endl;

    return 0;
}
