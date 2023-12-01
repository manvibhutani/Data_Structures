#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int cut_rod(int Profit[], int n)
{
    int max_rev=INT_MIN;
    if(n==0) return 0;
    max_rev=Profit[n-1];
    for(int i=0; i<n-1; i++)
    {
        int rec_call=cut_rod(Profit,n-1-i);
        if(max_rev<Profit[i]+rec_call)
        {
            max_rev=Profit[i]+rec_call;
        }
    }
    return max_rev;
}
int main()
{
    int p[]={1,5,8,9,10};
    cout<<cut_rod(p,5);
return 0;
}