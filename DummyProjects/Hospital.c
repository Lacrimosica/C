#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    int day;
    int month;
    int year;
}date;

typedef struct{
    int caseNum;    //is going to start from 1 to 1025!
    char *name;
    char *address;
    int age;
    char gender;
    char *description;
    int roomNum;

    //case registeration date
    date registerationDate;
    
    //what was the point of this again?
    double totalCredit;
    double totalDeposit;
    double totalReturn;

} patient;

void addPatient(patient*, int * , date *);                                 //args: array of patients, patient counter, date of that day
patient SearchPatientRecord(patient*, int , char *, char);              //args: array of patients , patient counter, search key, search mode
void EditpatientRecord(patient *, int id);                         //args: array of patients, id of patient
void PrintPatientInfo(patient);                                             //args: patient struct
void PrintFinancialInfo(patient);                                           //args: patient struct
void ListPatients(patient *, int , char);                                  //args:array of patients, patient count, listing mode
void DeletePatientRecord(patient * ,int *);    //args:array of patients, patient count, id
void Formatter();

int main(void){
    int id;
    int c;  //stands for choice
    int patientCounter = 0;
    //to have a dating system of our own

    date today;
    

    //dynamically allocated array of patients
    patient * patients = (patient * ) malloc( 1024 * sizeof(patient));

    if(patients == NULL){
        fprintf(stderr, "Error while allocatign memory");
        exit(EXIT_FAILURE);
    }

    //set the date in order to have it as patient info
    printf("what is the date today?\n");
    printf("day:\n");
    scanf("%d", &today.day);
    printf("month(1-12):\n");
    scanf("%d", &today.month);
    printf("year:\n");
    scanf("%d", &today.year);

    printf("date set successfully\n");
    
    printf("--------WOLCOME TO MY HOSPITAL PROGRAM--------\n");
    while(1){
        printf("--------------------MENU--------------------\n");
        printf("Input the number of your choice:\n");
        printf("1- Add new patient \n");
        printf("2- Search/Edit for a patient record\n");
        printf("3- List patients\n");
        printf("4- Delete patient record\n");
        printf("5- Exit\n");
    
        scanf("%d" , &c);

        switch(c){

            case 1:
                addPatient(patients, &patientCounter, &today);
                break;
            case 2:
                Formatter();
                printf("1- search\n");
                printf("2- Edit");
                scanf("%d", &c);

                switch(c){
                    case 1: //search
                        Formatter();
                        printf("search with:\n 1-id\n 2-name\n");
                        scanf("%d" , &c);
                        switch(c){
                            char key[100];
                            int response;
                            patient searchResult;

                            case 1: //get case id to search with
                                
                                Formatter();
                                printf("input id\n");
                                scanf("%s" , key);
                                searchResult = SearchPatientRecord(patients, patientCounter, key,'i');
                                PrintPatientInfo(searchResult);
                                Formatter();
                                printf("do you want to get patient's financial statement?(y/n)\n");
                                response = getchar();
                                if(response == 'y') PrintFinancialInfo(searchResult);
                                break;
                            case 2:
                            //get name to search with
                                Formatter();
                                printf("input name (firstname lastname togheter with space)");
                                gets(key);
                                searchResult = SearchPatientRecord(patients,patientCounter, key, 'n');
                                PrintPatientInfo(searchResult);
                                Formatter();
                                printf("do you want to get patient's financial statement?(y/n)\n");
                                response = getchar();
                                if(response == 'y') PrintFinancialInfo(searchResult);
                                break;
                        }
                    //edit
                    case 2: //editing phase, first get the id number for it and then edit it
                        printf("search with:\n 1- id\n 2-name\n");
                        scanf("%d" , &c);
                        switch(c){
                            char key[100];
                            int id;
                            patient searchResult;
                            case 1:
                                //get case id to search with
                                printf("input id\n");
                                scanf("%d" , &id);
                                EditpatientRecord(patients, id);
                                break;
                            case 2:
                            //get name to search with
                                Formatter();
                                printf("input name (firstname lastname togheter with space)\n");
                                gets(key);
                                searchResult=  SearchPatientRecord(patients,patientCounter, key, 'n');
                                EditpatientRecord(patients, searchResult.caseNum);
                                break;
                        }
                        break;
                }
                break;
                //list patients
            case 3:
                Formatter();
                printf("how do you want records to be listed?\n");
                printf("1-order they were inserted in\n");
                printf("2-by alphabetical order\n");
                printf("3-at specific date");

                scanf("%d", &c);
                switch(c){
                    case 1:
                        ListPatients(patients, patientCounter,'n');    //n stands for normal
                        break;
                    case 2:
                        ListPatients(patients, patientCounter,'s');    //n stands for sort
                        break;
                    case 3:
                        ListPatients(patients, patientCounter,'d');    //d stands for date
                        break;
                }
                break;
            case 4:
                DeletePatientRecord(patients , &patientCounter);
                break;
            case 5:
                exit(0);
        }
    }
}

