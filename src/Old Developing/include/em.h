#ifndef EM_H_INCLUDED
#define EM_H_INCLUDED


void restB(int *bulit[MAX_Y][MAX_X], int *world[MAX_Y][MAX_X]){ // zero 
    int y,x;
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++){
            bulit[y][x] = 0;
            world[y][x] = 0;
        }
    }
}

void shot(int *x,int *y, int *bulit[MAX_Y][MAX_X]){ 
    // shot the bulit
    bulit[*y-4][*x-1] = 1;
}

void emShot(int *bulit[MAX_Y][MAX_X]){
    int x,y;
    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++){
            if(y == 0){bulit[y][x]=0; // Remove the shot to prevent it from crashing
            }else if(bulit[y][x]==1){
                bulit[y][x]=0; 
                bulit[y-1][x]=1; // move bulit to up
            }
        }
    }
}



void emWorld(int *world[MAX_Y][MAX_X]){
    int x,y;

    for(y=0; y<MAX_Y; y++){
        for(x=0; x<MAX_X; x++){
            if(world[y][x] == 1) {
                    world[y+1][x]=1; 
            }
        }
    }
	for(x=0; x<MAX_X; x++){
        world[0][x]=((rand() < (RAND_MAX/20)) ? 1 : 0); // Add the cell to the top
    }
}


#endif // EM_H_INCLUDED
