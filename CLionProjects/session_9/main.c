#include <stdio.h>
//EXERCISE 1 - Complexity
/*Write a program able to:
 * read an integer value n
 * print-out the number sum of ordered couples (i,j) such that the following confitions hold
 * - i and j are integer values
 * - 1 <=i<=j<=n
 */
/*
int count_ver1 (int n) {
    int i, j, sum;
    sum = 0;
    for (i=1; i<=n; i++) {
        for (j=i; j<=n; j++) {
            sum++;
        }
    }
    return sum;
}

int count_ver2 (int n) {
    int i, sum;
    sum = 0;
    for (i=1; i<=n; i++) {
        sum = sum + (n–i+1);
    }
    return sum;
}

int count_ver3 (int n) {
    return n * (n+1) / 2;
}
 */
//EXERCISE 2 - Search
//Search algorithms
//searching for key k in an unordered array
//region random
/*
int LinearSearch1 (int v[], int l, int r, int k) {
    int i = l;
    int found = 0;
    while (i<=r && found==0) {
        if (k == v[i]) {
            found = 1;
        } else {
            i++;
        }
    }
    if (found==0)
        return -1;
    else
        return i;
}
//searching fot key k in an array ordered in ascending order
int LinearSearch2 (int v[], int l, int r, int k) {
    int i = l;
    while (i<=r && k>v[i]) {
        i++;
    }
    if (k == v[i]) {
        return (i);
    } else {
        return (-1);
    }
}
//Binary Search
int BinarySearch (int v[], int l, int r, int k) {
    int c;
    while (l<=r){
        c = (int) ((l+r) / 2);
        if (k == v[c]) {
            return(c);
        }
        if (k < v[c]) {
            r = c-1;
        } else {
            l = c+1;
        }
    }
    return(-1);
}
*/
//endregion
//EXERCISE 3 - Connectivity
