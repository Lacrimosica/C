#include <stdio.h>
#include <stdlib.h>


#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
#define PARENT(i) (int)((i-1)/2)

typedef struct Item_s
{
    int i;
}item;



typedef struct PQ_S
{
    int heapsize;
    item *A;
}PQ;


void pq_insert(PQ pq, item item){
    int i;

    pq.heapsize++;
    while( (i>=1) && pq.A[PARENT(i)].i < item.i ){
        pq.A[i]=pq.A[PARENT(i)].i;
        i=PARENT(i);
    }

    pq.A[i].i=item.i;

    return;
}


void p1_extract_max(PQ pq, item i)