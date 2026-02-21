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

    int q[2*n], front = 0, size = 0;
    int tank = 0;

    for (int i = 0; i < 2*n; i++) {
        int idx = i % n;

        q[front + size] = idx;
        size++;
        tank += gas[idx] - dist[idx];

        while (tank < 0) {
            int rem = q[front++];
            size--;
            tank -= (gas[rem] - dist[rem]);
        }

        if (size == n) {
            printf("%d\n", q[front]);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
