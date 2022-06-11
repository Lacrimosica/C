#include <stdio.h>
#include <stdlib.h>

#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
#define PARENT(i) (int)((i-1)/2)



typedef struct heap_s{
    int *A;
    int heapsize;
}heap_t;

void headpify(heap_t heap, int i);
void swap(heap_t heap, int i, int j);

void swap(heap_t heap, int i, int j){
    int temp;

    temp = heap.A[i];
    heap.A[i]= heap.A[j];
    heap.A[j]= temp;
}


void headpify(heap_t heap, int i){
    int r, l;
    int largest;
    l=LEFT(i);
    r=RIGHT(i);

    if( (l < heap.heapsize) && (heap.A[i] < heap.A[l]) ){
        largest=l;
    }else{
        largest=i;
    }

    if( (r < heap.heapsize) && (heap.A[r] < heap.A[largest]) ){
        largest=r;
    }
    if(largest !=i){
        swap(heap, i, largest);
        headpify(heap, largest);
    }
    return;
}


void heapbuild(heap_t heap){
    for(int i= (int) (((heap.heapsize)/2)-1) ; i>=0 ; i--){
        headpify(heap, i);
    }
    return;
}


void heapsort(heap_t heap){
    int i, tmp;

    heapbuild(heap);

    tmp = heap.heapsize;

    for(i = (heap.heapsize -1) ; i>0 ; i--){
        swap(heap,0, i);
        heap.heapsize--;
        headpify(heap , 0);
    }

    heap.heapsize =tmp;

    return;
}