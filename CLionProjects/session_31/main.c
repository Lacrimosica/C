#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
void map_read(char *, int ***, int *, int *);
void expand_r (int **, int, int, int);
void map_write(char *, int **, int, int, int);

int main(int argc,char *argv[]){
	int i,j,nr,nc,n=0;
    int **map;
   
	if(argc!=2){
		perror("Error: ");
		exit(EXIT_FAILURE);
	}
	
    map_read(argv[1], & map, &nr, &nc);
    for(i=0;i<nr; i++){
        for(j=0; j<nc; j++){
            if(map[i][j] == (-1)){
                expand_r(map, i,j,++n);
            }
        }
    }
    
    map_write(argv[2], map, nr,nc,n);
    printf("i get here");

    return EXIT_SUCCESS;
}

void map_read(char *name, int ***m,int *nr, int *nc){
    FILE *fp;
    int i,j;
    int **map;
    map=*m;

    char line[MAX+2];

    fp=fopen(name, "r");
    
    if(fp==NULL){
        fprintf(stderr,"Error reading file %s", name);
        exit(EXIT_FAILURE);
    }

    i=0;
    while(fgets(line, MAX, fp) !=NULL){
        map=(int **)malloc(20 * sizeof(int *));
        if(map==NULL){
            fprintf(stderr, "Memory allocation error");
            exit(EXIT_FAILURE);
            }
        j=0;
        while(j<MAX && (line[j] =='.' || line[j]=='*')){
            map[i]=(int *)malloc(strlen(line) *sizeof(int));
            if(map[i]=NULL){
                fprintf(stderr, "Memory allocation error");
                exit(EXIT_FAILURE);
                }
            map[i][j] = (line[j] =='*' ? 0: -1);
            j++;
        }
        i++;
    }
    fclose(fp);

    *nr=i;
    *nc=j;
    m=&map;
    return;

}

void expand_r (int **map, int x, int y, int id){
    int i,xx,yy;
    const int xoffset[4] = {1,0 , -1, 0};
    const int yoffset[4] = {0 , 1, 0, -1};

    if(map[x][y]!=-1){
            return;
    }

    map[x][y] = id;
    
    for(i=0; i<4; i++){
        xx= x + xoffset[i];
        yy = y + yoffset[i];
        expand_r(map, xx, yy,id);
    }
}


void map_write(char *name, int **map, int nr, int nc, int n){
    FILE *fp;
    int i,j;

    fp=fopen(name, "w");

    for(i=0; i<nr;i++){
        for(j=0; j<nc;j++){
            if(map[i][j]==0){
                fprintf(fp, "*");
            }else {
                fprintf(fp, "%d", map[i][j]);
            }
        }
        fprintf(fp,"\n");
    }
    fprintf(stdout, "regions number = %d\n",  n);

    fclose(fp);

    return;
}


