#include <stdio.h>
#include <stdlib.h>

int maxi(int a , int b)
{
    return a>b?a:b;
}

int func(int i, int trans,int b, int k, int n , int arr[n], int dp[n+1][n+1][2]) //b == 1 implies we can uy
{
    if(i>=n) return 0;
    if(dp[i][trans][b] != -1) return dp[i][trans][b];
    if(b == 1)
    {
        int buy = INT_MIN;
        buy = -arr[i] + func(i+1,trans,0,k,n,arr,dp);
        int notbuy = func(i+1,trans,1,k,n,arr,dp);
        dp[i][trans][b] = maxi(buy,notbuy);
    }
    else
    {
        int sell = INT_MIN;
        if(trans<k) sell = arr[i] + func(i+1,trans+1,1,k,n,arr,dp);
        int notsell = func(i+1,trans,0,k,n,arr,dp);
        dp[i][trans][b] = maxi(sell,notsell);
    }
    return dp[i][trans][b];
}

int main()
{
    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n];
    int sum = 0;
    for(int i =0; i< n ; i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    int dp[n+1][sum+1][2];
    for(int i =0; i< n+1; i++)
    {
        for(int j = 0; j< sum +1; j++)
        {
            for(int l =0; l< 2 ; l++) dp[i][j][l] = -1;
        }
    }

    printf("%d\n",func(0,0,1,k,n,arr,dp));

    return 0;
}