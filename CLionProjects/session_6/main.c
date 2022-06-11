#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------------------------------------------------------------------------------------------------------------
//SUB MATRIX SEARCHING

//let DIM1 and DIM2 be two integer constants, with DIM1 larger than DIM2. write a program to be able to:
//read from standard input two integer matrices, m1 of size DIM1xDIM1, adn m2 of size DIM2xDIM2, storing only characters
//'*' and '#'
//find in m1 all sub-matrices equivalent to m2
//copy all sub-matrices equal to m2 in m1 into a new matrix m3 in which all other characters are white elements(blanks)
//print-out m3
//example 1.21 LET DIM1 = 5 and DIM2=3. if m1 and m2 are the fo
/*
#define DIM1 5
#define DIM2 3
int main(void) {
    int i,j,r,c,flag;
    char m1[DIM1][DIM1] , m2[DIM2][DIM2] , aux[DIM1][DIM1];
    printf("input matrix 1");
    for (int i = 0; i < DIM1; ++i) {
        for (int j = 0; j < DIM1; ++j) {
            printf("Element [%d %d]", i,j);
            scanf("%c%*c", &m1[i][j]);
            aux[i][j]=0;
        }
    }
    printf("input matrix 2");
    for (int i = 0; i < DIM2; ++i) {
        for (int j = 0; j < DIM2; ++j) {
            printf("Element [%d %d]", i,j);
            scanf("%c%*c", &m2[i][j]);  //we are acquiring one additional character with the %*c and throw away
        }
    }

    for (int i = 0; i < DIM1 - DIM2; ++i) {
        for (int j = 0; j < DIM1 - DIM2; ++j) {
            flag =1;
            for (int r = 0; r < DIM2 && flag ==1; ++r) {
                for (int c = 0; c < DIM2 && flag ==1; ++c) {
                    if(m1[i+r][j+c] != m2[r][c]){
                        flag=0;
                    }
                }
            }
            if(flag==1) {
                for (int r = 0; r < DIM2; ++r) {
                    for (int c = 0; c < DIM2; ++c) {
                        aux[i + r][j + c] = 1;
                    }
                }
            }
        }
    }

    //the auxilary does masking, when you have the auxialry you can know what to print and what not to.
    for (int i = 0; i < DIM1; ++i) {
        for (int j = 0; j < DIM1; ++j) {
            printf("%c", (aux[i][j]==1) ? m1[i][j] : ' '); //if the aux value is 1, the m1 is printed, else a space
        }
        printf("\n");
    }

    return 0;
}
*/


//----------------------------------------------------------------------------------------------------------------------
//FUNCTIONS
//EXIT_SUCCESS (often equal to 0, but implementation dependant) to return a success program termination code to the
//operating system
//EXIT_FAILURE(often set to 1, but implementation dependant to return an error program termination code to the
// operating system)
//----------------------------------------------------------------------------------------------------------------------
//SUB STRING SUBSTITUTION
/*
 * write a program tht:
 * receives three strings on the command line. each string is at most 40 characters long
 * substitutes into the first string all occurrences of the second string with the third string.
 * prints the resulting string output
 */
