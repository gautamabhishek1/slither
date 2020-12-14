#include "game.h"

int direction;
int game_state= BEFORE_START;
int score;
int lives;
bool snake_displayed = false;

void start_game()
{
    init_snake();
    init_food();
    score = 0;
    lives = INITIAL_LIVES;
    direction = UP;
    game_state = STARTED;
}

void end_game(){
    game_state = ENDED;   
}

void paint_status()
{
    move(0,5);
    printw("Score %d", score);
    move(0, COLS-10);
    for(int i=0; i<lives; i++){
    addstr("O");
    }

    if(game_state == BEFORE_START){
        move(LINES-1,5);
        addstr("Press space to start");
    } else if(game_state == STARTED) {
        //
    }
    else if(game_state == SNAKE_RESET) {
        move(LINES-1,5);
        addstr("You just lost a Life! Press Space to continue...");
    
    } else {
        move(LINES-1,5);
        addstr(" [Press SPACE to restart] [Q to quit] ");
    }
}

bool execute_frame()
{   
    paint_border();
    paint_status();
    char key=getch();

    if(game_state == BEFORE_START){
   
    if(key==32)
    {
        start_game();
    }
} else if(game_state == STARTED){
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

        if(has_collision()){
            lives--;
            reset_snake();
            game_state = SNAKE_RESET; 

            if(lives == -1){
            end_game();
            }
        }
        
    } else if(game_state == SNAKE_RESET) {
        if(key == 32){
            game_state = STARTED;
        }
        if(snake_displayed){
            paint_snake();
        }
        snake_displayed = !snake_displayed;
        paint_food();


    } else {
        paint_snake();
        paint_food();
        if(key == 32){
            start_game();
        }
        if(key == QUIT){
            return true;
        }

    }
        return false;
}