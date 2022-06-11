#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define EX3


#ifdef EX1
#define MAX_WORD_LENGTH   20
#define MAX_WORD_NUMBER  100
#define MAX_LINE_LENGTH  100
#endif

#ifdef EX2
#define MAX_RECTANGLE_NUMBER 100
#endif

//Exercise 01
/*
-----------

A first file stores a text with an undefined number of rows.
Each row is shorter than 100 characters.
A second file stores a list of words.
Each word is shorter than 20 characters, and the number of words
        is at most equal to 100.

Write a program that counts the number of times each word stored in the
second file appears in the text stored in the first file.

Once the file has been read, the program has to print out (on standard
        output) each word with its absolute frequency, i.e., the number of
        times it appears in the text.

Both files have to be read just once.
Capital and small letters have to be considered as equivalent, e.g.,
"word" and "WORD" and "WoRd" are considered as equivalent.

Example
-------

Let the first file be the following one:

Watch your thoughts ; they become words .
Watch your words ; they become actions .
Watch your actions ; they become habits .
Watch your habits ; they become character .
Watch your character ; it becomes your destiny .
Lao-Tze

        and the second file the following one:

watch
words
become

        The program has to print-out:

watch - 5 occurrence(s)
words - 2 occurrence(s)
become - 4 occurrence(s)


*/
#ifdef EX1
/* structure declaration */
typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
} index_t;

/* function prototypes */
void read_words(char *, index_t [], int *);
void read_text(char *, index_t [], int);
void display_index(index_t [], int);
int compare(char *, char *);


int main(int argc, char *argv[])
{
    index_t index[MAX_WORD_NUMBER];
    int n;

    if (argc < 3) {
        printf("Error: missing parameter.\n");
        printf("Run as: %s <text_file> <word_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_words(argv[2], index, &n);
    read_text(argv[1], index, n);
    display_index(index, n);

    return EXIT_SUCCESS;
}

/*
 *  read the words file; return the index array
 */
void read_words(char *name, index_t index[], int *num_ptr)
{
    FILE *fp;
    int i;

    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", name);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i<MAX_WORD_NUMBER && fscanf(fp, "%s", index[i].word)!=EOF) {
        index[i].occurrences = 0;
        i++;
    }
    *num_ptr = i;

    fclose(fp);
}

/*
 *  read the text file; complete the index infos
 */
void read_text(char *name, index_t index[], int n)
{
    char word[MAX_LINE_LENGTH+1];
    int i, j;
    FILE *fp;

    fp = fopen(name, "r");
    if (fp == NULL) {
        printf("Error opening file %s.\n", name);
        exit(EXIT_FAILURE);
    }

    i = 1;
    while (fscanf(fp, "%s", word) != EOF) {
        /* look for the word in the index */
        for (j=0; j<n; j++) {
            if (compare(word, index[j].word) == 1) {
                /* found an occurrence for a word */
                index[j].occurrences++;
            }
        }
        i++;
    }

    fclose(fp);
}

/*
 *  output the index contents
 */
void display_index(index_t index[], int n)
{
    int i;

    for (i=0; i<n; i++) {
        printf("%s - %d occurrence(s)\n", index[i].word, index[i].occurrences);
    }
}

/*
 *  case insensitive comparison between two strings
 *  return 1 if the strings are equal, 0 otherwise
 */
int compare(char *str1, char *str2)
{
    int i;

    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    for (i=0; i<strlen(str1); i++) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return 0;
        }
    }

    return 1;
}
#endif
//Exercise 02
/*
-----------

A file defines a set of rectangles with the following format:
* Each row of the file contains 1 string and 2 real numbers:
- The string (4 character long) is the rectangle identifier,
- The two numbers specifies the x and y coordinates,
respectively, of one of its vertices
        * For each rectangle there are two lines in the file, specifying
        the coordinate of two opposite vertices (top-right and
bottom-left or top-left and bottom-right).
Notice that, in general, the two rows defining a rectangle are
        not consecutive, and that it is not known which vertex they
        specify.
In any case, suppose the maximum number of rectangles is 100.

Write a C program that receives 3 file names on the command line:
- The first file is an input file, and it contains all rectangles
        specifications as previously indicated
- The second file is an output file, and it must contain the
        name of the rectangles ordered by descending area values.
- The third file is an output file, and it must contain the
        name of the rectangles ordered by descending perimeter values.

Suggestion
----------

Use an array of structures where each element on the array stores
the name and the two extreme coordinates.

Example
-------

Let us suppose that the program receives the following three parameters:
fileIn.txt fileArea.txt filePerimeter.txt

        Moreover, let us suppose that the content of fileIn.txt is the following:

rct2  1.5 3.5
xxyy  -0.5 3.0
xxyy  1.5 2.0
abcd  1.0 4.5
ktkr  -2.5 1.5
abcd  2.0 2.0
rct2  3.5 -2.0
trya  2.5 -1.0
ktkr  1.5 3.5
trya  4.0 4.0

As areas and perimeters of the rectangles are:
rct2   area=11.00   perimeter=15.00
xxyy   area= 2.00   perimeter= 6.00
abcd   area= 2.50   perimeter= 7.00
ktkr   area= 8.00   perimeter=12.00
trya   area= 7.50   perimeter=13.00
the program has to generate the following two files:

fileArea.txt:
rct2
ktkr
trya
abcd
xxyy

filePerimeter.txt:
rct2
trya
ktkr
abcd
xxyy

 */
