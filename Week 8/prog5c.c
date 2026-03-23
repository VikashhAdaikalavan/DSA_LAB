#include <stdio.h>

#define MAX 1000000

int heap[MAX];
int size = 0;

void swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

void heapify(int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

void buildHeap() {
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(i);
}

// extract min and return it
int extractMin() {
    int min = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return min;
}

int main() {
    int n;
    scanf("%d", &n);

    int total = n * n;

    for (int i = 0; i < total; i++) {
        scanf("%d", &heap[size++]);
    }

    buildHeap();

    int k;
    scanf("%d", &k);

    int ans = -1;

    // extract min k times → kth extraction is kth smallest
    for (int i = 0; i < k; i++) {
        ans = extractMin();
    }

    printf("%d\n", ans);

    return 0;
}