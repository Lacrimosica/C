#include <stdio.h>
#include <stdlib.h>

#define BASE 2

int fib(int);
int fact(long);
void binary(int *, int, int);

int main() {


	int n=3, *array;
       	
//	printf("input n: \n");
	
//	scanf("%d" , &n);

	array=(int *)malloc(n* sizeof(int));
	if(array=NULL){
		fprintf(stdout,"Memory allocation failure.\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout,"binary numbers\n");

	binary(array, 0, n);
	free(array);

	return EXIT_SUCCESS;
}

/*
int fib(int n){
	if( n==0 || n==1)
		return n;
	return (fib(n-2), +fib(n-1));

}
*/
/*
long fact(long n){
	long f=1;
	stack_t stack;
	stack = stack_init();
	while (n>0){
		stack_push (stack,n);
		n--;
	}
	while (stack_size(stack) > 0 ){
		n = stack_pop(stack);
		f = n * f;
	}
	return f;
}

*/
void binary(int *array, int dep, int n){
	int i;
	printf("dep: %d , n: %d", dep,n);

	if(dep>=n){
		for(int i=0 ; i<n ; i++){
			printf("%d" , array[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0; i<BASE; i++){
		array[dep]=i;
		binary(array,dep+1, n);
	}
}


