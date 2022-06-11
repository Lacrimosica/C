#include <stdio.h>
#include <stdlib.h>

//you can change N to your will
#define N 5
#define MOVE 8

void printBoard(int **board ,  int s){
    for(int i=0; i< s; i++){
        for(int j=0; j< s; j++){
            printf("%d\t" , board[i][j]);
        }
        printf("\n");
    }
}

int knight_r(int ***b, int x, int y ,int level){
    int x_off[8]={2 , 1, -1, -2, -2, -1, 1, 2};
    int y_off[8]={-1 , -2, -2, -1, 1, 2, 2, 1};
    int count[MOVE];

    int min, min_idx;

    int **bp =*b;
    int t, xx,yy ,xxx,yyy;
    
    //termination condition
    if(level == N*N+1){
        return 1;
    }

    //compute count array for the offsets
    for(int t=0; t< MOVE; t++){
        xx= x + x_off[t];
        yy= y + y_off[t];
        if(xx >= 0 && xx <N && yy>=0 && yy<N && (bp[xx][yy] == 0) ){
            count[t]=0;
            for(int tt=0; tt< MOVE ; tt++){
                xxx= xx + x_off[tt];
                yyy= yy + y_off[tt];
                if(xxx >= 0 && xxx <N && yyy>=0 && yyy<N && (bp[xxx][yyy] == 0)){
                    count[tt]++;
                }
            }
        }     
    }

    //detemine min move offset and take move
    for(int i=0; i<MOVE ; i++){
        min=MOVE;
        min_idx=MOVE;
        for(int j=0; j<MOVE ; j++){
            if(count[j]<min){
                min=count[j];
                min_idx=j;
            }
        }
        if(min_idx <MOVE){
                xx = x +x_off[min_idx];
                yy = y +y_off[min_idx];
            if(xx >= 0 && xx <N && yy>=0 && yy<N){
                if(bp[xx][yy] == 0){
                    bp[xx][yy] = level;
                    if(knight_r(&bp, xx, yy, level+1)){
                        return 1;
                    }
                    bp[xx][yy]=0;
                }
            }
            count[min_idx]=MOVE;
        }else{
            break;
        }
    }
    *b=bp;
    return 0;
}

void initBoard(int ***board, int n){
    int **bp;
    bp = (int **)calloc(n, sizeof(int *));
    if(bp == NULL){
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i< n; i++){
        bp[i]= (int *)calloc(n, sizeof(int));
        if(bp[i] == NULL){
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    *board = bp;
}

void cleanBoard(int ***b, int s){
    int **bp=*b;
    for(int i=0; i<s; i++){
        for(int j=0; j< s; j++){
            bp[i][j]=0;
        }
    }
    *b=bp;
}

int main(void){

    int **board;
    int i,j;
    initBoard(&board, N);
    int command;
    printf("modes:\n1-go through all cells in %dx%d matrix\n2-custom start point\n", N, N);
    scanf("%d" , &command);

    switch (command){
        case 1:
            for(int i=0; i<N ; i++){
                for(int j=0; j<N ; j++){
                    board[i][j]=1;
                    printf(" starting at (i,j) = (%d,%d)\n", i, j);
                    knight_r(&board,i,j,2);
                    printBoard(board,N);
                    cleanBoard(&board, N);
                }
            }
            break;

        case 2:
            printf("position to begin at?\n");
            scanf("%d %d" , &i, &j); 
            board[i][j]=1;
            knight_r(&board, i,j,2);
            printf("here\n");
            printBoard(board, N);

            break;
    }
    
    for(int i=0; i<N; i++){
        free(board[i]);
    }
    free(board);

    return EXIT_SUCCESS;
}