#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void generate(char *str, int n , int m);
int generate_r(int *vals, int *marked, int k, int n, int m, int *sol);

int main(void){


    char *str;
    char buff[100];
    int x;
    x=scanf("%s" , buff);
    printf("x: %d\n");
    str = malloc(x *sizeof(char));
    strcpy(str, buff);
    printf("str: %s\n", str);
    int n=2; 
    int m=9;

    // printf("%s" , str);
    generate(str, n, m);
}


int generate_r(int *vals, int *marked, int k, int n, int m, int *sol){

    if(k >= n){
        printf("{ ");
        for(int i=0 ; i< n ; i++){
            printf("%d" , sol[i]);
        }
        printf(" }\n");

        return 1;
    }

    for(int i=0 ; i<n ; i++){
        if(vals[i] <= m && marked[i] == 0){
            marked[i] =1;
            sol[k] = vals[i];
            generate_r(vals, marked, k+1, n, m-vals[i], sol);
            marked[i]=0;
        }
    }

    return 1;
}



void generate(char *str, int n , int m){

    int *sol = malloc(n *sizeof(int));

    int *marked = calloc( 10 ,sizeof(int));

    int *values = malloc( 10 * sizeof(int));

    if(sol == NULL || marked == NULL || values == NULL){
        fprintf(stderr , "error during memeroy allcoation\n");
        exit(EXIT_FAILURE);
    }

    for(int i= 0 ; i< 10 ; i++){
        values[i]= scanf("%d");
    }

    generate_r(values, marked, 0, n, m, sol);



}