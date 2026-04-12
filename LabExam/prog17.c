#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int l, int mid, int r)
{
    int sum = 0;
    int left_sum = INT_MIN;

    // left suffix
    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;

    // right prefix
    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubarray(int arr[], int l, int r)
{
    if (l == r)
        return arr[l]; // base case

    int mid = (l + r) / 2;

    int left = maxSubarray(arr, l, mid);
    int right = maxSubarray(arr, mid + 1, r);
    int cross = maxCrossingSum(arr, l, mid, r);

    return max3(left, right, cross);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxSubarray(arr, 0, n - 1));
    return 0;
}