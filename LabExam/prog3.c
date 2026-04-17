#include <stdio.h>
#include <stdlib.h>

int func(int i, int j, int n, int m, char source[n+1], char target[m+1],int dp[n+1][m+1])
{
    if(j == m) return 1;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(source[i] == target[j])
    {
        dp[i][j] = func(i+1,j+1,n,m,source,target,dp) + func(i+1,j,n,m,source,target,dp);
        return dp[i][j];
    }
    else 
    {
        dp[i][j] = func(i+1, j, n, m,source,target,dp);
        return dp[i][j];
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char source[n+1], target[m+1];
    scanf("%s",source);
    scanf("%s",target);
    int dp[n+1][m+1];
    for(int i =0 ; i<= n ; i++)
    {
        for(int j = 0 ; j<= m; j++)
        {
            dp[i][j] = -1;
        }
    }
    printf("%d\n",func(0,0,n,m,source,target,dp));

    return 0;
}

