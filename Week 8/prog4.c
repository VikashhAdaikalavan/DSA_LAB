#include <stdio.h>

#define MAX 10000

int A[1000], B[1000];

// heap node
typedef struct {
    int sum, i, j;
} Node;

Node heap[MAX];
int size = 0;

// swap
void swap(int i, int j) {
    Node t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

// heapify
void heapify(int i) {
    int s = i, l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l].sum < heap[s].sum) s = l;
    if (r < size && heap[r].sum < heap[s].sum) s = r;

    if (s != i) {
        swap(i, s);
        heapify(s);
    }
}

// push
void push(Node x) {
    int i = size++;
    heap[i] = x;

    while (i && heap[(i-1)/2].sum > heap[i].sum) {
        swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

// pop
Node pop() {
    Node x = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return x;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    for (int i = 0; i < n1; i++) scanf("%d", &A[i]);
    for (int j = 0; j < n2; j++) scanf("%d", &B[j]);

    int k;
    scanf("%d", &k);

    // initialize heap with (i,0)
    for (int i = 0; i < n1; i++) {
        push((Node){A[i] + B[0], i, 0});
    }

    // get k pairs
    while (k-- && size > 0) {
        Node cur = pop();

        int i = cur.i, j = cur.j;

        printf("%d %d\n", A[i], B[j]);

        // push next element in same row
        if (j + 1 < n2) {
            push((Node){A[i] + B[j+1], i, j+1});
        }
    }
}