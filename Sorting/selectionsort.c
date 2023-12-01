#include<stdio.h>
#include<limits.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int *a, int n)
{
    int j;
    int smallest;
    for(int i=0; i<n-1;i++)
    {
        smallest=i;
        for(j=i+1; j<n; j++)
        {
            if(a[j]<a[smallest])
            {
                smallest=j;
            }
        }
        swap(&a[smallest],&a[i]);
    }
}
int main()
{int num;
    scanf("%d", &num);
    int a[num];
    for(int i=0; i<num; i++)
    {
        scanf("%d", &a[i]);
    }
    selectionsort(a,num);
    for(int i=0; i<num; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}