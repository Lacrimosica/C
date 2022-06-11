#include <stdio.h>
#include <stdlib.h>

//Dynamic memory allocation and pointers
/*
 *there is no difference between int* p , int * p, int *p
 * void pointer:
 * it is used as a generic pointer for an unspecified type and it is used to cast a specific pointer to a generic type
 * and eventually to a specific type
 * the c compiler knows what each pointer is pointing to
 */

/*
 * indirection operator:
 *  the *, when it is used before a pointer, it means i'm referring to the content pointed to by the pointer.
 *
 * the address operator:
 * the &, when used before a variable, it return it's address. so:
 *
 *  int countPtr, count;
 *
 *  countPtr = &count
 *  *countPtr = 10 //for example same as count=10
 *  count = *countPtr
 *
 */
swap(int *a, int *b);
int main() {
    float *ptr;
    float f;

    f= 7.5;
    ptr = &f;
    fprintf(stdout, "%f %f\n", f,*ptr);
    fprintf(stdout, "0X%lu\n", ptr);


    //NULL pointer

    float *ptr2=NULL; //to initialize the pointer to point to nothing
    fprintf(stdout, "0X%lu\n", ptr2); //prints out 0X0


    //passing by reference
    int array[2]={1,2};
    swap(&array[0],&array[1]);
    printf("%d, %d", array[0],array[1]);

    //pointer arithmetics
    //it is important to note in order to move forward on the memory, you should consider the type of pointer you are
    //using because the size of each type is different
    //you cannot point to the middle of something
    //because everything is logically synced.

    return 0;
}

//passing values by reference to functions
//exchanging values;
swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}