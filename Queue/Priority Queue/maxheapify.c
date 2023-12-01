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
int main()
{
    int a[]={27,17,3,16,13,10,1,5,7,12,4,8,9,0};
    maxheapify(a,14,2);
    for(int i=0; i<14; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}