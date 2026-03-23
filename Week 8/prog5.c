#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// min heapify
void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// build heap
void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    scanf("%d", &n);

    int size = n*n;
    int arr[size];

    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    buildHeap(arr, size);

    int k;
    scanf("%d", &k);

    // remove smallest (size-k) times
    for (int i = 0; i < size - k; i++) {
        arr[0] = arr[size - 1];
        size--;
        heapify(arr, size, 0);
    }

    printf("%d\n", arr[0]); // kth largest
}