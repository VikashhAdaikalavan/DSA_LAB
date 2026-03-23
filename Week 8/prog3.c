#include <stdio.h>

#define MAX 100000

int maxHeap[MAX], maxSize = 0; // left
int minHeap[MAX], minSize = 0; // right

// ---------- MAX HEAP ----------
void maxSwap(int i, int j) {
    int t = maxHeap[i]; maxHeap[i] = maxHeap[j]; maxHeap[j] = t;
}

void maxHeapify(int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;

    if (l < maxSize && maxHeap[l] > maxHeap[largest]) largest = l;
    if (r < maxSize && maxHeap[r] > maxHeap[largest]) largest = r;

    if (largest != i) {
        maxSwap(i, largest);
        maxHeapify(largest);
    }
}

void maxInsert(int x) {
    int i = maxSize++;
    maxHeap[i] = x;

    while (i && maxHeap[(i-1)/2] < maxHeap[i]) {
        maxSwap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

int maxTop() { return maxHeap[0]; }

int maxPop() {
    int x = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapify(0);
    return x;
}

// ---------- MIN HEAP ----------
void minSwap(int i, int j) {
    int t = minHeap[i]; minHeap[i] = minHeap[j]; minHeap[j] = t;
}

void minHeapify(int i) {
    int smallest = i, l = 2*i+1, r = 2*i+2;

    if (l < minSize && minHeap[l] < minHeap[smallest]) smallest = l;
    if (r < minSize && minHeap[r] < minHeap[smallest]) smallest = r;

    if (smallest != i) {
        minSwap(i, smallest);
        minHeapify(smallest);
    }
}

void minInsert(int x) {
    int i = minSize++;
    minHeap[i] = x;

    while (i && minHeap[(i-1)/2] > minHeap[i]) {
        minSwap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

int minTop() { return minHeap[0]; }

int minPop() {
    int x = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapify(0);
    return x;
}

// ---------- MAIN ----------
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        // Step 1: insert
        if (maxSize == 0 || x <= maxTop())
            maxInsert(x);
        else
            minInsert(x);

        // Step 2: balance
        if (maxSize > minSize + 1)
            minInsert(maxPop());
        else if (minSize > maxSize)
            maxInsert(minPop());

        // Step 3: print median
        if (maxSize == minSize)
            printf("%.1f ", (maxTop() + minTop()) / 2.0);
        else
            printf("%.1f ", (float)maxTop());
    }

    printf("\n");
}