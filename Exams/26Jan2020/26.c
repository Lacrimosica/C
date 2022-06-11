#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE 10+1
#define MAX_TIME 10+1
#define MAX_LINE 200

typedef struct access_info_s{
    char *ip;
    char *username;
    char date[MAX_DATE];
    char time[MAX_TIME];
    char *resource;
    int response;
    struct access_info_s *next;
}access_info;

typedef struct directory_s{
    access_info node;
}directory_t;


void readFile(char *name, directory_t g);

int main(int argc, char *argv[]){
    directory_t g;
    readFile(argv[1], g);
}


void readFile(char *name, directory_t g){

    FILE *fp;
    char line[MAX_LINE];

    fp=fopen(name, "r");
    if(fp == NULL){
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp , "%s" , line) !=EOF){
        add_log(line, g);
    }
}


void add_log(char *line, directory_t g){
    
    sscanf(line, "%s %s ")
}