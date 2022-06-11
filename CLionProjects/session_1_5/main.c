#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>
/*
 * if you use include " " you are referring to a library in your current directory
 * you can use define in this manner as well, macro:
 * #define sum(a,b) a+b
 */
/*
int main (void) {
    int n,r,c;
    printf("-------\n");
    for (int r = 0; r < N + 2 ; ++r) {
        for (int c = 0; c < N + 2; ++c) {
            if(r==0 && (c==0 || c==6))
        }
        if(r==0 || r-N==0){

    }

    }

    return 0
}
int main(int argc , char *argv[] )

*/
/*
#define DIM 10
int main(void){
    int i,j,n;
    int vector[DIM]
    printf("input array:\n");
    for (int i = 0; i < DIM; ++i) {
        printf("array[%d] =", i);
        scanf("%d" , &vector[i]);
    }


    n=DIM;
    i= 0;
    while(i<n){
        if (vector[i]==0) {
            for (int j = i+1; j < n; ++j) {
                vector[j-1] = vector[j];
                vector[j]=0;
            }
            //decreasing the logical array size
            n=n-1;

        }else {
            i++;
        }

    }
    printf("output array:\n");

}
*/
/*
#define DIM 10
int main(void){
    int i,j;
    int array[DIM];

    printf("input array:\n");
    for (i = 0; i < DIM; ++i) {
        printf("array[%d] =", i);
        scanf("%d", &array[i]);
    }
    int k,p;
    for (i = 0 , j = 0 ; i < DIM ; ++i) {
        if(array[i]== 0){
            array[j] = array[i];
            j++;
        }
    }

    printf("output array:\n");
    for (i = 0; i < j; ++i) {
        printf("array[%d] = %d\n" , i, array[i]);
    }

    return 0;
}
 */

//exercise on  sub-arrays
//read two arrays of integer values v1 and v2 of size DIM1 and DIM2 predefined constants adn DIM1>DIM2
//understand whether the sequence of values stored in v2 appears om v1 as a sub-sequence. In such case the program
//has to print-out the starting index.
/*
#define DIM1 5
#define DIM2 2
#define OVERLAPPING 1
#define PRINTMATS 1
#define ALT 0

int main(void){
    printf("Hell0 world\n");
    int i,j,n, flag;
    int num_occ=0;

    //n is the number of the box
    //flag for whether you are in the patter search
    //vector initialization
    int arr1[DIM1]={1,2,3,1,2};
    int arr2[DIM2]={1,2};
    n= DIM1-DIM2-1;


    if(PRINTMATS){
        //printing code}
        for (int i = 0; i < DIM1; ++i) {
            printf("%d\n" , arr1[i]);
        }
    }
    //below is my algorithm
    //this code can't identify overlapping
    if(!ALT){
        for (i = 0, j =0; i < DIM1; ++i) {
            if(arr1[i] == arr2[j]){
                flag=1;
                j++;
                if(j==n){
                    num_occ++;
                    printf("number of occurrence: %d ,index of occurrence: %d\n", num_occ,  i-n+1);
                    flag=0;
                    j=0;
                    }

                }

            }
        }
    }
    //below is the second solution
    if(ALT) { //offset displacement
        i = 0;
        while (i <= DIM1 - DIM2) {
            j = 0;
            flag = 1;
            while (j < DIM2 && flag == 1) {
                if (arr1[i + j] != arr2[j]) {
                    flag = 0;
                    //whenever i find an inequality i will set the flag to zero and exit
                    //the internal cycle ends and
                }
                j++;
            }
            if (flag == 1) {
                printf("sub-sequence found form element %d.\n", i);
                if (OVERLAPPING == 0) {
                    //find non overlapping sequence
                    i = i + DIM2; //guearantess that overlapping won't be considere
                    //because we are sliding by the size of the smaller sequence
                } else {
                    //find out overlapping sequence
                    i++;
                    i++;
                }
            } else {
                i++;
            }

        }
    }
    return 0;
}
*/

