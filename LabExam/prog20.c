#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // check if possible
    if ((n - 1) % (k - 1) != 0) {
        printf("-1\n");
        return 0;
    }

    // prefix sum
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // dp table
    int dp[n][n];

    // initialize
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // build dp
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // try all splits 
            for (int m = i; m < j; m++) {
                int cost = dp[i][m] + dp[m + 1][j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }

            // add merge cost only if can form 1 pile
            if ((j - i) % (k - 1) == 0) {
                dp[i][j] += prefix[j + 1] - prefix[i];
            }
        }
    }

    printf("%d\n", dp[0][n - 1]);
    return 0;
}