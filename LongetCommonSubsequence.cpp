#include<bits/stdc++.h>
using namespace std;

long long LCS(string X,string Y,long long m,long long n)
{
    if(m == 0 or n == 0)
       return 0;

    long long dp[m + 1][n + 1];

    for(long long i = 0; i < m + 1 ; i++)
        dp[i][0] = 0;

    for(long long j = 0; j < n + 1 ; j++)
        dp[0][j] = 0;

    long long i,j;

    for(i = 1; i < m + 1 ; i++)
    {
        for(j = 1; j < n + 1 ; j++)
        {
            if(X[i] == Y[j])
               dp[i][j] = 1 + dp[i - 1][j - 1];
            else
               dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    string X,Y;

    cout<<"Enter String 1 : ";
    cin>>X;
    cout<<"Enter String 2 : ";
    cin>>Y;
    cout<<endl;

    cout<<"Length Of Longest Common Subsequence Of Entered Strings : "<<LCS(X,Y,X.size(),Y.size())<<endl;

    return 0;
}
