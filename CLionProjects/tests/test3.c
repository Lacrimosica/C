
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct list{
 char *id;
 struct list *next;
};

int main(void){
struct list *list_t;
char buffer[10];

 for(int i=0; i<3;i++){
  list_t=(struct list *)malloc(sizeof(struct list));
  printf("pointer position x%d\n" , list_t); 
  scanf("%s" ,buffer);
  list_t->id=strdup(buffer);
 
 }

 for(int i=0 ; i<3 ; i++){
  printf("%s\n" , list_t->next->id);
 }
 
return 0;
}
