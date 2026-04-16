#include <stdio.h>
#include <stdlib.h>

int func(int i, int j, int m , int n,int mat[m][n],int dp[m+1][n+1])
{
    if(i <0 || j <0 || i>=m || j>=n|| mat[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = func(i-1,j,m,n,mat,dp) + func(i, j-1,m,n,mat,dp);
    return dp[i][j];
}


int main()
{
    int m ,n;
    scanf("%d %d",&m,&n);
    int mat[m][n];
    for(int i =0 ; i< m ; i++) 
    {
        for(int j = 0; j< n ; j++) 
            scanf("%d",&mat[i][j]);
    }

    int dp[m+1][n+1];
    for (int  i = 0; i <= m; i++)
    {
        for(int j = 0; j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }
    printf("%d\n",func(m-1,n-1,m,n,mat,dp)%(int)(1e9+7));
    return 0;
}