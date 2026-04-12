//note
#include <stdio.h>
#include <stdlib.h>

long long count = 0;

void merge(long long prefix[], int l, int mid, int r, int lower, int upper) {
    int j = mid + 1, k = mid + 1;
    
    // COUNT VALID RANGES
    for (int i = l; i <= mid; i++) {
        while (j <= r && prefix[j] - prefix[i] < lower) j++;
        while (k <= r && prefix[k] - prefix[i] <= upper) k++;
        count += (k - j);
    }

    // MERGE STEP (sort)
    long long temp[r - l + 1];
    int i = l, t = 0;
    j = mid + 1;

    while (i <= mid && j <= r) {
        if (prefix[i] <= prefix[j])
            temp[t++] = prefix[i++];
        else
            temp[t++] = prefix[j++];
    }

    while (i <= mid) temp[t++] = prefix[i++];
    while (j <= r) temp[t++] = prefix[j++];

    for (int x = 0; x < t; x++)
        prefix[l + x] = temp[x];
}

void mergeSort(long long prefix[], int l, int r, int lower, int upper) {
    if (l >= r) return;

    int mid = (l + r) / 2;

    mergeSort(prefix, l, mid, lower, upper);
    mergeSort(prefix, mid + 1, r, lower, upper);

    merge(prefix, l, mid, r, lower, upper);
}

int main() {
    int n, lower, upper;
    scanf("%d %d %d", &n, &lower, &upper);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long prefix[n + 1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    count = 0;
    mergeSort(prefix, 0, n, lower, upper);

    printf("%lld\n", count);
    return 0;
}