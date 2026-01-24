#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int f(int x)
{
    return 2*x*x*x -x*x + 5*x;
}

int main()
{
    int y;
    scanf("%d",&y);
    int l = 0;
    int r = 100;
    
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(f(mid) <= y) l = mid+1;
        else r = mid-1;
    }
    printf("%d",r);

    return 0;
}