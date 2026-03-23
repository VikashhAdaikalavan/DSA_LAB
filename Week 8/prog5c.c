#include <stdio.h>

#define MAX 1000000

int heap[MAX];
int size = 0;

// swap
void swap(int i, int j) {
    int t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

// heapify (min heap)
void heapify(int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

// build heap
void buildHeap() {
    for (int i = size/2 - 1; i >= 0; i--)
        heapify(i);
}

int main() {
    int n;
    scanf("%d", &n);

    int total = n * n;

    // read directly into global heap
    for (int i = 0; i < total; i++) {
        scanf("%d", &heap[size++]);
    }

    buildHeap();

    int k;
    scanf("%d", &k);

    // remove smallest (total - k) times
    for (int i = 0; i < total - k; i++) {
        heap[0] = heap[--size];
        heapify(0);
    }

    printf("%d\n", heap[0]); // kth largest
}