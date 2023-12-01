#include<stdio.h>
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
void transpose(struct Matrix a[], struct Matrix b[])
{
    int rowterms[a[0].col];
    int startingposition[a[0].col+1];
    int i,j,numsCol=a[0].col,numTerms=a[0].value;
    b[0].row=numsCol,b[0].col=a[0].row;
    b[0].value=numTerms;
    if(numTerms>0)
    {
        for(i=0; i<numsCol; i++)
        rowterms[i]=0;
        for(i=1; i<=numTerms; i++)
        {
            rowterms[a[i].col]++;
        }
        startingposition[0]=1;
        for(i=1; i<numsCol; i++)
        {
            startingposition[i]=startingposition[i-1]+rowterms[i-1];
        }
        for(i=1; i<=numTerms; i++)
        {
            j=startingposition[a[i].col]++;
            b[j].row=a[i].col;
            b[j].col=a[i].row;
            b[j].value=a[i].value;
        }
    }
}
int main()
{
    struct Matrix a[1000];
    struct Matrix b[1000];
    readMatrix(a);
    
    transpose(a,b);
    printMatrix(b);

    return 0;
}