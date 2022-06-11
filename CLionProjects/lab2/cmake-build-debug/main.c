#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define EX2 //toggle to switch between exercises

#ifdef EX1
#define MAX 10
#endif

#ifdef EX2
#define MAX (100+1)
#define R 5
#endif

#ifdef EX3
#define MAX (100+1)
#define L (20+1)
#endif

//Exercise 01
/*-----------

Re-write (and clean-up) the C program of
Laboratory Number 01 Exercise 04
dealing with matrix multiplication, using the following functions:

1. void readDim(int *, int *);
reads the number of rows and the number of columns of a matrix

2. int checkDim(int, int, int, int);
it receives the size of the two matrices and checks for their
        compatibility

3. void readMatrix(float [][MAX], int, int);
reads the matrix m of size r x c from standard input

4. void computeProduct(float [][MAX], int, int,
                       float [][MAX], int, int,
                       float [][MAX], int *, int *);
computes the product
        m3 = m1 x m2.

5. void writeMatrix(float [][MAX], int, int,
                    float [][MAX], int, int,
                    float [][MAX], int, int);
prints out the matrix m1, m2 and the result m3 on standard
        output.


*/
#ifdef EX1
void readDim(int * , int *);
int checkDim(int, int, int, int);
void readMatrix(float [][MAX], int, int);
void computeProduct(float [][MAX], int, int,
                    float [][MAX], int, int,
                    float [][MAX], int *, int *);
void writeMatrix(float [][MAX], int, int,
                 float [][MAX], int, int,
                 float [][MAX], int, int);

int main(){
    int r1,c1,r2,c2,r3,c3;
    float m1[MAX][MAX], m2[MAX][MAX], m3[MAX][MAX];
    readDim(&r1,&c1);
    readDim(&r2,&c2);

    if(checkDim(r1,c1,r2,c2)){
        readMatrix(m1, r1,c1);
        readMatrix(m2, r2,c2);
    }
    computeProduct(m1, r1, c1, m2, r2, c2, m3, &r3, &c3);
    writeMatrix(m1, r1, c1, m2, r2, c2, m3, r3, c3);
}


void readDim(int *r, int *c){
    fprintf(stdout, "input row and column:\n");
    fscanf(stdin,"%d %d", r ,c );
}

