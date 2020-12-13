#include "ui.h"

void init_ui()
{
    setlocale(LC_ALL,"");
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void tear_down_ui()
{
    endwin();
}

void paint_border() {

    for(int i=0;i<COLS; i++)
    {
        move(0,i);
        addstr("\u2588");
        move(LINES-1,i);
        addstr("\u2588");
    }
    for(int i=0;i<LINES; i++)
    {
        move(i, 0);
        addstr("\u2588");
        move(i, COLS-1);
        addstr("\u2588");
    }

}