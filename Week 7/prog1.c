#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int inStack[MAX], outStack[MAX];
int topIn = -1, topOut = -1;

void transfer() {
    if (topOut == -1) {
        while (topIn != -1) {
            outStack[++topOut] = inStack[topIn--];
        }
    }
}

void enqueue(int x) {
    inStack[++topIn] = x;
}

int dequeue() {
    transfer();
    if (topOut == -1) return -1;
    return outStack[topOut--];
}

int peek() {
    transfer();
    if (topOut == -1) return -1;
    return outStack[topOut];
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (type == 2) {
            printf("%d\n", dequeue());
        }
        else if (type == 3) {
            printf("%d\n", peek());
        }
    }
    return 0;
}