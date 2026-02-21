#include <stdio.h>

int main()
{
    int q[1000];
    int front = 0;
    int back = -1;
    int stk[1000];
    int top = -1;
    int n,k;
    scanf("%d %d",&n,&k);

    for(int i = 0 ; i< n ; i++)
    {
        scanf("%d",&q[++back]);
    }
    for(int i = 0; i< k ; i++)
    {
        stk[++top] = q[front++];
    }
    for(int i = 0; i < k ; i++)
    {
        q[++back] = stk[top--];
    }

    for(int i =0; i< n-k ; i++)
    {
        q[++back] = q[front++];
    }
    for(int i = 0 ; i< n ; i++)
    {
        printf("%d ",q[front+i]);
    }
    printf("\n");
    return 0;
}