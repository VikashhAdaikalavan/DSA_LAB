#include <stdio.h>
#include <limits.h>

#define MAXK 100
#define MAXN 1000

typedef struct {
    int val;   // value
    int row;   // which list
    int idx;   // index inside list
} Node;

Node heap[MAXK];
int size = 0;

// Swap
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// Min-heapify
void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l].val < heap[smallest].val)
        smallest = l;
    if (r < size && heap[r].val < heap[smallest].val)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Insert
void push(Node x) {
    heap[size] = x;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2].val > heap[i].val) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract min
Node pop() {
    Node root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify(0);
    return root;
}

int main() {
    int K;
    scanf("%d", &K);

    int arr[MAXK][MAXN];
    int sz[MAXK];

    for (int i = 0; i < K; i++) {
        scanf("%d", &sz[i]);
        for (int j = 0; j < sz[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int current_max = INT_MIN;

    // Initialize heap
    for (int i = 0; i < K; i++) {
        push((Node){arr[i][0], i, 0});
        if (arr[i][0] > current_max)
            current_max = arr[i][0];
    }

    int start = 0, end = INT_MAX;

    while (1) {
        Node minNode = pop();

        int current_min = minNode.val;

        // Update range
        if (current_max - current_min < end - start) {
            start = current_min;
            end = current_max;
        }

        int r = minNode.row;
        int c = minNode.idx;

        // If that list is exhausted → stop
        if (c + 1 == sz[r])
            break;

        // Push next element from same list
        int nextVal = arr[r][c + 1];
        push((Node){nextVal, r, c + 1});

        // Update max
        if (nextVal > current_max)
            current_max = nextVal;
    }

    printf("%d %d\n", start, end);
    return 0;
}