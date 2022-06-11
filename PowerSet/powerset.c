#include "library.h"

int powerset(int *val, int *sol, int k, int start , int pos, int count){
    int i;

    if(start >=k){
        printf("{ ");
        for(i=0; i< k; i++){
            printf("%d " , sol[i]);
        }
        printf("}\n");
        return count +1;
    }

    for(i=start ; i< k ; i++){
        sol[pos]= val[i];
        count =powerset(val, sol, k, i+1, pos+1, count);
    }   
    count = powerset(val, sol, k, k, pos, count);
    return count;
}


int powerset2(int *val, int *sol, int pos, int k, int count){

    int i; 
    if(pos>=k){
        printf("{ ");
        for(i=0 ; i<k ; i++){
            if(sol[i] != 0){
            printf("%d " , val[i]);
            }
        }
        printf("}");
        return count+1;
    }

    sol[pos]=0;
    count = powerset2(val, sol, pos+1, k, count);
    sol[pos]=1;
    count = powerset2(val, sol, pos+1, k, count);

    return count;
}



int powerset3_r(int *val , int *sol , int k , int n, int pos, int start){
    int count=0,i;

    if(pos ==n){
        printf("{ ");
        for(i=0 ; i< n ; i++){
            printf("%d " , sol[i]);
        }
        printf("}");
        return 1;
    }

    for(i=start ; i<k; i++){
        sol[pos] = val[i];
        count+= powerset3_r(val, sol, k, n, pos+1, i+1);
    }

    return count;
}

int powerset3(int *val, int *sol, int k ){
    int count,i;

    count = 0;
    for(i=0; i<k; i++){
        count +=powerset3_r(val, sol, k, i, 0, 0);
    }
    return count;
}