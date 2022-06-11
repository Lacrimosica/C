#include "library.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void hello(void) {
    printf("Hello, World!\n");
}

int* RandomArray(int size, int max){
    int *array;
    array = (int*) malloc(size *sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i]=rand()%max;
    }

    return array;
}


void PrintArray(int A[], int n){
    for (int i = 0; i < n; ++i) {
        //printf("[");
        printf(" %d " , A[i]);
        //printf("]");
    }
    printf("\n");
    return;
}

void PrintArray2d(char **A,int R, int C){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%c", A[i][j]);
        }
        printf("\n");
    }
}

