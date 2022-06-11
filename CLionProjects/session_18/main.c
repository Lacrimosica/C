#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST
#define PRINT_CHECK 1
#define DIM 10+1

//RELATED TO TEST5-FUNCTIONS
//USING RETURN VALUE
int *array_create_2(int n){
    int *ptr;
    ptr =(int *) malloc(n *sizeof(int));
    if (ptr==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    return ptr;
}
//USING PASS BY REFERENCE OF REFERENCE
void array_create_3_0(int **v_ptr, int n) {
    *v_ptr = (int *) malloc(n *sizeof(int));
    if(*v_ptr ==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
}
void array_create_3_1(int **v_ptr, int n){
    int *ptr;   //a local object is used

    ptr =(int *) malloc(n *sizeof(int));
    if (ptr==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    *v_ptr = ptr;
}

//DYNAMICALLY ALLOCATED 1D ARRAY
int main() {
    //VERY IMPORTANT NOTE:
#ifdef TEST1
    char v[10];
    char *p;
    p= malloc(10 *sizeof(char));
    printf("size of v: %d\n size of p: %d\n" , sizeof(v), sizeof(p));
    p=v;
    printf("size of v: %d\n size of p: %d\n" , sizeof(&v[5]), sizeof(p));
#endif

    //INTEGER ARRAY
#ifdef TEST2
    int n, *v;
    printf("introduce n: \n");
    scanf("%d" , &n);
    v=malloc(n *sizeof(int));
    if(v==NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
        //or EXIT_FAILURE
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d" , (v+i) );
    }
    for (int i = 0; i < n; ++i) {
        printf("v[%i] = %i\n" , i, *(v+i));
    }

    free(v);
#endif

    //STRING
#ifdef TEST3
    char string[100+1];
    char *v = (char *)malloc((strlen(string) +1) *sizeof(char));
    if(v==NULL){
        fprintf(stderr, "Memory allocation failed\n");
        EXIT_FAILURE;
    }
#endif

    //STRUCTS
#ifdef TEST4
    struct student{
        char *first_name , *last_name;
        int rn;
        float mark;
    }typedef student;

    struct student *ps;
    int i,n;
    char first_name[DIM], last_name[DIM];

    fprintf(stdout,"introduce n (number of students): \n");
    fscanf(stdin, "%d" , &n);
    ps= (student *)malloc( n * sizeof(struct student));
    if( ps==NULL){
        fprintf(stderr, "Memory allocation error\n");
        EXIT_FAILURE;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(stdout, "firstname,lastname,rn,mark: \n");
        fscanf(stdin, "%s%s%d%f" , first_name, last_name , &ps[i].rn, &ps[i].mark);

        //IMPORT STEP BELOW
        ps[i].first_name = strdup(first_name);
        ps[i].last_name = strdup(last_name);
        //IMPORTANT STEP ABOVE
        if(ps[i].first_name ==NULL || ps[i].last_name == NULL){
            fprintf(stderr, "Memory allocation error");
            EXIT_FAILURE;
        }
    }
    //PRINT THE STUDENTS
    if (PRINT_CHECK) {
        for (int i = 0; i < n; ++i) {
            printf("%s %s %d %f", ps[i].first_name, ps[i].last_name, ps[i].rn, ps[i].mark);
        }
    }
    //IMPORTANT STEP BELOW
    for (int i = 0; i < n; ++i) {
        free(ps[i].first_name);
        free(ps[i].last_name);
    }
    free(ps);
    //IMPORTANT STEP ABOVE
#endif

#ifdef TEST5
    int *v=NULL;
    int n;
    fprintf(stdout, "input array size: \n");
    fscanf(stdin, "%d", &n);

    //FUNCTIONS
    //1-using global variable

    //2-using return
    v=array_create_2(n);
    //3-passing pointer by reference
    array_create_3_1(&v, n);
    //to check if the function has really manipulated the array
    if (v==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }else{
        fprintf(stdout, "Memory allocation OK...continue.\n");

    }
#endif
    return 0;
}
//VERY IMPORTANT NOTE
//strdup:
/*
 * this little function does the below:
 * allocates memory to the sub-struct pointers each by considering the string length of the given string argument
 * checks to see if ti's equal to null or not
 * returns the string given as argument to the pointer
 */