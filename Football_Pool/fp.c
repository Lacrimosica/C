#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void play_r( char** scheme, char * column, int n, int r , FILE *fp){

    if( n>= r){
        fprintf(fp, "%s\n" , column);
        return;
    }

    for(int i=0 ; i<strlen(scheme[n]) ; i++){
        column[n] = scheme[n][i];
        play_r(scheme, column , n+1 , r, fp );
    }
    return;
}

int main(void){
    int n_r=0;
    int n_c=1;
    char row[3+1];
    char *column;

    FILE *fp=fopen("file.txt", "r");

    if(fp ==NULL){
        fprintf(stderr,"error in opening file\n");
        exit(EXIT_FAILURE);
    }

    char **scheme;
    
    while(fscanf(fp, "%s" , row)!=EOF){
        n_r++;
        n_c*= strlen(row);
    }

    
    scheme = (char **)malloc( n_c *sizeof(char *));

    if(scheme == NULL){
        fprintf(stderr, "all err\n");
        exit(EXIT_FAILURE);
    }


    fclose(fp);

    column = (char *)malloc (n_r * sizeof(char));
    if(column == NULL){
        fprintf(stderr, "mem rroor\n");  
        exit(EXIT_FAILURE);
    }

    fp=fopen("file.txt", "r");

    if(fp == NULL){
        fprintf(stderr, "error in opening file\n");
        exit(EXIT_FAILURE);
    }
    
    for(int i=0; i<n_r ; i++){
        fscanf(fp,"%s" , row);
        scheme[i]=strdup(row);
    }

    fclose(fp);

    FILE *fpw=fopen("out.txt", "w");

    if(fpw ==NULL){
        fprintf(stderr, "file erro\n");
        exit(EXIT_FAILURE);
    } 

    play_r(scheme, column, 0, n_r, fpw);

    printf("here\n");

    for(int i=0 ; i< n_r ; i++){
        free(scheme[i]);
    }
    free(scheme);

    fclose(fpw);
    
    return 0;
}