#include<stdio.h>
#include<limits.h>
#include<math.h>
int numOfDigits(int n)
{
    if(n/10==0)
    {
        return 1;
    }
    else{
    return numOfDigits(n%10)+numOfDigits(n/10);
    }
}
int ithDigit(int num, int i)
{
     return (num%(int)(pow(10,i+1)))/pow(10,i);
}
int findMax(int *a, int n)
{
    int max=INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
int countSort(int *a, int n, int exp)
{
    int output[n];
int count[10]={0};
for(int i=0; i<n; i++)
{
    count[(a[i]/exp)%10]++;
    
}
for(int i=1;i<10; i++)
{
    count[i]+=count[i-1];
}
for(int i=n-1;i>=0;i--)
{
    output[count[(a[i]/exp)%10]-1]=a[i];
    count[(a[i]/exp)%10]--;
}
for(int i=0; i<n; i++)
{
    a[i]=output[i];
}
}
int main()
{
    
    int a[]={45,76,7345,568};
    int num=4;
    int max=findMax(a,num);
    for(int i=1; max/i>0;i*=10)
    {
        countSort(a,num,i);
    }
    
    for(int i=0; i<4; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}