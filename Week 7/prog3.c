#include <stdio.h>
#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int queue[MAX];
    int front = 0, rear = -1;

    int stack[MAX];
    int top = -1;

    int half = n / 2;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    for (int i = 0; i < half; i++) {
        stack[++top] = queue[front++];  
    }

    while (top != -1) {
        queue[++rear] = stack[top--];
    }

    for (int i = 0; i < half; i++) {
        queue[++rear] = queue[front++];
    }

    for (int i = 0; i < half; i++) {
        stack[++top] = queue[front++];
    }

    while (top != -1) {
        queue[++rear] = stack[top--];
        queue[++rear] = queue[front++];
    }

    while (front <= rear) {
        printf("%d ", queue[front++]);
    }

    return 0;
}
