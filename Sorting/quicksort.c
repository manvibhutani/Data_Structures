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
void Quicksort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
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
    