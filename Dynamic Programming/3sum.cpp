#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         if(nums.size()==0)
//         {
//             return {{}};
//         }

//     }
// };
class Solution {
public:
    bool pal(string s)
    {
        for(int i=0; i<s.size(); i++){
            if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string result;
        for(int i=0; i<s.size(); i++)
        {
            if((s[i]>=65 && s[i]<=91)||(s[i]>=97 && s[i]<=122)||(s[i]>=48 && s[i]<=57))
            {
                if(s[i]>=97)
                {
                    result+=s[i]-32;
                }
                else
                {
                    result+=s[i];
                }
            }
        }
        cout<<result;
        return pal(result);
    }
};
int main()
{
    Solution s;
    cout<<s.isPalindrome("Marge, let's \"[went].\" I await {news} telegram.");
return 0;
}