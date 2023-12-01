#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define maxsize 100
int MCM_NR(int P[], int n, int R[][maxsize], int N[][maxsize])
{
    int minsteps,j;
    for(int i=1; i<=n; i++)
    {
        R[i][i]=0;
    }

    for(int length=2; length<=n; length++)
    {
        for(int i=1; i<=n-length+1; i++)
        {
            j=i+length-1;
            minsteps=INT_MAX;
            for(int k=i; k<=j-1; k++)
            {
                if(minsteps>R[i][k]+R[k+1][j]+P[i-1]*P[k]*P[j])
                {
                    minsteps=R[i][k]+R[k+1][j]+P[i-1]*P[k]*P[j];
                    N[i][j]=k;
                }
            }
            R[i][j]=minsteps;
        }
    }
    return R[1][n];
}
void PrintMat(int i, int j, int N[][maxsize])
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else{
        int k=N[i][j];
        cout<<"(";
        PrintMat(i,k,N);
        PrintMat(k+1,j,N);
        cout<<")";
    }
}
int main()
{

     int n = 3; 
    int P[] = {2,3,5,1}; 
    int R[maxsize][maxsize];
    int N[maxsize][maxsize];

    int result = MCM_NR(P, n, R,N);


    cout << result<<endl;
    PrintMat(1,n,N);
return 0;
}