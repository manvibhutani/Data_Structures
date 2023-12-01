#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MCM_rec(int P[], int start, int end)
{
int minsteps,x,y,t;

if(start>=end)
{
    return 0;
}
else{
    minsteps=INT_MAX;
    for(int k=start; k<=end-1; k++)
{
    x=MCM_rec(P,start,k);
    y=MCM_rec(P,k+1,end);
    t=P[start-1]*P[k]*P[end];
    minsteps=min(minsteps,(x+y+t));
}

}
return minsteps;}
int main()
{

   int P[]={2,3,5,1};
    cout<<MCM_rec(P,1,3)<<endl;

    return 0;
}







