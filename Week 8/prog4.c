#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum, i, j;
} Node;

Node heap[100005];
int heap_size = 0;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void push(Node n) {
    int i = heap_size;
    heap[heap_size++] = n;
    while (i && heap[i].sum < heap[(i-1)/2].sum) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

Node pop() {
    Node top = heap[0];
    heap[0] = heap[--heap_size];
    int i = 0;
    while (1) {
        int smallest = i;
        if (2*i+1 < heap_size && heap[2*i+1].sum < heap[smallest].sum) smallest = 2*i+1;
        if (2*i+2 < heap_size && heap[2*i+2].sum < heap[smallest].sum) smallest = 2*i+2;
        if (smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    int nums1[1005], nums2[1005];
    for (int i = 0; i < n1; i++) scanf("%d", &nums1[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &nums2[i]);

    int k;
    scanf("%d", &k);

    // Push (nums1[i] + nums2[0], i, 0) for all i
    for (int i = 0; i < n1 && i < k; i++) {
        Node n = {nums1[i] + nums2[0], i, 0};
        push(n);
    }

    int count = 0;
    while (heap_size > 0 && count < k) {
        Node cur = pop();
        printf("%d %d\n", nums1[cur.i], nums2[cur.j]);
        count++;

        // Push next pair from same nums1[i] row
        if (cur.j + 1 < n2) {
            Node next = {nums1[cur.i] + nums2[cur.j + 1], cur.i, cur.j + 1};
            push(next);
        }
    }

    return 0;
}