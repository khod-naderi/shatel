#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED

void setPaddile(int *x,int *y){
    // draw a padding
    clrscr();
    gotoxy(*x-4,*y);
    printf("<@@@@@@@>");
    gotoxy(*x-1,*y-1);
    printf("/^\\");
    gotoxy(*x,*y);
}

void writeBulit(int *bulit[MAX_Y][MAX_X]){
    int x,y;
    int h=1;
    gotoxy(1,h++);
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++)
            printf("%c", ((bulit[y][x] == 1) ? '+' : ' '));
        printf("\n");
    }
}

void drawWorld(int *world[MAX_Y][MAX_X]){
    int x,y;
    gotoxy(1,1);
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++){
            printf("%c", ((world[y][x]==1) ? '#' : ' '));
        }
        printf("\n");
    }
}


#endif // SHOW_H_INCLUDED
