#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxsize 100
int LCS(string s, int i, string t, int j)
{
    if(i==0 || j==0)
    {
        return 0;
    }
    else if(s[i-1]==t[j-1])
    {
        return 1+LCS(s,i-1,t,j-1);
    }
    else{
        return max(LCS(s,i,t,j-1),LCS(s,i-1,t,j));
    }
}
int LCS_memoized(string s, int m, string t, int n, int L[][100], char C[][100])
{
for(int i=0; i<=m; i++)
{
    L[i][0]=0;
}
for(int j=0; j<=n; j++)
{
    L[0][j] = 0;
}
int i,j;
for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                L[i][j] = 1 + L[i - 1][j - 1];
                C[i][j] = 'D';  
            } else if (L[i - 1][j] >= L[i][j - 1]) {
                L[i][j] = L[i - 1][j];
                C[i][j] = 'U';  
            } else {
                L[i][j] = L[i][j - 1];
                C[i][j] = 'L';  
            }
        }
    }

return L[m][n];
}
void printLCS(string X, int m, int n, char C[][maxsize]) {
    if (m == 0 || n == 0) {
        return;
    }
    if (C[m][n] == 'D') {
        printLCS(X, m - 1, n - 1, C);
        cout << X[m - 1];
    } else if (C[m][n] == 'U') {
        printLCS(X, m - 1, n, C);
    } else {
        printLCS(X, m, n - 1, C);
    }
}

int main()
{
    
    string a="abfgtc";
    string b="cadbgtac";
    int m=a.size();
    int n=b.size();
    int L[100][100];
    char C[100][100];
    cout<<LCS(a,m,b,n)<<endl;
    cout<<LCS_memoized(a,m,b,n,L,C)<<endl;
    printLCS(a,m,n,C);

return 0;
}