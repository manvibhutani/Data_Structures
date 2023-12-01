#include<stdio.h>
#include<limits.h>
int left(int a)
{
return 2*a+1;
}
int right(int a)
{
    return 2*a+2;
}
int parent(int i)
{
    return (i-1)/2;
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
void minheapify(int *a,int n,  int i)
{
   int l=left(i);
   int r=right(i);
    int smallest=i;
    if(l<n && a[l]<a[i])
    {
        smallest=l;
    }
    if(r<n && a[r]<a[smallest])
    {
        smallest=r;
    }
    if(smallest!=i)
    {
        swap(&a[i],&a[smallest]);
        minheapify(a, n,smallest);
    }
}
void buildMinHeap(int *a, int n)
{
    int floor=(n-1)/2;
    for(int i=floor; i>=0; i--)
    {
        minheapify(a,n,i);
    }
}
void heapSort(int *a, int n)
{
    int heapSize=n;
    buildMinHeap(a,n);
    for(int i=n-1;i>=1;i--)
    {
        swap(&a[i],&a[0]);
        heapSize--;
        minheapify(a,heapSize,0);
    }
}
int maximum(int *a)
{
    return a[0];
}
int extractMax(int *a, int n)
{
    
    int heapSize=n;
    int max=a[0];
    a[0]=a[heapSize-1];
    heapSize--;
    maxheapify(a,heapSize,0);
    return max;
}
void increaseKey(int *a,int i, int key)
{
    if(key<a[i])
    {
        printf("New key is smaller\n");
        return;
    }
    a[i]=key;
    while(i>0 && a[parent(i)]<a[i])
    {
        swap(&a[i],&a[parent(i)]);
        i=parent(i);
    }
}
void insert(int *a, int *n,  int key) {
    (*n)++;
   
    a[*n - 1] = INT_MIN;
    increaseKey(a, *n, key);
}


int main()
{
   
    int a[]={1,2,3,4,5,6,7,8,9};
    heapSort(a,9);
    for(int i=0; i<9; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    increaseKey(a,2,23);
     for(int i=0; i<9; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    heapSort(a,9);
    for(int i=0; i<9; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int hs=9;
    insert(a,&hs,0);
     for(int i=0; i<hs; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}