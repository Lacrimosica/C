#include <stdbool.h>
#include <stdio.h>

bool validParentheses(const char *str_in) {
  int test[2];
  while(*str_in != '\0'){
    printf("%c" , *str_in);
    test[(int)(*str_in++) - 40]++;
  }
  printf("%d %d" , test[0] , test[1]);
  if(test[0] == test[1]) return 1;
  return 0;
}

int main(void){
  validParentheses("(((())))");
}