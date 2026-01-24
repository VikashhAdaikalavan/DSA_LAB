#include<stdio.h>
#include <stdlib.h>


int maxi(int a, int b) {
    return (a > b) ? a : b;
}

int main()
{
    int n;
    scanf("%d",&n);
    
    int max = -10000;
    int arr[n];
    for(int i = 0; i< n ; i++) 
    {
        scanf("%d",&arr[i]);
        max = maxi(max,arr[i]);
    }
    int r = max;
    int l = 0;

    while(l<=r)
    {
        int mid = (l+r)/2;
        
    }

    
}