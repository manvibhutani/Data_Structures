#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findLengthOfShortestSubarray(vector<int>& arr) {
        int N=arr.size();
        int left=0,right=N-1;
        while(left<N && arr[left]<arr[left+1]) left++;
    
        if(left==N-1) return 0;
        while(left<right && arr[right]>arr[right-1] && arr[right]>arr[left]) right--;
       cout<<left<<endl;
        if(right==N-1) return N-1;
        return left;
        

    }
int main()
{
    vector<int> a={1,2,3,10,4,2,3,5};
    cout<<findLengthOfShortestSubarray(a);
return 0;
}