#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int dq[n];      
    int front = 0, back = -1;

    int ans[n];         
    int idx = 0;

    for (int i = 0; i < n; i++) {

        while (front <= back && dq[front] <= i - k) {
            front++;
        }

        while (front <= back && arr[dq[back]] <= arr[i]) {
            back--;
        }

        dq[++back] = i;

        if (i >= k - 1) {
            ans[idx++] = arr[dq[front]];
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}