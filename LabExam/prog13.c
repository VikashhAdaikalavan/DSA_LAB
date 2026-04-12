#include <stdio.h>
#include <stdlib.h>

int maxi(int a , int b)
{
    return a>b?a:b;
}
int mini(int a, int b)
{
    return a < b ? a : b;
}

int func(int i, int j, int alpha, int n, int arr[n],int dp[n+2][n+2][2]) //alpha = 1 means apha turn
{
    if(i>j) return 0;
    if(dp[i][j][alpha] != -1) return dp[i][j][alpha];
    if(alpha == 1)
    {
        int n1 = arr[i] + func(i+1,j,0,n,arr,dp);
        int n2 =  arr[j] + func(i,j-1,0,n,arr,dp);
        dp[i][j][alpha] = maxi(n1,n2); 
        return dp[i][j][alpha];       
    }
    else
    {   
        int n1 = func(i+1,j,1,n,arr,dp);
        int n2 = func(i,j-1,1,n,arr,dp);
        dp[i][j][alpha] = mini(n1,n2);
        return dp[i][j][alpha];
    }
}

int main ()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0; i< n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    int dp[n+2][n+2][2];
    for(int i =0 ; i< n+2; i++)
    {
        for(int j = 0; j< n+2; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        } 
    }
    printf("%d\n",func(0,n-1,1,n,arr,dp));
    return 0;
}