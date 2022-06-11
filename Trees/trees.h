#ifndef _LIBRARY
#define _LIBRARY

#include <stdio.h>
#include <stdlib.h>


typedef struct node *link;

struct node{
    int k;
    // link parent;
    link l;
    link r;
};





#endif
