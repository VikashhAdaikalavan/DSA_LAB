#include<stdio.h>
#include<stdlib.h>

int main()
{
    int k;
    scanf("%d",&k);

    int l = 0;
    int r = 10000;

    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(mid*mid<=k) l = mid+1;
        else r = mid-1;
    }

    printf("%d\n",r);
    return 0;
}