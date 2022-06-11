#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DEBUG_FLAG 0

//LIST_SORTING
/*a file stores information about all the students who passed an exam. for each student a row of the file reports the
last name (string of 20 characters at most) and the final mark (real value in the rane 0-30) students are stored in random order

write a porgram able to execute the following commans, eventually more than once:
read fileName: read file name, store content of file in a list
writeN fileName: store the current list file fileName with the same format of the input file but ordered by name
writeM fileName: same as above, ordered by mark
stop: terminates the program*/
//we are going to use a single linked list and is one directional

#define ROW_LEN 100
#define STR_LEN 21
#define SUCCESS 1
#define FAILURE 2

typedef struct node_s {
    char name[STR_LEN];
    float mark;
    struct node_s *next;
}node_t;

node_t *file_read(node_t *, char *);
void orderByName(node_t *);
void orderByMark(node_t *);
void file_write(node_t *, char *);
node_t *newE (void);
void memory_free(node_t *);

int main(void) {
    node_t *headPtr;
    char cmd[ROW_LEN] , name[ROW_LEN];
    int stop=0;
    headPtr = NULL;
    return 0;
}

void orderByName(node_t *headPtr){
    char tmpStr[STR_LEN];
    float tmpFloat;
    node_t *endPtr, *tmpPtr1, *tmpPtr2, *tmpPtr3;
    //empty list check
    if(headPtr==NULL){
        return;
    }
    //list with one element check
    if(headPtr->next==NULL){
        return;
    }
    //list with more than one element
    endPtr=NULL;
    //iterates once for each element.ALSO IMPORTANT STEP
    //the below loop is just a counter and the value of tmpPtr1 is used as one
    //but the value itself is not used as a base for anything else other than a counter
    //instead tmpPtr2 is assigned to headPtr and then reassigned to tmpPtr3 and tmpPtr3 is assigned to tmpPtr3.next

    for(tmpPtr1 = headPtr; tmpPtr1 != NULL ; tmpPtr1=tmpPtr1->next){
        //IMPORTANT STEP, a for loop for going through a list
        for(tmpPtr2=headPtr, tmpPtr3=headPtr->next ; tmpPtr3!=endPtr; tmpPtr2=tmpPtr3, tmpPtr3= tmpPtr3->next){
            //ascending order
            if(strcmp (tmpPtr2->name, tmpPtr3->name) > 0){
                strcpy(tmpStr, tmpPtr2->name);
                tmpFloat = tmpPtr2->mark;
                strcpy(tmpPtr2->name , tmpPtr3->name);
                tmpPtr2->mark = tmpPtr3->mark;
                strcpy(tmpPtr3->name, tmpStr);
                tmpPtr3->mark = tmpFloat;
            }

        }

#if DEBUG_FLAG
        fprintf(stdout, "List:\n");
        file_write (headPtr, "stdout");
#endif
        //move backward final pointer for inner cycle
        //because tmpPtr3 is already NULL and therefore tmpPtr3.next is just random and not NULL for sure or idk, i think
        //this is the reason for the below line
        endPtr=tmpPtr2;
    }
    return;
}

void orderByMark(node_t *headPtr){
    char tmpStr[STR_LEN];
    float tmpFloat;
    node_t * endPtr, *tmpPtr1, *tmpPtr2, *tmpPtr3;

    if(headPtr==NULL){
        exit(EXIT_FAILURE);
    }
    if(headPtr->next==NULL){
        exit(EXIT_FAILURE);
    }
   endPtr=NULL;

    for(tmpPtr1=headPtr; tmpPtr1!=NULL ;tmpPtr1=tmpPtr1->next){
        for(tmpPtr2=headPtr, tmpPtr3= headPtr->next ; tmpPtr3!= endPtr ; tmpPtr2= tmpPtr3, tmpPtr3= tmpPtr3->next){

            if(tmpPtr2->mark > tmpPtr3->mark){
                //swapping and stuff occcurs
            }
        }
        tmpPtr2= endPtr;
    }

}

void file_write(node_t *headPtr, char *name){
    FILE *fp;
    node_t *tmpPtr;
    if(strcmp (name, "stdout") == 0){
        fp=stdout;
    }else{
        fp=fopen(name, "w");
        if(fp==NULL){
            fprintf(stderr, "Error opening file %s\n", name);
            return;
        }
    }

    tmpPtr= headPtr;

    while(tmpPtr !=NULL){
        fprintf(fp, "%s %f\n", tmpPtr->name, tmpPtr->mark);
        tmpPtr = tmpPtr->next;
    }

    if(strcmp (name, "stdout") !=0){
        fclose(fp);
    }

    return;
}

node_t *file_read(node_t *headPtr, char *name){
    FILE *fp;
    char row[ROW_LEN];
    float mark;
    node_t *tmpPtr;

    fp=fopen(name, "r");
    if(fp==NULL){
        fprintf(stderr, "Error opening file.\n");
        return NULL;
    }

    headPtr= NULL; //initialization

    while(fgets(row, ROW_LEN, fp) !=NULL){
        sscanf(row, "%s %f" , name, &mark);

        tmpPtr=newE();
        strcpy(tmpPtr->name , name);
        tmpPtr->mark = mark;

        //HEAD INSERTION
        tmpPtr->next = headPtr;
        headPtr = tmpPtr;
    }

    fclose(fp);

    return (headPtr);
}

node_t *newE(void){
    node_t *tmpPtr;

    tmpPtr=(node_t *)malloc(sizeof(node_t));
    if(tmpPtr==NULL){
        fprintf(stderr, "Memory allcoation error\n");
        exit(EXIT_FAILURE);
    }

    return (tmpPtr);
}

void memory_free(node_t *head){
    node_t *tmp;

    while(head !=NULL){
        tmp=head;
        head=head->next;
        free(tmp);
    }
}