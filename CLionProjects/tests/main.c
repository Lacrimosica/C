#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[]){

	FILE *fp;
 	char buffer[MAX+1], buffer2[40];

	fp=fopen(argv[1], "r");
	fgets(buffer, MAX, fp);

	for(int i=0 ; i<strlen(buffer) ; i++){
		printf("%d %c\n" , i ,buffer[i]);
	}

	r=sscanf(buffer, "%s" ,buffer2);
	fgets(buffer2, 10,fp);

	for(int i=0 ; i<strlen(buffer2) ; i++)
        {
                printf("%c" , buffer2[i];

                                }
	printf("%d" , r);

	return 0;
}

