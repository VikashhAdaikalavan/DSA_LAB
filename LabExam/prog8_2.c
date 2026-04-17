#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int lis[n], lds[n];

    // Step 1: LIS from left
    for(int i = 0; i < n; i++) {
        lis[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    // Step 2: LDS from right
    for(int i = n - 1; i >= 0; i--) {
        lds[i] = 1;
        for(int j = n - 1; j > i; j--) {
            if(arr[j] < arr[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    // Step 3: Combine
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, lis[i] + lds[i] - 1);
    }

    printf("%d\n", ans);

    return 0;
}