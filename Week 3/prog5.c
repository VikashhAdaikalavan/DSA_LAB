#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    if (n == 0) {
    printf("-1 -1");
    return 0;
    }
    for(int i = 0 ; i< n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    int t;
    scanf("%d",&t);

    //staring index;

    int l = 0; int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]>=t)
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    int start = l;

    //ending index
    
    l = 0;
    r = n-1;

    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]<=t)
        {
            l = mid+1;
        }
        else
        {
            r = mid -1;
        }
    }

    int end = r;
    if(start > end)
    {
        start = -1;
        end = -1;
    }
    printf("%d %d",start,end);
    return 0;
}