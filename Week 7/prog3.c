#include <stdio.h>
#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int q[MAX];
    int front = 0, back = -1;

    int stk[MAX];
    int top = -1;

    int half = n / 2;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        q[++back] = x;
    }

    for(int i = 0 ; i< half ; i++)
    {
        q[++back] = q[front++]; 
    }
    for(int i = half ; i<n ; i++)
    {
        stk[++top] = q[front++];
    }
    while(top != -1) q[++back] = stk[top--];

    for(int i = 0 ; i< half ; i++)
    {
        q[++back] = q[front++]; 
    }
    for(int i = half ; i<n ; i++)
    {
        stk[++top] = q[front++];
    }

    for(int i = 0; i< n ; i++)
    {
        if(i%2 == 0) q[++back] = q[front++];
        else q[++back] = stk[top--];
    }
    

    while (front <= back) {
        printf("%d ", q[front++]);
    }

    return 0;
}
