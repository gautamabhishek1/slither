#include"game.h"

int i=0;

void game_logic()
{   
    move(10,i);
    addstr("hello");
    i=i+1;
    if(i>10)
    i=0;
}