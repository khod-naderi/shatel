#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_Y 20
#define MAX_X 75
#include <time.h>
#include "./include/show.h"
#include "./include/em.h"


void main() {
    int key, x=40,y=23, bulit[MAX_Y][MAX_X],world[MAX_Y][MAX_X];
    restB(&bulit,&world);
    gotoxy(x,y);
    setPaddile(&x,&y);
    while(1) {
        if (kbhit) {
            key = getch();
            switch(key){
                case MAX_X: if(x > 5) x--; break;
                case 77: if(x < MAX_X) x++; break;
                case 32: shot(&x,&y,&bulit); break;
            }
        }
        gotoxy(x,y);
        setPaddile(&x,&y);
        writeBulit(&bulit);
        emShot(&bulit);
        //emWorld(&world);
        //drawWorld(&world);
    }
}
