#include "header.h"

void BFS(graph_t *g , int id){
    int i;
    vertex_t *v;
    v = graph_find(g, id);
    v->color =WHITE;
    v->disc_time = INT_MAX;
    v->pred = NULL;
    for()
}