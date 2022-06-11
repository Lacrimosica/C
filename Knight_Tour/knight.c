#include <stdio.h>
#include <stdlib.h>



int search ( int **board ,int i, int j, int k){
    int xx, yy;

    int x_off[8]={2,1,-1,-2,-2,-1,1,2};
    int y_off[8]={-1,-2,-2,-1,1,2,2,1};
    
    for(int n=k; n< 8; n++){
        xx= i +x_off[n];
        yy= j+y_off[n];
        if (board[xx][yy] == 0){
            return n;
        }
    }
    return -1;
}

void printBoard(int **board ,  int s){
    for(int i=0; i< s; i++){
        for(int j=0; j< s; j++){
            printf("%d\t" , board[i][j]);
        }
        printf("\n");
    }
}

int knight_r(int ***b, int i, int j ,int level){
    int x_off[8]={2 , 1, -1, -2, -2, -1, 1, 2};
    int y_off[8]={-1 , -2, -2, -1, 1, 2, 2, 1};

    int **bp =*b;
    int t, xx,yy;

    if(level == 65){
        return 1;
    }
    for(int t=0; t<8 ; t++){
        xx= i + x_off[t];
        yy= j + y_off[t];
        if(xx >= 0 && xx <8 && yy>=0 && yy<8){
            if(bp[xx][yy] == 0){
                bp[xx][yy] = level;
                if(knight_r(&bp, xx, yy, level+1)){
                    return 1;
                }
                bp[xx][yy]=0;
            }
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

    initBoard(&board, 8);
    // for(int i=0; i<8 ; i++){
    //     for(int j=0; j<8 ; j++){
    //         board[i][j]=1;
    //         printf("got to: %d , with (i,j) = (%d,%d)\n", knight_r(&board , i, j, 2) , i, j);
    //         printBoard(board,8);
    //         cleanBoard(&board, 8);
    //     }
    // }
    
    int i=0;
    int j=4;
    board[i][j]=1;
    knight_r(&board, i,j,2);
    printBoard(board, 8);
    cleanBoard(&board, 8);
    printf("\n*******************\n");
    printBoard(board ,8);

    for(int i=0; i<8; i++){
        free(board[i]);
    }
    free(board);
    return 0;
}