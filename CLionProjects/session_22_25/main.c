#include <stdio.h>
#include <stdlib.h>


typedef struct list_s list_t;  //define a new type of variable which is a struct based on a=the structure called list
                                //structure,called list_t
struct list_s{
    /* Data fields*/
    int key;
    /* Auto-referencing Pointer */

    list_t *next; //pointer to a data structure like itself
};


/* another syntax
 * typedef struct list_s{
 * int key;
 * ...
 * struct list_s *next;    **important here
 * } list_t;
 */




list_t  *new_element();
int main() {
    list_t *p; //this will be the head, the beginning pointer to the whole list
    list_t *head, *tail;
    p = new_element();

    //TRAVERSING THROUGH A LIST
    p = head;
    while (p != NULL) {
        /* visit element p (p->key field) */
        p = p->next;
    }

    //SEARCHING
    p = head;
    int value;
    int goOn = 1;
    while (p != NULL && goOn == 1) {
        if (value == p->key) {
            //something here
            goOn = 0;
            return 1;
        } else {
            p = p->next;
        }
    }

    //ANOTHER WAY OF SEARCHING (ALTHOUGH IS KINDA BUGY)
    p = head;
    while ((p != NULL) && p->key != value) {
        p = p->next;
    }
    if (p != NULL) {
        //value has been found since the above loop has been exited
    }

    //searching in an ordered list
    while (p != NULL && value > p->key) {
        p = p->next;
    }
    if (p != NULL && value == p->next) {
        //value found
    }



    //EXTRACTION USING TWO EXPLICIT POINTERS
    list_t *p1,*p2;
    if(head==NULL){
        //empty list
    }
    if(value ==head->key) {
        p = head->next;
        free(head);
        head = p;
    }

    //initialization
    p1=head;
    p2=head->next;
    //searching for the extraction point
    while(p2!=NULL && value>p2->key){
        p1=p2;
        p2=p2->next;
    }
    if(p2!=NULL && value==p2->key){
        p1->next = p2->next;
        free(p2);
    }else{
        //element not found
    }


    //EXTRACTION USING ONE EXPLICIT POINTERS
    if(head==NULL){
        //empty list
    }

    //this part is kinda confusing for me
    if(value = head->key){
        p=head->next;
        free(head);
        head = p;   //especially this part that we are reusing head, since it's just been freed
    }
    p1=head;
    //IMPORTANT TRICK HERE
    while (p1->next !=NULL && value> p1->next->key) {
        p1=p1->next;
    }

    if(p1->next!=NULL &&  value==p1->next->key){
        p2=p1->next; //temporary pointer here,p2 i guess
        p1->next = p2->next;
        free(p2);
    } else {
        //element not found
    }

    //INSERTION
    //we are inserting p between p1 and p2

    //where to insert the element,look for where to put
    p->next=p2;
    p1->next=p;

    p=new_element();
    p->key = value;
    p->next = NULL;
    if(head==NULL || value < head->key){
        p->next = head;
        head=p;
    } else {
        p1= head;
        p2=head->next;
        while ()
    }
    return 0;
}





list_t  *new_element() {
    list_t *e_ptr; //points to another element of list_t , for storing the allocation of a new node
    e_ptr = (list_t *) malloc(sizeof(list_t));
    if(e_ptr==NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    return (e_ptr);
}

list_t *search(list_t *head, int id){
    list_t *p;

    while(p!=NULL && p->key!=id){
        p=p->next;
    }
    return p;
}
