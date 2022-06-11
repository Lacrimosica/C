#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//OVERLAPPED LISTS
/*

#define MAX 100
#define NAME 1
#define MARK 2

typedef struct node_s{
    char name[MAX];
    int mark;
    struct node_s *nextN;
    struct node_s *nextM;
}node_t;

void file_read(node_t **headName, node_t **headMark, char *filename);
node_t *insertByName(node_t *head, node_t *ptr);
node_t *insertByMark (node_t *head, node_t *ptr);
void file_write (node_t *head, char *filename, int nameMark);
void memory_free(node_t *headMark);

int main(void) {
    node_t *headName=NULL, *headMark=NULL;
    char cmd[MAX], name[MAX];
    int stop=0;

    while(stop ==0){
        fprintf(stdout,"\n Available commands:\n"
                       "read <filename>\n"
                       "writeN <filename (<filename" );
        if(strcmp(cmd, "read") == 0){
            scanf("%s" , name);
            fprintf(stdout, "reading file %s. \n" , name);
            memory_free(headMark);
            file_read(&headName , &headMark , name);
        }else if(strcmp(cmd, "writeN") == 0){
            scanf("%s" , name);
            fprintf(stdout, "writing file %s. \n" , name);
            file_write(headName , name, NAME);
        }else if(strcmp(cmd, "writeM") ==0){
            scanf("%s" , name);
            fprintf(stdout, "writing file %s. \n" , name);
            file_write(headName , name, MARK);
        }else if(strcmp(cmd, "stop") ==0){
            fprintf(stdout, "Program terminated.\n");
            stop=1;
        }else {
            fprintf(stderr, "Error: unknown command (%s)" , cmd);
        }
    }

    memory_free(headMark);
    return EXIT_SUCCESS;
}

void file_read(node_t **headName , node_t **headMark , char *filename){
    char name[MAX];
    int mark;
    node_t *tmp;
    FILE *fp;


    *headName = NULL;
    *headMark= NULL;

    fp=fopen(filename , "r");
    while(fscanf(fp, "%s %d" , name, &mark) !=EOF){

        tmp= (node_t *)malloc(sizeof(node_t));
        if(tmp==NULL){
            //error
            exit(EXIT_FAILURE);
        }
        strcpy(tmp->name , name);
        tmp->mark=mark;

        *headMark=insertByMark(*headMark , tmp);
        *headName=insertByName(*headName, tmp);

    }

}

node_t *insertByName(node_t *head, node_t *ptr){

}

node_t *insertByMark(node_t *head, node_t *ptr){

    node_t *tmp0, *tmp1;
    //IMPORTANT STEP HERE IN THE BEGINNING
//    the first condition is in case it is the first line that is read in which *headname is still NULL
//    the second confition is in case the head is larger (by comparison factor) than the read line so the head is
//    replaced by the new line read


    if(head==NULL || ptr->mark < head->mark) {
        ptr->nextM = head;
        return ptr;
    }


    tmp0=head;
    tmp1=head->nextM;

    while(tmp1!=NULL && tmp1->mark < ptr->mark){
        tmp0=tmp1;
        tmp1=tmp1->nextM;
    }
    tmp0->nextM = ptr;
    ptr->nextM = tmp1;

    return head;

}
*/

//LONELY HEARTS CLUB
//10/11/2020 Report
/*the first error i encountered was due to the fgets not waiting to get my query so i added a scanf on between to fix this
problem, later on when the code was done and fixed every where else i would get a exit 139 and SIGSEGV signal and stuff like that
later on i ran it also with ulimit -c unlimited ; a.out and it didn't work either, gdb would tell me the second time, the
 sex is not scanned and in the end at the process() function it would cause an error so i changed sex from char to string
 didn't change either and the previous stuff wouldn't work as well, valgrind and gdb where of no use
 i finally changed the filename scan and wrote the file name manually and eliminated the scanf for the newline feed.
 at the end of this report i'm going to test getchar instead of scanf to see if it works or not
 alternative ways were reported and the root problem was found, being trivial yet hard to catch and  it didn't need a report
 like this although i'm writing this so that i'll keep it in mind*/

