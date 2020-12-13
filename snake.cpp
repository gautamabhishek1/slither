#include"snake.h"

vector<pair<int,int>> body;
pair<int,int> last_tail_location;
void init_snake()
{
    body.clear();
    body.push_back({10,10});
    body.push_back({10,11});
    body.push_back({10,12});

}
void paint_snake()
{
    for(int i=0;i<body.size();i++){
        auto location= body[i];
        move(location.first, location.second);
        addstr("#");
    }
}

pair<int, int> move_snake(int direction)
{
    last_tail_location=body.back();
    body.pop_back();
    pair<int,int> head= body[0];
    pair<int,int> new_head= {head.first, head.second};
 
    if(direction== LEFT){
        new_head.second --;
    }
    else if(direction== RIGHT){
        new_head.second ++;
    }
    else if(direction== DOWN){
        new_head.first ++;
    }
    else if(direction== UP){
        new_head.first --;
    }

    body.insert(body.begin(),new_head);
    return new_head;
}

void grow_snake()
{
    body.push_back(last_tail_location);
}