#include <stdio.h>
#include <stdlib.h>


typedef struct ddl_s{
    int n;
    struct ddl_s *right;
    struct ddl_s *left;
}ddl;

ddl *new(){
    ddl *new = (ddl *)malloc(sizeof(ddl));
    if(new ==NULL){
        fprintf(stderr , "Error in memory allocation\n");
        exit(EXIT_FAILURE);
    }
}

void SetHead (ddl **head_ref , ddl *new){
    new->right = NULL;
    new->left = (*head_ref);
    *head_ref = new;
}

void push(ddl ** head_ref , ddl *new){
    new->right = *head_ref;
    new->left = NULL;
    *head_ref = new;
}

int main(void){

    FILE *fp;
    FILE *fpw;

    fp=fopen("file.txt" , "r");
    fpw=fopen("out.txt" , "w");

    if(fp == NULL || fpw == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    ddl *tmp = new();
    ddl *head = NULL;

    while(fscanf(fp,"%d" , &tmp->n)!= EOF){
        fprintf(fpw, "%d\n" , tmp->n);

        if( head == NULL){
            fprintf(fpw,"this\n");
            SetHead(&head , tmp);
        }else{
            fprintf(fpw,"that\n");
            push(&head, tmp);
        }
    }


    while(head != NULL){
        printf("%d->" , head->n);
        head = head->right;
    }

    return 0;
}


