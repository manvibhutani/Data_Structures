#include<stdio.h>
int main()
{
    int n;
    printf("enter no. of elements");
    scanf("%d", &n);
    int a[n];
    int i,j,key;
    printf("enter elements");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=1; i<n; i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && key<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}