#include <iostream>
#include "ui.h"

using namespace std;

int main()
{   
    init_ui();
    game();
    tear_down_ui();
    cout<<endl<<"thanks for playing slither"<<endl;
    return 0;
}