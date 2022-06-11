#include <stdlib.h>
#include <stdio.h>
void merge_sort( int *A,int N);
void merger_sort_r(int *A, int *B, int l, int r);
void merge_sort_r (int *A, int *B, int l,int r);
void merge(int *A, int *B, int l, int c, int r);

int main(void){
    int A[10]={1,5,4,2,8,7,3,5,6,9};
    merge_sort(A,10);
    for(int i=0;i<10;i++){
        fprintf(stdout, "[%d] ",A[i]);
    }
    fprintf(stdout, "\n");

    return 0;
}

void merge_sort(int *A, int N){
    int l=0, r=N-1;
    int *B=(int *)malloc(N*sizeof(int));
    if(B==NULL){
        fprintf(stderr, "Memory allocation error");
        exit(EXIT_FAILURE);
    }
    merge_sort_r(A,B,l,r);
}

void merge_sort_r (int *A, int *B, int l,int r){
    int c;
    if(r<=1)
        return;
    c=(l+r)/2;
    merge_sort_r(A,B,l,c);
    merge_sort_r(A,B,c+1,r);
    merge(A,B,l,c,r);
}

void merge(int *A, int *B, int l, int c, int r){
    int i,j,k;

    for(i=l; j=c+1, k=l; i<=c && j<=r)
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];

    while (i<=c)
        B[k++]=A[i++];
    while(j<=r)
        B[k++]=A[j++];

    for(k=l; k<=r; k++)
        A[k]=B[k];

    return;
}
