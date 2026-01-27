#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int caneat(int x, int n, int arr[n], int h)
{
    int tothrs = 0;
    for (int i = 0; i < n; i++)
    {
        tothrs += ceil((double)(arr[i]) / x);
    }
    return tothrs <= h;
}

int main()
{
    int n;
    int h;
    scanf("%d", &n);
    scanf("%d", &h);
    int arr[n];
    int r = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        r = max(r, arr[i]);
    }
    int l = 1;
    if (r == 0)
    {
        printf("0");
        return 0;
    }

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (caneat(mid, n, arr, h))
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    printf("%d\n", l);
    return 0;
}
