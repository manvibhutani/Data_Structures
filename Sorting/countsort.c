#include<stdio.h>
#include<limits.h>
int main()
{
    int max=INT_MIN;
    int a[]={3,7,9,1,4};
    for(int i=0; i<5; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int count[max+1];
    for(int i=0; i<max+1; i++)
    {
        count[i]=0;
    }
    for(int i=0; i<5; i++)
    {
        count[a[i]]++;
    }
    int k=0;
    int j=0;
    int i=0;
    while(j<max+1)
    {
        if(count[j]>0)
        {
            a[i++]=j;
            count[j]--;
        }
        else
        {j++;}
    }
    for(int i=0; i<5; i++)
    {
        printf("%d ", a[i]);
    }
}