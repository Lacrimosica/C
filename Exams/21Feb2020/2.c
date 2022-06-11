#include <stdio.h>
#include <stdlib.h>

typedef struct node_s node_t;

struct node_s{
    node_t * left;
    node_t * right;
    int key;
};

node_t * node_insert(node_t *node, int k);
int subtree (node_t *tree1, node_t *tree2);
node_t * new_node(int key);

int main(void){
    node_t *temp;
    node_t *r1= new_node(1);
    temp = node_insert(r1->left, 2);
    node_insert(r1->right, 3);

    node_insert(temp->left, 4);
    node_insert(temp->right, 5);


    node_t *r2 = new_node(2);

    node_insert(r2->left, 4);
    node_insert(r2->right, 5);


    subtree(r1, r2);
}

int subtree (node_t *tree1, node_t *tree2){
    int r=1, l=1;

    if(tree1 = NULL){
        printf("reached the end of the first tree\n");
        return 0;
    }

    if(tree1->key == tree2->key){
        printf("found similar keys, going deeper\n");

        if(tree2->left != NULL){
            l=subtree(tree1->left, tree2->left);
        }

        if(tree2->left !=NULL){    
            r=subtree(tree1->right , tree2->right);
        }
    }
    //recur left
    l=subtree (tree1->left , tree2);

    //recur right
    r=subtree (tree1->right , tree2);

    return r && l ;

}


node_t * new_node(int key){

    node_t * new=malloc(sizeof( node_t));

    if(new == NULL){
        fprintf(stderr, "error in allcaotion to node\n");
        exit(EXIT_FAILURE);
    }

    new->key=key;
    new->left= NULL;
    new->right = NULL;

    return new;
}


node_t * node_insert(node_t *node, int k){
    node->key = k;
    return node;
}