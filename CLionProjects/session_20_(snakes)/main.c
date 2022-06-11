#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct snake{
    int i,j;   //coordinate of the head
    int l;
};
void PrintArray2d(char **A,int R, int C);
char **malloc2d(int, int);
int find(int n, char **map, int R,int C, struct snake *s);
int find_all(int row, int col, int R, int C, char **map, struct snake s);
void free2d(char **mat , int R);

int main(int argc,  char*argv[]) {
    char **map;
    struct snake *sns;
    int R, C, i, j, nsnake;
    FILE *fp;
    int n; //number of snakes


    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "error reading file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d%d%*c", &R, &C);
    map = malloc2d(R, C);


    nsnake = 0;
    for (i = 0; i < R; ++i) {
        for (j = 0; j < C; ++j) {
            fscanf(fp, "%c", &map[i][j]);
            if (map[i][j] == '+') {
                nsnake++;
            }
        }
        fscanf(fp, "%*c");
    }
    fclose(fp);


    sns = (struct snake *) (n * sizeof(struct snake));
    n = 0;
    do {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (map[i][j] == '+');
                sns[n].i = i;
                sns[n].j = j;
                sns[n].l = 1;
            }
        }
    } while (n < nsnake);
    find(nsnake, map, R, C, sns);


    free2d(map, R);

    //one should do a sorting here
    printf("snake number :%d\n", nsnake);
    int min = sns[0].l;
    for (int k = 0; k < nsnake; ++k) {
        if (min > sns[k].l) {
            min = sns[k].l;
        }
    }
    printf("minimum snake length :%d\n", min);

    int max = sns[0].l;
    for (int k = 0; k < nsnake; ++k) {
        if (max < sns[k].l) {
            max = sns[k].l;
        }
    }
    printf("maximum snake length :%d\n", max);
    return 0;

}



char **malloc2d(int r, int c) {
    int i;
    char **mat;
    mat = (char **) malloc(r * sizeof(char *));
    if(mat==NULL){
        fprintf(stderr,"Memory allocation error");
    }
    for (i = 0; i < r; ++i) {
        mat[i] = (char *) malloc(c * sizeof(char));
        if(mat[i]==NULL){
            fprintf(stderr,"Memory allocation error");
        }
    }
    return mat;
}


int find(int n, char **map, int R,int C, struct snake *s) {
    while (n > 0) {
        find_all(s[n].i, s[n].j, R, C, map, s[n]);
        n--;
    }
}


int find_all(int row, int col, int R, int C, char **map, struct snake s){
    int r,c;
    int flag;
    int pd=0;
    int offsets[2][8]={{0, -1, -1 , -1, 0 , 1 , 1 , 1},
                       {1 , 1 , 0 , -1, -1, -1, 0, 1} };

    for (int i = pd; i < 8; ++i) {
        r=row + offsets[0][i];
        c=col + offsets[1][i];
        if(r< 0 || r>=R || c<0 || c>= C || map[r][c] !='*') {
            flag=0;
        }else{
            s.l++;
            s.i=r;
            s.j=c;
            pd=i;
        }
    }
}

void free2d(char **mat , int R){
    int i;
    for (i=0; i<R; i++){
        free(mat[i]);
    }
    free(mat);
}

void PrintArray2d(char **A,int R, int C){
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%c", A[i][j]);
        }
        printf("\n");
    }
}
 */
