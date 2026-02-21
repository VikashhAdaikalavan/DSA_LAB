#include <stdio.h>
int min(int a, int b)
{
    return a>b? b: a;
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    int q[n];
    int sum = 0;
    for(int i = 0; i< n ; i++)
    {
        scanf("%d",&q[i]);
    }
    int key = q[k];
    for(int i = 0; i< n ; i++)
    {
        if(i<=k)
        sum = sum + min(q[i],key);
        else
        {
            sum = sum + min(q[i],key-1);
        }
    }
    printf("%d\n",sum);
    return 0;
}