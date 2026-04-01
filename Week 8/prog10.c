#include <stdio.h>
#include <limits.h>

#define MAX_K 100
#define MAX_N 1000

typedef struct {
    int val;
    int row;
    int idx;
} Node;

Node heap[MAX_K];
int size = 0;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapify(int i) {
    int smallest = i;
    if (2*i+1 < size && heap[2*i+1].val < heap[smallest].val)
        smallest = 2*i+1;
    if (2*i+2 < size && heap[2*i+2].val < heap[smallest].val)
        smallest = 2*i+2;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

Node extractMin() {
    Node root = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return root;
}

void insert(Node x) {
    heap[size++] = x;
    int i = size - 1;
    while (i > 0 && heap[i].val < heap[(i-1)/2].val) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main() {
    int k;
    scanf("%d", &k);

    int arr[MAX_K][MAX_N], n[MAX_K];

    for (int i = 0; i < k; i++) {
        scanf("%d", &n[i]);
        for (int j = 0; j < n[i]; j++)
            scanf("%d", &arr[i][j]);
    }

    int current_max = INT_MIN;

    // Initialize heap
    for (int i = 0; i < k; i++) {
        Node x = {arr[i][0], i, 0};
        insert(x);
        if (arr[i][0] > current_max)
            current_max = arr[i][0];
    }

    int range_start = 0, range_end = INT_MAX;

    while (1) {
        Node minNode = extractMin();
        int current_min = minNode.val;

        // Update range
        if (current_max - current_min < range_end - range_start) {
            range_start = current_min;
            range_end = current_max;
        }

        int row = minNode.row;
        int idx = minNode.idx + 1;

        if (idx >= n[row]) break;

        int nextVal = arr[row][idx];

        insert((Node){nextVal, row, idx});

        if (nextVal > current_max)
            current_max = nextVal;
    }

    printf("%d %d\n", range_start, range_end);

    return 0;
}