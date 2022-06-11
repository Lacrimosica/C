#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//PASSING 2D MATRICES TO FUNCTIONS
//f(int **m)  : other syntax's do exist as well
//a linear array with pointers to something


//fgets gets the newline
//CROSS-PUZZLE

//macro
#define  max(R,C) ((R>C)?R:C)

void PrintArray2d(char **,int , int );
//function prototypes
char **malloc2d(int,int);
char **free2d(char **,int);
void find(char *, char **, char **, int,int);
int find_all(int,int,char *, char **, char **, int ,int);

int main(int argc , char *argv[]) {
    int i, j, R, C;
    FILE *fp;
    char *word;
    char **matrixIn, **matrixOut;

    //input check
    if (argc < 4) {
        fprintf(stderr, "Wrong number of arguments <matrix_file> <word_file>, <output file>\n");
        exit(EXIT_FAILURE);
    }
    //reading puzzle file
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Reading error on file= %s\n", argv[1]);
        return 1;
    }
    //getting size of puzzle
    if (fscanf(fp, "%d%d%*c", &R, &C) == EOF) {    //skipping newline character
        fprintf(stderr, "Read file error.\n");
        return 1;
    }

    //allocating memory to matrices
    matrixIn = malloc2d(R, C);
    matrixOut = malloc2d(R, C);

    //allocating memory for word
    //for avoiding a different memory size for word each time
    word = (char *) malloc((max(R, C) + 1) * sizeof(char));
    if (word == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    //filling matrixIN with the values on the map
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; ++j) {
            //very important step below
            fscanf(fp, "%c", &matrixIn[i][j]);
        }
        fscanf(fp, "%*c"); //skip \n
    }
    fclose(fp);


    //reading words file
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        fprintf(stderr, "file opening error on %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    //read each string of word and look for it in the map
    while(fscanf(fp,"%s", word)!=EOF){
        find(word,matrixIn,matrixOut,R,C);
        printf("%s\n", word);
    }
    fclose(fp);

    //opening output file and writing in it
    fp=fopen(argv[3], "w");
    if(fp==NULL){
        fprintf(stderr, "Error reading file %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    //writing in the output file the values of matrixOUT
    for(i=0; i<R;i++) {
        for (j = 0; j < C; ++j) {
            fprintf(fp,"%c", matrixOut[i][j]);
        }
        fprintf(fp,"\n"); //skip \n
    }
    fclose(fp);


    free(word);
    free2d(matrixIn, R);
    free2d(matrixOut, R);

    return EXIT_SUCCESS;
}

void find(char *word, char **matrixIn, char **matrixOut, int R,int C){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if(matrixIn[i][j] == word[0]) {
                //printf("char for %s found on  = (%d,%d)\n", word,i,j);
                //printf("%c ? %c\n", matrixIn[i][j], word[0]);
                find_all(i, j, word, matrixIn, matrixOut, R, C);
            }
        }
    }
}

int find_all(int row,int col ,char *word, char **mIn, char **mOut, int R,int C){
    int r,c,i,j;
    char flag;
    char found;
    int offsets[2][8]={{0, -1, -1 , -1, 0 , 1 , 1 , 1},
                       {1 , 1 , 0 , -1, -1, -1, 0, 1} };


    for (i = 0; i < 8 && !found; ++i) {
        flag=1;
        found=0;
        for (j = 0; j < strlen(word) && flag; ++j) {
            r=row+j* offsets[0][i];
            c=col+j* offsets[1][i];
            if(r< 0 || r>=R || c<0 || c>= C || mIn[r][c] !=word[j]){
                flag=0;
                //printf("j= %d, exiting j cycle\n",j);
            }
        }
        if(flag ==1){
            for (j=0; j <strlen(word) ; j++) {
                mOut[row+j*offsets[0][i] ][col+j*offsets[1][i] ] = word[j];
                if(j==strlen(word)-1){
                    found=1;
                }
            }
            return 1;

        }
    }
    return 0;
}

char **malloc2d(int r ,int c){
    char **mat;
    int i,j;

    mat = (char **)malloc(r* sizeof(char *));
    if(mat ==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < r ; ++i) {
        mat[i]= (char*) malloc( c  * sizeof (char));
        if(mat[i] ==NULL){
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
    }

    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            mat[i][j] = ' ';
        }
    }
    return mat;
}

char **free2d(char **mat ,int c){
    int i;
    for (i = 0; i < c; ++i) {
        free(mat[i]);
    }
    free(mat);

    return mat;
}


void PrintArray2d(char **A,int R, int C){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%c", A[i][j]);
        }
        printf("\n");
    }
}