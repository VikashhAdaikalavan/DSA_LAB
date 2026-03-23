#include <stdio.h>

#define MAX 26

int heap[MAX], size = 0;

// Swap
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Heapify
void heapify(int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] > heap[largest]) largest = l;
    if (r < size && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

// Build heap
void buildHeap() {
    for (int i = size/2 - 1; i >= 0; i--) heapify(i);
}

// Extract max
int extractMax() {
    int mx = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return mx;
}

// Insert
void insert(int val) {
    int i = size++;
    heap[i] = val;

    while (i && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Main logic
int leastInterval(char tasks[], int n, int k) {
    int freq[26] = {0};

    for (int i = 0; i < n; i++) freq[tasks[i] - 'A']++;

    // Fill heap
    for (int i = 0; i < 26; i++)
        if (freq[i]) heap[size++] = freq[i];

    buildHeap();

    int time = 0;

    while (size > 0) {
        int temp[MAX], tsize = 0;

        for (int i = 0; i <= k; i++) {
            if (size) {
                int x = extractMax() - 1;
                if (x > 0) temp[tsize++] = x;
                time++;
            } else {
                if (!tsize) break;
                time++;
            }
        }

        for (int i = 0; i < tsize; i++) insert(temp[i]);
    }

    return time;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char tasks[n];
    for (int i = 0; i < n; i++) scanf(" %c", &tasks[i]);

    printf("%d\n", leastInterval(tasks, n, k));
}