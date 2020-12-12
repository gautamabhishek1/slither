#include"ui.h"

void init_ui()
{
    initscr();
}

void tear_down_ui()
{
    endwin();
}

void game()
{
    move(10,10);
    addstr("hello");
    getch();
}