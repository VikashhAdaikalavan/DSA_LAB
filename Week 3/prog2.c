#include<stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    int l = 1;
    int r = n;
    int arr[n+2];
    arr[0] = -10000;
    arr[n+1] = -10000;
    for(int i = 1; i<= n ; i++) scanf("%d",&arr[i]);

    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {
            printf("%d",mid-1);
            return 0;
        }
        else if(arr[mid]>=arr[mid-1] && arr[mid]<=arr[mid+1]) l = mid+1;
        else if(arr[mid]<=arr[mid-1] && arr[mid]>=arr[mid+1]) r= mid-1;
    }

    printf("-1");
    return 0;
}