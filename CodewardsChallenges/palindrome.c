#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int palindrome(char *str);
int palindrome_r(char *str);

int main(void){
    char *str;
    char input[30];

    scanf("%s" , input);
    str = malloc( strlen(input) *sizeof(input));
    if(str == NULL){
        fprintf(stderr, "error in memory allcoation\n");
        exit(EXIT_FAILURE);
    }

    palindrome(str);

}


int palindrome(char *str){
    int n=strlen(str);
    int i,j, count=0, index=0, max_count=INT_MIN, max_index=0;
    char c;
    char temp[n];

    for(i=0; i< n ; i++){
        c=str[i];
        index=1;
        for(j = i+1 ; j< n-1 ; j++){
            if(str[j] == c){
                printf("found same char %c == %c\n" , str+i , str+j);
                strncpy(temp, str+i, j-i);
                n = palindrome_r(temp);
                if(n){
                    index=i;
                }

                if(count > max_count){
                    max_count=count;
                    max_index = index;
                }
            }
        }
    }

    printf("the longest plaindrome substring in %s is:\n %s with lenght %d\n" , str, str+max_index , max_count);
}


int palindrome_r(char *str){
    int n= strlen(str);
    
    int i,j;
    int c;
    for(i=0; i<n ; i++ ){
        if(str[i] != str[n-i]){
            return 0;
        }
    }
    return n;
}