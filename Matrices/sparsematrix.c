#include <stdio.h>

#define MAXSIZE 1000 
struct Matrix {
    int row;
    int col;
    int value;
};

void readMatrix(struct Matrix A[]) {
    
    scanf("%d %d %d", &A[0].row, &A[0].col, &A[0].value); 
    for (int i = 1; i <= A[0].value; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value); 
    }
}

void printMatrix(struct Matrix A[]) {
    
    printf("%d %d %d\n", A[0].row, A[0].col, A[0].value);
    for (int i = 1; i <= A[0].value; i++) {
        printf("%d %d %d\n", A[i].row, A[i].col, A[i].value); 
    }
}
int main()
{
    struct Matrix s[1000];
    readMatrix(s);
    printMatrix(s);
    return 0;
}
