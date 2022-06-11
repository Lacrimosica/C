#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void historgram(char *str);

int main(void){

    char str[]="azaaabbnnccacczn";

    printf("%s\n" , str);

    historgram(str);    
}


void historgram(char *str){
    int count[256]={0};
    int i,j;
    char c;
    for(i=0 ; i<strlen(str) ; i++){
        c=str[i];
        count[(int)c]++;
    }

    for(i=0; i<256 ; i++){
        if(count[i] != 0){
            printf("\"%c\": %d," , (char)(i) , count[i]);
        }
    }
    printf("\n");
}