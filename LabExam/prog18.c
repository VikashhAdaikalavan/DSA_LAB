//note
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll merge(ll arr[], ll temp[], int left, int mid, int right, ll lower, ll upper)
{
    ll count = 0;

    int k = mid + 1;
    int j = mid + 1;

    // counting part 
    for (int i = left; i <= mid; i++)
    {
        while (k <= right && arr[k] - arr[i] < lower)
            k++;

        while (j <= right && arr[j] - arr[i] <= upper)
            j++;

        count += (j - k);
    }

    int i = left;
    j = mid + 1;
    int t = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[t++] = arr[i++];
        else
            temp[t++] = arr[j++];
    }

    while (i <= mid) temp[t++] = arr[i++];
    while (j <= right) temp[t++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];

    return count;
}

ll msort(ll arr[], ll temp[], int left, int right, ll lower, ll upper)
{
    if (left >= right) return 0;

    int mid = (left + right) / 2;

    ll n1 = msort(arr, temp, left, mid, lower, upper);
    ll n2 = msort(arr, temp, mid + 1, right, lower, upper);
    ll n3 = merge(arr, temp, left, mid, right, lower, upper);

    return n1 + n2 + n3;
}

int main()
{
    int n;
    ll lower, upper;

    scanf("%d %lld %lld", &n, &lower, &upper);

    ll arr[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    // prefix sum array
    ll prefix[n + 1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    ll temp[n + 1];

    printf("%lld\n", msort(prefix, temp, 0, n, lower, upper));

    return 0;
}