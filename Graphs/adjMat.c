#include "header.h"

#define MAX_LINE 100

enum {WHITE , GRAY , BLACK};

typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;


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


graph_t *graph_load(char *filename){
    graph_t *g;
    char line[MAX_LINE];
    int i,j, weight, dir;
    FILE *fp;

    fp=fopen(filename, "r");

    g = (graph_t *) calloc (1, sizeof(graph_t));
    fgets(line, MAX_LINE, fp);
    if(sscanf(line, "%d %d" , &g->nv , dir) != 2){
        sscanf(line, "%d" , &g->nv);
        dir = 1;
    }

    g->v = (vertex_t *)calloc(g->nv , sizeof(vertex_t));

    for(i=0; i<g->nv ; i++){
        g->v[i].id = i;
        g->v[i].color= WHITE;
        g->v[i].dist = INT_MAX;
        g->v[i].pred = g->v[i].scc = -1;
        g->v[i].disc_time = g->v[i].endp_time = -1;
        g->v[i].rowAdj = (int *)calloc( g->nv , sizeof(int));
    }

    while(fgets(line, MAX_LINE, fp) != NULL){
        if(sscanf( line, "%d %d %d" , &i , &j , &weight) !=3){
            sscanf(line, "%d %d" , &i , &j);
            weight=1;
        }
        g->v[i].rowAdj[j] = weight ;
        if(dir ==0){
            g->v[j].rowAdj[i] = weight;
        }
    }
    fclose(fp);
    return g;
}

void graph_attribute_init(graph_t *g){
    int i;
    for(i = 0 ; i< g->nv ; i++){
        g->v[i].color = WHITE;
        g->v[i].dist = INT_MAX;
        g->v[i].endp_time = -1;
        g->v[i].disc_time = -1;
        g->v[i].pred = -1;
        g->v[i].scc = -1;
    }
        return;
}

int graph_find(graph_t *g, int id){
    int i;
    for(i=0 ; i < g->nv ; i++){
        if(g->v[i].id == id){
            return i;
        }
    }
    return -1;
}

void graph_dispose(graph_t *g){
    int i;
    for(i = 0 ; i< g->nv ; i++){
        free(g->v[i].rowAdj);
    }
    free(g->v);
    free(g);

    return;
}

