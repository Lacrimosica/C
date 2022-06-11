#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    1000
#define MAX     5
#define ALGS    8
//region SortingAlgorithmsPrototypes
void InsertionSort(int A[], int n);
void SelectionSort(int A[], int n);
void BubbleSort(int A[],int n);
void OptBubbleSort(int A[],int n);
void OptBubbleSort2(int A[], int n);
void ShellSort(int A[], int n);
void OptShellSort(int A[], int n);
void CountingSort(int A[], int n, int k);
void PrintArray(int A[], int n);
int* RandomArray(int size, int max);
//endregion

//includes the array initialization
//sorting of all arrays,different ones
//times of each operation given and printed
//as well as the arrays themselves
//in conclusion, the speed of the algorithms were as follows:
//shellsort>insertion>selection>bubble>optbubble>optbubble2
int main() {
    int s=SIZE, max=MAX,i=ALGS;
    int* p;
    clock_t begin,end;
    while(i>0){
        p=RandomArray(s,max);
        printf("ARRAY %d:\n" , ALGS-i+1);
        //PrintArray(p,s);
        switch (i)
        {
            case 8:
                printf("CountingSort:\n");
                begin=clock();
                CountingSort(p,s,max);
                end=clock();
                break;
            case 7:
                printf("OptShellSort:\n");
                begin=clock();
                OptShellSort(p, s);
                end = clock();
                break;
            case 6:
                printf("InsertionSort:\n");
                begin=clock();
                InsertionSort(p, s);
                end = clock();
                break;
            case 5:
                printf("SelectionSort:\n");
                begin=clock();
                SelectionSort(p, s);
                end = clock();
                break;
            case 4:
                printf("BubbleSort:\n");
                begin = clock();
                BubbleSort(p, s);
                end = clock();
                break;
            case 3:
                printf("OptBubbleSort:\n");
                begin = clock();
                OptBubbleSort(p, s);
                end = clock();
                break;
            case 2:
                printf("OptBubbleSort_2:\n");
                begin=clock();
                OptBubbleSort2(p, s);
                end = clock();
                break;
            case 1:
                printf("Shellsort:\n");
                begin = clock();
                ShellSort(p, s);
                end=clock();
                break;
        }
        double t= (double)(end-begin)/CLOCKS_PER_SEC;
        printf("time for sorting algorithm %d is %10f\n", i , t);
        //PrintArray(p,s);
        printf("---------------------\n");
        i--;
    }

    return 0;
}

void InsertionSort(int A[], int n){
    int i,j,x;
    for (int i = 1; i < n; ++i) {
        x=A[i];
        j=i-1;
        while(j>=0 && x<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    return;
}

void SelectionSort(int A[], int n){
    int i,j,min,temp;
    for (int i = 0; i < n - 1; ++i) {//n-1 because when we get to the n-1, the n-th element is relatively sorted already
        min=i;  //we start by setting min to the first element on the left
        for (int j = i+1; j < n; ++j) { //we strt going through the unsorted subarray starting from i+1
            if(A[min]>A[j]){ //we compare the min with the one we are pointing to
                min=j; //each time a min is found, it's index is stored
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    return;
}

void BubbleSort(int A[],int n){
    int i,j,temp;
    for (int i = 0; i < n-1; ++i) { //i is the numebr of elements already sorted
        for (int j = 0 ; j < n-i-1 ; ++j) { //at the end of each cycle the largest integer reaches the final position
                                            //and add 1 to the number of elements already sorted
            if(A[j]>A[j+1]){    //comparison phase
                //swapping phase
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    return;
}

void OptBubbleSort(int A[], int n){
    int i,j,flag,temp;
    flag=1;
    for (int i = 0; i < n - 1 && flag==1; ++i) {
        flag=0;
        for (int j = 0; j < n - i - 1; ++j) {
            if(A[j+1]<A[j]){
                flag=1;
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    return;
}

void OptBubbleSort2(int A[], int n) {
    int i,j,idx,temp;
    idx=1;
    for (int i = idx; i < n && idx !=0; i++) {
        idx=0;
        for (int j = 0; j < n-i-1; ++j) {
            if (A[j + 1] < A[j]) {
                idx = j;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    return;
}
//with static h
void ShellSort(int A[], int n) {
    int i, j, x, h;
    h = 4; //for examaple
    while (h > 0) {
        for (int i = h; i < n; ++i) {
            x = A[i];
            j = i - h;
            while (j >= 0 && x < A[j]) {
                A[j + h] = A[j];
                j -= h;
            }
            A[j + h] = x;
        }
        h -= 1; //or any other sequence, this is just an example
    }
}


void OptShellSort(int A[], int n){
    int i,j,x,h;
    h=1;
    while (h<n/3) {     //because we are planning to multiply it by 3 in the coming line, we evaluate this expression
        h = 3 * n + 1; //we produce the initial h by going through the while loop until the condition is not satisfied
    }
    while(h>=1){
        for (int i = h; i < n; ++i) {
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
    return;
}

void CountingSort(int A[], int n, int k){ //so i think n is the number of elements we want to sort and k is the
    //number of different values that exist in the selected array
    int i,B[MAX], C[MAX];
    for (i = 0; i < k; ++i) {
        C[i]=0;
    }
    for (i = 0; i < n; ++i) {
        C[B[i]]++;
    }
    for (int i = 1; i < k; ++i) {
        C[i]=C[i]+C[i-1];
    }
    for (int i = 0; i < n; ++i) {
        B[C[A[i]]-1]=A[i];
        C[A[i]]--;
    }
    for (int i = 0; i < n; ++i) {
        A[i]=B[i];
    }
    return;
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