#include <stdio.h>
#include <stdlib.h>

#define N 8

void printBoard(int **board ,  int s){
    for(int i=0; i< s; i++){
        for(int j=0; j< s; j++){
            printf("%d\t" , board[i][j]);
        }
        printf("\n");
    }
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

int checkSolution(int **b){
    int i,j;

    int x_doff={1,-1};
    int y_doff={1,-1};

    //check rows
    int count=0;
    for(int i=0; i<N ; i++){
        for(int j=0; j<N ; j++){
            if(b[i][j] == 1){
                count++;
            }
        }
        if(count >1){
            return 0;
        }
        count=0;
    }

    count=0;

    //check columns
    for(int i=0; i<N ; i++){
        for(int j=0; j<N ; j++){
            if(b[j][i] == 1){
                count++;
            }
        }
        if(count >1){
            return 0;
        }
        count=0;
    }

    count=0;

    //diagonal check
    for(int d=0 ; d<2*N+1 ; d++){
        count=0;
        for(int i=0; i<N ; i++){
            j=d-i;
            if( (j>=0) && (j<N) ){
                if(b[i][j] != 0){
                    count++;
                }
            }
        }
        if(count >1){
            return 0;
        }
    }

    count=0;
    //check anti-diagonal
    for(int d=0 ; d<2*N+1 ; d++){
        count=0;
        for(int i=0; i<N ; i++){
            j= i-d +N-1;
            if( (j>=0) && (j<N) ){
                if(b[i][j] != 0){
                    count++;
                }
            }
        }
        if(count >1){
            return 0;
        }
    }


    return 1;
}

int queens(int ***board , int r0, int c0 , int n){
    int **bp = *board;

    if(n == N){
        if(checkSolution(bp) == 1){
            return 1;
        }else{
            return 0;
        }
    }

    
}
int main(void){
    int **board;

    initBoard(&board,N);
    queens(&board , )



}