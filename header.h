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

#define mode_ID  1
#define mode_atk 11
#define mode_dfd 12


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
        int hero_info(int mode){
            switch(mode){
                case mode_ID:
                    return this->ID;
                    break;
            }
        }
        hero operator=(hero& hero_i){
            hero temp;
            temp.ID = hero_i.hero_info(mode_ID);
            temp.atk = /*hero.atk*/123;
            temp.dfd = /*hero.dfd*/456;
            return temp;
        }

};