#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50+1

char*** board_read(char *);

int main(void){

    char ***m;
    m=board_read("f2.txt");

    for(int i=0 ; i< 4; i++){
        for(int j=0; j< 9 ; j++){
            fprintf(stdout, "%s" , m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

char ***board_read(char *name){

    int row, col;
    int r,c;
    char ***map;
    char name_buffer[MAX];
    FILE*fp;

    fp=fopen(name, "r");
    if(fp == NULL){
        fprintf(stderr, "error opening file\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d %d" , &row, &col);
    map = (char ***)calloc(row, sizeof(char**));
    if(map == NULL){
        fprintf(stderr, "error opening file\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0 ; i< row; i++){
        map[i] = (char **)calloc(col,sizeof(char*));

        if(map[i] == NULL){
            fprintf(stderr, "error opening file\n");
            exit(EXIT_FAILURE);
        }

    }

    for(int i=0 ; i< row ; i++){
        fscanf(fp , "%d %d %s" , &r,&c, &name_buffer);
        map[r][c]=strdup(name_buffer);
    }

    return map;
}