#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EX? //toggle to switch between exercises

#ifdef EX1
#define DIM 15
#endif

#ifdef EX2
#define DIM 100
#endif

#ifdef EX3
#define R   3
#define C   5
#endif

#ifdef EX4
#define MAX_DIM 10



#endif
//Exercise 01
/*-----------

Write a C program able to:
- Read an array of integer values of size DIM, where DIM is a
pre-defined constant.
- Find and print-out the longest ascending sub-sequence on integer
        values within the array.


Example
-------

Let DIM be equal to 15, ant let the array be the following one:

2   3   4  -1  -10   5   6   8   11  -9   8  -10   9   3   0

The program has to print-out the sub-sequence:

-10   5   6   8   11
*/
#ifdef EX1
int main() {
    int i, v[DIM],maxlen=1, len=0,idx=0;

    //reading the array
    fprintf(stdout, "input integer: \n");
    for(i=0 ; i<DIM; i++) {
        fscanf(stdin, "%d", v + i);
    }

    for (int i = 0; i < DIM; ++i) {
        if(i< DIM-1 && v[i]<v[i+1]){
            len++;
        }else {
            if(len>maxlen){
                maxlen=len+1;
                idx= i-len;
            }
            len=0;
        }
    }

    for (int i = idx; i<idx +maxlen; ++i) {
        fprintf(stdout,"%d " , v[i]);
    }

    return 0;
}
#endif

//Exercise 02
/*-----------

Write a C program able to:
- Read two integer values N1 and N2.
- Check whether N1<=DIM and N2<=DIM (DIM is a pre-defined constant
value).
- Read from standard input an array v1 of N1 integer values
- Compute an array v2 of N1 integer values, where each v2[i] is equal
to the arithmetic average of
        v1[i-N2], v1[i-N2+1], ..., v1[i-1], v1[i], v1[i+1], ..., v1[i+N2]
if they exist.
- Print-out v2.


Example
-------

Let us suppose DIM = 100, N1 = 10, N2 = 2, ant let v1 be the following
        one:

0   2   3   4  -1  -10   5   1   8   3

Each element of v2[i] has to be equal to the average of at most
5 (2 on the left of v1[i], 2 on the right of v1[i], and v1[i] itself)
elements "around" v1[i], e.g.:

v2[0] = (0 + 2 + 3) / 3 = 1.67
v2[1] = (0 + 2 + 3 + 4) / 4 = 2.25
v2[2] = (0 + 2 + 3 + 4 + (-1)) / 5 = 1.60
v2[3] = (2 + 3 + 4 + (-1) + (-10)) / 5 = -0.40
etc.

As a consequence, the program has to print-out the sub-sequence:
1.67  2.25  1.60  -0.40  0.20  -0.20  0.60  1.40  4.25  4.00
*/
#ifdef EX2
int main() {
    int N1, N2, i,j;
    int flag = 1, n;
    float sum, v1[DIM], v2[DIM];
    //getting and checking values

    while (flag) {
        fprintf(stdout, "input N1 and N2: \n");
        fscanf(stdin, "%d %d", &N1, &N2);
        if (N1 <= DIM && N2 <= DIM && N1> 0 && N2>0) {
            flag = 0;
        } else {
            fprintf(stderr, "numbers should be less than %d\n", DIM);
        }
    }

    //v1 input
    fprintf(stdout, "input array: \n");
    for (i = 0; i < N1; ++i) {
        scanf( "%d", v1 + i);
    }

    for (i = 0; i < N1; ++i) {
        n = 0;
        v2[i]=0;
        for (j = i - N2; j <= i + N2; ++j) {
            if (j >= 0 && j < N1) {
                v2[i] += v1[j];
                n++;
            }
        }
        v2[i] = v2[i]/n;
    }


    for (int i = 0; i < N1; ++i) {
        fprintf(stdout, "%.2f ", v2[i]);
    }
}
#endif

