#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 0) return 0;

    int arr[n + 2];
    arr[0] = INT_MIN;
    arr[n + 1] = INT_MIN;

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int l = 1, r = n;

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] > arr[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }

    // l == r is peak
    printf("%d", l - 1); // 0-based index
    return 0;
}