//example 1.17
//write a program that:
//reads a sequence of integer numbers until a value strictly negative or larger that 99 is introduced
//print out a histogram made up of 10 rows of characters # where the numbers of characters in the
//first row indicates the number if values previously introduce din the range 0,9
//second row 10,19
//the tenth row 90,99


/*
#define MAX 100
#define MIN 0
#define INTERVALS   10
int main(void){
    //int N= argc-1; //number of numbers given to the command line besides the exe adn the negative or larger one
    //idk how to deal with the argv i'll try this
    //int num_list[N];
    int band = (MAX-MIN)/INTERVALS;
    int counter[INTERVALS]={0};
    //int b; // temporary for each division to assign to counter
    for (int i = 0; i < N ; ++i) {
        num_list[i]=atoi(argv[i+1]);
    }
    for (int i = 0; i < N; ++i) {
        b=num_list[i]/band;
        counter[b]++;
    }

    //change this because i got the whole command line thing wrong
    //do this instead:
    printf("input sequence:\n");
    int flag =1;
    int val;
    do {
        printf("value - ");
        scanf("%d" , &val);
        if(val < 0 || val>= MAX){
            flag = 0;
        } else{
            counter[val/band]++;
        }
    }while(flag==1);

    for (int i = 0; i < band; ++i) {
        printf("[%2d-%2d] " , i*band , (i+1)*band -1);
        for (int j = 0; j < counter[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
*/


//same as the one above but this time the histogram is vertical
/*
#define SIZE 10
int main(void){
    int counter[SIZE]={0};
    printf("input sequence:\n");
    int flag =1;
    int val;
    do {
        printf("value - ");
        scanf("%d" , &val);
        if(val < 0 || val>= 99){
            flag = 0;
        } else{
            counter[val/SIZE]++;
        }
    }while(flag==1);

    flag = 1;
    do {
        flag=0; //we are not going to repeat anymore unless something happens
        for (int i = 0; i < SIZE; ++i) { //the for is essential so that we can go through one row
            if(counter[i] > 0) {
                printf("#");
                --counter[i];
                flag = 1; //to preform another cycle
            } else {
                printf(" ");
            }
        }
        printf("\n");
    } while(flag ==1);

    return 0;
}
 */

//some exercise on strings
/*
#define MAX_LEN 31
int main(int argc, char *argv[]){
    char s1[MAX_LEN] , s2[MAX_LEN];
    int i,j, found;
    //manage input
    if(argc != 3){
        fprintf(stderr, "Parameter error\n");
        fprintf(stderr, "run program as  %s <string1> <string2>\n", argv[0]);
        return 1;
    }
    //copy input to string arrays
    strcpy(s1, argv[1]);
    strcpy(s2, argv[2]);

    strlwr(s1);
    strlwr(s2);
    //checking for anagrams
    for (found=1, i = 0; i < strlen(s1) && found==1; ++i) {
        for (found= 0 , j = 0; j < strlen(s2) && found==0; ++j) {
            if(s1[i]==s2[j]){
            s2[j]= '-';
            found=1;
            }
        }
    }

    if(found==0){
        fprintf(stdout, "no anagrams found");
    }else{
        for (found=0,i =0 ;i<strlen(s2) && found==0; ++i){
            if(s2[i] != '-'){
                found=1; //this found is finding another thing
            }
        }
        if(found==0){
            printf("the two words are anagram s.\n");
        }else{
            printf("the two words are not anagrams.\n");
        }
    }

    return 0;
}
*/
//second solution:
#define MAX_LEN 31
/*
int main(int argc, char *argv[]) {
    int i, flag;
    int occurances[26] = {0};
    for (i = 0; i < strlen(argv[1]); ++i) {
        occurances[tolower(argv[1][i]) - 'a']++;
    }
    for (i = 0; i < strlen(argv[2]); ++i) {
        occurances[tolower(argv[2][i]) - 'a']--;
    }
    flag = 1;
    for (int i = 0; i < 26 && flag; ++i) {
        if (occurances[i] != 0) {
            flag = 0;
        }
        //now for a fancy thing here
        printf("the two words are%s anagrams.\n", flag ? "" : " NOT");

        return 0;
    }
}
 */