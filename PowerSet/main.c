#include "library.h"

int main(void){

    int vals[N]= {1,2, 3, 4};
    int solution[N]={0,0,0,0};
    int cnt=0;

    int k;

    for(int k=0; k< N ; k++){
        cnt+=powerset3(vals, solution, k); 
        // cnt+=powerset2(vals, solution ,0, k, cnt);
        printf("\n");
    }

    printf("count = %d\n", cnt);
    return EXIT_SUCCESS;
}