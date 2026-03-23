#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int h, r, c;
} Node;

Node heap[MAX];
int size = 0;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Min-heapify
void heapify(int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l].h < heap[smallest].h)
        smallest = l;
    if (r < size && heap[r].h < heap[smallest].h)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

// Insert
void push(Node val) {
    heap[size] = val;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2].h > heap[i].h) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Extract min
Node pop() {
    Node top = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapify(0);
    return top;
}

int trapRainWater(int **height, int R, int C) {
    if (R <= 2 || C <= 2) return 0;

    int visited[100][100] = {0};

    // Push all boundary cells
    for (int i = 0; i < R; i++) {
        push((Node){height[i][0], i, 0});
        push((Node){height[i][C-1], i, C-1});
        visited[i][0] = visited[i][C-1] = 1;
    }

    for (int j = 1; j < C-1; j++) {
        push((Node){height[0][j], 0, j});
        push((Node){height[R-1][j], R-1, j});
        visited[0][j] = visited[R-1][j] = 1;
    }

    int water = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (size > 0) {
        Node curr = pop();

        for (int d = 0; d < 4; d++) {
            int nr = curr.r + dir[d][0];
            int nc = curr.c + dir[d][1];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
                visited[nr][nc] = 1;

                int h = height[nr][nc];

                if (curr.h > h)
                    water += curr.h - h;

                // push with updated boundary height
                push((Node){ curr.h > h ? curr.h : h, nr, nc });
            }
        }
    }

    return water;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    int **grid = (int **)malloc(R * sizeof(int *));
    for (int i = 0; i < R; i++) {
        grid[i] = (int *)malloc(C * sizeof(int));
        for (int j = 0; j < C; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("%d\n", trapRainWater(grid, R, C));
    return 0;
}