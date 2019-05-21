#include "Jogo.h"
#include <ncurses.h>

using namespace std;

void Jogo::executar() {
    initscr();
    start_color();
    wattron(stdscr, COLOR_BLUE);
    wrefresh(stdscr);

    
}