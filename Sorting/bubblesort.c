#include<stdio.h>
#include<limits.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int *a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>=i+1; j--)
        {
            if(a[j]<a[j-1])
            {
                swap(&a[j],&a[j-1]);
            }
        }
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
    bubblesort(a,num);
    for(int i=0; i<num; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}