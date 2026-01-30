#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int maxi(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int check(int n, int arr[n], int g, int c)
{
    int tax = 0;
    for(int i = 0; i< n ; i++)
    {
        if(arr[i]>c) tax = tax + c;
        else tax = tax + arr[i];
    }
    return tax>=g;
}


int main ()
{
    int c, g,n;
    scanf("%d",&n);
    scanf("%d",&g);
    int arr[n];
    int r = INT_MIN;
    for(int i = 0; i< n ; i++)
    {
        scanf("%d",&arr[i]);
        r = maxi(r,arr[i]);
    }

    int l = 0;
    int maxtax  = r;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(n,arr,g,mid))
        {
            r = mid -1;
        }
        else l = mid +1;
    }

    if(l >maxtax) printf("-1\n");
    else printf("%d\n",l);
    return 0;  

}