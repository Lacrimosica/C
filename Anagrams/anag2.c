#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define NUM 256

int processString(char *string , int *f){
    
    int i;
    for(i=0; i< NUM ; i++){
        f[i]=0;
    }

    for(i=0; string[i] != '\0'; i++){
        f[(int)string[i]]++;
    }

    return i;
}

int anag_r(char * anagram, int * frequency, int pos, int l, int count){

    int c;

    if(pos >= l){
        printf("%s\n",  anagram);
        return count+1;
    }

    for(c=0 ; c < NUM ; c++){
        if(frequency[c] >0){
            frequency[c]--;
            anagram[pos] = (char)(c);
            count = anag_r(anagram, frequency , pos+1 , l, count);
            frequency[c]++;
        }
    }

    return count;
}

int main(void){

    char word[MAX];
    char anagram[MAX];
    int frequency[NUM];

    char *input;
    char *output;

    int length;
    int count;
    printf("input string\n");

    scanf("%s" , word);
    printf("Anagrams of %s:\n" , word);

    length = processString(word, frequency);
    anagram[length]= '\0';


    count = anag_r(anagram, frequency, 0 , length, 0);
    printf("the total number of anagrams is: %d\n" , count);
    // char string[MAX];
    // int j=0;
    // for(int i=70 ; i< 80 ; i++){
    //     string[j]=i;
    //     j++;
    // }
    // for(int i=0; i<10 ; i++){
    //     printf("%c\n" , string[i]);
    // }
    // printf("%s\n" , string);
    return 0;
}