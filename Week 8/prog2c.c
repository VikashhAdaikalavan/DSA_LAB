#include <stdio.h>

#define MAX 10000

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

// extract min
int extractMin() {
    int x = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return x;
}

// insert
void insert(int val) {
    int i = size++;
    heap[i] = val;

    while (i && heap[(i-1)/2] > heap[i]) {
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &heap[size++]);
    }

    buildHeap();

    int cost = 0;

    while (size > 1) {
        int a = extractMin();
        int b = extractMin();

        int sum = a + b;
        cost += sum;

        insert(sum);
    }

    printf("%d\n", cost);
}