#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MYERR(...) do{ \
	printf("@ %s (%d): ", __FILE__, __LINE__); \
	printf(__VA__ARGS__); \
}while(0)

#define EX2   //TOGGLE BETWEEN EXERCISES EX1A EX1B EX2


//Exercise 01 (A and B)
/*---------------------

A file has the following format:
- the first row contains an integer number n
- the following n rows store a string (each string is terminated
        by a '\n' character).
The longest string included in the file is 100 character long but
the average string length is much smaller (e.g., 10 characters).

A C program receives two file names on the command line (input and
output file names).
The first file has the format previously specified.
The program:
1) reads the content of the first (input) file and stores all strings
into a dynamic data structure
2) orders the strings in alphabetic order
3) stores the strings in the second (output) file.
The output file has the same format of the input one.

Write two versions of the program:

- Version A
It stores words in an 1D dynamic array of structures including
        a dynamically allocated string:

struct string {
    char *str;
};

- Version B
It stores the words in a dynamic matrix:

char **mat;

In this second version, is it necessary to swap the actual strings
        or is it sufficient to swap pointers to strings?
//i think swapping the pointers would be enough
Example
-------

The following is an example of the input file:

10
this
is
an
example
of
file
used
to
order
strings

and the following is the corresponding output file:

10
an
example
file
is
of
order
strings
this
to
used
*/
#ifdef EX1A
#define MAX_STRING_LENGTH 100

typedef struct string_t{
    char *str;
}string;

string *read(char *name, int *);
void string_sort(string * strings, int n);
void write(char *name, string *, int num);

