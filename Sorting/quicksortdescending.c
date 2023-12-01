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

int Partition(int *a, int left, int right)
{
   int i,j;
   i=left-1;
   int pivot=a[right];
   for(j=left; j<right; j++)
   {
    if(a[j]>pivot)
    {
        i++;
        swap(&a[i], &a[j]);
    }

   }
   swap(&a[i+1], &a[right]);
   return i+1;
}
void quicksort(int *a, int l, int h)
{
    if(l<h)
    {
        int q=Partition(a,l,h);
        quicksort(a,l,q-1);
        quicksort(a,q+1,h);
    }
}
int main()
{
    int a[]={453,4352,6532,765,23,76,186};
    
    quicksort(a,0,6);
    for(int i=0; i<7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}