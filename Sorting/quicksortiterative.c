#include<stdio.h>
void swap(int *a,int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int Partition(int A[],int p,int r)
{
    int pivot=A[r];
    int i=p-1;
    for(int j=p; j<r; j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void Quicksort(int A[], int p, int r) {
    int stack[r - p + 1];
    int top = -1;

    stack[++top] = p;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        p = stack[top--];

        while (p < r) {
            int q = Partition(A, p, r);

            if (q - p < r - q) {
                stack[++top] = q + 1;
                stack[++top] = r;
                r = q - 1;
            } else {
                stack[++top] = p;
                stack[++top] = q - 1;
                p = q + 1;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int a[num];
    for(int i=0; i<num; i++)
    {
        scanf("%d", &a[i]);
    }
    Quicksort(a,0,num-1);
    for(int i=0; i<num; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
    