#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int parent(int i)
{
    return (i-1)/2;
}
void swap(int *a, int *b)
{
int k=*a;
*a=*b;
*b=k;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void maxheapify(int *a, int i,int num)
{int l=left(i);
int r=right(i);
int largest;
if(i<num && a[l]>a[i])
  largest=l;
else
largest=i;
if(i<num && a[r]>a[i])
{
    largest=r;
}
if(largest!=i)
{
    swap(&a[i],&a[largest]);
    maxheapify(a,largest,num);
}
}
int main()
{
int *a,num;
num=8;

a=malloc(sizeof(int)*num);
for(int i=0; i<num; i++)
{
    scanf("%d", &a[i]);

}
maxheapify(a,1,num);
for(int i=0; i<num; i++)
{
    printf("%d ", a[i]);
}
}