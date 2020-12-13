#include <curses.h>
#include <iostream>
#ifndef DEF_UI

#define DEF_UI

void init_ui();
void tear_down_ui();
void paint_border();
#endif