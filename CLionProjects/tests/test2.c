#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
char a[]="helloworld"; //should print out 12
int n;
char buf1[10];
char buf2[10];

sscanf(a, "%s%n", buf1, &n);
printf("%d\n" , n);
return 0;
}
