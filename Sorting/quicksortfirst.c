//Manvi, 12213106
#include<stdio.h>
#include<stdlib.h>
void swap(int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int Pivot(int *a, int left, int right)
{
    int pivot=a[left];
    int i=right+1;
    for(int j=right; j>=left+1; j--)
    {
        if(a[j]>pivot)
        {
            i--;
            swap(&a[i],&a[j]);

        }
    }
    swap(&a[i-1], &a[left]);
    
    return i-1;
}
void quicksort(int *a, int l, int h)
{
    if(l<h)
    {
        int q=Pivot(a,l,h);
        quicksort(a,l,q-1);
        quicksort(a,q+1,h);
    }
}
int main()
{
    int a[]={5,4,729,-3,15,24};
    printf("%d ", Pivot(a, 0, 5));
    quicksort(a,0,5);
    for(int i=0; i<6; i++)
    {
        printf("%d ", a[i]);
    }
}