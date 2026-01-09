#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    int temp[n];
    k = k % n;

    int idx = 0;
    for (int i = k; i < n; i++)
        temp[idx++] = arr[i];

    for (int i = 0; i < k; i++)
        temp[idx++] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void rotateRight(int arr[], int n, int k) {
    int temp[n];
    k = k % n;

    int idx = 0;

    for (int i = n - k; i < n; i++)
        temp[idx++] = arr[i];

    for (int i = 0; i < n - k; i++)
        temp[idx++] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int d, k;
    scanf("%d", &d);  
    scanf("%d", &k);

    if (d == 0)
        rotateLeft(arr, n, k);
    else
        rotateRight(arr, n, k);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