int checkDim(int r1, int c1, int r2 , int c2){
    if(r1<MAX && c1<MAX && r2<MAX && c2<MAX){
        if(c1==r2){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

void readMatrix(float m[][MAX], int r, int c){
    int i,j;
    fprintf(stdout, "input matrix\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            fscanf(stdin, "%f" , &m[i][j]);
        }
    }
}

void computeProduct(float m1[][MAX], int r1, int c1,
                    float m2[][MAX], int r2, int c2,
                    float m3[][MAX], int *r3, int *c3){
    *r3=r1;
    *c3=c2;

    for (int i = 0; i < *r3; ++i) {
        for (int j = 0; j < *c3; ++j) {
            for (int n = 0; n < c1; ++n) {
                m3[i][j]+=m1[i][n] * m2[n][j];
            }
        }
    }
}

void writeMatrix(float m1[][MAX], int r1, int c1,
                 float m2[][MAX], int r2, int c2,
                 float m3[][MAX], int r3, int c3) {

    {
        int i, j;

        for (i = 0; i < r1; i++) {
            for (j = 0; j < c1; j++) {
                printf("%7.2f ", m1[i][j]);
            }
            printf("\n");
        }

        printf("*\n");
        for (i = 0; i < r2; i++) {
            for (j = 0; j < c2; j++) {
                printf("%7.2f ", m2[i][j]);
            }
            printf("\n");
        }
        printf("=\n");
        for (i = 0; i < r3; i++) {
            for (j = 0; j < c3; j++) {
                printf("%7.2f ", m3[i][j]);
            }
            printf("\n");
        }
    }
}
#endif


//Exercise 02
/*-----------

A file contains a text with an unknown number of rows, but with lines
        of maximum length equal to 100 characters.

Write a C program able to find and count-up the number of:
- horizontal sequences made up of 5 adjacent 'h' characters
('h' like in "horizontal") on the same row
- vertical sequences made up of 5 adjacent 'v' characters
('v' like in "vertical") on the same column.

Notice that, as the length of the file is unknown, it cannot be stored
entirely at the same time into the main memory (i.e., it can only be
stored into the main memory a piece at a time).
Moreover, it is not possible to read the file more than once.

The program:
- receives on the command line the name of the file
- prints out (on standard output) the number of times the "hhhhh"
sequence appears on a row, and the number of times the sequence
"vvvvv" appears on a column.

Example
-------

Let the input file be the following one:

Regression file:
Line with two hhhhhorizontal sequences hhhhh!
From hereinafter  vv
v all rows        vv
v include         vv
v two vertical    vv
v sequences       v
v and one horizontal ---> hhhhh!

The output will be:
Horizontal Sequence: 3
Vertical Sequence  : 2

Suggestions
-----------

- Read the file on a line-by-line basis using fgets, like
while (fgets ( ... ) != NULL) { ... }
- Looking for horizontal sequences on "h"s is straightforward just
storing single line of the file into the main memory.
To check for vertical sequences of "v"s there are two main
        possibilities:
a. Work on single lines, keeping an array of (100) counters
        b. Work on a matrix which stores 5 rows of the file at the same
        time. Once the check has been performed scroll ("shift") all
        rows up and read the last one from file.


*/
#ifdef EX2
int read(char [MAX], FILE *);
int check_v(char [MAX],int [MAX]);
int check_h(char [MAX]);
void clean(char [][MAX], int);

//second method
int check_h2(char mat[R][MAX]);
int check_v2(char [][MAX]);
void CopyRow(char[][MAX], char []);
void clean3(char row[]);
void copyRow3(char mat[R][MAX] , char row[MAX]);

int main(int argc, char *argv[]){
    FILE *fp;
    char row[MAX];
    int count[MAX];
    int i,nh=0,nv=0;

    //second method
     char mat[R][MAX];

    if(argc!= 2){
        fprintf(stderr, "Wrong number of arguments. correct form : <%s> <file_name>.\n" , argv[0]);
        exit(EXIT_FAILURE);
    }

    fp=fopen(argv[1], "r");
    if(fp==NULL){
        fprintf(stderr,"Error Reading file \n");
        exit(EXIT_FAILURE);
    }


    //reset counter
    for (i = 0; i < MAX; ++i) {
        count[i]=0;
    }
    nh=nv=0;

    //second method
     for(i=0 ; i<R ; i++){
         clean(mat,i);
     }
    while(read(row, fp) == 1){
        printf("reached here at least");
        nh+=check_h(row);
        nv+=check_v(row, count);
    }

    //third method
    for( i=0; i<MAX ; i++)

#if 0
     while(read(row,fp) ==1){
         copyRow(mat,row);
         nh+= check_h2(mat);
         nv+= check_v2(mat);
     }
#endif

    fclose(fp);

    fprintf(stdout, "Horizontal Sequence: %d\n", nh);
    fprintf(stdout,"Vertical Sequence  : %d\n" , nv);

    return 0;
}

int read(char row[MAX], FILE *fp){
    int i;

    if(fgets(row, MAX , fp) == NULL){
        return 0;
    }

    for (int i = strlen(row); i < MAX; ++i) {
        row[i]= ' ';
    }
    return 1;
}

int check_h(char row[MAX]){
    int i,n;

    n=0;

    for(i=0; i< MAX-R ; i++){
        if(row[i]=='h' && row[i+1]=='h' && row[i+2]=='h' && row[i+3]=='h' && row[i+4]=='h' ){
            n++;
        }
    }
    return n;
}

int check_h2(char mat[R][MAX]) {
    int i, n;
    n = 0;

    for (i = 0; i < MAX; i++) {
        if (mat[R - 1][i] == 'h' && mat[R - 1][i + 1] == 'h' && mat[R - 1][i + 2] == 'h' && mat[R - 1][i + 3] == 'h' &&
            mat[R - 1][i + 4] == 'h') {
            n++;
        }
    }
    return n;
}

void copyRow(char mat[R][MAX] , char row[MAX]){
    int i,j;

    for(i=0 ; i<R-1; i++){
        clean(mat,i);           //cleans all rows of the matrix except the last row
        for(j=0; j<MAX; j++){       //shift the curret rows one level up after cleaning the row before
            mat[i][j] = mat[i+1][j];
        }
    }

    clean(mat, R-1);            //cleaning the last row of the matrix (this is done after it is shifted up and saved
    for(j=0; j<MAX ; j++){
        mat[i][j] = row[j];         //inserting the buffer row on the last row
    }
}

void copyRow3(char mat[R][MAX] , char row[MAX]){
    int i;
    for(i=0 ; i<R-1; i++){
        clean3(mat[i]);
        strcpy(mat[i] , mat[i+1]);
    }

    clean3(mat[R-1]);
    strcpy(mat[R-1] , row);
}

int check_v(char row[MAX],int count[MAX]) {
    int i, n;

    n = 0;
    for (i = 0; i < MAX; ++i) {
        if (row[i] != 'v') {
            count[i] += 0;
        } else {
            count[i]++;
            if (count[i] >= 5) {
                n++;
            }
        }
    }
    return n;
}

int check_v2(char mat[R][MAX]){
    int i,n;
    n=0;
    for (i=0;  i<MAX ; i++) {
        if(mat[0][i] =='v' && mat[1][i] == 'v' && mat[2][i] == 'v' && mat[3][i] == 'v' && mat[4][i] == 'v'){
            n++;
        }
    }
    return n;
}

void clean(char mat[R][MAX], int i){
    int j;
    for (j=0;j< MAX;j++) {
        mat[i][j]= ' ';
    }
}

void clean3(char row[]){
    int i;

    for(i=1 ; i<MAX ; i++){
        row[i] = ' ';
    }
    row[0]='\0';
}

#endif

//Exercise 03
/*-----------

A C program is run with 4 parameters on the command line:

string1 file1 string2 file2

where file1 and file2 are file names and string1 and string2 are C
        strings.
It makes a copy of the content of file1 (input file) into file2
        (output file) by substituting each sequence of characters equal to
string1 with the string2 sequence.

Notice that:
* file1 contains an unknown number of rows, but each row is at
        most 100 characters long
        * string1, string2 and all C strings in file1 are at most 20
20 characters long
        * string1 and string2 are proper C strings, i.e., they to not
        contain spaces, tabs, etc.
* all rows that have to be stored into file2 are also shorter than 100
characters.

Example
-------

Let us suppose to run the program with the following parameters:

test file1.txt check file2.txt

        and that file1.txt is the following:

Regression file.
This file is to test the program.
In the previous line we should have a substitution (testWITHcheck).
Here we should not have it: t-e-s-t.

The following file2.txt has to be generated:

Regression file.
This file is to check the program.
In the previous line we should have a substitution (checkWITHcheck).
Here we should not have it: t-e-s-t.

Suggestions
-----------

- Read the file on a line-by-line basis using fgets, like
while (fgets ( ... ) != NULL) { ... }
- Search string1 as a sub-string in each row
- For each hit, before moving on with the next search, write into
file2 everything coming before string1 and then string2 instead of
string1.

*/
#ifdef EX3
void subText(char [], FILE *, char [], FILE *);
void subStringReplace(char [], char [], char [], char []);
int searchSubStr(char[] , char[] , int);

int main(int argc, char *argv[]){
    FILE *fpR , *fpW;

    if(argc !=5 ){
        fprintf(stderr, "wrong number of arguments.\n");
        return EXIT_FAILURE;
    }

    fpR=fopen(argv[2], "r");
    fpW=fopen(argv[4], "w");
    if(fpR==NULL || fpW==NULL){
        fprintf(stderr, "One or both of the files doesn't exist\n");
        return EXIT_FAILURE;
    }

    subText(argv[1], fpR, argv[3], fpW);

    fclose(fpR);
    fclose(fpW);


    return 0;
}

void subText(char from[MAX] , FILE *fpR, char to[MAX] , FILE *fpW){
    char buff[MAX];
    char s[MAX];

    while(fgets(buff, MAX, fpR) != NULL){       //get lines from the file and store them in buff
        subStringReplace(buff, from,to,s);          //s is the final return string written to the fpW
        fprintf(fpW, "%s",s);
    }
}

void subStringReplace(char s1[], char s2[], char s3[], char s4[]){  //subStringReplace(buff, from,to,s);
    int i, idx, from, to, endFlag;
    endFlag = from = idx =0;
    do{
        to = searchSubStr(s1,s2,from);          //search ffor s2 in s1 and return the index
        if(to< 0 ){     //if the substring is not found,
            to = strlen(s1);        //pass over the whole string by it's length
            endFlag=1;              //end the cycle
        }
        for (i = from; i < to; ++i) {
            s4[idx] = s1[i];           //s4 is the string we ultimately return and is written by fpW
                    idx++;
        }
        if(endFlag==0){
            for (i = 0;  i< strlen(s3) ; i++) {   //s3 is the second string that we want to substitute the first string with
                s4[idx]= s3[i];
                idx++;
            }
        }
        from= to+strlen(s2);    //moves forward the from index and int he next turn searches for it again
    }while(endFlag!=1);

    s4[idx]= '\0';
}

void subStringReplace2(char s1[], char s2[], char s3[], char s4[]){
    char *start, *end;

    s4[0] = '\0';       //this is important
    start=s1;
    do{
        end=strstr(start,s2); //looks for s2 in start (s1)

        if(end ==NULL){
            strcat(s4,start); //in case s2 is not found, s4 and s1 are concatenated

        }else{
            *end= '\0'; //we put a terminator at the index where the string is found and it cuts the start string
            strcat(s4,start);
            strcat(s4,s3);
            start = end + strlen(s2);
        }
    }while(end !=NULL);
}

int searchSubStr(char str1[], char str2[], int from) {
    int i, j, flag;

    i = from;
    while (i < strlen(str1) - strlen(str2)) {
        flag = j = 0;
        while (j < strlen(str2) && flag == 0) {
            if (str1[i + j] != str2[j]) {
                flag = 1;
            }
            j++;
        }
        if (flag == 0) {
            return i; //returns the index from which the substring starts
        }
        i++;
    }
    return -1;
}

#endif