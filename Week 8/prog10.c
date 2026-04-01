#include <stdio.h>
#include <limits.h>

#define KMAX 100
#define NMAX 100

typedef struct {
    int val;
    int row;
    int idx;
} Node;

Node heap[KMAX];
int size = 0;

int arr[KMAX][NMAX], sz[KMAX];

// swap
void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

// heapify
void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l].val < heap[smallest].val)
        smallest = l;
    if (r < size && heap[r].val < heap[smallest].val)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// push
void push(Node n) {
    int i = size;
    heap[size++] = n;

    while (i > 0 && heap[(i-1)/2].val > heap[i].val) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// pop
Node pop() {
    Node top = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return top;
}

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &sz[i]);
        for (int j = 0; j < sz[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int max_val = INT_MIN;

    // push first elements
    for (int i = 0; i < k; i++) {
        Node n = {arr[i][0], i, 0};
        push(n);
        if (arr[i][0] > max_val)
            max_val = arr[i][0];
    }

    int best_l = 0, best_r = INT_MAX;

    while (1) {
        Node cur = pop();
        int min_val = cur.val;

        // update range
        if (max_val - min_val < best_r - best_l) {
            best_l = min_val;
            best_r = max_val;
        }

        // move forward in same list
        if (cur.idx + 1 < sz[cur.row]) {
            int next_val = arr[cur.row][cur.idx + 1];
            Node next = {next_val, cur.row, cur.idx + 1};
            push(next);

            if (next_val > max_val)
                max_val = next_val;
        } else {
            break; // one list finished
        }
    }

    printf("%d %d\n", best_l, best_r);
    return 0;
}