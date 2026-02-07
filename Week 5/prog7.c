#include <stdio.h>

// Swap utility
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto partition
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);
    return i;
}

// Quickselect
int quickSelect(int arr[], int left, int right, int k)
{
    if (left <= right)
    {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(arr, pivotIndex + 1, right, k);
        else
            return quickSelect(arr, left, pivotIndex - 1, k);
    }
    return -1; // should never reach here
}

int main()
{
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d",&k);
    int targetIndex = n - k; 
    int result = quickSelect(arr, 0, n - 1, targetIndex);

    printf("%d\n", result);
    return 0;
}
