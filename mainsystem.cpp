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

void* child(void* data) {
  char *str = (char*) data; // get input
  for(int i = 0;i < 3;++i) {
    printf("%s\n", str); // output character per second
    Sleep(1000);
  }
  pthread_exit(NULL); // exit pthread
}

int main()
{
    debug_msg();
    hero a;
    a.init(0);
    a.print();
    int cycle = 0;

    char mych[8] = "Child";
    pthread_t t; // pthread variable
    pthread_create(&t, NULL, child, mych); // build child pthread

    // std::thread first (mainprint, a);
    // printf("%d sisisi\n", first.id);

    pthread_join(t, NULL); // wait child pthread
    
    while(true){
        
        if(cycle > 10000000){
            a.increase(); 
            cycle = 0;
        }
        cycle++;
    }

    return 0;
}