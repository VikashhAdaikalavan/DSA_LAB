#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int txor = 0;
    for(int i = 0 ; i< n ; i++) 
    {
        scanf("%d",&arr[i]);
        txor = txor ^ arr[i];
    }
    int nxor = arr[0];
    for(int i = 1; i< n-1 ; i++)
    {
        if((txor ^ nxor ^ arr[i]) == (nxor)) printf("%d ",i+1);
        nxor = nxor ^ arr[i];
    }

    return 0;
}

