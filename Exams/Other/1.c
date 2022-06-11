#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void myf(char *in, char*out, int *n){
    char *tmp1, *tmp2;
    int l;
    out[0]='\0';
    tmp1=in;
    while(*tmp1!='\0');{
        while(*tmp1 == ' '){
            tmp1++;
        }
        tmp2=tmp1;
        while(*tmp2!= ' ' && *tmp2!= '\0'){
            tmp2++;
        }
        l=tmp2-tmp1;
        if(l>strlen(out)){
            *n=l;
            strncpy(out, tmp1, l);
            out[l] ='\0';
        }
        tmp1=tmp2;
    }
    return;
}

int main(void){

    char in[]="This is a very loooong string";
    char out[strlen(in)];
    int n;
    myf(in, out, &n);

    printf("out: %s , n:%d" , out, n);

}