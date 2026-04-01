#include <stdio.h>
#include <stdlib.h>

#define MAX 110

typedef struct {
    int x, y, h;
} Cell;

Cell heap[MAX * MAX];
int size = 0;

int visited[MAX][MAX];
int grid[MAX][MAX];
int R, C;

// Directions
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Swap
void swap(Cell *a, Cell *b) {
    Cell t = *a; *a = *b; *b = t;
}

// Heapify
void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l].h < heap[smallest].h)
        smallest = l;
    if (r < size && heap[r].h < heap[smallest].h)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Push
void push(Cell c) {
    int i = size;
    heap[size++] = c;

    while (i > 0 && heap[(i-1)/2].h > heap[i].h) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Pop
Cell pop() {
    Cell top = heap[0];
    heap[0] = heap[--size];
    heapify(0);
    return top;
}

int main() {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf("%d", &grid[i][j]);

    // Step 1: push all boundary cells
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 || j == 0 || i == R-1 || j == C-1) {
                Cell c = {i, j, grid[i][j]};
                push(c);
                visited[i][j] = 1;
            }
        }
    }

    int water = 0;

    while (size > 0) {
        Cell cur = pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visited[nx][ny]) {

                visited[nx][ny] = 1;

                int nh = grid[nx][ny];

                // Water trapped
                if (cur.h > nh)
                    water += cur.h - nh;

                // Push updated height
                Cell next = {nx, ny, (cur.h > nh ? cur.h : nh)};
                push(next);
            }
        }
    }

    printf("%d\n", water);
    return 0;
}