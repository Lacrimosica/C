#ifndef __HEADER
#define __HEADER

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_LINE 100
#define ADJACENCY_MATRIX 1
#define ADJACENCY_LIST 0

enum {WHITE , GRAY , BLACK};

typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
typedef struct edge_s edge_t;


graph_t * graph_load(char *filename);
void graph_attribute_init(graph_t *g);
void graph_dispose (graph_t *g);
vertex_t *graph_find (graph_t *g, int id);

#if ADJACENCY_MATRIX

struct vertex_s{
    int id;
    int color;
    int dist;
    int disc_time;  //discovery time
    int endp_time;  //end_processing time
    int pred;
    int scc;    //strictly connected component;
    int *rowAdj;    //array of adjacent vertices
};

struct graph_s{
    vertex_t *v;    //pointer to array of vertices
    int nv; //number of vertices
};

#endif

#if ADJACENCY_LIST
struct vertex_s{
    int id;
    int color;
    int dist;
    int disc_time;
    int end_time;
    int scc;
    vertex_t *pred;
    edge_t *head;
    vertex_t *next;
};

struct graph_s{
    vertex_t *v;
    int nv;
};


struct edge_s{
    int weight;
    vertex_t *dst;
    edge_t *next;
};

void new_edge(graph_t *g, int i, int j , int weight);
static vertex_t *new_node(graph_t *g, int id);


#endif


#endif