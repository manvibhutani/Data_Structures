#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 80;

int MCM_memo_util(int P[], int start, int end, int R[][MAX_SIZE]);

int MCM_memo(int P[], int n, int R[][MAX_SIZE])
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            R[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        R[i][i] = 0;
    }

    return MCM_memo_util(P, 1, n, R);
}
int MCM_memo_util(int P[], int start, int end, int R[][MAX_SIZE])
{
    int minsteps, x, y, t;
    if (start >= end)
    {
        return 0;
    }
    if (R[start][end] < INT_MAX)
        return R[start][end];
    else
    {
        minsteps = INT_MAX;
        for (int k = start; k <= end - 1; k++)
        {
            x = MCM_memo_util(P, start, k, R);
            y = MCM_memo_util(P, k + 1, end, R);
            t = P[start - 1] * P[k] * P[end];
            minsteps = min(minsteps, (x + y + t));
        }
    }
    R[start][end] = minsteps;
    return minsteps;
}

int main()
{
  
    int n = 3; 
    int P[] = {2,3,5,1}; 
    int R[MAX_SIZE][MAX_SIZE];

    int result = MCM_memo(P, n, R);

    cout << result<<endl;

    return 0;
}
