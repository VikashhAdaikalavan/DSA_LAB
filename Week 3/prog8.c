#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int maxi(int a, int b)
{
    return a>b?a:b;
}


int cantransfer(int n, int arr[n], int d, int cap)
{
    if(cap == 0) return 0;
    int x = 0;
    int days = 0;
    for(int i = 0; i< n ; i++)
    {
        x = x+ arr[i];
        if(x>cap)
        {
            x = arr[i];
            days++;
        }
    }
    return (days+1)<=d;
}
int main()
{
    int n,d;
    scanf("%d",&n);
    scanf("%d",&d);
    int arr[n];
    int l = INT_MIN;
    int r = 0;
    for(int i = 0; i < n ; i++)
    {
        scanf("%d",&arr[i]);
        r += arr[i];
        l = maxi(l,arr[i]);
    }
    if(r == 0) 
    {
        printf("0\n");
        return 0;
    }
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(cantransfer(n,arr,d,mid))
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    printf("%d\n",l);
}