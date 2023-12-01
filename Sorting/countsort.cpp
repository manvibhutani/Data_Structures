#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> countSort(vector<int> &inputArray)
{
    int N=inputArray.size();
    int Max=0;
    for(int i=0; i<N; i++)
    {
        Max=max(Max,inputArray[i]);
    }
    vector<int> counterArray(Max+1,0);
    for(int i=0; i<N; i++)
    {
        counterArray[inputArray[i]]++;
    }
    vector<int> outputArray(N);
      int k=0;
    for(int i=0; i<=Max; i++)
    {
      int count=counterArray[i];
       
            while(count>0)
            {
                outputArray[k]=i;
                k++;
                count--;
            }
     
    }
    return outputArray;
}
int main()
{
    vector<int> a={3,4,6,5,7,8,7};
    vector<int> b=countSort(a);
    for(int i=0; i<a.size(); i++)
    {
        cout<<b[i]<<" ";
    }
return 0;
}