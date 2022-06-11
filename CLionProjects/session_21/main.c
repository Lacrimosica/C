#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct{
    char value;
    int visited;
}element_t;

element_t **malloc2d(int,int);
element_t  **free2d(element_t **,int );
int map_read(char *, element_t ***, int *, int *);
int length_evaluate(element_t **,int, int, int, int);

int main(int argc, char *argv[]){
    element_t **map;
    int nsnake=0, minLen=INT_MAX, maxLen=0;
    int nr,nc,i,j,length;

    if(argc >2){
        fprintf(stderr, "wrong number of arguments\n");
    }
    //map is read and the number of columns and rows is updated
    if(!map_read(argv[1] , &map, &nr, &nc)){
        return 1;
    }


    for (i = 0; i < nr; ++i) {
        for (j = 0; j < nc; ++j) {
            if(map[i][j].value == '+'){
                nsnake++;
                length = length_evaluate(map, nr,nc,i,j);
                if(length<minLen){
                    minLen = length;
                }
                if (length>maxLen){
                    maxLen= length;
                }
            }
        }
    }
    free2d(map,nr);

    fprintf(stdout, "snake number = %d\n",nsnake);
    fprintf(stdout, "minimum snake length = %d\n" , minLen);
    fprintf(stdout, "maximum snake length = %d\n" , maxLen);

    return 0;
}

element_t **malloc2d(int r, int c){
    element_t **mat;
    mat = (element_t **)malloc(r * sizeof(element_t *));
    if (mat == NULL){
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < r; ++i) {
        mat[i]= (element_t *) malloc(c *sizeof(element_t));
        if (mat[i] == NULL){
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

element_t **free2d(element_t **mat, int r){
    for (int i = 0; i < r; ++i) {
        free(mat[i]);
    }
    free(mat);

    return mat;
}

int map_read(char *file_name, element_t ***mapP, int *nr, int *nc){
    element_t **map;
    FILE *fp;
    fp= fopen(file_name, "r");
    int i,j;
    char c;
    if(fp==NULL){
        fprintf(stderr, "error reading file\n");
        exit(EXIT_FAILURE);
    }
    if(fscanf(fp, "%d %d", nr,nc) !=2){
        fprintf(stderr, "error while reading first line of the file\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c", &c);

    map =malloc2d( *nr, *nc); //we are dereferencing the pointers
    for (i = 0; i < *nr; ++i) {
        for (j = 0; j < *nc; ++j) {
            if(fscanf(fp,"%c", &map[i][j].value) !=EOF) {
                map[i][j].visited = 0;
            } else {
                fprintf(stderr, "error while parsing the input file.\n");
                fclose(fp);
                return EXIT_FAILURE;
            }
        }
        fscanf(fp,"%c", &c);
    }
    fclose(fp);
    *mapP = map;

    return 1;
}

int length_evaluate(element_t **map, int nr, int nc, int r, int c) {
    int length = 1, end = 0, found, r_new, c_new;

    map[r][c].visited = 1;

    while (!end) {
        found = 0;
        for (int i = r - 1; i <= r + 1 && found == 0; ++i) {
            for (int j = c - 1; j <= c + 1 && found == 0; ++j) {
                if (i >= 0 && i < nr && j >= 0 && j < nc) {  //to check if the new coordinates is in the matrix
                    if (map[i][j].value == '*' && !map[i][j].visited) {
                        found = 1;
                        r_new = i;
                        c_new = j;
                    }
                }
            }
        }
        if(found){
            length++;
            r=r_new;
            c=c_new;
            map[r][c].visited=1;
        } else{
            end =1;
        }
    }
    return length;
}




