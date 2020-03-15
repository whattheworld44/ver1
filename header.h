#include <conio.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <future>
#include <pthread.h>
#include <windows.h>
#include <csignal>

#include "filesystem.h"

#define cmd_str_len 64

#define kc_A        65

#define mode_ID     1
#define mode_atk    11
#define mode_dfd    12


class hero{
    private:
        int    ID;
        double atk;
        double dfd;
        bool   dup_bit;
    public:
        int init(int ID_i){
            ID = ID_i;
            atk = 5;
            dfd = 5;
            dup_bit = 0;
            return 0;
        }
        int print(){
            printf("ID = %d atk = %.1lf dfd = %.1lf dup_bit = %d\n",ID, atk, dfd, dup_bit);
            return 0;
        }
        int increase(){
            atk = atk + 0.01*atk;
            dfd = dfd + 0.01*dfd;
            return 0;
        }
        double hero_info(int mode){
            switch(mode){
                case mode_ID:
                    return (double)ID;
                    break;
                case mode_atk:
                    return (double)atk;
                    break;
                case mode_dfd:
                    return (double)dfd;
                    break;
            }
        }
        void operator=(hero hero_i){
            this->ID  =     (int)hero_i.hero_info(mode_ID);
            this->atk =     (double)hero_i.hero_info(mode_atk);
            this->dfd =     (double)hero_i.hero_info(mode_dfd);
            this->dup_bit = 1;
        }

};