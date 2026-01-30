#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    int arr[n];
    for(int i = 0 ;i< n ; i++)
    {
        scanf("%d",&arr[i]);
    }

    int l = 0;
    int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(arr[mid] - mid -1 < k) l = mid+1; 
        else r = mid-1;
    }
    printf("%d\n",k + r + 1);
    return 0;
}