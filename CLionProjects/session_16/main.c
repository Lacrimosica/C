#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//why don't we pass and array by address in functions? we already are because v is a pointer itself

#define L   30
#define N   10
#define DIM 30

//structs
struct element{
    char n[L];
    char s[L];
    int mat;
    int mark;
}typedef ele;

struct student{
    char first_name[L] , Last_name[L];
    int register_number;
    float average;
} typedef std;

int mystrlen(char *s){
    int cnt=0;
    while(s[cnt]!='\0'){
        cnt++;
    }
    //printf("%d", cnt);
    return cnt;
}
int mystrcmp(char *s1, char *s2){
    int i=0;
    while(s1[i]==s2[i] && s1[i]!= '\0')
        i++;
    return (s1[i]-s2[i]);
}
void function_on_sturct(struct element *e){ //passing the value (pf the struct) by reference
    //e->n; //first notation for referencing a member of a struct
    //(*e).n;  //second notation
}
void read(std *v){
    char first_name[DIM], last_name[DIM];
    int rn,a;
    fprintf(stdout, "First name, last name, register number, average: ");
    scanf("%s%s%d%d" , first_name,last_name,&rn, &a);
    strcpy(v->first_name,first_name);
    strcpy(v->Last_name, last_name);
    v->register_number = rn;
    v->average = a;
}



int main() {
    int v[10];
    for (int i = 0; i < 10; ++i) {
        v[i]=i;
    }


    int *p;
    //array name is a pointer to the first element of the array so:  //v=&v[0]
    p=v;
    //or alternatively:
    p= &v[0];
    //the difference between pa dn v is that p is a variable pointer but v is a constant pointer and not modifiable
    for (int i = 9; i >=0; --i) {
        printf("[%d]\n" , *(p+i) ); //printing the array inversely using pointer
    }
    //it is important to note that v is the address of the first element and is sitting at that address itself
    //where as p is a pointer to the address of the first element in an array and itself is sitting somewhere else in
    //the memory

    //f(v,10);
    char string[]="hello";
    mystrlen(string);

    //mystrcmp
    char a[]="hello";
    char b[]="Hello";

    //structures
    ele e1,e2,e[N];

    std student_one[1];
    read (&v);

    return 0;

}


