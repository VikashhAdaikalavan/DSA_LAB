#include <stdio.h>
#include <stdlib.h>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;    // left subarray index
    int j = mid + 1; // right subarray index
    int k = left;    // temp array index
    long long invCount = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // key inversion count
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right)
{
    long long invCount = 0;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }

    return invCount;
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    int temp[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSortAndCount(arr, temp, 0, N - 1);
    printf("%lld\n", result);

    return 0;
}