void addPatient(patient *patients, int * counter, date * d){
    char buffer[100];
    int index = *counter;

    patient p;

    //set date
    p.registerationDate = *d;
    
    //get patient's name
    Formatter();
    printf("input name (firstname & lastname togheter with space)\n");
    getchar();               //catches the newline character
    gets(buffer);
    p.name = strdup(buffer);
    //get patient's address
    Formatter();
    printf("enter patient address\n");
    gets(buffer);
    p.address = strdup(buffer);
    //get patient's age
    Formatter();
    printf("enter patient age\n");
    scanf("%d", &p.age);

    //get patient's gender
    Formatter();
    printf("enter patient gender (m/f)\n");
    scanf("%*c%c", &p.gender);

    //get patient's disease? description
    Formatter();
    printf("enter patient description\n");
    getchar();                      //catches the newline character
    gets(buffer);
    p.description = strdup(buffer);

    //get number of the room of professional
    Formatter();
    printf("enter patient room\n");
    scanf("%d", &p.roomNum);

    p.caseNum = index+1;
    patients[index++] = p;  //assigsn p as the index-th element in "patients" struct array, then increments index;
    *counter = index;       //assings the incremented index to total count of patients

    Formatter();
    printf("Patient successfully added!\n");
}

patient SearchPatientRecord(patient *patients, int count, char *key, char searchType){
    patient res;
    //search with name
    if(searchType == 'n'){
        for(int i=0 ; i< count ; i++){
            if(strcasecmp(patients[i].name, key) == 0) return patients[i];
        }
        fprintf(stderr, "!!!!patient record not found!!!!\n");
    }
 
    //search by id
    if(searchType == 'i'){
        int id;
        sscanf(key,"%d", &id);
        return patients[id-1];
    }
    fprintf(stderr, "!!!!!patient record not found!!!!\n");
}

void EditpatientRecord(patient * patients, int id){
    char buffer[100];
    int response;
    patient p  = patients[id];

    //edit patient's name
    Formatter();
    printf("do you want to edit patient name? (y/n)\n");
    getchar();
    response = getchar();
    if(response == 'y'){
        printf("enter the new one!\n");
        getchar();
        gets(buffer);
        strcpy( p.name, buffer);
    }
    //edit patient's address
    Formatter();
    printf("do you want to edit the  patient address(y/n)\n");
    getchar();
    response = getchar();
    if(response == 'y'){
        printf("enter the new one!\n");
        getchar();
        gets(buffer);
        strcpy(p.address,buffer);
    }
    //edit patient's age
    Formatter();
    printf("do you want to edit the patients age?(y/n)\n");
    getchar();
    response = getchar();
    if(response == 'y'){
        printf("enter the new one!\n");
        scanf("%d", &p.age);
    }

    //edit patient's gender
    Formatter();
    printf("do you want to edit patient's gender?(y/n)\n");
    response = getchar();
    if(response=='y'){
        printf("enter the new one!\n");
        scanf("%*c%c", &p.gender);
    }

    //edit patient's disease? description
    Formatter();
    printf("do you want to edit patient's description(y/n)\n");
    response = getchar();
    if(response =='y'){
        printf("enter the new one!\n");
        gets(buffer);
        strcpy(p.description,buffer);
    }

    //edit number of the room of professional
    Formatter();
    printf("do you want to edit patient's description(y/n)\n");
    response = getchar();
    if(response == 'y'){
        printf("enter the new one!\n");
        scanf("%d", &p.roomNum);
    }

}