//Exercise 03
/*-----------

Write a C program able to:
- Read a matrix m1 of R rows and C columns of integer values
- Compute a matrix m2 of R rows and C columns such that
- m2[i][j] is equal to zero
if m1[i][j] is equal to zero.
- m2[i][j] is the factorial number of -m1[i][j]
if m1[i][j] is a negative number.
- m2[i][j] is the smallest power of 10 larger than m1[r][j]
if m1[i][j] is a positive number.

Example
-------

Let R and C be equal to 3 and 5 respectively.
Let m1 be the following:

9   23   155   -1    33
0   -2    -4    8    -6
20   -1     0    0   499

m2 has to be:

10 100 1000 1 100
0 2 24 10 720
100 1 0 0 1000
*/
#ifdef EX3
int factorial(int);
int power(int, int);

int main() {
    int m1[R][C], m2[R][C]={0};
    int v,t;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d",&v);
            m1[i][j]= v;
            if (v==0) {
                m2[i][j] = 0;
            }else if(v<0) {
                m2[i][j] = factorial(v);
            }else if(v>0) {
                t = 0;
                do {
                    v = v / 10;
                    t++;
                } while (v > 1);
                m2[i][j] = power(10, t);
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    return 1;
}
int factorial(int n){
    int r=1;
    if (n<0){
        n=-n;
    }
    if(n>0) {
        for (int i = 1; i <= n; ++i) {
            r = r * i;
        }
    }
    return r;
}
int power(int x, int y){
    for (int i = 1; i < y; ++i) {
        x=x*x;
    }
    return x;
}
#endif

//Exercise 04
/*-----------

Write a C program able to compute the product of two matrices
containing      real        values.

The program has to proceed as follows:
1. It defines two matrix's m1 and m2 of "physical" size equal to MAX_DIM rows and MAX_DIM columns, where MAX_DIM is a
 pre-defined constant.

2. It reads the "logical" (actual) size of the two matrices: r1 rows and c1 columns for m1 and r2 rows and c2 columns
 for m2.

3. It verifies whether r1, c1, r2, and c2 are smaller than MAX_DIM,
and whether c1==r2 (i.e., it is possible to compute the product).

4. It reads m1 and m2 from standard input.

5. It computes the product
m3 = m1 x m2
with m3 having r1 rows and c2 columns.

6. It prints-out m3 on standard output.

Example
-------

If m1 is the following on (with 2 rows and 3 columns)
1.00    2.00    3.00
4.00    5.00    6.00
and m2 is the next one (with 3 rows and 2 columns)
1.00    2.00
3.00    4.00
5.00    6.00
the output matrix must be the following:
22.00   28.00
49.00   64.00
 */
#ifdef EX4
//we are computing m1 x m2 , so c1==r2 has to be true
int main(){
    double m1[MAX_DIM][MAX_DIM], m2[MAX_DIM][MAX_DIM];
    int r1,c1,r2,c2;

    //getting matrix dimensions
    fprintf(stdout, "input: r1 c1 r2 c2: \n");
    fscanf(stdin," %d%d%d%d" , &r1, &c1 , &r2, &c2);

    //checks and initializations
    if(c1!=r2 || (r1>MAX_DIM || c1>MAX_DIM || r2>MAX_DIM || c2>MAX_DIM) ){
        fprintf(stderr, "multiplication can't be done\n");
        exit(EXIT_FAILURE);
        //get matrixes as input here
    }else{
        fprintf(stdout,"Input Matrix 1\n");

        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) {
                fscanf(stdin, "%lg", &m1[i][j]);
                //fprintf(stdout, "%.2lg ", m1[i][j]);
            }
            fprintf(stdout, "\n");
        }
        fprintf(stdout, "Input Matrix 2\n");
        for (int i = 0; i < r2; ++i) {
            for (int j = 0; j < c2; ++j) {
                fscanf(stdin, "%lg", &m2[i][j]);
                //fprintf(stdout, "%.2lg ", m2[i][j]);
            }
            fprintf(stdout, "\n");
        }
    }


    int r3=r1, c3=c2;
    double m3[r3][c3];

    for (int i = 0; i < r3; ++i) {
        for (int j = 0; j <c3; ++j) {
            m3[i][j]=0;
            for (int n = 0; n < r2; ++n) {   //we can also use c1  since r2=c1
                m3[i][j] += m1[i][n] * m2[n][j];
            }
        }
    }
    //printing matrix 3 to check
    for (int i = 0; i < r3; ++i) {
        for (int j = 0; j < c3; ++j) {
            fprintf(stdout, "%.2f ", m3[i][j]);
        }
        fprintf(stdout, "\n");
    }


    return 0;
}
#endif
