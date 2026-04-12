//note
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int h;
} Point;

Point* merge(Point* left, int n1, Point* right, int n2, int* size) {
    Point* res = (Point*)malloc(sizeof(Point) * (n1 + n2));

    int i = 0, j = 0, k = 0;
    int h1 = 0, h2 = 0, prev = 0;

    while (i < n1 && j < n2) {
        int x;

        if (left[i].x < right[j].x) {
            x = left[i].x;
            h1 = left[i].h;
            i++;
        } else {
            x = right[j].x;
            h2 = right[j].h;
            j++;
        }

        int curr = (h1 > h2) ? h1 : h2;

        if (k == 0 || curr != prev) {
            res[k].x = x;
            res[k].h = curr;
            prev = curr;
            k++;
        }
    }

    // Remaining points
    while (i < n1) {
        res[k++] = left[i++];
    }

    while (j < n2) {
        res[k++] = right[j++];
    }

    *size = k;
    return res;
}

Point* solve(int buildings[][3], int l, int r, int* size) {
    if (l == r) {
        Point* res = (Point*)malloc(sizeof(Point) * 2);
        res[0].x = buildings[l][0];
        res[0].h = buildings[l][2];
        res[1].x = buildings[l][1];
        res[1].h = 0;
        *size = 2;
        return res;
    }

    int mid = (l + r) / 2;

    int n1, n2;
    Point* left = solve(buildings, l, mid, &n1);
    Point* right = solve(buildings, mid + 1, r, &n2);

    return merge(left, n1, right, n2, size);
}

int main() {
    int n;
    scanf("%d", &n);

    int buildings[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &buildings[i][0], &buildings[i][1], &buildings[i][2]);
    }

    int size;
    Point* skyline = solve(buildings, 0, n - 1, &size);

    for (int i = 0; i < size; i++) {
        printf("%d %d ", skyline[i].x, skyline[i].h);
    }

    return 0;
}