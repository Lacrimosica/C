
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MYERR(...) do{ \
	printf("@ %s (%d): " , __FILE__ , __LINE__); \
printf(__VA__ARGS__); \
}while(0)

void nl();

int main(){
//{{'a','b', '\0'},{'c','d','\0'},{'e','f','\0'}
 int n=3;
 char **a;
 char ***p;
 p=&a; 
 p=(char ***)malloc(n * sizeof(char**) );
 
 a=(char **)malloc(n * sizeof(char *) );
 for(int i=0 ; i<n; i++){
	a[i]=(char *)malloc(n* sizeof(char) );
 }//or alternatively *(a+i) 

a[0]="ab";
a[1]="cd";
a[2]="ef";

printf("%s", a[0]);
nl();
//printf(" printf(\"\%c\", a[0]); \/\/this is a wrong thing to do"); 
nl();
printf("%c", a[0][0]);
nl();
printf("%c", a[0][1]);
nl();
if(a[0][2]==NULL);
printf("NULL");
nl();
printf("%c", a[0][2]);
nl();
//for(int i=0;i<n;i++){
  //for(int j=0;j<n;j++){
  // scanf("%s", *(a+i) ); 
  //}
// }


 //for(int i=0;i<3;i++){
//for(int j=0;j<3;j++){

// printf("(1)%s , %s",a[i] , *p[i] );
// printf("\n");
// }

return 0;
}

void nl(){
 printf("\n");
}
