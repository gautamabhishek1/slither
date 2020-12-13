#include <iostream>
using namespace std;

#include "ui.h"
#include "game.h"


void event_loop()
{
    while(true){
        erase();
        paint_border();
        game_logic();
        refresh();
    }
}
int main()
{   
    init_ui();
    event_loop();
    tear_down_ui();
    cout<<endl<<"thanks for playing slither"<<endl<<endl;
    return 0;
}