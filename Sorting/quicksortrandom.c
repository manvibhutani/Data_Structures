#include<stdio.h>
#include<stdlib.h>
void swap(int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

int Partition(int *a, int left, int right, int random)
{
   int i,j;
   i=left-1;
   int pivot=a[random];
   swap(&a[random],&a[right]);
   for(j=left; j<right; j++)
   {
    if(a[j]<pivot)
    {
        i++;
        swap(&a[i], &a[j]);
    }

   }
   swap(&a[i+1], &a[right]);
   return i+1;
}
void quicksort(int *a, int l, int h, int random)
{
   
    if(l<h)
    {
        int q=Partition(a,l,h,random);
        quicksort(a,l,q-1,random);
        quicksort(a,q+1,h,random);
    }
}
int main()
{
    int a[]={453,4352,6532,765,23,76,186};
    
    quicksort(a,0,6,4);
    for(int i=0; i<7; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}