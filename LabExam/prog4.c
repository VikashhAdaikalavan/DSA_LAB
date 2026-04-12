#include <stdio.h>
#include <stdlib.h>

int maxi(int a , int b)
{
    return a>b?a:b;
}


int func(int i , int n , int arr[n],int dp[n+1])
{
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];
    int take = arr[i] + func(i+2,n,arr,dp);
    int nottake = func(i+1,n,arr,dp);
    dp[i] = maxi(take,nottake);
    return dp[i];
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],dp1[n],dp2[n];
    for(int i =0; i< n ; i++)
    {
        dp1[i] = -1;
        dp2[i] = -1;
        scanf("%d",&arr[i]);
    }
    int arr1[n-1], arr2[n-1];
    for(int i =0; i< n-1 ; i++) arr1[i] = arr[i];
    for(int i = 1; i< n ; i++) arr2[i-1] = arr[i];
    int ans = maxi(func(0,n-1,arr1,dp1),func(0,n-1,arr2,dp2));
    printf("%d\n", ans);
    return 0;
}
