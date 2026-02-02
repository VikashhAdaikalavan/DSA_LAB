#include<stdio.h>
#include<stdlib.h>

int maxi(int a, int b)
{
    return a > b ? a : b;
}

int check(int n, int arr[], int workload, int w)
{
    int workers = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > workload)
            return 0;

        if (sum + arr[i] <= workload)
        {
            sum += arr[i];
        }
        else
        {
            workers++;
            sum = arr[i];
        }
    }

    return workers <= w;
}

int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[n];
    int r = 0;
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        r = r + arr[i];
        l = maxi(l, arr[i]);
    }

    while(l<=r)
    {
        int mid = (l + r) / 2;
        if(check(n,arr,mid,k))
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
