#include <stdio.h>
#include <stdlib.h>

int merge(int arr[],int temp[], int left, int mid, int right, int lower, int upper)
{
    int j = mid + 1;
    int k = mid +1;
    int count = 0;
    for(int i = left; i<=mid ; i++)
    {
        while(k<=right && arr[k] - arr[i]<lower) k++;
        while(j<=right && arr[j] - arr[i]<=upper) j++;

        count += (j - k);
    }
    int p = left;
    int i = left;
    j = mid+1;
    while (i<=mid && j<=right)
    {
        if(arr[i]<arr[j])
        {
            temp[p++] = arr[i++];
        }
        else
        {
            temp[p++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[p++] = arr[i++];
    }
    while(j<=right)
    {
        temp[p++] = arr[j++];
    }
    for(int o = left; o<= right ; o++)
    {
        arr[o] = temp[o];
    }
    
    return count;
}

int msort(int arr[], int temp[], int i, int j,int lower , int upper)
{
    if(i>=j) return 0;
    int mid = (i+j)/2;
    int n1 = msort(arr,temp,i,mid,lower, upper);
    int n2 = msort(arr,temp,mid+1,j,lower, upper);
    int n3 = merge(arr,temp,i,mid,j,lower, upper);
    return n1+n2+n3;
}

int main()
{
    int n;
    int lower, upper;

    scanf("%d %d %d", &n, &lower, &upper);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix[n + 1];
    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    int temp[n + 1];

    printf("%lld\n", msort(prefix, temp, 0, n, lower, upper));

    return 0;
}