int main(int argc, char *argv[]){

    string *string_list;
    int num_strings;

    if(argc!=3){
        fprintf(stderr, "Wrong number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    string_list = read(argv[1], &num_strings);
    string_sort(string_list, num_strings);
    write(argv[2], string_list, num_strings);

    for (int i = 0; i < num_strings; ++i) {
        free(string_list[i].str);
    }
    free(string_list);
}

string *read(char *name, int *num_ptr){

    int i,n;
    FILE *fp;
    string *strings;
    char buffer_string[MAX_STRING_LENGTH];

    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error opening file %s (%d)\n" , name, __LINE__);
        exit(EXIT_FAILURE);
    }

    if(fscanf(fp, "%d" , &n) == EOF){
        fprintf(stderr, "Error reading the file %s (%d)\n" , name, __LINE__);
        exit(EXIT_FAILURE);
    }

    strings= (string *)malloc(n * sizeof(string));
    if(strings==NULL){
        fprintf(stderr, "Memory allocation error (%d).\n" , __LINE__);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fscanf(fp, "%s" , buffer_string)!=EOF && i<n){
        strings[i].str=strdup(buffer_string);
        i++;
    }

    *num_ptr=n;
    fclose(fp);
    return strings;
}

void string_sort(string * strings, int n){
    int i,j,k,flag=1;
    string current;
    printf("got here\n");
    printf("%d %s %s %s\n", n, strings[0].str, strings[1].str, strings[n-1].str);

    for (i = 1; i < n; i++) {
        current = strings[i];
        j = i - 1;

        while (j >= 0 && (strcmp(current.str,strings[j].str))< 0) {
            strings[j + 1]=strings[j];
            j--;
        }
        strings[j + 1] = current;
    }
    printf("finished sorting\n");
}

void write(char *name, string *str, int num){
    FILE *fp;
    fp=fopen(name, "w");
    if(fp==NULL){
        fprintf(stderr, "Error opening file %s (%d)" , name, __LINE__);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d\n", num);
    for (int i = 0; i < num; ++i) {
        fprintf(fp,"%s\n", str[i].str);
    }
    fclose(fp);
}
#endif

#ifdef EX1B
#define MAX_STRING_LENGTH 100

void read(char *,char  ***, int *);
void string_sort(char ***, int n);
void write(char *,char ***, int num);

int main(int argc, char *argv[]){
    char **mat;
    int num_strings;

    if(argc!=3){
        fprintf(stderr, "Wrong number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    read(argv[1], &mat,  &num_strings);
    string_sort(&mat, num_strings);
    write(argv[2], &mat, num_strings);

    //freeing section
    for (int i = 0; i < num_strings; ++i) {
        free(mat[i]); //or alternative
    }
    free(mat);

}

void read(char *name,char  ***mat, int *num_ptr){

    int i,n;
    FILE *fp;
    char buffer_string[MAX_STRING_LENGTH];
    char **m=*mat;
/*    alternatively:
    char *buffer_string;
    buffer_string= (char *)malloc(MAX_STRING_LENGTH * sizeof(char ));*/

    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error opening file %s (%d)\n" , name, __LINE__);
        exit(EXIT_FAILURE);
    }

    if(fscanf(fp, "%d" , &n) == EOF){
        fprintf(stderr, "Error reading the file %s (%d)\n" , name, __LINE__);
        exit(EXIT_FAILURE);
    }



    m=(char **)malloc(n * sizeof(char *));
    if(m==NULL){
        fprintf(stderr, "Memory allocation error (%d).\n" , __LINE__);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fscanf(fp, "%s" , buffer_string)!=EOF && i<n){
        m[i]=strdup(buffer_string);
        i++;
    }

    *mat=m;
    *num_ptr=n;
    fclose(fp);
}

void string_sort(char ***mat, int n){
    int i,j;
    char *current;
    char **m=*mat;

/*
    printf("%d %s %s %s\n", n, m[0], m[1], m[n-1]);

    for (int i = 0; i < n; ++i) {
        printf("mat[%d] = %s\n" , i, m[i]);
    }
    printf("got here (%d)\n" , __LINE__);
*/

    for (i = 1; i < n; i++) {
        /*ways to print this and stuff
        printf("%s", *(m+i));
        printf("%s", *(*mat+i) );*/
        current=strdup(m[i]);
        j = i - 1;

        while (j >= 0 && (strcmp(current ,m[j]))< 0) {
            m[j+1]=m[j];
            j--;
        }
        m[j+1] = current;
    }
    *mat=m;
}

void write(char *name,char ***mat, int num){
    FILE *fp;
    fp=fopen(name, "w");
    char **m=*mat;

    if(fp==NULL){
        fprintf(stderr, "Error opening file %s (%d)" , name, __LINE__);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d\n", num);
    for (int i = 0; i < num; ++i) {
        fprintf(fp,"%s\n", m[i]);
    }
    fclose(fp);
}

#endif
//Exercise 02

/*-----------

A matrix of strings is stored in a file with the following format:

R C
string_1_1 string_1_2 string_1_3 ... string_1_C
...
string_R_1 string_R_2 string_R_3 ... string_R_C

where R and C are integers, representing the number of rows and
columns of the matrix, and string_i_j are the strings stored in
the matrix.
Each string is at most 20 characters long.
Notice that strings on each row are already alphabetically ordered.

Write a C program able to "merge" all strings in the matrix in a
single array of strings, i.e., to store all strings of the matrix
in a unique array containing all strings alphabetically ordered.

Notice that:
1. the array has a number of elements equal to RxC, and
each element contains a string
2. as the strings on each row of the matrix are already ordered,
strings do not need to be re-ordered completely to generate the
final array.
See the "suggestions" for further details.

The result has to be stored in an output file, which contains
the total number of strings on the first row, and all string in the
following lines.

Example
-------

The following is an example of input file:

4 3
milano torino venezia
bari genova taranto
firenze napoli roma
bologna cagliari palermo

and the following is the corresponding output file:

12
bari
bologna
cagliari
firenze
genova
milano
napoli
palermo
roma
taranto
torino
venezia

Suggestions
-----------

- The dynamic matrix has to be defined as:
char ***mat;
Allocate it accordingly:
- first, allocate the column of pointers to pointers to characters
- then, allocate the rows of pointers to characters
- finally, allocate the strings.

- The "strdup" function can be used to avoid string allocation.

- To merge two "already ordered" array it is possible to use a "merge"
algorithm which is much more efficient than a sorting algorithm.

Merge uses the following scheme.

1. Let us suppose A and B are two ordered arrays that have to be merged into array C.
2. Set a=0 and b=0 and c=0
3. As A is sorted A[a] is the smallest element within A.
As B is sorted B[b] is the smallest element within B.
Then, the smallest element between A[a] and B[b] is the smallest
overall, and it can be copied into array C before any other
element.
That is:

if (A[a]<B[b]) {
C[c]=A[a]; a++;
} else {
C[c]=B[b]; b++;
}
c++;

4. After that, repeat all steps from step 3, until all elements
within A OR  B have been copied into C.

5. At this point, copy the remaining element of A OR B (the one with
remaining elements) into C.

Notice that merge has a linear time cost whereas sorting is linearithmic or
quadratic.
In this case, it is sufficient to "merge" all rows of the matrix (i.e.,
array of strings) in a single array of strings.
 */

#ifdef EX2
//./lab5 input2.txt output2.txt

#define MAX_STRING_LENGTH 20
typedef struct string_t{
    struct string_t *next;
    struct string_t *previous;
    struct string_t *up;
    struct string_t *down;
    char *str;
    int visisted;
}string;

void read(char *, string ****, int *, int *);

void merge(string ****, int, int);
void write(char *name, char **);



int main(int argc, char *argv[]){
    string ***mat;
    char *all_string;
    int R, C;
    int i,j;
    if(argc!=3){
        fprintf(stderr, "Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    read(argv[1], &mat, &R , &C);
    merge(&mat, R,C);
    write(argv[2], &all_string);


    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            free(mat[i][j]);
        }
        free(mat[i]);
    }
    free(mat);
}

void read(char *name, string ****mat , int *R, int *C){
    string ***m;
    FILE *fp;
    int r,c,i,j;
    char buffer[MAX_STRING_LENGTH];

    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error opening file %s" , name);
        exit(EXIT_FAILURE);
    }


    if(fscanf(fp, "%d%d" , &r, &c)==EOF){
        fprintf(stderr, "Error reading file.\n");
        exit(EXIT_FAILURE);
    }

    m=(string ***)malloc(r * sizeof(string **) );
    if(m==NULL){
        fprintf(stderr, "Memory allocation error (%d)" , __LINE__);
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < r; ++i) {
        m[i]=(string **)malloc(c * sizeof(string *));
        if(m[i]==NULL){
            fprintf(stderr, "Memory allocation error (%d)" , __LINE__);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < r; ++i) {
        j=0;
        while (j<r && fscanf(fp, "%s" , buffer) !=EOF){
            m[i][j]->str=strdup(buffer);
            m[i][j]->visisted=0;
            j++;
        }
    }

    *mat=m;
    *R=r;
    *C=c;
    fclose(fp);
}
void merge(string ****mat , int R, int C){
    int r,c,i,j;
    int pre_i,pre_j;
    int last=0;
    string ***m, *str;
    //or char str[180] or str[(MAX_STRING_LENGTH+1)*3*3]
    m=*mat;

    printf("****mat :%d\n" , sizeof(mat));
    printf("***mat :%d\n" , sizeof(*mat));
    printf("**mat :%d\n" , sizeof(**mat));
    printf("*mat :%d\n" , sizeof(***mat));
    printf("mat :%d\n" , sizeof(****mat));
    //str=(char *)malloc( sizeof(mat) *sizeof(char) );

    r=1;
    c=0;
    j=0;
    i=0;
    pre_i=i;
    pre_j=j;
    while(j<C-1){//for(j=0; j<C; j++){
        i=pre_i;
        r=1;
        while(i<R-1){ //for(i=pre_i ;i<R-1 ;i++)
            //j=pre_j;
            if(strcmp(m[i][j]->str, m[i+r][j-c]->str)<0 || !(m[i][j]->visisted) ){
                r++;
            }else{
                i++;
                j=pre_j;
                r=1;
            }
        }
        pre_i=i;
        pre_j=j;
        c++;
        j++;
    }





    strcpy( (str+last) , m[i][j]->str);
    m[i][j]->visisted=1;
    last+=strlen(m[i][j]->str);   //(str+last) = strdup(m[i][j]);


    *mat=m;
}
#endif