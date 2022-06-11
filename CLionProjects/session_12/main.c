#include <stdio.h>
#include <stdlib.h>
//quick-union considering the size of the trees
int main() {
    int i, j, p, q, id[N], sz[N];
    for (int i = 0; i < N; ++i) {
        id[i] = i; //the array of elements
        sz[i] = 1; //the array corresponding to the size of each tree
    }
    do {
        //getting the pairs
        printf("input pair");
        scanf("%d %d", &p, &q);
        //finding the root of each element
        for (i = p; id[i] != i; p = id[i]); //setting the i to p, if the root of i is not itself change p to the root
        for (j = q; id[j] != j; q = id[j]);
        if (i == j) { //if the roots are the same
            printf("the pair %d,%d is already connected");
        } else { //if the roots are not the same
            printf("the pair %d,%d is not yet connected");
            if (sz[i] <= sz[j]) {   //if i has the smaller tree
                id[i] = j;  //add i tree to the j tree which is larger
                sz[j] += sz[i]; //add the size of i tree to the j tree
            } else {
                id[j] = i;
                sz[i] += sz[j];
            }
        }
    } while (p != q); //in orde to stop the cycle you should imput the same two elements
    return 0;
}

//Sorting-insertion algorithm
int InsertionSort(int A[] , int n){
    int i,j,x;
    for (int i = 1; i < n; ++i) {
        x=A[i];
        j=i-1;
        while(j>=0 && x<A[j]){ //while we haven't yet reached the end of the sorted subarray, compare x to A[j]
            A[j+1]=A[j]; //if x is still smaller, then right shift the subarray element 1 position forward
            j--; //move the pointer of comparison 1 positioin left
        }
        A[j+1]=x; //incase that x is not smaller than A[j], then set x to the position it is already in, which is j+1=i
    }
    return 0;
}