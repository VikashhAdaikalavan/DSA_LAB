#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return (top == -1);
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    int span[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    push(0);
    span[0] = 1;

    for(int i = 1; i < n; i++) {

        while(!isEmpty() && arr[i] >= arr[peek()]) {
            pop();
        }

        if(isEmpty())
            span[i] = i + 1;
        else
            span[i] = i - peek();

        push(i);
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }

    return 0;
}