#define MAX 101
typedef struct trait_s{
    char *id;
    struct trait_s *next;
}trait_t;

typedef struct member_s{
    char *name;
    char sex;
    struct trait_s *features;
    struct member_s *next;
}member_t;

member_t *load(char *filename);
trait_t *read(char *sex_ptr);
void process(member_t *club, char sex, trait_t *features);
int check(trait_t * head1, trait_t *head2);
void destroy(trait_t *head);
void quit(member_t *head);

int main(void){
    member_t *club=NULL;
    trait_t *features=NULL;
    char name[MAX], sex[2];

    fprintf(stdout, "input the club file name: \n");
    scanf("%s" ,name);
    //getchar(); or alternatively scanf("%s%*c" , name); or even scanf("%s ",name);

    club=load(name);

    do{
        //printf("imma get ma read on\n");
        features = read(sex);
        if(features){//i think any value except NULL and zero count here
            //printf("in if , sex is: %c\n" , sex);
            process(club, sex[0], features);
            //printf("processed stuff\n");
            destroy(features);
        }

    }while(features != NULL);

    //printf("i got here then i will soon quit\n");
    quit(club);
    return EXIT_SUCCESS;
}

member_t *load(char *filename) {
    char lastName[MAX], firstName[MAX], line[MAX], name[MAX], sex[MAX], featureName[MAX], featureValue[MAX];
    member_t *member, *head = NULL;
    trait_t *feature;
    FILE *fp;

    fp=fopen(filename, "r");
    if(fp==NULL){
        fprintf(stderr, "Error in opening file %s \n" , filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX, fp) != NULL) {
        if (line[0] == '#') {

            member = (member_t *) malloc(sizeof(member_t));
            if (member == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }

            sscanf(&line[1], "%s %s %s", lastName, firstName, sex);
            sprintf(name, "%s %s", lastName, firstName);
            member->name = strdup(name);
            member->features = NULL; //we initialize the array feature to NULL and we malloc it going on
            member->sex = sex[0];
            member->next = head;
            head = member;
        } else {
            feature = (trait_t *) malloc(sizeof(trait_t));
            if (feature == NULL) {
                fprintf(stderr, "Memory allocation error.\n");
                exit(EXIT_FAILURE);
            }
            sscanf(line, "%s %s", featureName, featureValue);
            sprintf(name, "%s %s", featureName, featureValue);
            feature->id = strdup(name);

            //this part i don't get really
            feature->next = member->features;
            member->features = feature;
        }
    }
    fclose(fp);

    return head;
}

//head1 is for the member in the club
//head to goes to the features you gave it in the query
int check(trait_t * head1, trait_t *head2){
    trait_t *ptr1, *ptr2;
    int found, equal=0;

    ptr1=head1;

    while(ptr1 != NULL){
        ptr2 = head2;

        found=0;
        while(ptr2 != NULL && !found){
            //printf("this is ptr2.id %s\n" , ptr2->id);
            //printf("this is ptr1.id %s\n" , ptr1->id);
            //int r=strcasecmp(ptr1->id , ptr2->id);
            //printf("just compared '%s' with '%s' = r = %d \n" , ptr1->id , ptr2->id , r);
            if(strcasecmp(ptr1->id , ptr2->id)== 0){//looks for the features provided in the members of the list
                found=1;
            }
            ptr2=ptr2->next; //goes through the requested feature list each time until it finds what it's looking for
                            //OR UNTIL IT REACHES THE END OF THE REQUESTED FEATURES LIST AND THEREFORE 'NULL'
        }
        equal+= found;
        //printf("equal in check: %d\n" , equal);
        ptr1= ptr1->next; //goes to the next feature of the subject we are currently analyzing and commpares all the
                            //requested features in the requested features list with it until it again finds OR doesn't
                            //find what it's looking for
    }
    return equal;
}