#ifdef EX2

typedef struct point_t{
    double x,y;
}point;
typedef struct rectangle_t{
    char id[4+1];
    double area,perimeter;
    point p1,p2;
}rectangle;
int read( char *, rectangle [], int *);
void sortbyarea(rectangle [], int);
void sortbyperimeter(rectangle[] , int);
void write(rectangle [] , char *, int);
int main(int argc, char *argv[]){
    rectangle rect[MAX_RECTANGLE_NUMBER];
    int n,i;
    if(argc!=4){
        fprintf(stderr, "wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }

    read(argv[1], rect ,&n);

    sortbyarea(rect , n);
    write(rect , argv[2] , n);

    sortbyperimeter(rect, n);
    write(rect , argv[3] , n);


    return EXIT_SUCCESS;

}
int read(char *name, rectangle rect[], int *num) {
    FILE *fp;
    int i;
    double x, y;
    char id[4 + 1];
    double l1,l2;
    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "error reading file");
        exit(EXIT_FAILURE);
    }
    *num = 0; //setting the value of existing rectangles to 0

    while (fscanf(fp, "%s%lf%lf", id, &x, &y) != EOF && *num < MAX_RECTANGLE_NUMBER) {
        for (i = 0; i < *num; i++) {
            if (strcmp(id, rect[i].id) == 0) {
                break;  //2-when you break you go to the while loop for example the second line of file, if the same id
                            //2-and therefore consecutive rectangles:
                            //3-for the third time , num=1, i=0 -> nothing happens, i=1, nothing happens:
            }
        }
        //1-the first loop i=0=*num so we go here instead of the above loop
        //2-you come here with i==0 and !=num
        //3-you arrive here and i=1=num so you add the new shit, and so it goes for num==2 and i=1 is broken and...

        if (i == *num) { //the first point
            strcpy(rect[i].id, id);
            rect[i].p1.x = x;
            rect[i].p1.y = y;
            *num = *num + 1;
        } else { //second point         //1-in the first ever loop the else is skipped, num=1
                                        //2-and here in the break result you add the second point here
                                        //2-and also num is not incremented
            rect[i].p2.x = x;
            rect[i].p2.y = y;
            l1=fabs(rect[i].p2.x - rect[i].p1.x);
            l2=fabs(rect[i].p2.y - rect[i].p1.y);
            rect[i].area = l1*l2;
            rect[i].perimeter= 2*(l1+l2);
        }
    }
    fclose(fp);
}
void sortbyarea(rectangle rect[] , int n){
    rectangle current;
    int i,j;

    for (i = 1; i < n; ++i) {
        current=rect[i];
        j=i-1;
        while(j>=0 && current.area>rect[j].area){
            rect[j+1].area=rect[j].area;
            j--;
        }
        rect[j+1]=current;
    }
}
void sortbyperimeter(rectangle rect[] , int n){
    rectangle current;
    int i,j;

    for (i = 1; i < n; ++i) {
        current=rect[i];
        j=i-1;
        while(j>=0 && current.perimeter>rect[j].perimeter){
            rect[j+1].perimeter=rect[j].perimeter;
            j--;
        }
        rect[j+1]=current;
    }
}
void write(rectangle rect[], char *name, int n){
    FILE *fp;
    int i;
    fp=fopen(name, "w");
    if(fp==NULL){
        fprintf(stderr, "error opening file to write in\n");
        exit(EXIT_FAILURE);
    }

    for(i=0 ; i<n; i++){
        fprintf(fp, "%s\n" , rect[i].id);
    }

    fclose(fp);
}

#endif