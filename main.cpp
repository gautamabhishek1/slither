#include <iostream>
#include <chrono>
using namespace std;

#include "ui.h"
#include "game.h"
#include "constants.h"

void event_loop()
{
    auto last_time = chrono::system_clock::now();
    auto current_time = last_time;
    int dt;

    while(true){
        do{
        current_time = chrono::system_clock::now();
        dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
    } while(dt<TIME_DELAY_BETWEEN_FRAMES);

    last_time = current_time;
        
        erase();
        bool exit = execute_frame();
        if(exit){
            break;
        }
        refresh();
     
    }
}
int main()
{   
    init_ui();
    event_loop();
    tear_down_ui();
    cout<<endl<<"Thanks for playing slither!"<<endl<<endl;
    return 0;
}