void process (member_t *club, char sex, trait_t * features){
    member_t *mate=NULL, *ptr=club;
    int equal, max=0;
    while(ptr !=NULL){
        if(ptr->sex == sex){
            equal = check(ptr->features , features);
            //printf("equal: %d\n" , equal);
            //either in the first term or in case more similarity is found, mate is changed
            if(mate == NULL || equal >max){
                mate= ptr;
                max = equal;
                //printf("max: %d\n" , max);
            }
        }
        ptr = ptr->next; //goes to the next member after analyzing each one until it reaches the end of the list
    }
    fprintf(stdout, "Member found: %s score(%d)\n" , mate->name , max);
}


//MOST IMPORTANT FUNCTION IN THIS PROBLEM
trait_t *read(char *sex_ptr){
    char *line, name[MAX], value[MAX] , id[MAX] , sex[2], *ptr;
    trait_t *trait=NULL, *features=NULL;
    int n;
    char c;

    fprintf(stdout, "input query: \n");

    //fscanf(stdin, "%c" , &c);
//     this step is important since if it doesn't exist, the space after file name gets
//     eaten by fgets as string
//     this lead to the program failing over and over, in the next rounds, the first round of the query was fine though
//      below i will also check getchar



    line=(char *)malloc(MAX * sizeof(char ));
    if(line==NULL){
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    fgets(line, MAX, stdin);
    sscanf(line, "%c" , sex);
    printf("got the sex : '%c'\n" , sex[0]);

    if(sex[0] =='T'){
        fprintf(stdout, "Process terminated by user\n");
        return NULL;
    }


    ptr= &line[1];
    while( sscanf(ptr, "%s %s%n" , name,value , &n) !=EOF) {
        trait = (trait_t *) malloc(sizeof(trait_t));

        if (trait == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        sprintf(id, "%s %s", name, value);

        //printf("id = %s\n" , id);


        trait->id = strdup(id);
        //this part i don't get
        //this is strange for me
        //i got it finally but it's the core part of this code IMO and it's really important to get
        //printf("trait->id: %s\n" , trait->id);
        trait->next = features;
        features = trait;

        ptr += n;
    }
    *sex_ptr=sex[0];
    //testing and shit
    /*//printf("traits[0]: %s\n" , trait[0]);

    printf("traits->id: %s\n" , trait->id); //last query argument sitting first
    printf("traits->next->id: %s\n" , trait->next->id);
    printf("traits->next->next->id: %s\n" , trait->next->next->id);
    printf("traits->next->next->next->id: %s\n" , trait->next->next->next->id); //first query argument sitting last

    //this is how features is structured, print it
    //printf("features[0]: %s\n" , features[0]);
    printf("features->id: %s\n" , features->id); //last query argument sitting first
    printf("feature->next->id: %s\n" , features->next->id);
    printf("features->next->next->id: %s\n" , features->next->next->id);
    printf("features->next->next->next->id: %s\n" , features->next->next->next->id); //first query argument sitting last
    */
    return features;
}

//for freeing traits
//used in the end
//and also when we want to clear the previous search query

void destroy(trait_t *head){
    trait_t *tmp;

    while(head != NULL){
        tmp=head;           //saving the head and passing it to the next after head
        head=tmp->next;     //freeing the previous has been head in the following lines

        free(tmp->id);  //had done malloc on it with strdup
        free(tmp);      //freeing most outer layer
    }
}

//for freeing members
void quit( member_t *head){
    member_t *tmp;

    while(head != NULL){
        tmp=head;
        head=tmp->next;
        free(tmp->name);
        destroy(tmp->features);  //each member had it's own feature list which is freed by destroy
        free(tmp);
    }
}