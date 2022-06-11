#include "trees.h"

#define N 20

link new_node(int val){
    link new= (link) malloc(sizeof(struct node));
    new->k=val;
    new->l=NULL;
    new->r=NULL;
    // new->parent=NULL;

}

link leaf_insert_r(link root, int val){
    if(root == NULL){
        printf("new node made :%d\n" , val);
        return new_node(val);
    }
    if(root->k > val){
        printf("%d going through left arm: %d\n", val , root->k);
        root->l=leaf_insert_r(root->l, val);
    }else if(root->k < val) {
        printf("%d going through right arm %d\n", val , root->k);
        root->r=leaf_insert_r(root->r, val);
    }

    return root;
}

int main(void){

    link root=new_node(13);

    for(int i=0 ; i<30 ; i+=3){
        root= leaf_insert(root, i);
    }

}
