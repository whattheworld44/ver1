#include "header.h"

void* f_increase(void* a_i){
    while(true){
        hero* a = (hero*)a_i;
        (*a).increase();
        Sleep(100);
    }
}

void signalHandler(int signum){
   std::cout << "Interrupt signal (" << signum << ") received.\n";
   std::cout << "bye bye\n";

   exit(signum);  
}

int main()
{
    debug_msg();
    hero a;
    a.init(0);
    printf("initial value\n");
    a.print();
    
    signal(SIGINT, signalHandler);

    pthread_t t_increasing;
    pthread_create(&t_increasing, NULL, f_increase, &a);

    
    while(true){
        char mode_i[cmd_str_len];
        scanf("%s",mode_i);
        Sleep(100);
        if(strcmp(mode_i, "print") == 0){
            printf("command %s\n",mode_i);
            a.print();
            printf("-----------------\n");
        }
        else if(strcmp(mode_i, "dup") == 0){
            printf("command %s\n",mode_i);
            hero b;
            b = a;
            b.print();
            printf("-----------------\n");
        }
        else{
            printf("command fault\n");
            continue;
        }
        
    }

    return 0;
}