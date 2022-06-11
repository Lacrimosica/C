#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void anag_r(char * output, char * input, int * mark, int pos, int n){

    if(pos >= n){
        printf("%s\n",  output);
        return;
    }

    for(int i=0 ; i < n ; i++){
        if(mark[i] == 0){
            mark[i]=1;
            output[pos] = input[i];
            anag_r(output, input , mark, pos+1 , n);
            mark[i]=0;
        }
    }

    return;
}

int main(void){

    char buff[10];
    char *input;
    char *output;
    printf("input string\n");
    scanf("%s" , buff);
    printf("Anagrams of %s:\n" , buff);
    
    input = strdup(buff);
    output = (char *) malloc( strlen(input) * sizeof(char));
    if(output == NULL){
        fprintf(stderr, "memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int *mark = (int *) calloc(strlen(buff) , sizeof(int));

    anag_r(output, input, mark , 0 , strlen(input));

    return 0;
}