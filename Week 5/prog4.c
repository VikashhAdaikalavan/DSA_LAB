#include <stdio.h>
#include <stdlib.h>

int canhave(int n, int arr[n], int d, int k)
{
    int count = 1;
    int l = 0;
    int r = 1;
    while(r< n)
    {
        if(arr[r] - arr[l] >= d)
        {
            count++;
            l = r;
        }
        r++;
    }
    return count >=k;
}


int main()
{
    int n, k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n];
    for(int i =0 ; i< n ; i++) scanf("%d", & arr[i]);

    int l = 0;
    int r = arr[n-1] - arr[0]; 

    while(l<= r)
    {
        int mid = (l+r)/2;
        if(canhave(n,arr,mid,k)) l = mid +1;
        else r = mid -1;
    }

    printf("%d\n",r);
    return 0;
}