// Online C compiler to run C program online
#include <stdio.h>
void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
void maxheap(int A[], int i, int n)
{
    int l=2*i+1;
    int r=2*i+2;
    
    int largest=i;
    if(l<n && A[l]>A[largest])
    
        largest=l;
    
    if(r<n &&A[r]>A[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&A[i],&A[largest]);
        maxheap(A,largest,n);
    }
}
void buildheap(int A[], int n)
{
    int i;
    for(i=n/2; i>=0;i--)
    {
        maxheap(A,i,n);
    }
}
void heapsort(int A[], int n)
{
    int heapsize=n;
    buildheap(A,heapsize);
    for(int i=n-1; i>=1;i--)
    {
        swap(&A[0],&A[i]);
        heapsize--;
        maxheap(A,0,heapsize);
    }
}
int main() {
    int num;
    printf("enter no. of elements in heap");
    scanf("%d", &num);
    int a[num];
    for(int i=0; i<num; i++)
        scanf("%d", &a[i]);
    
    heapsort(a,num);
    for(int i=0; i<num;i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}