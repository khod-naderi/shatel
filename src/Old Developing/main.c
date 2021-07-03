#ifndef _WIN32
#   include <conio.h>
#else
#   include <curses.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#define MAX_Y 20
#define MAX_X 75
#include <time.h>
#include "./show.c"
#include "./include/em.h"


void main() {
    int key, x=40,y=23, bulit[MAX_Y][MAX_X],world[MAX_Y][MAX_X];
    restB(&bulit,&world); // zero
    gotoxy(x,y);
    setPaddile(&x,&y); // show paddile
    while(1) {
        if (kbhit) { // if key press
            key = getch(); // get ey
            switch(key){
                case MAX_X: if(x > 5) x--; break; // left
                case 77: if(x < MAX_X) x++; break; // rhite
                case 32: shot(&x,&y,&bulit); break; // space
            }
        }
        gotoxy(x,y);
        setPaddile(&x,&y); // show paddile
        writeBulit(&bulit); // show bulit
        emShot(&bulit); // bulit
        drawWorld(&world); // show enamy
        //emWorld(&world); // enamy

    }
}
