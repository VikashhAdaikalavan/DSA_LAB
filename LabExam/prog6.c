#include <stdio.h>
#include <stdlib.h>

int maxi(int a, int b)
{
    return a>b? a:b;
}

int func(int i, int j, int n, char s[n+1], int dp[n+1][n+1])
{
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j]; 
    if(i == j) 
    {
        dp[i][j] = 1;
        return dp[i][j];
    }
    if(s[i] == s[j])
    {
        dp[i][j] = 2 + func(i+1,j-1,n,s,dp);
        return dp[i][j];
    }
    else
    {
        int n1 = func(i+1, j, n, s,dp);
        int n2 = func(i,j-1,n,s,dp);
        int n3 = func(i+1, j-1,n,s,dp);
        dp[i][j] =  maxi(n3,maxi(n1,n2));
        return dp[i][j];
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    int dp[n+1][n+1];
    for(int i =0; i <= n ; i++)
    {
        for(int j =0; j <= n ; j++)
        {
            dp[i][j] = -1;
        }
    }
    scanf("%s",s);
    printf("%d\n",func(0,n-1,n,s,dp));
    return 0;
}
