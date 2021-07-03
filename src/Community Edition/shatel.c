#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

#define MAX_Y 25
#define MAX_X 50

#ifdef _WIN32
    #define CLRSCR "cls"
#else
    #define CLRSCR "clear"
#endif



char world[MAX_Y][MAX_X];




void flushWorld(){
    for(int y = 0; y < MAX_Y; y++){
        for(int x = 0; x < MAX_X; x++){
            world[y][x] = 0;
        }
    }
}

void* draw(void *arg){
    while (1){
        system(CLRSCR);
        for(int y = 0; y < MAX_Y; y++){
            for(int x = 0; x < MAX_X; x++){
                switch(world[y][x]){
                    case 1: 
                        printf("@");
                        break;
                    case 2:
                        printf("*");
                        break;
                    case 3:
                    case 4:
                        printf("#");
                        break;
                    case 5:
                        printf("^");
                        break;
                    case 6:
                        printf("<");
                        break;
                    case 7:
                        printf(">");
                        break;
                    default:
                        printf(" ");
                        break;
                }
            }
            printf("\n");
        }
        usleep(100000);
    }
}

void showPaddel(int x){
    for(int i = 0; i < MAX_X; i++){
        world[MAX_Y-1][i] = 0;
        world[MAX_Y-2][i] = 0;
    }
    for(int i = x-4; i < x+4; i++){
        world[MAX_Y-1][i] = 1;
    }
    world[MAX_Y-2][x] = 5;
    world[MAX_Y-1][x-4] = 6;
    world[MAX_Y-1][x+4] = 7;
}

void* rigidbody(void *arg){
    while(1){
        for(int y = 0; y < MAX_Y; y++){
            for(int x = 0; x < MAX_X; x++){
                switch(world[y][x]){
                    case 2:
                        world[y][x] = 0;
                        if(y != 0) world[y-1][x] = 2;
                        break;
                    case 3:
                        if (y == MAX_Y-4) exit(1);
                        world[y][x] = 0;
                        if (world[y+1][x] != 2)  world[y+1][x] = 4;
                        break;

                }
            }
        }
        for(int y = 0; y < MAX_Y; y++)
            for(int x = 0; x < MAX_X; x++)
                if(world[y][x] == 4) world[y][x] = 3;
        usleep(500000);
    }
}

void* showEnemy(){
    while(1){
        for(int i = 8; i < MAX_X-8; i++){
            world[0][i] = ( (rand() < (RAND_MAX / 50)) ? 3 : world[0][i] ); // TODO
        }
        sleep(2);
    }
}

int main(int argc, char *argv[]){
    srand(time(0));


    pthread_t drawThread;
    pthread_t rigidbodyThread;
    pthread_t enemyThread;
    flushWorld();
    

    pthread_create(&drawThread, NULL, &draw, NULL);
    pthread_create(&enemyThread, NULL, &showEnemy, NULL);
    pthread_create(&rigidbodyThread, NULL, &rigidbody, NULL);
    

    int xPaddel = 20;
    while (1) {
        if(kbhit()){
            switch(getch()){
                case 77: 
                    if (xPaddel+7 <= MAX_X) xPaddel+=2; 
                    break;
                case 75: 
                    if (xPaddel-7 >= 0) xPaddel-=2;
                    break;
                case 32:
                    world[MAX_Y-3][xPaddel] = 2;
                    world[MAX_Y-3][xPaddel-1] = 2;
                    world[MAX_Y-3][xPaddel+1] = 2;
                    break;
                default: break;
            }
        }
        showPaddel(xPaddel);
    }

    return 0;
}
