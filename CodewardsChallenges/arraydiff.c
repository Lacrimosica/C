#include <stdlib.h>
#include <stdio.h>

//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z);


int main(void){
    const int arr1[2] = {1, 2};
    const int arr2[1] = {1};
    const int expected[1] = {2};
    size_t z=0;
    array_diff(arr1 , 2, arr2 , 1 , &z);
}

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
    int count=0;
    int *marker,*res;
    int i,j;
    int n1x = (int)n1;
    int n2x = (int)n2x;
    marker=(int *)calloc(n1x ,sizeof(int));
    for(i=0; i< n2x ; i++){
        for(j=0; j<n1x ; j++){
            if(arr2[i] == arr1[j]){
                marker[j] = 1;
            }
        }
    }
    for(i=0 ; i<n1x; i++){
        if(marker[i] == 0){
            count++;
        }
    }

    for(int i= 0 ; i< n1; i++){
        printf("%d" , marker[i]);
    }

    printf("\ncount :%d\n" , count);

    res = (int *)malloc(count * sizeof(int));
    int k=0;
    for(i=0 ; i<n1x ; i++){
        if(marker[i] == 0){
            res[k] = arr1[i];
            k++;
        }
    }

    for(int i=0 ; i< count ; i++){
        printf("res[%d] = %d\n" , i, res[i]);
    }
    *z=count;
    return marker;
}