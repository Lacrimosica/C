
#include <stdio.h>
#include <stdlib.h>


void printArray(int * , int);
int * makeArray(int);
void quickFind(int);
void quickUnion(int);
void quickUnionOpt(int);
void insertionSort(int *, int);
void bubbleSort(int *,int);
void selectionSort(int *, int );
void shellSort(int *, int );
void countingSort(int * array, int n, int k);
int main(void){

    printf("what do you want to do?\n");
    printf("1- quick find\n");
    printf("2- quick union\n");
    printf("3- quick union(optimized)\n");
    printf("4- insertion sort\n");
    printf("5- selection sort\n");
    printf("6- bubble(exchange) sort\n");
    printf("7- shell sort\n");
    printf("8- counting sort\n");


    int len;
    int i,j,k,h;
    int choice;

    scanf("%d", &choice);
    switch(choice){
        
    
        
        case 1:
            printf("input array length\n");
            scanf("%d", &len);
            quickFind(len);
            break;
        case 2:
            printf("input array length\n");
            scanf("%d", &len);
            quickUnion(len);
            break;

        case 3:
            printf("input array length\n");
            scanf("%d", &len);
            quickUnionOpt(len);
            break;
        case 4:
            printf("input array length\n");
            scanf("%d", &len);

            insertionSort(makeArray(len),len);
            break;
        case 5:
            printf("input array length\n");
            scanf("%d", &len);
            selectionSort(makeArray(len),len);
            break;
        case 6:
            printf("input array length\n");
            scanf("%d", &len);

            bubbleSort(makeArray(len),len);
            break;
        case 7:
            printf("input array length\n");
            scanf("%d", &len);
            shellSort(makeArray(len), len);
            break;

        case 8:
            printf("input array length\n");
            scanf("%d", &len);
            printf("input number of max range\n");
            scanf("%d" , &k);
            countingSort(makeArray(len), len , k);
            break;

    }


}

//connectivity
void quickUnionOpt(int n){
    int *id = (int *) malloc(n * sizeof(int));
    int *sz = (int *) malloc(n * sizeof(int));
    int p,q,t,i,j;

    for(i=0; i< n; i++){
        id[i] = i;
        sz[i]= 1;
    }

    do{
        printf("Input par p,q : \n");
        scanf("%d %d" , &p, &q);
        for(i=p; i!= id[i]; i = id[i]);
        for( j= q; j!= id[j]; j = id[j]);

        if(i != j) {
            if(sz[i] <= sz[j]){
                id[i] =j; 
                sz[j] += sz[i];
            }else{
                id[j] = i; 
                sz[i] += sz[j];
            }
            printf("%d-%d: ",p,q);
            printArray(id, n);
        }else if( i == j){
            printf("%d-%d are already connected\n", p, q);
        }
    }while( p!=q);

}

void quickUnion(int n){
    int *id = (int *) malloc(n * sizeof(int));
    int p,q,t,i,j;

    for(i=0; i< n; i++){
        id[i] = i;
    }

    do{
        printf("Input par p,q : \n");
        scanf("%d %d" , &p, &q);
        for(i=p; i!= id[i]; i = id[i]);
        for( j= q; j!= id[j]; j = id[j]);
        if(i != j) {
            id[i] = j;
            printf("%d-%d: ",p,q);
            printArray(id, n);
        }else if( i == j){
            printf("%d-%d are already connected\n", p,q);
        }
    }while( p!=q);

}

void quickFind(int n){
    int *id = (int *) malloc(n * sizeof(int));
    int p,q,t,i;

    for(i=0; i< n; i++){
        id[i] = i;
    }

    do{
        printf("Input par: p q : \n");
        scanf("%d %d" , &p, &q);
        if(id[p] != id[q]){
            for(t = id[p], i=0 ; i <n ; i++){
                if(id[i] == t){
                    id[i] = id[q];
                }
            }
            printf("%d-%d : ", p,q);
        }
        printArray(id, n);
    }while( p!=q);
}


//sort
void insertionSort( int *array, int len){
int x;
int i,j;
for(i=1; i< len; i++){
    x = array[i];
    j = i-1;    

    while( j>=0 && array[j] > x){
        array[j+1] =  array[j];
        j--;
    }
        array[j+1] = x;
        printArray(array, len);
    }
}

