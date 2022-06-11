#include "header.h"

void printArray(int *a, int n){
    printf("[ ");
    for(int i=0; i<n ; i++){
        printf("%d ", a[i]);
    }
    printf("]\n");
}