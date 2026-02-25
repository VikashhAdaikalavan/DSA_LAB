#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int gas[n], dist[n];
    int total = 0;

    for (int i = 0; i < n; i++) scanf("%d", &gas[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);
        total += gas[i] - dist[i];
    }

    if (total < 0) {
        printf("-1\n");
        return 0;
    }

    int q[2*n];
    int front = 0, back = -1;
    int tank = 0;

    for (int i = 0; i < 2*n; i++) {
        int idx = i % n;

        q[++back] = idx;
        tank += gas[idx] - dist[idx];

        while (tank < 0 && front <= back) {
            int rem = q[front++];
            tank -= (gas[rem] - dist[rem]);
        }

        if (back - front + 1 == n) {
            printf("%d\n", q[front]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}