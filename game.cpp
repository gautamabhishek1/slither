#include "game.h"
#include "constants.h"

int direction;
int game_state= BEFORE_START;
int score;

void start_game()
{
    init_snake();
    init_food();
    score=0;
    direction=UP;
    game_state=STARTED;
}
void execute_frame()
{   
    paint_border();
    char key=getch();

    if(game_state == BEFORE_START){
    move(10,10);
    addstr("Press space to start");
    if(key==32)
    {
        start_game();
    }
} else {
        if(key==UP && direction != DOWN) {
            direction=UP;
        }
        else if(key==DOWN && direction != UP) {
            direction=DOWN;
        }
        else if(key==RIGHT && direction != LEFT) {
            direction=RIGHT;
        }
        else if(key==LEFT && direction != RIGHT) {
            direction=LEFT;
        }
        
        pair<int, int>head = move_snake(direction);
        if(try_consume_food(head)){
            grow_snake();
            score++;
        }
        paint_snake();
        paint_food();
    }
        
}