#include<iostream>
using namespace std;
int knapsack(int W, int wt[], int p[], int n)
{
    if(W==0||n==0)
    {
        return 0;
    }
    if(wt[n-1]>W)
    {
        return knapsack(W,wt,p,n-1);
    }
    else{
        return max(p[n-1]+knapsack(W-wt[n-1],wt,p,n-1),knapsack(W,wt,p,n-1));
    }
}
int main()
{
    int wt[]={1,2,3,4,5};
    int p[]={1,5,8,9,10};
    cout<<knapsack(5,wt,p,5);
return 0;
}