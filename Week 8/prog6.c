#include <stdio.h>

#define MAX 10000

int heap[MAX], size = 0;

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

void insert(int val) {
    int i = size++;
    heap[i] = val;

    while (i && heap[(i-1)/2] > heap[i]) {
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

int extractMin() {
    int x = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return x;
}

int main() {
    int n;
    scanf("%d", &n);

    int visited[100001] = {0};

    insert(2); visited[2] = 1;
    insert(5); visited[5] = 1;
    insert(7); visited[7] = 1;

    int ans = 0;
    int primes[3] = {2, 5, 7};

    for (int i = 0; i < n; i++) {
        int x = extractMin();
        ans = x;

        for (int j = 0; j < 3; j++) {
            long long next = (long long)x * primes[j]; // ← overflow safe
            if (next <= 100000 && !visited[next]) {
                insert((int)next);
                visited[next] = 1;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}