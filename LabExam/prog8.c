//note

#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

// LIS ending at k (0 - k)
int lis(int i, int prev, int k, int arr[], int dp[100][101])
{
    if(i > k) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = lis(i+1, prev, k, arr, dp);

    int take = 0;
    if(prev == -1 || arr[i] > arr[prev])
    {
        take = 1 + lis(i+1, i, k, arr, dp);
    }

    return dp[i][prev+1] = max(take, notTake);
}

// LDS starting at k (k - n-1)
int lds(int i, int prev, int n, int arr[], int dp[100][101])
{
    if(i >= n) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = lds(i+1, prev, n, arr, dp);

    int take = 0;
    if(prev == -1 || arr[i] < arr[prev])
    {
        take = 1 + lds(i+1, i, n, arr, dp);
    }

    return dp[i][prev+1] = max(take, notTake);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int ans = 0;

    for(int k = 0; k < n; k++)
    {
        int dp1[100][101], dp2[100][101];

        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));

        int inc = lis(0, -1, k, arr, dp1);
        int dec = lds(k, -1, n, arr, dp2);

        ans = max(ans, inc + dec - 1);
    }

    printf("%d\n", ans);
}