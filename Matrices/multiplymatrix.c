#include <stdio.h>

#define MAXSIZE 1000 

struct Triple {
    int row;
    int col;
    int value;
};

void readMatrix(struct Triple A[], int *m, int *n, int *t) {
    
    scanf("%d %d %d", m, n, t); 
    for (int i = 0; i < *t; i++) {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value); 
    }
}

void printMatrix(struct Triple A[], int m, int n, int t) {
    
    printf("%d %d %d\n", m, n, t); 
    for (int i = 0; i < t; i++) {
        printf("%d %d %d\n", A[i].row, A[i].col, A[i].value); 
    }
}

void multiplyMatrix(struct Triple A[], int tA, struct Triple B[], int tB, struct Triple C[], int *tC) {
    
    int k = 0;
    *tC = 0;
    for (int i = 0; i < tA; i++) {
        for (int j = 0; j < tB; j++) {
            if (A[i].col == B[j].row) {
                
                int val = A[i].value * B[j].value;
                int row = A[i].row;
                int col = B[j].col;
                int l;
                
                for (l = k; l < *tC && row >= C[l].row; l++) {
                    if (row == C[l].row && col == C[l].col) {
                        
                        C[l].value += val;
                        break;
                    }
                }
                if (l == k || row > C[l-1].row || (row == C[l-1].row && col > C[l-1].col)) {
                    
                    for (int m = *tC; m > l; m--) {
                        C[m] = C[m-1];
                    }
                    C[l].row = row;
                    C[l].col = col;
                    C[l].value = val;
                    (*tC)++;
                    k = l; 
                }
            }
        }
    }
}

int main() {
    struct Triple A[MAXSIZE], B[MAXSIZE], C[MAXSIZE];
    int mA, nA, tA, mB, nB, tB, tC;

    readMatrix(A, &mA, &nA, &tA);
    readMatrix(B, &mB, &nB, &tB);
    multiplyMatrix(A, tA, B, tB, C, &tC);
    printMatrix(C, mA, nB, tC);

    return 0;
}
