#include "Library.h"
#include <PrintArray.h>

#define N 4

// void printArray(int *a, int n){
//     printf("[ ");
//     for(int i=0; i<n ; i++){
//         printf("%d ", a[i]);
//     }
//     printf("]\n");
// }

int main(void){

    int val[N]={1,2,3,4};
    int sol[N]={0};
    int base=2;

    printArray(val,N);

    for(base=0; base<N; base++){
        printf("\ndividing into %d partitions:\n" , base);
        partition_r(sol, val,N, 0,  base);
    }


    return 0;
}