void selectionSort(int *array, int n){
    int i, j, min, temp;
    for (i=0; i<n-1; i++) {
        min = i;
        for (j=i+1; j<n; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    printArray(array, n);
}

void bubbleSort(int *array, int len){
    int i,j,temp;
    int n= len;

    for( i=0 ; i< n-1; i++){
        for(j=0; j< n-i-1; j++){
            if( array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            printArray(array, len);
        }
    }
}

void shellSort(int * array, int n){
    int h,i,j,x;

    for( h=1; h< n; h= 3*h+1);

    for(h; h>0 ; h= (h-1)/3){
        for(i =h; i< n; i++){
        x = array[i];
        j = i-h;
        while(j>=0 && x<array[j]) {
            array[j+h] = array[j];
            j-=h;
        }
        array[j+h] =x;
        printArray(array, n);
        }
    }
    
}

void countingSort(int * array, int n, int k){
    //k distinct numbers;
    int i, c[100], b[100];

    for(i=0; i<k; i++){
        c[i] = 0;
    }

    for(i=0; i<n; i++){
        b[i] = -100;
    }


    for(i=0; i<n; i++){
        c[array[i]]++;
    }
    printf("Initial C after counting one time all elements:\n");
    printArray(c, k);

    for(i=1; i< k ; i++){
        c[i] += c[i-1];
    }

    printf("intermediate C after summing:\n");
    printArray(c, k);

    for(i=n-1 ; i>=0; i--){
        b[c[array[i]]-1] = array[i];
        c[array[i]]--;
        printf("C: %d: " , n-i);
        printArray(c, k);
    }

    for(i=0; i<n ; i++){
        array[i] = b[i];
    }
    printf("final array:B:\n");
    printArray(b, n);


}


// void mergeSort(int *A, int N){
//     int l=0;
//     int r= N-1;
//     int *b = (int *) malloc(N * sizeof(int));
//     merge_sort_r (A, B, l,r);
// }

// void merge_sort_r (int *A, int *B, int l, int r){
//     int c;
//     if(r <=1){
//         return;
//     }

//     c=(l+r)/2;
//     merge_sort_r(A,B,l,c);
//     merge_sort_r(A,B, c+1, r);
//     merge(A,B,l,c,r);
//     return;
// }

// void merge(int *A, int *B, int l, int c, int r, int N){
//     int i,j,k;

//     for(i=1, j= c+1, k=1 i<=c && j<=r; ){
//         if(A[i] <= A[j]){
//             B[k++] = A[i++];
//         }else{
//             B[k++] = A[j++];
//         }


//         while(i<=c){
//             B[k++] = A[i++];
//         }

//         while(j<=r){
//             B[K==] = A[j++];
//         }

//         for(k=1 k<=r; k++){
//             A[k] = B[k];
//         }

//         return;
//     }
// }


// void quickSort(int *array, int n){
//     int l,r;
//     l=0;
//     r = N-1;
//     quick_sort_r(array, l ,r);
// }

// void quick_sort_r (int *A, int l, int r){
//     int c;
//     if(r <=1){
//         return;
//     }


//     c = partition(A,l, r);

//     quick_sort_r(A,l,c-1);
//     quick_sort_r(A,c+1,r);
//     return;
// }

// int partition(int *A, int l, int r){
//     int i,j,pivot;

//     i=l-1; j=r;
//     pivot = A[r];

//     while(i<j){
//         while (A[++i] < pivot);
//         while(j>1 && A[--j] >=pivot);
//         if(i< j){
//             swap(A, i,j);
//         }
//     }

//     swap(A,i,r);
//     return i;
// }


// void swap(int *v, int n1, int n2){
//     int temp;
//     temp = v[n1];
//     v[n1]= v[n2];
//     v[n2] = temp;
//     return;
// }

//utilities
void printArray(int *a, int n){
        int i;
        printf("[ ");
        for(i =0 ; i< n; i++){
            printf(" %d ", a[i]);
        } 
        printf("] \n");
    }

int * makeArray(int n){
    int i;
    int *array = (int *) malloc( n * sizeof(int));
    for(i=0; i< n; i++ ){
        scanf("%d", &array[i]);
    }

    return array;
}
