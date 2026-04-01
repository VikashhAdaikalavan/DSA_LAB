#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int d, r;
} Job;

// Min-heap
int heap[MAX];
int size = 0;

// Swap
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify (min-heap)
void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest])
        smallest = l;
    if (r < size && heap[r] < heap[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Insert
void push(int val) {
    heap[size] = val;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Remove smallest
void pop() {
    heap[0] = heap[size-1];
    size--;
    heapify(0);
}


int main() {
    int N;
    scanf("%d", &N);

    Job jobs[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].d, &jobs[i].r);
    }

    // Sort by deadline
   for(int i = 0; i< N; i++)
   {
        for(int j = 0; j< N-1 ; j++)
        {
            if(jobs[j].d > jobs[j+1].d)
            {
                Job t = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = t;
            }
        }
   }

    for (int i = 0; i < N; i++) {
        push(jobs[i].r);

        // If more jobs than allowed → remove smallest reward
        if (size > jobs[i].d) {
            pop();
        }
    }

    // Sum remaining rewards
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += heap[i];
    }

    printf("%d\n", total);
    return 0;
}