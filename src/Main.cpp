#include "Jogo.h"

int main() {
    try {
        Jogo jogo;
        jogo.executar();
    } catch (const char *ex) {
        cout << ex << endl;
    }
}
