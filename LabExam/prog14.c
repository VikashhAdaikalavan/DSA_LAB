//note
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct {
    int x, y;
    int set; // 0 = P1, 1 = P2
} Point;

int min(int a, int b) { return a < b ? a : b; }

int dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// brute force
int brute(Point arr[], int l, int r) {
    int d = INT_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = l; j <= r; j++) {
            if (arr[i].set != arr[j].set && i != j) {
                d = min(d, dist(arr[i], arr[j]));
            }
        }
    }
    return d;
}

int closest(Point arr[], int l, int r) {
    if (r - l <= 3)
        return brute(arr, l, r);

    int mid = (l + r) / 2;
    int midx = arr[mid].x;

    int dl = closest(arr, l, mid);
    int dr = closest(arr, mid + 1, r);

    int d = min(dl, dr);

    // build strip
    Point strip[r - l + 1];
    int k = 0;

    for (int i = l; i <= r; i++) {
        if (abs(arr[i].x - midx) < d) {
            strip[k++] = arr[i];
        }
    }

    // check neighbors
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k ; j++) {
            if (strip[i].set != strip[j].set && i != j) {
                d = min(d, dist(strip[i], strip[j]));
            }
        }
    }

    return d;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Point arr[N + M];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
        arr[i].set = 0;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &arr[N + i].x, &arr[N + i].y);
        arr[N + i].set = 1;
    }

    for(int j = 0; j< N+M ; j++)
    {
        for(int i = 0; i<N+M-1 ; i++)
        {
            if(arr[i].x<arr[i+1].x)
            {
                Point temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    int ans = closest(arr, 0, N + M - 1);

    printf("%d\n", ans);
    return 0;
}