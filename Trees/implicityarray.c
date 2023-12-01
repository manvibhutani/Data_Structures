#include<stdio.h>
#define maxsize 100

int main()
{
    int num,i;
    printf("Enter no. of nodes");
    scanf("%d", &num);

    int a[maxsize];
    printf("Enter elements");
    for(i=0; i<num; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0; i<num; i++)
    {
        if(2*i+2<num)
        {
            printf("%d %d %d ", a[i],a[2*i+1],a[2*i+2]);
        }
        
    }

    
    return 0;
}