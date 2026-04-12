#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mini(int a , int b)
{
    return a<b? a:b;
}

int prefix[105];
int sum(int i, int j)
{
    return prefix[j+1] - prefix[i];
}

int func(int i , int j, int K, int n , int arr[], int dp[n+2][n+2])
{
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k += (K - 1))
    {
        int left = func(i, k, K, n, arr, dp);
        int right = func(k+1, j, K, n, arr, dp);

        if(left != INT_MAX && right != INT_MAX)
            ans = mini(ans, left + right);
    }

    // conditional cost
    if((j - i) % (K - 1) == 0)
    {
        ans += sum(i, j);
    }

    return dp[i][j] = ans;
}

int main()
{
    int n,K;
    scanf("%d %d",&n,&K);

    int arr[n];
    for(int i = 0; i< n ; i++) scanf("%d",&arr[i]);

    // feasibility check
    if((n-1) % (K-1) != 0)
    {
        printf("-1\n");
        return 0;
    }

    // prefix sum
    prefix[0] = 0;
    for(int i = 0; i < n; i++)
    {
        prefix[i+1] = prefix[i] + arr[i];
    }

    int dp[n+2][n+2];
    for(int i =0 ; i< n+2; i++)
    {
        for(int j = 0; j< n+2; j++)
        {
            dp[i][j] = -1;
        } 
    }
    
    printf("%d\n",func(0,n-1,K,n,arr,dp));
    return 0;
}