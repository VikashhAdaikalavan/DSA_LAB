#include <stdio.h>
#include <stdlib.h>

int tobin(int n)
{
    int bin = 0;
    int place = 1;

    while(n > 0)
    {
        bin += (n % 2) * place;
        place *= 10;
        n /= 2;
    }
    return bin;
}

int main()
{
    int q[1000];
    int front = 0;
    int back = 0;
    q[0] = 1;
    int n;
    scanf("%d",&n);
    int bin = tobin(n);
    printf("%d\n",bin);
    while(front<=back)
    {
        int c = back-front+1;
        for(int i = 0 ; i< c; i++)
        {
            int n = q[front++];
            printf("%d ",n);
            if(n*10<=bin) q[++back] = n*10;
            if(n*10+1<=bin) q[++back] = n*10+1;
        }

    }
    return 0;
}