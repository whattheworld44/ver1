#include <conio.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <future>
#include <pthread.h>
#include <windows.h>

#include "filesystem.h"

#define kc_A 65


class hero{
    private:
        int ID;
        double atk;
        double dfd;
    public:
        int init(int ID_i){
            ID = ID_i;
            atk = 5;
            dfd = 5;
            return 0;
        }
        int print(){
            printf("ID = %d atk = %.1lf dfd = %.1lf\n",ID, atk, dfd);
            return 0;
        }
        int increase(){
            atk = atk + 0.01*atk;
            dfd = dfd + 0.01*dfd;
        }

};