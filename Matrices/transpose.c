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
    int n,i,j,currentb;
    n=a[0].value;
    b[0].row=a[0].col;
    b[0].col=b[0].row;
    b[0].value=n;
    if(n>0)
    {
        currentb=1;
        for(i=0; i<a[0].col; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(a[j].col==i)
                {
                    b[currentb].row=a[j].col; 
                    b[currentb].col=a[j].row;
                    b[currentb].value=a[j].value;    
                    currentb++;        
                    }
            }
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