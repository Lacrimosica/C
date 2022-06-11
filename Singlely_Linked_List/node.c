#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s{
    struct node_s * next;
    int val;
}node;

node *new(int n){
    node *nd = (node *) malloc(sizeof(node));
    nd->val=n;
    nd->next=NULL;
}

node *head_insert(node *head, int n){

    node* new_head = new(n);
    new_head->next =NULL;
    
    if(head == NULL){
        return new_head;
    }else{
        new_head->next = head;
    }

    return new_head;
}

node *tail_insert(node *head, int n){
    node* new_tail = new(n);
    node* ptr =head;

    if(ptr == NULL){
        new_tail->next = NULL;
        return new_tail;
    }else{

        while(ptr->next != NULL){
            ptr=ptr->next;
        }

        if(ptr->next == NULL){
            ptr->next = new_tail;
            new_tail->next=NULL;
        }
    }
    return head; 
}

node *insert_val_at(node *head, int val, int idx){

    if(idx ==0){
        return head_insert(head, val);
    }

    node *new_node=new(val);
    node *ptr = head;
    node *tmp;
    for(int i=0; i<idx-1;i++){
        if(ptr->next != NULL)
             ptr=ptr->next;
    }
    tmp=ptr->next;
    ptr->next=new_node;
    new_node->next=tmp;

    return head;
}

void swap_adj_nodes(node *head, node *p, node*q){
    node *node1, *prev1, *node2, *prev2;
    node1=p;
    node2=q;
    prev1=head;
    prev2=head;

    while(prev1!= NULL && prev1->next != node1){
        prev1=prev1->next;
    }

    while(prev2!= NULL && prev2->next != node2){
        prev1=prev2->next;
    }

    prev1->next=node2;
    node1->next=node2->next
    prev2->next=node1;




    
;
}   
// node *sort(node * head){
//     node *min, *bmin;
//     node *ptr, *qtr;
//     node *sort;
//     node *tmp;

//     sort=head;
//     ptr=head;
//     min=head;

//     while(ptr!= NULL && (ptr->next != NULL) && (ptr->val > min->val) ){
//         ptr=ptr->next;
//     }
//     qtr=ptr->next;
//     tmp=min;
//     sort=ptr;
//     sort->next=tmp
        
// }

void printNodes(node *head){
    printf("preaparing to print nodes\n");
    if(head == NULL){
        return;
    }

    while(head != NULL){
        if(head->next != NULL){
            fprintf(stdout, "%d--->", head->val);
        }else{
            fprintf(stdout, "%d\n", head->val);
        }
        head=head->next;
    }
}


int main(void){
    
    node *head = NULL;
    
    head = new(1);

    

    head=head_insert(head, 2);
    head=head_insert(head, 8);
    head=head_insert(head, 4);
    head=head_insert(head, 6);

    head=tail_insert(head, 7);
    head=tail_insert(head, 11);
    head=tail_insert(head, 9);
    head=tail_insert(head, 16);


    head=insert_val_at(head, 20, 8);


    swap_adj_nodes(head, head->next);

    printNodes(head);

    return 0;
}