#include <stdio.h>
#include <stdlib.h>

#define BASE 2

void binary_r(int *array , int depth, int n){

    if(depth >= n ){
        for(int i=0; i< n ; i++){
            printf("%d" , array[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0; i< BASE ; i++){
        array[depth]= i;
        binary_r(array, depth+1 , n);
    }
}
int main(void){
    int n, *array;
    printf("intput n:\n");
    scanf("%d" , &n);
    array = (int *) malloc( n * sizeof(int));
    binary_r(array , 0, n);
    return 0;

}