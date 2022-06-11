#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EX //TOGGLE BETWEEN EXERCISES : EX1A EX1B EX2 EX3

#ifdef EX1A
#define MAX_WORD_LENGTH 20
#define MAX_WORD_NUMBER 100
#define MAX_LINE_LENGTH 100
#endif

#ifdef EX2
#define MAX_RECTANGLE_NUMBER 100
#define MAX_ID_LENGTH 4
#endif

#ifdef EX3
#define MAX_NAME_LENGTH 30
#define STAND_BY -1
#endif

//Exercise 01 (A and B)
/*---------------------

In
Exercise 01 of Laboratory 03
given a list of words (stored in a file), it is required
to print out the number of times each word appears in a
text (stored in a second file).

Extend this program with dynamic allocation, i.e.
dynamically allocate an array of structures to store
the list of words read from file and their absolute
frequency.

The number of words stored in the second file is specified
        on the first row of the file itself, for example:
3
watch
words
become

Write two versions of this program:

- Version A
Define the C structure as

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
} index_t;

- Version B
Define the C structure as

typedef struct {
    char *word;
    int occurrences;
} index_t;


*/
#ifdef EX1A
typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int occurrences;
} index_t;

index_t *read_word(char *, int *n);
void read_text(char *, index_t *, int n);
void display_index(index_t *index, int n);
int main(){
//int argc, char *argv[]
    int n_words;
    /*if(argc!=3){
        fprintf(stderr, "wrong number of arguments\n");
        fprintf(stderr, "Run as: %s <text_file> <word_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
*/
    index_t *index;
//argv[2]
    index=read_word("words.txt", &n_words);
//argv[1]
    read_text("text.txt", index, n_words);

    display_index(index, n_words);

    free(index);

    return EXIT_SUCCESS;
}

index_t *read_word(char *name, int *num_ptr){
    FILE *fp;
    int i,n;
    index_t *index;

    fp=fopen(name , "r");
    if(fp==NULL){
        fprintf(stderr, "Error in opening file %s.\n", name);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d" , &n)==EOF){
        fprintf(stderr, "Error reading file %s\n" , name);
        exit(EXIT_FAILURE);
    }

    index=(index_t *)malloc(n * sizeof(index_t));
    if(index==NULL){
        fprintf(stderr, "Error in memory allocation %s (%d)\n" , __FILE__ , __LINE__);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(i<n && fscanf(fp, "%s" , index[i].word)!=EOF){
        index[i].occurrences = 0;
        i++;
    }

    *num_ptr=i;

    fclose(fp);

    return index;
}

void read_text(char *name, index_t * index, int n){
    FILE *fp;
    char *line;
    int i;

    line=(char *)malloc((MAX_LINE_LENGTH+1) *sizeof(char));
    if(line==NULL){
        fprintf(stderr, "Error in memory allocation %s (%d)\n" , __FILE__ , __LINE__);
        exit(EXIT_FAILURE);
    }


    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error reading file %s\n" , name);
        exit(EXIT_FAILURE);
    }


    while(fscanf(fp, "%s", line)!=EOF) {
        for (i = 0; i < n; ++i) {
            if(strcasecmp(line, index[i].word)==0){
                index[i].occurrences++;
            }
        }
    }

    free(line);
    fclose(fp);
}

void display_index(index_t *index, int n){
    int i;
    for (i=0; i<n; i++) {
        printf("%s - %d occurrence(s)\n", index[i].word, index[i].occurrences);
    }
}
#endif
#ifdef EX1B
typedef struct {
    char *word;
    int occurrences;
} index_t;

index_t *read_word(char *, int *n);
void read_text(char *, index_t *, int n);
void display_index(index_t *index, int n);

int main(){
//int argc, char *argv[]
    int n_words;
    /*if(argc!=3){
        fprintf(stderr, "wrong number of arguments\n");
        fprintf(stderr, "Run as: %s <text_file> <word_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
*/
    index_t *index;
//argv[2]
    index=read_word("words.txt", &n_words);
//argv[1]
    read_text("text.txt", index, n_words);

    display_index(index, n_words);

    //freeing index
    for(int i=0;i<n_words ;i++ ){
        free(index[i].word);
    }
    free(index);

    return EXIT_SUCCESS;
}

