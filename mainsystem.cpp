#include "header.h"

void* f_increase(void* a_i){
    while(true){
        hero* a = (hero*)a_i;
        (*a).increase();
        Sleep(100);
    }
}


int main()
{
    debug_msg();
    hero a;
    a.init(0);
    printf("initial value\n");
    a.print();
    
    pthread_t t_increasing;
    pthread_create(&t_increasing, NULL, f_increase, &a);

    
    while(true){
        char c;
        scanf("%c",&c);
        if(c == '\n'){
            continue;
        }
        printf("%c siisisisisisi\n",c);
        a.print();
        printf("-------\n");
    }

    return 0;
}