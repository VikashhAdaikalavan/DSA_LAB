#include <stdio.h>
#include <stdlib.h>


int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left;
    int j = mid +1;
    int k = left;
    int invertcount = 0;
    while(i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invertcount += (mid-i+1);
        }
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];

    for(int i = left ; i<=right ; i++) arr[i] = temp[i];

    return invertcount;
    
}

int split(int arr[], int temp[], int left, int right)
{
    int c = 0;
    if(left<right)
    {
        int mid = (left+right)/2;
        c += split(arr,temp,left,mid);
        c += split(arr,temp,mid+1,right);
        c += merge(arr,temp,left,mid,right);
    }
    
    return c;
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    int temp[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long result = split(arr, temp, 0, N - 1);
    printf("%lld\n", result);
    return 0;
}