index_t *read_word(char *name, int *num_ptr) {
    FILE *fp;
    int i, n=0;
    index_t *index;
    char str[MAX_WORD_LENGTH];

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error in opening file %s.\n", name);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d", &n) == EOF) {
        fprintf(stderr, "Error reading file %s\n", name);
        exit(EXIT_FAILURE);
    }

    index = (index_t *) malloc(n * sizeof(index_t));
    if (index == NULL) {
        fprintf(stderr, "Error in memory allocation %s (%d)\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (i < n && fscanf(fp, "%s", str) != EOF) {
        index[i].word = (char *) malloc((strlen(str) + 1) * sizeof(char));
        if (index[i].word == NULL) {
            fprintf(stderr, "Error in memory allocation %s (%d)", __FILE__, __LINE__);
            exit(EXIT_FAILURE);
        }
        strcpy(index[i].word, str);
        index[i].occurrences = 0;
        i++;
    }
    //index[i].word = strdup(str);

    *num_ptr = i;

    fclose(fp);

    return index;

}

void read_text(char *name, index_t * index, int n){
    FILE *fp;
    char *line;
    int i;

    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error reading file %s\n" , name);
        exit(EXIT_FAILURE);
    }

    line=(char *)malloc((MAX_LINE_LENGTH+1) *sizeof(char));
    if(line==NULL){
        fprintf(stderr, "Error in memory allocation %s (%d)\n" , __FILE__ , __LINE__);
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp, "%s", line)!=EOF) {
        for (i = 0; i < n; ++i) {
            if(strcasecmp(line, index[i].word)==0){
                index[i].occurrences++;
            }
        }
    }

    free(line);
    fclose(fp);
}

void display_index(index_t *index, int n){
    int i;
    for (i=0; i<n; i++) {
        printf("%s - %d occurrence(s)\n", index[i].word, index[i].occurrences);
    }
}
#endif

//Exercise 02
/*-----------

In Exercise 02 of Laboratory 03
it is requested to order a list of rectangles read from file.

Extend this program with dynamic allocation, i.e.
dynamically allocate an array of structures to store
information on all rectangles.

The number of rectangles stored in the input file is specified on the
        first row of the file itself, for example:

5
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
*/
#ifdef EX2
//
typedef struct point_t{
    float x,y;
}point;

typedef struct rectangle_t{
    char id[4+1];
    float area,perimeter;
    point p1,p2;
}rectangle;

rectangle *read(char * , int *);
void SortByArea(rectangle *, int);
void SortByPerimeter(rectangle * , int);
void write(rectangle *, char *, int);


