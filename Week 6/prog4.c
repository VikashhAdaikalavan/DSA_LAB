#include <stdio.h>
#include <limits.h>
#define MAX 1000

int stack[MAX];
int top = -1;

int isEmpty() {
    return (top == -1);
}

void push(int value) {
    stack[++top] = value;
}

int pop() {
    if(top == -1)
    {
        printf("Stack Empty\n");
        return INT_MIN;
    }
    return stack[top--];
}

void peek() {
    if(top == -1)
    {
        printf("Stack Empty\n");
    }
    printf("Top value: %d\n",stack[top]);
}
int getMin()
{
    if(isEmpty())
    {
        printf("Stack empty\n");
        return INT_MIN;
    }
    int min = INT_MAX;
    for(int i = 0 ; i<= top ; i++)
    {
        min = stack[i] > min ? min : stack[i];
    }
    return min;
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i< n ; i++)
    {
        int opt;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            int k;
            scanf("%d",&k);
            push(k);
            break;
        case 2:
            int k2 = pop();
            if( k2 != INT_MIN) printf("Popped value : %d\n",k2);
            break;
        case 3:
            int k3 = getMin();
            if( k3 != INT_MIN) printf("Min value : %d\n",k3);
            break;
        case 4:
            peek();
            break;
        }
    }
    return 0;
}
