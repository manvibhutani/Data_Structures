#include<stdio.h>
#include<limits.h>
void merge(int A[], int p, int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],M[n2+1];
    int i,j,k;
    L[n1]=INT_MAX;
    M[n2]=INT_MAX;
    for(i=0; i<n1; i++)
    {
        L[i]=A[p+i];
    }
    for(i=0; i<n2; i++)
    {
        M[i]=A[q+1+i];
    }
    i=0,j=0;
    for(k=p; k<=r; k++)
    {
        if(L[i]<=M[j])
        {
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=M[j];
            j++;

        }
    }
}
void mergesort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);
    }
}
int main()
{int num;
    scanf("%d", &num);
    int a[num];
    for(int i=0; i<num; i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a,0,num-1);
    for(int i=0; i<num; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}