int main(int argc, char *argv[]){
    rectangle *rectangles;
    int n_rectangles,i;

    if(argc!=4){
        fprintf(stderr, "wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }

    rectangles=read(argv[1], &n_rectangles);

    SortByArea(rectangles , n_rectangles);
    write(rectangles, argv[2]  , n_rectangles);

    SortByPerimeter(rectangles, n_rectangles);
    write(rectangles , argv[3]  , n_rectangles);

    free(rectangles);

    return EXIT_SUCCESS;
}

rectangle *read(char *name, int *num){

    FILE *fp;
    int i, n;
    float x, y, l1, l2;
    char id[MAX_ID_LENGTH + 1];
    rectangle *rectangles;

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error reading file %s (%d)\n", name, __LINE__);
        exit(EXIT_FAILURE);
    }

    //reading the first line of the file
    if(fscanf(fp, "%d" , &n)==EOF){
        fprintf(stderr, "Error reading file (%d)", __LINE__);
        exit(EXIT_FAILURE);
    }

    rectangles=(rectangle *)malloc(n * sizeof(rectangle));
    if(rectangles==NULL){
        fprintf(stderr, "Error in memory allocation (%d).\n" , __LINE__);
        exit(EXIT_FAILURE);
    }

    *num=0;
    //reading the rectangles and vertices
    while (fscanf(fp, "%s%f%f", id, &x, &y) != EOF && *num < n) {
        for (i = 0; i < *num; i++) {
            if (strcmp(id, rectangles[i].id) == 0) {
                break;  //2-when you break you go to the while loop for example the second line of file, if the same id
                //2-and therefore consecutive rectangles:
                //3-for the third time , num=1, i=0 -> nothing happens, i=1, nothing happens:
            }
        }
        //1-the first loop i=0=*num so we go here instead of the above loop
        //2-you come here with i==0 and !=num
        //3-you arrive here and i=1=num so you add the new shit, and so it goes for num==2 and i=1 is broken and...

        if (i == *num) { //the first point
            strcpy(rectangles[i].id, id);
            rectangles[i].p1.x = x;
            rectangles[i].p1.y = y;
            *num = *num + 1;
        } else { //second point         //1-in the first ever loop the else is skipped, num=1
            //2-and here in the break result you add the second point here
            //2-and also num is not incremented
            rectangles[i].p2.x = x;
            rectangles[i].p2.y = y;

            l1=fabs(x - rectangles[i].p1.x);
            l2=fabs(y - rectangles[i].p1.y);

            rectangles[i].area = l1*l2;
            rectangles[i].perimeter= 2*(l1+l2);
        }
    }

    *num=n;
    fclose(fp);
    return rectangles;
}

void SortByArea(rectangle *rect , int n){
    rectangle current;
    int i,j;

    for (i = 1; i < n; ++i) {
        current=rect[i];
        j=i-1;
        while(j>=0 && current.area > rect[j].area){
            rect[j+1]=rect[j];
            j--;
        }
        rect[j+1]=current;
    }
}

void SortByPerimeter(rectangle *rect , int n){
    rectangle current;
    int i,j;

    for (i = 1; i < n; ++i) {
        current=rect[i];
        j=i-1;
        while(j>=0 && current.perimeter>rect[j].perimeter){
            rect[j+1]=rect[j];
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

//Exercise 03
/*-----------

During a training session each athlete of a group of professional
cyclists is checked during each lap.
For each athlete all lap times are stored in a file with the following
format.
The first line of the file stores the number of cyclists in the group.
Then, for each cyclist, the file stores:
- On the first line, his/her name (string of 30 characters at most),
identifier (integer value), and number of laps performed.
- On the second line, all lap times,
        time_1 time_2 ... time_N, stored as real values.

Write a program that, after reading the file and storing its content
        in a proper data structure, is able to reply to the following menu
        inquiry:
- list: the program prints-out the number of athletes, their names,
        identifiers, and number of laps performed.
- detail name: given an athlete name, the program prints-out
        his/her identifier, and all lap times.
- best: the program prints-out the name, identifier, all lap times
        and the average lap time for the athlete whose average lap time is
        smaller.
- stop: end the program.

Notice that all operations can be performed more than once till the
stop command is issued.

Example
-------
Let the following be the input file:

4
Rossi 100 3
1.30 1.38 1.29
Bianchi 101 5
1.46 1.43 1.42 1.51 1.28
Neri 117 2
1.26 1.34
Verdi 89 4
2.01 1.45 1.43 1.38

The following is a run example of the program:

Input file name: cyclist.txt
Command? list
Number of athletes : 4
Name: Rossi #Id:100 #Laps:3
Name: Bianchi #Id:101 #Laps:5
Name: Neri #Id:117 #Laps:2
Name: Verdi #Id:89 #Laps:4
Command? best
Name:Neri #Id number:117 Laps:2 Times: 1.26 1.34 (Average:1.30)
Command? details Bianchi
#Id:101 #Laps:5 Times: 1.46 1.43 1.42 1.51 1.28
Command? stop
Program ended.
*/
#ifdef EX3
typedef struct athlete_t {
    char name[MAX_NAME_LENGTH];
    int id;
    int n_laps;
    float *laps;
    float average;
}athlete;

athlete *read_file(char *, int *);
void list(athlete *, int);
void detail(athlete *, char *, int);
void best(athlete *, int);

int main(int argc, char*argv[]){

    if(argc!=2){
        fprintf(stderr, "Wrong number of arguments.\n");
        fprintf(stderr, "run like this: %s <file.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int opt=0, num=0;
    char choice[10], name[MAX_NAME_LENGTH];
    athlete *athletes;
    athletes=read_file(argv[1],&num);

    do{
        fprintf(stdout, "----------type in a choice---------\n"
                                "1-list\n"
                                "2-detail\n"
                                "3-best\n"
                                "4-stop\n"
                                "----------------------------------\n");
        fscanf(stdin, "%s", choice);

        if(strcasecmp(choice, "list")==0){
            opt=1;
            list(athletes, num);
        }else if(strcasecmp(choice, "detail")==0){
            opt=2;
            fprintf(stdout, "input name:\n");
            fscanf(stdin, "%s", name);
            detail(athletes, name, num);
        }else if(strcasecmp(choice, "best")==0) {
            opt = 3;
            best(athletes, num);
        }else if(strcasecmp(choice, "stop")==0){
            opt=0;
        }else{
            fprintf(stdout, "invalid selection\n");
            opt=STAND_BY;
        }
    }while(opt!=0);

    for (int i = 0; i < num; ++i) {
        free(athletes[i].laps);
    }
    free(athletes);

    return EXIT_SUCCESS;
}

athlete *read_file(char *file_name, int *n) {
    FILE *fp;
    int num_athletes, i, j;
    float sum = 0;
    athlete *ath;

    char name[MAX_NAME_LENGTH];
    int id, nl;
    float tl;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error reading file %s (%d)\n", file_name, __LINE__);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d", &num_athletes) == EOF) {
        fprintf(stderr, "Error reading file %s (%d)\n", file_name, __LINE__);
        exit(EXIT_FAILURE);
    }

    ath = (athlete *) malloc(num_athletes * sizeof(athlete));

    if (ath == NULL) {
        fprintf(stderr, "Memory allocation error  (%d)\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    i = 0;
    while (fscanf(fp, "%s %d %d", name, &id, &nl) != EOF && (i < num_athletes)) {
        strcpy(ath[i].name, name);
        ath[i].id = id;
        ath[i].n_laps = nl;

        ath[i].laps = (float *) malloc(nl * sizeof(float));
        if (ath[i].laps == NULL) {
            fprintf(stderr, "Memory allocation error (%d)\n", __LINE__);
            exit(EXIT_FAILURE);
        }
        j = 0;
        while (j < nl && fscanf(fp, "%f", &tl) != EOF) {
            ath[i].laps[j] = tl;
            sum += tl;
            j++;
        }
        ath[i].average = sum / (float) (ath[i].n_laps);
        sum=0;
        i++;
    }

    athlete current;
    for(i=1; i<num_athletes; i++){
        current=ath[i];
        j=i-1;
        while(j>=0 && current.average<ath[j].average) {
            ath[j + 1] = ath[j];
            j--;
        }
        ath[j+1]=current;
    }

    *n=num_athletes;
    fclose(fp);
    return ath;
}
void list(athlete *ath, int n){
    int i;
    fprintf(stdout, "Number of athletes : %d\n", n);
    for (i = 0; i < n; ++i) {
        fprintf(stdout, "Name: %s, #Id:%d #Laps: %d\n", ath[i].name, ath[i].id , ath[i].n_laps);
    }
}
void detail(athlete *ath, char *name, int n){
    int i, j;
    for(i=0; i<n; i++){
        if(strcasecmp(name, ath[i].name)==0){
            fprintf(stdout, "Id: %d #Laps: %d Times:" , ath[i].id , ath[i].n_laps);
            for (j = 0; j <ath[i].n_laps ; ++j) {
                fprintf(stdout, " %.2f" , ath[i].laps[j] );
            }
            fprintf(stdout, " (Average: %.2f)\n", ath[i].average);
        }
    }
    fprintf(stdout,"\n");
}
void best(athlete *ath, int num_athletes){
    athlete current;
    int i,j;
    for(i=1; i<num_athletes; i++){
        current=ath[i];
        j=i-1;
        while(j>=0 && current.average<ath[j].average) {
            ath[j + 1] = ath[j];
            j--;
        }
        ath[j+1]=current;
    }

    fprintf(stdout, "Name: %s #Id: %d #Laps: %d Times:" ,ath[0].name, ath[0].id , ath[0].n_laps);
    for (j = 0; j <ath[0].n_laps ; ++j) {
        fprintf(stdout, " %.2f" , ath[0].laps[j] );
    }
    fprintf(stdout, " (Average: %.2f)\n", ath[0].average);
}
#endif
