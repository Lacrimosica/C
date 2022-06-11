#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 10
#define MAX 100
#define ALGS 2
//Knuth's sequence:
//h0= 1
//hi = 3h(i-1) +1 for i=1,2,...
//h=1,4,13,40,121,...
//Second sequence:
//h0=1
//h(i+1)= 4^(i+1) +3x2^i +1 for i=0,1,....
//h=1,8,23,77,281,1073,...
//Sedgewicks's Sequence:
//h=1,5,19,41,109,209,505,929,21,61,3905,...

void PrintArray(int A[], int n);
int *RandomArray(int size, int max);
void Shellsort(int A[], int n);
void CountingSort(int A[], int n, int k);

int main(void) {
    int s=SIZE, max=MAX,i=ALGS;
    int* p;                 //pointer for the return value of random array
    clock_t begin,end;      //define clock variable
    while(i>0){

        p=RandomArray(10,100);
        PrintArray(p,10);
        printf("ARRAY %d:\n", ALGS+1-i);
        PrintArray(p,s);
        switch (i)
        {
            case 2:
                printf("ShellSort:\n");
                begin=clock();
                Shellsort(p, s);
                end=clock();
                break;
            case 1:
                printf("CountingSort:\n");
                begin=clock();
                CountingSort(p,s,s);
                end=clock();
                break;
        }

        double t= (double)(end-begin)/CLOCKS_PER_SEC;
        printf("time for sorting algorithm %d is %10f\n", i , t);
        PrintArray(p,s);
        i--;
    }
    return 0;
}
void Shellsort(int A[], int n){
    int i,j,x,h;
    h=1;
    while (h<n/3) {     //because we are planning to multiply it by 3 in the coming line, we evaluate this expression
        h = 3 * n + 1; //we produce the initial h by going through the while loop until the condition is not satisfied
    }
    while(h>=1){
        for (i = h; i < n; ++i) {
            x=A[i];
            j=i-h;
            while(j>=0 && x<A[j]){
                A[j+h]=A[j]; //j+h=i keep in mind, and j is the element on the left
                            //if the element on the left is bigger, we shift it right
                j-=h;       //and we decrement j inorder to move it's pointer to the next element to compare it in the
                            //next loop
            }
            A[j+h]=x;    //when we have reached an i which is not less than j, we tell it to stay put
        }
        h= h/3;  //we don't do the minus one since the int type rounds h to the int of sequence that we want
    }
}

void CountingSort(int A[], int n, int k){ //so i think n is the number of elements we want to sort and k is the
                                        //number of different values that exist in the selected array
    int i,B[n], C[k];
    for (i = 0; i < k; ++i) {
        C[i]=0;
    }
    for (i = 0; i < n; ++i) {
        C[B[i]]++;
    }
    for (i = 1; i < k; ++i) {
        C[i]+=C[i-1];
    }
    for (i = n-1; i >=0; i--) {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for (i = 0; i < n; ++i) {
        A[i]=B[i];
    }
    PrintArray(B,n);
}

void PrintArray(int A[], int n){
    for (int i = 0; i < n; ++i) {
        //printf("[");
        printf(" %d " , A[i]);
        //printf("]");
    }
    printf("\n");
}

//make random array with a size and maximum value
//VERY IMPORTANT BREAKTHROUGH WITH THIS ONE
int* RandomArray(int size, int max){
    int *array;
    array = (int*) malloc(size *sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        array[i]=rand()%max;
    }
    return array;
}
