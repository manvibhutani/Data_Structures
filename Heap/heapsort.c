//Manvi, 12213106
#include<stdio.h>
#include<stdlib.h>

int parent(int i)
{
    return i-1/2;
}
void swap(int *a, int *b)
{
int k=*a;
*a=*b;
*b=k;
}


void maxheapify(int *arr, int i, int N)
{
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        
        maxheapify(arr, largest, N);
    }
}

void heapsort(int *a, int N)
{
 
   
    for (int i = N / 2 - 1; i >= 0; i--)
 
        maxheapify(a, i, N);
 
    
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&a[0], &a[i]);
 
        maxheapify(a, 0,i);;
    }
}
 


int main()
{
int *a,num;
scanf("%d", &num);

a=malloc(sizeof(int)*num);
for(int i=0; i<num; i++)
{
    scanf("%d", &a[i]);

}

heapsort(a,num);
for(int i=0; i<num; i++)
{
    printf("%d ", a[i]);
}
}