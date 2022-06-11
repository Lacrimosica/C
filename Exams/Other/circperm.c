#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cs_s{
    char *str;
}circularString;

void circularPermutation(char *str);
void circularPermutation_r(char *sol, int level, char solutions[][], char *str , int n);

int main(void){
    char string[]="ABCDE";
    
    circularPermutation(string);
}

void circularPermutation(char *str){

    int n=strlen(str);
    int size=n;
    int i=1;

    while(--size >0){
        i*=size;
    }

    char solutions[i][n];
    char sol[n];
    circularPermutation_r(sol,0 ,  solutions , str, n);

}

void circularPermutation_r(char *sol, int level, char solutions[][], char *str , int n){
    int i;
    if( level == n ){
        check();

    }


    for(i=0 ; i <n ; i++){
        sol[level] = *(str+i);
        circularPermutation_r(sol, level+1, solutions,str , n);
    }
}
