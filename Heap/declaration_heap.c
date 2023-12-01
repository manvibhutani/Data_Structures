#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a, int *b)
{
int k=*a;
*a=*b;
*b=k;
}
int parent(int i)
{
    return i-1/2;
}
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
void maxheapify(int *a, int i)
{int l=left(i);
int r=right(i);
int largest;
if(i<strlen(a) && a[left(i)]>a[i])
{
    largest=l;
}
else
largest=i;
if(i<strlen(a) && a[right(i)]>a[i])
{
    largest=r;
}
if(largest!=i)
{
    swap(&a[i],&a[largest]);
    maxheapify(a,largest);
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
maxheapify(a,1);
for(int i=0; i<num; i++)
{
    printf("%d ", a[i]);
}
}