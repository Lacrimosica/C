#include <stdio.h>
#include <stdlib.h>

#define N 10000
//quick find
/*
int main(){
    int i,t,p,q,id[N];
    for  i = 0; i < N; i++)
    {
        id[i]= i;
    }

    //alternative way to do:
    //while(scanf("%d %d, &p &q")==2)
    do {
        printf("Input pair pq:");
        scanf("%d %d", &p, &q);
        if (id[p]!=id[q]){
            for (t=id[p], i=0; i<N; i++) {
                if (id[i] == t){
                    id[i] = id[q];
                }
            }
            printf("%d-%d" , p,q);
        }
    }while (p!=q)
}
*/
//quick union
//quer solution
int main(void){
    int i, j, p, q, id[N], sz[N];
    for(i=0; i<N; i++) {
        id[i] = i; sz[i] = 1;
    }
    do {
        printf ("Input pair p q: ");
        scanf ("%d %d", &p, &q);
        for (i = p; i!= id[i]; i = id[i]);
        for (j = q; j!= id[j]; j = id[j]);
        if (i != j) {
            id[i] = j;
            printf ("%d %d\n", p, q);
        }
        if (i == j){
            printf ("pair %d %d already connected\n", p,q);
            else {
                printf ("pair %d %d not yet connected\n", p, q);
                if (sz[i] <= sz[j]) {
                    id[i] = j; sz[j] += sz[i];

                } else {

                    id[j] = i; sz[i] += sz[j];

                }
            }
        } while (p!=q);

        return 0;
    }


//my own

    int main(void){
        int i,tp,tq,p,q,id[N];
        for(i = 0; i < N; i++){
            id[i]= i;
        }
        while(scanf("%d %d", &p, &q)==2){
            tp=p;
            tq=q;
            if(id[tp]==p){
                if(id[tq]==q){
                    if(id[tp]!=id[tq]){
                        id[tp]= id[tq];
                    }
                }else{
                    tq=id[tq];
                }
            }else{
                tp=id[tp];
            }
            for(i=0 ; )
        }
    }