void Formatter(){
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
}

void PrintPatientInfo(patient p){
    Formatter();
    printf("#Case: %d, name: %s\nage: gender:%c\n%d\naddress: %s\ndisease description: %s\nMedic's #Room: %d\n" , p.caseNum, p.name, p.age, p.gender, p.address , p.description , p.roomNum);
}

void PrintFinancialInfo(patient p){
    Formatter();
    printf("TotalCredit: %lf\nTotal Deposit :%lf\nTotalReturn: %lf\n" , p.totalCredit, p.totalDeposit, p.totalReturn);
}

void ListPatients(patient * patients, int patientCount, char listingType){
    int response;
    date d;
    patient p;

    if(listingType == 'n'){
        printf("press enter to view next result (press any other key to exit)\n");
        response= getchar();
        for(int i=0 ;i< patientCount ; i++){
            PrintPatientInfo(patients[i]);
            response = getchar();
            if(response != '\n') return;
        }
        printf("***THE END**\n");
    }

    if(listingType == 'd'){
        //get date to look for
        printf("day:\n");
        scanf("%d", &d.day);
        printf("month(1-12):\n");
        scanf("%d", &d.month);
        printf("year:\n");
        scanf("%d", &d.year);



        printf("viewing results for %d/%d/%d: \n" , d.day , d.month , d.year);
        printf("press enter to view next result (press any other key to exit)\n");
        response= getchar();



        for(int i=0 ;i< patientCount ; i++){
            p = patients[i];

            if(p.registerationDate.day == d.day && p.registerationDate.month == d.month && p.registerationDate.year == d.year ){
                PrintPatientInfo(patients[i]);
                response = getchar();
                if(response != '\n') return;
            }
        }
        printf("***THE END**\n");
    }

    if(listingType == 's'){
        //make a copy of the list 
        patient toBeSorted[patientCount];
        for(int k=0; k< patientCount ; k++){
            toBeSorted[k] = patients[k];
        }

        //sorting using insertion sort
        int i,j;
        patient key;

        for(i=1; i<patientCount ; i++){
            key = toBeSorted[i];
            j=i-1;
            while(j>=0 && strcmp(key.name, patients[j].name) ){
                toBeSorted[j+1] = toBeSorted[j];
                j= j-1;
            }
            toBeSorted[j+1] = key;
        }


        //printing stage
        printf("viewing sorted results:\n");
        printf("press enter to view next result (press any other key to exit)\n");
        response= getchar();
        for(int i=0 ;i< sizeof(toBeSorted) ; i++){
            PrintPatientInfo(toBeSorted[i]);
            response = getchar();
            if(response != '\n') return;
        }
        printf("***THE END**\n");
    }

}
    

void DeletePatientRecord(patient * patients ,int *patientCount){
    int id;
    int response;
    int length = *patientCount;
    Formatter();
    printf("enter the id of the patient to be deleted\n");
    scanf("%d" , &id);

   if(id <= length){
        Formatter();
        printf("do you want to see patient info?(press Enter if yes)\n");
        response = getchar();
        if(response == '\n'){
            PrintPatientInfo(patients[id-1]);
        }else{
            return; //get out of deletion process
        }
        Formatter();
        printf("do you want to delete patient record?(press Enter if yes)\n");
        response = getchar();
        if(response == '\n'){
            for(int i=id-1; i< length-1; i++){
                patients[i] = patients[i+1];
            }
            Formatter();
            printf("deletion executed successfully\n");
            *patientCount = length-1;
        }else{
            return; //get out of deletion process
        }
    }else{
        fprintf(stderr, "Record not found\n");
    }
}





