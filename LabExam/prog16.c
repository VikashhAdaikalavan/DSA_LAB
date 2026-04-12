#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int temp[], int left, int mid, int right, int K)
{
    int count = 0;
    int j = mid + 1;
    for (int i = left; i <= mid; i++)
    {
        while (j <= right && arr[i] > (long long)K * arr[j])
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = left; x <= right; x++)
        arr[x] = temp[x];

    return count;
}

int msort(int arr[], int temp[], int left, int right, int K)
{
    if (left >= right) return 0;

    int mid = (left + right) / 2;

    int n1 = msort(arr, temp, left, mid, K);
    int n2 = msort(arr, temp, mid + 1, right, K);
    int n3 = merge(arr, temp, left, mid, right, K);

    return n1 + n2 + n3;
}

int main()
{
    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i =0 ; i< n ; i++) scanf("%d",&arr[i]);
    int temp[n];
    printf("%d\n",msort(arr,temp,0,n-1,k));
    return 0;
}