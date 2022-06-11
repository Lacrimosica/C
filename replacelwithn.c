#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
  int *buffer;
  buffer = (int *) calloc(strlen(text) , sizeof(int));
  int i=0;
  char c;
  while(*text != '\0'){
    c = *text;
    if(isalpha(c)) buffer[i++] = tolower(c) - 'a' + 1;
    text++;
  }
  
  if (i == 0) return "";
  printf("i :%d\n" , i);

  for(int j=0 ; j< i ; j++){
    printf("%d\n" , buffer[j]);
  }
  char *res = (char *) malloc( i * sizeof(char));
  int j,k=0;

  for(j=0 ; j< i; j++){
    if(buffer[j] <=9){
        printf("here k=%d\n" , k);
      strcpy(res[k++], (char)buffer[j]);
      strcpy(res[k++],' ');
    }else{

        printf("hetre k:%d\n" , k);
      strcpy(res[k++], (char) (buffer[j] / 10) ) ;
      strcpy(res[k++], (char) (buffer[j] % 10) ) ;
      strcpy(res[k++], ' ');
    }
  }

  for(int j=0 ; j < i ; j++){
      printf("%c" , res[j]);
  }
  return res;
}

int main(void){
    printf("%s\n" , alphabet_position("abcdefghijklmn") );
    // alphabet_position("The sunset sets at twelve o' clock.");
    // printf("%s" , alphabet_position("The sunset sets at twelve o' clock."));
}
