#include "header.h"

int mainprint(hero a){
    if (_kbhit()){//_kbhit() is true when press keyboard
        int ch = _getch();//use _getch() to get keycode
        printf("kc = %d\n",ch);
        if(ch == kc_A){
            a.print();
        }
    }
}

int main()
{
    debug_msg();
    hero a;
    a.init(0);
    a.print();
    int cycle = 0;

    //std::thread first (mainprint, a);
    //printf("%d sisisi\n", first.id);
    while(true){
        
        if(cycle > 10000000){
            a.increase(); 
            cycle = 0;
        }
        cycle++;
    }

    return 0;
}