/*
#define DIM 40

int searchsubstr(char str1[], char str2[], int from);
int main(int argc, char *argv[]){
    char s1[DIM+1], s2[DIM+1], s3[DIM+1];
    char strOut[DIM*DIM +1];
    int i, idx, from, to, endFlag;
    if(argc != 4 ){
        fprintf(stderr, "wrong number of arguments");
        EXIT_FAILURE; //which returns 1
    }
    //int end = 0;
    //for (int i = 0; i < DIM && !end; ++i) {
        //s1[i]=argv
                //i was trying to check how can i do strcpy myself i have to search for it
    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);
    strcpy(s3, argv[3]);

    //this part puts the third string instead of the second string inside the first string
    //LEARN THIS ONE
    endFlag = from = idx = 0;
    do{
        to = searchsubstr(s1,s2, from);
        if(to < 0 ){
            to= strlen(s1);
            endFlag=1;
        }
        for (int i = from; i < to ; ++i) {
            strOut[idx]=s1[i];
            idx++;
        }
        if(!endFlag){
            for (int i = 0; i < strlen(s3); ++i) {
                strOut[idx]=s3[i];
                idx++;
            }
        }
        from=to +strlen(s2);
    }while (!endFlag);

    strOut[idx]='\0';
    printf("%s\n" , strOut);
    return 0;
}

int searchsubstr(char str1[], char str2[], int from) {
    int flag, i, j;

    i=from;
    while (i < strlen(str1) - strlen(str2)) {
        flag = j = 0;
        while (j < strlen(str2) && flag == 0)
            if (str1[i + j] != str2[j]) {
                flag = 1;
            }
        j++;
    }
    if(flag == 0){
        return i;
    }
    return -1;
}
*/
//----------------------------------------------------------------------------------------------------------------------
//FILES
//INSTRUCTIONS
/*
 * steps in working with files
 * 1-DEFIEN POINTER:
     * FILE *<file_pointer_name>
 *
 *
 * 2-OPEN THE FILE:
     * fp=fopen("name.txt", "r" ) or a or w for write and append respectively
     * also you can #define NAME "name.txt"
     * fp=fopen(NAME, "r" );
     * ALSO, you can acquire the name as a variable and then use it.
     * FILE *fp;
     * char name[L];
     * strcpy(name, "name.txt");
     * fp-fopen (name, "r");
     *
     * 3-CHECK A FILE POINTER:
     * if(<file_pointer_name == NULL>){
     * fprintf(stderr, "Error opening file (%s)", name);
     * exit(1);
 *
 * 4-INPUT/OUTPUT FROM/TO FILE:
     * we have fscanf and fgets
     * fgets has a line by line approach by default, by fscanf has a limit of aquiring spaces and does a string by string
     * while(fscanf(fp, ....) != EOF){ .... }
     * while(fscanf(fp, ....) != n){ .... } if we want to make sure exactly n values have been read from the file
     *
     * while(fgets(... , fp) != NULL) { ... }
     * the fp position is different between these two.
     *
     *and for output we use fprintf
     * also stdout and stdin can be used
 *
 * 5-CLOSE A FILE:
     * fclose(fp); to deal wih garbage and...
 *
 *
 */
//END_INSTRUCTIONS
//----------------------------------------------------------------------------------------------------------------------
//STRUCTURES
//INSTRUCTIONS
/*
 * //DEFINITION
     * 1ST STRATEGY
     * struct <name_struct> {
     * <type_1>  <name_1>;
     * ..
     * .
     * };
     *
     * struct <struct_name>  <var1>,<var2>, ... ;
     *
     * 2ND STRATEGY: (the one i used last year)
     * typedef struct <struct_name> <type_name>;
     * typedef struct <struct_name>{
     * ...
     * } <type_name>;
     *
     * <type_name> <var1>,<var2>, ...;
     *
     *
 * //ACCESSING STRUCTURE CONTENT:
     * BY VALUE:
     * <var_name>.<field_name>
     * BY REFERENCE:
     * either, (*<ptr_name>).(<field_name>)
     * or(preferred), (<ptr_name>)->(<field>)
 *
 */

/*
 * write a program able to.
 * Read from standard output a file name storing a generic ASCII text.
 * Read the text from file and print each row of the file centered with respect to a row size of 80 columns.
 */

#define SIZE 82 //because 80 +\n +\0
int main(void){
    FILE *fp;
    char name[SIZE], line[SIZE];
    int i, num_space;

    printf("input text file name: ");
    scanf("%s", name);  //be careful here that the & is not used since it is an array
    //the file is read from the cmake-build-debug directory
    //typed as test.txt format without the quotations, with quotations it doesn't work

    fp=fopen(name, "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening the file (%s)\n", name);
        exit(1);
    }
    printf("centered text: ");
    while(fgets(line,SIZE, fp)!=NULL) {
        num_space = (SIZE - strlen(line) / 2);
        for (int i = 0; i < num_space; ++i) {
            printf(" ");
        }
        printf("%s", line);
    }
    fclose(fp);
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------