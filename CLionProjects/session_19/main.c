#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define BROKENLINE 1
#define TWODARRAY 1
//BROKEN LINES
#ifdef BROKENLINES
//another syntax for struct below
typedef struct{
    int x1,y1,x2,y2;
    int used1,used2; //to counter to determine how many connections ther are on each end
}segment_t;
//funtion prototypes
//there is no need to specify a name for parameters
segment_t *load(char *, int *);
//going to receive file name and number of segments and will return a pointer to the array that will store the segments
void connect(segment_t *, int);
void check(segment_t *, int);
int main(int argc, char *argv[]) {
    segment_t *segments; //a pointer to the beginning of an array that will contain all the segments, and is of type segment_t
    int n;

    segments = load(argv[1] , &n); //the number of segments is passed by address
    connect (segments, n);
    check (segments,n);

    free(segments);         //important to free the array

    return EXIT_SUCCESS;
}
//another section must be added to this part to discard and not consider them
segment_t *load(char *name, int *n){
    int i,x1,y1,x2,y2;
    segment_t *segments;
    FILE *fp;

    fp =fopen(name, "r");
    if(fp == NULL){
        fprintf(stderr , "File open error.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp,"%d" , n);
    segments = (segment_t *) malloc(*n * sizeof(segment_t));
    if(segments == NULL){
        fprintf(stderr , "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    i=0;
    //IMPORTANT
    //IMPLEMENTATION OF FILE READING
    while(i< *n && fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2) != EOF){
        segments[i].x1=x1;
        segments[i].y1=y1;
        segments[i].x2=x2;
        segments[i].y2=y2;
        segments[i].used1 =0;
        segments[i].used2 =0;
        i++;
    }
    *n =i;
    flcose(fp);

    return segments;
}
void connect(segment_t *segments, int n){
    int i,j;
    //quadratic cost here
    //kind of an insertion sort loop
    for (i = 0; i < n-1; ++i) {
        for (j = i+1; j < n; ++j) {

        }
    }
}
void check(segment_t *segments, int n){

    //to be added later
}
 */
#endif

//DYNAMICALLY ALLOCATING 2D ARRAY

#ifdef TWODARRAY
//i=r.C +c
//r= i/C
//c= i%C

void main(void){
    //INTEGERS

    int r,c,i;
    //the matrix which is a 1D array of integer pointers,they will then each point to another array each
    int **mat;
    fprintf(stdout, "introduce the number of rows: \n");
    fscanf(stdin, "%d" , &r);

    mat = (int **) malloc(r * sizeof(int *)); //IMPORTANT
    if(mat==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "introduce the number of columns: \n");
    fscanf(stdin, "%d" , &c);

    for(i=0 ; i<r ;i++){
        mat[i] =(int *)malloc(c * sizeof(int)); //IMPORTANT
        if (mat[i] == NULL){
            fprintf(stderr, "Memory Allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }
    //freeing the memory
    //order is important
    for (int i = 0; i < r; ++i) {
        free(mat[i]);
    }
    free(mat);
}

#endif