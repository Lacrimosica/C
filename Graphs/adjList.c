#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_LINE 100

enum {WHITE , GRAY , BLACK};

typedef struct graph_s graph_t;
typedef struct vertex_s vertex_t;
typedef struct edge_s edge_t;


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

vertex_t *graph_find (graph_t *g, int id){
    vertex_t *v;
    v= g->v;
    while(v !=NULL){
        if(v->id == id){
            return v;
        }
        v=v->next;
    }

    return NULL;
}


void new_edge(graph_t *g, int i, int j , int weight){
    vertex_t *src, *dst;
    edge_t *e;

    src = graph_find(g, i);
    dst = graph_find(g, j);

    e = (edge_t *)malloc( sizeof (edge_t));
    e->dst = dst;
    e->weight = weight;
    e->next = src->head;
    src->head = e;
    return;
}

void graph_attribute_init(graph_t *g){
    vertex_t *v;

    v = g->v;
    while(v !=NULL){
        v->color =WHITE;
        v->disc_time = INT_MAX;
        v->disc_time = -1 ;
        v->end_time = -1;
        v->scc = -1 ; 
        v->pred = NULL;
        v = v->next ;
    }
    return;
}

static vertex_t *new_node(graph_t *g, int id){
    vertex_t *v;
    v = (vertex_t *) malloc(sizeof(vertex_t));
    v->id = id;
    v->color = WHITE;
    v->dist = INT_MAX;
    v->scc = v->disc_time = v->end_time = -1;
    v->pred = NULL;
    v->head = NULL;
    v->next = g->v;
    return v;
}

graph_t * graph_load(char *filename){
    graph_t *g;
    int i,j, dir, weight;
    FILE *fp;
    char line[MAX_LINE];

    g = (graph_t *) calloc (1, sizeof(graph_t));
    fgets(line, MAX_LINE, fp);
    if(sscanf(line, "%d %d" , &g->nv , dir) != 2){
        sscanf(line, "%d" , &g->nv);
        dir = 1;
    }

    for(i=g->nv-1 ; i>=0; i--){
        g->v = new_node(g, i);
    }

    while(fgets(line, MAX_LINE , fp) != NULL){
        if(sscanf (line, "%d %d %d", &i, &j , &weight) != 3){
            sscanf (line, "%d %d", &i, &j);
            weight =1;
        }

        new_edge(g, i, j ,weight);
        if(dir == 0){
            new_edge (g, j, i , weight);
        }
    }
    fclose(fp);


    return g;
}

void graph_dispose (graph_t *g){
    vertex_t *v; 
    edge_t *e;
    v= g->v;
    while(v !=NULL){
        while (v->head != NULL)
        {
            e = v->head;
            v->head = e->next;
            free(e);
        }
        v = v->next;
        free(v);
    }
    return;

}