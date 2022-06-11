#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int [8], int, int);
int max(int [], int , int);
int fact(int);
int main() {
	int r;
	int v[8]={1,2,3,4,5,6,7,8};
	r=fact(5);
	printf("%d\n", r);
	return r;

}//factorial
/*
int fact(int a){

	if(a==0){
		return 1;
	}
	
	return(a* fact(a-1)) ;

}
 */
//MAX
/*int max(int a[] , int l, int r){
	int u,v,c;
	if(l>=r)
		return a[l];
	c= (l+r)/2;

	u=max(a,l,c);
	v=max (a, c+1,r);
	if(u>v)
		return u;
	else
		return v;
}
*/
//going through elements
/*void show(int v[8], int l, int r){
	int i,c;
	printf("\n");

	if(l>=r){
		return;
	}
	c=(r+l)/2;
	printf("\n");
	for(i=0; i<=c; i++){
		printf("v[%d] to v[%d] =%d\n" ,i,c, v[i]);
	}
	printf("-----------------");
	show(v,l,c);
	
	printf("\n");

	for(i=c+1; i<=r; i++){
		printf("v[%d] to v[%d] = %d\n" ,i,r, v[i]);
	}
	printf("---------------------");
	show(v,c+1,r);

	return;
}
*/
