#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int memoized_rod_cut_rec(int P[], int n, int R[])
{
    if(R[n-1]>=0) return R[n-1];
    if(n==0)
    {
        R[0]=0;
        return 0;
    }
    int max_rev=P[n-1];
    for(int i=0; i<n-1; i++)
    {
        int rec_call=memoized_rod_cut_rec(P,n-1-i,R);
        if(max_rev<P[i]+rec_call)
        {
            max_rev=P[i]+rec_call;
        }

    }
    R[n-1]=max_rev;
    return R[n-1];
}
void memoized_rod_cut_start(int P[], int n, int R[])
{
    for(int i=0; i<n; i++)
    {
        R[i]=INT_MIN;
    }
    memoized_rod_cut_rec(P,n,R);

}


int main()
{
    int p[]={1,5,8,9,10};
    int R[]={0,0,0,0,0};
    memoized_rod_cut_start(p,5,R);
    cout<<R[4];
return 0;
}