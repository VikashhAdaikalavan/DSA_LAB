#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mini(int a , int b)
{
    return a<b? a:b;
}

int func(int i , int j, int m, int n , int arr[m], int dp[n+2][n+2])
{
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k =0; k< m ; k++)
    {
        int pos = arr[k];
        if(pos>i && pos<j)
        {
            ans = mini(ans,j-i + func(i,pos,m,n,arr,dp) + func(pos,j,m,n,arr,dp));
        }
    }
    dp[i][j] = ans == INT_MAX? 0:ans;
    return dp[i][j];
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int cuts[m];
    for(int i = 0; i< m ; i++) scanf("%d",&cuts[i]);
    int dp[n+2][n+2];
    for(int i =0 ; i< n+2; i++)
    {
        for(int j = 0; j< n+2; j++)
        {
            dp[i][j] = -1;
        } 
    }
    
    printf("%d\n",func(0,n,m,n,cuts,dp));
    return 0;
}