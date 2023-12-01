#include<stdio.h>

int left(int a)
{
return 2*a+1;
}
int right(int a)
{
    return 2*a+2;
}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxheapify(int *a,int n,  int i)
{
   int l=left(i);
   int r=right(i);
    int largest=i;
    if(l<n && a[l]>a[i])
    {
        largest=l;
    }
    if(r<n && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        maxheapify(a, n,largest);
    }
}
void buildMaxHeap(int *a, int n)
{
    int floor=(n-1)/2;
    for(int i=floor; i>=0; i--)
    {
        maxheapify(a,n,i);
    }
}
int main()
{
    int a[]={4,1,3,2,16,9,10,14,8,7};
    buildMaxHeap(a,10);
    for(int i=0; i<10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}