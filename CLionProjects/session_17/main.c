#include <stdio.h>
#include <stdlib.h>

#define TEST 0
//DYNAMIC MEMORY ALLOCATION
//to define the size of the data structure at run time
//malloc, calloc,realloc,free the 2nd and 3rd are the modification of the first one

//MALLOC PROTOTYPE
//void *malloc (size_t number_of_bytes);
//notes:
//the void pointer is used
//size_t is a type of integer, it is showing here that the number of bytes is an integer
//malloc is a pointer, a generic, void pointer
//when we use it , we cast it into a specific type of pointer from a generic one as seen in the example:

//CALLOC PROTOTYPE:
//void *calloc (size_t number_of_objects, size_t size);
//notes:
//calloc initializes the memory, the integers with 0 and the character with NULL
//therefore it is slower than malloc

//REALLOC PROTOTYPE:
//void *realloc(void *ptr, size_t size);
//to reallocate something, you can allocate and then modify the allocation with realloc
//it gets a pointer as first parameter,
//you can give the pointer of a previously allocated memory with malloc and calloc, but if you
//are just adding a NULL pointer, that can be done by malloc and calloc
//shrinking is alsmost always ok and can be done, but in the case of inlargement it can be tricky, if even possible, it
//can be done "in place" or "in another place", meaning that in the second case all that is already written somewhere is
//to be copied somewhere else and this is very expensive
//IN CASE THE RE_ALLOCATION FAILS,THE RETURN VALUE POINTER WILL POINT TO NULL*****

//FREE PROTOTYPE:
//void free(void *pointer);
//the pointer type is void so that any pointer specific or generic, given to it can be freed in the end
//to free the memory, given the pointer that is midway somewhere, from that point on, the memory is freed and given back
//to the operating system and no longer usable, although the stuff already written there might still be there
//for each single malloc you need a free
int main() {


    //char *p;
    //p=(char *) malloc (100);

    //malloc is cast into char *, a character pointer, with 100bytes
    //there is no explicit need to cast, if like in this case p is already defined as a char pointer so like this:
    //p=malloc(100);
    //integers like 100,160 or whatever, are not common, the more common syntax is as below:
    //struct node *newPtr
    //newPtr = malloc (1* sizeof(struct node));

    //CORRECT SYNTAX TO IMPLEMENT MEMORY ALLOCATION
    if(TEST) {
        //malloc
        int *p;
        p = (int *) malloc(1 * sizeof(int));
        if (p == NULL) {
            fprintf(stderr, "memory allocation error.\n");
            exit(1);
        }
        fprintf(stdout, "introduce an integer value: ");
        scanf("%d", p);

        //calloc
        int *test;
        test = (int *) calloc(5, sizeof(int));
        if (test == NULL) {
            fprintf(stderr, "memory allocation error,\n");
            exit(1);
        }

        //realloc
        int *v1, *v2, *v3;

        v1 = malloc(50 * sizeof(int));
        if (v1 == NULL) {
            fprintf(stderr, "memory allocation failed:\n");
            exit(1);
        }

        v2 = realloc(v1, 100 * sizeof(int));
        if (v2 == NULL) {
            fprintf(stderr, "memory allocation failed:\n");
            exit(1);
        }

        v3 = realloc(v2, 200 * sizeof(int));
        if (v3 == NULL) {
            fprintf(stderr, "memory allocation failed:\n");
            exit(1);
        }

        //free
        int n, *ptr;
        fprintf(stdout, "intorduce n:");
        scanf("%d", &n);

        ptr = (int *) malloc(n * sizeof(int));
        if (ptr == NULL) {
            fprintf(stderr, "memory allocation failed:\n");
            exit(1);
        } else {
            //use ptr
        }
        //when p is no longer needed
        free(ptr);
    }

    return 0;
}
