#include "Library.h"

void partition_r(int *sol,int *val, int n, int pos, int base){
    if(pos >=n){
        for(int p=0; p< base ; p++){
            printf(" { ");
            for(int i=0; i< N; i++){ 
                if(sol[i] == p){
                    printf("%d ", val[i]);
                } 
            }
            printf("} ");
        }
        printf("\n");
        return;
    }
    for(int i=0; i< base; i++){
        sol[pos]=i;
        partition_r(sol, val,n, pos+1, base);
    }
}