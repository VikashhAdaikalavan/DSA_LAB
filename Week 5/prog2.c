#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int l = 0;
    int r = 1;
    int start = 0,end = 1, maxlen = 1;

    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i =0 ; i< n ; i++) scanf("%d",&arr[i]);
    int prediff = arr[1] - arr[0];
    while (r<=n)
    {
        if(r == n || arr[r] - arr[r-1] != prediff)
        {
            if(r-l > maxlen)
            {
                maxlen = r-l;
                start = l;
                end = r-1;
            }
            l = r-1;
            if(r != n) prediff = arr[r] - arr[l];
        }
        r++;
    }
    printf("%d %d\n",start+1, end+1);

    return 0;

}