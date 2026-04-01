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

    for (int i = 0; i < n1; i++) {
        scanf("%d", &nums1[i]);
    }

    for (int i = 0; i < n2; i++) {
        scanf("%d", &nums2[i]);
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            Node n;
            n.sum = nums1[i] + nums2[j];
            n.i = i;
            n.j = j;
            push(n);
        }
    }

    int count = 0;
    while (heap_size > 0 && count < k) {
        Node cur = pop();
        printf("%d %d\n", nums1[cur.i], nums2[cur.j]);
        count++;
    }

    return 0;
}