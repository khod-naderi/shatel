#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED

void setPaddile(int *x,int *y){
    // draw a padding
    clrscr(); // clear screen
    gotoxy(*x-4,*y);
    printf("<@@@@@@@>");
    gotoxy(*x-1,*y-1);
    printf("/^\\");
    gotoxy(*x,*y);
}

void writeBulit(int *bulit[MAX_Y][MAX_X]){ // show the bulit
    int x,y;
    gotoxy(1,1);
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++)
			//gotoxy(x,y);
            printf("%c", ((bulit[y][x] == 1) ? '+' : ' ')); // if bulit is say then show by + else empty
        printf("\n");
    }
}

void drawWorld(int *world[MAX_Y][MAX_X]){ // show cell
    int x,y;
    gotoxy(1,1);
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++){
            printf("%c", ( (world[y][x]==1) ? '#' : ' ') ); // if cell is healt then show by # else empty
        }
        printf("\n");
    }
}


#endif // SHOW_H_INCLUDED
