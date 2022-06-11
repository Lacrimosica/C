#include <stdio.h>
#include <stdlib.h>

#define N 3

//moves rod 
void move(int **rods, int a, int b){
    int i,j;
    a-=1;
    b-=1;
    while(rods[a][i] != 0){
        i++;
    }
    while(rods[b][j] != 0){
        j++;
    }  
    if(rods[b][j-1] > rods[a][i-1]){
        rods[b][j]=rods[a][i-1];
        rods[a][i-1]=0;
    }
}

int check(int **rods){
    for(int i=0; i<N ; i++){
        if(rods[2][i] != i+1){
            return 0;
        }
    }
    return 1;
}

int hanoi_r(int **rods , int n){
    if(check(rods)){
        return 1;
    }

    for(int i=0; i<N; i++){
        
    }
}

int main(void){

    int **rods;
    int i;
    int n_moves=0;

    rods = (int **)malloc(3 * sizeof(int *));

    for(i=0 ; i< 3; i++){
        rods[i]=(int *)malloc( N * sizeof(int));
    }   

    for(i=1;  i<=N ; i++){
        rods[0][i-1] = i;
    }

    n_moves = hanoi_r(rods, N);

}